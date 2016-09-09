#include "stdafx.h"
#include "CppUnitTest.h"
#include "../types.h"
#include <string>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;


namespace test
{
    /*
     * Test for the Types Struct and associated methods within types.h
     */
    TEST_CLASS(TypesTest)
    {
    public:

        TEST_METHOD(TestConstructor)
        {
            Type t1(0);
            Assert::IsTrue(t1.simple(), L"The type t1 is a basic type.");
        }

        TEST_METHOD(TestOperators)
        {
            Type* t1 = new Type(0);
            Type t2(0);
            Type t3(1);

            Assert::IsTrue(*t1 == t2, L"Types with the same index should be equal.");
            Assert::IsTrue(*t1 != t3, L"Types with different indices should be unequal.");
            Assert::IsTrue(*t1 < t3, L"Type orders are determined by their indices.");

            delete t1;
        }

        TEST_METHOD(TestOutput)
        {
            Type* droid = new Type(1138);
            std::cout << droid << std::endl;
        }

    };


    /*
     * Test for TypeTable Struct and associated methods within types.h
     */
    TEST_CLASS(TypeTableTest)
    {
    public:

        TEST_METHOD(TestStaticMembers)
        {
            Type obj_type = TypeTable::OBJECT;
            Assert::IsTrue(obj_type.simple(), L"The higher level Object type registered to the type table is a simple type.");

            std::string obj_name = TypeTable::OBJECT_NAME;
            std::string expected = "object";
            Assert::AreEqual(expected, obj_name, L"The top level object should be called 'object' ");


            std::string number_name = TypeTable::NUMBER_NAME;
            expected = "number";
            Assert::AreEqual(expected, number_name, L"The top level number type should be called 'type'");
        }

        TEST_METHOD(TestObjectHierarchy)
        {
            read_file("..\\test\\travel_domain.pddl");
            read_file("..\\test\\travel_problem.pddl");
            const Domain* domain = Domain::find("travel");
            const Problem* problem = Problem::find("travel-to-la");


            // Check the typing hierarchy
            TypeTable tt = domain->types();
            Type object = TypeTable::OBJECT;
            const Type* place = tt.find_type("place");
            const Type* transport = tt.find_type("transport");
            const Type* person = tt.find_type("person");
            const Type* plane = tt.find_type("plane");
            const Type* car = tt.find_type("car");

            // All types are subtypes of object
            Assert::IsTrue(TypeTable::subtype(*place, object));
            Assert::IsTrue(TypeTable::subtype(*transport, object));
            Assert::IsTrue(TypeTable::subtype(*person, object));
            Assert::IsTrue(TypeTable::subtype(*plane, object));
            Assert::IsTrue(TypeTable::subtype(*car, object));

            // Object is not a subtype of anything
            Assert::IsFalse(TypeTable::subtype(object, *place));
            Assert::IsFalse(TypeTable::subtype(object, *transport));
            Assert::IsFalse(TypeTable::subtype(object, *person));
            Assert::IsFalse(TypeTable::subtype(object, *plane));
            Assert::IsFalse(TypeTable::subtype(object, *car));


            // Plane and Car are subtypes of Transport
            Assert::IsTrue(TypeTable::subtype(*plane, *transport));
            Assert::IsTrue(TypeTable::subtype(*car, *transport));

            // Transport is not a subtype of Plane or Car
            Assert::IsFalse(TypeTable::subtype(*transport, *plane));
            Assert::IsFalse(TypeTable::subtype(*transport, *car));


        }

    };
}
