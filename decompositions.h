/* -*-C++-*- */
/*
* Decompositions.
*
* Copyright (C) 2016 North Carolina State University
* Written by Rogelio E. Cardona-Rivera.
*
* Permission is hereby granted to distribute this software for
* non-commercial research purposes, provided that this copyright
* notice is included with any such distribution.
*
* THIS SOFTWARE IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND,
* EITHER EXPRESSED OR IMPLIED, INCLUDING, BUT NOT LIMITED TO, THE
* IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
* PURPOSE.  THE ENTIRE RISK AS TO THE QUALITY AND PERFORMANCE OF THE
* SOFTWARE IS WITH YOU.  SHOULD THE PROGRAM PROVE DEFECTIVE, YOU
* ASSUME THE COST OF ALL NECESSARY SERVICING, REPAIR OR CORRECTION.
*
*/
#ifndef DECOMPOSITIONS_H
#define DECOMPOSITIONS_H

#include <string>
#include "actions.h"
#include "plans.h"
#include "bindings.h"

/* ====================================================================== */
/* Decomposition */

/*
 * A decomposition schema represents a single-layer expansion of a composite
 * action. 
 */
struct Decomposition {

    /* Next pseudo-step id. */
    static size_t next_pseudo_step_id;

    /* Adds a pseudo-step to this decomposition. */
    void add_pseudo_step(const Step& pseudo_step);

    /* Adds a binding to this decomposition. */
    void add_binding(const Binding& binding);

    /* Adds an ordering to this decomposition. */
    void add_ordering(const Ordering& ordering);

    /* Returns the unique id for this decomposition. */
    size_t id() const { return id_; }

    /* Returns the composite action this decomposition is appliable to. */
    const ActionSchema& composite_action_schema() const { return *composite_action_schema_; }

    /* Returns the name of this decomposition. */
    const std::string& name() const { return name_; }

    /* Returns the pseudo steps of this decomposition. */
    const StepList pseudo_steps() const { return pseudo_steps_; }

    /* Returns the list of bindings for this decomposition. */
    const BindingList binding_list() const { return binding_list_; }

    /* Returns the list of orderings for this decomposition. */
    const OrderingList ordering_list() const { return ordering_list_; }

    /* Returns the list of causal links of this decomposition. */
    const LinkList links() const { return links_; }

protected:

    /* Constructs a decomposition for the given composite action with the given name. */
    Decomposition(const ActionSchema* composite_action_schema, const std::string& name);

private:

    /* Next decomposition id. */
    static size_t next_id;

    /* Unique id for decompositions. */
    size_t id_;

    /* The composite action this decomposition is applicable to. */
    const ActionSchema* composite_action_schema_;

    /* Name of this decomposition. */
    std::string name_;

    /* List of pseudo steps. */
    StepList pseudo_steps_;

    /* List of bindings for this decomposition. */
    BindingList binding_list_;

    /* List of ordering constraints of this decomposition. */
    OrderingList ordering_list_;

    /* List of causal links of this decomposition. */
    LinkList links_;

};


/* ====================================================================== */
/* DecompositionSchema */

struct DecompositionSchema : public Decomposition {

    /* Constructs a decomposition schema for the given composite action name with the given name. */
    DecompositionSchema(const ActionSchema* composite_action_schema, const std::string& name);

    /* Adds a parameter to this decomposition schema. */
    void add_parameter(Variable var);

    /* Returns the parameters of this decomposition schema. */
    const VariableList& parameters() const { return parameters_; }

    /* Prints this decomposition schema on the given stream. */
    // void print(std::ostream& os) const;

private:

    /* Decomposition parameters. */
    VariableList parameters_;

};


/* ====================================================================== */
/* DecompositionSchemaMap */

/*
 * Table of decomposition schema definitions. This table maps a pair of strings
 * to a decomposition schema.  The pair of strings are (respectively):
 * - the name of the action being decomposed (the composite action), and 
 * - the name of a specific decomposition.
 */
struct DecompositionSchemaMap : 
    public std::map < std::pair<std::string, std::string>, const DecompositionSchema* > {};



#endif /* DECOMPOSITIONS_H */
