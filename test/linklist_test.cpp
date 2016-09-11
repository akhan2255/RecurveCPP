#include "stdafx.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace test
{
	TEST_CLASS(LinkListTest)
	{
	public:
		
		TEST_METHOD(ContainsPathTest)
		{
			// Magic numbers:
			int init_id = -1;
			int goal_id = -2;

			// An empty list should contain no path.
			LinkList empty;
			Assert::IsFalse(empty.contains_path(0, 100));
			Assert::IsFalse(empty.contains_path(-50, 100));
			
			// Simple path of one step
			LinkList simple;
			OpenCondition goal(goal_id, Formula::TRUE);
			simple.push_back(Link(init_id, StepTime::AT_END, goal));
			Assert::IsTrue(simple.contains_path(init_id, goal_id));
			Assert::IsFalse(simple.contains_path(goal_id, init_id));

			// More complicated path of several steps.
			LinkList complicated;
			OpenCondition goal_1(goal_id, Formula::TRUE);
			OpenCondition step3_1(-3, Formula::TRUE);
			OpenCondition step6_1(-6, Formula::TRUE);
			OpenCondition step4_1(-4, Formula::TRUE);
			OpenCondition step4_2(-4, Formula::TRUE);
			OpenCondition step5_1(-5, Formula::TRUE);
			

			complicated.push_back(Link(-3, StepTime::AT_END, goal));
			complicated.push_back(Link(-6, StepTime::AT_END, step3_1));
			complicated.push_back(Link(-6, StepTime::AT_END, step4_1));
			complicated.push_back(Link(-5, StepTime::AT_END, step4_2));
			complicated.push_back(Link(init_id, StepTime::AT_END, step6_1));
			complicated.push_back(Link(init_id, StepTime::AT_END, step5_1));
			Assert::IsTrue(complicated.contains_path(init_id, goal_id));
			

			// The method should work even in the presence of cycles
			OpenCondition cycle_condition(init_id, Formula::TRUE);
			complicated.push_back(Link(-3, StepTime::AT_END, cycle_condition));
			Assert::IsTrue(complicated.contains_path(init_id, goal_id));

		}

	};
}