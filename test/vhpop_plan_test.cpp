#include "stdafx.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;


/* The parse function. */
extern int yyparse();

/* File to parse. */
extern FILE* yyin;

/* Name of current file. */
std::string current;

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
        current = name;
        bool success = (yyparse() == 0);
        fclose(yyin);
        return success;
    }
}

namespace test
{
	TEST_CLASS(VHPOP_PlanTest)
	{
	public:
		
		TEST_METHOD(SolveSimpleBlocksWorldProblem)
		{
            read_file("E:\\Developer\\vhpop\\test\\blocks_domain.pddl");
            read_file("E:\\Developer\\vhpop\\test\\blocks_problem.pddl");

            const Domain* blocks_domain = Domain::find("blocks");
            const Problem* blocks_problem = Problem::find("blocks-3");
            Assert::AreEqual(blocks_domain->name(), blocks_problem->domain().name(), L"The parsed domain for the blocks problem should be the same");

            Parameters planner_parameters;
            planner_parameters.heuristic = Heuristic("UCPOP");
            
            const Plan* plan = Plan::plan(*blocks_problem, planner_parameters, true);
            Assert::IsNotNull(plan, L"There should be a solution to this planning problem.");
            Assert::AreEqual(6, plan->steps()->size(), L"The plan should have six steps: the dummy initial and final, and four steps that achieve the solution.");
		}

	};
}