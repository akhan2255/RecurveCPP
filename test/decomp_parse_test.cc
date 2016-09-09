#include "stdafx.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;



namespace test
{
	TEST_CLASS(DecompositionParseTest)
	{
	public:

        TEST_METHOD(ParseCompositeAction)
        {
            read_file("..\\test\\composite_action.pddl");
            const Domain* parsed = Domain::find("composite_action");
            Assert::IsTrue(parsed->requirements.decompositions, L"Decompositions were implicitly specified due to an action being marked with a composite property.");

            const ActionSchema* pick_up = parsed->find_action("pick-up");
            Assert::IsTrue(pick_up->composite(), L"pick-up should have been parsed as a composite action.");

            const ActionSchema* put_down = parsed->find_action("put-down");
            Assert::IsTrue(put_down->composite(), L"put-down should have been parsed as a composite action.");

            const ActionSchema* stack = parsed->find_action("stack");
            Assert::IsFalse(stack->composite(), L"stack should have been parsed as a non-composite action");
        }
		

        TEST_METHOD(ParseDecompositionSchema)
        {
            read_file("..\\test\\travel_domain.pddl");
            read_file("..\\test\\travel_problem.pddl");
            const Domain* domain = Domain::find("travel");
            const Problem* problem = Problem::find("travel-to-la");
            
			// Check decompositions implicit requirement
            Assert::IsTrue(domain->requirements.decompositions, L"Decompositions were implicitly specified due to an action being marked with a composite property.");
            Assert::IsTrue(domain->requirements.typing, L"Typing was implicitly specified due to parsing a 'types' list.");

			// Get the decomposition schema
            const DecompositionSchema* travel_drive = domain->find_decomposition("travel", "drive");
			std::vector<Step>::size_type num_pseudo_steps = travel_drive->pseudo_steps().size();

            Assert::IsNotNull(travel_drive, L"The travel-drive decomposition should exist as a not-null, domain thing.");
            Assert::AreEqual((size_t) 4, travel_drive->parameters().size(), L"The travel-drive decomposition should have been domain with four parameters.");
			Assert::AreEqual((size_t) 5, num_pseudo_steps, L"This decomposition schema specifies 5 pseudo-steps.");

            // Check the dummy initial and final
            Step decomp_dummy_initial_step = travel_drive->pseudo_steps()[0];
            Assert::AreEqual(std::string("<decomposition-init-for-drive>"), decomp_dummy_initial_step.action().name());
            Assert::AreEqual((size_t) 1, decomp_dummy_initial_step.action().effects().size(), L"Decomposition dummy initial step should have 1 effect");
            Assert::IsTrue(decomp_dummy_initial_step.action().condition().tautology(), L"Decomposition dummy initial step should have no preconditions.");


            Step decomp_dummy_final_step = travel_drive->pseudo_steps()[1];
            Assert::AreEqual(std::string("<decomposition-goal-for-drive>"), decomp_dummy_final_step.action().name());
            Assert::AreEqual((size_t) 0, decomp_dummy_final_step.action().effects().size(), L"Decomposition dummy final step should have no effects.");
            Assert::IsTrue(typeid(decomp_dummy_final_step.action().condition()) == typeid(Conjunction), L"Decomposition dummy final step precondition Formula should be a Conjunction.");

            const Conjunction& conj = dynamic_cast<const Conjunction&>(decomp_dummy_final_step.action().condition());
            Assert::AreEqual((size_t) 2, conj.conjuncts().size(), L"Decomposition dummy final step should have 2 preconditions.");

            // Check a dummy step
            Step pseudo_get_in_car = travel_drive->pseudo_steps()[2];
            Assert::IsTrue(pseudo_get_in_car.pseudo_step(), L"get-in-car is a pseudo-step");
            Assert::AreEqual(std::string("get-in-car"), pseudo_get_in_car.action().name());
            const ActionSchema* pseudo_action_schema = dynamic_cast<const ActionSchema*> (&pseudo_get_in_car.action());
			
			// Get one of the effects of this step.
			const Effect* in_person_car;
			for (EffectList::const_iterator ei = pseudo_action_schema->effects().begin();
				ei != pseudo_action_schema->effects().end();
				++ei)
			{
				const Literal* el = &(*ei)->literal();
				const Predicate predicate = el->predicate();
				if (PredicateTable::name(predicate) == std::string("in")) {
					in_person_car = *ei;
				}
			}

			// Get another dummy step
			Step pseudo_drive = travel_drive->pseudo_steps()[3];
			Assert::IsTrue(pseudo_drive.pseudo_step(), L"drive is a pseudo-step");
			Assert::AreEqual(std::string("drive"), pseudo_drive.action().name());
			

			// Check an ordering
			OrderingList travel_drive_orderings = travel_drive->ordering_list();
			Assert::IsFalse(travel_drive_orderings.empty(), L"Orderings were specified as part of the decomposition.");

            int step1_step2_idx = ((travel_drive->pseudo_steps().size()-2) * 2) + 1;
			Ordering step1_step2 = travel_drive_orderings[step1_step2_idx];
			Assert::AreEqual(pseudo_get_in_car.id(), step1_step2.before_id(), L"The preceeding pseudo step is `get-in-car'");
			Assert::AreEqual(pseudo_drive.id(), step1_step2.after_id(), L"The succeeding pseudo step is `drive'");


			// Check causal link - step references
			LinkList travel_drive_links = travel_drive->link_list();
			Assert::IsFalse(travel_drive_links.empty(), L"Causal links were specified as part of the decomposition.");
			Link step1_in_person_car_step2 = travel_drive_links[1];
			Assert::AreEqual(pseudo_get_in_car.id(), step1_in_person_car_step2.from_id(), L"The source step is `get-in-car'");
			Assert::AreEqual(pseudo_drive.id(), step1_in_person_car_step2.to_id(), L"The sink step is `drive'");

			// Check causal link - established condition
			const Literal* in_person_car_literal = &in_person_car->literal();
			const Literal* link_condition = &step1_in_person_car_step2.condition();
			
			Assert::AreEqual(in_person_car_literal->predicate(), link_condition->predicate(), L"The literal predicate of the step effect should be the same one referenced in the link condition.");
			Assert::AreEqual(in_person_car_literal->arity(), link_condition->arity(), L"The arity of the literal of the step effect should be the same as the one referenced in the link condition.");

			// Check bindings
			BindingList travel_drive_bindings = travel_drive->binding_list();
			Assert::AreEqual((size_t) 20, travel_drive_bindings.size(), L"There should be 20 bindings.");

			// Check causal link - term bindings
			for (size_t i = 0; i < link_condition->arity(); ++i)
			{
				// Each pair of terms should be bound
				Term in_person_car_term = in_person_car_literal->term(i); // effect
				Term link_condition_term = link_condition->term(i);		  // precondition
				const Binding* relevant_binding = 0;

				// find the relevant binding - it should exist!
				for (BindingList::const_iterator bi = travel_drive_bindings.begin();
					 bi != travel_drive_bindings.end();
					 ++bi)
				{
					const Binding b = *bi;
					if (b.contains(in_person_car_term, pseudo_get_in_car.id()) && 
						b.contains(link_condition_term, pseudo_drive.id())) {
						relevant_binding = &b;
					}
				}

				if (relevant_binding == 0) {
					Assert::Fail(L"There should be a binding that matches terms in a causal link");
				}
			}

            // Check the decomposition legality criteria
            Assert::IsTrue(travel_drive->satisfies_dpocl_legality_criteria(), L"This decomposition schema should be considered legal.");
        }

        TEST_METHOD(ParseDecompositionsRequirement)
        {
            read_file("..\\test\\decompositions_requirement.pddl");
            const Domain* parsed = Domain::find("decompositions_requirement");
            Assert::IsTrue(parsed->requirements.decompositions, L"Decompositions were specified as part of the domain definition requirements.");
        }


	};
}