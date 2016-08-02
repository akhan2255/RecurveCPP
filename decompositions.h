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
#include "plans.h"

/* ====================================================================== */
/* Decomposition */

/*
 * A decomposition schema represents a single-layer expansion of a composite
 * action. 
 */
struct Decomposition {


    

private:

    /* Unique id for decompositions. */
    size_t id_;

    /* Name of this decomposition. */
    std::string name_;

    /* Name of the action this decomposition is applicable to. */
    std::string action_name_;

    /* Chain of pseudo steps. */
    const Chain<Step>* pseudo_steps_;

    /* Binding constraints of this decomposition schema. */
    const Bindings* bindings_;

    /* Ordering constraints of this decomposition schema. */
    const Orderings* orderings_;

    /* Chain of causal links of this decomposition schema. */
    const Chain<Link>* links_;

    
};

#endif /* DECOMPOSITIONS_H */
