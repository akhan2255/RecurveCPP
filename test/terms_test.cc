#include "stdafx.h"
#include "CppUnitTest.h"
#include "../terms.h"
#include "../types.h"
#include <string>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace test
{
	TEST_CLASS(TermTableTest)
	{
	public:

        TEST_METHOD(static_add_variable)
        {
            Type sword(1);
            Variable sword_var = TermTable::add_variable(sword);

            // check that we got a variable back
            Term sword_var_as_term = sword_var;
            Assert::IsTrue(sword_var_as_term.variable(), L"We should get a variable");

            // check that the type is what we expect
            Type t = TermTable::type(sword_var_as_term);
            bool types_match = (sword == t);
            Assert::IsTrue(types_match, L"The type that was specified should accompany the Term");

        }

        TEST_METHOD(static_set_type)
        {
            // Declare something of one type
            Type sword(1);
            Variable sword_var = TermTable::add_variable(sword);
            Term sword_var_as_term = sword_var;

            // Change the type
            Type master_sword(2);
            TermTable::set_type(sword_var_as_term, master_sword);

            // Check that the type is what we expect
            Type t = TermTable::type(sword_var_as_term);
            bool type_changed = (master_sword == t && sword != t);
            Assert::IsTrue(type_changed, L"The type should have changed as instructed.");
        }

		
		TEST_METHOD(add_object)
		{
            Type sword(1);
            std::string name = "sword1";

            TermTable *tt = new TermTable();
            Object firstSword = tt->add_object(name, sword);
            const Object *origSword = tt->find_object(name);

           


		}

	};
}