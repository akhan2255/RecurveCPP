/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 24 "pddl.yy" /* yacc.c:339  */

#include "requirements.h"
#include "problems.h"
#include "domains.h"
#include "formulas.h"
#include "types.h"
#include <typeinfo>
#include <utility>
#include <cstdlib>
#include <iostream>


/* Workaround for bug in Bison 1.35 that disables stack growth. */
#define YYLTYPE_IS_TRIVIAL 1

/* Name of package */
#define PACKAGE "vhpop"

/* Define to the address where bug reports for this package should be sent. */
#define PACKAGE_BUGREPORT "lorens@cs.cmu.edu"

/* Define to the full name of this package. */
#define PACKAGE_NAME "VHPOP"

/* Define to the full name and version of this package. */
#define PACKAGE_STRING "VHPOP 3.0"

/* Define to the one symbol short name of this package. */
#define PACKAGE_TARNAME "vhpop"

/* Define to the version of this package. */
#define PACKAGE_VERSION "3.0"

/*
 * Context of free variables.
 */
struct Context {
  void push_frame() {
    frames_.push_back(VariableMap());
  }

  void pop_frame() {
    frames_.pop_back();
  }

  void insert(const std::string& name, const Variable& v) {
    frames_.back().insert(std::make_pair(name, v));
  }

  const Variable* shallow_find(const std::string& name) const {
    VariableMap::const_iterator vi = frames_.back().find(name);
    if (vi != frames_.back().end()) {
      return &(*vi).second;
    } else {
      return 0;
    }
  }

  const Variable* find(const std::string& name) const {
    for (std::vector<VariableMap>::const_reverse_iterator fi =
	   frames_.rbegin(); fi != frames_.rend(); fi++) {
      VariableMap::const_iterator vi = (*fi).find(name);
      if (vi != (*fi).end()) {
	return &(*vi).second;
      }
    }
    return 0;
  }

private:
  struct VariableMap : public std::map<std::string, Variable> {
  };

  std::vector<VariableMap> frames_;
};


/* The lexer. */
extern int yylex();

/* Current line number. */
extern size_t line_number;

/* Name of current file. */
extern std::string current_file;

/* Level of warnings. */
extern int warning_level;

/* Whether the last parsing attempt succeeded. */
static bool success = true;

/* Current domain. */
static Domain* domain;

/* Domains. */
static std::map<std::string, Domain*> domains;

/* Problem being parsed, or 0 if no problem is being parsed. */
static Problem* problem;

/* Current requirements. */
static Requirements* requirements;

/* Predicate being parsed. */
static const Predicate* predicate;

/* Whether predicate declaration is repeated. */
static bool repeated_predicate;

/* Function being parsed. */
static const Function* function;

/* Whether function declaration is repeated. */
static bool repeated_function;

/* Action being parsed, or 0 if no action is being parsed. */
static ActionSchema* action;

/* Time of current condition. */ 
static FormulaTime formula_time; 

/* Time of current effect. */
static Effect::EffectTime effect_time;

/* Condition for effect being parsed, or 0 if unconditional effect. */
static const Formula* effect_condition; 

/* Current variable context. */
static Context context;

/* Predicate for atomic formula being parsed. */
static const Predicate* atom_predicate;

/* Whether the predicate of the currently parsed atom was undeclared. */
static bool undeclared_atom_predicate;

/* Whether parsing metric fluent. */
static bool metric_fluent;

/* Function for fluent being parsed. */
static const Function* fluent_function;

/* Whether the function of the currently parsed fluent was undeclared. */
static bool undeclared_fluent_function;

/* Paramerers for atomic formula or fluent being parsed. */
static TermList term_parameters;

/* Quantified variables for effect or formula being parsed. */
static TermList quantified;

/* Kind of name map being parsed. */
static enum { TYPE_KIND, CONSTANT_KIND, OBJECT_KIND, VOID_KIND } name_kind;

/* Outputs an error message. */
static void yyerror(const std::string& s); 

/* Outputs a warning message. */
static void yywarning(const std::string& s);

/* Creates an empty domain with the given name. */
static void make_domain(const std::string* name);

/* Creates an empty problem with the given name. */
static void make_problem(const std::string* name,
			 const std::string* domain_name);

/* Adds :typing to the requirements. */
static void require_typing();

/* Adds :fluents to the requirements. */
static void require_fluents();

/* Adds :disjunctive-preconditions to the requirements. */
static void require_disjunction();

/* Adds :duration-inequalities to the requirements. */
static void require_duration_inequalities();

/* Adds: :decompositions to the requirements. */
static void require_decompositions();

/* Returns a simple type with the given name. */
static const Type& make_type(const std::string* name);

/* Returns the union of the given types. */
static Type make_type(const TypeSet& types);

/* Returns a simple term with the given name. */
static Term make_term(const std::string* name);

/* Creates a predicate with the given name. */
static void make_predicate(const std::string* name);

/* Creates a function with the given name. */
static void make_function(const std::string* name);

/* Creates an action with the given name. */
static void make_action(const std::string* name, bool durative, bool composite);

/* Adds the current action to the current domain. */ 
static void add_action();

/* Prepares for the parsing of a universally quantified effect. */ 
static void prepare_forall_effect();

/* Prepares for the parsing of a conditional effect. */ 
static void prepare_conditional_effect(const Formula& condition);

/* Adds types, constants, or objects to the current domain or problem. */
static void add_names(const std::vector<const std::string*>* names,
		      const Type& type);

/* Adds variables to the current variable list. */
static void add_variables(const std::vector<const std::string*>* names,
			  const Type& type);

/* Prepares for the parsing of an atomic formula. */ 
static void prepare_atom(const std::string* name);

/* Prepares for the parsing of a fluent. */ 
static void prepare_fluent(const std::string* name);

/* Adds a term with the given name to the current atomic formula. */
static void add_term(const std::string* name);

/* Creates the atomic formula just parsed. */
static const Atom* make_atom();

/* Creates the fluent just parsed. */
static const Fluent* make_fluent();

/* Creates a subtraction. */
static const Expression* make_subtraction(const Expression& term,
					  const Expression* opt_term);

/* Creates an equality formula. */
static const Formula* make_equality(const Term* term1, const Term* term2);

/* Creates a negation. */
static const Formula* make_negation(const Formula& negand);

/* Prepares for the parsing of an existentially quantified formula. */
static void prepare_exists();

/* Prepares for the parsing of a universally quantified formula. */
static void prepare_forall();

/* Creates an existentially quantified formula. */
static const Formula* make_exists(const Formula& body);

/* Creates a universally quantified formula. */
static const Formula* make_forall(const Formula& body);

/* Adds the given literal as an effect to the currect action. */
static void add_effect(const Literal& literal);

/* Pops the top-most universally quantified variables. */
static void pop_forall_effect();

/* Adds a timed initial literal to the current problem. */
static void add_init_literal(float time, const Literal& literal);

#line 331 "pddl.cc" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "pddl.hh".  */
#ifndef YY_YY_PDDL_HH_INCLUDED
# define YY_YY_PDDL_HH_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    DEFINE = 258,
    DOMAIN_TOKEN = 259,
    PROBLEM = 260,
    REQUIREMENTS = 261,
    TYPES = 262,
    CONSTANTS = 263,
    PREDICATES = 264,
    FUNCTIONS = 265,
    STRIPS = 266,
    TYPING = 267,
    NEGATIVE_PRECONDITIONS = 268,
    DISJUNCTIVE_PRECONDITIONS = 269,
    EQUALITY = 270,
    EXISTENTIAL_PRECONDITIONS = 271,
    UNIVERSAL_PRECONDITIONS = 272,
    QUANTIFIED_PRECONDITIONS = 273,
    CONDITIONAL_EFFECTS = 274,
    FLUENTS = 275,
    ADL = 276,
    DURATIVE_ACTIONS = 277,
    DURATION_INEQUALITIES = 278,
    CONTINUOUS_EFFECTS = 279,
    TIMED_INITIAL_LITERALS = 280,
    ACTION = 281,
    PARAMETERS = 282,
    PRECONDITION = 283,
    EFFECT = 284,
    DURATIVE_ACTION = 285,
    DURATION = 286,
    CONDITION = 287,
    PDOMAIN = 288,
    OBJECTS = 289,
    INIT = 290,
    GOAL = 291,
    METRIC = 292,
    WHEN = 293,
    NOT = 294,
    AND = 295,
    OR = 296,
    IMPLY = 297,
    EXISTS = 298,
    FORALL = 299,
    AT = 300,
    OVER = 301,
    START = 302,
    END = 303,
    ALL = 304,
    MINIMIZE = 305,
    MAXIMIZE = 306,
    TOTAL_TIME = 307,
    NUMBER_TOKEN = 308,
    OBJECT_TOKEN = 309,
    EITHER = 310,
    LE = 311,
    GE = 312,
    NAME = 313,
    DURATION_VAR = 314,
    VARIABLE = 315,
    NUMBER = 316,
    ILLEGAL_TOKEN = 317,
    DECOMPOSITIONS = 318,
    ABSTRACT = 319
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 307 "pddl.yy" /* yacc.c:355  */

  const Formula* formula;
  const Literal* literal;
  const Atom* atom;
  const Expression* expr;
  const Fluent* fluent;
  const Term* term;
  const Type* type;
  TypeSet* types;
  const std::string* str;
  std::vector<const std::string*>* strs;
  float num;

#line 450 "pddl.cc" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_PDDL_HH_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 467 "pddl.cc" /* yacc.c:358  */

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif


#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   1073

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  74
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  156
/* YYNRULES -- Number of rules.  */
#define YYNRULES  337
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  552

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   319

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      65,    66,    72,    71,     2,    67,     2,    73,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    70,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,    69,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,    68,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   341,   341,   341,   345,   346,   347,   354,   354,   358,
     359,   360,   361,   364,   365,   366,   369,   370,   371,   372,
     373,   374,   375,   378,   379,   380,   381,   382,   385,   386,
     387,   388,   389,   392,   393,   394,   395,   396,   399,   400,
     401,   404,   405,   406,   409,   410,   411,   414,   415,   418,
     421,   424,   425,   428,   429,   430,   432,   434,   435,   437,
     439,   441,   442,   443,   444,   445,   447,   449,   454,   457,
     457,   461,   461,   465,   468,   468,   475,   476,   479,   479,
     483,   484,   485,   488,   489,   492,   492,   495,   495,   505,
     505,   506,   506,   509,   510,   513,   514,   517,   518,   521,
     522,   525,   525,   528,   528,   531,   532,   535,   536,   539,
     540,   547,   548,   552,   557,   562,   566,   567,   575,   576,
     579,   580,   583,   583,   584,   584,   585,   585,   592,   593,
     594,   594,   596,   597,   596,   601,   602,   605,   606,   609,
     610,   614,   615,   618,   619,   620,   620,   622,   622,   626,
     627,   631,   630,   634,   633,   638,   639,   640,   640,   642,
     642,   646,   647,   655,   654,   659,   660,   663,   664,   667,
     668,   671,   671,   675,   678,   679,   682,   682,   684,   684,
     686,   688,   690,   694,   695,   698,   701,   701,   703,   703,
     711,   712,   713,   714,   715,   715,   716,   716,   718,   718,
     720,   720,   724,   725,   728,   729,   732,   732,   736,   736,
     740,   741,   748,   749,   750,   751,   752,   753,   756,   757,
     760,   760,   762,   765,   766,   768,   770,   772,   774,   777,
     778,   781,   781,   783,   790,   791,   792,   795,   796,   799,
     800,   803,   804,   805,   805,   809,   810,   813,   814,   815,
     815,   818,   819,   822,   822,   825,   826,   827,   830,   831,
     832,   833,   836,   843,   846,   849,   852,   855,   858,   861,
     864,   867,   870,   873,   876,   879,   882,   885,   888,   891,
     894,   897,   900,   903,   906,   906,   906,   907,   908,   908,
     908,   908,   908,   909,   909,   909,   910,   913,   914,   914,
     917,   917,   917,   918,   919,   919,   919,   919,   920,   920,
     920,   921,   922,   922,   925,   928,   928,   928,   929,   929,
     929,   930,   930,   930,   930,   930,   930,   930,   931,   931,
     931,   931,   931,   932,   932,   932,   933,   936
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "DEFINE", "DOMAIN_TOKEN", "PROBLEM",
  "REQUIREMENTS", "TYPES", "CONSTANTS", "PREDICATES", "FUNCTIONS",
  "STRIPS", "TYPING", "NEGATIVE_PRECONDITIONS",
  "DISJUNCTIVE_PRECONDITIONS", "EQUALITY", "EXISTENTIAL_PRECONDITIONS",
  "UNIVERSAL_PRECONDITIONS", "QUANTIFIED_PRECONDITIONS",
  "CONDITIONAL_EFFECTS", "FLUENTS", "ADL", "DURATIVE_ACTIONS",
  "DURATION_INEQUALITIES", "CONTINUOUS_EFFECTS", "TIMED_INITIAL_LITERALS",
  "ACTION", "PARAMETERS", "PRECONDITION", "EFFECT", "DURATIVE_ACTION",
  "DURATION", "CONDITION", "PDOMAIN", "OBJECTS", "INIT", "GOAL", "METRIC",
  "WHEN", "NOT", "AND", "OR", "IMPLY", "EXISTS", "FORALL", "AT", "OVER",
  "START", "END", "ALL", "MINIMIZE", "MAXIMIZE", "TOTAL_TIME",
  "NUMBER_TOKEN", "OBJECT_TOKEN", "EITHER", "LE", "GE", "NAME",
  "DURATION_VAR", "VARIABLE", "NUMBER", "ILLEGAL_TOKEN", "DECOMPOSITIONS",
  "ABSTRACT", "'('", "')'", "'-'", "'t'", "'f'", "'='", "'+'", "'*'",
  "'/'", "$accept", "pddl_file", "$@1", "domains_and_problems",
  "domain_def", "$@2", "domain_body", "domain_body2", "domain_body3",
  "domain_body4", "domain_body5", "domain_body6", "domain_body7",
  "domain_body8", "domain_body9", "structure_defs", "structure_def",
  "require_def", "require_keys", "require_key", "types_def", "$@3",
  "constants_def", "$@4", "predicates_def", "functions_def", "$@5",
  "predicate_decls", "predicate_decl", "$@6", "function_decls",
  "function_decl_seq", "function_type_spec", "$@7", "function_decl", "$@8",
  "action_def", "$@9", "$@10", "parameters", "action_body", "action_body2",
  "action_body3", "precondition", "$@11", "effect", "$@12", "abstract",
  "da_body", "da_body2", "duration_constraint",
  "simple_duration_constraint", "simple_duration_constraints", "da_gd",
  "timed_gds", "timed_gd", "$@13", "$@14", "$@15", "eff_formula", "$@16",
  "$@17", "$@18", "eff_formulas", "one_eff_formula", "term_literal",
  "term_literals", "da_effect", "$@19", "$@20", "da_effects",
  "timed_effect", "$@21", "$@22", "a_effect", "$@23", "$@24", "a_effects",
  "problem_def", "$@25", "problem_body", "problem_body2", "problem_body3",
  "object_decl", "$@26", "init", "init_elements", "init_element", "$@27",
  "$@28", "goal_spec", "goal", "metric_spec", "$@29", "$@30", "formula",
  "$@31", "$@32", "$@33", "$@34", "conjuncts", "disjuncts",
  "atomic_term_formula", "$@35", "atomic_name_formula", "$@36",
  "name_literal", "f_exp", "opt_f_exp", "f_head", "$@37", "ground_f_exp",
  "opt_ground_f_exp", "ground_f_head", "$@38", "terms", "names", "term",
  "variables", "$@39", "variable_seq", "typed_names", "$@40", "name_seq",
  "type_spec", "$@41", "type", "types", "function_type", "define",
  "domain", "problem", "when", "not", "and", "or", "imply", "exists",
  "forall", "at", "over", "start", "end", "all", "duration_var",
  "minimize", "maximize", "number", "object", "either", "type_name",
  "predicate", "init_predicate", "function", "name", "variable", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,    40,    41,    45,   116,   102,
      61,    43,    42,    47
};
# endif

#define YYPACT_NINF -422

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-422)))

#define YYTABLE_NINF -274

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -422,    28,  -422,  -422,   -14,    76,  -422,  -422,  -422,    19,
     173,  -422,  -422,   838,   838,  -422,  -422,  -422,  -422,  -422,
    -422,  -422,  -422,  -422,  -422,  -422,  -422,  -422,  -422,  -422,
    -422,  -422,  -422,  -422,  -422,  -422,  -422,    24,    30,  -422,
      38,    43,    96,   162,    77,  -422,  -422,    91,  -422,    97,
     116,   129,   136,   139,  -422,   838,  1010,  -422,  -422,  -422,
    -422,   838,   838,  -422,   149,  -422,   131,  -422,   176,  -422,
     150,  -422,    91,   156,   160,   179,  -422,    91,   156,   196,
      45,  -422,    91,   160,   196,   148,  -422,  -422,  -422,  -422,
    -422,  -422,  -422,  -422,  -422,  -422,  -422,  -422,  -422,  -422,
    -422,  -422,   916,  -422,   838,   838,   158,   203,  -422,  -422,
      68,  -422,    91,    91,   125,  -422,    91,    91,  -422,    59,
    -422,    91,    91,  -422,  -422,  -422,  -422,  -422,   161,   491,
    -422,   170,   962,  -422,  -422,   838,   205,   155,  -422,   248,
     248,    91,    91,    91,   228,  -422,  -422,  -422,  -422,  -422,
    -422,  -422,  -422,  -422,  -422,  -422,  -422,  -422,  -422,  -422,
    -422,  -422,  -422,  -422,  -422,  -422,  -422,  -422,  -422,  -422,
    -422,   203,  -422,   235,    -5,   270,    66,   245,   236,  -422,
    -422,   246,   249,  -422,   252,   782,   838,   253,   253,   267,
    -422,   253,  -422,  -422,   122,   255,  -422,  -422,    -2,   258,
    -422,   259,  -422,  -422,   261,   177,  -422,  -422,   180,  -422,
     287,  -422,   290,  -422,  -422,   273,  -422,  -422,  -422,  -422,
    -422,   263,   -24,  -422,   264,  -422,  -422,  -422,   265,   261,
     268,  -422,  -422,  -422,  -422,  -422,    74,   171,  -422,   838,
     165,   237,   266,  -422,   182,  -422,   995,  -422,  -422,  -422,
    -422,  -422,  -422,   868,  -422,  -422,  -422,  -422,   275,   275,
     275,  -422,   271,   272,   269,  -422,   277,   458,  -422,  -422,
    -422,  -422,  -422,  -422,  -422,   810,   261,  -422,  -422,  -422,
    -422,  -422,  -422,  -422,  -422,  -422,  -422,  -422,   371,  -422,
    -422,   253,  -422,  -422,   279,  -422,  -422,  -422,   695,   695,
     695,   169,     1,  -422,  -422,    41,   309,  -422,  -422,  -422,
    -422,  -422,  -422,   288,  -422,  -422,  -422,  -422,  -422,  -422,
    -422,  -422,  -422,  -422,  -422,   754,   283,   289,  -422,   810,
    -422,  -422,   285,   172,  -422,   261,   291,   292,  -422,   723,
     723,  -422,  -422,  -422,  -422,   261,   962,   286,   183,   293,
    -422,   342,   294,  -422,  -422,   295,   296,   -26,  -422,  -422,
    -422,   272,  -422,  -422,   197,  -422,  -422,   197,   304,  -422,
    -422,   838,   302,  -422,   962,   298,   300,  -422,   301,  -422,
    -422,  -422,   185,   261,   253,   253,   521,  -422,   402,   303,
    -422,   305,  -422,  -422,  -422,  -422,   253,   695,   695,   695,
     695,  -422,  -422,  -422,  -422,  -422,   187,   307,  -422,  -422,
    -422,  -422,   198,  -422,  -422,  -422,  -422,   579,  -422,   311,
    -422,  -422,   939,  -422,   312,   608,  -422,  -422,  -422,   313,
     332,   333,  -422,  -422,  -422,   723,   723,   723,   723,  -422,
    -422,   336,   337,   695,   695,   695,   695,  -422,   343,  -422,
    -422,   253,   345,   345,   221,  -422,  -422,   261,   261,   261,
    -422,  -422,  -422,  -422,  -422,   283,  -422,  -422,  -422,   261,
     261,   723,   723,   723,   723,   906,   358,  -422,   268,  -422,
     361,   362,   364,   365,   550,   310,   366,   367,   868,  -422,
     368,   369,   370,   372,   373,   637,   666,   392,   393,   398,
    -422,   399,   400,   401,   404,  -422,  -422,   406,  -422,  -422,
    -422,  -422,  -422,  -422,   271,   261,  -422,  -422,  -422,  -422,
    -422,  -422,  -422,  -422,  -422,  -422,  -422,  -422,  -422,  -422,
    -422,  -422,   208,  -422,   410,  -422,   231,   346,   939,  -422,
    -422,  -422,   336,  -422,  -422,   253,   411,   412,  -422,   345,
     413,  -422
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
       2,     0,     4,     1,     3,     0,     5,     6,   263,     0,
       0,   264,   265,     0,     0,   315,   316,   317,   321,   322,
     323,   324,   325,   326,   327,   328,   329,   330,   331,   332,
     333,   334,   335,   318,   319,   320,   336,     0,     0,     7,
       0,     9,     0,     0,     0,    12,    15,    22,    47,    10,
      13,    16,    17,    18,    49,     0,     0,    69,    71,    76,
      74,     0,     0,     8,     0,    48,     0,    11,     0,    14,
       0,    19,    27,    23,    24,     0,    20,    32,    28,    29,
       0,    21,    37,    33,    34,     0,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    68,     0,    51,   247,   247,     0,    80,    89,    91,
       0,    25,    40,    38,     0,    26,    43,    41,    30,     0,
      31,    46,    44,    35,    36,   163,    50,    52,     0,   248,
     251,     0,     0,    73,    77,     0,     0,    81,    83,    93,
      93,    39,    42,    45,     0,    70,   253,   249,   252,    72,
     284,   285,   286,   288,   289,   290,   291,   292,   293,   294,
     295,   299,   298,   287,   296,   297,    78,    87,   314,    75,
      85,    80,    84,     0,    99,     0,     0,     0,     0,   166,
     168,     0,     0,   170,   183,     0,   247,   241,   241,     0,
      82,   241,   101,   103,     0,     0,    96,    98,    99,    99,
     100,     0,   171,   174,     0,     0,   165,   164,     0,   167,
       0,   169,     0,   184,   282,     0,   254,   255,   256,   250,
     337,     0,   242,   245,     0,   281,    86,   262,     0,     0,
       0,   105,   106,    90,    95,    97,     0,   109,   111,   247,
       0,     0,     0,   190,     0,   283,     0,    79,   243,   246,
      88,    94,   102,     0,   104,   128,   139,   268,     0,     0,
       0,   116,     0,     0,     0,   108,     0,     0,   173,   175,
     267,   269,   270,   271,   272,     0,     0,   202,   194,   196,
     198,   200,   206,   185,   279,   280,   188,   186,     0,   258,
     259,   241,   266,   132,     0,   135,   130,   278,     0,     0,
       0,     0,     0,   110,   143,     0,   109,   118,    92,   172,
     300,   301,   302,   178,   304,   305,   306,   307,   308,   309,
     310,   313,   312,   303,   311,     0,     0,     0,   176,     0,
     239,   240,     0,     0,   204,     0,     0,     0,   234,     0,
       0,   257,   260,   261,   244,     0,     0,     0,     0,     0,
     212,     0,     0,   217,   222,     0,     0,     0,   112,   117,
     273,     0,   149,   145,     0,   274,   120,     0,     0,   107,
     237,     0,     0,   233,     0,     0,     0,   237,     0,   192,
     193,   203,     0,     0,   241,   241,     0,   223,     0,     0,
     228,     0,   133,   140,   129,   136,   241,     0,     0,     0,
       0,   220,   113,   114,   115,   147,     0,     0,   275,   276,
     151,   153,     0,   122,   124,   277,   126,     0,   231,     0,
     208,   180,     0,   210,     0,     0,   191,   195,   205,     0,
       0,     0,   207,   235,   236,     0,     0,     0,     0,   189,
     187,     0,     0,   218,     0,     0,     0,   234,     0,   144,
     150,   241,     0,     0,     0,   119,   121,     0,     0,     0,
     179,   238,   237,   181,   237,     0,   182,   177,   197,     0,
       0,   229,     0,     0,     0,     0,     0,   137,     0,   219,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   155,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     230,     0,     0,     0,     0,   141,   134,     0,   214,   213,
     215,   216,   221,   148,     0,     0,   161,   157,   152,   154,
     123,   125,   127,   232,   209,   211,   199,   201,   225,   224,
     226,   227,     0,   131,     0,   159,     0,     0,     0,   138,
     142,   146,     0,   156,   162,   241,     0,     0,   160,     0,
       0,   158
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -422,  -422,  -422,  -422,  -422,  -422,  -422,   317,   318,  -422,
    -422,  -422,   276,   319,   384,   -18,    11,   226,  -422,   378,
    -422,  -422,   -15,  -422,    -1,    85,  -422,  -422,  -422,  -422,
     314,  -422,  -422,  -422,   344,  -422,  -422,  -422,  -422,   347,
    -422,   316,   299,  -422,  -422,  -422,  -422,  -422,  -422,   178,
    -422,   188,  -422,   127,  -422,    78,  -422,  -422,  -422,  -336,
    -422,  -422,  -422,  -422,   -56,  -223,  -422,  -388,  -422,  -422,
    -422,    44,  -422,  -422,  -421,  -422,  -422,  -422,  -422,  -422,
    -422,   322,   320,  -422,  -422,  -422,  -422,  -422,  -422,  -422,
     335,  -422,  -422,  -422,  -422,  -200,  -422,  -422,  -422,  -422,
    -422,  -422,  -224,  -422,  -359,  -422,  -422,  -279,  -422,  -422,
    -422,  -325,  -422,   166,  -422,    46,  -355,   186,  -186,  -422,
    -422,   -89,  -422,  -422,   278,  -422,  -422,  -422,  -422,  -422,
    -422,  -422,  -291,  -227,  -228,  -422,  -422,  -422,  -245,  -258,
    -422,   135,   151,  -422,    39,  -422,  -422,  -422,  -220,  -422,
    -166,  -128,  -422,  -132,   -13,  -212
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,     2,     4,     6,    41,    44,    45,    46,    71,
      76,    81,   111,   115,   120,    47,    48,    49,   102,   103,
      50,   104,    51,   105,    52,    53,   107,   106,   134,   187,
     136,   137,   171,   189,   138,   188,    54,   139,   140,   174,
     195,   196,   197,   198,   229,   199,   230,   200,   264,   265,
     237,   238,   301,   306,   412,   307,   457,   458,   459,   254,
     349,   345,   441,   348,   476,   489,   532,   303,   407,   448,
     406,   304,   452,   453,   490,   537,   542,   536,     7,   144,
     178,   179,   180,   181,   239,   182,   240,   269,   377,   370,
     183,   184,   213,   340,   339,   242,   334,   335,   336,   337,
     333,   382,   243,   338,   375,   464,   424,   352,   480,   353,
     447,   389,   501,   390,   462,   386,   417,   329,   221,   291,
     222,   128,   186,   129,   147,   185,   216,   288,   226,     9,
      13,    14,   293,   294,   261,   278,   279,   280,   281,   364,
     368,   410,   411,   416,   298,   286,   287,   227,   217,   246,
     165,   282,   328,   354,   168,   223
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      37,    38,   224,   167,   166,   228,   256,   255,   296,   327,
     249,   361,   395,   277,   276,   391,   131,   423,   450,   218,
     355,   356,   425,   192,   193,   295,   289,   193,     3,   252,
     258,   259,   491,    72,    77,    82,   220,    78,    83,   292,
     326,   257,    85,   146,   260,   274,   360,   367,   108,   109,
      73,     5,    84,    58,    59,   112,   116,   363,    65,   194,
     112,   121,   194,   331,   122,   116,   121,    58,   342,   122,
     347,    61,    56,   117,   362,    62,   332,   366,    60,     8,
     290,   257,   117,    65,    10,    61,   360,   365,    65,    62,
      39,   130,   130,    65,    61,   141,    40,   219,    62,   142,
     202,   203,   204,    42,   143,   344,   497,   495,    43,   496,
     471,   472,   473,   474,   257,   544,   148,   331,   443,   444,
     445,   446,   343,    65,   256,   255,   534,    65,   550,    55,
     258,   259,    65,   381,    59,   383,    74,    79,    57,    58,
      59,    60,   507,    63,   260,   392,   500,   502,   503,   504,
     266,    61,    65,    65,    65,    62,    64,    61,   113,    59,
      60,    62,    66,   113,   479,   481,   482,   483,    56,    57,
      58,    59,    60,   130,   434,    61,    61,    11,    12,    62,
      62,    68,   428,   429,    58,    59,    60,    58,    61,    60,
     231,   232,    62,   373,    70,   465,   367,   515,   430,   431,
     262,    75,    61,   263,    80,    61,    62,   373,   373,    62,
     442,   202,   203,   204,   125,   203,   204,   256,   477,   401,
     135,   110,   170,   132,   133,   114,   130,   145,   256,   256,
     267,   268,   284,   285,   357,   358,   149,   241,   380,   418,
     150,   151,   152,   517,   408,   409,   420,   505,   253,   394,
     241,   427,   302,   449,   256,   255,   418,   492,   493,   494,
     516,   119,   330,   454,   455,   487,   360,   365,   135,   498,
     499,   169,   434,   538,   539,   173,   270,   257,   271,   272,
     273,   274,   153,   154,   155,   156,   157,   158,   159,   160,
     161,   162,   163,   176,   420,   164,   488,   543,   299,   300,
     191,   201,   207,   373,   373,   373,   373,   275,   256,   540,
     205,   208,   256,   220,   210,   535,   330,   212,   256,   477,
     225,   233,   194,   204,   236,   256,   241,   244,   245,   247,
     250,   251,   283,   253,   297,   308,   302,   305,   262,   373,
     373,   373,   373,   309,   346,    15,    16,    17,   374,  -273,
     376,   379,   393,   415,   118,   360,   384,   385,   396,   547,
     402,   403,   404,   419,   421,   422,    67,   426,    69,   439,
     177,   440,   451,   433,   150,   151,   152,   463,   466,   468,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,   469,   470,
      36,   475,   123,   478,   461,    15,    16,    17,   485,   397,
     488,   545,   461,   398,   399,   400,   153,   154,   155,   156,
     157,   158,   159,   160,   506,   214,   163,   508,   509,   164,
     510,   511,   513,   514,   518,   519,   520,   341,   521,   522,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,   525,   526,
      36,   310,   311,   312,   527,   528,   529,   530,   124,   435,
     531,   433,   533,   436,   437,   438,   541,   548,   549,   551,
     127,   172,   461,   461,   369,   190,   546,   175,   405,   359,
     456,   372,   486,   484,    15,    16,    17,   270,   235,   206,
     248,   209,   413,   313,   314,   315,   316,   317,   318,   319,
     320,   321,   322,   323,   234,   378,   324,   211,   414,     0,
       0,     0,     0,     0,    15,    16,    17,     0,   325,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,     0,     0,    36,
       0,     0,     0,    15,    16,    17,     0,     0,   146,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,     0,     0,    36,
       0,   220,    15,    16,    17,     0,     0,   432,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,     0,     0,    36,     0,
     220,    15,    16,    17,     0,     0,   512,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,     0,     0,    36,     0,     0,
      15,    16,    17,     0,     0,   460,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,     0,     0,    36,     0,     0,    15,
      16,    17,     0,     0,   467,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,     0,     0,    36,     0,     0,    15,    16,
      17,     0,     0,   523,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,     0,     0,    36,     0,    15,    16,    17,     0,
       0,     0,   524,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,     0,     0,    36,     0,     0,   350,    15,    16,    17,
     351,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,     0,
       0,    36,     0,     0,   387,   150,   151,   152,   388,     0,
       0,     0,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
       0,     0,    36,    15,    16,    17,     0,     0,     0,   371,
       0,     0,     0,     0,     0,     0,     0,   153,   154,   155,
     156,   157,   158,   159,   160,     0,   214,   163,     0,     0,
     164,    15,    16,    17,     0,     0,     0,   215,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,     0,     0,    36,     0,
     220,   150,   151,   152,     0,     0,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,     0,     0,    36,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   292,   270,   257,   150,
     151,   152,   274,   153,   154,   155,   156,   157,   158,   159,
     160,   161,   162,   163,     0,     0,   164,    86,    87,    88,
      89,    90,    91,    92,    93,    94,    95,    96,    97,    98,
      99,   100,   150,   151,   152,   270,   257,     0,     0,     0,
       0,   153,   154,   155,   156,   157,   158,   159,   160,   161,
     162,   163,     0,     0,   164,   150,   151,   152,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   270,   101,
       0,     0,   126,     0,   153,   154,   155,   156,   157,   158,
     159,   160,   161,   162,   163,     0,     0,   164,   150,   151,
     152,     0,     0,     0,     0,     0,     0,   153,   154,   155,
     156,   157,   158,   159,   160,   161,   162,   163,     0,     0,
     164,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,     0,     0,     0,     0,
     153,   154,   155,   156,   157,   158,   159,   160,     0,   214,
     163,     0,     0,   164,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   101
};

static const yytype_int16 yycheck[] =
{
      13,    14,   188,   135,   132,   191,   230,   230,   253,   267,
     222,   302,   348,   241,   241,   340,   105,   376,   406,   185,
     299,   300,   377,    28,    29,   253,   246,    29,     0,   229,
      56,    57,   453,    51,    52,    53,    60,    52,    53,    38,
     267,    40,    55,    67,    70,    44,    45,   305,    61,    62,
      51,    65,    53,     8,     9,    73,    74,   302,    47,    64,
      78,    79,    64,   275,    79,    83,    84,     8,   288,    84,
     294,    26,     6,    74,   302,    30,   276,   305,    10,     3,
     246,    40,    83,    72,    65,    26,    45,    46,    77,    30,
      66,   104,   105,    82,    26,   113,    66,   186,    30,   117,
      34,    35,    36,    65,   122,   291,   465,   462,    65,   464,
     435,   436,   437,   438,    40,   536,   129,   329,   397,   398,
     399,   400,   288,   112,   348,   348,   514,   116,   549,    33,
      56,    57,   121,   333,     9,   335,    51,    52,     7,     8,
       9,    10,   478,    66,    70,   345,   471,   472,   473,   474,
     239,    26,   141,   142,   143,    30,    65,    26,    73,     9,
      10,    30,    65,    78,   443,   444,   445,   446,     6,     7,
       8,     9,    10,   186,   386,    26,    26,     4,     5,    30,
      30,    65,   382,   383,     8,     9,    10,     8,    26,    10,
      68,    69,    30,   325,    65,   422,   454,   488,   384,   385,
      29,    65,    26,    32,    65,    26,    30,   339,   340,    30,
     396,    34,    35,    36,    66,    35,    36,   441,   441,   351,
      65,    65,    67,    65,    66,    65,   239,    66,   452,   453,
      65,    66,    50,    51,    65,    66,    66,    65,    66,   371,
       3,     4,     5,   488,    47,    48,   374,   475,    65,    66,
      65,    66,    65,    66,   478,   478,   388,   457,   458,   459,
     488,    65,   275,    65,    66,   451,    45,    46,    65,   469,
     470,    66,   484,    65,    66,    27,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    65,   422,    58,    65,    66,   259,   260,
      65,    31,    66,   435,   436,   437,   438,    70,   532,   532,
      65,    65,   536,    60,    65,   515,   329,    65,   542,   542,
      53,    66,    64,    36,    65,   549,    65,    37,    55,    66,
      66,    66,    66,    65,    59,    66,    65,    65,    29,   471,
     472,   473,   474,    66,    65,     3,     4,     5,    65,    61,
      61,    66,    66,    49,    78,    45,    65,    65,    65,   545,
      66,    66,    66,    61,    66,    65,    49,    66,    50,    66,
     144,    66,    65,   386,     3,     4,     5,    66,    66,    66,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    66,    66,
      58,    65,    83,    66,   417,     3,     4,     5,    65,    67,
      65,    65,   425,    71,    72,    73,    45,    46,    47,    48,
      49,    50,    51,    52,    66,    54,    55,    66,    66,    58,
      66,    66,    66,    66,    66,    66,    66,    66,    66,    66,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    66,    66,
      58,     3,     4,     5,    66,    66,    66,    66,    84,    67,
      66,   484,    66,    71,    72,    73,    66,    66,    66,    66,
     102,   137,   495,   496,   306,   171,   542,   140,   361,   301,
     412,   325,   448,   447,     3,     4,     5,    39,   199,   177,
     222,   181,   367,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,   198,   329,    58,   182,   367,    -1,
      -1,    -1,    -1,    -1,     3,     4,     5,    -1,    70,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    -1,    -1,    58,
      -1,    -1,    -1,     3,     4,     5,    -1,    -1,    67,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    -1,    -1,    58,
      -1,    60,     3,     4,     5,    -1,    -1,    66,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    -1,    -1,    58,    -1,
      60,     3,     4,     5,    -1,    -1,    66,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    -1,    -1,    58,    -1,    -1,
       3,     4,     5,    -1,    -1,    66,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    -1,    -1,    58,    -1,    -1,     3,
       4,     5,    -1,    -1,    66,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    -1,    -1,    58,    -1,    -1,     3,     4,
       5,    -1,    -1,    66,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    -1,    -1,    58,    -1,     3,     4,     5,    -1,
      -1,    -1,    66,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    -1,    -1,    58,    -1,    -1,    61,     3,     4,     5,
      65,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    -1,
      -1,    58,    -1,    -1,    61,     3,     4,     5,    65,    -1,
      -1,    -1,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      -1,    -1,    58,     3,     4,     5,    -1,    -1,    -1,    65,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    45,    46,    47,
      48,    49,    50,    51,    52,    -1,    54,    55,    -1,    -1,
      58,     3,     4,     5,    -1,    -1,    -1,    65,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    -1,    -1,    58,    -1,
      60,     3,     4,     5,    -1,    -1,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    -1,    -1,    58,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    38,    39,    40,     3,
       4,     5,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    -1,    -1,    58,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,     3,     4,     5,    39,    40,    -1,    -1,    -1,
      -1,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    -1,    -1,    58,     3,     4,     5,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    39,    63,
      -1,    -1,    66,    -1,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    -1,    -1,    58,     3,     4,
       5,    -1,    -1,    -1,    -1,    -1,    -1,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    -1,    -1,
      58,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    -1,    -1,    -1,    -1,
      45,    46,    47,    48,    49,    50,    51,    52,    -1,    54,
      55,    -1,    -1,    58,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    63
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    75,    76,     0,    77,    65,    78,   152,     3,   203,
      65,     4,     5,   204,   205,     3,     4,     5,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    58,   228,   228,    66,
      66,    79,    65,    65,    80,    81,    82,    89,    90,    91,
      94,    96,    98,    99,   110,    33,     6,     7,     8,     9,
      10,    26,    30,    66,    65,    90,    65,    81,    65,    82,
      65,    83,    89,    98,    99,    65,    84,    89,    96,    99,
      65,    85,    89,    96,    98,   228,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    63,    92,    93,    95,    97,   101,   100,   228,   228,
      65,    86,    89,    99,    65,    87,    89,    98,    86,    65,
      88,    89,    96,    87,    88,    66,    66,    93,   195,   197,
     228,   195,    65,    66,   102,    65,   104,   105,   108,   111,
     112,    89,    89,    89,   153,    66,    67,   198,   228,    66,
       3,     4,     5,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    58,   224,   225,   227,   228,    66,
      67,   106,   108,    27,   113,   113,    65,    91,   154,   155,
     156,   157,   159,   164,   165,   199,   196,   103,   109,   107,
     104,    65,    28,    29,    64,   114,   115,   116,   117,   119,
     121,    31,    34,    35,    36,    65,   155,    66,    65,   156,
      65,   164,    65,   166,    54,    65,   200,   222,   224,   195,
      60,   192,   194,   229,   192,    53,   202,   221,   192,   118,
     120,    68,    69,    66,   115,   116,    65,   124,   125,   158,
     160,    65,   169,   176,    37,    55,   223,    66,   198,   229,
      66,    66,   169,    65,   133,   139,   176,    40,    56,    57,
      70,   208,    29,    32,   122,   123,   195,    65,    66,   161,
      39,    41,    42,    43,    44,    70,   207,   208,   209,   210,
     211,   212,   225,    66,    50,    51,   219,   220,   201,   222,
     224,   193,    38,   206,   207,   208,   212,    59,   218,   218,
     218,   126,    65,   141,   145,    65,   127,   129,    66,    66,
       3,     4,     5,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    58,    70,   207,   213,   226,   191,
     228,   229,   169,   174,   170,   171,   172,   173,   177,   168,
     167,    66,   222,   224,   192,   135,    65,   176,   137,   134,
      61,    65,   181,   183,   227,   181,   181,    65,    66,   125,
      45,   206,   208,   212,   213,    46,   208,   213,   214,   123,
     163,    65,   187,   227,    65,   178,    61,   162,   191,    66,
      66,   169,   175,   169,    65,    65,   189,    61,    65,   185,
     187,   185,   169,    66,    66,   133,    65,    67,    71,    72,
      73,   227,    66,    66,    66,   127,   144,   142,    47,    48,
     215,   216,   128,   215,   216,    49,   217,   190,   227,    61,
     225,    66,    65,   178,   180,   190,    66,    66,   169,   169,
     192,   192,    66,   228,   229,    67,    71,    72,    73,    66,
      66,   136,   192,   181,   181,   181,   181,   184,   143,    66,
     141,    65,   146,   147,    65,    66,   129,   130,   131,   132,
      66,   228,   188,    66,   179,   207,    66,    66,    66,    66,
      66,   185,   185,   185,   185,    65,   138,   139,    66,   181,
     182,   181,   181,   181,   189,    65,   145,   192,    65,   139,
     148,   148,   169,   169,   169,   190,   190,   178,   169,   169,
     185,   186,   185,   185,   185,   208,    66,   133,    66,    66,
      66,    66,    66,    66,    66,   206,   208,   212,    66,    66,
      66,    66,    66,    66,    66,    66,    66,    66,    66,    66,
      66,    66,   140,    66,   141,   169,   151,   149,    65,    66,
     139,    66,   150,    66,   148,    65,   138,   192,    66,    66,
     148,    66
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    74,    76,    75,    77,    77,    77,    79,    78,    80,
      80,    80,    80,    81,    81,    81,    82,    82,    82,    82,
      82,    82,    82,    83,    83,    83,    83,    83,    84,    84,
      84,    84,    84,    85,    85,    85,    85,    85,    86,    86,
      86,    87,    87,    87,    88,    88,    88,    89,    89,    90,
      91,    92,    92,    93,    93,    93,    93,    93,    93,    93,
      93,    93,    93,    93,    93,    93,    93,    93,    93,    95,
      94,    97,    96,    98,   100,    99,   101,   101,   103,   102,
     104,   104,   104,   105,   105,   107,   106,   109,   108,   111,
     110,   112,   110,   113,   113,   114,   114,   115,   115,   116,
     116,   118,   117,   120,   119,   121,   121,   122,   122,   123,
     123,   124,   124,   125,   125,   125,   126,   126,   127,   127,
     128,   128,   130,   129,   131,   129,   132,   129,   133,   133,
     134,   133,   135,   136,   133,   137,   137,   138,   138,   139,
     139,   140,   140,   141,   141,   142,   141,   143,   141,   144,
     144,   146,   145,   147,   145,   148,   148,   149,   148,   150,
     148,   151,   151,   153,   152,   154,   154,   155,   155,   156,
     156,   158,   157,   159,   160,   160,   162,   161,   163,   161,
     161,   161,   161,   164,   164,   165,   167,   166,   168,   166,
     169,   169,   169,   169,   170,   169,   171,   169,   172,   169,
     173,   169,   174,   174,   175,   175,   177,   176,   179,   178,
     180,   180,   181,   181,   181,   181,   181,   181,   182,   182,
     184,   183,   183,   185,   185,   185,   185,   185,   185,   186,
     186,   188,   187,   187,   189,   189,   189,   190,   190,   191,
     191,   192,   192,   193,   192,   194,   194,   195,   195,   196,
     195,   197,   197,   199,   198,   200,   200,   200,   201,   201,
     201,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   224,   224,   224,   224,   224,
     224,   224,   224,   224,   224,   224,   224,   225,   225,   225,
     226,   226,   226,   226,   226,   226,   226,   226,   226,   226,
     226,   226,   226,   226,   227,   228,   228,   228,   228,   228,
     228,   228,   228,   228,   228,   228,   228,   228,   228,   228,
     228,   228,   228,   228,   228,   228,   228,   229
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     2,     0,     2,     2,     0,     9,     0,
       1,     2,     1,     1,     2,     1,     1,     1,     1,     2,
       2,     2,     1,     1,     1,     2,     2,     1,     1,     1,
       2,     2,     1,     1,     1,     2,     2,     1,     1,     2,
       1,     1,     2,     1,     1,     2,     1,     1,     2,     1,
       4,     1,     2,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     0,
       5,     0,     5,     4,     0,     5,     0,     2,     0,     5,
       0,     1,     3,     1,     2,     0,     3,     0,     5,     0,
       7,     0,     9,     0,     4,     2,     1,     2,     1,     0,
       1,     0,     3,     0,     3,     2,     2,     3,     1,     0,
       2,     1,     4,     5,     5,     5,     0,     2,     1,     4,
       0,     2,     0,     6,     0,     6,     0,     6,     1,     4,
       0,     8,     0,     0,     7,     0,     2,     1,     4,     1,
       4,     0,     2,     1,     4,     0,     8,     0,     6,     0,
       2,     0,     6,     0,     6,     1,     4,     0,     8,     0,
       6,     0,     2,     0,    13,     2,     1,     2,     1,     2,
       1,     0,     5,     4,     0,     2,     0,     5,     0,     5,
       4,     5,     5,     1,     2,     4,     0,     6,     0,     6,
       1,     5,     4,     4,     0,     5,     0,     6,     0,     8,
       0,     8,     0,     2,     0,     2,     0,     5,     0,     5,
       1,     4,     1,     5,     5,     5,     5,     1,     0,     1,
       0,     5,     1,     1,     5,     5,     5,     5,     1,     0,
       1,     0,     5,     1,     0,     2,     2,     0,     2,     1,
       1,     0,     1,     0,     4,     1,     2,     0,     1,     0,
       4,     1,     2,     0,     3,     1,     1,     4,     1,     1,
       2,     2,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
do                                                              \
  if (yychar == YYEMPTY)                                        \
    {                                                           \
      yychar = (Token);                                         \
      yylval = (Value);                                         \
      YYPOPSTACK (yylen);                                       \
      yystate = *yyssp;                                         \
      goto yybackup;                                            \
    }                                                           \
  else                                                          \
    {                                                           \
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;                                                  \
    }                                                           \
while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            /* Fall through.  */
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        YYSTYPE *yyvs1 = yyvs;
        yytype_int16 *yyss1 = yyss;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yystacksize);

        yyss = yyss1;
        yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yytype_int16 *yyss1 = yyss;
        union yyalloc *yyptr =
          (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
#line 341 "pddl.yy" /* yacc.c:1646  */
    { success = true; line_number = 1; }
#line 2094 "pddl.cc" /* yacc.c:1646  */
    break;

  case 3:
#line 342 "pddl.yy" /* yacc.c:1646  */
    { if (!success) YYERROR; }
#line 2100 "pddl.cc" /* yacc.c:1646  */
    break;

  case 7:
#line 354 "pddl.yy" /* yacc.c:1646  */
    { make_domain((yyvsp[-1].str)); }
#line 2106 "pddl.cc" /* yacc.c:1646  */
    break;

  case 53:
#line 428 "pddl.yy" /* yacc.c:1646  */
    { requirements->strips = true; }
#line 2112 "pddl.cc" /* yacc.c:1646  */
    break;

  case 54:
#line 429 "pddl.yy" /* yacc.c:1646  */
    { requirements->typing = true; }
#line 2118 "pddl.cc" /* yacc.c:1646  */
    break;

  case 55:
#line 431 "pddl.yy" /* yacc.c:1646  */
    { requirements->negative_preconditions = true; }
#line 2124 "pddl.cc" /* yacc.c:1646  */
    break;

  case 56:
#line 433 "pddl.yy" /* yacc.c:1646  */
    { requirements->disjunctive_preconditions = true; }
#line 2130 "pddl.cc" /* yacc.c:1646  */
    break;

  case 57:
#line 434 "pddl.yy" /* yacc.c:1646  */
    { requirements->equality = true; }
#line 2136 "pddl.cc" /* yacc.c:1646  */
    break;

  case 58:
#line 436 "pddl.yy" /* yacc.c:1646  */
    { requirements->existential_preconditions = true; }
#line 2142 "pddl.cc" /* yacc.c:1646  */
    break;

  case 59:
#line 438 "pddl.yy" /* yacc.c:1646  */
    { requirements->universal_preconditions = true; }
#line 2148 "pddl.cc" /* yacc.c:1646  */
    break;

  case 60:
#line 440 "pddl.yy" /* yacc.c:1646  */
    { requirements->quantified_preconditions(); }
#line 2154 "pddl.cc" /* yacc.c:1646  */
    break;

  case 61:
#line 441 "pddl.yy" /* yacc.c:1646  */
    { requirements->conditional_effects = true; }
#line 2160 "pddl.cc" /* yacc.c:1646  */
    break;

  case 62:
#line 442 "pddl.yy" /* yacc.c:1646  */
    { requirements->fluents = true; }
#line 2166 "pddl.cc" /* yacc.c:1646  */
    break;

  case 63:
#line 443 "pddl.yy" /* yacc.c:1646  */
    { requirements->adl(); }
#line 2172 "pddl.cc" /* yacc.c:1646  */
    break;

  case 64:
#line 444 "pddl.yy" /* yacc.c:1646  */
    { requirements->durative_actions = true; }
#line 2178 "pddl.cc" /* yacc.c:1646  */
    break;

  case 65:
#line 446 "pddl.yy" /* yacc.c:1646  */
    { requirements->duration_inequalities = true; }
#line 2184 "pddl.cc" /* yacc.c:1646  */
    break;

  case 66:
#line 448 "pddl.yy" /* yacc.c:1646  */
    { yyerror("`:continuous-effects' not supported"); }
#line 2190 "pddl.cc" /* yacc.c:1646  */
    break;

  case 67:
#line 450 "pddl.yy" /* yacc.c:1646  */
    {
					requirements->durative_actions = true;
					requirements->timed_initial_literals = true;
				}
#line 2199 "pddl.cc" /* yacc.c:1646  */
    break;

  case 68:
#line 454 "pddl.yy" /* yacc.c:1646  */
    { requirements->decompositions = true; }
#line 2205 "pddl.cc" /* yacc.c:1646  */
    break;

  case 69:
#line 457 "pddl.yy" /* yacc.c:1646  */
    { require_typing(); name_kind = TYPE_KIND; }
#line 2211 "pddl.cc" /* yacc.c:1646  */
    break;

  case 70:
#line 458 "pddl.yy" /* yacc.c:1646  */
    { name_kind = VOID_KIND; }
#line 2217 "pddl.cc" /* yacc.c:1646  */
    break;

  case 71:
#line 461 "pddl.yy" /* yacc.c:1646  */
    { name_kind = CONSTANT_KIND; }
#line 2223 "pddl.cc" /* yacc.c:1646  */
    break;

  case 72:
#line 462 "pddl.yy" /* yacc.c:1646  */
    { name_kind = VOID_KIND; }
#line 2229 "pddl.cc" /* yacc.c:1646  */
    break;

  case 74:
#line 468 "pddl.yy" /* yacc.c:1646  */
    { require_fluents(); }
#line 2235 "pddl.cc" /* yacc.c:1646  */
    break;

  case 78:
#line 479 "pddl.yy" /* yacc.c:1646  */
    { make_predicate((yyvsp[0].str)); }
#line 2241 "pddl.cc" /* yacc.c:1646  */
    break;

  case 79:
#line 480 "pddl.yy" /* yacc.c:1646  */
    { predicate = 0; }
#line 2247 "pddl.cc" /* yacc.c:1646  */
    break;

  case 85:
#line 492 "pddl.yy" /* yacc.c:1646  */
    { require_typing(); }
#line 2253 "pddl.cc" /* yacc.c:1646  */
    break;

  case 87:
#line 495 "pddl.yy" /* yacc.c:1646  */
    { make_function((yyvsp[0].str)); }
#line 2259 "pddl.cc" /* yacc.c:1646  */
    break;

  case 88:
#line 496 "pddl.yy" /* yacc.c:1646  */
    { function = 0; }
#line 2265 "pddl.cc" /* yacc.c:1646  */
    break;

  case 89:
#line 505 "pddl.yy" /* yacc.c:1646  */
    { make_action((yyvsp[0].str), false, false); }
#line 2271 "pddl.cc" /* yacc.c:1646  */
    break;

  case 90:
#line 505 "pddl.yy" /* yacc.c:1646  */
    { add_action(); }
#line 2277 "pddl.cc" /* yacc.c:1646  */
    break;

  case 91:
#line 506 "pddl.yy" /* yacc.c:1646  */
    { make_action((yyvsp[0].str), true, false); }
#line 2283 "pddl.cc" /* yacc.c:1646  */
    break;

  case 92:
#line 506 "pddl.yy" /* yacc.c:1646  */
    { add_action(); }
#line 2289 "pddl.cc" /* yacc.c:1646  */
    break;

  case 101:
#line 525 "pddl.yy" /* yacc.c:1646  */
    { formula_time = AT_START; }
#line 2295 "pddl.cc" /* yacc.c:1646  */
    break;

  case 102:
#line 525 "pddl.yy" /* yacc.c:1646  */
    { action->set_condition(*(yyvsp[0].formula)); }
#line 2301 "pddl.cc" /* yacc.c:1646  */
    break;

  case 103:
#line 528 "pddl.yy" /* yacc.c:1646  */
    { effect_time = Effect::AT_END; }
#line 2307 "pddl.cc" /* yacc.c:1646  */
    break;

  case 105:
#line 531 "pddl.yy" /* yacc.c:1646  */
    { require_decompositions(); action->set_composite(true); }
#line 2313 "pddl.cc" /* yacc.c:1646  */
    break;

  case 106:
#line 532 "pddl.yy" /* yacc.c:1646  */
    { require_decompositions(); action->set_composite(false); }
#line 2319 "pddl.cc" /* yacc.c:1646  */
    break;

  case 107:
#line 535 "pddl.yy" /* yacc.c:1646  */
    { action->set_condition(*(yyvsp[-1].formula)); }
#line 2325 "pddl.cc" /* yacc.c:1646  */
    break;

  case 112:
#line 549 "pddl.yy" /* yacc.c:1646  */
    { require_duration_inequalities(); }
#line 2331 "pddl.cc" /* yacc.c:1646  */
    break;

  case 113:
#line 553 "pddl.yy" /* yacc.c:1646  */
    {
				 require_duration_inequalities();
				 action->set_max_duration(*(yyvsp[-1].expr));
			       }
#line 2340 "pddl.cc" /* yacc.c:1646  */
    break;

  case 114:
#line 558 "pddl.yy" /* yacc.c:1646  */
    {
				 require_duration_inequalities();
				 action->set_min_duration(*(yyvsp[-1].expr));
			       }
#line 2349 "pddl.cc" /* yacc.c:1646  */
    break;

  case 115:
#line 563 "pddl.yy" /* yacc.c:1646  */
    { action->set_duration(*(yyvsp[-1].expr)); }
#line 2355 "pddl.cc" /* yacc.c:1646  */
    break;

  case 119:
#line 576 "pddl.yy" /* yacc.c:1646  */
    { (yyval.formula) = (yyvsp[-1].formula); }
#line 2361 "pddl.cc" /* yacc.c:1646  */
    break;

  case 120:
#line 579 "pddl.yy" /* yacc.c:1646  */
    { (yyval.formula) = &Formula::TRUE; }
#line 2367 "pddl.cc" /* yacc.c:1646  */
    break;

  case 121:
#line 580 "pddl.yy" /* yacc.c:1646  */
    { (yyval.formula) = &(*(yyvsp[-1].formula) && *(yyvsp[0].formula)); }
#line 2373 "pddl.cc" /* yacc.c:1646  */
    break;

  case 122:
#line 583 "pddl.yy" /* yacc.c:1646  */
    { formula_time = AT_START; }
#line 2379 "pddl.cc" /* yacc.c:1646  */
    break;

  case 123:
#line 583 "pddl.yy" /* yacc.c:1646  */
    { (yyval.formula) = (yyvsp[-1].formula); }
#line 2385 "pddl.cc" /* yacc.c:1646  */
    break;

  case 124:
#line 584 "pddl.yy" /* yacc.c:1646  */
    { formula_time = AT_END; }
#line 2391 "pddl.cc" /* yacc.c:1646  */
    break;

  case 125:
#line 584 "pddl.yy" /* yacc.c:1646  */
    { (yyval.formula) = (yyvsp[-1].formula); }
#line 2397 "pddl.cc" /* yacc.c:1646  */
    break;

  case 126:
#line 585 "pddl.yy" /* yacc.c:1646  */
    { formula_time = OVER_ALL; }
#line 2403 "pddl.cc" /* yacc.c:1646  */
    break;

  case 127:
#line 585 "pddl.yy" /* yacc.c:1646  */
    { (yyval.formula) = (yyvsp[-1].formula); }
#line 2409 "pddl.cc" /* yacc.c:1646  */
    break;

  case 130:
#line 594 "pddl.yy" /* yacc.c:1646  */
    { prepare_forall_effect(); }
#line 2415 "pddl.cc" /* yacc.c:1646  */
    break;

  case 131:
#line 595 "pddl.yy" /* yacc.c:1646  */
    { pop_forall_effect(); }
#line 2421 "pddl.cc" /* yacc.c:1646  */
    break;

  case 132:
#line 596 "pddl.yy" /* yacc.c:1646  */
    { formula_time = AT_START; }
#line 2427 "pddl.cc" /* yacc.c:1646  */
    break;

  case 133:
#line 597 "pddl.yy" /* yacc.c:1646  */
    { prepare_conditional_effect(*(yyvsp[0].formula)); }
#line 2433 "pddl.cc" /* yacc.c:1646  */
    break;

  case 134:
#line 598 "pddl.yy" /* yacc.c:1646  */
    { effect_condition = 0; }
#line 2439 "pddl.cc" /* yacc.c:1646  */
    break;

  case 139:
#line 609 "pddl.yy" /* yacc.c:1646  */
    { add_effect(*(yyvsp[0].atom)); }
#line 2445 "pddl.cc" /* yacc.c:1646  */
    break;

  case 140:
#line 611 "pddl.yy" /* yacc.c:1646  */
    { add_effect(Negation::make(*(yyvsp[-1].atom))); }
#line 2451 "pddl.cc" /* yacc.c:1646  */
    break;

  case 145:
#line 620 "pddl.yy" /* yacc.c:1646  */
    { prepare_forall_effect(); }
#line 2457 "pddl.cc" /* yacc.c:1646  */
    break;

  case 146:
#line 621 "pddl.yy" /* yacc.c:1646  */
    { pop_forall_effect(); }
#line 2463 "pddl.cc" /* yacc.c:1646  */
    break;

  case 147:
#line 622 "pddl.yy" /* yacc.c:1646  */
    { prepare_conditional_effect(*(yyvsp[0].formula)); }
#line 2469 "pddl.cc" /* yacc.c:1646  */
    break;

  case 148:
#line 623 "pddl.yy" /* yacc.c:1646  */
    { effect_condition = 0; }
#line 2475 "pddl.cc" /* yacc.c:1646  */
    break;

  case 151:
#line 631 "pddl.yy" /* yacc.c:1646  */
    { effect_time = Effect::AT_START; formula_time = AT_START; }
#line 2481 "pddl.cc" /* yacc.c:1646  */
    break;

  case 153:
#line 634 "pddl.yy" /* yacc.c:1646  */
    { effect_time = Effect::AT_END; formula_time = AT_END; }
#line 2487 "pddl.cc" /* yacc.c:1646  */
    break;

  case 157:
#line 640 "pddl.yy" /* yacc.c:1646  */
    { prepare_forall_effect(); }
#line 2493 "pddl.cc" /* yacc.c:1646  */
    break;

  case 158:
#line 641 "pddl.yy" /* yacc.c:1646  */
    { pop_forall_effect(); }
#line 2499 "pddl.cc" /* yacc.c:1646  */
    break;

  case 159:
#line 642 "pddl.yy" /* yacc.c:1646  */
    { prepare_conditional_effect(*(yyvsp[0].formula)); }
#line 2505 "pddl.cc" /* yacc.c:1646  */
    break;

  case 160:
#line 643 "pddl.yy" /* yacc.c:1646  */
    { effect_condition = 0; }
#line 2511 "pddl.cc" /* yacc.c:1646  */
    break;

  case 163:
#line 655 "pddl.yy" /* yacc.c:1646  */
    { make_problem((yyvsp[-5].str), (yyvsp[-1].str)); }
#line 2517 "pddl.cc" /* yacc.c:1646  */
    break;

  case 164:
#line 656 "pddl.yy" /* yacc.c:1646  */
    { delete requirements; }
#line 2523 "pddl.cc" /* yacc.c:1646  */
    break;

  case 171:
#line 671 "pddl.yy" /* yacc.c:1646  */
    { name_kind = OBJECT_KIND; }
#line 2529 "pddl.cc" /* yacc.c:1646  */
    break;

  case 172:
#line 672 "pddl.yy" /* yacc.c:1646  */
    { name_kind = VOID_KIND; }
#line 2535 "pddl.cc" /* yacc.c:1646  */
    break;

  case 176:
#line 682 "pddl.yy" /* yacc.c:1646  */
    { prepare_atom((yyvsp[0].str)); }
#line 2541 "pddl.cc" /* yacc.c:1646  */
    break;

  case 177:
#line 683 "pddl.yy" /* yacc.c:1646  */
    { problem->add_init_atom(*make_atom()); }
#line 2547 "pddl.cc" /* yacc.c:1646  */
    break;

  case 178:
#line 684 "pddl.yy" /* yacc.c:1646  */
    { prepare_atom((yyvsp[0].str)); }
#line 2553 "pddl.cc" /* yacc.c:1646  */
    break;

  case 179:
#line 685 "pddl.yy" /* yacc.c:1646  */
    { problem->add_init_atom(*make_atom()); }
#line 2559 "pddl.cc" /* yacc.c:1646  */
    break;

  case 180:
#line 687 "pddl.yy" /* yacc.c:1646  */
    { Formula::register_use((yyvsp[-1].atom)); Formula::unregister_use((yyvsp[-1].atom)); }
#line 2565 "pddl.cc" /* yacc.c:1646  */
    break;

  case 181:
#line 689 "pddl.yy" /* yacc.c:1646  */
    { problem->add_init_value(*(yyvsp[-2].fluent), (yyvsp[-1].num)); }
#line 2571 "pddl.cc" /* yacc.c:1646  */
    break;

  case 182:
#line 691 "pddl.yy" /* yacc.c:1646  */
    { add_init_literal((yyvsp[-2].num), *(yyvsp[-1].literal)); }
#line 2577 "pddl.cc" /* yacc.c:1646  */
    break;

  case 185:
#line 698 "pddl.yy" /* yacc.c:1646  */
    { problem->set_goal(*(yyvsp[-1].formula)); }
#line 2583 "pddl.cc" /* yacc.c:1646  */
    break;

  case 186:
#line 701 "pddl.yy" /* yacc.c:1646  */
    { metric_fluent = true; }
#line 2589 "pddl.cc" /* yacc.c:1646  */
    break;

  case 187:
#line 702 "pddl.yy" /* yacc.c:1646  */
    { problem->set_metric(*(yyvsp[-1].expr), true); metric_fluent = false; }
#line 2595 "pddl.cc" /* yacc.c:1646  */
    break;

  case 188:
#line 703 "pddl.yy" /* yacc.c:1646  */
    { metric_fluent = true; }
#line 2601 "pddl.cc" /* yacc.c:1646  */
    break;

  case 189:
#line 704 "pddl.yy" /* yacc.c:1646  */
    { problem->set_metric(*(yyvsp[-1].expr)); metric_fluent = false; }
#line 2607 "pddl.cc" /* yacc.c:1646  */
    break;

  case 190:
#line 711 "pddl.yy" /* yacc.c:1646  */
    { (yyval.formula) = &TimedLiteral::make(*(yyvsp[0].atom), formula_time); }
#line 2613 "pddl.cc" /* yacc.c:1646  */
    break;

  case 191:
#line 712 "pddl.yy" /* yacc.c:1646  */
    { (yyval.formula) = make_equality((yyvsp[-2].term), (yyvsp[-1].term)); }
#line 2619 "pddl.cc" /* yacc.c:1646  */
    break;

  case 192:
#line 713 "pddl.yy" /* yacc.c:1646  */
    { (yyval.formula) = make_negation(*(yyvsp[-1].formula)); }
#line 2625 "pddl.cc" /* yacc.c:1646  */
    break;

  case 193:
#line 714 "pddl.yy" /* yacc.c:1646  */
    { (yyval.formula) = (yyvsp[-1].formula); }
#line 2631 "pddl.cc" /* yacc.c:1646  */
    break;

  case 194:
#line 715 "pddl.yy" /* yacc.c:1646  */
    { require_disjunction(); }
#line 2637 "pddl.cc" /* yacc.c:1646  */
    break;

  case 195:
#line 715 "pddl.yy" /* yacc.c:1646  */
    { (yyval.formula) = (yyvsp[-1].formula); }
#line 2643 "pddl.cc" /* yacc.c:1646  */
    break;

  case 196:
#line 716 "pddl.yy" /* yacc.c:1646  */
    { require_disjunction(); }
#line 2649 "pddl.cc" /* yacc.c:1646  */
    break;

  case 197:
#line 717 "pddl.yy" /* yacc.c:1646  */
    { (yyval.formula) = &(!*(yyvsp[-2].formula) || *(yyvsp[-1].formula)); }
#line 2655 "pddl.cc" /* yacc.c:1646  */
    break;

  case 198:
#line 718 "pddl.yy" /* yacc.c:1646  */
    { prepare_exists(); }
#line 2661 "pddl.cc" /* yacc.c:1646  */
    break;

  case 199:
#line 719 "pddl.yy" /* yacc.c:1646  */
    { (yyval.formula) = make_exists(*(yyvsp[-1].formula)); }
#line 2667 "pddl.cc" /* yacc.c:1646  */
    break;

  case 200:
#line 720 "pddl.yy" /* yacc.c:1646  */
    { prepare_forall(); }
#line 2673 "pddl.cc" /* yacc.c:1646  */
    break;

  case 201:
#line 721 "pddl.yy" /* yacc.c:1646  */
    { (yyval.formula) = make_forall(*(yyvsp[-1].formula)); }
#line 2679 "pddl.cc" /* yacc.c:1646  */
    break;

  case 202:
#line 724 "pddl.yy" /* yacc.c:1646  */
    { (yyval.formula) = &Formula::TRUE; }
#line 2685 "pddl.cc" /* yacc.c:1646  */
    break;

  case 203:
#line 725 "pddl.yy" /* yacc.c:1646  */
    { (yyval.formula) = &(*(yyvsp[-1].formula) && *(yyvsp[0].formula)); }
#line 2691 "pddl.cc" /* yacc.c:1646  */
    break;

  case 204:
#line 728 "pddl.yy" /* yacc.c:1646  */
    { (yyval.formula) = &Formula::FALSE; }
#line 2697 "pddl.cc" /* yacc.c:1646  */
    break;

  case 205:
#line 729 "pddl.yy" /* yacc.c:1646  */
    { (yyval.formula) = &(*(yyvsp[-1].formula) || *(yyvsp[0].formula)); }
#line 2703 "pddl.cc" /* yacc.c:1646  */
    break;

  case 206:
#line 732 "pddl.yy" /* yacc.c:1646  */
    { prepare_atom((yyvsp[0].str)); }
#line 2709 "pddl.cc" /* yacc.c:1646  */
    break;

  case 207:
#line 733 "pddl.yy" /* yacc.c:1646  */
    { (yyval.atom) = make_atom(); }
#line 2715 "pddl.cc" /* yacc.c:1646  */
    break;

  case 208:
#line 736 "pddl.yy" /* yacc.c:1646  */
    { prepare_atom((yyvsp[0].str)); }
#line 2721 "pddl.cc" /* yacc.c:1646  */
    break;

  case 209:
#line 737 "pddl.yy" /* yacc.c:1646  */
    { (yyval.atom) = make_atom(); }
#line 2727 "pddl.cc" /* yacc.c:1646  */
    break;

  case 210:
#line 740 "pddl.yy" /* yacc.c:1646  */
    { (yyval.literal) = (yyvsp[0].atom); }
#line 2733 "pddl.cc" /* yacc.c:1646  */
    break;

  case 211:
#line 741 "pddl.yy" /* yacc.c:1646  */
    { (yyval.literal) = &Negation::make(*(yyvsp[-1].atom)); }
#line 2739 "pddl.cc" /* yacc.c:1646  */
    break;

  case 212:
#line 748 "pddl.yy" /* yacc.c:1646  */
    { (yyval.expr) = new Value((yyvsp[0].num)); }
#line 2745 "pddl.cc" /* yacc.c:1646  */
    break;

  case 213:
#line 749 "pddl.yy" /* yacc.c:1646  */
    { (yyval.expr) = &Addition::make(*(yyvsp[-2].expr), *(yyvsp[-1].expr)); }
#line 2751 "pddl.cc" /* yacc.c:1646  */
    break;

  case 214:
#line 750 "pddl.yy" /* yacc.c:1646  */
    { (yyval.expr) = make_subtraction(*(yyvsp[-2].expr), (yyvsp[-1].expr)); }
#line 2757 "pddl.cc" /* yacc.c:1646  */
    break;

  case 215:
#line 751 "pddl.yy" /* yacc.c:1646  */
    { (yyval.expr) = &Multiplication::make(*(yyvsp[-2].expr), *(yyvsp[-1].expr)); }
#line 2763 "pddl.cc" /* yacc.c:1646  */
    break;

  case 216:
#line 752 "pddl.yy" /* yacc.c:1646  */
    { (yyval.expr) = &Division::make(*(yyvsp[-2].expr), *(yyvsp[-1].expr)); }
#line 2769 "pddl.cc" /* yacc.c:1646  */
    break;

  case 217:
#line 753 "pddl.yy" /* yacc.c:1646  */
    { (yyval.expr) = (yyvsp[0].fluent); }
#line 2775 "pddl.cc" /* yacc.c:1646  */
    break;

  case 218:
#line 756 "pddl.yy" /* yacc.c:1646  */
    { (yyval.expr) = 0; }
#line 2781 "pddl.cc" /* yacc.c:1646  */
    break;

  case 220:
#line 760 "pddl.yy" /* yacc.c:1646  */
    { prepare_fluent((yyvsp[0].str)); }
#line 2787 "pddl.cc" /* yacc.c:1646  */
    break;

  case 221:
#line 761 "pddl.yy" /* yacc.c:1646  */
    { (yyval.fluent) = make_fluent(); }
#line 2793 "pddl.cc" /* yacc.c:1646  */
    break;

  case 222:
#line 762 "pddl.yy" /* yacc.c:1646  */
    { prepare_fluent((yyvsp[0].str)); (yyval.fluent) = make_fluent(); }
#line 2799 "pddl.cc" /* yacc.c:1646  */
    break;

  case 223:
#line 765 "pddl.yy" /* yacc.c:1646  */
    { (yyval.expr) = new Value((yyvsp[0].num)); }
#line 2805 "pddl.cc" /* yacc.c:1646  */
    break;

  case 224:
#line 767 "pddl.yy" /* yacc.c:1646  */
    { (yyval.expr) = &Addition::make(*(yyvsp[-2].expr), *(yyvsp[-1].expr)); }
#line 2811 "pddl.cc" /* yacc.c:1646  */
    break;

  case 225:
#line 769 "pddl.yy" /* yacc.c:1646  */
    { (yyval.expr) = make_subtraction(*(yyvsp[-2].expr), (yyvsp[-1].expr)); }
#line 2817 "pddl.cc" /* yacc.c:1646  */
    break;

  case 226:
#line 771 "pddl.yy" /* yacc.c:1646  */
    { (yyval.expr) = &Multiplication::make(*(yyvsp[-2].expr), *(yyvsp[-1].expr)); }
#line 2823 "pddl.cc" /* yacc.c:1646  */
    break;

  case 227:
#line 773 "pddl.yy" /* yacc.c:1646  */
    { (yyval.expr) = &Division::make(*(yyvsp[-2].expr), *(yyvsp[-1].expr)); }
#line 2829 "pddl.cc" /* yacc.c:1646  */
    break;

  case 228:
#line 774 "pddl.yy" /* yacc.c:1646  */
    { (yyval.expr) = (yyvsp[0].fluent); }
#line 2835 "pddl.cc" /* yacc.c:1646  */
    break;

  case 229:
#line 777 "pddl.yy" /* yacc.c:1646  */
    { (yyval.expr) = 0; }
#line 2841 "pddl.cc" /* yacc.c:1646  */
    break;

  case 231:
#line 781 "pddl.yy" /* yacc.c:1646  */
    { prepare_fluent((yyvsp[0].str)); }
#line 2847 "pddl.cc" /* yacc.c:1646  */
    break;

  case 232:
#line 782 "pddl.yy" /* yacc.c:1646  */
    { (yyval.fluent) = make_fluent(); }
#line 2853 "pddl.cc" /* yacc.c:1646  */
    break;

  case 233:
#line 783 "pddl.yy" /* yacc.c:1646  */
    { prepare_fluent((yyvsp[0].str)); (yyval.fluent) = make_fluent(); }
#line 2859 "pddl.cc" /* yacc.c:1646  */
    break;

  case 235:
#line 791 "pddl.yy" /* yacc.c:1646  */
    { add_term((yyvsp[0].str)); }
#line 2865 "pddl.cc" /* yacc.c:1646  */
    break;

  case 236:
#line 792 "pddl.yy" /* yacc.c:1646  */
    { add_term((yyvsp[0].str)); }
#line 2871 "pddl.cc" /* yacc.c:1646  */
    break;

  case 238:
#line 796 "pddl.yy" /* yacc.c:1646  */
    { add_term((yyvsp[0].str)); }
#line 2877 "pddl.cc" /* yacc.c:1646  */
    break;

  case 239:
#line 799 "pddl.yy" /* yacc.c:1646  */
    { (yyval.term) = new Term(make_term((yyvsp[0].str))); }
#line 2883 "pddl.cc" /* yacc.c:1646  */
    break;

  case 240:
#line 800 "pddl.yy" /* yacc.c:1646  */
    { (yyval.term) = new Term(make_term((yyvsp[0].str))); }
#line 2889 "pddl.cc" /* yacc.c:1646  */
    break;

  case 242:
#line 804 "pddl.yy" /* yacc.c:1646  */
    { add_variables((yyvsp[0].strs), TypeTable::OBJECT); }
#line 2895 "pddl.cc" /* yacc.c:1646  */
    break;

  case 243:
#line 805 "pddl.yy" /* yacc.c:1646  */
    { add_variables((yyvsp[-1].strs), *(yyvsp[0].type)); delete (yyvsp[0].type); }
#line 2901 "pddl.cc" /* yacc.c:1646  */
    break;

  case 245:
#line 809 "pddl.yy" /* yacc.c:1646  */
    { (yyval.strs) = new std::vector<const std::string*>(1, (yyvsp[0].str)); }
#line 2907 "pddl.cc" /* yacc.c:1646  */
    break;

  case 246:
#line 810 "pddl.yy" /* yacc.c:1646  */
    { (yyval.strs) = (yyvsp[-1].strs); (yyval.strs)->push_back((yyvsp[0].str)); }
#line 2913 "pddl.cc" /* yacc.c:1646  */
    break;

  case 248:
#line 814 "pddl.yy" /* yacc.c:1646  */
    { add_names((yyvsp[0].strs), TypeTable::OBJECT); }
#line 2919 "pddl.cc" /* yacc.c:1646  */
    break;

  case 249:
#line 815 "pddl.yy" /* yacc.c:1646  */
    { add_names((yyvsp[-1].strs), *(yyvsp[0].type)); delete (yyvsp[0].type); }
#line 2925 "pddl.cc" /* yacc.c:1646  */
    break;

  case 251:
#line 818 "pddl.yy" /* yacc.c:1646  */
    { (yyval.strs) = new std::vector<const std::string*>(1, (yyvsp[0].str)); }
#line 2931 "pddl.cc" /* yacc.c:1646  */
    break;

  case 252:
#line 819 "pddl.yy" /* yacc.c:1646  */
    { (yyval.strs) = (yyvsp[-1].strs); (yyval.strs)->push_back((yyvsp[0].str)); }
#line 2937 "pddl.cc" /* yacc.c:1646  */
    break;

  case 253:
#line 822 "pddl.yy" /* yacc.c:1646  */
    { require_typing(); }
#line 2943 "pddl.cc" /* yacc.c:1646  */
    break;

  case 254:
#line 822 "pddl.yy" /* yacc.c:1646  */
    { (yyval.type) = (yyvsp[0].type); }
#line 2949 "pddl.cc" /* yacc.c:1646  */
    break;

  case 255:
#line 825 "pddl.yy" /* yacc.c:1646  */
    { (yyval.type) = new Type(TypeTable::OBJECT); }
#line 2955 "pddl.cc" /* yacc.c:1646  */
    break;

  case 256:
#line 826 "pddl.yy" /* yacc.c:1646  */
    { (yyval.type) = new Type(make_type((yyvsp[0].str))); }
#line 2961 "pddl.cc" /* yacc.c:1646  */
    break;

  case 257:
#line 827 "pddl.yy" /* yacc.c:1646  */
    { (yyval.type) = new Type(make_type(*(yyvsp[-1].types))); delete (yyvsp[-1].types); }
#line 2967 "pddl.cc" /* yacc.c:1646  */
    break;

  case 258:
#line 830 "pddl.yy" /* yacc.c:1646  */
    { (yyval.types) = new TypeSet(); }
#line 2973 "pddl.cc" /* yacc.c:1646  */
    break;

  case 259:
#line 831 "pddl.yy" /* yacc.c:1646  */
    { (yyval.types) = new TypeSet(); (yyval.types)->insert(make_type((yyvsp[0].str))); }
#line 2979 "pddl.cc" /* yacc.c:1646  */
    break;

  case 260:
#line 832 "pddl.yy" /* yacc.c:1646  */
    { (yyval.types) = (yyvsp[-1].types); }
#line 2985 "pddl.cc" /* yacc.c:1646  */
    break;

  case 261:
#line 833 "pddl.yy" /* yacc.c:1646  */
    { (yyval.types) = (yyvsp[-1].types); (yyval.types)->insert(make_type((yyvsp[0].str))); }
#line 2991 "pddl.cc" /* yacc.c:1646  */
    break;

  case 263:
#line 843 "pddl.yy" /* yacc.c:1646  */
    { delete (yyvsp[0].str); }
#line 2997 "pddl.cc" /* yacc.c:1646  */
    break;

  case 264:
#line 846 "pddl.yy" /* yacc.c:1646  */
    { delete (yyvsp[0].str); }
#line 3003 "pddl.cc" /* yacc.c:1646  */
    break;

  case 265:
#line 849 "pddl.yy" /* yacc.c:1646  */
    { delete (yyvsp[0].str); }
#line 3009 "pddl.cc" /* yacc.c:1646  */
    break;

  case 266:
#line 852 "pddl.yy" /* yacc.c:1646  */
    { delete (yyvsp[0].str); }
#line 3015 "pddl.cc" /* yacc.c:1646  */
    break;

  case 267:
#line 855 "pddl.yy" /* yacc.c:1646  */
    { delete (yyvsp[0].str); }
#line 3021 "pddl.cc" /* yacc.c:1646  */
    break;

  case 268:
#line 858 "pddl.yy" /* yacc.c:1646  */
    { delete (yyvsp[0].str); }
#line 3027 "pddl.cc" /* yacc.c:1646  */
    break;

  case 269:
#line 861 "pddl.yy" /* yacc.c:1646  */
    { delete (yyvsp[0].str); }
#line 3033 "pddl.cc" /* yacc.c:1646  */
    break;

  case 270:
#line 864 "pddl.yy" /* yacc.c:1646  */
    { delete (yyvsp[0].str); }
#line 3039 "pddl.cc" /* yacc.c:1646  */
    break;

  case 271:
#line 867 "pddl.yy" /* yacc.c:1646  */
    { delete (yyvsp[0].str); }
#line 3045 "pddl.cc" /* yacc.c:1646  */
    break;

  case 272:
#line 870 "pddl.yy" /* yacc.c:1646  */
    { delete (yyvsp[0].str); }
#line 3051 "pddl.cc" /* yacc.c:1646  */
    break;

  case 273:
#line 873 "pddl.yy" /* yacc.c:1646  */
    { delete (yyvsp[0].str); }
#line 3057 "pddl.cc" /* yacc.c:1646  */
    break;

  case 274:
#line 876 "pddl.yy" /* yacc.c:1646  */
    { delete (yyvsp[0].str); }
#line 3063 "pddl.cc" /* yacc.c:1646  */
    break;

  case 275:
#line 879 "pddl.yy" /* yacc.c:1646  */
    { delete (yyvsp[0].str); }
#line 3069 "pddl.cc" /* yacc.c:1646  */
    break;

  case 276:
#line 882 "pddl.yy" /* yacc.c:1646  */
    { delete (yyvsp[0].str); }
#line 3075 "pddl.cc" /* yacc.c:1646  */
    break;

  case 277:
#line 885 "pddl.yy" /* yacc.c:1646  */
    { delete (yyvsp[0].str); }
#line 3081 "pddl.cc" /* yacc.c:1646  */
    break;

  case 278:
#line 888 "pddl.yy" /* yacc.c:1646  */
    { delete (yyvsp[0].str); }
#line 3087 "pddl.cc" /* yacc.c:1646  */
    break;

  case 279:
#line 891 "pddl.yy" /* yacc.c:1646  */
    { delete (yyvsp[0].str); }
#line 3093 "pddl.cc" /* yacc.c:1646  */
    break;

  case 280:
#line 894 "pddl.yy" /* yacc.c:1646  */
    { delete (yyvsp[0].str); }
#line 3099 "pddl.cc" /* yacc.c:1646  */
    break;

  case 281:
#line 897 "pddl.yy" /* yacc.c:1646  */
    { delete (yyvsp[0].str); }
#line 3105 "pddl.cc" /* yacc.c:1646  */
    break;

  case 282:
#line 900 "pddl.yy" /* yacc.c:1646  */
    { delete (yyvsp[0].str); }
#line 3111 "pddl.cc" /* yacc.c:1646  */
    break;

  case 283:
#line 903 "pddl.yy" /* yacc.c:1646  */
    { delete (yyvsp[0].str); }
#line 3117 "pddl.cc" /* yacc.c:1646  */
    break;


#line 3121 "pddl.cc" /* yacc.c:1646  */
      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 939 "pddl.yy" /* yacc.c:1906  */


/* Outputs an error message. */
static void yyerror(const std::string& s) {
  std::cerr << PACKAGE ":" << current_file << ':' << line_number << ": " << s
	    << std::endl;
  success = false;
}


/* Outputs a warning. */
static void yywarning(const std::string& s) {
  if (warning_level > 0) {
    std::cerr << PACKAGE ":" << current_file << ':' << line_number << ": " << s
	      << std::endl;
    if (warning_level > 1) {
      success = false;
    }
  }
}


/* Creates an empty domain with the given name. */
static void make_domain(const std::string* name) {
  domain = new Domain(*name);
  domains[*name] = domain;
  requirements = &domain->requirements;
  problem = 0;
  delete name;
}


/* Creates an empty problem with the given name. */
static void make_problem(const std::string* name,
			 const std::string* domain_name) {
  std::map<std::string, Domain*>::const_iterator di =
    domains.find(*domain_name);
  if (di != domains.end()) {
    domain = (*di).second;
  } else {
    domain = new Domain(*domain_name);
    domains[*domain_name] = domain;
    yyerror("undeclared domain `" + *domain_name + "' used");
  }
  requirements = new Requirements(domain->requirements);
  problem = new Problem(*name, *domain);
  delete name;
  delete domain_name;
}


/* Adds :typing to the requirements. */
static void require_typing() {
  if (!requirements->typing) {
    yywarning("assuming `:typing' requirement");
    requirements->typing = true;
  }
}


/* Adds :fluents to the requirements. */
static void require_fluents() {
  if (!requirements->fluents) {
    yywarning("assuming `:fluents' requirement");
    requirements->fluents = true;
  }
}


/* Adds :disjunctive-preconditions to the requirements. */
static void require_disjunction() {
  if (!requirements->disjunctive_preconditions) {
    yywarning("assuming `:disjunctive-preconditions' requirement");
    requirements->disjunctive_preconditions = true;
  }
}


/* Adds :duration-inequalities to the requirements. */
static void require_duration_inequalities() {
  if (!requirements->duration_inequalities) {
    yywarning("assuming `:duration-inequalities' requirement");
    requirements->duration_inequalities = true;
  }
}

/* Adds :decompositions to the requirements. */
static void require_decompositions() {
  if (!requirements->decompositions) {
    yywarning("assuming `:decompositions' requirement'");
	requirements->decompositions = true;
  }
}


/* Returns a simple type with the given name. */
static const Type& make_type(const std::string* name) {
  const Type* t = domain->types().find_type(*name);
  if (t == 0) {
    t = &domain->types().add_type(*name);
    if (name_kind != TYPE_KIND) {
      yywarning("implicit declaration of type `" + *name + "'");
    }
  }
  delete name;
  return *t;
}


/* Returns the union of the given types. */
static Type make_type(const TypeSet& types) {
  return TypeTable::union_type(types);
}


/* Returns a simple term with the given name. */
static Term make_term(const std::string* name) {
  if ((*name)[0] == '?') {
    const Variable* vp = context.find(*name);
    if (vp != 0) {
      delete name;
      return *vp;
    } else {
      Variable v = TermTable::add_variable(TypeTable::OBJECT);
      context.insert(*name, v);
      yyerror("free variable `" + *name + "' used");
      delete name;
      return v;
    }
  } else {
    TermTable& terms = (problem != 0) ? problem->terms() : domain->terms();
    const Object* o = terms.find_object(*name);
    if (o == 0) {
      size_t n = term_parameters.size();
      if (atom_predicate != 0
	  && PredicateTable::parameters(*atom_predicate).size() > n) {
	const Type& t = PredicateTable::parameters(*atom_predicate)[n];
	o = &terms.add_object(*name, t);
      } else {
	o = &terms.add_object(*name, TypeTable::OBJECT);
      }
      yywarning("implicit declaration of object `" + *name + "'");
    }
    delete name;
    return *o;
  }
}


/* Creates a predicate with the given name. */
static void make_predicate(const std::string* name) {
  predicate = domain->predicates().find_predicate(*name);
  if (predicate == 0) {
    repeated_predicate = false;
    predicate = &domain->predicates().add_predicate(*name);
  } else {
    repeated_predicate = true;
    yywarning("ignoring repeated declaration of predicate `" + *name + "'");
  }
  delete name;
}


/* Creates a function with the given name. */
static void make_function(const std::string* name) {
  repeated_function = false;
  function = domain->functions().find_function(*name);
  if (function == 0) {
    function = &domain->functions().add_function(*name);
  } else {
    repeated_function = true;
    if (*name == "total-time") {
      yywarning("ignoring declaration of reserved function `" + *name + "'");
    } else {
      yywarning("ignoring repeated declaration of function `" + *name + "'");
    }
  }
  delete name;
}


/* Creates an action with the given name. */
static void make_action(const std::string* name, bool durative, bool composite) {
  if (durative) {
    if (!requirements->durative_actions) {
      yywarning("assuming `:durative-actions' requirement");
      requirements->durative_actions = true;
    }
  }
  context.push_frame();
  action = new ActionSchema(*name, durative, composite);
  delete name;
}


/* Adds the current action to the current domain. */
static void add_action() {
  context.pop_frame();
  if (domain->find_action(action->name()) == 0) {
    action->strengthen_effects(*domain);
    domain->add_action(*action);
  } else {
    yywarning("ignoring repeated declaration of action `"
	      + action->name() + "'");
    delete action;
  }
  action = 0;
}


/* Prepares for the parsing of a universally quantified effect. */ 
static void prepare_forall_effect() {
  if (!requirements->conditional_effects) {
    yywarning("assuming `:conditional-effects' requirement");
    requirements->conditional_effects = true;
  }
  context.push_frame();
  quantified.push_back(Term(0));
}


/* Prepares for the parsing of a conditional effect. */ 
static void prepare_conditional_effect(const Formula& condition) {
  if (!requirements->conditional_effects) {
    yywarning("assuming `:conditional-effects' requirement");
    requirements->conditional_effects = true;
  }
  effect_condition = &condition;
}


/* Adds types, constants, or objects to the current domain or problem. */
static void add_names(const std::vector<const std::string*>* names,
		      const Type& type) {
  for (std::vector<const std::string*>::const_iterator si = names->begin();
       si != names->end(); si++) {
    const std::string* s = *si;
    if (name_kind == TYPE_KIND) {
      if (*s == TypeTable::OBJECT_NAME) {
	yywarning("ignoring declaration of reserved type `object'");
      } else if (*s == TypeTable::NUMBER_NAME) {
	yywarning("ignoring declaration of reserved type `number'");
      } else {
	const Type* t = domain->types().find_type(*s);
	if (t == 0) {
	  t = &domain->types().add_type(*s);
	}
	if (!TypeTable::add_supertype(*t, type)) {
	  yyerror("cyclic type hierarchy");
	}
      }
    } else if (name_kind == CONSTANT_KIND) {
      const Object* o = domain->terms().find_object(*s);
      if (o == 0) {
	domain->terms().add_object(*s, type);
      } else {
	TypeSet components;
	TypeTable::components(components, TermTable::type(*o));
	components.insert(type);
	TermTable::set_type(*o, make_type(components));
      }
    } else { /* name_kind == OBJECT_KIND */
      if (domain->terms().find_object(*s) != 0) {
	yywarning("ignoring declaration of object `" + *s
		  + "' previously declared as constant");
      } else {
	const Object* o = problem->terms().find_object(*s);
	if (o == 0) {
	  problem->terms().add_object(*s, type);
	} else {
	  TypeSet components;
	  TypeTable::components(components, TermTable::type(*o));
	  components.insert(type);
	  TermTable::set_type(*o, make_type(components));
	}
      }
    }
    delete s;
  }
  delete names;
}


/* Adds variables to the current variable list. */
static void add_variables(const std::vector<const std::string*>* names,
			  const Type& type) {
  for (std::vector<const std::string*>::const_iterator si = names->begin();
       si != names->end(); si++) {
    const std::string* s = *si;
    if (predicate != 0) {
      if (!repeated_predicate) {
	PredicateTable::add_parameter(*predicate, type);
      }
    } else if (function != 0) {
      if (!repeated_function) {
	FunctionTable::add_parameter(*function, type);
      }
    } else {
      if (context.shallow_find(*s) != 0) {
	yyerror("repetition of parameter `" + *s + "'");
      } else if (context.find(*s) != 0) {
	yywarning("shadowing parameter `" + *s + "'");
      }
      Variable var = TermTable::add_variable(type);
      context.insert(*s, var);
      if (!quantified.empty()) {
	quantified.push_back(var);
      } else { /* action != 0 */
	action->add_parameter(var);
      }
    }
    delete s;
  }
  delete names;
}


/* Prepares for the parsing of an atomic formula. */ 
static void prepare_atom(const std::string* name) {
  atom_predicate = domain->predicates().find_predicate(*name);
  if (atom_predicate == 0) {
    atom_predicate = &domain->predicates().add_predicate(*name);
    undeclared_atom_predicate = true;
    if (problem != 0) {
      yywarning("undeclared predicate `" + *name + "' used");
    } else {
      yywarning("implicit declaration of predicate `" + *name + "'");
    }
  } else {
    undeclared_atom_predicate = false;
  }
  term_parameters.clear();
  delete name;
}


/* Prepares for the parsing of a fluent. */ 
static void prepare_fluent(const std::string* name) {
  fluent_function = domain->functions().find_function(*name);
  if (fluent_function == 0) {
    fluent_function = &domain->functions().add_function(*name);
    undeclared_fluent_function = true;
    if (problem != 0) {
      yywarning("undeclared function `" + *name + "' used");
    } else {
      yywarning("implicit declaration of function `" + *name + "'");
    }
  } else {
    undeclared_fluent_function = false;
  }
  if (*name == "total-time") {
    if (!metric_fluent) {
      yyerror("reserved function `" + *name + "' not allowed here");
    }
  } else {
    require_fluents();
  }
  term_parameters.clear();
  delete name;
}


/* Adds a term with the given name to the current atomic formula. */
static void add_term(const std::string* name) {
  Term term = make_term(name);
  if (atom_predicate != 0) {
    size_t n = term_parameters.size();
    if (undeclared_atom_predicate) {
      PredicateTable::add_parameter(*atom_predicate, TermTable::type(term));
    } else {
      const TypeList& params = PredicateTable::parameters(*atom_predicate);
      if (params.size() > n
	  && !TypeTable::subtype(TermTable::type(term), params[n])) {
	yyerror("type mismatch");
      }
    }
  } else if (fluent_function != 0) {
    size_t n = term_parameters.size();
    if (undeclared_fluent_function) {
      FunctionTable::add_parameter(*fluent_function, TermTable::type(term));
    } else {
      const TypeList& params = FunctionTable::parameters(*fluent_function);
      if (params.size() > n
	  && !TypeTable::subtype(TermTable::type(term), params[n])) {
	yyerror("type mismatch");
      }
    }
  }
  term_parameters.push_back(term);
}


/* Creates the atomic formula just parsed. */
static const Atom* make_atom() {
  size_t n = term_parameters.size();
  if (PredicateTable::parameters(*atom_predicate).size() < n) {
    yyerror("too many parameters passed to predicate `"
	    + PredicateTable::name(*atom_predicate) + "'");
  } else if (PredicateTable::parameters(*atom_predicate).size() > n) {
    yyerror("too few parameters passed to predicate `"
	    + PredicateTable::name(*atom_predicate) + "'");
  }
  const Atom& atom = Atom::make(*atom_predicate, term_parameters);
  atom_predicate = 0;
  return &atom;
}


/* Creates the fluent just parsed. */
static const Fluent* make_fluent() {
  size_t n = term_parameters.size();
  if (FunctionTable::parameters(*fluent_function).size() < n) {
    yyerror("too many parameters passed to function `"
	    + FunctionTable::name(*fluent_function) + "'");
  } else if (FunctionTable::parameters(*fluent_function).size() > n) {
    yyerror("too few parameters passed to function `"
	    + FunctionTable::name(*fluent_function) + "'");
  }
  const Fluent& fluent = Fluent::make(*fluent_function, term_parameters);
  fluent_function = 0;
  return &fluent;
}


/* Creates a subtraction. */
static const Expression* make_subtraction(const Expression& term,
					  const Expression* opt_term) {
  if (opt_term != 0) {
    return &Subtraction::make(term, *opt_term);
  } else {
    return &Subtraction::make(*new Value(0), term);
  }
}


/* Creates an equality formula. */
static const Formula* make_equality(const Term* term1, const Term* term2) {
  if (!requirements->equality) {
    yywarning("assuming `:equality' requirement");
    requirements->equality = true;
  }
  const Formula& eq = Equality::make(*term1, *term2);
  delete term1;
  delete term2;
  return &eq;
}


/* Creates a negated formula. */
static const Formula* make_negation(const Formula& negand) {
  if (typeid(negand) == typeid(Literal)
      || typeid(negand) == typeid(TimedLiteral)) {
    if (!requirements->negative_preconditions) {
      yywarning("assuming `:negative-preconditions' requirement");
      requirements->negative_preconditions = true;
    }
  } else if (!requirements->disjunctive_preconditions
	     && typeid(negand) != typeid(Equality)) {
    yywarning("assuming `:disjunctive-preconditions' requirement");
    requirements->disjunctive_preconditions = true;
  }
  return &!negand;
}


/* Prepares for the parsing of an existentially quantified formula. */
static void prepare_exists() {
  if (!requirements->existential_preconditions) {
    yywarning("assuming `:existential-preconditions' requirement");
    requirements->existential_preconditions = true;
  }
  context.push_frame();
  quantified.push_back(Term(0));
}


/* Prepares for the parsing of a universally quantified formula. */
static void prepare_forall() {
  if (!requirements->universal_preconditions) {
    yywarning("assuming `:universal-preconditions' requirement");
    requirements->universal_preconditions = true;
  }
  context.push_frame();
  quantified.push_back(Term(0));
}


/* Creates an existentially quantified formula. */
static const Formula* make_exists(const Formula& body) {
  context.pop_frame();
  size_t m = quantified.size() - 1;
  size_t n = m;
  while (quantified[n].variable()) {
    n--;
  }
  if (n < m) {
    if (body.tautology() || body.contradiction()) {
      quantified.resize(n, Term(0));
      return &body;
    } else {
      Exists& exists = *new Exists();
      for (size_t i = n + 1; i <= m; i++) {
	exists.add_parameter(quantified[i].as_variable());
      }
      exists.set_body(body);
      quantified.resize(n, Term(0));
      return &exists;
    }
  } else {
    quantified.pop_back();
    return &body;
  }
}


/* Creates a universally quantified formula. */
static const Formula* make_forall(const Formula& body) {
  context.pop_frame();
  size_t m = quantified.size() - 1;
  size_t n = m;
  while (quantified[n].variable()) {
    n--;
  }
  if (n < m) {
    if (body.tautology() || body.contradiction()) {
      quantified.resize(n, Term(0));
      return &body;
    } else {
      Forall& forall = *new Forall();
      for (size_t i = n + 1; i <= m; i++) {
	forall.add_parameter(quantified[i].as_variable());
      }
      forall.set_body(body);
      quantified.resize(n, Term(0));
      return &forall;
    }
  } else {
    quantified.pop_back();
    return &body;
  }
}


/* Adds the current effect to the currect action. */
static void add_effect(const Literal& literal) {
  PredicateTable::make_dynamic(literal.predicate());
  Effect* effect = new Effect(literal, effect_time);
  for (TermList::const_iterator vi = quantified.begin();
       vi != quantified.end(); vi++) {
    if ((*vi).variable()) {
      effect->add_parameter((*vi).as_variable());
    }
  }
  if (effect_condition != 0) {
    effect->set_condition(*effect_condition);
  }
  action->add_effect(*effect);
}


/* Pops the top-most universally quantified variables. */
static void pop_forall_effect() {
  context.pop_frame();
  size_t n = quantified.size() - 1;
  while (quantified[n].variable()) {
    n--;
  }
  quantified.resize(n, Term(0));
}


/* Adds a timed initial literal to the current problem. */
static void add_init_literal(float time, const Literal& literal) {
  problem->add_init_literal(time, literal);
  if (time > 0.0f) {
    PredicateTable::make_dynamic(literal.predicate());
  }
}
