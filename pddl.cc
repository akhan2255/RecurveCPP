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

/* Enable Bison debugging. */
#define YYDEBUG 1

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

/* Decomposition schema being parsed, or 0 if no decomposition is being parsed. */
static DecompositionSchema* decomposition;

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

/* Checks whether there exists a composite action with the given name in the current domain. */
static bool composite_action_exists(const std::string* composite_action_name);

/* Creates a decomposition for the given composite action name with the given name. */
static void make_decomposition(const std::string* composite_action_name, const std::string* name);

/* Adds the current decomposition to the current domain. */
static void add_decomposition();

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

#line 345 "pddl.cc" /* yacc.c:339  */

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
    COMPOSITE = 319,
    DECOMPOSITION = 320,
    STEPS = 321,
    LINKS = 322,
    ORDERINGS = 323,
    DECOMPOSITION_NAME = 324
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 322 "pddl.yy" /* yacc.c:355  */

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

#line 469 "pddl.cc" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_PDDL_HH_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 486 "pddl.cc" /* yacc.c:358  */

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
#define YYLAST   1272

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  79
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  162
/* YYNRULES -- Number of rules.  */
#define YYNRULES  345
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  574

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   324

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
      70,    71,    77,    76,     2,    72,     2,    78,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    75,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,    74,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,    73,     2,     2,     2,
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
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   356,   356,   356,   360,   361,   362,   369,   369,   373,
     374,   375,   376,   379,   380,   381,   384,   385,   386,   387,
     388,   389,   390,   393,   394,   395,   396,   397,   400,   401,
     402,   403,   404,   407,   408,   409,   410,   411,   414,   415,
     416,   419,   420,   421,   424,   425,   426,   429,   430,   433,
     434,   437,   440,   441,   444,   445,   446,   448,   450,   451,
     453,   455,   457,   458,   459,   460,   461,   463,   465,   470,
     473,   473,   477,   477,   481,   484,   484,   491,   492,   495,
     495,   499,   500,   501,   504,   505,   508,   508,   511,   511,
     519,   519,   520,   520,   523,   524,   527,   528,   531,   532,
     535,   536,   539,   539,   542,   542,   545,   546,   549,   550,
     553,   554,   562,   561,   575,   578,   579,   582,   585,   605,
     606,   610,   615,   620,   624,   625,   633,   634,   637,   638,
     641,   641,   642,   642,   643,   643,   650,   651,   652,   652,
     653,   653,   653,   656,   657,   660,   661,   664,   665,   668,
     669,   672,   673,   674,   674,   676,   676,   680,   681,   685,
     684,   688,   687,   692,   693,   694,   694,   696,   696,   700,
     701,   709,   708,   713,   714,   717,   718,   721,   722,   725,
     725,   729,   732,   733,   736,   736,   738,   738,   740,   742,
     744,   748,   749,   752,   755,   755,   757,   757,   765,   766,
     767,   768,   769,   769,   770,   770,   772,   772,   774,   774,
     778,   779,   782,   783,   786,   786,   790,   790,   794,   795,
     802,   803,   804,   805,   806,   807,   810,   811,   814,   814,
     816,   819,   820,   822,   824,   826,   828,   831,   832,   835,
     835,   837,   844,   845,   846,   849,   850,   853,   854,   857,
     858,   859,   859,   863,   864,   867,   868,   869,   869,   872,
     873,   876,   876,   879,   880,   881,   884,   885,   886,   887,
     890,   897,   900,   903,   906,   909,   912,   915,   918,   921,
     924,   927,   930,   933,   936,   939,   942,   945,   948,   951,
     954,   957,   960,   960,   960,   961,   962,   962,   962,   962,
     962,   963,   963,   963,   964,   967,   968,   968,   971,   971,
     971,   972,   973,   973,   973,   973,   974,   974,   974,   975,
     976,   976,   979,   982,   982,   982,   983,   983,   983,   984,
     984,   984,   984,   984,   984,   984,   985,   985,   985,   985,
     985,   986,   986,   986,   987,   990
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
  "COMPOSITE", "DECOMPOSITION", "STEPS", "LINKS", "ORDERINGS",
  "DECOMPOSITION_NAME", "'('", "')'", "'-'", "'t'", "'f'", "'='", "'+'",
  "'*'", "'/'", "$accept", "pddl_file", "$@1", "domains_and_problems",
  "domain_def", "$@2", "domain_body", "domain_body2", "domain_body3",
  "domain_body4", "domain_body5", "domain_body6", "domain_body7",
  "domain_body8", "domain_body9", "structure_defs", "structure_def",
  "require_def", "require_keys", "require_key", "types_def", "$@3",
  "constants_def", "$@4", "predicates_def", "functions_def", "$@5",
  "predicate_decls", "predicate_decl", "$@6", "function_decls",
  "function_decl_seq", "function_type_spec", "$@7", "function_decl", "$@8",
  "action_def", "$@9", "$@10", "parameters", "action_body", "action_body2",
  "action_body3", "precondition", "$@11", "effect", "$@12", "composite",
  "da_body", "da_body2", "decomposition_def", "$@13", "decomposition_body",
  "steps", "step", "pseudo_step", "duration_constraint",
  "simple_duration_constraint", "simple_duration_constraints", "da_gd",
  "timed_gds", "timed_gd", "$@14", "$@15", "$@16", "eff_formula", "$@17",
  "$@18", "$@19", "eff_formulas", "one_eff_formula", "term_literal",
  "term_literals", "da_effect", "$@20", "$@21", "da_effects",
  "timed_effect", "$@22", "$@23", "a_effect", "$@24", "$@25", "a_effects",
  "problem_def", "$@26", "problem_body", "problem_body2", "problem_body3",
  "object_decl", "$@27", "init", "init_elements", "init_element", "$@28",
  "$@29", "goal_spec", "goal", "metric_spec", "$@30", "$@31", "formula",
  "$@32", "$@33", "$@34", "$@35", "conjuncts", "disjuncts",
  "atomic_term_formula", "$@36", "atomic_name_formula", "$@37",
  "name_literal", "f_exp", "opt_f_exp", "f_head", "$@38", "ground_f_exp",
  "opt_ground_f_exp", "ground_f_head", "$@39", "terms", "names", "term",
  "variables", "$@40", "variable_seq", "typed_names", "$@41", "name_seq",
  "type_spec", "$@42", "type", "types", "function_type", "define",
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
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324,
      40,    41,    45,   116,   102,    61,    43,    42,    47
};
# endif

#define YYPACT_NINF -447

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-447)))

#define YYTABLE_NINF -282

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -447,    32,  -447,  -447,   -26,    55,  -447,  -447,  -447,    -5,
     130,  -447,  -447,  1214,  1214,  -447,  -447,  -447,  -447,  -447,
    -447,  -447,  -447,  -447,  -447,  -447,  -447,  -447,  -447,  -447,
    -447,  -447,  -447,  -447,  -447,  -447,  -447,     8,    26,  -447,
      34,    36,    68,    46,    90,  -447,  -447,    38,  -447,    69,
      77,   100,   102,   127,  -447,  -447,  1214,   966,  -447,  -447,
    -447,  -447,  1214,  1214,  1214,  -447,     1,  -447,    31,  -447,
     392,  -447,   254,  -447,    38,   144,   148,   145,  -447,    38,
     144,   151,    37,  -447,    38,   148,   151,   133,  -447,  -447,
    -447,  -447,  -447,  -447,  -447,  -447,  -447,  -447,  -447,  -447,
    -447,  -447,  -447,  -447,   277,  -447,  1214,  1214,    67,   162,
    -447,  -447,   165,   315,  -447,    38,    38,   143,  -447,    38,
      38,  -447,    52,  -447,    38,    38,  -447,  -447,  -447,  -447,
    -447,   166,   563,  -447,   168,   820,  -447,  -447,  1214,   184,
      14,  -447,   252,   252,  1214,    38,    38,    38,   187,  -447,
    -447,  -447,  -447,  -447,  -447,  -447,  -447,  -447,  -447,  -447,
    -447,  -447,  -447,  -447,  -447,  -447,  -447,  -447,  -447,  -447,
    -447,  -447,  -447,  -447,  -447,   162,  -447,   213,     0,   299,
    -447,   225,   217,   237,  -447,  -447,   262,   268,  -447,   274,
     526,  1214,   291,   291,   321,  -447,   291,  -447,  -447,    76,
     306,  -447,  -447,     5,   314,  -447,   309,   252,  -447,  -447,
     311,    56,  -447,  -447,   146,  -447,   346,  -447,   347,  -447,
    -447,   328,  -447,  -447,  -447,  -447,  -447,   316,   -30,  -447,
     317,  -447,  -447,  -447,   320,   311,   319,  -447,  -447,  -447,
    -447,  -447,   163,     4,  -447,   326,  1214,   141,   507,   322,
    -447,   175,  -447,   876,  -447,  -447,  -447,  -447,  -447,  -447,
     594,  -447,  -447,  -447,  -447,   327,   327,   327,  -447,   333,
     334,   335,  -447,   337,   338,   339,   138,  -447,  -447,  -447,
    -447,  -447,  -447,  -447,  1191,   311,  -447,  -447,  -447,  -447,
    -447,  -447,  -447,  -447,  -447,  -447,  -447,   195,  -447,  -447,
     291,  -447,  -447,   341,  -447,  -447,  -447,  1017,  1017,  1017,
     158,    43,  -447,  -447,   134,   376,  -447,  -447,  -447,  -447,
    -447,  -447,  -447,  -447,   351,  -447,  -447,  -447,  -447,  -447,
    -447,  -447,  -447,  -447,  -447,  -447,  1135,   343,   353,  -447,
    1191,  -447,  -447,   344,   199,  -447,   311,   350,   354,  -447,
    1076,  1076,  -447,  -447,  -447,  -447,   311,   820,   352,   206,
     355,  -447,   318,   357,  -447,  -447,   358,   359,    73,  -447,
    -447,  -447,   334,  -447,  -447,   256,  -447,  -447,   256,   368,
    -447,   236,  -447,  1214,   360,  -447,   820,   379,   356,  -447,
     380,  -447,  -447,  -447,   241,   311,   291,   291,   619,  -447,
     394,   382,  -447,   387,  -447,  -447,  -447,  -447,   291,  1017,
    1017,  1017,  1017,  -447,  -447,  -447,  -447,  -447,   243,   361,
    -447,  -447,  -447,  -447,   258,  -447,  -447,  -447,  -447,  1214,
    -447,  -447,   793,  -447,   388,  -447,  -447,   762,  -447,   389,
     849,  -447,  -447,  -447,   390,   391,   393,  -447,  -447,  -447,
    1076,  1076,  1076,  1076,  -447,  -447,   395,   396,  1017,  1017,
    1017,  1017,  -447,   398,  -447,  -447,   291,   399,   399,   289,
    -447,  -447,   311,   311,   311,   404,  -447,  -447,  -447,  -447,
    -447,   343,  -447,  -447,  -447,   311,   311,  1076,  1076,  1076,
    1076,   704,   402,  -447,   319,  -447,   405,   406,   409,   410,
     677,   363,   411,   414,   594,  -447,   415,   419,   420,   421,
     422,  1214,   423,   905,   961,   424,   425,   426,  -447,   428,
     431,   432,   433,  -447,  -447,   434,  -447,  -447,  -447,  -447,
    -447,  -447,   333,   311,  -447,  -447,  -447,  -447,  -447,  -447,
    -447,  -447,  -447,  -447,  -447,  -447,  -447,  -447,  -447,  -447,
    -447,  -447,   272,  -447,   435,  -447,   276,   437,   735,   762,
    -447,  -447,  -447,   395,  -447,  -447,   291,  -447,   438,   442,
    -447,   399,   443,  -447
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
       2,     0,     4,     1,     3,     0,     5,     6,   271,     0,
       0,   272,   273,     0,     0,   323,   324,   325,   329,   330,
     331,   332,   333,   334,   335,   336,   337,   338,   339,   340,
     341,   342,   343,   326,   327,   328,   344,     0,     0,     7,
       0,     9,     0,     0,     0,    12,    15,    22,    47,    10,
      13,    16,    17,    18,    49,    50,     0,     0,    70,    72,
      77,    75,     0,     0,     0,     8,     0,    48,     0,    11,
       0,    14,     0,    19,    27,    23,    24,     0,    20,    32,
      28,    29,     0,    21,    37,    33,    34,     0,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    68,    69,     0,    52,   255,   255,     0,    81,
      90,    92,     0,     0,    25,    40,    38,     0,    26,    43,
      41,    30,     0,    31,    46,    44,    35,    36,   171,    51,
      53,     0,   256,   259,     0,     0,    74,    78,     0,     0,
      82,    84,    94,    94,     0,    39,    42,    45,     0,    71,
     261,   257,   260,    73,   292,   293,   294,   296,   297,   298,
     299,   300,   301,   302,   303,   307,   306,   295,   304,   305,
      79,    88,   322,    76,    86,    81,    85,     0,   100,     0,
     112,     0,     0,     0,   174,   176,     0,     0,   178,   191,
       0,   255,   249,   249,     0,    83,   249,   102,   104,     0,
       0,    97,    99,   100,   100,   101,     0,    94,   179,   182,
       0,     0,   173,   172,     0,   175,     0,   177,     0,   192,
     290,     0,   262,   263,   264,   258,   345,     0,   250,   253,
       0,   289,    87,   270,     0,     0,     0,   106,   107,    91,
      96,    98,     0,   110,   119,     0,   255,     0,     0,     0,
     198,     0,   291,     0,    80,   251,   254,    89,    95,   103,
       0,   105,   136,   147,   276,     0,     0,     0,   124,     0,
       0,     0,   109,     0,     0,     0,     0,   181,   183,   275,
     277,   278,   279,   280,     0,     0,   210,   202,   204,   206,
     208,   214,   193,   287,   288,   196,   194,     0,   266,   267,
     249,   274,   140,     0,   143,   138,   286,     0,     0,     0,
       0,     0,   111,   151,     0,   110,   126,    93,   115,   113,
     180,   308,   309,   310,   186,   312,   313,   314,   315,   316,
     317,   318,   321,   320,   311,   319,     0,     0,     0,   184,
       0,   247,   248,     0,     0,   212,     0,     0,     0,   242,
       0,     0,   265,   268,   269,   252,     0,     0,     0,     0,
       0,   220,     0,     0,   225,   230,     0,     0,     0,   120,
     125,   281,     0,   157,   153,     0,   282,   128,     0,     0,
     108,     0,   245,     0,     0,   241,     0,     0,     0,   245,
       0,   200,   201,   211,     0,     0,   249,   249,     0,   231,
       0,     0,   236,     0,   141,   148,   137,   144,   249,     0,
       0,     0,     0,   228,   121,   122,   123,   155,     0,     0,
     283,   284,   159,   161,     0,   130,   132,   285,   134,     0,
     114,   116,     0,   239,     0,   216,   188,     0,   218,     0,
       0,   199,   203,   213,     0,     0,     0,   215,   243,   244,
       0,     0,     0,     0,   197,   195,     0,     0,   226,     0,
       0,     0,   242,     0,   152,   158,   249,     0,     0,     0,
     127,   129,     0,     0,     0,     0,   187,   246,   245,   189,
     245,     0,   190,   185,   205,     0,     0,   237,     0,     0,
       0,     0,     0,   145,     0,   227,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   163,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   238,     0,
       0,     0,     0,   149,   142,     0,   222,   221,   223,   224,
     229,   156,     0,     0,   169,   165,   160,   162,   131,   133,
     135,   242,   117,   240,   217,   219,   207,   209,   233,   232,
     234,   235,     0,   139,     0,   167,     0,     0,     0,     0,
     146,   150,   154,     0,   164,   170,   249,   118,     0,     0,
     168,     0,     0,   166
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -447,  -447,  -447,  -447,  -447,  -447,  -447,   459,   413,  -447,
    -447,  -447,   436,   430,   439,   403,    21,   369,  -447,   371,
    -447,  -447,   170,  -447,    22,   230,  -447,  -447,  -447,  -447,
     345,  -447,  -447,  -447,   378,  -447,  -447,  -447,  -447,  -118,
    -447,   323,   329,  -447,  -447,  -447,  -447,  -447,  -447,   207,
    -447,  -447,  -447,  -447,  -447,  -447,  -447,   211,  -447,   152,
    -447,   103,  -447,  -447,  -447,  -343,  -447,  -447,  -447,  -447,
     -31,  -226,  -447,  -400,  -447,  -447,  -447,    71,  -447,  -447,
    -446,  -447,  -447,  -447,  -447,  -447,  -447,   362,   349,  -447,
    -447,  -447,  -447,  -447,  -447,  -447,   377,  -447,  -447,  -447,
    -447,  -200,  -447,  -447,  -447,  -447,  -447,  -447,  -232,  -447,
    -369,  -447,  -447,  -296,  -447,  -447,  -447,  -330,  -447,   200,
    -447,  -438,  -352,   197,  -191,  -447,  -447,   -92,  -447,  -447,
     310,  -447,  -447,  -447,  -447,  -447,  -447,  -447,  -297,  -228,
    -237,  -447,  -447,  -447,  -252,  -267,  -447,   161,   164,  -447,
      83,  -447,  -447,  -447,  -227,  -447,  -173,  -128,  -447,  -135,
     -13,  -222
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,     2,     4,     6,    41,    44,    45,    46,    73,
      78,    83,   114,   118,   123,    47,    48,    49,   104,   105,
      50,   106,    51,   107,    52,    53,   109,   108,   137,   192,
     139,   140,   175,   194,   141,   193,    54,   142,   143,   178,
     200,   201,   202,   203,   235,   204,   236,   205,   271,   272,
      55,   207,   274,   381,   431,   512,   243,   244,   310,   315,
     424,   316,   472,   473,   474,   261,   360,   356,   456,   359,
     492,   505,   552,   312,   419,   463,   418,   313,   467,   468,
     506,   557,   563,   556,     7,   148,   183,   184,   185,   186,
     246,   187,   247,   278,   389,   382,   188,   189,   219,   351,
     350,   249,   345,   346,   347,   348,   344,   394,   250,   349,
     387,   480,   439,   363,   496,   364,   462,   401,   519,   402,
     478,   398,   432,   340,   227,   300,   228,   131,   191,   132,
     151,   190,   222,   297,   232,     9,    13,    14,   302,   303,
     268,   287,   288,   289,   290,   375,   379,   422,   423,   428,
     307,   295,   296,   233,   223,   253,   169,   291,   339,   365,
     172,   229
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      37,    38,   230,   171,   263,   234,   256,   170,   305,   338,
     262,   286,   366,   367,   372,   134,   407,   224,   465,   438,
     285,   403,   507,   304,   500,   179,   298,    62,   197,   198,
     226,    63,     3,   269,   198,   259,   270,   440,    58,    59,
      60,    61,   150,    87,     5,    59,    60,   378,   337,   110,
     111,   112,    57,    58,    59,    60,    61,    62,     8,   374,
      59,    63,   342,    62,   199,    10,    64,    63,    67,   199,
     353,   358,    62,    75,   373,    86,    63,   377,    62,    39,
     299,   301,    63,   264,   138,   343,   174,   283,   371,   245,
     208,   209,   210,   133,   133,    67,    64,    40,   120,   225,
      67,    56,    64,   558,    42,    67,    43,   120,    66,   355,
     565,    64,   515,   458,   459,   460,   461,    64,   342,   152,
     487,   488,   489,   490,   354,   572,   513,   263,   514,   265,
     266,   180,   554,   262,    11,    12,    67,   135,   136,    68,
      67,   321,   322,   323,   393,    67,   395,    70,   267,   237,
     238,   525,    60,    59,   275,    61,   404,   518,   520,   521,
     522,    65,   495,   497,   498,   499,    67,    67,    67,    62,
      72,    62,    77,    63,   264,    63,   449,   279,   133,   371,
     376,   209,   210,   324,   325,   326,   327,   328,   329,   330,
     331,   332,   333,   334,   443,   444,   335,    82,   154,   155,
     156,   385,   378,   264,   128,   445,   446,   533,    64,   481,
      64,   276,   277,   336,   113,   385,   385,   457,   117,   265,
     266,   122,    80,    85,   263,   293,   294,   413,   368,   369,
     493,    57,   138,   133,   144,   263,   263,   149,   267,   153,
     157,   158,   159,   160,   161,   162,   163,   164,   433,   220,
     167,   125,   535,   168,   523,   173,   125,   181,   435,   208,
     209,   210,   263,    60,    61,   433,   352,   534,   262,   248,
     392,   341,   508,   509,   510,   503,   260,   406,   449,   177,
      62,    76,    81,   196,    63,   516,   517,   211,    88,    89,
      90,    91,    92,    93,    94,    95,    96,    97,    98,    99,
     100,   101,   102,   420,   421,   116,   429,   430,   213,   435,
     116,   248,   442,   311,   464,   385,   385,   385,   385,    64,
     263,    15,    16,    17,   263,    61,   561,   341,   469,   470,
     206,   263,   214,   555,   371,   376,   449,   493,   216,   263,
     103,    62,   559,   560,   218,    63,   504,   564,   129,   308,
     309,   226,   385,   385,   385,   385,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,   231,   569,    36,   239,   199,   242,
      64,   248,   210,   252,   251,   448,   306,   254,   257,   260,
     409,   258,   273,   292,   410,   411,   412,    15,    16,    17,
      59,    60,    61,   311,   314,   269,   317,   318,   371,   319,
     320,   357,  -281,   386,   388,   391,   475,   427,    62,   477,
     396,   434,    63,   405,   397,   408,   437,   477,   414,   415,
     416,   466,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
     436,   441,    36,   454,    74,    79,    84,    64,   455,   479,
     482,   484,   485,    71,   486,   491,   450,   494,   501,   504,
     451,   452,   453,   524,   511,   130,   526,   527,   115,   119,
     528,   529,   531,   115,   124,   532,   536,   448,   119,   124,
     537,   538,   539,   540,   542,   545,   546,   547,   541,   548,
     477,   477,   549,   550,   551,   553,   562,   566,    69,   570,
     154,   155,   156,   571,   573,   126,   121,   182,   176,   145,
     195,   370,   380,   146,   417,   127,   240,   471,   147,   154,
     155,   156,   568,   241,   502,   215,   384,   390,   255,   425,
       0,     0,   426,     0,   212,   448,   279,   264,   280,   281,
     282,   283,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   167,     0,   217,   168,    15,    16,    17,     0,
       0,   157,   158,   159,   160,   161,   162,   163,   164,     0,
     220,   167,   284,     0,   168,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   221,   154,   155,   156,
       0,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,     0,
       0,    36,    15,    16,    17,     0,     0,     0,     0,     0,
       0,     0,   301,   279,   264,   150,     0,     0,   283,   157,
     158,   159,   160,   161,   162,   163,   164,   165,   166,   167,
       0,     0,   168,     0,     0,     0,     0,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,     0,     0,    36,     0,   226,
      15,    16,    17,     0,     0,     0,     0,     0,     0,     0,
     447,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   154,   155,   156,
       0,     0,     0,     0,     0,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,     0,     0,    36,     0,   226,    15,    16,
      17,     0,     0,   279,   264,     0,     0,     0,   530,   157,
     158,   159,   160,   161,   162,   163,   164,   165,   166,   167,
       0,     0,   168,     0,     0,   154,   155,   156,     0,     0,
       0,     0,     0,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,     0,     0,    36,     0,   226,    15,    16,    17,     0,
       0,   279,     0,     0,     0,     0,   567,   157,   158,   159,
     160,   161,   162,   163,   164,   165,   166,   167,     0,     0,
     168,     0,     0,   154,   155,   156,     0,     0,     0,     0,
       0,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,     0,
       0,    36,    15,    16,    17,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   476,   157,   158,   159,   160,   161,
     162,   163,   164,   165,   166,   167,     0,     0,   168,   154,
     155,   156,     0,     0,     0,     0,     0,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,     0,     0,    36,    15,    16,
      17,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     483,   157,   158,   159,   160,   161,   162,   163,   164,     0,
     220,   167,     0,     0,   168,     0,     0,     0,     0,     0,
       0,     0,     0,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,     0,     0,    36,    15,    16,    17,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   543,    88,    89,    90,
      91,    92,    93,    94,    95,    96,    97,    98,    99,   100,
     101,   102,     0,     0,     0,     0,     0,     0,     0,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,     0,     0,    36,
      15,    16,    17,     0,     0,     0,     0,     0,     0,   103,
       0,     0,   544,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,     0,     0,    36,     0,     0,   361,    15,
      16,    17,     0,     0,     0,     0,     0,   362,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,     0,     0,    36,     0,     0,   399,    15,    16,
      17,     0,     0,     0,     0,     0,   400,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,     0,     0,    36,    15,    16,    17,     0,     0,     0,
       0,     0,     0,     0,     0,   383,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    15,    16,    17,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,     0,     0,    36,
       0,   226,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
       0,     0,    36
};

static const yytype_int16 yycheck[] =
{
      13,    14,   193,   138,   236,   196,   228,   135,   260,   276,
     236,   248,   308,   309,   311,   107,   359,   190,   418,   388,
     248,   351,   468,   260,   462,   143,   253,    26,    28,    29,
      60,    30,     0,    29,    29,   235,    32,   389,     7,     8,
       9,    10,    72,    56,    70,     8,     9,   314,   276,    62,
      63,    64,     6,     7,     8,     9,    10,    26,     3,   311,
       8,    30,   284,    26,    64,    70,    65,    30,    47,    64,
     297,   303,    26,    51,   311,    53,    30,   314,    26,    71,
     253,    38,    30,    40,    70,   285,    72,    44,    45,   207,
      34,    35,    36,   106,   107,    74,    65,    71,    76,   191,
      79,    33,    65,   541,    70,    84,    70,    85,    70,   300,
     556,    65,   481,   409,   410,   411,   412,    65,   340,   132,
     450,   451,   452,   453,   297,   571,   478,   359,   480,    56,
      57,   144,   532,   359,     4,     5,   115,    70,    71,    70,
     119,     3,     4,     5,   344,   124,   346,    70,    75,    73,
      74,   494,     9,     8,   246,    10,   356,   487,   488,   489,
     490,    71,   458,   459,   460,   461,   145,   146,   147,    26,
      70,    26,    70,    30,    40,    30,   398,    39,   191,    45,
      46,    35,    36,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,   394,   395,    58,    70,     3,     4,
       5,   336,   469,    40,    71,   396,   397,   504,    65,   437,
      65,    70,    71,    75,    70,   350,   351,   408,    70,    56,
      57,    70,    52,    53,   456,    50,    51,   362,    70,    71,
     456,     6,    70,   246,    69,   467,   468,    71,    75,    71,
      45,    46,    47,    48,    49,    50,    51,    52,   383,    54,
      55,    81,   504,    58,   491,    71,    86,    70,   386,    34,
      35,    36,   494,     9,    10,   400,    71,   504,   494,    70,
      71,   284,   472,   473,   474,   466,    70,    71,   500,    27,
      26,    51,    52,    70,    30,   485,   486,    70,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    47,    48,    75,    70,    71,    71,   437,
      80,    70,    71,    70,    71,   450,   451,   452,   453,    65,
     552,     3,     4,     5,   556,    10,   552,   340,    70,    71,
      31,   563,    70,   533,    45,    46,   558,   563,    70,   571,
      63,    26,    70,    71,    70,    30,    70,    71,    71,   266,
     267,    60,   487,   488,   489,   490,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    53,   566,    58,    71,    64,    70,
      65,    70,    36,    55,    37,   398,    59,    71,    71,    70,
      72,    71,    66,    71,    76,    77,    78,     3,     4,     5,
       8,     9,    10,    70,    70,    29,    71,    70,    45,    71,
      71,    70,    61,    70,    61,    71,   429,    49,    26,   432,
      70,    61,    30,    71,    70,    70,    70,   440,    71,    71,
      71,    70,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      71,    71,    58,    71,    51,    52,    53,    65,    71,    71,
      71,    71,    71,    50,    71,    70,    72,    71,    70,    70,
      76,    77,    78,    71,    70,   104,    71,    71,    75,    76,
      71,    71,    71,    80,    81,    71,    71,   500,    85,    86,
      71,    71,    71,    71,    71,    71,    71,    71,   511,    71,
     513,   514,    71,    71,    71,    71,    71,    70,    49,    71,
       3,     4,     5,    71,    71,    85,    80,   148,   140,   116,
     175,   310,   315,   120,   372,    86,   203,   424,   125,     3,
       4,     5,   563,   204,   463,   186,   336,   340,   228,   378,
      -1,    -1,   378,    -1,   182,   558,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    -1,   187,    58,     3,     4,     5,    -1,
      -1,    45,    46,    47,    48,    49,    50,    51,    52,    -1,
      54,    55,    75,    -1,    58,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    70,     3,     4,     5,
      -1,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    -1,
      -1,    58,     3,     4,     5,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    38,    39,    40,    72,    -1,    -1,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      -1,    -1,    58,    -1,    -1,    -1,    -1,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    -1,    -1,    58,    -1,    60,
       3,     4,     5,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      71,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,     3,     4,     5,
      -1,    -1,    -1,    -1,    -1,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    -1,    -1,    58,    -1,    60,     3,     4,
       5,    -1,    -1,    39,    40,    -1,    -1,    -1,    71,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      -1,    -1,    58,    -1,    -1,     3,     4,     5,    -1,    -1,
      -1,    -1,    -1,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    -1,    -1,    58,    -1,    60,     3,     4,     5,    -1,
      -1,    39,    -1,    -1,    -1,    -1,    71,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    -1,    -1,
      58,    -1,    -1,     3,     4,     5,    -1,    -1,    -1,    -1,
      -1,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    -1,
      -1,    58,     3,     4,     5,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    71,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    -1,    -1,    58,     3,
       4,     5,    -1,    -1,    -1,    -1,    -1,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    -1,    -1,    58,     3,     4,
       5,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      71,    45,    46,    47,    48,    49,    50,    51,    52,    -1,
      54,    55,    -1,    -1,    58,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    -1,    -1,    58,     3,     4,     5,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    71,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    -1,    -1,    58,
       3,     4,     5,    -1,    -1,    -1,    -1,    -1,    -1,    63,
      -1,    -1,    71,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    -1,    -1,    58,    -1,    -1,    61,     3,
       4,     5,    -1,    -1,    -1,    -1,    -1,    70,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    -1,    -1,    58,    -1,    -1,    61,     3,     4,
       5,    -1,    -1,    -1,    -1,    -1,    70,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    -1,    -1,    58,     3,     4,     5,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    70,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,     3,     4,     5,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    -1,    -1,    58,
      -1,    60,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      -1,    -1,    58
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    80,    81,     0,    82,    70,    83,   163,     3,   214,
      70,     4,     5,   215,   216,     3,     4,     5,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    58,   239,   239,    71,
      71,    84,    70,    70,    85,    86,    87,    94,    95,    96,
      99,   101,   103,   104,   115,   129,    33,     6,     7,     8,
       9,    10,    26,    30,    65,    71,    70,    95,    70,    86,
      70,    87,    70,    88,    94,   103,   104,    70,    89,    94,
     101,   104,    70,    90,    94,   101,   103,   239,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    63,    97,    98,   100,   102,   106,   105,
     239,   239,   239,    70,    91,    94,   104,    70,    92,    94,
     103,    91,    70,    93,    94,   101,    92,    93,    71,    71,
      98,   206,   208,   239,   206,    70,    71,   107,    70,   109,
     110,   113,   116,   117,    69,    94,    94,    94,   164,    71,
      72,   209,   239,    71,     3,     4,     5,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    58,   235,
     236,   238,   239,    71,    72,   111,   113,    27,   118,   118,
     239,    70,    96,   165,   166,   167,   168,   170,   175,   176,
     210,   207,   108,   114,   112,   109,    70,    28,    29,    64,
     119,   120,   121,   122,   124,   126,    31,   130,    34,    35,
      36,    70,   166,    71,    70,   167,    70,   175,    70,   177,
      54,    70,   211,   233,   235,   206,    60,   203,   205,   240,
     203,    53,   213,   232,   203,   123,   125,    73,    74,    71,
     120,   121,    70,   135,   136,   118,   169,   171,    70,   180,
     187,    37,    55,   234,    71,   209,   240,    71,    71,   180,
      70,   144,   150,   187,    40,    56,    57,    75,   219,    29,
      32,   127,   128,    66,   131,   206,    70,    71,   172,    39,
      41,    42,    43,    44,    75,   218,   219,   220,   221,   222,
     223,   236,    71,    50,    51,   230,   231,   212,   233,   235,
     204,    38,   217,   218,   219,   223,    59,   229,   229,   229,
     137,    70,   152,   156,    70,   138,   140,    71,    70,    71,
      71,     3,     4,     5,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    58,    75,   218,   224,   237,
     202,   239,   240,   180,   185,   181,   182,   183,   184,   188,
     179,   178,    71,   233,   235,   203,   146,    70,   187,   148,
     145,    61,    70,   192,   194,   238,   192,   192,    70,    71,
     136,    45,   217,   219,   223,   224,    46,   219,   224,   225,
     128,   132,   174,    70,   198,   238,    70,   189,    61,   173,
     202,    71,    71,   180,   186,   180,    70,    70,   200,    61,
      70,   196,   198,   196,   180,    71,    71,   144,    70,    72,
      76,    77,    78,   238,    71,    71,    71,   138,   155,   153,
      47,    48,   226,   227,   139,   226,   227,    49,   228,    70,
      71,   133,   201,   238,    61,   236,    71,    70,   189,   191,
     201,    71,    71,   180,   180,   203,   203,    71,   239,   240,
      72,    76,    77,    78,    71,    71,   147,   203,   192,   192,
     192,   192,   195,   154,    71,   152,    70,   157,   158,    70,
      71,   140,   141,   142,   143,   239,    71,   239,   199,    71,
     190,   218,    71,    71,    71,    71,    71,   196,   196,   196,
     196,    70,   149,   150,    71,   192,   193,   192,   192,   192,
     200,    70,   156,   203,    70,   150,   159,   159,   180,   180,
     180,    70,   134,   201,   201,   189,   180,   180,   196,   197,
     196,   196,   196,   219,    71,   144,    71,    71,    71,    71,
      71,    71,    71,   217,   219,   223,    71,    71,    71,    71,
      71,   239,    71,    71,    71,    71,    71,    71,    71,    71,
      71,    71,   151,    71,   152,   180,   162,   160,   200,    70,
      71,   150,    71,   161,    71,   159,    70,    71,   149,   203,
      71,    71,   159,    71
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    79,    81,    80,    82,    82,    82,    84,    83,    85,
      85,    85,    85,    86,    86,    86,    87,    87,    87,    87,
      87,    87,    87,    88,    88,    88,    88,    88,    89,    89,
      89,    89,    89,    90,    90,    90,    90,    90,    91,    91,
      91,    92,    92,    92,    93,    93,    93,    94,    94,    95,
      95,    96,    97,    97,    98,    98,    98,    98,    98,    98,
      98,    98,    98,    98,    98,    98,    98,    98,    98,    98,
     100,    99,   102,   101,   103,   105,   104,   106,   106,   108,
     107,   109,   109,   109,   110,   110,   112,   111,   114,   113,
     116,   115,   117,   115,   118,   118,   119,   119,   120,   120,
     121,   121,   123,   122,   125,   124,   126,   126,   127,   127,
     128,   128,   130,   129,   131,   132,   132,   133,   134,   135,
     135,   136,   136,   136,   137,   137,   138,   138,   139,   139,
     141,   140,   142,   140,   143,   140,   144,   144,   145,   144,
     146,   147,   144,   148,   148,   149,   149,   150,   150,   151,
     151,   152,   152,   153,   152,   154,   152,   155,   155,   157,
     156,   158,   156,   159,   159,   160,   159,   161,   159,   162,
     162,   164,   163,   165,   165,   166,   166,   167,   167,   169,
     168,   170,   171,   171,   173,   172,   174,   172,   172,   172,
     172,   175,   175,   176,   178,   177,   179,   177,   180,   180,
     180,   180,   181,   180,   182,   180,   183,   180,   184,   180,
     185,   185,   186,   186,   188,   187,   190,   189,   191,   191,
     192,   192,   192,   192,   192,   192,   193,   193,   195,   194,
     194,   196,   196,   196,   196,   196,   196,   197,   197,   199,
     198,   198,   200,   200,   200,   201,   201,   202,   202,   203,
     203,   204,   203,   205,   205,   206,   206,   207,   206,   208,
     208,   210,   209,   211,   211,   211,   212,   212,   212,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   235,   235,   235,   235,   235,   235,   235,
     235,   235,   235,   235,   235,   236,   236,   236,   237,   237,
     237,   237,   237,   237,   237,   237,   237,   237,   237,   237,
     237,   237,   238,   239,   239,   239,   239,   239,   239,   239,
     239,   239,   239,   239,   239,   239,   239,   239,   239,   239,
     239,   239,   239,   239,   239,   240
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     2,     0,     2,     2,     0,     9,     0,
       1,     2,     1,     1,     2,     1,     1,     1,     1,     2,
       2,     2,     1,     1,     1,     2,     2,     1,     1,     1,
       2,     2,     1,     1,     1,     2,     2,     1,     1,     2,
       1,     1,     2,     1,     1,     2,     1,     1,     2,     1,
       1,     4,     1,     2,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       0,     5,     0,     5,     4,     0,     5,     0,     2,     0,
       5,     0,     1,     3,     1,     2,     0,     3,     0,     5,
       0,     7,     0,     9,     0,     4,     2,     1,     2,     1,
       0,     1,     0,     3,     0,     3,     2,     2,     3,     1,
       0,     2,     0,     9,     4,     0,     2,     4,     4,     1,
       4,     5,     5,     5,     0,     2,     1,     4,     0,     2,
       0,     6,     0,     6,     0,     6,     1,     4,     0,     8,
       0,     0,     7,     0,     2,     1,     4,     1,     4,     0,
       2,     1,     4,     0,     8,     0,     6,     0,     2,     0,
       6,     0,     6,     1,     4,     0,     8,     0,     6,     0,
       2,     0,    13,     2,     1,     2,     1,     2,     1,     0,
       5,     4,     0,     2,     0,     5,     0,     5,     4,     5,
       5,     1,     2,     4,     0,     6,     0,     6,     1,     5,
       4,     4,     0,     5,     0,     6,     0,     8,     0,     8,
       0,     2,     0,     2,     0,     5,     0,     5,     1,     4,
       1,     5,     5,     5,     5,     1,     0,     1,     0,     5,
       1,     1,     5,     5,     5,     5,     1,     0,     1,     0,
       5,     1,     0,     2,     2,     0,     2,     1,     1,     0,
       1,     0,     4,     1,     2,     0,     1,     0,     4,     1,
       2,     0,     3,     1,     1,     4,     1,     1,     2,     2,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1
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
#line 356 "pddl.yy" /* yacc.c:1646  */
    { success = true; line_number = 1; }
#line 2167 "pddl.cc" /* yacc.c:1646  */
    break;

  case 3:
#line 357 "pddl.yy" /* yacc.c:1646  */
    { if (!success) YYERROR; }
#line 2173 "pddl.cc" /* yacc.c:1646  */
    break;

  case 7:
#line 369 "pddl.yy" /* yacc.c:1646  */
    { make_domain((yyvsp[-1].str)); }
#line 2179 "pddl.cc" /* yacc.c:1646  */
    break;

  case 54:
#line 444 "pddl.yy" /* yacc.c:1646  */
    { requirements->strips = true; }
#line 2185 "pddl.cc" /* yacc.c:1646  */
    break;

  case 55:
#line 445 "pddl.yy" /* yacc.c:1646  */
    { requirements->typing = true; }
#line 2191 "pddl.cc" /* yacc.c:1646  */
    break;

  case 56:
#line 447 "pddl.yy" /* yacc.c:1646  */
    { requirements->negative_preconditions = true; }
#line 2197 "pddl.cc" /* yacc.c:1646  */
    break;

  case 57:
#line 449 "pddl.yy" /* yacc.c:1646  */
    { requirements->disjunctive_preconditions = true; }
#line 2203 "pddl.cc" /* yacc.c:1646  */
    break;

  case 58:
#line 450 "pddl.yy" /* yacc.c:1646  */
    { requirements->equality = true; }
#line 2209 "pddl.cc" /* yacc.c:1646  */
    break;

  case 59:
#line 452 "pddl.yy" /* yacc.c:1646  */
    { requirements->existential_preconditions = true; }
#line 2215 "pddl.cc" /* yacc.c:1646  */
    break;

  case 60:
#line 454 "pddl.yy" /* yacc.c:1646  */
    { requirements->universal_preconditions = true; }
#line 2221 "pddl.cc" /* yacc.c:1646  */
    break;

  case 61:
#line 456 "pddl.yy" /* yacc.c:1646  */
    { requirements->quantified_preconditions(); }
#line 2227 "pddl.cc" /* yacc.c:1646  */
    break;

  case 62:
#line 457 "pddl.yy" /* yacc.c:1646  */
    { requirements->conditional_effects = true; }
#line 2233 "pddl.cc" /* yacc.c:1646  */
    break;

  case 63:
#line 458 "pddl.yy" /* yacc.c:1646  */
    { requirements->fluents = true; }
#line 2239 "pddl.cc" /* yacc.c:1646  */
    break;

  case 64:
#line 459 "pddl.yy" /* yacc.c:1646  */
    { requirements->adl(); }
#line 2245 "pddl.cc" /* yacc.c:1646  */
    break;

  case 65:
#line 460 "pddl.yy" /* yacc.c:1646  */
    { requirements->durative_actions = true; }
#line 2251 "pddl.cc" /* yacc.c:1646  */
    break;

  case 66:
#line 462 "pddl.yy" /* yacc.c:1646  */
    { requirements->duration_inequalities = true; }
#line 2257 "pddl.cc" /* yacc.c:1646  */
    break;

  case 67:
#line 464 "pddl.yy" /* yacc.c:1646  */
    { yyerror("`:continuous-effects' not supported"); }
#line 2263 "pddl.cc" /* yacc.c:1646  */
    break;

  case 68:
#line 466 "pddl.yy" /* yacc.c:1646  */
    {
					requirements->durative_actions = true;
					requirements->timed_initial_literals = true;
				}
#line 2272 "pddl.cc" /* yacc.c:1646  */
    break;

  case 69:
#line 470 "pddl.yy" /* yacc.c:1646  */
    { requirements->decompositions = true; }
#line 2278 "pddl.cc" /* yacc.c:1646  */
    break;

  case 70:
#line 473 "pddl.yy" /* yacc.c:1646  */
    { require_typing(); name_kind = TYPE_KIND; }
#line 2284 "pddl.cc" /* yacc.c:1646  */
    break;

  case 71:
#line 474 "pddl.yy" /* yacc.c:1646  */
    { name_kind = VOID_KIND; }
#line 2290 "pddl.cc" /* yacc.c:1646  */
    break;

  case 72:
#line 477 "pddl.yy" /* yacc.c:1646  */
    { name_kind = CONSTANT_KIND; }
#line 2296 "pddl.cc" /* yacc.c:1646  */
    break;

  case 73:
#line 478 "pddl.yy" /* yacc.c:1646  */
    { name_kind = VOID_KIND; }
#line 2302 "pddl.cc" /* yacc.c:1646  */
    break;

  case 75:
#line 484 "pddl.yy" /* yacc.c:1646  */
    { require_fluents(); }
#line 2308 "pddl.cc" /* yacc.c:1646  */
    break;

  case 79:
#line 495 "pddl.yy" /* yacc.c:1646  */
    { make_predicate((yyvsp[0].str)); }
#line 2314 "pddl.cc" /* yacc.c:1646  */
    break;

  case 80:
#line 496 "pddl.yy" /* yacc.c:1646  */
    { predicate = 0; }
#line 2320 "pddl.cc" /* yacc.c:1646  */
    break;

  case 86:
#line 508 "pddl.yy" /* yacc.c:1646  */
    { require_typing(); }
#line 2326 "pddl.cc" /* yacc.c:1646  */
    break;

  case 88:
#line 511 "pddl.yy" /* yacc.c:1646  */
    { make_function((yyvsp[0].str)); }
#line 2332 "pddl.cc" /* yacc.c:1646  */
    break;

  case 89:
#line 512 "pddl.yy" /* yacc.c:1646  */
    { function = 0; }
#line 2338 "pddl.cc" /* yacc.c:1646  */
    break;

  case 90:
#line 519 "pddl.yy" /* yacc.c:1646  */
    { make_action((yyvsp[0].str), false, false); }
#line 2344 "pddl.cc" /* yacc.c:1646  */
    break;

  case 91:
#line 519 "pddl.yy" /* yacc.c:1646  */
    { add_action(); }
#line 2350 "pddl.cc" /* yacc.c:1646  */
    break;

  case 92:
#line 520 "pddl.yy" /* yacc.c:1646  */
    { make_action((yyvsp[0].str), true, false); }
#line 2356 "pddl.cc" /* yacc.c:1646  */
    break;

  case 93:
#line 520 "pddl.yy" /* yacc.c:1646  */
    { add_action(); }
#line 2362 "pddl.cc" /* yacc.c:1646  */
    break;

  case 102:
#line 539 "pddl.yy" /* yacc.c:1646  */
    { formula_time = AT_START; }
#line 2368 "pddl.cc" /* yacc.c:1646  */
    break;

  case 103:
#line 539 "pddl.yy" /* yacc.c:1646  */
    { action->set_condition(*(yyvsp[0].formula)); }
#line 2374 "pddl.cc" /* yacc.c:1646  */
    break;

  case 104:
#line 542 "pddl.yy" /* yacc.c:1646  */
    { effect_time = Effect::AT_END; }
#line 2380 "pddl.cc" /* yacc.c:1646  */
    break;

  case 106:
#line 545 "pddl.yy" /* yacc.c:1646  */
    { require_decompositions(); action->set_composite(true); }
#line 2386 "pddl.cc" /* yacc.c:1646  */
    break;

  case 107:
#line 546 "pddl.yy" /* yacc.c:1646  */
    { require_decompositions(); action->set_composite(false); }
#line 2392 "pddl.cc" /* yacc.c:1646  */
    break;

  case 108:
#line 549 "pddl.yy" /* yacc.c:1646  */
    { action->set_condition(*(yyvsp[-1].formula)); }
#line 2398 "pddl.cc" /* yacc.c:1646  */
    break;

  case 112:
#line 562 "pddl.yy" /* yacc.c:1646  */
    { 
							/* Verify that there exists a composite action already defined in the domain. */
							if(!composite_action_exists((yyvsp[-2].str))) {
								yyerror("No composite action of type " + *(yyvsp[-2].str) + " exists for decomposition " + *(yyvsp[0].str));
							}

							else {
								make_decomposition((yyvsp[-2].str), (yyvsp[0].str)); 
							}
						}
#line 2413 "pddl.cc" /* yacc.c:1646  */
    break;

  case 113:
#line 572 "pddl.yy" /* yacc.c:1646  */
    { add_decomposition(); }
#line 2419 "pddl.cc" /* yacc.c:1646  */
    break;

  case 118:
#line 585 "pddl.yy" /* yacc.c:1646  */
    {

					/* 1. Verify that the name refers to an existing action. */
					const ActionSchema* a = domain->find_action(*(yyvsp[-2].str));
					if(a == 0) {
						yyerror("No action of type " + *(yyvsp[-2].str) + " exists for pseudo-step definition");
					}

					else 
					{
					  /* 2. Verify that the indicated terms match the corresponding action correctly. */
					  /* 3. Build a pseudo-step. */
					  /* 4. Return it. */
					}
				}
#line 2439 "pddl.cc" /* yacc.c:1646  */
    break;

  case 120:
#line 607 "pddl.yy" /* yacc.c:1646  */
    { require_duration_inequalities(); }
#line 2445 "pddl.cc" /* yacc.c:1646  */
    break;

  case 121:
#line 611 "pddl.yy" /* yacc.c:1646  */
    {
				 require_duration_inequalities();
				 action->set_max_duration(*(yyvsp[-1].expr));
			       }
#line 2454 "pddl.cc" /* yacc.c:1646  */
    break;

  case 122:
#line 616 "pddl.yy" /* yacc.c:1646  */
    {
				 require_duration_inequalities();
				 action->set_min_duration(*(yyvsp[-1].expr));
			       }
#line 2463 "pddl.cc" /* yacc.c:1646  */
    break;

  case 123:
#line 621 "pddl.yy" /* yacc.c:1646  */
    { action->set_duration(*(yyvsp[-1].expr)); }
#line 2469 "pddl.cc" /* yacc.c:1646  */
    break;

  case 127:
#line 634 "pddl.yy" /* yacc.c:1646  */
    { (yyval.formula) = (yyvsp[-1].formula); }
#line 2475 "pddl.cc" /* yacc.c:1646  */
    break;

  case 128:
#line 637 "pddl.yy" /* yacc.c:1646  */
    { (yyval.formula) = &Formula::TRUE; }
#line 2481 "pddl.cc" /* yacc.c:1646  */
    break;

  case 129:
#line 638 "pddl.yy" /* yacc.c:1646  */
    { (yyval.formula) = &(*(yyvsp[-1].formula) && *(yyvsp[0].formula)); }
#line 2487 "pddl.cc" /* yacc.c:1646  */
    break;

  case 130:
#line 641 "pddl.yy" /* yacc.c:1646  */
    { formula_time = AT_START; }
#line 2493 "pddl.cc" /* yacc.c:1646  */
    break;

  case 131:
#line 641 "pddl.yy" /* yacc.c:1646  */
    { (yyval.formula) = (yyvsp[-1].formula); }
#line 2499 "pddl.cc" /* yacc.c:1646  */
    break;

  case 132:
#line 642 "pddl.yy" /* yacc.c:1646  */
    { formula_time = AT_END; }
#line 2505 "pddl.cc" /* yacc.c:1646  */
    break;

  case 133:
#line 642 "pddl.yy" /* yacc.c:1646  */
    { (yyval.formula) = (yyvsp[-1].formula); }
#line 2511 "pddl.cc" /* yacc.c:1646  */
    break;

  case 134:
#line 643 "pddl.yy" /* yacc.c:1646  */
    { formula_time = OVER_ALL; }
#line 2517 "pddl.cc" /* yacc.c:1646  */
    break;

  case 135:
#line 643 "pddl.yy" /* yacc.c:1646  */
    { (yyval.formula) = (yyvsp[-1].formula); }
#line 2523 "pddl.cc" /* yacc.c:1646  */
    break;

  case 138:
#line 652 "pddl.yy" /* yacc.c:1646  */
    { prepare_forall_effect(); }
#line 2529 "pddl.cc" /* yacc.c:1646  */
    break;

  case 139:
#line 652 "pddl.yy" /* yacc.c:1646  */
    { pop_forall_effect(); }
#line 2535 "pddl.cc" /* yacc.c:1646  */
    break;

  case 140:
#line 653 "pddl.yy" /* yacc.c:1646  */
    { formula_time = AT_START; }
#line 2541 "pddl.cc" /* yacc.c:1646  */
    break;

  case 141:
#line 653 "pddl.yy" /* yacc.c:1646  */
    { prepare_conditional_effect(*(yyvsp[0].formula)); }
#line 2547 "pddl.cc" /* yacc.c:1646  */
    break;

  case 142:
#line 653 "pddl.yy" /* yacc.c:1646  */
    { effect_condition = 0; }
#line 2553 "pddl.cc" /* yacc.c:1646  */
    break;

  case 147:
#line 664 "pddl.yy" /* yacc.c:1646  */
    { add_effect(*(yyvsp[0].atom)); }
#line 2559 "pddl.cc" /* yacc.c:1646  */
    break;

  case 148:
#line 665 "pddl.yy" /* yacc.c:1646  */
    { add_effect(Negation::make(*(yyvsp[-1].atom))); }
#line 2565 "pddl.cc" /* yacc.c:1646  */
    break;

  case 153:
#line 674 "pddl.yy" /* yacc.c:1646  */
    { prepare_forall_effect(); }
#line 2571 "pddl.cc" /* yacc.c:1646  */
    break;

  case 154:
#line 675 "pddl.yy" /* yacc.c:1646  */
    { pop_forall_effect(); }
#line 2577 "pddl.cc" /* yacc.c:1646  */
    break;

  case 155:
#line 676 "pddl.yy" /* yacc.c:1646  */
    { prepare_conditional_effect(*(yyvsp[0].formula)); }
#line 2583 "pddl.cc" /* yacc.c:1646  */
    break;

  case 156:
#line 677 "pddl.yy" /* yacc.c:1646  */
    { effect_condition = 0; }
#line 2589 "pddl.cc" /* yacc.c:1646  */
    break;

  case 159:
#line 685 "pddl.yy" /* yacc.c:1646  */
    { effect_time = Effect::AT_START; formula_time = AT_START; }
#line 2595 "pddl.cc" /* yacc.c:1646  */
    break;

  case 161:
#line 688 "pddl.yy" /* yacc.c:1646  */
    { effect_time = Effect::AT_END; formula_time = AT_END; }
#line 2601 "pddl.cc" /* yacc.c:1646  */
    break;

  case 165:
#line 694 "pddl.yy" /* yacc.c:1646  */
    { prepare_forall_effect(); }
#line 2607 "pddl.cc" /* yacc.c:1646  */
    break;

  case 166:
#line 695 "pddl.yy" /* yacc.c:1646  */
    { pop_forall_effect(); }
#line 2613 "pddl.cc" /* yacc.c:1646  */
    break;

  case 167:
#line 696 "pddl.yy" /* yacc.c:1646  */
    { prepare_conditional_effect(*(yyvsp[0].formula)); }
#line 2619 "pddl.cc" /* yacc.c:1646  */
    break;

  case 168:
#line 697 "pddl.yy" /* yacc.c:1646  */
    { effect_condition = 0; }
#line 2625 "pddl.cc" /* yacc.c:1646  */
    break;

  case 171:
#line 709 "pddl.yy" /* yacc.c:1646  */
    { make_problem((yyvsp[-5].str), (yyvsp[-1].str)); }
#line 2631 "pddl.cc" /* yacc.c:1646  */
    break;

  case 172:
#line 710 "pddl.yy" /* yacc.c:1646  */
    { delete requirements; }
#line 2637 "pddl.cc" /* yacc.c:1646  */
    break;

  case 179:
#line 725 "pddl.yy" /* yacc.c:1646  */
    { name_kind = OBJECT_KIND; }
#line 2643 "pddl.cc" /* yacc.c:1646  */
    break;

  case 180:
#line 726 "pddl.yy" /* yacc.c:1646  */
    { name_kind = VOID_KIND; }
#line 2649 "pddl.cc" /* yacc.c:1646  */
    break;

  case 184:
#line 736 "pddl.yy" /* yacc.c:1646  */
    { prepare_atom((yyvsp[0].str)); }
#line 2655 "pddl.cc" /* yacc.c:1646  */
    break;

  case 185:
#line 737 "pddl.yy" /* yacc.c:1646  */
    { problem->add_init_atom(*make_atom()); }
#line 2661 "pddl.cc" /* yacc.c:1646  */
    break;

  case 186:
#line 738 "pddl.yy" /* yacc.c:1646  */
    { prepare_atom((yyvsp[0].str)); }
#line 2667 "pddl.cc" /* yacc.c:1646  */
    break;

  case 187:
#line 739 "pddl.yy" /* yacc.c:1646  */
    { problem->add_init_atom(*make_atom()); }
#line 2673 "pddl.cc" /* yacc.c:1646  */
    break;

  case 188:
#line 741 "pddl.yy" /* yacc.c:1646  */
    { Formula::register_use((yyvsp[-1].atom)); Formula::unregister_use((yyvsp[-1].atom)); }
#line 2679 "pddl.cc" /* yacc.c:1646  */
    break;

  case 189:
#line 743 "pddl.yy" /* yacc.c:1646  */
    { problem->add_init_value(*(yyvsp[-2].fluent), (yyvsp[-1].num)); }
#line 2685 "pddl.cc" /* yacc.c:1646  */
    break;

  case 190:
#line 745 "pddl.yy" /* yacc.c:1646  */
    { add_init_literal((yyvsp[-2].num), *(yyvsp[-1].literal)); }
#line 2691 "pddl.cc" /* yacc.c:1646  */
    break;

  case 193:
#line 752 "pddl.yy" /* yacc.c:1646  */
    { problem->set_goal(*(yyvsp[-1].formula)); }
#line 2697 "pddl.cc" /* yacc.c:1646  */
    break;

  case 194:
#line 755 "pddl.yy" /* yacc.c:1646  */
    { metric_fluent = true; }
#line 2703 "pddl.cc" /* yacc.c:1646  */
    break;

  case 195:
#line 756 "pddl.yy" /* yacc.c:1646  */
    { problem->set_metric(*(yyvsp[-1].expr), true); metric_fluent = false; }
#line 2709 "pddl.cc" /* yacc.c:1646  */
    break;

  case 196:
#line 757 "pddl.yy" /* yacc.c:1646  */
    { metric_fluent = true; }
#line 2715 "pddl.cc" /* yacc.c:1646  */
    break;

  case 197:
#line 758 "pddl.yy" /* yacc.c:1646  */
    { problem->set_metric(*(yyvsp[-1].expr)); metric_fluent = false; }
#line 2721 "pddl.cc" /* yacc.c:1646  */
    break;

  case 198:
#line 765 "pddl.yy" /* yacc.c:1646  */
    { (yyval.formula) = &TimedLiteral::make(*(yyvsp[0].atom), formula_time); }
#line 2727 "pddl.cc" /* yacc.c:1646  */
    break;

  case 199:
#line 766 "pddl.yy" /* yacc.c:1646  */
    { (yyval.formula) = make_equality((yyvsp[-2].term), (yyvsp[-1].term)); }
#line 2733 "pddl.cc" /* yacc.c:1646  */
    break;

  case 200:
#line 767 "pddl.yy" /* yacc.c:1646  */
    { (yyval.formula) = make_negation(*(yyvsp[-1].formula)); }
#line 2739 "pddl.cc" /* yacc.c:1646  */
    break;

  case 201:
#line 768 "pddl.yy" /* yacc.c:1646  */
    { (yyval.formula) = (yyvsp[-1].formula); }
#line 2745 "pddl.cc" /* yacc.c:1646  */
    break;

  case 202:
#line 769 "pddl.yy" /* yacc.c:1646  */
    { require_disjunction(); }
#line 2751 "pddl.cc" /* yacc.c:1646  */
    break;

  case 203:
#line 769 "pddl.yy" /* yacc.c:1646  */
    { (yyval.formula) = (yyvsp[-1].formula); }
#line 2757 "pddl.cc" /* yacc.c:1646  */
    break;

  case 204:
#line 770 "pddl.yy" /* yacc.c:1646  */
    { require_disjunction(); }
#line 2763 "pddl.cc" /* yacc.c:1646  */
    break;

  case 205:
#line 771 "pddl.yy" /* yacc.c:1646  */
    { (yyval.formula) = &(!*(yyvsp[-2].formula) || *(yyvsp[-1].formula)); }
#line 2769 "pddl.cc" /* yacc.c:1646  */
    break;

  case 206:
#line 772 "pddl.yy" /* yacc.c:1646  */
    { prepare_exists(); }
#line 2775 "pddl.cc" /* yacc.c:1646  */
    break;

  case 207:
#line 773 "pddl.yy" /* yacc.c:1646  */
    { (yyval.formula) = make_exists(*(yyvsp[-1].formula)); }
#line 2781 "pddl.cc" /* yacc.c:1646  */
    break;

  case 208:
#line 774 "pddl.yy" /* yacc.c:1646  */
    { prepare_forall(); }
#line 2787 "pddl.cc" /* yacc.c:1646  */
    break;

  case 209:
#line 775 "pddl.yy" /* yacc.c:1646  */
    { (yyval.formula) = make_forall(*(yyvsp[-1].formula)); }
#line 2793 "pddl.cc" /* yacc.c:1646  */
    break;

  case 210:
#line 778 "pddl.yy" /* yacc.c:1646  */
    { (yyval.formula) = &Formula::TRUE; }
#line 2799 "pddl.cc" /* yacc.c:1646  */
    break;

  case 211:
#line 779 "pddl.yy" /* yacc.c:1646  */
    { (yyval.formula) = &(*(yyvsp[-1].formula) && *(yyvsp[0].formula)); }
#line 2805 "pddl.cc" /* yacc.c:1646  */
    break;

  case 212:
#line 782 "pddl.yy" /* yacc.c:1646  */
    { (yyval.formula) = &Formula::FALSE; }
#line 2811 "pddl.cc" /* yacc.c:1646  */
    break;

  case 213:
#line 783 "pddl.yy" /* yacc.c:1646  */
    { (yyval.formula) = &(*(yyvsp[-1].formula) || *(yyvsp[0].formula)); }
#line 2817 "pddl.cc" /* yacc.c:1646  */
    break;

  case 214:
#line 786 "pddl.yy" /* yacc.c:1646  */
    { prepare_atom((yyvsp[0].str)); }
#line 2823 "pddl.cc" /* yacc.c:1646  */
    break;

  case 215:
#line 787 "pddl.yy" /* yacc.c:1646  */
    { (yyval.atom) = make_atom(); }
#line 2829 "pddl.cc" /* yacc.c:1646  */
    break;

  case 216:
#line 790 "pddl.yy" /* yacc.c:1646  */
    { prepare_atom((yyvsp[0].str)); }
#line 2835 "pddl.cc" /* yacc.c:1646  */
    break;

  case 217:
#line 791 "pddl.yy" /* yacc.c:1646  */
    { (yyval.atom) = make_atom(); }
#line 2841 "pddl.cc" /* yacc.c:1646  */
    break;

  case 218:
#line 794 "pddl.yy" /* yacc.c:1646  */
    { (yyval.literal) = (yyvsp[0].atom); }
#line 2847 "pddl.cc" /* yacc.c:1646  */
    break;

  case 219:
#line 795 "pddl.yy" /* yacc.c:1646  */
    { (yyval.literal) = &Negation::make(*(yyvsp[-1].atom)); }
#line 2853 "pddl.cc" /* yacc.c:1646  */
    break;

  case 220:
#line 802 "pddl.yy" /* yacc.c:1646  */
    { (yyval.expr) = new Value((yyvsp[0].num)); }
#line 2859 "pddl.cc" /* yacc.c:1646  */
    break;

  case 221:
#line 803 "pddl.yy" /* yacc.c:1646  */
    { (yyval.expr) = &Addition::make(*(yyvsp[-2].expr), *(yyvsp[-1].expr)); }
#line 2865 "pddl.cc" /* yacc.c:1646  */
    break;

  case 222:
#line 804 "pddl.yy" /* yacc.c:1646  */
    { (yyval.expr) = make_subtraction(*(yyvsp[-2].expr), (yyvsp[-1].expr)); }
#line 2871 "pddl.cc" /* yacc.c:1646  */
    break;

  case 223:
#line 805 "pddl.yy" /* yacc.c:1646  */
    { (yyval.expr) = &Multiplication::make(*(yyvsp[-2].expr), *(yyvsp[-1].expr)); }
#line 2877 "pddl.cc" /* yacc.c:1646  */
    break;

  case 224:
#line 806 "pddl.yy" /* yacc.c:1646  */
    { (yyval.expr) = &Division::make(*(yyvsp[-2].expr), *(yyvsp[-1].expr)); }
#line 2883 "pddl.cc" /* yacc.c:1646  */
    break;

  case 225:
#line 807 "pddl.yy" /* yacc.c:1646  */
    { (yyval.expr) = (yyvsp[0].fluent); }
#line 2889 "pddl.cc" /* yacc.c:1646  */
    break;

  case 226:
#line 810 "pddl.yy" /* yacc.c:1646  */
    { (yyval.expr) = 0; }
#line 2895 "pddl.cc" /* yacc.c:1646  */
    break;

  case 228:
#line 814 "pddl.yy" /* yacc.c:1646  */
    { prepare_fluent((yyvsp[0].str)); }
#line 2901 "pddl.cc" /* yacc.c:1646  */
    break;

  case 229:
#line 815 "pddl.yy" /* yacc.c:1646  */
    { (yyval.fluent) = make_fluent(); }
#line 2907 "pddl.cc" /* yacc.c:1646  */
    break;

  case 230:
#line 816 "pddl.yy" /* yacc.c:1646  */
    { prepare_fluent((yyvsp[0].str)); (yyval.fluent) = make_fluent(); }
#line 2913 "pddl.cc" /* yacc.c:1646  */
    break;

  case 231:
#line 819 "pddl.yy" /* yacc.c:1646  */
    { (yyval.expr) = new Value((yyvsp[0].num)); }
#line 2919 "pddl.cc" /* yacc.c:1646  */
    break;

  case 232:
#line 821 "pddl.yy" /* yacc.c:1646  */
    { (yyval.expr) = &Addition::make(*(yyvsp[-2].expr), *(yyvsp[-1].expr)); }
#line 2925 "pddl.cc" /* yacc.c:1646  */
    break;

  case 233:
#line 823 "pddl.yy" /* yacc.c:1646  */
    { (yyval.expr) = make_subtraction(*(yyvsp[-2].expr), (yyvsp[-1].expr)); }
#line 2931 "pddl.cc" /* yacc.c:1646  */
    break;

  case 234:
#line 825 "pddl.yy" /* yacc.c:1646  */
    { (yyval.expr) = &Multiplication::make(*(yyvsp[-2].expr), *(yyvsp[-1].expr)); }
#line 2937 "pddl.cc" /* yacc.c:1646  */
    break;

  case 235:
#line 827 "pddl.yy" /* yacc.c:1646  */
    { (yyval.expr) = &Division::make(*(yyvsp[-2].expr), *(yyvsp[-1].expr)); }
#line 2943 "pddl.cc" /* yacc.c:1646  */
    break;

  case 236:
#line 828 "pddl.yy" /* yacc.c:1646  */
    { (yyval.expr) = (yyvsp[0].fluent); }
#line 2949 "pddl.cc" /* yacc.c:1646  */
    break;

  case 237:
#line 831 "pddl.yy" /* yacc.c:1646  */
    { (yyval.expr) = 0; }
#line 2955 "pddl.cc" /* yacc.c:1646  */
    break;

  case 239:
#line 835 "pddl.yy" /* yacc.c:1646  */
    { prepare_fluent((yyvsp[0].str)); }
#line 2961 "pddl.cc" /* yacc.c:1646  */
    break;

  case 240:
#line 836 "pddl.yy" /* yacc.c:1646  */
    { (yyval.fluent) = make_fluent(); }
#line 2967 "pddl.cc" /* yacc.c:1646  */
    break;

  case 241:
#line 837 "pddl.yy" /* yacc.c:1646  */
    { prepare_fluent((yyvsp[0].str)); (yyval.fluent) = make_fluent(); }
#line 2973 "pddl.cc" /* yacc.c:1646  */
    break;

  case 243:
#line 845 "pddl.yy" /* yacc.c:1646  */
    { add_term((yyvsp[0].str)); }
#line 2979 "pddl.cc" /* yacc.c:1646  */
    break;

  case 244:
#line 846 "pddl.yy" /* yacc.c:1646  */
    { add_term((yyvsp[0].str)); }
#line 2985 "pddl.cc" /* yacc.c:1646  */
    break;

  case 246:
#line 850 "pddl.yy" /* yacc.c:1646  */
    { add_term((yyvsp[0].str)); }
#line 2991 "pddl.cc" /* yacc.c:1646  */
    break;

  case 247:
#line 853 "pddl.yy" /* yacc.c:1646  */
    { (yyval.term) = new Term(make_term((yyvsp[0].str))); }
#line 2997 "pddl.cc" /* yacc.c:1646  */
    break;

  case 248:
#line 854 "pddl.yy" /* yacc.c:1646  */
    { (yyval.term) = new Term(make_term((yyvsp[0].str))); }
#line 3003 "pddl.cc" /* yacc.c:1646  */
    break;

  case 250:
#line 858 "pddl.yy" /* yacc.c:1646  */
    { add_variables((yyvsp[0].strs), TypeTable::OBJECT); }
#line 3009 "pddl.cc" /* yacc.c:1646  */
    break;

  case 251:
#line 859 "pddl.yy" /* yacc.c:1646  */
    { add_variables((yyvsp[-1].strs), *(yyvsp[0].type)); delete (yyvsp[0].type); }
#line 3015 "pddl.cc" /* yacc.c:1646  */
    break;

  case 253:
#line 863 "pddl.yy" /* yacc.c:1646  */
    { (yyval.strs) = new std::vector<const std::string*>(1, (yyvsp[0].str)); }
#line 3021 "pddl.cc" /* yacc.c:1646  */
    break;

  case 254:
#line 864 "pddl.yy" /* yacc.c:1646  */
    { (yyval.strs) = (yyvsp[-1].strs); (yyval.strs)->push_back((yyvsp[0].str)); }
#line 3027 "pddl.cc" /* yacc.c:1646  */
    break;

  case 256:
#line 868 "pddl.yy" /* yacc.c:1646  */
    { add_names((yyvsp[0].strs), TypeTable::OBJECT); }
#line 3033 "pddl.cc" /* yacc.c:1646  */
    break;

  case 257:
#line 869 "pddl.yy" /* yacc.c:1646  */
    { add_names((yyvsp[-1].strs), *(yyvsp[0].type)); delete (yyvsp[0].type); }
#line 3039 "pddl.cc" /* yacc.c:1646  */
    break;

  case 259:
#line 872 "pddl.yy" /* yacc.c:1646  */
    { (yyval.strs) = new std::vector<const std::string*>(1, (yyvsp[0].str)); }
#line 3045 "pddl.cc" /* yacc.c:1646  */
    break;

  case 260:
#line 873 "pddl.yy" /* yacc.c:1646  */
    { (yyval.strs) = (yyvsp[-1].strs); (yyval.strs)->push_back((yyvsp[0].str)); }
#line 3051 "pddl.cc" /* yacc.c:1646  */
    break;

  case 261:
#line 876 "pddl.yy" /* yacc.c:1646  */
    { require_typing(); }
#line 3057 "pddl.cc" /* yacc.c:1646  */
    break;

  case 262:
#line 876 "pddl.yy" /* yacc.c:1646  */
    { (yyval.type) = (yyvsp[0].type); }
#line 3063 "pddl.cc" /* yacc.c:1646  */
    break;

  case 263:
#line 879 "pddl.yy" /* yacc.c:1646  */
    { (yyval.type) = new Type(TypeTable::OBJECT); }
#line 3069 "pddl.cc" /* yacc.c:1646  */
    break;

  case 264:
#line 880 "pddl.yy" /* yacc.c:1646  */
    { (yyval.type) = new Type(make_type((yyvsp[0].str))); }
#line 3075 "pddl.cc" /* yacc.c:1646  */
    break;

  case 265:
#line 881 "pddl.yy" /* yacc.c:1646  */
    { (yyval.type) = new Type(make_type(*(yyvsp[-1].types))); delete (yyvsp[-1].types); }
#line 3081 "pddl.cc" /* yacc.c:1646  */
    break;

  case 266:
#line 884 "pddl.yy" /* yacc.c:1646  */
    { (yyval.types) = new TypeSet(); }
#line 3087 "pddl.cc" /* yacc.c:1646  */
    break;

  case 267:
#line 885 "pddl.yy" /* yacc.c:1646  */
    { (yyval.types) = new TypeSet(); (yyval.types)->insert(make_type((yyvsp[0].str))); }
#line 3093 "pddl.cc" /* yacc.c:1646  */
    break;

  case 268:
#line 886 "pddl.yy" /* yacc.c:1646  */
    { (yyval.types) = (yyvsp[-1].types); }
#line 3099 "pddl.cc" /* yacc.c:1646  */
    break;

  case 269:
#line 887 "pddl.yy" /* yacc.c:1646  */
    { (yyval.types) = (yyvsp[-1].types); (yyval.types)->insert(make_type((yyvsp[0].str))); }
#line 3105 "pddl.cc" /* yacc.c:1646  */
    break;

  case 271:
#line 897 "pddl.yy" /* yacc.c:1646  */
    { delete (yyvsp[0].str); }
#line 3111 "pddl.cc" /* yacc.c:1646  */
    break;

  case 272:
#line 900 "pddl.yy" /* yacc.c:1646  */
    { delete (yyvsp[0].str); }
#line 3117 "pddl.cc" /* yacc.c:1646  */
    break;

  case 273:
#line 903 "pddl.yy" /* yacc.c:1646  */
    { delete (yyvsp[0].str); }
#line 3123 "pddl.cc" /* yacc.c:1646  */
    break;

  case 274:
#line 906 "pddl.yy" /* yacc.c:1646  */
    { delete (yyvsp[0].str); }
#line 3129 "pddl.cc" /* yacc.c:1646  */
    break;

  case 275:
#line 909 "pddl.yy" /* yacc.c:1646  */
    { delete (yyvsp[0].str); }
#line 3135 "pddl.cc" /* yacc.c:1646  */
    break;

  case 276:
#line 912 "pddl.yy" /* yacc.c:1646  */
    { delete (yyvsp[0].str); }
#line 3141 "pddl.cc" /* yacc.c:1646  */
    break;

  case 277:
#line 915 "pddl.yy" /* yacc.c:1646  */
    { delete (yyvsp[0].str); }
#line 3147 "pddl.cc" /* yacc.c:1646  */
    break;

  case 278:
#line 918 "pddl.yy" /* yacc.c:1646  */
    { delete (yyvsp[0].str); }
#line 3153 "pddl.cc" /* yacc.c:1646  */
    break;

  case 279:
#line 921 "pddl.yy" /* yacc.c:1646  */
    { delete (yyvsp[0].str); }
#line 3159 "pddl.cc" /* yacc.c:1646  */
    break;

  case 280:
#line 924 "pddl.yy" /* yacc.c:1646  */
    { delete (yyvsp[0].str); }
#line 3165 "pddl.cc" /* yacc.c:1646  */
    break;

  case 281:
#line 927 "pddl.yy" /* yacc.c:1646  */
    { delete (yyvsp[0].str); }
#line 3171 "pddl.cc" /* yacc.c:1646  */
    break;

  case 282:
#line 930 "pddl.yy" /* yacc.c:1646  */
    { delete (yyvsp[0].str); }
#line 3177 "pddl.cc" /* yacc.c:1646  */
    break;

  case 283:
#line 933 "pddl.yy" /* yacc.c:1646  */
    { delete (yyvsp[0].str); }
#line 3183 "pddl.cc" /* yacc.c:1646  */
    break;

  case 284:
#line 936 "pddl.yy" /* yacc.c:1646  */
    { delete (yyvsp[0].str); }
#line 3189 "pddl.cc" /* yacc.c:1646  */
    break;

  case 285:
#line 939 "pddl.yy" /* yacc.c:1646  */
    { delete (yyvsp[0].str); }
#line 3195 "pddl.cc" /* yacc.c:1646  */
    break;

  case 286:
#line 942 "pddl.yy" /* yacc.c:1646  */
    { delete (yyvsp[0].str); }
#line 3201 "pddl.cc" /* yacc.c:1646  */
    break;

  case 287:
#line 945 "pddl.yy" /* yacc.c:1646  */
    { delete (yyvsp[0].str); }
#line 3207 "pddl.cc" /* yacc.c:1646  */
    break;

  case 288:
#line 948 "pddl.yy" /* yacc.c:1646  */
    { delete (yyvsp[0].str); }
#line 3213 "pddl.cc" /* yacc.c:1646  */
    break;

  case 289:
#line 951 "pddl.yy" /* yacc.c:1646  */
    { delete (yyvsp[0].str); }
#line 3219 "pddl.cc" /* yacc.c:1646  */
    break;

  case 290:
#line 954 "pddl.yy" /* yacc.c:1646  */
    { delete (yyvsp[0].str); }
#line 3225 "pddl.cc" /* yacc.c:1646  */
    break;

  case 291:
#line 957 "pddl.yy" /* yacc.c:1646  */
    { delete (yyvsp[0].str); }
#line 3231 "pddl.cc" /* yacc.c:1646  */
    break;


#line 3235 "pddl.cc" /* yacc.c:1646  */
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
#line 993 "pddl.yy" /* yacc.c:1906  */


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
    yywarning("assuming `:decompositions' requirement");
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

/* Checks whether there exists a composite action with the given name in the current domain. */
static bool composite_action_exists(const std::string* composite_action_name)
{
	const ActionSchema* a = domain->find_action(*composite_action_name);
	return (a != 0 && a->composite());
}

/* Creates a decomposition for the given composite action name with the given name. */
static void make_decomposition(const std::string* composite_action_name, const std::string* name) 
{
	context.push_frame();
	decomposition = new DecompositionSchema(*composite_action_name, *name);
	delete name; 
}

/* Adds the current decomposition to the current domain. */
static void add_decomposition()
{
	context.pop_frame();

	/* If we have not declared this decomposition in the past, */
	if(domain->find_decomposition(decomposition->composite_action_name(), decomposition->name()) == 0) {
		domain->add_decomposition(*decomposition);
	}

	else {
		yywarning("ignoring repeated declaration of decomposition `" 
			+ decomposition->name() + "' for composite action `" 
			+ decomposition->composite_action_name() + "'");
		delete decomposition;
	}

	decomposition = 0;
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
static void add_variables(const std::vector<const std::string*>* names, const Type& type) 
{
  for (std::vector<const std::string*>::const_iterator si = names->begin();
       si != names->end(); 
	   si++) 
  {
    const std::string* s = *si;
    
	if (predicate != 0) 
	{
      if (!repeated_predicate) {
		PredicateTable::add_parameter(*predicate, type);
      }
    } 
	
	else if (function != 0) 
	{
      if (!repeated_function) {
		FunctionTable::add_parameter(*function, type);
      }
    } 
	
	else 
	{
      if (context.shallow_find(*s) != 0) {
		yyerror("repetition of parameter `" + *s + "'");
      } 
	  
	  else if (context.find(*s) != 0) {
		yywarning("shadowing parameter `" + *s + "'");
      }

      Variable var = TermTable::add_variable(type);
      context.insert(*s, var);
      
	  if (!quantified.empty()) {
		quantified.push_back(var);
      } 
	  
	  else { 

		if(action != 0) {
		  action->add_parameter(var);
		}

		else { /* decomposition != 0 */
		  decomposition->add_parameter(var);
		}

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
