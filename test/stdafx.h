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
#include "../plans.h"

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


            template<>
            static std::wstring ToString<Decomposition>(const Decomposition& d) {
                std::stringstream ss;

                ss << "decomposition '" << d.name() << "'";
                ss << " for composite action '" << d.composite_action_schema().name();
                ss << "' at memory location ";
                ss << &d;

                std::string str = ss.str();
                std::wstring wstr;
                wstr.assign(str.begin(), str.end());
                return wstr;
            }


            template<>
            static std::wstring ToString<StepList>(const StepList& sl) {
                std::stringstream ss;

                ss << "step list [";
                for (StepList::const_iterator si = sl.begin(); si != sl.end(); ++si)
                {
                    ss << "(";
                    ss << (*si).action().name() << ", id=" << (*si).id();
                    ss << ")";

                    if (si + 1 != sl.end())
                        ss << ", ";
                }
                ss << "]";

                std::string str = ss.str();
                std::wstring wstr;
                wstr.assign(str.begin(), str.end());
                return wstr;
            }

            template<>
            static std::wstring ToString<BindingList>(const BindingList& bl) {
                std::stringstream ss;

                ss << "binding list [";
                for (BindingList::const_iterator bi = bl.begin(); bi != bl.end(); ++bi)
                {
                    ss << "(";
                    ss << "var=" << (*bi).var() << ", " << "term=" << (*bi).term();
                    ss << ")";

                    if (bi + 1 != bl.end())
                        ss << ", ";
                }
                ss << "]";

                std::string str = ss.str();
                std::wstring wstr;
                wstr.assign(str.begin(), str.end());
                return wstr;
            }

            template<>
            static std::wstring ToString<OrderingList>(const OrderingList& ol) {
                std::stringstream ss;

                ss << "ordering list [";
                for (OrderingList::const_iterator oi = ol.begin(); oi != ol.end(); ++oi)
                {
                    ss << "(";
                    ss <<  (*oi).before_id() << " < " << (*oi).after_id();
                    ss << ")";

                    if (oi + 1 != ol.end())
                        ss << ", ";
                }
                ss << "]";

                std::string str = ss.str();
                std::wstring wstr;
                wstr.assign(str.begin(), str.end());
                return wstr;
            }

            template<>
            static std::wstring ToString<LinkList>(const LinkList& ll) {
                std::stringstream ss;

                ss << "link list [";
                for (LinkList::const_iterator li = ll.begin(); li != ll.end(); ++li)
                {
                    ss << "(";
                    ss << (*li).from_id() << " -> " << (*li).to_id();
                    ss << ")";

                    if (li + 1 != ll.end())
                        ss << ", ";
                }
                ss << "]";

                std::string str = ss.str();
                std::wstring wstr;
                wstr.assign(str.begin(), str.end());
                return wstr;
            }
        }
    }
}


