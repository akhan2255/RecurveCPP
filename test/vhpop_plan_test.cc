#include "stdafx.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace test
{
	TEST_CLASS(VHPOP_PlanTest)
	{
	public:
		
		TEST_METHOD(SolveSimpleBlocksWorldProblem)
		{
            read_file("..\\test\\blocks_domain.pddl");
            read_file("..\\test\\blocks_problem.pddl");

            const Domain* blocks_domain = Domain::find("blocks");
            const Problem* blocks_problem = Problem::find("blocks-3");
            Assert::AreEqual(blocks_domain->name(), blocks_problem->domain().name(), L"The parsed domain for the blocks problem should be the same");

            Parameters planner_parameters;
            planner_parameters.heuristic = Heuristic("UCPOP");
            
            const Plan* plan = Plan::plan(*blocks_problem, planner_parameters, true);
            Assert::IsNotNull(plan, L"There should be a solution to this planning problem.");
            Assert::AreEqual(6, plan->steps()->size(), L"The plan should have six steps: the dummy initial and final, and four steps that achieve the solution.");

            const Action* a = dynamic_cast<const Action*>(blocks_domain->find_action("pick-up"));
            Step d(4, *a);
            const Step* pickup = plan->steps()->get(d);

            Term randomTerm = pickup->action().effects()[0]->literal().term(0);
            plan->bindings()->binding(randomTerm, 4);

		}

	};
}