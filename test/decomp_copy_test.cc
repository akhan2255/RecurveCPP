#include "stdafx.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace test
{
	TEST_CLASS(DecompositionCopyTest)
	{
	public:
		
		TEST_METHOD(TestDecompositionFrameMemberCopy)
		{
			// Setup
            read_file("..\\test\\travel_domain.pddl");
            read_file("..\\test\\travel_problem.pddl");
            const Domain* domain = Domain::find("travel");
            const Problem* problem = Problem::find("travel-to-la");

            const DecompositionSchema* travel_drive_schema = domain->find_decomposition("travel", "drive");
            const Decomposition* travel_drive = dynamic_cast<const Decomposition*>(travel_drive_schema);
            DecompositionFrame instance(1, *travel_drive);

            // When a DecompositionStep is instantiated, the instance fields are copied 
            // over from the decomposition. Each field should be a distinct object, 
            // because these are the ones that will be manipulated in terms of ids.
            Assert::AreNotSame(travel_drive->pseudo_steps(), instance.steps());
            Assert::AreNotSame(travel_drive->binding_list(), instance.binding_list());
            Assert::AreNotSame(travel_drive->ordering_list(), instance.ordering_list());
            Assert::AreNotSame(travel_drive->link_list(), instance.link_list());
   		}

	};
}