/* -*-C++-*- */
/*
* Causal Links.
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
#ifndef LINKS_H
#define LINKS_H

#include "orderings.h"
#include "flaws.h"

/* ====================================================================== */
/* Link */

/*
* Causal link.
*/
struct Link {

    /* Constructs a causal link. */
    Link(int from_id, StepTime effect_time, const OpenCondition& open_cond);

    /* Constructs a causal link. */
    Link(const Link& l);

    /* Deletes this causal link. */
    ~Link();

    /* Returns the id of step that link goes from. */
    int from_id() const { return from_id_; }

    /* Returns the time of effect satisfying link. */
    StepTime effect_time() const { return effect_time_; }

    /* Returns the id of step that link goes to. */
    int to_id() const { return to_id_; }

    /* Returns the condition satisfied by link. */
    const Literal& condition() const { return *condition_; }

    /* Returns the time of the condition satisfied by this link. */
    FormulaTime condition_time() const { return condition_time_; }

private:

    /* Id of step that link goes from. */
    int from_id_;

    /* Time of effect satisfying link. */
    StepTime effect_time_;

    /* Id of step that link goes to. */
    int to_id_;

    /* Condition satisfied by link. */
    const Literal* condition_;

    /* Time of condition satisfied by link. */
    FormulaTime condition_time_;
};

/* Equality operator for links. */
inline bool operator==(const Link& l1, const Link& l2) {
    return &l1 == &l2;
}


/* ====================================================================== */
/* LinkList */

/*
* List of Links.
*/
struct LinkList : std::vector<Link> {

    /* Returns a vector of all the unique step ids in this link list. */
    std::vector<int> unique_step_ids() const;

public:

    /* Returns a list of links whose source step is given by the step_id. If no such links exist,
    this method returns an empty list. */
    const LinkList outgoing_links(int step_id) const;

    /* Checks whether this link list contains a path from the step given by the source_id to the
    step given by the destination_id.*/
    bool contains_path(int source_id, int destination_id) const;

    /* Checks whether this Links in this link list give rise to a cycle. */
    bool contains_cycle() const;

};

#endif /* LINKS_H */
