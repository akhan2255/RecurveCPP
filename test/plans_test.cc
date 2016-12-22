#include "stdafx.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace test
{
	TEST_CLASS(PlansTest)
	{
        /* Mapping of predicate names to achievers. */
        struct PredicateAchieverMap : public std::map < Predicate, ActionEffectMap > {};

        /* Maps predicates to actions. */
        PredicateAchieverMap achieves_pred;

        /* Maps negated predicates to actions. */
        PredicateAchieverMap achieves_neg_pred;

	public:

		TEST_METHOD(TestLiteralAchievers)
		{
            // Setup
            read_file("..\\test\\travel_domain.pddl");
            read_file("..\\test\\travel_problem.pddl");
            const Domain* domain = Domain::find("travel");
            const Problem* problem = Problem::find("travel-to-la");

            achieves_pred.clear();
            achieves_neg_pred.clear();

            // For each action schema in the domain...
            for (ActionSchemaMap::const_iterator ai = domain->actions().begin();
                ai != domain->actions().end();
                ai++)
            {
                const ActionSchema* as = (*ai).second;

                // ...for each effect of the action schema...
                for (EffectList::const_iterator ei = as->effects().begin();
                    ei != as->effects().end();
                    ei++)
                {

                    // Get the effect as a Literal,
                    const Literal& literal = (*ei)->literal();

                    // And see if it's an Atom or its negation.
                    // If the former, it belongs in the "achieves_pred" map.
                    // If the latter, it belongs in the "achieves_neg_pred" map.
                    if (typeid(literal) == typeid(Atom)) {
                        achieves_pred[literal.predicate()].insert(std::make_pair(as, *ei));
                    }

                    else {
                        achieves_neg_pred[literal.predicate()].insert(std::make_pair(as, *ei));
                    }
                }
            }

            // We also need to add the initial dummy action to the map.
            const GroundAction& ia = problem->init_action();
            for (EffectList::const_iterator ei = ia.effects().begin();
                ei != ia.effects().end();
                ei++)
            {
                const Literal& literal = (*ei)->literal();
                achieves_pred[literal.predicate()].insert(std::make_pair(&ia, *ei));
            }

            // And because we're also dealing with timed actions, we repeat the process
            // for these as well.
            for (TimedActionTable::const_iterator ai = problem->timed_actions().begin();
                ai != problem->timed_actions().end();
                ai++)
            {
                const GroundAction& action = *(*ai).second;
                for (EffectList::const_iterator ei = action.effects().begin();
                    ei != action.effects().end();
                    ei++)
                {
                    const Literal& literal = (*ei)->literal();

                    if (typeid(literal) == typeid(Atom)) {
                        achieves_pred[literal.predicate()].insert(std::make_pair(&action, *ei));
                    }

                    else {
                        achieves_neg_pred[literal.predicate()].insert(std::make_pair(&action, *ei));
                    }
                }
            }

            Assert::AreEqual((size_t)2, achieves_pred.size(), L"There are two positive literals that appear in actions within the domain.");
            Assert::AreEqual((size_t)2, achieves_neg_pred.size(), L"There are two negative literals that appear in actions within the domain."); 

            const Predicate* at_p = domain->predicates().find_predicate("at");
            const Predicate* in_p = domain->predicates().find_predicate("in");

            Assert::AreEqual((size_t)7, achieves_pred[*at_p].size(), L"There are three actions within the domain that assert 'at(...)', one action achieves two different 'at' predicates (so it counts twice), plus three dummy actions that collectively assert the initial state");
            Assert::AreEqual((size_t)4, achieves_neg_pred[*at_p].size(), L"There are three actions within the domain that assert 'not at(...)', one action achieves two different 'not at' predicates (so it counts twice)");
            Assert::AreEqual((size_t)1, achieves_pred[*in_p].size(), L"There is one action within the domain that asserts 'in(...)'");
            Assert::AreEqual((size_t)1, achieves_neg_pred[*in_p].size(), L"There is one action within the domain that asserts 'not in(...)'");
		}

	};
}