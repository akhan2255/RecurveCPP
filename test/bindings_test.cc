#include "stdafx.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace test
{
	TEST_CLASS(BindingsListTest)
	{
	public:
		
		TEST_METHOD(TestBindingListSwapIds)
		{
            TypeTable types;
            TermTable terms;
            
            Type weapon_t = types.add_type("weapon");
            Variable weapon = terms.add_variable(weapon_t);
            Object sword = terms.add_object("s1", weapon_t);

            Type location_t = types.add_type("location");
            Variable from_location = terms.add_variable(location_t);
            Variable to_location = terms.add_variable(location_t);
            Variable hero_location = terms.add_variable(location_t);
            Object castle = terms.add_object("castle", location_t);
            Object forest = terms.add_object("forest", location_t);
            Object ranch = terms.add_object("ranch", location_t);
            Object lake = terms.add_object("lake", location_t);
            
            Type character_t = types.add_type("character");
            Variable hero = terms.add_variable(character_t);
            Variable villain = terms.add_variable(character_t);
            Variable sidekick = terms.add_variable(character_t);
            Object link = terms.add_object("link", character_t);
            Object ganon = terms.add_object("ganon", character_t);
            Object navi = terms.add_object("navi", character_t);

            BindingList bl;
            bl.push_back(Binding(weapon, -1, sword, -2, true)); //0
            bl.push_back(Binding(from_location, -1, castle, -3, true)); //1
            bl.push_back(Binding(to_location, -1, ranch, -4, true)); //2
            bl.push_back(Binding(hero, -1, link, -5, true)); //3
            bl.push_back(Binding(villain, -3, ganon, 10, true)); //4
            bl.push_back(Binding(hero_location, -5, lake, 11, true)); //5
            bl.push_back(Binding(sidekick, -5, navi, -4, true)); //6

            BindingList swapped;

            swapped = bl.swap_ids(-1, 1);
            Assert::AreEqual(swapped[0].var_id(), 1, L"Pseudo-step id -1 was replaced for 1.");
            Assert::AreEqual(swapped[1].var_id(), 1, L"Pseudo-step id -1 was replaced for 1.");
            Assert::AreEqual(swapped[2].var_id(), 1, L"Pseudo-step id -1 was replaced for 1.");
            Assert::AreEqual(swapped[3].var_id(), 1, L"Pseudo-step id -1 was replaced for 1.");

            swapped = swapped.swap_ids(-1, 1);
            Assert::AreEqual(swapped[0].var_id(), 1, L"Pseudo-step id -1 was replaced for 1.");

            swapped = swapped.swap_ids(-3, 3);
            Assert::AreEqual(swapped[2].var_id(), 1, L"Swapping different numbers should not affect previously swapped other numbers.");
            Assert::AreEqual(swapped[1].term_id(), 3, L"Pseudo-step id -3 was replaced for 3.");
            Assert::AreEqual(swapped[4].var_id(), 3, L"Pseudo-step id -3 was replaced for 3.");

            swapped = swapped.swap_ids(-5, 5);
            swapped = swapped.swap_ids(-4, 4);
            Assert::AreEqual(swapped[0].var_id(), 1, L"Swapping different numbers should not affect previously swapped other numbers.");
            Assert::AreEqual(swapped[1].term_id(), 3, L"Swapping different numbers should not affect previously swapped other numbers.");
            Assert::AreEqual(swapped[2].term_id(), 4, L"Pseudo-step id -4 was replaced for 4.");
            Assert::AreEqual(swapped[3].term_id(), 5, L"Pseudo-step id -5 was replaced for 5.");
            Assert::AreEqual(swapped[5].var_id(), 5, L"Pseudo-step id -5 was replaced for 5.");
            Assert::AreEqual(swapped[6].var_id(), 5, L"Pseudo-step id -5 was replaced for 5.");
		}

	};
}