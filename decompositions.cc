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


/* ====================================================================== */
/* Auxiliary Function Declarations */

/* Attempt to convert the parameter Formula to an Effect. */
Effect* attempt_to_convert_formula(const Formula* formula);





/* ====================================================================== */
/* Decomposition */

/* Ids for dummy start and goal steps that bound a decomposition's pseudo-steps. */
const size_t Decomposition::DUMMY_START_ID = 0;
const size_t Decomposition::DUMMY_GOAL_ID = std::numeric_limits<size_t>::max();

/* Next decomposition id. */
size_t Decomposition::next_id = 0;

/* Constructs a decomposition for the given composite action name with the given name. */
Decomposition::Decomposition(const ActionSchema* composite_action_schema, const std::string& name)
    : id_(next_id++),
      composite_action_schema_(composite_action_schema),
      name_(name),
      next_pseudo_step_id_(1) 
{
    // From the paper by Young, Pollack, and Moore:
    // Each decomposition schema:
    // (1) contains a dummy initial step whose effects are the preconditions of the parent step.
    // (2) contains a dummy final step whose effects are the preconditions of the parent step.
    // (3) has ordering constraints ensuring that s_i precedes all other steps, and
    // (4) each effect of s_i has a path of causal links that terminates in a precondition of s_f.
    

    /* ---------------------------------------------------------------- */
    /* Dummy Initial Step Construction  */

    // Build the dummy step's schema
    ActionSchema* dummy_initial_action_schema = new ActionSchema("<decomposition-init-for-" + name + ">", false, false);
    const Formula* composite_preconditions = &(composite_action_schema->condition());
    Effect* dummy_initial_effect;

    // Check whether the composite's precondition is a Conjunction or is a Literal;
    // Anything else is not supported at this time.
    // TODO: Extend the kinds of effects of dummy initial steps to be more than just Literals or Conjunctions.
    const Conjunction* conj = dynamic_cast<const Conjunction*>(composite_preconditions);
    if (conj != NULL)
    {
        // Add each conjunct (which should be a Literal) as an effect.
        const FormulaList& conjuncts = conj->conjuncts();
        for (FormulaList::const_iterator fi = conjuncts.begin(); fi != conjuncts.end(); ++fi) {
            dummy_initial_effect = attempt_to_convert_formula(*fi);
            dummy_initial_action_schema->add_effect(*dummy_initial_effect);
        }
    }

    else { // If it's not a Conjunction, it should be a literal - otherwise, this will throw an exception.
        dummy_initial_effect = attempt_to_convert_formula(composite_preconditions);
        dummy_initial_action_schema->add_effect(*dummy_initial_effect);
    }

    // TODO: [#7]  Abstract Action Schemata should support wider range of precondition/effect Formulas #7 


    /* ---------------------------------------------------------------- */
    /* Dummy Goal Step Construction  */

    ActionSchema* dummy_goal_action_schema = new ActionSchema("<decomposition-goal-for-" + name + ">", false, false);
    EffectList composite_effects = composite_action_schema->effects();
    Conjunction* dummy_goal_preconditions = new Conjunction();
    for (EffectList::const_iterator ei = composite_effects.begin(); ei != composite_effects.end(); ++ei)
    {
        const Effect* eff = *ei;
        const Formula* eff_formula = &(eff->literal());
        dummy_goal_preconditions->add_conjunct(*eff_formula);
    }
    dummy_goal_action_schema->set_condition(*dummy_goal_preconditions);

    
    // build pseudo_steps
    pseudo_steps_ =
        new Chain<Step>(Step(Decomposition::DUMMY_START_ID, *dummy_initial_action_schema),
         new Chain<Step>(Step(Decomposition::DUMMY_GOAL_ID, *dummy_goal_action_schema), NULL));

    // build bindings
    bindings_ = &Bindings::EMPTY;

    // build orderings

    // TODO: extend this to the other kind of orderings, TermporalOrderings
    orderings_ = new BinaryOrderings(); 

    // build links
    links_ = NULL;


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


/* ====================================================================== */
/* Auxiliary Function Definitions */

/* Attempt to convert the parameter Formula to an Effect. */
Effect* attempt_to_convert_formula(const Formula* formula)
{
    const Literal* l = dynamic_cast<const Literal*>(formula);
    if (l == NULL) {
        throw std::logic_error("unable to convert formula to effect; only literals may be used");
    }

    else
    {
        Effect* effect = new Effect(*l, Effect::AT_START);
        return effect;
    }
}

