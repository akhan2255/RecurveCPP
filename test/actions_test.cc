#include "stdafx.h"
#include "CppUnitTest.h"
#include "../actions.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace test
{
	TEST_CLASS(ActionSchemaTest)
	{
	public:
		
		TEST_METHOD(ActionSchemaConstructor)
		{
            // Manually create an action schema:
            // Name: fly
            // Composite: true
            // Parameters: ?x - vehicle, ?from - location, ?to - location
            // Preconditions: nil
            // Effects: nil
            
            ActionSchema fly("fly", false, true);

            Type vehicle(0);
            Variable x = TermTable::add_variable(vehicle);
            
            Type location(1);
            Variable from = TermTable::add_variable(location);
            Variable to = TermTable::add_variable(location);

            fly.add_parameter(x);
            fly.add_parameter(from);
            fly.add_parameter(to);
		}

        TEST_METHOD(StepListSort)
        {
            // Setup
            read_file("..\\test\\travel_domain.pddl");
            read_file("..\\test\\travel_problem.pddl");
            const Domain* domain = Domain::find("travel");
            const Problem* problem = Problem::find("travel-to-la");


            Step get_in_car(1, *(dynamic_cast<const Action*>(domain->find_action("get-in-car"))));
            Step drive(2, *(dynamic_cast<const Action*>(domain->find_action("drive"))));
            Step get_out_of_car(3, *(dynamic_cast<const Action*>(domain->find_action("get-out-of-car"))));

            StepList l;
            l.push_back(get_out_of_car);
            l.push_back(get_in_car);
            l.push_back(drive);

            std::sort(l.begin(), l.end());

            Assert::AreEqual(1, l[0].id());
            Assert::AreEqual(2, l[1].id());
            Assert::AreEqual(3, l[2].id());
        }

	};
}