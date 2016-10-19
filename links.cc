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

#include "links.h"


/* ====================================================================== */
/* Link */

/* Constructs a causal link. */
Link::Link(int from_id, StepTime effect_time,
    const OpenCondition& open_cond)
    : from_id_(from_id), effect_time_(effect_time), to_id_(open_cond.step_id()),
    condition_(open_cond.literal()), condition_time_(open_cond.when()) {
    Formula::register_use(condition_);
}


/* Constructs a causal link. */
Link::Link(const Link& l)
: from_id_(l.from_id_), effect_time_(l.effect_time_), to_id_(l.to_id_),
condition_(l.condition_), condition_time_(l.condition_time_) {
    Formula::register_use(condition_);
}


/* Deletes this causal link. */
Link::~Link() {
    Formula::unregister_use(condition_);
}


/* ====================================================================== */
/* LinkList */


/* Returns a vector of all the unique step ids in this link list. */
std::vector<int> LinkList::unique_step_ids() const
{
    // collect a vector of unique ids, and return it.
    std::vector<int> unique_step_ids;

    for (LinkList::const_iterator li = this->begin(); li != this->end(); ++li)
    {
        const Link l = *li;

        // if you can't find the from_id, add it
        if (std::find(unique_step_ids.begin(), unique_step_ids.end(), l.from_id()) ==
            unique_step_ids.end()) {
            unique_step_ids.push_back(l.from_id());
        }

        // if you can't find the to_id, add it
        if (std::find(unique_step_ids.begin(), unique_step_ids.end(), l.to_id()) ==
            unique_step_ids.end()) {
            unique_step_ids.push_back(l.to_id());
        }
    }

    return unique_step_ids;

}


/* Returns a list of Links whose source step is given by the step_id. If no such links exist,
this method returns an empty list. */
const LinkList LinkList::outgoing_links(int step_id) const
{
    LinkList outgoing_links;

    for (LinkList::const_iterator li = this->begin(); li != this->end(); ++li)
    {
        Link l = *li;
        if (l.from_id() == step_id) {
            outgoing_links.push_back(l);
        }
    }

    return outgoing_links;
}


/* Checks whether this LinkList contains a path from the step given by the source_id to the
step given by the destination_id. */
bool LinkList::contains_path(int source_id, int destination_id) const
{
    // Setup the visited list
    std::vector<int> visited;

    // Setup the fringe.
    std::vector<int> fringe;
    fringe.push_back(source_id);

    // While the search fringe has elements,
    while (!fringe.empty())
    {
        // Pop the back of the fringe - a depth-first search
        int id = fringe[fringe.size() - 1];
        fringe.pop_back();

        // Goal test
        if (id == destination_id) {
            return true;
        }

        else
        {
            // Check that we haven't already visited this node.
            if (std::find(visited.begin(), visited.end(), id) != visited.end()) {
                continue; // skip - don't generate edges for this node again
            }

            else
            {
                // Mark this node as visited
                visited.push_back(id);

                // Generate new edges to look through, and add them to the fringe
                LinkList outgoing_edges = this->outgoing_links(id);
                for (LinkList::const_iterator li = outgoing_edges.begin(); li != outgoing_edges.end(); ++li)
                {
                    // The id to add to the fringe is the id of the sink step of the link
                    Link outgoing_edge = *li;
                    fringe.push_back(outgoing_edge.to_id());
                }
            }
        }
    }

    return false;
}


/* Checks whether this Links in this LinkList give rise to a cycle. */
bool LinkList::contains_cycle() const
{
    // Get every unique step id within this link list
    std::vector<int> unique_step_ids = this->unique_step_ids();

    // For each such id, attempt to find yourself in a depth traversal
    for (std::vector<int>::const_iterator si = unique_step_ids.begin();
        si != unique_step_ids.end();
        ++si)
    {
        int start_id = *si;

        // Setup the visited list
        std::vector<int> visited;

        // Setup the fringe
        std::vector<int> fringe;
        fringe.push_back(start_id);

        // While the search fringe has elements,
        while (!fringe.empty())
        {
            // Pop the back of the fringe - a depth-first search
            int id = fringe[fringe.size() - 1];
            fringe.pop_back();

            // Check to see if we've seen this before
            if (std::find(visited.begin(), visited.end(), id) != visited.end())
            {
                // If we've seen it before, check that it's the one we started with
                if (id == start_id) {
                    return true; // cycle found!
                }

                else {
                    continue;
                }
            }

            else
            {
                // Register the node as visited
                visited.push_back(id);

                // Generate new edges to look through, and add them to the fringe
                LinkList outgoing_links = this->outgoing_links(id);
                for (LinkList::const_iterator li = outgoing_links.begin(); li != outgoing_links.end(); ++li)
                {
                    // The id to add to the fringe is the id of the to step.
                    Link l = *li;
                    fringe.push_back(l.to_id());
                }

            }
        }
    } // end for

    // No depth first search has found its corresponding starting node, so no cycles detected!
    return false;
}
