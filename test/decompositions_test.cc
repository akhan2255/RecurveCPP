#include "stdafx.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace test
{
	TEST_CLASS(DecompositionFrameTest)
	{
	public:
		
		TEST_METHOD(TestConstructor)
		{
			// Setup
            read_file("..\\test\\travel_domain.pddl");
            read_file("..\\test\\travel_problem.pddl");
            const Domain* domain = Domain::find("travel");
            const Problem* problem = Problem::find("travel-to-la");

            const DecompositionSchema* travel_drive_schema = domain->find_decomposition("travel", "drive");
            const Decomposition* travel_drive = dynamic_cast<const Decomposition*>(travel_drive_schema);
            DecompositionFrame instance(*travel_drive);

            // When a DecompositionStep is instantiated, the instance fields are copied 
            // over from the decomposition. Each field should be a distinct object, 
            // because these are the ones that will be manipulated in terms of ids.
            Assert::AreNotSame(travel_drive->pseudo_steps(), instance.steps());
            Assert::AreNotSame(travel_drive->binding_list(), instance.binding_list());
            Assert::AreNotSame(travel_drive->ordering_list(), instance.ordering_list());
            Assert::AreNotSame(travel_drive->link_list(), instance.link_list());
   		}

        TEST_METHOD(TestSwapSteps)
        {
            // Setup
            read_file("..\\test\\travel_domain.pddl");
            read_file("..\\test\\travel_problem.pddl");
            const Domain* domain = Domain::find("travel");
            const Problem* problem = Problem::find("travel-to-la");

            const DecompositionSchema* travel_drive_schema = domain->find_decomposition("travel", "drive");
            const Decomposition* travel_drive = dynamic_cast<const Decomposition*>(travel_drive_schema);
            DecompositionFrame instance(*travel_drive);

            int swap_index = 2;
            int new_step_index = 1;
            Step pseudo_get_in_car = travel_drive->pseudo_steps()[swap_index]; // get the first pseudo-step that isn't a dummy
            Step get_in_car(new_step_index, *(dynamic_cast<const Action*>(domain->find_action("get-in-car"))));

            // Swap!
            instance.swap_steps(pseudo_get_in_car, get_in_car);

            // Should have same number of steps
            Assert::AreEqual(travel_drive->pseudo_steps().size(), instance.steps().size(), L"Swapping a step should not change the number of steps.");

            // Should have a non-pseudo-step (id of new step is positive) in the place of the pseudo-step
            Step new_step = instance.steps()[swap_index];
            Assert::IsFalse(new_step.pseudo_step(), L"The new step in the swap should not be a pseudo-step.");

            // The link from -3 to -4, should now be a link from 1 to -4
            Link step1_in_person_car_step2 = instance.link_list()[1];
            Assert::AreEqual(new_step_index, step1_in_person_car_step2.from_id(), L"The causal link (-3)->(-4) should have been updated.");

            // All relevant bindings should have their step id's updated - pick a random one from those
            Binding in_person_car_binding = instance.binding_list()[10];
            Assert::AreEqual(new_step_index, in_person_car_binding.term_id(), L"The binding that referenced the pseudo-step should have been updated.");
            
            // The ordering -3 < -4 should be update to 1 < -4
            int step1_step2_idx = ((travel_drive->pseudo_steps().size() - 2) * 2) + 1;
            Ordering step1_step2_ordering = instance.ordering_list()[step1_step2_idx];
            Assert::AreEqual(new_step_index, step1_step2_ordering.before_id(), L"The ordering that contained the swapped pseudo-step id should be updated.");
        }

	};
}