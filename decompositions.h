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
#include "orderings.h"
#include "bindings.h"
#include "links.h"


/* ====================================================================== */
/* Decomposition */

/*
 * A decomposition schema represents a single-layer expansion of a composite
 * action. 
 */
struct Decomposition {

    /* Next pseudo-step id. */
    static size_t next_pseudo_step_id;

    /* Checks whether this decomposition satisfies the legality criteria defined by the DPOCL
       planning system, defined by Young, Pollack, and Moore. */
    bool satisfies_dpocl_legality_criteria() const;

    /* Adds a pseudo-step to this decomposition. */
    void add_pseudo_step(const Step& pseudo_step);

    /* Adds a binding to this decomposition. */
    void add_binding(const Binding& binding);

    /* Adds an ordering to this decomposition. */
    void add_ordering(const Ordering& ordering);

	/* Adds a link to this decomposition. */
	void add_link(const Link& link);

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

    /* Returns the list of ordering constraints of this decomposition. */
    const OrderingList ordering_list() const { return ordering_list_; }

    /* Returns the list of causal links of this decomposition. */
    const LinkList link_list() const { return link_list_; }

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
    LinkList link_list_;

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
/* DecompositionFrame */

/* Represents an instantiated decomposition. It's the decompositional analogue to
the basic plan step. */
struct DecompositionFrame {

    /* Constructs a decomposition step instantiated from a decomposition. */
    DecompositionFrame(const Decomposition& decomposition)
    : decomposition_(&decomposition),
    steps_(decomposition.pseudo_steps()),
    binding_list_(decomposition.binding_list()),
    ordering_list_(decomposition.ordering_list()),
    link_list_(decomposition.link_list()) 
    {
        id_ = DecompositionFrame::next_id;
        DecompositionFrame::next_id++;
    }

    /* Constructs a decomposition step. */
    DecompositionFrame(const DecompositionFrame& ds)
        : id_(ds.id_),
        decomposition_(ds.decomposition_),
        steps_(ds.steps_),
        binding_list_(ds.binding_list()),
        ordering_list_(ds.ordering_list()),
        link_list_(ds.link_list()) {}

    /* Returns the decomposition step id. */
    int id() const { return id_; }

    /* Swaps the old step in this Frame for the given new step. Returns true if swap was 
       successful. */
    bool swap_steps(const Step old_step, const Step new_step);

    /* Returns the decomposition that this step is instantiated from. */
    const Decomposition& decomposition() const { return *decomposition_; }

    /* Returns the steps that belong to this decomposition. */
    const StepList steps() const { return steps_; }

    /* Returns the list of bindings for this decomposition. */
    const BindingList binding_list() const { return binding_list_; }

    /* Returns the list of ordering constraints of this decomposition. */
    const OrderingList ordering_list() const { return ordering_list_; }

    /* Returns the list of causal links of this decomposition. */
    const LinkList link_list() const { return link_list_; }

private:

    /* Next decomposition frame id. */
    static size_t next_id;

    /* Decomposition frame id */
    int id_;

    /* Decomposition that this decomposition step is instantiated from. */
    const Decomposition* decomposition_;

    /* List of steps that belong to this decomposition. */
    StepList steps_;

    /* List of bindings for this decomposition. */
    BindingList binding_list_;

    /* List of ordering constraints of this decomposition. */
    OrderingList ordering_list_;

    /* List of causal links of this decomposition. */
    LinkList link_list_;
};


/* ====================================================================== */
/* Decomposition Link */

/*
* A DecompositionLink is used to record the fact that the purpose of some
* step s is to be part of a more-primitive realization of some other step.
*/
struct DecompositionLink {

    /* Constructs a decomposition link. */
    DecompositionLink(int composite_id, DecompositionFrame& decomposition_frame)
    : composite_id_(composite_id), decomposition_frame_(decomposition_frame) {}

    /* Returns the id of the composite step being decomposed. */
    int composite_id() const { return composite_id_; }

    /* Returns the decomposition step that refines the composite step of this decomposition link. */
    const DecompositionFrame decomposition_frame() const { return decomposition_frame_; }

private:

    /* Id of the composite step being decomposed. */
    int composite_id_;

    /* The decomposition step that refines the composite step identified by the id. */
    DecompositionFrame decomposition_frame_;

};

/* Equality operator for decomposition links. */
inline bool operator==(const DecompositionLink& l1, const DecompositionLink& l2) {
    return &l1 == &l2;
}


/* ====================================================================== */
/* DecompositionSchemaMap */

/* Table of decomposition schema definitions. This table maps a pair of strings to a decomposition
   schema.  Each string in the pair of strings is (respectively): the name of the action being 
   decomposed (the composite action), and the name of a specific decomposition. */
struct DecompositionSchemaMap : 
    public std::map < std::pair<std::string, std::string>, const DecompositionSchema* > {};


#endif /* DECOMPOSITIONS_H */
