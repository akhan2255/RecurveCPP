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
/* Decomposition */

/* Next decomposition id. */
size_t Decomposition::next_id = 0;

/* Constructs a decomposition for the given composite action name with the given name. */
Decomposition::Decomposition(const std::string& composite_action_name, const std::string& name)
    : id_(next_id++),
      composite_action_name_(composite_action_name),
      name_(name),
      pseudo_steps_(NULL),
      bindings_(NULL),
      orderings_(NULL),
      links_(NULL) {}

/* ====================================================================== */
/* DecompositionSchema */

/* Constructs a decomposition schema for the given composite action name with the given name. */
DecompositionSchema::DecompositionSchema(const std::string& composite_action_name, const std::string& name)
    : Decomposition(composite_action_name, name) {}





