#include "stdafx.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace test
{
	TEST_CLASS(DecompositionPlanTest)
	{
	public:
		
		TEST_METHOD(TestDecompositionalPlanning)
		{
            // Setup
            read_file("..\\test\\travel_domain.pddl");
            read_file("..\\test\\travel_problem.pddl");
            const Domain* domain = Domain::find("travel");
            const Problem* problem = Problem::find("travel-to-la");
            Parameters params = Parameters();

            std::vector<FlawSelectionOrder> orders;
            orders.push_back(FlawSelectionOrder("Longbow*"));
            params.flaw_orders = orders;

            // Find a plan
            // This currently blows up->
            const Plan* plan = Plan::plan(*problem, params, true);

            // TODO: UPDATE
            // For now, this plan should exist, and it should have a non-zero 
            // number of unexpanded composite step flaws.
            // Assert::IsNull(plan, L"There should not be a plan that solves this problem.");



		}

	};
}