#include "stdafx.h"
#include <stdlib.h>
#include "CppUnitTest.h"


using namespace Microsoft::VisualStudio::CppUnitTestFramework;

/* The parse function. */
extern int yyparse();

/* File to parse. */
extern FILE* yyin;

/* Name of current file. */
std::string curr;

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
        curr = name;
        bool success = (yyparse() == 0);        
        fclose(yyin);
        return success;
    }
}

namespace test
{
	TEST_CLASS(DecompositionParseTest)
	{
	public:
		
		TEST_METHOD(ParseAbstractAction)
		{
            read_file("E:\\Developer\\vhpop\\test\\composite_action.pddl");
		}

	};
}