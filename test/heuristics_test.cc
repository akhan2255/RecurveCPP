#include "stdafx.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace test
{
	TEST_CLASS(FlawSelectionOrderTest)
	{
	public:
		
		TEST_METHOD(IsPoclComplete)
		{
            std::vector<FlawSelectionOrder> all_orders;
            all_orders.push_back(FlawSelectionOrder("UCPOP"));
            all_orders.push_back(FlawSelectionOrder("UCPOP-LC"));
            all_orders.push_back(FlawSelectionOrder("DSep-LIFO"));
            all_orders.push_back(FlawSelectionOrder("DSep-FIFO"));
            all_orders.push_back(FlawSelectionOrder("DSep-LC"));
            all_orders.push_back(FlawSelectionOrder("DUnf-LIFO"));
            all_orders.push_back(FlawSelectionOrder("DUnf-FIFO"));
            all_orders.push_back(FlawSelectionOrder("DUnf-LC"));
            all_orders.push_back(FlawSelectionOrder("DUnf-Gen"));
            all_orders.push_back(FlawSelectionOrder("DRes-LIFO"));
            all_orders.push_back(FlawSelectionOrder("DRes-FIFO"));
            all_orders.push_back(FlawSelectionOrder("DRes-LC"));
            all_orders.push_back(FlawSelectionOrder("DEnd-LIFO"));
            all_orders.push_back(FlawSelectionOrder("DEnd-FIFO"));
            all_orders.push_back(FlawSelectionOrder("DEnd-LC"));
            all_orders.push_back(FlawSelectionOrder("LCFR"));
            all_orders.push_back(FlawSelectionOrder("LCFR-DSep"));
            all_orders.push_back(FlawSelectionOrder("ZLIFO"));
            all_orders.push_back(FlawSelectionOrder("ZLIFO*"));
            all_orders.push_back(FlawSelectionOrder("Static"));
            all_orders.push_back(FlawSelectionOrder("LCFR-Loc"));
            all_orders.push_back(FlawSelectionOrder("LCFR-Conf"));
            all_orders.push_back(FlawSelectionOrder("LCFR-Loc-Conf"));
            all_orders.push_back(FlawSelectionOrder("MC"));
            all_orders.push_back(FlawSelectionOrder("MC-Loc"));
            all_orders.push_back(FlawSelectionOrder("MC-Loc-Conf"));
            all_orders.push_back(FlawSelectionOrder("MW"));
            all_orders.push_back(FlawSelectionOrder("MW-Loc"));
            all_orders.push_back(FlawSelectionOrder("MW-Loc-Conf"));
            all_orders.push_back(FlawSelectionOrder("Longbow"));
            
            // Verify that all pre-defined flaw selection orders are POCL complete.
            std::vector<FlawSelectionOrder>::const_iterator fi;
            for (fi = all_orders.begin(); fi != all_orders.end(); ++fi) {
                std::string name = fi->name();
                std::wstring wstr = std::wstring(name.begin(), name.end());
                Assert::IsTrue(fi->is_pocl_complete(), wstr.c_str());
            }

		}

        TEST_METHOD(IsDecompositionComplete)
        {
            FlawSelectionOrder longbow = FlawSelectionOrder("Longbow");
            Assert::IsTrue(longbow.is_decomposition_complete());

            FlawSelectionOrder ucpop = FlawSelectionOrder("UCPOP");
            Assert::IsFalse(ucpop.is_decomposition_complete());
        }

	};
}