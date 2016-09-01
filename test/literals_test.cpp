#include "stdafx.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

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

        }
    }
}


namespace test
{
	TEST_CLASS(LiteralTests)
	{
	public:
		
		TEST_METHOD(AtomCopyConstructor)
		{
            TypeTable *types = new TypeTable();
            TermTable *terms = new TermTable();
            PredicateTable *predicates = new PredicateTable();
            
            Type sword = types->add_type("sword");
            Type character = types->add_type("character");

            // defines: has(?x - character, ?y - sword)
            Predicate has_pred = predicates->add_predicate("has");
            predicates->add_parameter(has_pred, character);
            predicates->add_parameter(has_pred, sword);

            // defines: master-sword of type sword
            Object master_sword = terms->add_object("master-sword", sword);

            // defines: link of type character
            Object link = terms->add_object("link", character);

            // defines: has(link, master-sword)
            TermList has_link_mastersword;
            has_link_mastersword.push_back(master_sword);
            has_link_mastersword.push_back(link);
            Atom has_atom = Atom::make(has_pred, has_link_mastersword);


            Atom* has_atom_copy_ptr = new Atom(has_atom);
            Atom has_atom_copy = *has_atom_copy_ptr;


            Assert::AreNotSame(has_atom, has_atom_copy);
		}

        TEST_METHOD(AtomUnifyingWithCopy)
        {
            TypeTable *types = new TypeTable();
            TermTable *terms = new TermTable();
            PredicateTable *predicates = new PredicateTable();

            Type sword = types->add_type("sword");
            Type character = types->add_type("character");

            Predicate has_pred = predicates->add_predicate("has");
            predicates->add_parameter(has_pred, character);
            predicates->add_parameter(has_pred, sword);

            // defines: ?x variable of type sword
            Variable xVar = terms->add_variable(sword);

            // defines: ?y variable of type character
            Variable yVar = terms->add_variable(character);

            // defines: has(?y - character, ?x - sword)
            TermList has_character_sword;
            has_character_sword.push_back(yVar);
            has_character_sword.push_back(xVar);
            Atom has_atom = Atom::make(has_pred, has_character_sword);

            Atom* has_atom_copy_ptr = new Atom(has_atom);
            Atom has_atom_copy = *has_atom_copy_ptr;

           

            // Verify if it is possible to unify with a copy.
            BindingList mgu;
            Assert::IsTrue(Bindings::EMPTY.unify(mgu, has_atom, 1, has_atom_copy, 2));
            Assert::AreEqual((size_t) 2, mgu.size());
        }
        



	};
}