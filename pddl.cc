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

#include "plans.h"
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

  /* Find the Variable given by the name in the context. */
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

  /* Find the name of the Variable in the context. */
  const std::string* find(const Variable& variable) const 
  {
      for (std::vector<VariableMap>::const_reverse_iterator fi = frames_.rbegin(); fi != frames_.rend(); ++fi)
      {
          for (VariableMap::const_iterator vi = (*fi).begin(); vi != (*fi).end(); ++vi)
          {
              Variable declared = vi->second;
              if (declared == variable) {
                  return &(vi->first);
              }
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

/* Action corresponding to the pseudo-step being parsed, or 0 if no pseudo-step is being parsed. */
static const ActionSchema* pseudo_step_action;

/* Decomposition schema being parsed, or 0 if no decomposition is being parsed. */
static DecompositionSchema* decomposition;

/* A map that tracks pseudo-steps for the decomposition schema currently being parsed. */
static std::map<std::string, Step*> decomposition_pseudo_steps;

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

/* Creates a decomposition for the given composite action name with the given name. */
static void make_decomposition(const std::string* composite_action_name, const std::string* name);

/* Adds the current decomposition to the current domain. */
static void add_decomposition();

/* Prepares for the parsing of a pseudo-step. */
static void prepare_pseudostep(const std::string* pseudo_step_action_name);

/* Creates the pseudo-step just parsed. */
static const Step* make_pseudostep();

/* Adds a pseudo-step to the current decomposition. */
static void add_pseudostep();

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

#line 374 "pddl.cc" /* yacc.c:339  */

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
#line 351 "pddl.yy" /* yacc.c:355  */

  const Step* step;
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

#line 499 "pddl.cc" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_PDDL_HH_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 516 "pddl.cc" /* yacc.c:358  */

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
#define YYLAST   1220

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  79
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  163
/* YYNRULES -- Number of rules.  */
#define YYNRULES  346
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  575

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
       0,   387,   387,   387,   391,   392,   393,   400,   400,   404,
     405,   406,   407,   410,   411,   412,   415,   416,   417,   418,
     419,   420,   421,   424,   425,   426,   427,   428,   431,   432,
     433,   434,   435,   438,   439,   440,   441,   442,   445,   446,
     447,   450,   451,   452,   455,   456,   457,   460,   461,   464,
     465,   468,   471,   472,   475,   476,   477,   479,   481,   482,
     484,   486,   488,   489,   490,   491,   492,   494,   496,   501,
     504,   504,   508,   508,   512,   515,   515,   522,   523,   526,
     526,   530,   531,   532,   535,   536,   539,   539,   542,   542,
     550,   550,   551,   551,   554,   555,   558,   559,   562,   563,
     566,   567,   570,   570,   573,   573,   576,   577,   580,   581,
     584,   585,   593,   592,   597,   600,   601,   604,   607,   607,
     614,   615,   619,   624,   629,   633,   634,   642,   643,   646,
     647,   650,   650,   651,   651,   652,   652,   659,   660,   661,
     661,   662,   662,   662,   665,   666,   669,   670,   673,   674,
     677,   678,   681,   682,   683,   683,   685,   685,   689,   690,
     694,   693,   697,   696,   701,   702,   703,   703,   705,   705,
     709,   710,   718,   717,   722,   723,   726,   727,   730,   731,
     734,   734,   738,   741,   742,   745,   745,   747,   747,   749,
     751,   753,   757,   758,   761,   764,   764,   766,   766,   774,
     775,   776,   777,   778,   778,   779,   779,   781,   781,   783,
     783,   787,   788,   791,   792,   795,   795,   799,   799,   803,
     804,   811,   812,   813,   814,   815,   816,   819,   820,   823,
     823,   825,   828,   829,   831,   833,   835,   837,   840,   841,
     844,   844,   846,   853,   854,   855,   858,   859,   862,   863,
     866,   867,   868,   868,   872,   873,   876,   877,   878,   878,
     881,   882,   885,   885,   888,   889,   890,   893,   894,   895,
     896,   899,   906,   909,   912,   915,   918,   921,   924,   927,
     930,   933,   936,   939,   942,   945,   948,   951,   954,   957,
     960,   963,   966,   969,   969,   969,   970,   971,   971,   971,
     971,   971,   972,   972,   972,   973,   976,   977,   977,   980,
     980,   980,   981,   982,   982,   982,   982,   983,   983,   983,
     984,   985,   985,   988,   991,   991,   991,   992,   992,   992,
     993,   993,   993,   993,   993,   993,   993,   994,   994,   994,
     994,   994,   995,   995,   995,   996,   999
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
  "steps", "step", "pseudo_step", "$@14", "duration_constraint",
  "simple_duration_constraint", "simple_duration_constraints", "da_gd",
  "timed_gds", "timed_gd", "$@15", "$@16", "$@17", "eff_formula", "$@18",
  "$@19", "$@20", "eff_formulas", "one_eff_formula", "term_literal",
  "term_literals", "da_effect", "$@21", "$@22", "da_effects",
  "timed_effect", "$@23", "$@24", "a_effect", "$@25", "$@26", "a_effects",
  "problem_def", "$@27", "problem_body", "problem_body2", "problem_body3",
  "object_decl", "$@28", "init", "init_elements", "init_element", "$@29",
  "$@30", "goal_spec", "goal", "metric_spec", "$@31", "$@32", "formula",
  "$@33", "$@34", "$@35", "$@36", "conjuncts", "disjuncts",
  "atomic_term_formula", "$@37", "atomic_name_formula", "$@38",
  "name_literal", "f_exp", "opt_f_exp", "f_head", "$@39", "ground_f_exp",
  "opt_ground_f_exp", "ground_f_head", "$@40", "terms", "names", "term",
  "variables", "$@41", "variable_seq", "typed_names", "$@42", "name_seq",
  "type_spec", "$@43", "type", "types", "function_type", "define",
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

#define YYPACT_NINF -451

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-451)))

#define YYTABLE_NINF -283

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -451,    41,  -451,  -451,    -2,    60,  -451,  -451,  -451,    14,
      97,  -451,  -451,  1162,  1162,  -451,  -451,  -451,  -451,  -451,
    -451,  -451,  -451,  -451,  -451,  -451,  -451,  -451,  -451,  -451,
    -451,  -451,  -451,  -451,  -451,  -451,  -451,    26,    40,  -451,
      50,    74,   121,   149,   102,  -451,  -451,   106,  -451,   152,
     158,   170,   172,   187,  -451,  -451,  1162,   914,  -451,  -451,
    -451,  -451,  1162,  1162,  1162,  -451,     1,  -451,   530,  -451,
      27,  -451,    35,  -451,   106,   196,   198,   478,  -451,   106,
     196,   200,   521,  -451,   106,   198,   200,   131,  -451,  -451,
    -451,  -451,  -451,  -451,  -451,  -451,  -451,  -451,  -451,  -451,
    -451,  -451,  -451,  -451,   421,  -451,  1162,  1162,    44,   207,
    -451,  -451,   143,    77,  -451,   106,   106,    45,  -451,   106,
     106,  -451,    16,  -451,   106,   106,  -451,  -451,  -451,  -451,
    -451,   182,   240,  -451,   188,   768,  -451,  -451,  1162,   234,
     -40,  -451,   281,   281,  1162,   106,   106,   106,   241,  -451,
    -451,  -451,  -451,  -451,  -451,  -451,  -451,  -451,  -451,  -451,
    -451,  -451,  -451,  -451,  -451,  -451,  -451,  -451,  -451,  -451,
    -451,  -451,  -451,  -451,  -451,   207,  -451,   258,     0,   298,
    -451,   189,   260,   261,  -451,  -451,   264,   265,  -451,   268,
     316,  1162,   271,   271,   286,  -451,   271,  -451,  -451,    78,
     269,  -451,  -451,    -6,   280,  -451,   275,   281,  -451,  -451,
     277,   132,  -451,  -451,   125,  -451,   312,  -451,   313,  -451,
    -451,   294,  -451,  -451,  -451,  -451,  -451,   288,    18,  -451,
     289,  -451,  -451,  -451,   301,   277,   299,  -451,  -451,  -451,
    -451,  -451,    -1,    54,  -451,   285,  1162,    99,   473,   302,
    -451,   130,  -451,   824,  -451,  -451,  -451,  -451,  -451,  -451,
     595,  -451,  -451,  -451,  -451,   317,   317,   317,  -451,   307,
     308,   309,  -451,   311,   318,   319,   529,  -451,  -451,  -451,
    -451,  -451,  -451,  -451,  1139,   277,  -451,  -451,  -451,  -451,
    -451,  -451,  -451,  -451,  -451,  -451,  -451,   142,  -451,  -451,
     271,  -451,  -451,   314,  -451,  -451,  -451,   965,   965,   965,
     128,    51,  -451,  -451,    59,   350,  -451,  -451,  -451,  -451,
    -451,  -451,  -451,  -451,   321,  -451,  -451,  -451,  -451,  -451,
    -451,  -451,  -451,  -451,  -451,  -451,  1083,   339,   322,  -451,
    1139,  -451,  -451,   341,   148,  -451,   277,   340,   343,  -451,
    1024,  1024,  -451,  -451,  -451,  -451,   277,   768,   344,   150,
     347,  -451,   353,   352,  -451,  -451,   355,   357,    13,  -451,
    -451,  -451,   308,  -451,  -451,   183,  -451,  -451,   183,   338,
    -451,   165,  -451,  1162,   327,  -451,   768,   376,   348,  -451,
     377,  -451,  -451,  -451,   176,   277,   271,   271,   567,  -451,
     417,   378,  -451,   379,  -451,  -451,  -451,  -451,   271,   965,
     965,   965,   965,  -451,  -451,  -451,  -451,  -451,   184,   354,
    -451,  -451,  -451,  -451,   190,  -451,  -451,  -451,  -451,  1162,
    -451,  -451,   741,  -451,   380,  -451,  -451,   710,  -451,   381,
     797,  -451,  -451,  -451,   382,   383,   402,  -451,  -451,  -451,
    1024,  1024,  1024,  1024,  -451,  -451,   404,   408,   965,   965,
     965,   965,  -451,   410,  -451,  -451,   271,   411,   411,   254,
    -451,  -451,   277,   277,   277,   412,  -451,  -451,  -451,  -451,
    -451,   339,  -451,  -451,  -451,   277,   277,  1024,  1024,  1024,
    1024,   652,   414,  -451,   299,  -451,   419,   420,   425,   426,
     625,   369,   428,   431,   595,  -451,   432,   434,   435,   436,
     438,  1162,   439,   853,   909,   440,   464,   465,  -451,   470,
     471,   474,   475,  -451,  -451,   479,  -451,  -451,  -451,  -451,
    -451,  -451,   307,   277,  -451,  -451,  -451,  -451,  -451,  -451,
    -451,  -451,  -451,  -451,  -451,  -451,  -451,  -451,  -451,  -451,
    -451,  -451,   233,  -451,   481,  -451,   243,   413,  -451,   710,
    -451,  -451,  -451,   404,  -451,  -451,   271,   683,   482,   484,
    -451,  -451,   411,   486,  -451
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
       2,     0,     4,     1,     3,     0,     5,     6,   272,     0,
       0,   273,   274,     0,     0,   324,   325,   326,   330,   331,
     332,   333,   334,   335,   336,   337,   338,   339,   340,   341,
     342,   343,   344,   327,   328,   329,   345,     0,     0,     7,
       0,     9,     0,     0,     0,    12,    15,    22,    47,    10,
      13,    16,    17,    18,    49,    50,     0,     0,    70,    72,
      77,    75,     0,     0,     0,     8,     0,    48,     0,    11,
       0,    14,     0,    19,    27,    23,    24,     0,    20,    32,
      28,    29,     0,    21,    37,    33,    34,     0,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    68,    69,     0,    52,   256,   256,     0,    81,
      90,    92,     0,     0,    25,    40,    38,     0,    26,    43,
      41,    30,     0,    31,    46,    44,    35,    36,   172,    51,
      53,     0,   257,   260,     0,     0,    74,    78,     0,     0,
      82,    84,    94,    94,     0,    39,    42,    45,     0,    71,
     262,   258,   261,    73,   293,   294,   295,   297,   298,   299,
     300,   301,   302,   303,   304,   308,   307,   296,   305,   306,
      79,    88,   323,    76,    86,    81,    85,     0,   100,     0,
     112,     0,     0,     0,   175,   177,     0,     0,   179,   192,
       0,   256,   250,   250,     0,    83,   250,   102,   104,     0,
       0,    97,    99,   100,   100,   101,     0,    94,   180,   183,
       0,     0,   174,   173,     0,   176,     0,   178,     0,   193,
     291,     0,   263,   264,   265,   259,   346,     0,   251,   254,
       0,   290,    87,   271,     0,     0,     0,   106,   107,    91,
      96,    98,     0,   110,   120,     0,   256,     0,     0,     0,
     199,     0,   292,     0,    80,   252,   255,    89,    95,   103,
       0,   105,   137,   148,   277,     0,     0,     0,   125,     0,
       0,     0,   109,     0,     0,     0,     0,   182,   184,   276,
     278,   279,   280,   281,     0,     0,   211,   203,   205,   207,
     209,   215,   194,   288,   289,   197,   195,     0,   267,   268,
     250,   275,   141,     0,   144,   139,   287,     0,     0,     0,
       0,     0,   111,   152,     0,   110,   127,    93,   115,   113,
     181,   309,   310,   311,   187,   313,   314,   315,   316,   317,
     318,   319,   322,   321,   312,   320,     0,     0,     0,   185,
       0,   248,   249,     0,     0,   213,     0,     0,     0,   243,
       0,     0,   266,   269,   270,   253,     0,     0,     0,     0,
       0,   221,     0,     0,   226,   231,     0,     0,     0,   121,
     126,   282,     0,   158,   154,     0,   283,   129,     0,     0,
     108,     0,   246,     0,     0,   242,     0,     0,     0,   246,
       0,   201,   202,   212,     0,     0,   250,   250,     0,   232,
       0,     0,   237,     0,   142,   149,   138,   145,   250,     0,
       0,     0,     0,   229,   122,   123,   124,   156,     0,     0,
     284,   285,   160,   162,     0,   131,   133,   286,   135,     0,
     114,   116,     0,   240,     0,   217,   189,     0,   219,     0,
       0,   200,   204,   214,     0,     0,     0,   216,   244,   245,
       0,     0,     0,     0,   198,   196,     0,     0,   227,     0,
       0,     0,   243,     0,   153,   159,   250,     0,     0,     0,
     128,   130,     0,     0,     0,     0,   188,   247,   246,   190,
     246,     0,   191,   186,   206,     0,     0,   238,     0,     0,
       0,     0,     0,   146,     0,   228,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   164,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   239,     0,
       0,     0,     0,   150,   143,     0,   223,   222,   224,   225,
     230,   157,     0,     0,   170,   166,   161,   163,   132,   134,
     136,   118,   117,   241,   218,   220,   208,   210,   234,   233,
     235,   236,     0,   140,     0,   168,     0,     0,   243,     0,
     147,   151,   155,     0,   165,   171,   250,     0,     0,     0,
     119,   169,     0,     0,   167
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -451,  -451,  -451,  -451,  -451,  -451,  -451,   495,   499,  -451,
    -451,  -451,   483,   476,   472,   221,    -7,   416,  -451,   455,
    -451,  -451,    96,  -451,   156,   159,  -451,  -451,  -451,  -451,
     387,  -451,  -451,  -451,   427,  -451,  -451,  -451,  -451,  -122,
    -451,   362,   365,  -451,  -451,  -451,  -451,  -451,  -451,   251,
    -451,  -451,  -451,  -451,  -451,  -451,  -451,  -451,   263,  -451,
     213,  -451,   164,  -451,  -451,  -451,  -344,  -451,  -451,  -451,
    -451,    28,  -227,  -451,  -402,  -451,  -451,  -451,   126,  -451,
    -451,  -450,  -451,  -451,  -451,  -451,  -451,  -451,   415,   406,
    -451,  -451,  -451,  -451,  -451,  -451,  -451,   403,  -451,  -451,
    -451,  -451,  -223,  -451,  -451,  -451,  -451,  -451,  -451,  -230,
    -451,  -368,  -451,  -451,  -275,  -451,  -451,  -451,  -325,  -451,
     257,  -451,  -440,  -337,   256,  -191,  -451,  -451,   -93,  -451,
    -451,   366,  -451,  -451,  -451,  -451,  -451,  -451,  -451,  -300,
    -229,  -235,  -451,  -451,  -451,  -252,  -266,  -451,   223,   224,
    -451,    57,  -451,  -451,  -451,  -215,  -451,  -173,  -128,  -451,
    -135,   -13,  -224
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,     2,     4,     6,    41,    44,    45,    46,    73,
      78,    83,   114,   118,   123,    47,    48,    49,   104,   105,
      50,   106,    51,   107,    52,    53,   109,   108,   137,   192,
     139,   140,   175,   194,   141,   193,    54,   142,   143,   178,
     200,   201,   202,   203,   235,   204,   236,   205,   271,   272,
      55,   207,   274,   381,   431,   512,   558,   243,   244,   310,
     315,   424,   316,   472,   473,   474,   261,   360,   356,   456,
     359,   492,   505,   552,   312,   419,   463,   418,   313,   467,
     468,   506,   557,   563,   556,     7,   148,   183,   184,   185,
     186,   246,   187,   247,   278,   389,   382,   188,   189,   219,
     351,   350,   249,   345,   346,   347,   348,   344,   394,   250,
     349,   387,   480,   439,   363,   496,   364,   462,   401,   519,
     402,   478,   398,   432,   340,   227,   300,   228,   131,   191,
     132,   151,   190,   222,   297,   232,     9,    13,    14,   302,
     303,   268,   287,   288,   289,   290,   375,   379,   422,   423,
     428,   307,   295,   296,   233,   223,   253,   169,   291,   339,
     365,   172,   229
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      37,    38,   230,   171,   256,   234,   263,   170,   305,   262,
     338,   372,   259,   286,   134,   407,   465,   224,   507,   285,
     438,   179,   500,   198,    59,   304,   403,    62,   197,   198,
     138,    63,   174,   366,   367,    59,    60,    61,   298,   264,
      67,     3,    62,    87,    60,    61,    63,   337,   378,   110,
     111,   112,   440,    62,    60,   265,   266,    63,   199,   374,
     342,    62,   343,     8,   199,    63,    64,    67,     5,   265,
     266,    62,    67,   358,   267,    63,   373,    67,   226,   377,
     299,    64,   353,   269,    10,   245,   270,    61,   267,   301,
     150,   264,    64,   133,   133,   283,   371,    39,   225,   264,
      64,    11,    12,    62,   371,   376,   565,    63,    67,   355,
      64,    40,    67,   515,   135,   136,   342,    67,   567,   152,
      42,   393,   573,   395,   354,   487,   488,   489,   490,   263,
     554,   180,   262,   404,   458,   459,   460,   461,    67,    67,
      67,   513,    64,   514,    43,   154,   155,   156,    80,    85,
     525,   237,   238,   275,    56,    57,    58,    59,    60,    61,
     209,   210,   518,   520,   521,   522,   208,   209,   210,   276,
     277,   443,   444,    65,   449,    62,    66,   125,   133,    63,
     293,   294,   125,   495,   497,   498,   499,   157,   158,   159,
     160,   161,   162,   163,   164,    57,   220,   167,   368,   369,
     168,   385,   128,   378,   533,   445,   446,    75,   481,    86,
      76,    81,   144,   352,    64,   385,   385,   457,   248,   392,
     260,   406,    68,   208,   209,   210,   263,   413,    70,   493,
     420,   421,   120,   133,   116,   429,   430,   263,   263,   116,
      72,   120,    77,    15,    16,    17,   248,   442,   433,   508,
     509,   510,   535,   149,   311,   464,   523,    82,   435,   153,
     469,   470,   516,   517,   263,   433,   113,   262,   117,   534,
     122,   341,    74,    79,    84,   503,   449,   138,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,   115,   119,    36,   371,
     376,   115,   124,   559,   560,   173,   119,   124,   177,   435,
     555,   181,   150,   504,   564,   385,   385,   385,   385,   154,
     155,   156,   263,   308,   309,   561,   263,   341,   196,   206,
     211,   226,   213,   263,   214,   216,   493,   145,   218,   231,
     239,   146,   263,   449,   199,   242,   147,   248,   210,   252,
     251,   273,   385,   385,   385,   385,    15,    16,    17,   254,
     257,   157,   158,   159,   160,   161,   162,   163,   164,   260,
     220,   167,   258,   292,   168,   569,   306,   311,   314,   269,
     317,   318,  -282,   388,   357,   448,   221,   427,   434,   319,
     320,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,   386,
     396,    36,   391,   397,   371,   405,   475,   408,   437,   477,
      15,    16,    17,   414,   466,   409,   415,   477,   416,   410,
     411,   412,    88,    89,    90,    91,    92,    93,    94,    95,
      96,    97,    98,    99,   100,   101,   102,   436,   441,   454,
     455,   479,   482,   484,   485,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,   486,   491,    36,   154,   155,   156,   494,
     501,   504,   511,   566,   103,   524,    59,   448,    61,   450,
     526,   527,   129,   451,   452,   453,   528,   529,   541,   531,
     477,   477,   532,   536,    62,   537,   538,   539,    63,   540,
     542,   545,   279,   264,   280,   281,   282,   283,   157,   158,
     159,   160,   161,   162,   163,   164,   165,   166,   167,    59,
      60,   168,   321,   322,   323,   546,   547,    58,    59,    60,
      61,   548,   549,    64,    69,   550,   551,    62,   284,    71,
     553,    63,   562,   571,   448,   572,    62,   574,   127,   130,
      63,   126,   195,   121,   182,   240,   380,   176,   279,   241,
      15,    16,    17,   370,   324,   325,   326,   327,   328,   329,
     330,   331,   332,   333,   334,   417,    64,   335,   471,   502,
     217,   568,   215,   384,   255,    64,   390,   212,   154,   155,
     156,   425,   426,     0,   336,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,     0,     0,    36,     0,   226,    15,    16,
      17,     0,     0,   301,   279,   264,     0,     0,   447,   283,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     167,     0,     0,   168,     0,   154,   155,   156,     0,     0,
       0,     0,     0,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,     0,     0,    36,     0,   226,    15,    16,    17,     0,
       0,   279,   264,     0,     0,     0,   530,   157,   158,   159,
     160,   161,   162,   163,   164,   165,   166,   167,     0,     0,
     168,     0,     0,   154,   155,   156,     0,     0,     0,     0,
       0,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,     0,
       0,    36,     0,   226,    15,    16,    17,     0,     0,   279,
       0,     0,     0,     0,   570,   157,   158,   159,   160,   161,
     162,   163,   164,   165,   166,   167,     0,     0,   168,     0,
       0,   154,   155,   156,     0,     0,     0,     0,     0,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,     0,     0,    36,
      15,    16,    17,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   476,   157,   158,   159,   160,   161,   162,   163,
     164,   165,   166,   167,     0,     0,   168,   154,   155,   156,
       0,     0,     0,     0,     0,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,     0,     0,    36,    15,    16,    17,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   483,   157,
     158,   159,   160,   161,   162,   163,   164,     0,   220,   167,
       0,     0,   168,     0,     0,     0,     0,     0,     0,     0,
       0,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,     0,
       0,    36,    15,    16,    17,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   543,    88,    89,    90,    91,    92,
      93,    94,    95,    96,    97,    98,    99,   100,   101,   102,
       0,     0,     0,     0,     0,     0,     0,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,     0,     0,    36,    15,    16,
      17,     0,     0,     0,     0,     0,     0,   103,     0,     0,
     544,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,     0,     0,    36,     0,     0,   361,    15,    16,    17,
       0,     0,     0,     0,     0,   362,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
       0,     0,    36,     0,     0,   399,    15,    16,    17,     0,
       0,     0,     0,     0,   400,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,     0,
       0,    36,    15,    16,    17,     0,     0,     0,     0,     0,
       0,     0,     0,   383,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    15,    16,    17,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,     0,     0,    36,     0,   226,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,     0,     0,
      36
};

static const yytype_int16 yycheck[] =
{
      13,    14,   193,   138,   228,   196,   236,   135,   260,   236,
     276,   311,   235,   248,   107,   359,   418,   190,   468,   248,
     388,   143,   462,    29,     8,   260,   351,    26,    28,    29,
      70,    30,    72,   308,   309,     8,     9,    10,   253,    40,
      47,     0,    26,    56,     9,    10,    30,   276,   314,    62,
      63,    64,   389,    26,     9,    56,    57,    30,    64,   311,
     284,    26,   285,     3,    64,    30,    65,    74,    70,    56,
      57,    26,    79,   303,    75,    30,   311,    84,    60,   314,
     253,    65,   297,    29,    70,   207,    32,    10,    75,    38,
      72,    40,    65,   106,   107,    44,    45,    71,   191,    40,
      65,     4,     5,    26,    45,    46,   556,    30,   115,   300,
      65,    71,   119,   481,    70,    71,   340,   124,   558,   132,
      70,   344,   572,   346,   297,   450,   451,   452,   453,   359,
     532,   144,   359,   356,   409,   410,   411,   412,   145,   146,
     147,   478,    65,   480,    70,     3,     4,     5,    52,    53,
     494,    73,    74,   246,    33,     6,     7,     8,     9,    10,
      35,    36,   487,   488,   489,   490,    34,    35,    36,    70,
      71,   394,   395,    71,   398,    26,    70,    81,   191,    30,
      50,    51,    86,   458,   459,   460,   461,    45,    46,    47,
      48,    49,    50,    51,    52,     6,    54,    55,    70,    71,
      58,   336,    71,   469,   504,   396,   397,    51,   437,    53,
      51,    52,    69,    71,    65,   350,   351,   408,    70,    71,
      70,    71,    70,    34,    35,    36,   456,   362,    70,   456,
      47,    48,    76,   246,    75,    70,    71,   467,   468,    80,
      70,    85,    70,     3,     4,     5,    70,    71,   383,   472,
     473,   474,   504,    71,    70,    71,   491,    70,   386,    71,
      70,    71,   485,   486,   494,   400,    70,   494,    70,   504,
      70,   284,    51,    52,    53,   466,   500,    70,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    75,    76,    58,    45,
      46,    80,    81,    70,    71,    71,    85,    86,    27,   437,
     533,    70,    72,    70,    71,   450,   451,   452,   453,     3,
       4,     5,   552,   266,   267,   552,   556,   340,    70,    31,
      70,    60,    71,   563,    70,    70,   563,   116,    70,    53,
      71,   120,   572,   567,    64,    70,   125,    70,    36,    55,
      37,    66,   487,   488,   489,   490,     3,     4,     5,    71,
      71,    45,    46,    47,    48,    49,    50,    51,    52,    70,
      54,    55,    71,    71,    58,   566,    59,    70,    70,    29,
      71,    70,    61,    61,    70,   398,    70,    49,    61,    71,
      71,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    70,
      70,    58,    71,    70,    45,    71,   429,    70,    70,   432,
       3,     4,     5,    71,    70,    72,    71,   440,    71,    76,
      77,    78,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    71,    71,    71,
      71,    71,    71,    71,    71,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    71,    70,    58,     3,     4,     5,    71,
      70,    70,    70,    70,    63,    71,     8,   500,    10,    72,
      71,    71,    71,    76,    77,    78,    71,    71,   511,    71,
     513,   514,    71,    71,    26,    71,    71,    71,    30,    71,
      71,    71,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,     8,
       9,    58,     3,     4,     5,    71,    71,     7,     8,     9,
      10,    71,    71,    65,    49,    71,    71,    26,    75,    50,
      71,    30,    71,    71,   567,    71,    26,    71,    86,   104,
      30,    85,   175,    80,   148,   203,   315,   140,    39,   204,
       3,     4,     5,   310,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,   372,    65,    58,   424,   463,
     187,   563,   186,   336,   228,    65,   340,   182,     3,     4,
       5,   378,   378,    -1,    75,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    -1,    -1,    58,    -1,    60,     3,     4,
       5,    -1,    -1,    38,    39,    40,    -1,    -1,    71,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    -1,    -1,    58,    -1,     3,     4,     5,    -1,    -1,
      -1,    -1,    -1,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    -1,    -1,    58,    -1,    60,     3,     4,     5,    -1,
      -1,    39,    40,    -1,    -1,    -1,    71,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    -1,    -1,
      58,    -1,    -1,     3,     4,     5,    -1,    -1,    -1,    -1,
      -1,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    -1,
      -1,    58,    -1,    60,     3,     4,     5,    -1,    -1,    39,
      -1,    -1,    -1,    -1,    71,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    -1,    -1,    58,    -1,
      -1,     3,     4,     5,    -1,    -1,    -1,    -1,    -1,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    -1,    -1,    58,
       3,     4,     5,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    71,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    -1,    -1,    58,     3,     4,     5,
      -1,    -1,    -1,    -1,    -1,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    -1,    -1,    58,     3,     4,     5,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    71,    45,
      46,    47,    48,    49,    50,    51,    52,    -1,    54,    55,
      -1,    -1,    58,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    -1,
      -1,    58,     3,     4,     5,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    71,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    -1,    -1,    58,     3,     4,
       5,    -1,    -1,    -1,    -1,    -1,    -1,    63,    -1,    -1,
      71,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    -1,    -1,    58,    -1,    -1,    61,     3,     4,     5,
      -1,    -1,    -1,    -1,    -1,    70,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      -1,    -1,    58,    -1,    -1,    61,     3,     4,     5,    -1,
      -1,    -1,    -1,    -1,    70,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    -1,
      -1,    58,     3,     4,     5,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    70,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,     3,     4,     5,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    -1,    -1,    58,    -1,    60,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    -1,    -1,
      58
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    80,    81,     0,    82,    70,    83,   164,     3,   215,
      70,     4,     5,   216,   217,     3,     4,     5,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    58,   240,   240,    71,
      71,    84,    70,    70,    85,    86,    87,    94,    95,    96,
      99,   101,   103,   104,   115,   129,    33,     6,     7,     8,
       9,    10,    26,    30,    65,    71,    70,    95,    70,    86,
      70,    87,    70,    88,    94,   103,   104,    70,    89,    94,
     101,   104,    70,    90,    94,   101,   103,   240,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    63,    97,    98,   100,   102,   106,   105,
     240,   240,   240,    70,    91,    94,   104,    70,    92,    94,
     103,    91,    70,    93,    94,   101,    92,    93,    71,    71,
      98,   207,   209,   240,   207,    70,    71,   107,    70,   109,
     110,   113,   116,   117,    69,    94,    94,    94,   165,    71,
      72,   210,   240,    71,     3,     4,     5,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    58,   236,
     237,   239,   240,    71,    72,   111,   113,    27,   118,   118,
     240,    70,    96,   166,   167,   168,   169,   171,   176,   177,
     211,   208,   108,   114,   112,   109,    70,    28,    29,    64,
     119,   120,   121,   122,   124,   126,    31,   130,    34,    35,
      36,    70,   167,    71,    70,   168,    70,   176,    70,   178,
      54,    70,   212,   234,   236,   207,    60,   204,   206,   241,
     204,    53,   214,   233,   204,   123,   125,    73,    74,    71,
     120,   121,    70,   136,   137,   118,   170,   172,    70,   181,
     188,    37,    55,   235,    71,   210,   241,    71,    71,   181,
      70,   145,   151,   188,    40,    56,    57,    75,   220,    29,
      32,   127,   128,    66,   131,   207,    70,    71,   173,    39,
      41,    42,    43,    44,    75,   219,   220,   221,   222,   223,
     224,   237,    71,    50,    51,   231,   232,   213,   234,   236,
     205,    38,   218,   219,   220,   224,    59,   230,   230,   230,
     138,    70,   153,   157,    70,   139,   141,    71,    70,    71,
      71,     3,     4,     5,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    58,    75,   219,   225,   238,
     203,   240,   241,   181,   186,   182,   183,   184,   185,   189,
     180,   179,    71,   234,   236,   204,   147,    70,   188,   149,
     146,    61,    70,   193,   195,   239,   193,   193,    70,    71,
     137,    45,   218,   220,   224,   225,    46,   220,   225,   226,
     128,   132,   175,    70,   199,   239,    70,   190,    61,   174,
     203,    71,    71,   181,   187,   181,    70,    70,   201,    61,
      70,   197,   199,   197,   181,    71,    71,   145,    70,    72,
      76,    77,    78,   239,    71,    71,    71,   139,   156,   154,
      47,    48,   227,   228,   140,   227,   228,    49,   229,    70,
      71,   133,   202,   239,    61,   237,    71,    70,   190,   192,
     202,    71,    71,   181,   181,   204,   204,    71,   240,   241,
      72,    76,    77,    78,    71,    71,   148,   204,   193,   193,
     193,   193,   196,   155,    71,   153,    70,   158,   159,    70,
      71,   141,   142,   143,   144,   240,    71,   240,   200,    71,
     191,   219,    71,    71,    71,    71,    71,   197,   197,   197,
     197,    70,   150,   151,    71,   193,   194,   193,   193,   193,
     201,    70,   157,   204,    70,   151,   160,   160,   181,   181,
     181,    70,   134,   202,   202,   190,   181,   181,   197,   198,
     197,   197,   197,   220,    71,   145,    71,    71,    71,    71,
      71,    71,    71,   218,   220,   224,    71,    71,    71,    71,
      71,   240,    71,    71,    71,    71,    71,    71,    71,    71,
      71,    71,   152,    71,   153,   181,   163,   161,   135,    70,
      71,   151,    71,   162,    71,   160,    70,   201,   150,   204,
      71,    71,    71,   160,    71
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
     128,   128,   130,   129,   131,   132,   132,   133,   135,   134,
     136,   136,   137,   137,   137,   138,   138,   139,   139,   140,
     140,   142,   141,   143,   141,   144,   141,   145,   145,   146,
     145,   147,   148,   145,   149,   149,   150,   150,   151,   151,
     152,   152,   153,   153,   154,   153,   155,   153,   156,   156,
     158,   157,   159,   157,   160,   160,   161,   160,   162,   160,
     163,   163,   165,   164,   166,   166,   167,   167,   168,   168,
     170,   169,   171,   172,   172,   174,   173,   175,   173,   173,
     173,   173,   176,   176,   177,   179,   178,   180,   178,   181,
     181,   181,   181,   182,   181,   183,   181,   184,   181,   185,
     181,   186,   186,   187,   187,   189,   188,   191,   190,   192,
     192,   193,   193,   193,   193,   193,   193,   194,   194,   196,
     195,   195,   197,   197,   197,   197,   197,   197,   198,   198,
     200,   199,   199,   201,   201,   201,   202,   202,   203,   203,
     204,   204,   205,   204,   206,   206,   207,   207,   208,   207,
     209,   209,   211,   210,   212,   212,   212,   213,   213,   213,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   236,   236,   236,   236,   236,   236,
     236,   236,   236,   236,   236,   236,   237,   237,   237,   238,
     238,   238,   238,   238,   238,   238,   238,   238,   238,   238,
     238,   238,   238,   239,   240,   240,   240,   240,   240,   240,
     240,   240,   240,   240,   240,   240,   240,   240,   240,   240,
     240,   240,   240,   240,   240,   240,   241
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
       0,     2,     0,     9,     4,     0,     2,     4,     0,     5,
       1,     4,     5,     5,     5,     0,     2,     1,     4,     0,
       2,     0,     6,     0,     6,     0,     6,     1,     4,     0,
       8,     0,     0,     7,     0,     2,     1,     4,     1,     4,
       0,     2,     1,     4,     0,     8,     0,     6,     0,     2,
       0,     6,     0,     6,     1,     4,     0,     8,     0,     6,
       0,     2,     0,    13,     2,     1,     2,     1,     2,     1,
       0,     5,     4,     0,     2,     0,     5,     0,     5,     4,
       5,     5,     1,     2,     4,     0,     6,     0,     6,     1,
       5,     4,     4,     0,     5,     0,     6,     0,     8,     0,
       8,     0,     2,     0,     2,     0,     5,     0,     5,     1,
       4,     1,     5,     5,     5,     5,     1,     0,     1,     0,
       5,     1,     1,     5,     5,     5,     5,     1,     0,     1,
       0,     5,     1,     0,     2,     2,     0,     2,     1,     1,
       0,     1,     0,     4,     1,     2,     0,     1,     0,     4,
       1,     2,     0,     3,     1,     1,     4,     1,     1,     2,
       2,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1
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
#line 387 "pddl.yy" /* yacc.c:1646  */
    { success = true; line_number = 1; }
#line 2187 "pddl.cc" /* yacc.c:1646  */
    break;

  case 3:
#line 388 "pddl.yy" /* yacc.c:1646  */
    { if (!success) YYERROR; }
#line 2193 "pddl.cc" /* yacc.c:1646  */
    break;

  case 7:
#line 400 "pddl.yy" /* yacc.c:1646  */
    { make_domain((yyvsp[-1].str)); }
#line 2199 "pddl.cc" /* yacc.c:1646  */
    break;

  case 54:
#line 475 "pddl.yy" /* yacc.c:1646  */
    { requirements->strips = true; }
#line 2205 "pddl.cc" /* yacc.c:1646  */
    break;

  case 55:
#line 476 "pddl.yy" /* yacc.c:1646  */
    { requirements->typing = true; }
#line 2211 "pddl.cc" /* yacc.c:1646  */
    break;

  case 56:
#line 478 "pddl.yy" /* yacc.c:1646  */
    { requirements->negative_preconditions = true; }
#line 2217 "pddl.cc" /* yacc.c:1646  */
    break;

  case 57:
#line 480 "pddl.yy" /* yacc.c:1646  */
    { requirements->disjunctive_preconditions = true; }
#line 2223 "pddl.cc" /* yacc.c:1646  */
    break;

  case 58:
#line 481 "pddl.yy" /* yacc.c:1646  */
    { requirements->equality = true; }
#line 2229 "pddl.cc" /* yacc.c:1646  */
    break;

  case 59:
#line 483 "pddl.yy" /* yacc.c:1646  */
    { requirements->existential_preconditions = true; }
#line 2235 "pddl.cc" /* yacc.c:1646  */
    break;

  case 60:
#line 485 "pddl.yy" /* yacc.c:1646  */
    { requirements->universal_preconditions = true; }
#line 2241 "pddl.cc" /* yacc.c:1646  */
    break;

  case 61:
#line 487 "pddl.yy" /* yacc.c:1646  */
    { requirements->quantified_preconditions(); }
#line 2247 "pddl.cc" /* yacc.c:1646  */
    break;

  case 62:
#line 488 "pddl.yy" /* yacc.c:1646  */
    { requirements->conditional_effects = true; }
#line 2253 "pddl.cc" /* yacc.c:1646  */
    break;

  case 63:
#line 489 "pddl.yy" /* yacc.c:1646  */
    { requirements->fluents = true; }
#line 2259 "pddl.cc" /* yacc.c:1646  */
    break;

  case 64:
#line 490 "pddl.yy" /* yacc.c:1646  */
    { requirements->adl(); }
#line 2265 "pddl.cc" /* yacc.c:1646  */
    break;

  case 65:
#line 491 "pddl.yy" /* yacc.c:1646  */
    { requirements->durative_actions = true; }
#line 2271 "pddl.cc" /* yacc.c:1646  */
    break;

  case 66:
#line 493 "pddl.yy" /* yacc.c:1646  */
    { requirements->duration_inequalities = true; }
#line 2277 "pddl.cc" /* yacc.c:1646  */
    break;

  case 67:
#line 495 "pddl.yy" /* yacc.c:1646  */
    { yyerror("`:continuous-effects' not supported"); }
#line 2283 "pddl.cc" /* yacc.c:1646  */
    break;

  case 68:
#line 497 "pddl.yy" /* yacc.c:1646  */
    {
					requirements->durative_actions = true;
					requirements->timed_initial_literals = true;
				}
#line 2292 "pddl.cc" /* yacc.c:1646  */
    break;

  case 69:
#line 501 "pddl.yy" /* yacc.c:1646  */
    { requirements->decompositions = true; }
#line 2298 "pddl.cc" /* yacc.c:1646  */
    break;

  case 70:
#line 504 "pddl.yy" /* yacc.c:1646  */
    { require_typing(); name_kind = TYPE_KIND; }
#line 2304 "pddl.cc" /* yacc.c:1646  */
    break;

  case 71:
#line 505 "pddl.yy" /* yacc.c:1646  */
    { name_kind = VOID_KIND; }
#line 2310 "pddl.cc" /* yacc.c:1646  */
    break;

  case 72:
#line 508 "pddl.yy" /* yacc.c:1646  */
    { name_kind = CONSTANT_KIND; }
#line 2316 "pddl.cc" /* yacc.c:1646  */
    break;

  case 73:
#line 509 "pddl.yy" /* yacc.c:1646  */
    { name_kind = VOID_KIND; }
#line 2322 "pddl.cc" /* yacc.c:1646  */
    break;

  case 75:
#line 515 "pddl.yy" /* yacc.c:1646  */
    { require_fluents(); }
#line 2328 "pddl.cc" /* yacc.c:1646  */
    break;

  case 79:
#line 526 "pddl.yy" /* yacc.c:1646  */
    { make_predicate((yyvsp[0].str)); }
#line 2334 "pddl.cc" /* yacc.c:1646  */
    break;

  case 80:
#line 527 "pddl.yy" /* yacc.c:1646  */
    { predicate = 0; }
#line 2340 "pddl.cc" /* yacc.c:1646  */
    break;

  case 86:
#line 539 "pddl.yy" /* yacc.c:1646  */
    { require_typing(); }
#line 2346 "pddl.cc" /* yacc.c:1646  */
    break;

  case 88:
#line 542 "pddl.yy" /* yacc.c:1646  */
    { make_function((yyvsp[0].str)); }
#line 2352 "pddl.cc" /* yacc.c:1646  */
    break;

  case 89:
#line 543 "pddl.yy" /* yacc.c:1646  */
    { function = 0; }
#line 2358 "pddl.cc" /* yacc.c:1646  */
    break;

  case 90:
#line 550 "pddl.yy" /* yacc.c:1646  */
    { make_action((yyvsp[0].str), false, false); }
#line 2364 "pddl.cc" /* yacc.c:1646  */
    break;

  case 91:
#line 550 "pddl.yy" /* yacc.c:1646  */
    { add_action(); }
#line 2370 "pddl.cc" /* yacc.c:1646  */
    break;

  case 92:
#line 551 "pddl.yy" /* yacc.c:1646  */
    { make_action((yyvsp[0].str), true, false); }
#line 2376 "pddl.cc" /* yacc.c:1646  */
    break;

  case 93:
#line 551 "pddl.yy" /* yacc.c:1646  */
    { add_action(); }
#line 2382 "pddl.cc" /* yacc.c:1646  */
    break;

  case 102:
#line 570 "pddl.yy" /* yacc.c:1646  */
    { formula_time = AT_START; }
#line 2388 "pddl.cc" /* yacc.c:1646  */
    break;

  case 103:
#line 570 "pddl.yy" /* yacc.c:1646  */
    { action->set_condition(*(yyvsp[0].formula)); }
#line 2394 "pddl.cc" /* yacc.c:1646  */
    break;

  case 104:
#line 573 "pddl.yy" /* yacc.c:1646  */
    { effect_time = Effect::AT_END; }
#line 2400 "pddl.cc" /* yacc.c:1646  */
    break;

  case 106:
#line 576 "pddl.yy" /* yacc.c:1646  */
    { require_decompositions(); action->set_composite(true); }
#line 2406 "pddl.cc" /* yacc.c:1646  */
    break;

  case 107:
#line 577 "pddl.yy" /* yacc.c:1646  */
    { require_decompositions(); action->set_composite(false); }
#line 2412 "pddl.cc" /* yacc.c:1646  */
    break;

  case 108:
#line 580 "pddl.yy" /* yacc.c:1646  */
    { action->set_condition(*(yyvsp[-1].formula)); }
#line 2418 "pddl.cc" /* yacc.c:1646  */
    break;

  case 112:
#line 593 "pddl.yy" /* yacc.c:1646  */
    { make_decomposition((yyvsp[-2].str), (yyvsp[0].str)); }
#line 2424 "pddl.cc" /* yacc.c:1646  */
    break;

  case 113:
#line 594 "pddl.yy" /* yacc.c:1646  */
    { add_decomposition(); }
#line 2430 "pddl.cc" /* yacc.c:1646  */
    break;

  case 118:
#line 607 "pddl.yy" /* yacc.c:1646  */
    { prepare_pseudostep((yyvsp[0].str)); }
#line 2436 "pddl.cc" /* yacc.c:1646  */
    break;

  case 119:
#line 608 "pddl.yy" /* yacc.c:1646  */
    { (yyval.step) = make_pseudostep(); }
#line 2442 "pddl.cc" /* yacc.c:1646  */
    break;

  case 121:
#line 616 "pddl.yy" /* yacc.c:1646  */
    { require_duration_inequalities(); }
#line 2448 "pddl.cc" /* yacc.c:1646  */
    break;

  case 122:
#line 620 "pddl.yy" /* yacc.c:1646  */
    {
				 require_duration_inequalities();
				 action->set_max_duration(*(yyvsp[-1].expr));
			       }
#line 2457 "pddl.cc" /* yacc.c:1646  */
    break;

  case 123:
#line 625 "pddl.yy" /* yacc.c:1646  */
    {
				 require_duration_inequalities();
				 action->set_min_duration(*(yyvsp[-1].expr));
			       }
#line 2466 "pddl.cc" /* yacc.c:1646  */
    break;

  case 124:
#line 630 "pddl.yy" /* yacc.c:1646  */
    { action->set_duration(*(yyvsp[-1].expr)); }
#line 2472 "pddl.cc" /* yacc.c:1646  */
    break;

  case 128:
#line 643 "pddl.yy" /* yacc.c:1646  */
    { (yyval.formula) = (yyvsp[-1].formula); }
#line 2478 "pddl.cc" /* yacc.c:1646  */
    break;

  case 129:
#line 646 "pddl.yy" /* yacc.c:1646  */
    { (yyval.formula) = &Formula::TRUE; }
#line 2484 "pddl.cc" /* yacc.c:1646  */
    break;

  case 130:
#line 647 "pddl.yy" /* yacc.c:1646  */
    { (yyval.formula) = &(*(yyvsp[-1].formula) && *(yyvsp[0].formula)); }
#line 2490 "pddl.cc" /* yacc.c:1646  */
    break;

  case 131:
#line 650 "pddl.yy" /* yacc.c:1646  */
    { formula_time = AT_START; }
#line 2496 "pddl.cc" /* yacc.c:1646  */
    break;

  case 132:
#line 650 "pddl.yy" /* yacc.c:1646  */
    { (yyval.formula) = (yyvsp[-1].formula); }
#line 2502 "pddl.cc" /* yacc.c:1646  */
    break;

  case 133:
#line 651 "pddl.yy" /* yacc.c:1646  */
    { formula_time = AT_END; }
#line 2508 "pddl.cc" /* yacc.c:1646  */
    break;

  case 134:
#line 651 "pddl.yy" /* yacc.c:1646  */
    { (yyval.formula) = (yyvsp[-1].formula); }
#line 2514 "pddl.cc" /* yacc.c:1646  */
    break;

  case 135:
#line 652 "pddl.yy" /* yacc.c:1646  */
    { formula_time = OVER_ALL; }
#line 2520 "pddl.cc" /* yacc.c:1646  */
    break;

  case 136:
#line 652 "pddl.yy" /* yacc.c:1646  */
    { (yyval.formula) = (yyvsp[-1].formula); }
#line 2526 "pddl.cc" /* yacc.c:1646  */
    break;

  case 139:
#line 661 "pddl.yy" /* yacc.c:1646  */
    { prepare_forall_effect(); }
#line 2532 "pddl.cc" /* yacc.c:1646  */
    break;

  case 140:
#line 661 "pddl.yy" /* yacc.c:1646  */
    { pop_forall_effect(); }
#line 2538 "pddl.cc" /* yacc.c:1646  */
    break;

  case 141:
#line 662 "pddl.yy" /* yacc.c:1646  */
    { formula_time = AT_START; }
#line 2544 "pddl.cc" /* yacc.c:1646  */
    break;

  case 142:
#line 662 "pddl.yy" /* yacc.c:1646  */
    { prepare_conditional_effect(*(yyvsp[0].formula)); }
#line 2550 "pddl.cc" /* yacc.c:1646  */
    break;

  case 143:
#line 662 "pddl.yy" /* yacc.c:1646  */
    { effect_condition = 0; }
#line 2556 "pddl.cc" /* yacc.c:1646  */
    break;

  case 148:
#line 673 "pddl.yy" /* yacc.c:1646  */
    { add_effect(*(yyvsp[0].atom)); }
#line 2562 "pddl.cc" /* yacc.c:1646  */
    break;

  case 149:
#line 674 "pddl.yy" /* yacc.c:1646  */
    { add_effect(Negation::make(*(yyvsp[-1].atom))); }
#line 2568 "pddl.cc" /* yacc.c:1646  */
    break;

  case 154:
#line 683 "pddl.yy" /* yacc.c:1646  */
    { prepare_forall_effect(); }
#line 2574 "pddl.cc" /* yacc.c:1646  */
    break;

  case 155:
#line 684 "pddl.yy" /* yacc.c:1646  */
    { pop_forall_effect(); }
#line 2580 "pddl.cc" /* yacc.c:1646  */
    break;

  case 156:
#line 685 "pddl.yy" /* yacc.c:1646  */
    { prepare_conditional_effect(*(yyvsp[0].formula)); }
#line 2586 "pddl.cc" /* yacc.c:1646  */
    break;

  case 157:
#line 686 "pddl.yy" /* yacc.c:1646  */
    { effect_condition = 0; }
#line 2592 "pddl.cc" /* yacc.c:1646  */
    break;

  case 160:
#line 694 "pddl.yy" /* yacc.c:1646  */
    { effect_time = Effect::AT_START; formula_time = AT_START; }
#line 2598 "pddl.cc" /* yacc.c:1646  */
    break;

  case 162:
#line 697 "pddl.yy" /* yacc.c:1646  */
    { effect_time = Effect::AT_END; formula_time = AT_END; }
#line 2604 "pddl.cc" /* yacc.c:1646  */
    break;

  case 166:
#line 703 "pddl.yy" /* yacc.c:1646  */
    { prepare_forall_effect(); }
#line 2610 "pddl.cc" /* yacc.c:1646  */
    break;

  case 167:
#line 704 "pddl.yy" /* yacc.c:1646  */
    { pop_forall_effect(); }
#line 2616 "pddl.cc" /* yacc.c:1646  */
    break;

  case 168:
#line 705 "pddl.yy" /* yacc.c:1646  */
    { prepare_conditional_effect(*(yyvsp[0].formula)); }
#line 2622 "pddl.cc" /* yacc.c:1646  */
    break;

  case 169:
#line 706 "pddl.yy" /* yacc.c:1646  */
    { effect_condition = 0; }
#line 2628 "pddl.cc" /* yacc.c:1646  */
    break;

  case 172:
#line 718 "pddl.yy" /* yacc.c:1646  */
    { make_problem((yyvsp[-5].str), (yyvsp[-1].str)); }
#line 2634 "pddl.cc" /* yacc.c:1646  */
    break;

  case 173:
#line 719 "pddl.yy" /* yacc.c:1646  */
    { delete requirements; }
#line 2640 "pddl.cc" /* yacc.c:1646  */
    break;

  case 180:
#line 734 "pddl.yy" /* yacc.c:1646  */
    { name_kind = OBJECT_KIND; }
#line 2646 "pddl.cc" /* yacc.c:1646  */
    break;

  case 181:
#line 735 "pddl.yy" /* yacc.c:1646  */
    { name_kind = VOID_KIND; }
#line 2652 "pddl.cc" /* yacc.c:1646  */
    break;

  case 185:
#line 745 "pddl.yy" /* yacc.c:1646  */
    { prepare_atom((yyvsp[0].str)); }
#line 2658 "pddl.cc" /* yacc.c:1646  */
    break;

  case 186:
#line 746 "pddl.yy" /* yacc.c:1646  */
    { problem->add_init_atom(*make_atom()); }
#line 2664 "pddl.cc" /* yacc.c:1646  */
    break;

  case 187:
#line 747 "pddl.yy" /* yacc.c:1646  */
    { prepare_atom((yyvsp[0].str)); }
#line 2670 "pddl.cc" /* yacc.c:1646  */
    break;

  case 188:
#line 748 "pddl.yy" /* yacc.c:1646  */
    { problem->add_init_atom(*make_atom()); }
#line 2676 "pddl.cc" /* yacc.c:1646  */
    break;

  case 189:
#line 750 "pddl.yy" /* yacc.c:1646  */
    { Formula::register_use((yyvsp[-1].atom)); Formula::unregister_use((yyvsp[-1].atom)); }
#line 2682 "pddl.cc" /* yacc.c:1646  */
    break;

  case 190:
#line 752 "pddl.yy" /* yacc.c:1646  */
    { problem->add_init_value(*(yyvsp[-2].fluent), (yyvsp[-1].num)); }
#line 2688 "pddl.cc" /* yacc.c:1646  */
    break;

  case 191:
#line 754 "pddl.yy" /* yacc.c:1646  */
    { add_init_literal((yyvsp[-2].num), *(yyvsp[-1].literal)); }
#line 2694 "pddl.cc" /* yacc.c:1646  */
    break;

  case 194:
#line 761 "pddl.yy" /* yacc.c:1646  */
    { problem->set_goal(*(yyvsp[-1].formula)); }
#line 2700 "pddl.cc" /* yacc.c:1646  */
    break;

  case 195:
#line 764 "pddl.yy" /* yacc.c:1646  */
    { metric_fluent = true; }
#line 2706 "pddl.cc" /* yacc.c:1646  */
    break;

  case 196:
#line 765 "pddl.yy" /* yacc.c:1646  */
    { problem->set_metric(*(yyvsp[-1].expr), true); metric_fluent = false; }
#line 2712 "pddl.cc" /* yacc.c:1646  */
    break;

  case 197:
#line 766 "pddl.yy" /* yacc.c:1646  */
    { metric_fluent = true; }
#line 2718 "pddl.cc" /* yacc.c:1646  */
    break;

  case 198:
#line 767 "pddl.yy" /* yacc.c:1646  */
    { problem->set_metric(*(yyvsp[-1].expr)); metric_fluent = false; }
#line 2724 "pddl.cc" /* yacc.c:1646  */
    break;

  case 199:
#line 774 "pddl.yy" /* yacc.c:1646  */
    { (yyval.formula) = &TimedLiteral::make(*(yyvsp[0].atom), formula_time); }
#line 2730 "pddl.cc" /* yacc.c:1646  */
    break;

  case 200:
#line 775 "pddl.yy" /* yacc.c:1646  */
    { (yyval.formula) = make_equality((yyvsp[-2].term), (yyvsp[-1].term)); }
#line 2736 "pddl.cc" /* yacc.c:1646  */
    break;

  case 201:
#line 776 "pddl.yy" /* yacc.c:1646  */
    { (yyval.formula) = make_negation(*(yyvsp[-1].formula)); }
#line 2742 "pddl.cc" /* yacc.c:1646  */
    break;

  case 202:
#line 777 "pddl.yy" /* yacc.c:1646  */
    { (yyval.formula) = (yyvsp[-1].formula); }
#line 2748 "pddl.cc" /* yacc.c:1646  */
    break;

  case 203:
#line 778 "pddl.yy" /* yacc.c:1646  */
    { require_disjunction(); }
#line 2754 "pddl.cc" /* yacc.c:1646  */
    break;

  case 204:
#line 778 "pddl.yy" /* yacc.c:1646  */
    { (yyval.formula) = (yyvsp[-1].formula); }
#line 2760 "pddl.cc" /* yacc.c:1646  */
    break;

  case 205:
#line 779 "pddl.yy" /* yacc.c:1646  */
    { require_disjunction(); }
#line 2766 "pddl.cc" /* yacc.c:1646  */
    break;

  case 206:
#line 780 "pddl.yy" /* yacc.c:1646  */
    { (yyval.formula) = &(!*(yyvsp[-2].formula) || *(yyvsp[-1].formula)); }
#line 2772 "pddl.cc" /* yacc.c:1646  */
    break;

  case 207:
#line 781 "pddl.yy" /* yacc.c:1646  */
    { prepare_exists(); }
#line 2778 "pddl.cc" /* yacc.c:1646  */
    break;

  case 208:
#line 782 "pddl.yy" /* yacc.c:1646  */
    { (yyval.formula) = make_exists(*(yyvsp[-1].formula)); }
#line 2784 "pddl.cc" /* yacc.c:1646  */
    break;

  case 209:
#line 783 "pddl.yy" /* yacc.c:1646  */
    { prepare_forall(); }
#line 2790 "pddl.cc" /* yacc.c:1646  */
    break;

  case 210:
#line 784 "pddl.yy" /* yacc.c:1646  */
    { (yyval.formula) = make_forall(*(yyvsp[-1].formula)); }
#line 2796 "pddl.cc" /* yacc.c:1646  */
    break;

  case 211:
#line 787 "pddl.yy" /* yacc.c:1646  */
    { (yyval.formula) = &Formula::TRUE; }
#line 2802 "pddl.cc" /* yacc.c:1646  */
    break;

  case 212:
#line 788 "pddl.yy" /* yacc.c:1646  */
    { (yyval.formula) = &(*(yyvsp[-1].formula) && *(yyvsp[0].formula)); }
#line 2808 "pddl.cc" /* yacc.c:1646  */
    break;

  case 213:
#line 791 "pddl.yy" /* yacc.c:1646  */
    { (yyval.formula) = &Formula::FALSE; }
#line 2814 "pddl.cc" /* yacc.c:1646  */
    break;

  case 214:
#line 792 "pddl.yy" /* yacc.c:1646  */
    { (yyval.formula) = &(*(yyvsp[-1].formula) || *(yyvsp[0].formula)); }
#line 2820 "pddl.cc" /* yacc.c:1646  */
    break;

  case 215:
#line 795 "pddl.yy" /* yacc.c:1646  */
    { prepare_atom((yyvsp[0].str)); }
#line 2826 "pddl.cc" /* yacc.c:1646  */
    break;

  case 216:
#line 796 "pddl.yy" /* yacc.c:1646  */
    { (yyval.atom) = make_atom(); }
#line 2832 "pddl.cc" /* yacc.c:1646  */
    break;

  case 217:
#line 799 "pddl.yy" /* yacc.c:1646  */
    { prepare_atom((yyvsp[0].str)); }
#line 2838 "pddl.cc" /* yacc.c:1646  */
    break;

  case 218:
#line 800 "pddl.yy" /* yacc.c:1646  */
    { (yyval.atom) = make_atom(); }
#line 2844 "pddl.cc" /* yacc.c:1646  */
    break;

  case 219:
#line 803 "pddl.yy" /* yacc.c:1646  */
    { (yyval.literal) = (yyvsp[0].atom); }
#line 2850 "pddl.cc" /* yacc.c:1646  */
    break;

  case 220:
#line 804 "pddl.yy" /* yacc.c:1646  */
    { (yyval.literal) = &Negation::make(*(yyvsp[-1].atom)); }
#line 2856 "pddl.cc" /* yacc.c:1646  */
    break;

  case 221:
#line 811 "pddl.yy" /* yacc.c:1646  */
    { (yyval.expr) = new Value((yyvsp[0].num)); }
#line 2862 "pddl.cc" /* yacc.c:1646  */
    break;

  case 222:
#line 812 "pddl.yy" /* yacc.c:1646  */
    { (yyval.expr) = &Addition::make(*(yyvsp[-2].expr), *(yyvsp[-1].expr)); }
#line 2868 "pddl.cc" /* yacc.c:1646  */
    break;

  case 223:
#line 813 "pddl.yy" /* yacc.c:1646  */
    { (yyval.expr) = make_subtraction(*(yyvsp[-2].expr), (yyvsp[-1].expr)); }
#line 2874 "pddl.cc" /* yacc.c:1646  */
    break;

  case 224:
#line 814 "pddl.yy" /* yacc.c:1646  */
    { (yyval.expr) = &Multiplication::make(*(yyvsp[-2].expr), *(yyvsp[-1].expr)); }
#line 2880 "pddl.cc" /* yacc.c:1646  */
    break;

  case 225:
#line 815 "pddl.yy" /* yacc.c:1646  */
    { (yyval.expr) = &Division::make(*(yyvsp[-2].expr), *(yyvsp[-1].expr)); }
#line 2886 "pddl.cc" /* yacc.c:1646  */
    break;

  case 226:
#line 816 "pddl.yy" /* yacc.c:1646  */
    { (yyval.expr) = (yyvsp[0].fluent); }
#line 2892 "pddl.cc" /* yacc.c:1646  */
    break;

  case 227:
#line 819 "pddl.yy" /* yacc.c:1646  */
    { (yyval.expr) = 0; }
#line 2898 "pddl.cc" /* yacc.c:1646  */
    break;

  case 229:
#line 823 "pddl.yy" /* yacc.c:1646  */
    { prepare_fluent((yyvsp[0].str)); }
#line 2904 "pddl.cc" /* yacc.c:1646  */
    break;

  case 230:
#line 824 "pddl.yy" /* yacc.c:1646  */
    { (yyval.fluent) = make_fluent(); }
#line 2910 "pddl.cc" /* yacc.c:1646  */
    break;

  case 231:
#line 825 "pddl.yy" /* yacc.c:1646  */
    { prepare_fluent((yyvsp[0].str)); (yyval.fluent) = make_fluent(); }
#line 2916 "pddl.cc" /* yacc.c:1646  */
    break;

  case 232:
#line 828 "pddl.yy" /* yacc.c:1646  */
    { (yyval.expr) = new Value((yyvsp[0].num)); }
#line 2922 "pddl.cc" /* yacc.c:1646  */
    break;

  case 233:
#line 830 "pddl.yy" /* yacc.c:1646  */
    { (yyval.expr) = &Addition::make(*(yyvsp[-2].expr), *(yyvsp[-1].expr)); }
#line 2928 "pddl.cc" /* yacc.c:1646  */
    break;

  case 234:
#line 832 "pddl.yy" /* yacc.c:1646  */
    { (yyval.expr) = make_subtraction(*(yyvsp[-2].expr), (yyvsp[-1].expr)); }
#line 2934 "pddl.cc" /* yacc.c:1646  */
    break;

  case 235:
#line 834 "pddl.yy" /* yacc.c:1646  */
    { (yyval.expr) = &Multiplication::make(*(yyvsp[-2].expr), *(yyvsp[-1].expr)); }
#line 2940 "pddl.cc" /* yacc.c:1646  */
    break;

  case 236:
#line 836 "pddl.yy" /* yacc.c:1646  */
    { (yyval.expr) = &Division::make(*(yyvsp[-2].expr), *(yyvsp[-1].expr)); }
#line 2946 "pddl.cc" /* yacc.c:1646  */
    break;

  case 237:
#line 837 "pddl.yy" /* yacc.c:1646  */
    { (yyval.expr) = (yyvsp[0].fluent); }
#line 2952 "pddl.cc" /* yacc.c:1646  */
    break;

  case 238:
#line 840 "pddl.yy" /* yacc.c:1646  */
    { (yyval.expr) = 0; }
#line 2958 "pddl.cc" /* yacc.c:1646  */
    break;

  case 240:
#line 844 "pddl.yy" /* yacc.c:1646  */
    { prepare_fluent((yyvsp[0].str)); }
#line 2964 "pddl.cc" /* yacc.c:1646  */
    break;

  case 241:
#line 845 "pddl.yy" /* yacc.c:1646  */
    { (yyval.fluent) = make_fluent(); }
#line 2970 "pddl.cc" /* yacc.c:1646  */
    break;

  case 242:
#line 846 "pddl.yy" /* yacc.c:1646  */
    { prepare_fluent((yyvsp[0].str)); (yyval.fluent) = make_fluent(); }
#line 2976 "pddl.cc" /* yacc.c:1646  */
    break;

  case 244:
#line 854 "pddl.yy" /* yacc.c:1646  */
    { add_term((yyvsp[0].str)); }
#line 2982 "pddl.cc" /* yacc.c:1646  */
    break;

  case 245:
#line 855 "pddl.yy" /* yacc.c:1646  */
    { add_term((yyvsp[0].str)); }
#line 2988 "pddl.cc" /* yacc.c:1646  */
    break;

  case 247:
#line 859 "pddl.yy" /* yacc.c:1646  */
    { add_term((yyvsp[0].str)); }
#line 2994 "pddl.cc" /* yacc.c:1646  */
    break;

  case 248:
#line 862 "pddl.yy" /* yacc.c:1646  */
    { (yyval.term) = new Term(make_term((yyvsp[0].str))); }
#line 3000 "pddl.cc" /* yacc.c:1646  */
    break;

  case 249:
#line 863 "pddl.yy" /* yacc.c:1646  */
    { (yyval.term) = new Term(make_term((yyvsp[0].str))); }
#line 3006 "pddl.cc" /* yacc.c:1646  */
    break;

  case 251:
#line 867 "pddl.yy" /* yacc.c:1646  */
    { add_variables((yyvsp[0].strs), TypeTable::OBJECT); }
#line 3012 "pddl.cc" /* yacc.c:1646  */
    break;

  case 252:
#line 868 "pddl.yy" /* yacc.c:1646  */
    { add_variables((yyvsp[-1].strs), *(yyvsp[0].type)); delete (yyvsp[0].type); }
#line 3018 "pddl.cc" /* yacc.c:1646  */
    break;

  case 254:
#line 872 "pddl.yy" /* yacc.c:1646  */
    { (yyval.strs) = new std::vector<const std::string*>(1, (yyvsp[0].str)); }
#line 3024 "pddl.cc" /* yacc.c:1646  */
    break;

  case 255:
#line 873 "pddl.yy" /* yacc.c:1646  */
    { (yyval.strs) = (yyvsp[-1].strs); (yyval.strs)->push_back((yyvsp[0].str)); }
#line 3030 "pddl.cc" /* yacc.c:1646  */
    break;

  case 257:
#line 877 "pddl.yy" /* yacc.c:1646  */
    { add_names((yyvsp[0].strs), TypeTable::OBJECT); }
#line 3036 "pddl.cc" /* yacc.c:1646  */
    break;

  case 258:
#line 878 "pddl.yy" /* yacc.c:1646  */
    { add_names((yyvsp[-1].strs), *(yyvsp[0].type)); delete (yyvsp[0].type); }
#line 3042 "pddl.cc" /* yacc.c:1646  */
    break;

  case 260:
#line 881 "pddl.yy" /* yacc.c:1646  */
    { (yyval.strs) = new std::vector<const std::string*>(1, (yyvsp[0].str)); }
#line 3048 "pddl.cc" /* yacc.c:1646  */
    break;

  case 261:
#line 882 "pddl.yy" /* yacc.c:1646  */
    { (yyval.strs) = (yyvsp[-1].strs); (yyval.strs)->push_back((yyvsp[0].str)); }
#line 3054 "pddl.cc" /* yacc.c:1646  */
    break;

  case 262:
#line 885 "pddl.yy" /* yacc.c:1646  */
    { require_typing(); }
#line 3060 "pddl.cc" /* yacc.c:1646  */
    break;

  case 263:
#line 885 "pddl.yy" /* yacc.c:1646  */
    { (yyval.type) = (yyvsp[0].type); }
#line 3066 "pddl.cc" /* yacc.c:1646  */
    break;

  case 264:
#line 888 "pddl.yy" /* yacc.c:1646  */
    { (yyval.type) = new Type(TypeTable::OBJECT); }
#line 3072 "pddl.cc" /* yacc.c:1646  */
    break;

  case 265:
#line 889 "pddl.yy" /* yacc.c:1646  */
    { (yyval.type) = new Type(make_type((yyvsp[0].str))); }
#line 3078 "pddl.cc" /* yacc.c:1646  */
    break;

  case 266:
#line 890 "pddl.yy" /* yacc.c:1646  */
    { (yyval.type) = new Type(make_type(*(yyvsp[-1].types))); delete (yyvsp[-1].types); }
#line 3084 "pddl.cc" /* yacc.c:1646  */
    break;

  case 267:
#line 893 "pddl.yy" /* yacc.c:1646  */
    { (yyval.types) = new TypeSet(); }
#line 3090 "pddl.cc" /* yacc.c:1646  */
    break;

  case 268:
#line 894 "pddl.yy" /* yacc.c:1646  */
    { (yyval.types) = new TypeSet(); (yyval.types)->insert(make_type((yyvsp[0].str))); }
#line 3096 "pddl.cc" /* yacc.c:1646  */
    break;

  case 269:
#line 895 "pddl.yy" /* yacc.c:1646  */
    { (yyval.types) = (yyvsp[-1].types); }
#line 3102 "pddl.cc" /* yacc.c:1646  */
    break;

  case 270:
#line 896 "pddl.yy" /* yacc.c:1646  */
    { (yyval.types) = (yyvsp[-1].types); (yyval.types)->insert(make_type((yyvsp[0].str))); }
#line 3108 "pddl.cc" /* yacc.c:1646  */
    break;

  case 272:
#line 906 "pddl.yy" /* yacc.c:1646  */
    { delete (yyvsp[0].str); }
#line 3114 "pddl.cc" /* yacc.c:1646  */
    break;

  case 273:
#line 909 "pddl.yy" /* yacc.c:1646  */
    { delete (yyvsp[0].str); }
#line 3120 "pddl.cc" /* yacc.c:1646  */
    break;

  case 274:
#line 912 "pddl.yy" /* yacc.c:1646  */
    { delete (yyvsp[0].str); }
#line 3126 "pddl.cc" /* yacc.c:1646  */
    break;

  case 275:
#line 915 "pddl.yy" /* yacc.c:1646  */
    { delete (yyvsp[0].str); }
#line 3132 "pddl.cc" /* yacc.c:1646  */
    break;

  case 276:
#line 918 "pddl.yy" /* yacc.c:1646  */
    { delete (yyvsp[0].str); }
#line 3138 "pddl.cc" /* yacc.c:1646  */
    break;

  case 277:
#line 921 "pddl.yy" /* yacc.c:1646  */
    { delete (yyvsp[0].str); }
#line 3144 "pddl.cc" /* yacc.c:1646  */
    break;

  case 278:
#line 924 "pddl.yy" /* yacc.c:1646  */
    { delete (yyvsp[0].str); }
#line 3150 "pddl.cc" /* yacc.c:1646  */
    break;

  case 279:
#line 927 "pddl.yy" /* yacc.c:1646  */
    { delete (yyvsp[0].str); }
#line 3156 "pddl.cc" /* yacc.c:1646  */
    break;

  case 280:
#line 930 "pddl.yy" /* yacc.c:1646  */
    { delete (yyvsp[0].str); }
#line 3162 "pddl.cc" /* yacc.c:1646  */
    break;

  case 281:
#line 933 "pddl.yy" /* yacc.c:1646  */
    { delete (yyvsp[0].str); }
#line 3168 "pddl.cc" /* yacc.c:1646  */
    break;

  case 282:
#line 936 "pddl.yy" /* yacc.c:1646  */
    { delete (yyvsp[0].str); }
#line 3174 "pddl.cc" /* yacc.c:1646  */
    break;

  case 283:
#line 939 "pddl.yy" /* yacc.c:1646  */
    { delete (yyvsp[0].str); }
#line 3180 "pddl.cc" /* yacc.c:1646  */
    break;

  case 284:
#line 942 "pddl.yy" /* yacc.c:1646  */
    { delete (yyvsp[0].str); }
#line 3186 "pddl.cc" /* yacc.c:1646  */
    break;

  case 285:
#line 945 "pddl.yy" /* yacc.c:1646  */
    { delete (yyvsp[0].str); }
#line 3192 "pddl.cc" /* yacc.c:1646  */
    break;

  case 286:
#line 948 "pddl.yy" /* yacc.c:1646  */
    { delete (yyvsp[0].str); }
#line 3198 "pddl.cc" /* yacc.c:1646  */
    break;

  case 287:
#line 951 "pddl.yy" /* yacc.c:1646  */
    { delete (yyvsp[0].str); }
#line 3204 "pddl.cc" /* yacc.c:1646  */
    break;

  case 288:
#line 954 "pddl.yy" /* yacc.c:1646  */
    { delete (yyvsp[0].str); }
#line 3210 "pddl.cc" /* yacc.c:1646  */
    break;

  case 289:
#line 957 "pddl.yy" /* yacc.c:1646  */
    { delete (yyvsp[0].str); }
#line 3216 "pddl.cc" /* yacc.c:1646  */
    break;

  case 290:
#line 960 "pddl.yy" /* yacc.c:1646  */
    { delete (yyvsp[0].str); }
#line 3222 "pddl.cc" /* yacc.c:1646  */
    break;

  case 291:
#line 963 "pddl.yy" /* yacc.c:1646  */
    { delete (yyvsp[0].str); }
#line 3228 "pddl.cc" /* yacc.c:1646  */
    break;

  case 292:
#line 966 "pddl.yy" /* yacc.c:1646  */
    { delete (yyvsp[0].str); }
#line 3234 "pddl.cc" /* yacc.c:1646  */
    break;


#line 3238 "pddl.cc" /* yacc.c:1646  */
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
#line 1002 "pddl.yy" /* yacc.c:1906  */


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

/* Creates a decomposition for the given composite action name with the given name. */
static void make_decomposition(const std::string* composite_action_name, const std::string* name) 
{
	context.push_frame();

	const ActionSchema* composite_action = domain->find_action(*composite_action_name);
	if(composite_action == 0) {
		yyerror("no action labeled " + *composite_action_name + " exists");
	}

	else if(!(composite_action->composite())) {
		yyerror("action " + *composite_action_name + " is not composite");
	}

	else {
		decomposition = new DecompositionSchema(composite_action, *name);
		delete name;
	}
}

/* Adds the current decomposition to the current domain. */
static void add_decomposition()
{
	context.pop_frame();

	/* If we have not declared this decomposition in the past, */
	if(domain->find_decomposition(decomposition->composite_action_schema().name(), decomposition->name()) == 0) {
		domain->add_decomposition(*decomposition);
	}

	else {
		yywarning("ignoring repeated declaration of decomposition `" 
			+ decomposition->name() + "' for composite action `" 
			+ decomposition->composite_action_schema().name() + "'");
		delete decomposition;
	}

	decomposition = 0;
}


/* Prepares for the parsing of a pseudo-step. */
static void prepare_pseudostep(const std::string* pseudo_step_action_name) 
{ 
	/* Verify that the action name refers to an existing action. */
	pseudo_step_action = domain->find_action(*pseudo_step_action_name);

	if(pseudo_step_action == 0) {
		yyerror("No action of type " + *pseudo_step_action_name + " exists for pseudo-step definition.");
	}

	else {
		term_parameters.clear();
		delete pseudo_step_action_name;
	}
}


/* Creates the pseudo-step just parsed. */
static const Step* make_pseudostep()
{
	// Check that the arity of the parsed terms matches the arity of the pseudo-step's action.
	size_t n = term_parameters.size();

	if(pseudo_step_action->parameters().size() != n) 
	{
		yyerror("incorrect number of parameters specified for pseudo-step action "
			+ pseudo_step_action->name());
	}

	else 
    {
        // Store a reference to the id of this pseudo-step. */
        int pseudo_step_id = -(++Decomposition::next_pseudo_step_id);
        
        // Here, I have to iterate through the parsed terms, and do different things 
        // depending on whether the term is an object constant, or a variable.
        for (TermList::size_type pi = 0; pi < term_parameters.size(); ++pi)
        {
            // Get the parsed Term at this index.
            Term t = term_parameters[pi];

            // Get the variable and type of the action schema at this index. 
            const Variable action_parameter = pseudo_step_action->parameters()[pi];
            const Type typeof_action_parameter = TermTable::type(action_parameter);

            if (t.object()) 
            {
                // Find all the objects compatible with the type of the action schema's parameter at the current index.
                ObjectList ol = domain->terms().compatible_objects(typeof_action_parameter);

                // See if we can find the current term in that list.
                ObjectList::iterator oitr = std::find(ol.begin(), ol.end(), t);
                if (oitr == ol.end()) { // not found!
                    yyerror("type-incompatible object for pseudo-step action parameter");
                }

                else 
                { 
                    // The type of the action schema's parameter at the current index is compatible to the parsed term.
                    // Add a binding to the decomposition, where:
                    // (the action schema's variable and this decomposition's index) are bound to
                    // (this term and the pseudo-step's index)
                    const Binding* new_binding = new Binding(action_parameter, (int) decomposition->id(), t, pseudo_step_id, true);
                    decomposition->add_binding(*new_binding);
                }
            }

            else // t is a variable
            { 
                // Check that the name of this term matches one name on the parameter list of the decomposition schema.
                std::string name_of_term_variable = *context.find(t.as_variable());
                const Variable* parameter_variable_match = 0;

                for (VariableList::const_iterator vi = decomposition->parameters().begin();
                    vi != decomposition->parameters().end();
                    ++vi)
                {
                    std::string name_of_parameter_variable = *context.find(*vi);
                    if (name_of_term_variable == name_of_parameter_variable) {
                        parameter_variable_match = &(*vi);
                    }
                }

                if (parameter_variable_match == 0) {
                    yyerror("variable " + name_of_term_variable + " does not exist in parameter list for decomposition");
                }

                else
                {
                    // Since we have a match, we ignore the term variable altogether, 
                    // because the binding is relative to the parameter of the decomposition.

                    // The parameter variable must be a subtype of the action schema variable.
                    const Variable decomposition_parameter = *parameter_variable_match;
                    const Type typeof_decomposition_parameter = TermTable::type(decomposition_parameter);

                    if (! domain->types().subtype(typeof_decomposition_parameter, typeof_action_parameter)) {
                        yyerror("variable " + name_of_term_variable + " is type-incompatible with pseudo-step action parameater");
                    }

                    // Once I've done that check, add a binding as before.  And then we're done here!
                    const Binding* new_binding = new Binding(decomposition_parameter, (int)decomposition->id(), action_parameter, pseudo_step_id, true);
                    decomposition->add_binding(*new_binding);
                }
            }
        }

        /* At this point we have successfully created all the bindings necessary for the pseudo-step in question. */
        Step* new_pseudo_step = new Step(pseudo_step_id, *pseudo_step_action);
		decomposition->add_pseudo_step(*new_pseudo_step);
        return new_pseudo_step;
    }
	
    return NULL;
}


/* Adds a pseudo-step to the current decomposition. */
static void add_pseudostep() 
{
	// NOTE: *decomposition is referenceable in this function.
	pseudo_step_action = 0;
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
