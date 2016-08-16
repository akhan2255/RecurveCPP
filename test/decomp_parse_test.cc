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

std::wstring to_wstring(std::string const& str)
{
    size_t len = mbstowcs(nullptr, &str[0], 0);
    if (len == -1) // invalid source str, throw
        return NULL;
        
    std::wstring wstr(len, 0);
    mbstowcs(&wstr[0], &str[0], wstr.size());
    return wstr;
}

char* file_to_string(FILE *f, int *len) {
    if (fseek(f, 0, SEEK_END)) return NULL; //handle error
    int buflen = ftell(f);
    if (len) *len = buflen;
    char *buf = (char*) malloc(buflen + 1);
    buf[buflen] = '\0';
    rewind(f);
    size_t readlen = fread(buf, 1, buflen, f);
    if (readlen != buflen) return NULL; //handle error
    // in particular, note readlen might not equal buflen in the face of text-mode
    // conversions, but tmpfile() indicates binary-mode, so doesn't affect this
    // case
    return buf;
}




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
        bool success = true; // (yyparse() == 0);
        fputs("written to temporary file\n", yyin);

        const char *s = file_to_string(yyin, NULL);


        Assert::IsTrue(false, to_wstring(s).c_str());
        std::cout << "HELLO WORLD" << std::endl;
        
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
            Assert::IsTrue(false, L"The type should have changed as instructed.");
		}

	};
}