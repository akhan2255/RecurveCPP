#include "stdafx.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace test
{
	TEST_CLASS(OrderingListTest)
	{
	public:
		
		TEST_METHOD(TestContainsCycle)
		{
			OrderingList no_cycles;
			no_cycles.push_back(Ordering(-1, StepTime::AT_END, -2, StepTime::AT_START));
			no_cycles.push_back(Ordering(-2, StepTime::AT_END, -3, StepTime::AT_START));
            no_cycles.push_back(Ordering(-2, StepTime::AT_END, -4, StepTime::AT_START));
			no_cycles.push_back(Ordering(-4, StepTime::AT_END, -3, StepTime::AT_START));
			no_cycles.push_back(Ordering(-5, StepTime::AT_END, -4, StepTime::AT_START));
			no_cycles.push_back(Ordering(-6, StepTime::AT_END, -1, StepTime::AT_START));
			no_cycles.push_back(Ordering(-7, StepTime::AT_END, -8, StepTime::AT_START));
			Assert::IsFalse(no_cycles.contains_cycle(), L"This list of ordering constraints does not contain a cycle.");
			
			OrderingList cycle;
			cycle.push_back(Ordering( 0, StepTime::AT_END, -1, StepTime::AT_START));
			cycle.push_back(Ordering(-1, StepTime::AT_END, -2, StepTime::AT_START));
			cycle.push_back(Ordering(-2, StepTime::AT_END, -3, StepTime::AT_START));
			cycle.push_back(Ordering(-3, StepTime::AT_END,  0, StepTime::AT_START));
			Assert::IsTrue(cycle.contains_cycle(), L"This list of ordering constraints does contain one cycle.");
		}

	};
}