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

#include "decompositions.h"
#include <typeinfo>






/* ====================================================================== */
/* Decomposition */


/* Next pseudo-step id. */
size_t Decomposition::next_pseudo_step_id = 0;

/* Next decomposition id. */
size_t Decomposition::next_id = 0;

/* Constructs a decomposition for the given composite action name with the given name. */
Decomposition::Decomposition(const ActionSchema* composite_action_schema, const std::string& name)
    : id_(next_id++),
      composite_action_schema_(composite_action_schema),
      name_(name) 
{
    // From the paper by Young, Pollack, and Moore:
    // Each decomposition schema:
    // (1) contains a dummy initial step whose effects are the preconditions of the parent step, and these codesignate in the bindings.
    // (2) contains a dummy final step whose effects are the preconditions of the parent step, and these codesignate in the bindings.
    // (3) has ordering constraints ensuring that s_i precedes all other steps, and
    // (4) each effect of s_i has a path of causal links that terminates in a precondition of s_f.



    /* ---------------------------------------------------------------- */
    /* Dummy Initial Step Construction  */

    // Build the dummy step's schema
    ActionSchema* dummy_initial = new ActionSchema("<decomposition-init-for-" + name + ">", false, false);
    Step* dummy_initial_step = new Step(-(++next_pseudo_step_id), *dummy_initial); // Pseudo-steps are defined with negative index
    
    const Formula& composite_precondition = composite_action_schema_->condition();
    
    // Currently, I'm only supporting Literals and Conjunctions of Literals.
    // TODO: [#7]  Abstract Action Schemata should support wider range of precondition/effect Formulas #7 
    if (typeid(composite_precondition) == typeid(Atom)) 
    {
        const Atom& atom = dynamic_cast<const Atom&>(composite_precondition);
        Effect* dummy_initial_effect = new Effect(atom, Effect::AT_END);
        dummy_initial->add_effect(*dummy_initial_effect);
    }

    else if (typeid(composite_precondition) == typeid(Negation))
    {
        const Negation& negation = dynamic_cast<const Negation&>(composite_precondition);
        Effect* dummy_initial_effect = new Effect(negation, Effect::AT_END);
        dummy_initial->add_effect(*dummy_initial_effect);
    }

    else if (typeid(composite_precondition) == typeid(Conjunction)) 
    {
        const Conjunction& conj = dynamic_cast<const Conjunction&>(composite_precondition);
        for (FormulaList::const_iterator fi = conj.conjuncts().begin();
             fi != conj.conjuncts().end();
             ++fi)
        {   
            // Iterate over each conjunct and attempt to convert it to an effect.
            if (typeid(*fi) == typeid(Atom))
            {
                const Atom& atom = dynamic_cast<const Atom&>(composite_precondition);
                Effect* dummy_initial_effect = new Effect(atom, Effect::AT_END);
                dummy_initial->add_effect(*dummy_initial_effect);
            }

            else if (typeid(*fi) == typeid(Negation))
            {
                const Negation& negation = dynamic_cast<const Negation&>(composite_precondition);
                Effect* dummy_initial_effect = new Effect(negation, Effect::AT_END);
                dummy_initial->add_effect(*dummy_initial_effect);
            }

            else
            {
                // Error - currently only supporting Literals
                throw std::logic_error("unable to convert formula within" + composite_action_schema_->name()
                    + " to effect; only literals and conjunctions of literals may be used");
            }
        }
    }

    else 
    {
        // Error
        throw std::logic_error("unable to convert formula within" + composite_action_schema_->name() 
            + " to effect; only literals and conjunctions of literals may be used");
    }


    /* ---------------------------------------------------------------- */
    /* Dummy Goal Step Construction  */

    ActionSchema* dummy_goal_action_schema = new ActionSchema("<decomposition-goal-for-" + name + ">", false, false); 
    Step* dummy_goal_step = new Step(-(++next_pseudo_step_id), *dummy_goal_action_schema);

    Conjunction* dummy_goal_preconditions = new Conjunction();
    for (EffectList::const_iterator ei = composite_action_schema->effects().begin();
         ei != composite_action_schema->effects().end();
         ++ei)
    {
        const Literal& lit = (*ei)->literal();
        dummy_goal_preconditions->add_conjunct(lit);
    }
    dummy_goal_action_schema->set_condition(*dummy_goal_preconditions);

    
    // build pseudo_steps
    pseudo_steps_ =
        new Chain<Step>(*dummy_goal_step,
         new Chain<Step>(*dummy_initial_step, NULL));

    // build orderings
    orderings_ = new BinaryOrderings(); // TODO: extend this to the other kind of orderings, TermporalOrderings 
	
    // build links
    links_ = NULL;
}


/* Adds a pseudo-step to this decomposition. */
void Decomposition::add_pseudo_step(const Step& pseudo_step) {
    pseudo_steps_ = new Chain<Step>(pseudo_step, pseudo_steps_);
}

/* Adds a binding to this decomposition. */
void Decomposition::add_binding(const Binding& binding) {
    binding_list_.push_back(binding);
}


/* ====================================================================== */
/* DecompositionSchema */

/* Constructs a decomposition schema for the given composite action name with the given name. */
DecompositionSchema::DecompositionSchema(const ActionSchema* composite_action_schema, const std::string& name)
    : Decomposition(composite_action_schema, name) {}

/* Adds a parameter to this decomposition schema. */
void DecompositionSchema::add_parameter(Variable var) {
    parameters_.push_back(var);
}
