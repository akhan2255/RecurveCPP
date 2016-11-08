/* -*-C++-*- */
/*
 * Actions.
 *
 * Copyright (C) 2002-2004 Carnegie Mellon University
 * Written by Håkan L. S. Younes.
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
 * $Id: actions.h,v 6.5 2003-12-05 21:02:08 lorens Exp $
 */
#ifndef ACTIONS_H
#define ACTIONS_H

#include "effects.h"

struct Expression;
struct Domain;
struct Bindings;


/* ====================================================================== */
/* Action */

/*
 * Abstract action definition.
 */
struct Action {
    
	/* Deletes this action. */
    virtual ~Action();

    /* Sets the condition for this action. */
    void set_condition(const Formula& condition);

    /* Adds an effect to this action. */
    void add_effect(const Effect& effect);

    /* Sets the minimum duration for this action. */
    void set_min_duration(const Expression& min_duration);

    /* Sets the maximum duration for this action. */
    void set_max_duration(const Expression& max_duration);

    /* Sets the duration for this action. */
    void set_duration(const Expression& duration);

    /* Sets the composite-ness for this action. */
    void set_composite(const bool composite) { composite_ = composite; };

    /* Returns the id for this action. */
    size_t id() const { return id_; }

    /* Returns the name of this action. */
    const std::string& name() const { return name_; }

    /* Return the condition of this action. */
    const Formula& condition() const { return *condition_; }

    /* List of action effects. */
    const EffectList& effects() const { return effects_; }

    /* Whether this is a durative action. */
    bool durative() const { return durative_; }

	/* Whether this is a composite action. */
	bool composite() const { return composite_; }

    /* Minimum duration of this action. */
    const Expression& min_duration() const { return *min_duration_; }

    /* Maximum duration of this action. */
    const Expression& max_duration() const { return *max_duration_; }

    /* "Strengthens" the effects of this action. */
    void strengthen_effects(const Domain& domain);

    /* Prints this action on the given stream with the given bindings. */
    virtual void print(std::ostream& os,
        size_t step_id, const Bindings& bindings) const = 0;

protected:
    
	/* Constructs an action with the given name. */
    Action(const std::string& name, bool durative, bool composite);

private:

	/* Next action id. */
    static size_t next_id;

    /* Unique id for actions. */
    size_t id_;

	/* Name of this action. */
    std::string name_;
    
	/* Action condition. */
    const Formula* condition_;
    
	/* List of action effects. */
    EffectList effects_;
    
	/* Whether this is a durative action. */
    bool durative_;
    
	/* Minimum duration of this action. */
    const Expression* min_duration_;
    
	/* Maximum duration of this action. */
    const Expression* max_duration_;

	/* Whether this is a composite action. */
	bool composite_;
};


/*
 * Less than function object for action pointers.
 */
namespace std {
    template<>
    struct less<const Action*>
        : public binary_function < const Action*, const Action*, bool > {
        /* Comparison function operator. */
        bool operator()(const Action* a1, const Action* a2) const {
            return a1->id() < a2->id();
        }
    };
}


/* ====================================================================== */
/* ActionList */

/*
 * List of action definitions.
 */
struct ActionList : public std::vector < const Action* > {
};


/* ====================================================================== */
/* ActionSchema */

struct GroundAction;
struct GroundActionList;

/*
 * Action schema definition.
 */
struct ActionSchema : public Action {
    
	/* Constructs an action schema with the given name. */
    ActionSchema(const std::string& name, bool durative, bool composite);

    /* Adds a parameter to this action schema. */
    void add_parameter(Variable var);

    /* Returns the parameters of this action schema. */
    const VariableList& parameters() const { return parameters_; }

    /* Fills the provided action list with all instantiations of this
       action schema. */
    void instantiations(GroundActionList& actions, const Problem& problem) const;

    /* Prints this action on the given stream. */
    void print(std::ostream& os) const;

    /* Prints this action on the given stream with the given bindings. */
    virtual void print(std::ostream& os,
        size_t step_id, const Bindings& bindings) const;

private:
    /* Action schema parameters. */
    VariableList parameters_;

    /* Returns an instantiation of this action schema. */
    const GroundAction* instantiation(const SubstitutionMap& args,
        const Problem& problem,
        const Formula& condition) const;
};

/*
 * Less than function object for action schemas pointers.
 */
namespace std {
    template<>
    struct less<const ActionSchema*> : public less < const Action* > {
    };
}


/* ====================================================================== */
/* ActionSchemaMap */

/*
 * Table of action schema definitions.
 */
struct ActionSchemaMap : public std::map < std::string, const ActionSchema* > {
};


/* ====================================================================== */
/* GroundAction */

/*
 * Ground action.
 */
struct GroundAction : public Action {
    
	/* Constructs a ground action with the given name. */
    GroundAction(const std::string& name, bool durative, bool composite);

    /* Adds an argument to this ground action. */
    void add_argument(Object arg);

    /* Action arguments. */
    const ObjectList& arguments() const { return arguments_; }

    /* Prints this action on the given stream with the given bindings. */
    virtual void print(std::ostream& os,
        size_t step_id, const Bindings& bindings) const;

private:
    /* Action arguments. */
    ObjectList arguments_;
};

/*
 * Less than function object for ground action pointers.
 */
namespace std {
    template<>
    struct less<const GroundAction*> : public less < const Action* > {
    };
}


/* ====================================================================== */
/* GroundActionList */

/*
 * List of ground actions.
 */
struct GroundActionList : public std::vector < const GroundAction* > {
};


/* ====================================================================== */
/* Step */

/*
 * Plan step.
 */
struct Step {

    /* Constructs a step instantiated from an action. */
    Step(int id, const Action& action)
        : id_(id), action_(&action) {}

    /* Constructs a step. */
    Step(const Step& s)
        : id_(s.id_), action_(s.action_) {}

    /* Tests if this object is a pseudo-step. */
    bool pseudo_step() { return id_ < 0; }

    /* Returns the step id. */
    int id() const { return id_; }

    /* Returns the action that this step is instantiated from. */
    const Action& action() const { return *action_; }

    /* Less-than operator for Steps. Less than follows from the comparison of step ids.*/
    bool operator<(const Step& other) const { return id_ < other.id_; }

private:

    /* Step id. */
    int id_;

    /* Action that this step is instantiated from. */
    const Action* action_;

    /* Equality operator for Steps. We assume every Step is uniquely identified by its id. */
    friend bool operator==(const Step& s1, const Step& s2);
};

/* Equality operator for Steps. We assume every Step is uniquely identified by its id. */
inline bool operator==(const Step& s1, const Step& s2) {
    return s1.id_ == s2.id_;
}


/* ====================================================================== */
/* StepList */

/*
* List of Steps.
*/
struct StepList : std::vector < Step > {

    /* Returns the first step in this list with the given id. If no such step exists, this
       method returns null. */
    const Step* find(int id) const;

};








#endif /* ACTIONS_H */
