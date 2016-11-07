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
    /* ---------------------------------------------------------------- */
    /* Dummy Initial Step Construction  */

    // Build the dummy step's schema
    ActionSchema* dummy_initial = new ActionSchema("<decomposition-init-for-" + name + ">", false, false);
    Step* dummy_initial_step = new Step(-((int) ++next_pseudo_step_id), *dummy_initial); // Pseudo-steps are defined with negative index
    
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
            if (typeid(**fi) == typeid(Atom))
            {
                const Atom& atom = dynamic_cast<const Atom&>(**fi);
                Effect* dummy_initial_effect = new Effect(atom, Effect::AT_END);
                dummy_initial->add_effect(*dummy_initial_effect);
            }

            else if (typeid(**fi) == typeid(Negation))
            {
                const Negation& negation = dynamic_cast<const Negation&>(**fi);
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
    Step* dummy_goal_step = new Step(-((int) ++next_pseudo_step_id), *dummy_goal_action_schema);

    Conjunction* dummy_goal_preconditions = new Conjunction();
    for (EffectList::const_iterator ei = composite_action_schema->effects().begin();
         ei != composite_action_schema->effects().end();
         ++ei)
    {
        const Literal& lit = (*ei)->literal(); // TODO: Should I copy?  Or just pass directly?
        dummy_goal_preconditions->add_conjunct(lit);
    }
    dummy_goal_action_schema->set_condition(*dummy_goal_preconditions);

    
    // build pseudo_steps
    pseudo_steps_.push_back(*dummy_initial_step);
    pseudo_steps_.push_back(*dummy_goal_step);

    // add orderings between the dummy initial and dummy final
    Ordering* init_goal = new Ordering(dummy_initial_step->id(), StepTime::AT_END, dummy_goal_step->id(), StepTime::AT_START);
    ordering_list_.push_back(*init_goal);
}


/* Checks whether this decomposition satisfies the legality criteria defined by the DPOCL
   planning system, defined by Young, Pollack, and Moore. */
bool Decomposition::satisfies_dpocl_legality_criteria() const
{
    // The legality criteria is as follows:
    //  (1) contains a dummy initial step whose effects are the preconditions of the parent step, and these codesignate in the bindings.
    //  (2) contains a dummy final step whose effects are the preconditions of the parent step, and these codesignate in the bindings.
    //  (3) has ordering constraints ensuring that s_i precedes all other steps and s_f succeeds all other steps, and finally
    //  (4) each effect of s_i has a path of causal links that terminates in a precondition of s_f.

    // Items (1), (2), and (3) are guaranteed through the construction of the schema.
    // Thus, this method checks (4).

    // Get the dummy initial and goal steps
    Step dummy_initial = pseudo_steps_[0];
    Step dummy_goal = pseudo_steps_[1];

    // Get every effect of the dummy initial step
    EffectList initial_effects = dummy_initial.action().effects();

    // Get every causal link that starts at the dummy initial step
    LinkList initial_outgoing_links = link_list_.outgoing_links(dummy_initial.id());

    // Verify that every effect of the dummy initial appears as the condition being established in 
    // one of the causal links and verify they lead to path culminating in the goal step
    for (EffectList::const_iterator ei = initial_effects.begin(); ei != initial_effects.end(); ++ei)
    {
        Effect e = **ei;
        bool path_exists = false;

        for (LinkList::const_iterator li = initial_outgoing_links.begin(); li != initial_outgoing_links.end(); ++li)
        {
            Link l = *li;

            // if we have a syntactic literal match, continue the search
            if (Literal::syntactically_equal(e.literal(), l.condition())) 
            {
                // attempt to find a path to the goal step through this link
                if (link_list_.contains_path(l.to_id(), dummy_goal.id())) 
                {
                    path_exists = true;
                    break; // go on to the next effect
                }
            }
        }

        if (!path_exists) {
            return false;
        }
    }
   
    return true;
}


/* Adds a pseudo-step to this decomposition. */
void Decomposition::add_pseudo_step(const Step& pseudo_step) 
{    
    // Adds the step
    pseudo_steps_.push_back(pseudo_step);

    // To satisfy the legality criteria for DPOCL defined by Young, Pollack, and Moore,
    // I must add two ordering constraints for the pseudo_step:

    // The initial dummy step must precede the step:
    Step dummy_initial = pseudo_steps_[0];
    this->add_ordering(Ordering(dummy_initial.id(), StepTime::AT_END, pseudo_step.id(), StepTime::AT_START));

    // The goal dummy step must succeed the step:
    Step dummy_goal = pseudo_steps_[1];
    this->add_ordering(Ordering(pseudo_step.id(), StepTime::AT_END, dummy_goal.id(), StepTime::AT_START));
}


/* Adds a binding to this decomposition. */
void Decomposition::add_binding(const Binding& binding) {
    binding_list_.push_back(binding);
}


/* Adds an ordering to this decomposition. */
void Decomposition::add_ordering(const Ordering& ordering) {
	ordering_list_.push_back(ordering);
}


/* Adds a link to this decomposition. */
void Decomposition::add_link(const Link& link) {
	link_list_.push_back(link);
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
/* DecompositionFrame */

size_t DecompositionFrame::next_id = 0;

/* Constructs a decomposition step instantiated from a decomposition. */
DecompositionFrame::DecompositionFrame(const Decomposition& decomposition) : 
    decomposition_(&decomposition),
    steps_(decomposition.pseudo_steps()),
    binding_list_(decomposition.binding_list()),
    ordering_list_(decomposition.ordering_list())
{
    // Set the id.
    id_ = DecompositionFrame::next_id;
    DecompositionFrame::next_id++;

    // The dummy initial and final are (by convention) the first and second pseudo-steps.
    dummy_initial_step_id_ = steps_[0].id();
    dummy_final_step_id_ = steps_[1].id();

    // Sort the links in breadth-first order starting at the dummy goal step and traversing
    // causal links backward. This is needed to add steps to the plan in a least-commitment
    // fashion that is compatible with the existing VHPOP code base.

    int start_id = dummy_final_step_id_;

    // Setup the visited list.
    LinkList ordered;

    // Setup the fringe.
    std::deque<int> fringe;
    std::deque<int> visited;
    fringe.push_back(start_id);

    // While the search fringe has elements,
    while (!fringe.empty())
    {
        // Pop the front of the fringe and mark it as visited.
        int id = fringe[0];
        fringe.pop_front();
        visited.push_back(id);

        // Get the links that point to the step given by the id.
        LinkList incoming = decomposition.link_list().incoming_links(id);

        // Get the ids of the steps that supply the link, and place
        // them on the fringe if they haven't already been visited.

        // For each incoming link,
        for (LinkList::size_type i = 0; i < incoming.size(); ++i)
        {
            Link link = incoming[i];
            ordered.push_back(link);

            // Get the id of the step that supplies the link and add it to the fringe
            // if we have not visited that step previously.
            if (std::find(visited.begin(), visited.end(), link.from_id()) == visited.end()) {
                fringe.push_back(link.from_id());
            }
        }
    }

    link_list_ = ordered;
}



/* Swaps the old step in this Frame for the given new step. Returns true if swap was
   successful. */
bool DecompositionFrame::swap_steps(const Step old_step, const Step new_step)
{
    // Attempt to find the old step in the frame
    StepList::iterator si = std::find(steps_.begin(), steps_.end(), old_step);

    // If we can't find it, no swap can occur.
    if (si == steps_.end())
        return false;

    // Otherwise,
    else
    {
        // Swap the old step for the new one, and update references throughout.
        (*si) = new_step;

        binding_list_ = binding_list_.swap_ids(old_step.id(), new_step.id());
        ordering_list_ = ordering_list_.swap_ids(old_step.id(), new_step.id());
        link_list_ = link_list_.swap_ids(old_step.id(), new_step.id());

        if (old_step.id() == dummy_initial_step_id_) {
            dummy_initial_step_id_ = new_step.id();
        }

        if (old_step.id() == dummy_final_step_id_) {
            dummy_final_step_id_ = new_step.id();
        }

        return true;
    }
}


