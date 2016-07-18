#include "stdafx.h"
#include "CppUnitTest.h"
#include "../types.h"

#ifdef VHPOP_EXPORTS
#define API __declspec(dllexport)
#else
#define API __declspec(dllimport)
#endif

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
        }

    };




}