// stdafx.h : include file for standard system include files,
// or project specific include files that are used frequently, but
// are changed infrequently
//

#pragma once

#include "targetver.h"

// Headers for CppUnitTest
#include "CppUnitTest.h"

// TODO: reference additional headers your program requires here
#include <iostream>
#include <stdlib.h>
#include <sstream>
#include <string>
#include <typeinfo>
#include <vector>
#include "../formulas.h"
#include "../expressions.h"
#include "../terms.h"
#include "../types.h"
#include "../problems.h"
#include "../pddl.hh"
#include "../decompositions.h"
#include "../parameters.h"

/* The parse function. */
extern int yyparse();

/* File to parse. */
extern FILE* yyin;

/* Debug flag for the parser. */
extern int yydebug;

/* Parses the given file, and returns true on success. */
static bool read_file(const char* name)
{
    yyin = fopen(name, "r");
    if (yyin == NULL)
    {
        std::cerr << "ERROR IN OPENING FILE" << std::endl;
        return false;
    }

    else
    {
        std::string current = name;
        bool success = (yyparse() == 0);
        fclose(yyin);
        return success;
    }
}

// Auxiliary ToString methods
namespace Microsoft{
    namespace VisualStudio {
        namespace CppUnitTestFramework {

            template<>
            static std::wstring ToString<Atom>(const Atom& a) {
                std::stringstream ss;
                ss << "(" << a.id() << " ";
                for (size_t i = 0; i < a.arity(); ++i)
                {
                    ss << a.term(i);

                    if ((i + 1) != a.arity()) {
                        ss << " ";
                    }
                }
                ss << ") at memory location ";
                ss << &a;


                std::string str = ss.str();
                std::wstring wstr;
                wstr.assign(str.begin(), str.end());
                return wstr;
            }




            template<>
            static std::wstring ToString<Predicate>(const Predicate& p) {
                std::stringstream ss;

                ss << "(" << PredicateTable::name(p);
                ss << ") at memory location ";
                ss << &p;

                std::string str = ss.str();
                std::wstring wstr;
                wstr.assign(str.begin(), str.end());
                return wstr;
            }


            template<>
            static std::wstring ToString<Term>(const Term& t) {
                std::stringstream ss;

                ss << "(" << t;
                ss << ") at memory location ";
                ss << &t;

                std::string str = ss.str();
                std::wstring wstr;
                wstr.assign(str.begin(), str.end());
                return wstr;
            }

        }
    }
}


