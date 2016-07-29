#include "stdafx.h"
#include "CppUnitTest.h"
#include "../actions.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace test
{
	TEST_CLASS(ActionSchemaTest)
	{
	public:
		
		TEST_METHOD(actionschema_constructor)
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

	};
}