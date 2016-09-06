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
#include "orderings.h"
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
static std::map<const std::string, const Step*> decomposition_pseudo_steps;

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
static void make_problem(const std::string* name, const std::string* domain_name);

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
static void add_pseudo_step(const Step& pseudo_step);

/* Creates an ordering from pseudo-steps with the parameter names. */
static const Ordering* make_ordering(const std::string* pseudo_step_name1, const std::string* pseudo_step_name2);

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

#line 377 "pddl.cc" /* yacc.c:339  */

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
#line 354 "pddl.yy" /* yacc.c:355  */

  const Step* step;
  const Ordering* ordering;
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

#line 503 "pddl.cc" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_PDDL_HH_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 520 "pddl.cc" /* yacc.c:358  */

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
#define YYLAST   1185

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  79
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  169
/* YYNRULES -- Number of rules.  */
#define YYNRULES  356
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  592

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
       0,   392,   392,   392,   396,   397,   398,   405,   405,   409,
     410,   411,   412,   415,   416,   417,   420,   421,   422,   423,
     424,   425,   426,   429,   430,   431,   432,   433,   436,   437,
     438,   439,   440,   443,   444,   445,   446,   447,   450,   451,
     452,   455,   456,   457,   460,   461,   462,   465,   466,   469,
     470,   473,   476,   477,   480,   481,   482,   484,   486,   487,
     489,   491,   493,   494,   495,   496,   497,   499,   501,   506,
     509,   509,   513,   513,   517,   520,   520,   527,   528,   531,
     531,   535,   536,   537,   540,   541,   544,   544,   547,   547,
     555,   555,   556,   556,   559,   560,   563,   564,   567,   568,
     571,   572,   575,   575,   578,   578,   581,   582,   585,   586,
     589,   590,   598,   597,   602,   605,   606,   610,   611,   614,
     615,   618,   621,   621,   625,   626,   629,   632,   633,   636,
     642,   643,   646,   647,   648,   651,   652,   660,   661,   664,
     665,   668,   668,   669,   669,   670,   670,   677,   678,   679,
     679,   680,   680,   680,   683,   684,   687,   688,   691,   692,
     695,   696,   699,   700,   701,   701,   703,   703,   707,   708,
     712,   711,   715,   714,   719,   720,   721,   721,   723,   723,
     727,   728,   736,   735,   740,   741,   744,   745,   748,   749,
     752,   752,   756,   759,   760,   763,   763,   765,   765,   767,
     769,   771,   775,   776,   779,   782,   782,   784,   784,   792,
     793,   794,   795,   796,   796,   797,   797,   799,   799,   801,
     801,   805,   806,   809,   810,   813,   813,   817,   817,   821,
     822,   829,   830,   831,   832,   833,   834,   837,   838,   841,
     841,   843,   846,   847,   849,   851,   853,   855,   858,   859,
     862,   862,   864,   871,   872,   873,   876,   877,   880,   881,
     884,   885,   886,   886,   890,   891,   894,   895,   896,   896,
     899,   900,   903,   903,   906,   907,   908,   911,   912,   913,
     914,   917,   924,   927,   930,   933,   936,   939,   942,   945,
     948,   951,   954,   957,   960,   963,   966,   969,   972,   975,
     978,   981,   984,   987,   987,   987,   988,   989,   989,   989,
     989,   989,   990,   990,   990,   991,   994,   995,   995,   998,
     998,   998,   999,  1000,  1000,  1000,  1000,  1001,  1001,  1001,
    1002,  1003,  1003,  1006,  1009,  1009,  1009,  1010,  1010,  1010,
    1011,  1011,  1011,  1011,  1011,  1011,  1011,  1012,  1012,  1012,
    1012,  1012,  1013,  1013,  1013,  1014,  1017
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
  "decomposition_body2", "decomposition_body3", "steps", "step",
  "pseudo_step", "$@14", "links", "link", "orderings", "ordering",
  "duration_constraint", "simple_duration_constraint",
  "simple_duration_constraints", "da_gd", "timed_gds", "timed_gd", "$@15",
  "$@16", "$@17", "eff_formula", "$@18", "$@19", "$@20", "eff_formulas",
  "one_eff_formula", "term_literal", "term_literals", "da_effect", "$@21",
  "$@22", "da_effects", "timed_effect", "$@23", "$@24", "a_effect", "$@25",
  "$@26", "a_effects", "problem_def", "$@27", "problem_body",
  "problem_body2", "problem_body3", "object_decl", "$@28", "init",
  "init_elements", "init_element", "$@29", "$@30", "goal_spec", "goal",
  "metric_spec", "$@31", "$@32", "formula", "$@33", "$@34", "$@35", "$@36",
  "conjuncts", "disjuncts", "atomic_term_formula", "$@37",
  "atomic_name_formula", "$@38", "name_literal", "f_exp", "opt_f_exp",
  "f_head", "$@39", "ground_f_exp", "opt_ground_f_exp", "ground_f_head",
  "$@40", "terms", "names", "term", "variables", "$@41", "variable_seq",
  "typed_names", "$@42", "name_seq", "type_spec", "$@43", "type", "types",
  "function_type", "define", "domain", "problem", "when", "not", "and",
  "or", "imply", "exists", "forall", "at", "over", "start", "end", "all",
  "duration_var", "minimize", "maximize", "number", "object", "either",
  "type_name", "predicate", "init_predicate", "function", "name",
  "variable", YY_NULLPTR
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

#define YYPACT_NINF -452

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-452)))

#define YYTABLE_NINF -293

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -452,    36,  -452,  -452,   -31,    55,  -452,  -452,  -452,    -8,
     108,  -452,  -452,  1127,  1127,  -452,  -452,  -452,  -452,  -452,
    -452,  -452,  -452,  -452,  -452,  -452,  -452,  -452,  -452,  -452,
    -452,  -452,  -452,  -452,  -452,  -452,  -452,    -2,     4,  -452,
      25,    47,   117,    38,    82,  -452,  -452,    89,  -452,    93,
     107,   121,   126,   130,  -452,  -452,  1127,  1049,  -452,  -452,
    -452,  -452,  1127,  1127,  1127,  -452,     1,  -452,   462,  -452,
      46,  -452,   202,  -452,    89,   133,   138,    71,  -452,    89,
     133,   153,    78,  -452,    89,   138,   153,   155,  -452,  -452,
    -452,  -452,  -452,  -452,  -452,  -452,  -452,  -452,  -452,  -452,
    -452,  -452,  -452,  -452,   593,  -452,  1127,  1127,    74,   160,
    -452,  -452,    37,    70,  -452,    89,    89,    33,  -452,    89,
      89,  -452,    84,  -452,    89,    89,  -452,  -452,  -452,  -452,
    -452,   165,   470,  -452,   170,   904,  -452,  -452,  1127,   176,
      35,  -452,   227,   227,  1127,    89,    89,    89,   186,  -452,
    -452,  -452,  -452,  -452,  -452,  -452,  -452,  -452,  -452,  -452,
    -452,  -452,  -452,  -452,  -452,  -452,  -452,  -452,  -452,  -452,
    -452,  -452,  -452,  -452,  -452,   160,  -452,   189,     9,   241,
    -452,   204,   200,   203,  -452,  -452,   214,   237,  -452,   244,
     780,  1127,   259,   259,   270,  -452,   259,  -452,  -452,   113,
     265,  -452,  -452,    -4,   276,  -452,   274,   227,  -452,  -452,
     278,   134,  -452,  -452,   178,  -452,   313,  -452,   314,  -452,
    -452,   295,  -452,  -452,  -452,  -452,  -452,   282,    17,  -452,
     284,  -452,  -452,  -452,   289,   278,   291,  -452,  -452,  -452,
    -452,  -452,    27,     0,  -452,   288,  1127,   151,   389,   293,
    -452,   199,  -452,   960,  -452,  -452,  -452,  -452,  -452,  -452,
     500,  -452,  -452,  -452,  -452,   306,   306,   306,  -452,   317,
     318,   319,  -452,   321,   324,   325,   407,  -452,  -452,  -452,
    -452,  -452,  -452,  -452,  1104,   278,  -452,  -452,  -452,  -452,
    -452,  -452,  -452,  -452,  -452,  -452,  -452,   724,  -452,  -452,
     259,  -452,  -452,   327,  -452,  -452,  -452,   930,   930,   930,
     193,   -10,  -452,  -452,    45,   355,  -452,  -452,  -452,  -452,
    -452,  -452,  -452,  -452,   337,  -452,  -452,  -452,  -452,  -452,
    -452,  -452,  -452,  -452,  -452,  -452,  1048,   329,   340,  -452,
    1104,  -452,  -452,   331,   206,  -452,   278,   333,   338,  -452,
     989,   989,  -452,  -452,  -452,  -452,   278,   904,   336,   208,
     339,  -452,   248,   342,  -452,  -452,   343,   344,    76,  -452,
    -452,  -452,   318,  -452,  -452,   233,  -452,  -452,   233,   368,
    -452,   212,  -452,  1127,   357,  -452,   904,   349,   351,  -452,
     352,  -452,  -452,  -452,   234,   278,   259,   259,   532,  -452,
     328,   353,  -452,   354,  -452,  -452,  -452,  -452,   259,   930,
     930,   930,   930,  -452,  -452,  -452,  -452,  -452,   239,   356,
    -452,  -452,  -452,  -452,   242,  -452,  -452,  -452,  -452,  1127,
     254,  -452,   706,  -452,   374,  -452,  -452,   848,  -452,   377,
     762,  -452,  -452,  -452,   378,   379,   380,  -452,  -452,  -452,
     989,   989,   989,   989,  -452,  -452,   393,   395,   930,   930,
     930,   930,  -452,   397,  -452,  -452,   259,   398,   398,   283,
    -452,  -452,   278,   278,   278,   406,  -452,   408,  -452,  -452,
    -452,  -452,  -452,  -452,  -452,   329,  -452,  -452,  -452,   278,
     278,   989,   989,   989,   989,   620,   409,  -452,   291,  -452,
     410,   412,   413,   414,   590,   432,   415,   416,   500,  -452,
     418,   419,   422,   423,   424,  1127,   425,    88,  -452,   818,
     874,   426,   427,   428,  -452,   429,   430,   455,   458,  -452,
    -452,   459,  -452,  -452,  -452,  -452,  -452,  -452,   317,   278,
    -452,  -452,  -452,  -452,  -452,  -452,  -452,  -452,  -452,   460,
    -452,  -452,   264,  -452,  -452,  -452,  -452,  -452,  -452,  -452,
    -452,  -452,   268,  -452,   461,  -452,   272,   463,  -452,  -452,
    1127,  -452,  -452,   848,  -452,  -452,  -452,   393,  -452,  -452,
     259,   648,  1127,   472,   485,  -452,   488,  -452,   398,  -452,
     489,  -452
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
       2,     0,     4,     1,     3,     0,     5,     6,   282,     0,
       0,   283,   284,     0,     0,   334,   335,   336,   340,   341,
     342,   343,   344,   345,   346,   347,   348,   349,   350,   351,
     352,   353,   354,   337,   338,   339,   355,     0,     0,     7,
       0,     9,     0,     0,     0,    12,    15,    22,    47,    10,
      13,    16,    17,    18,    49,    50,     0,     0,    70,    72,
      77,    75,     0,     0,     0,     8,     0,    48,     0,    11,
       0,    14,     0,    19,    27,    23,    24,     0,    20,    32,
      28,    29,     0,    21,    37,    33,    34,     0,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    68,    69,     0,    52,   266,   266,     0,    81,
      90,    92,     0,     0,    25,    40,    38,     0,    26,    43,
      41,    30,     0,    31,    46,    44,    35,    36,   182,    51,
      53,     0,   267,   270,     0,     0,    74,    78,     0,     0,
      82,    84,    94,    94,     0,    39,    42,    45,     0,    71,
     272,   268,   271,    73,   303,   304,   305,   307,   308,   309,
     310,   311,   312,   313,   314,   318,   317,   306,   315,   316,
      79,    88,   333,    76,    86,    81,    85,     0,   100,     0,
     112,     0,     0,     0,   185,   187,     0,     0,   189,   202,
       0,   266,   260,   260,     0,    83,   260,   102,   104,     0,
       0,    97,    99,   100,   100,   101,     0,    94,   190,   193,
       0,     0,   184,   183,     0,   186,     0,   188,     0,   203,
     301,     0,   273,   274,   275,   269,   356,     0,   261,   264,
       0,   300,    87,   281,     0,     0,     0,   106,   107,    91,
      96,    98,     0,   110,   130,     0,   266,     0,     0,     0,
     209,     0,   302,     0,    80,   262,   265,    89,    95,   103,
       0,   105,   147,   158,   287,     0,     0,     0,   135,     0,
       0,     0,   109,     0,     0,     0,     0,   192,   194,   286,
     288,   289,   290,   291,     0,     0,   221,   213,   215,   217,
     219,   225,   204,   298,   299,   207,   205,     0,   277,   278,
     260,   285,   151,     0,   154,   149,   297,     0,     0,     0,
       0,     0,   111,   162,     0,   110,   137,    93,   119,   113,
     191,   319,   320,   321,   197,   323,   324,   325,   326,   327,
     328,   329,   332,   331,   322,   330,     0,     0,     0,   195,
       0,   258,   259,     0,     0,   223,     0,     0,     0,   253,
       0,     0,   276,   279,   280,   263,     0,     0,     0,     0,
       0,   231,     0,     0,   236,   241,     0,     0,     0,   131,
     136,   292,     0,   168,   164,     0,   293,   139,     0,     0,
     108,     0,   256,     0,     0,   252,     0,     0,     0,   256,
       0,   211,   212,   222,     0,     0,   260,   260,     0,   242,
       0,     0,   247,     0,   152,   159,   148,   155,   260,     0,
       0,     0,     0,   239,   132,   133,   134,   166,     0,     0,
     294,   295,   170,   172,     0,   141,   143,   296,   145,     0,
     117,   120,     0,   250,     0,   227,   199,     0,   229,     0,
       0,   210,   214,   224,     0,     0,     0,   226,   254,   255,
       0,     0,     0,     0,   208,   206,     0,     0,   237,     0,
       0,     0,   253,     0,   163,   169,   260,     0,     0,     0,
     138,   140,     0,     0,     0,     0,   124,     0,   114,   116,
     198,   257,   256,   200,   256,     0,   201,   196,   216,     0,
       0,   248,     0,     0,     0,     0,     0,   156,     0,   238,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   174,
       0,     0,     0,     0,     0,     0,     0,   117,   127,     0,
       0,     0,     0,     0,   249,     0,     0,     0,     0,   160,
     153,     0,   233,   232,   234,   235,   240,   167,     0,     0,
     180,   176,   171,   173,   142,   144,   146,   122,   121,     0,
     115,   125,     0,   251,   228,   230,   218,   220,   244,   243,
     245,   246,     0,   150,     0,   178,     0,     0,   253,   126,
       0,   118,   128,     0,   157,   161,   165,     0,   175,   181,
     260,     0,     0,     0,     0,   123,     0,   179,     0,   129,
       0,   177
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -452,  -452,  -452,  -452,  -452,  -452,  -452,   373,   484,  -452,
    -452,  -452,   399,   456,   475,   109,    73,   417,  -452,   487,
    -452,  -452,   112,  -452,   184,   124,  -452,  -452,  -452,  -452,
     387,  -452,  -452,  -452,   448,  -452,  -452,  -452,  -452,  -119,
    -452,   360,   362,  -452,  -452,  -452,  -452,  -452,  -452,   249,
    -452,  -452,  -452,  -452,    50,  -452,  -452,  -452,  -452,  -452,
    -452,  -452,  -452,  -452,   279,  -452,   224,  -452,   173,  -452,
    -452,  -452,  -343,  -452,  -452,  -452,  -452,    21,  -232,  -452,
    -400,  -452,  -452,  -452,   136,  -452,  -452,  -451,  -452,  -452,
    -452,  -452,  -452,  -452,   420,   433,  -452,  -452,  -452,  -452,
    -452,  -452,  -452,   434,  -452,  -452,  -452,  -452,  -228,  -452,
    -452,  -452,  -452,  -452,  -452,  -225,  -452,  -355,  -452,  -452,
    -287,  -452,  -452,  -452,  -311,  -452,   286,  -452,  -439,  -336,
     260,  -191,  -452,  -452,   -92,  -452,  -452,   392,  -452,  -452,
    -452,  -452,  -452,  -452,  -452,  -299,  -235,  -240,  -452,  -452,
    -452,  -250,  -262,  -452,   223,   269,  -452,    80,  -452,  -452,
    -452,  -227,  -452,  -171,  -129,  -452,  -135,   -13,  -219
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,     2,     4,     6,    41,    44,    45,    46,    73,
      78,    83,   114,   118,   123,    47,    48,    49,   104,   105,
      50,   106,    51,   107,    52,    53,   109,   108,   137,   192,
     139,   140,   175,   194,   141,   193,    54,   142,   143,   178,
     200,   201,   202,   203,   235,   204,   236,   205,   271,   272,
      55,   207,   274,   478,   479,   381,   431,   516,   568,   517,
     551,   552,   572,   243,   244,   310,   315,   424,   316,   472,
     473,   474,   261,   360,   356,   456,   359,   496,   509,   562,
     312,   419,   463,   418,   313,   467,   468,   510,   567,   577,
     566,     7,   148,   183,   184,   185,   186,   246,   187,   247,
     278,   389,   382,   188,   189,   219,   351,   350,   249,   345,
     346,   347,   348,   344,   394,   250,   349,   387,   484,   439,
     363,   500,   364,   462,   401,   525,   402,   482,   398,   432,
     340,   227,   300,   228,   131,   191,   132,   151,   190,   222,
     297,   232,     9,    13,    14,   302,   303,   268,   287,   288,
     289,   290,   375,   379,   422,   423,   428,   307,   295,   296,
     233,   223,   253,   169,   291,   339,   365,   172,   229
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      37,    38,   230,   171,   262,   234,   170,   259,   286,   256,
     305,   263,   372,   285,   338,   134,   407,   511,   465,   224,
     304,   366,   367,   504,   179,   198,   298,    62,   301,   269,
     264,    63,   270,   438,   283,   371,     3,   197,   198,     5,
     403,   337,    60,    87,    57,    58,    59,    60,    61,   110,
     111,   112,   378,   440,    59,    60,    61,   343,     8,    62,
     199,   374,    10,    63,    62,   342,    64,   264,    63,    39,
     353,   373,    62,   199,   377,    40,    63,   226,   358,    59,
      61,    61,   299,   265,   266,   264,    59,    60,   245,   150,
     371,   376,    59,   133,   133,    42,    62,    62,    64,   225,
      63,    63,   267,    64,    62,   138,   144,   174,    63,   355,
      62,    64,    11,    12,    63,   579,   393,    43,   395,   152,
      67,   342,   458,   459,   460,   461,   354,   262,   404,   581,
     521,   180,   265,   266,   263,    64,    64,   590,   564,   491,
     492,   493,   494,    64,   135,   136,   519,    67,   520,    64,
      56,   267,    67,    65,   275,   531,   477,    67,   549,    66,
      74,    79,    84,    68,    80,    85,   443,   444,   208,   209,
     210,   499,   501,   502,   503,    76,    81,    70,   133,   449,
     524,   526,   527,   528,   115,   119,   237,   238,    67,   115,
     124,    72,    67,   125,   119,   124,    77,    67,   125,   116,
      82,   385,   485,   113,   116,   445,   446,   378,   117,   539,
      57,    60,    61,   209,   210,   385,   385,   457,    67,    67,
      67,   276,   277,   122,   497,   145,   128,   413,    62,   146,
     138,   263,    63,   133,   147,    75,   149,    86,   208,   209,
     210,   153,   263,   263,   512,   513,   514,   173,   433,   293,
     294,    15,    16,    17,   177,   529,   181,   435,   541,   196,
     120,   522,   523,   368,   369,   433,   262,    64,   540,   120,
     211,   341,   206,   263,   213,   507,   248,   392,   260,   406,
     420,   421,   429,   430,   214,   449,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,   248,   442,    36,   216,   435,   311,
     464,   565,   469,   470,   218,   385,   385,   385,   385,   226,
     409,   476,   477,   231,   410,   411,   412,   341,   371,   376,
     575,    15,    16,    17,   570,   571,   239,   263,   573,   574,
     199,   263,   508,   578,   242,   497,   308,   309,   248,   210,
     252,   251,   263,   254,   273,   257,   385,   385,   385,   385,
     258,   260,   449,   263,   292,   306,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,   269,   448,    36,   311,   314,   584,
     317,   318,   154,   155,   156,   319,   320,   357,  -292,   386,
     450,   388,   391,   396,   451,   452,   453,   405,   397,   408,
     321,   322,   323,   414,   415,   416,   475,   427,   434,   481,
     436,   437,    69,   441,   454,   455,   466,   481,   279,   264,
     280,   281,   282,   283,   157,   158,   159,   160,   161,   162,
     163,   164,   165,   166,   167,   483,   279,   168,   486,   488,
     489,   490,   324,   325,   326,   327,   328,   329,   330,   331,
     332,   333,   334,   495,   284,   335,   498,   505,   508,    58,
      59,    60,    61,    15,    16,    17,   515,   371,   518,   121,
     530,   532,   336,   533,   534,   535,   537,   538,    62,   542,
     543,   448,    63,   544,   545,   546,   548,   555,   556,   557,
     558,   559,   547,   154,   155,   156,   481,   481,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,   560,    64,    36,   561,
     563,   569,   576,   580,    71,    15,    16,    17,   301,   279,
     264,   126,   150,   587,   283,   157,   158,   159,   160,   161,
     162,   163,   164,   165,   166,   167,   588,   582,   168,   589,
     591,   127,   195,   240,   380,   182,   241,   550,   448,   586,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,   176,   370,
      36,   130,   226,    15,    16,    17,   417,   471,   583,   506,
     390,   425,   212,   447,    88,    89,    90,    91,    92,    93,
      94,    95,    96,    97,    98,    99,   100,   101,   102,   215,
     255,   217,   384,   154,   155,   156,     0,     0,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,     0,   426,    36,     0,
     226,    15,    16,    17,     0,     0,   103,     0,     0,   279,
     264,   536,     0,     0,   129,   157,   158,   159,   160,   161,
     162,   163,   164,   165,   166,   167,     0,     0,   168,     0,
       0,     0,     0,     0,     0,     0,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,     0,     0,    36,     0,   226,    15,
      16,    17,     0,     0,     0,     0,     0,     0,     0,   585,
       0,     0,     0,     0,     0,     0,     0,   154,   155,   156,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,     0,     0,    36,    15,    16,    17,     0,   157,
     158,   159,   160,   161,   162,   163,   164,   480,   220,   167,
       0,     0,   168,   154,   155,   156,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   352,     0,     0,     0,     0,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,     0,     0,
      36,    15,    16,    17,     0,   157,   158,   159,   160,   161,
     162,   163,   164,   487,   220,   167,     0,     0,   168,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     221,   154,   155,   156,     0,     0,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,     0,     0,    36,    15,    16,    17,
       0,     0,     0,     0,     0,     0,     0,   279,     0,   553,
       0,     0,     0,   157,   158,   159,   160,   161,   162,   163,
     164,   165,   166,   167,     0,     0,   168,   154,   155,   156,
       0,     0,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
       0,     0,    36,    15,    16,    17,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   554,     0,     0,     0,   157,
     158,   159,   160,   161,   162,   163,   164,   165,   166,   167,
       0,     0,   168,   154,   155,   156,     0,     0,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,     0,     0,    36,     0,
       0,   361,    15,    16,    17,     0,     0,     0,     0,     0,
     362,     0,     0,     0,     0,   157,   158,   159,   160,   161,
     162,   163,   164,     0,   220,   167,     0,     0,   168,     0,
       0,     0,     0,     0,     0,     0,     0,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,     0,     0,    36,     0,     0,
     399,    15,    16,    17,     0,     0,     0,     0,     0,   400,
      88,    89,    90,    91,    92,    93,    94,    95,    96,    97,
      98,    99,   100,   101,   102,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,     0,     0,    36,    15,    16,    17,
       0,     0,   103,     0,     0,     0,     0,     0,   383,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      15,    16,    17,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
       0,     0,    36,     0,   226,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,     0,     0,    36
};

static const yytype_int16 yycheck[] =
{
      13,    14,   193,   138,   236,   196,   135,   235,   248,   228,
     260,   236,   311,   248,   276,   107,   359,   468,   418,   190,
     260,   308,   309,   462,   143,    29,   253,    26,    38,    29,
      40,    30,    32,   388,    44,    45,     0,    28,    29,    70,
     351,   276,     9,    56,     6,     7,     8,     9,    10,    62,
      63,    64,   314,   389,     8,     9,    10,   285,     3,    26,
      64,   311,    70,    30,    26,   284,    65,    40,    30,    71,
     297,   311,    26,    64,   314,    71,    30,    60,   303,     8,
      10,    10,   253,    56,    57,    40,     8,     9,   207,    72,
      45,    46,     8,   106,   107,    70,    26,    26,    65,   191,
      30,    30,    75,    65,    26,    70,    69,    72,    30,   300,
      26,    65,     4,     5,    30,   566,   344,    70,   346,   132,
      47,   340,   409,   410,   411,   412,   297,   359,   356,   568,
     485,   144,    56,    57,   359,    65,    65,   588,   538,   450,
     451,   452,   453,    65,    70,    71,   482,    74,   484,    65,
      33,    75,    79,    71,   246,   498,    68,    84,    70,    70,
      51,    52,    53,    70,    52,    53,   394,   395,    34,    35,
      36,   458,   459,   460,   461,    51,    52,    70,   191,   398,
     491,   492,   493,   494,    75,    76,    73,    74,   115,    80,
      81,    70,   119,    81,    85,    86,    70,   124,    86,    75,
      70,   336,   437,    70,    80,   396,   397,   469,    70,   508,
       6,     9,    10,    35,    36,   350,   351,   408,   145,   146,
     147,    70,    71,    70,   456,   116,    71,   362,    26,   120,
      70,   456,    30,   246,   125,    51,    71,    53,    34,    35,
      36,    71,   467,   468,   472,   473,   474,    71,   383,    50,
      51,     3,     4,     5,    27,   495,    70,   386,   508,    70,
      76,   489,   490,    70,    71,   400,   498,    65,   508,    85,
      70,   284,    31,   498,    71,   466,    70,    71,    70,    71,
      47,    48,    70,    71,    70,   504,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    70,    71,    58,    70,   437,    70,
      71,   539,    70,    71,    70,   450,   451,   452,   453,    60,
      72,    67,    68,    53,    76,    77,    78,   340,    45,    46,
     562,     3,     4,     5,    70,    71,    71,   562,    70,    71,
      64,   566,    70,    71,    70,   577,   266,   267,    70,    36,
      55,    37,   577,    71,    66,    71,   491,   492,   493,   494,
      71,    70,   581,   588,    71,    59,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    29,   398,    58,    70,    70,   580,
      71,    70,     3,     4,     5,    71,    71,    70,    61,    70,
      72,    61,    71,    70,    76,    77,    78,    71,    70,    70,
       3,     4,     5,    71,    71,    71,   429,    49,    61,   432,
      71,    70,    49,    71,    71,    71,    70,   440,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    71,    39,    58,    71,    71,
      71,    71,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    70,    75,    58,    71,    70,    70,     7,
       8,     9,    10,     3,     4,     5,    70,    45,    70,    80,
      71,    71,    75,    71,    71,    71,    71,    71,    26,    71,
      71,   504,    30,    71,    71,    71,    71,    71,    71,    71,
      71,    71,   515,     3,     4,     5,   519,   520,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    71,    65,    58,    71,
      71,    71,    71,    70,    50,     3,     4,     5,    38,    39,
      40,    85,    72,    71,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    71,   570,    58,    71,
      71,    86,   175,   203,   315,   148,   204,   517,   581,   582,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,   140,   310,
      58,   104,    60,     3,     4,     5,   372,   424,   577,   463,
     340,   378,   182,    71,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,   186,
     228,   187,   336,     3,     4,     5,    -1,    -1,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    -1,   378,    58,    -1,
      60,     3,     4,     5,    -1,    -1,    63,    -1,    -1,    39,
      40,    71,    -1,    -1,    71,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    -1,    -1,    58,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    -1,    -1,    58,    -1,    60,     3,
       4,     5,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    71,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,     3,     4,     5,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    -1,    -1,    58,     3,     4,     5,    -1,    45,
      46,    47,    48,    49,    50,    51,    52,    71,    54,    55,
      -1,    -1,    58,     3,     4,     5,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    71,    -1,    -1,    -1,    -1,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    -1,    -1,
      58,     3,     4,     5,    -1,    45,    46,    47,    48,    49,
      50,    51,    52,    71,    54,    55,    -1,    -1,    58,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      70,     3,     4,     5,    -1,    -1,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    -1,    -1,    58,     3,     4,     5,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    39,    -1,    71,
      -1,    -1,    -1,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    -1,    -1,    58,     3,     4,     5,
      -1,    -1,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      -1,    -1,    58,     3,     4,     5,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    71,    -1,    -1,    -1,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      -1,    -1,    58,     3,     4,     5,    -1,    -1,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    -1,    -1,    58,    -1,
      -1,    61,     3,     4,     5,    -1,    -1,    -1,    -1,    -1,
      70,    -1,    -1,    -1,    -1,    45,    46,    47,    48,    49,
      50,    51,    52,    -1,    54,    55,    -1,    -1,    58,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    -1,    -1,    58,    -1,    -1,
      61,     3,     4,     5,    -1,    -1,    -1,    -1,    -1,    70,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    -1,    -1,    58,     3,     4,     5,
      -1,    -1,    63,    -1,    -1,    -1,    -1,    -1,    70,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
       3,     4,     5,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      -1,    -1,    58,    -1,    60,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    -1,    -1,    58
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    80,    81,     0,    82,    70,    83,   170,     3,   221,
      70,     4,     5,   222,   223,     3,     4,     5,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    58,   246,   246,    71,
      71,    84,    70,    70,    85,    86,    87,    94,    95,    96,
      99,   101,   103,   104,   115,   129,    33,     6,     7,     8,
       9,    10,    26,    30,    65,    71,    70,    95,    70,    86,
      70,    87,    70,    88,    94,   103,   104,    70,    89,    94,
     101,   104,    70,    90,    94,   101,   103,   246,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    63,    97,    98,   100,   102,   106,   105,
     246,   246,   246,    70,    91,    94,   104,    70,    92,    94,
     103,    91,    70,    93,    94,   101,    92,    93,    71,    71,
      98,   213,   215,   246,   213,    70,    71,   107,    70,   109,
     110,   113,   116,   117,    69,    94,    94,    94,   171,    71,
      72,   216,   246,    71,     3,     4,     5,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    58,   242,
     243,   245,   246,    71,    72,   111,   113,    27,   118,   118,
     246,    70,    96,   172,   173,   174,   175,   177,   182,   183,
     217,   214,   108,   114,   112,   109,    70,    28,    29,    64,
     119,   120,   121,   122,   124,   126,    31,   130,    34,    35,
      36,    70,   173,    71,    70,   174,    70,   182,    70,   184,
      54,    70,   218,   240,   242,   213,    60,   210,   212,   247,
     210,    53,   220,   239,   210,   123,   125,    73,    74,    71,
     120,   121,    70,   142,   143,   118,   176,   178,    70,   187,
     194,    37,    55,   241,    71,   216,   247,    71,    71,   187,
      70,   151,   157,   194,    40,    56,    57,    75,   226,    29,
      32,   127,   128,    66,   131,   213,    70,    71,   179,    39,
      41,    42,    43,    44,    75,   225,   226,   227,   228,   229,
     230,   243,    71,    50,    51,   237,   238,   219,   240,   242,
     211,    38,   224,   225,   226,   230,    59,   236,   236,   236,
     144,    70,   159,   163,    70,   145,   147,    71,    70,    71,
      71,     3,     4,     5,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    58,    75,   225,   231,   244,
     209,   246,   247,   187,   192,   188,   189,   190,   191,   195,
     186,   185,    71,   240,   242,   210,   153,    70,   194,   155,
     152,    61,    70,   199,   201,   245,   199,   199,    70,    71,
     143,    45,   224,   226,   230,   231,    46,   226,   231,   232,
     128,   134,   181,    70,   205,   245,    70,   196,    61,   180,
     209,    71,    71,   187,   193,   187,    70,    70,   207,    61,
      70,   203,   205,   203,   187,    71,    71,   151,    70,    72,
      76,    77,    78,   245,    71,    71,    71,   145,   162,   160,
      47,    48,   233,   234,   146,   233,   234,    49,   235,    70,
      71,   135,   208,   245,    61,   243,    71,    70,   196,   198,
     208,    71,    71,   187,   187,   210,   210,    71,   246,   247,
      72,    76,    77,    78,    71,    71,   154,   210,   199,   199,
     199,   199,   202,   161,    71,   159,    70,   164,   165,    70,
      71,   147,   148,   149,   150,   246,    67,    68,   132,   133,
      71,   246,   206,    71,   197,   225,    71,    71,    71,    71,
      71,   203,   203,   203,   203,    70,   156,   157,    71,   199,
     200,   199,   199,   199,   207,    70,   163,   210,    70,   157,
     166,   166,   187,   187,   187,    70,   136,   138,    70,   208,
     208,   196,   187,   187,   203,   204,   203,   203,   203,   226,
      71,   151,    71,    71,    71,    71,    71,    71,    71,   224,
     226,   230,    71,    71,    71,    71,    71,   246,    71,    70,
     133,   139,   140,    71,    71,    71,    71,    71,    71,    71,
      71,    71,   158,    71,   159,   187,   169,   167,   137,    71,
      70,    71,   141,    70,    71,   157,    71,   168,    71,   166,
      70,   207,   246,   156,   210,    71,   246,    71,    71,    71,
     166,    71
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
     128,   128,   130,   129,   131,   132,   132,   133,   133,   134,
     134,   135,   137,   136,   138,   138,   139,   140,   140,   141,
     142,   142,   143,   143,   143,   144,   144,   145,   145,   146,
     146,   148,   147,   149,   147,   150,   147,   151,   151,   152,
     151,   153,   154,   151,   155,   155,   156,   156,   157,   157,
     158,   158,   159,   159,   160,   159,   161,   159,   162,   162,
     164,   163,   165,   163,   166,   166,   167,   166,   168,   166,
     169,   169,   171,   170,   172,   172,   173,   173,   174,   174,
     176,   175,   177,   178,   178,   180,   179,   181,   179,   179,
     179,   179,   182,   182,   183,   185,   184,   186,   184,   187,
     187,   187,   187,   188,   187,   189,   187,   190,   187,   191,
     187,   192,   192,   193,   193,   195,   194,   197,   196,   198,
     198,   199,   199,   199,   199,   199,   199,   200,   200,   202,
     201,   201,   203,   203,   203,   203,   203,   203,   204,   204,
     206,   205,   205,   207,   207,   207,   208,   208,   209,   209,
     210,   210,   211,   210,   212,   212,   213,   213,   214,   213,
     215,   215,   217,   216,   218,   218,   218,   219,   219,   219,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   242,   242,   242,   242,   242,   242,
     242,   242,   242,   242,   242,   242,   243,   243,   243,   244,
     244,   244,   244,   244,   244,   244,   244,   244,   244,   244,
     244,   244,   244,   245,   246,   246,   246,   246,   246,   246,
     246,   246,   246,   246,   246,   246,   246,   246,   246,   246,
     246,   246,   246,   246,   246,   246,   247
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
       0,     2,     0,     9,     5,     3,     1,     0,     4,     0,
       2,     4,     0,     5,     0,     2,     2,     0,     2,     4,
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
#line 392 "pddl.yy" /* yacc.c:1646  */
    { success = true; line_number = 1; }
#line 2194 "pddl.cc" /* yacc.c:1646  */
    break;

  case 3:
#line 393 "pddl.yy" /* yacc.c:1646  */
    { if (!success) YYERROR; }
#line 2200 "pddl.cc" /* yacc.c:1646  */
    break;

  case 7:
#line 405 "pddl.yy" /* yacc.c:1646  */
    { make_domain((yyvsp[-1].str)); }
#line 2206 "pddl.cc" /* yacc.c:1646  */
    break;

  case 54:
#line 480 "pddl.yy" /* yacc.c:1646  */
    { requirements->strips = true; }
#line 2212 "pddl.cc" /* yacc.c:1646  */
    break;

  case 55:
#line 481 "pddl.yy" /* yacc.c:1646  */
    { requirements->typing = true; }
#line 2218 "pddl.cc" /* yacc.c:1646  */
    break;

  case 56:
#line 483 "pddl.yy" /* yacc.c:1646  */
    { requirements->negative_preconditions = true; }
#line 2224 "pddl.cc" /* yacc.c:1646  */
    break;

  case 57:
#line 485 "pddl.yy" /* yacc.c:1646  */
    { requirements->disjunctive_preconditions = true; }
#line 2230 "pddl.cc" /* yacc.c:1646  */
    break;

  case 58:
#line 486 "pddl.yy" /* yacc.c:1646  */
    { requirements->equality = true; }
#line 2236 "pddl.cc" /* yacc.c:1646  */
    break;

  case 59:
#line 488 "pddl.yy" /* yacc.c:1646  */
    { requirements->existential_preconditions = true; }
#line 2242 "pddl.cc" /* yacc.c:1646  */
    break;

  case 60:
#line 490 "pddl.yy" /* yacc.c:1646  */
    { requirements->universal_preconditions = true; }
#line 2248 "pddl.cc" /* yacc.c:1646  */
    break;

  case 61:
#line 492 "pddl.yy" /* yacc.c:1646  */
    { requirements->quantified_preconditions(); }
#line 2254 "pddl.cc" /* yacc.c:1646  */
    break;

  case 62:
#line 493 "pddl.yy" /* yacc.c:1646  */
    { requirements->conditional_effects = true; }
#line 2260 "pddl.cc" /* yacc.c:1646  */
    break;

  case 63:
#line 494 "pddl.yy" /* yacc.c:1646  */
    { requirements->fluents = true; }
#line 2266 "pddl.cc" /* yacc.c:1646  */
    break;

  case 64:
#line 495 "pddl.yy" /* yacc.c:1646  */
    { requirements->adl(); }
#line 2272 "pddl.cc" /* yacc.c:1646  */
    break;

  case 65:
#line 496 "pddl.yy" /* yacc.c:1646  */
    { requirements->durative_actions = true; }
#line 2278 "pddl.cc" /* yacc.c:1646  */
    break;

  case 66:
#line 498 "pddl.yy" /* yacc.c:1646  */
    { requirements->duration_inequalities = true; }
#line 2284 "pddl.cc" /* yacc.c:1646  */
    break;

  case 67:
#line 500 "pddl.yy" /* yacc.c:1646  */
    { yyerror("`:continuous-effects' not supported"); }
#line 2290 "pddl.cc" /* yacc.c:1646  */
    break;

  case 68:
#line 502 "pddl.yy" /* yacc.c:1646  */
    {
					requirements->durative_actions = true;
					requirements->timed_initial_literals = true;
				}
#line 2299 "pddl.cc" /* yacc.c:1646  */
    break;

  case 69:
#line 506 "pddl.yy" /* yacc.c:1646  */
    { requirements->decompositions = true; }
#line 2305 "pddl.cc" /* yacc.c:1646  */
    break;

  case 70:
#line 509 "pddl.yy" /* yacc.c:1646  */
    { require_typing(); name_kind = TYPE_KIND; }
#line 2311 "pddl.cc" /* yacc.c:1646  */
    break;

  case 71:
#line 510 "pddl.yy" /* yacc.c:1646  */
    { name_kind = VOID_KIND; }
#line 2317 "pddl.cc" /* yacc.c:1646  */
    break;

  case 72:
#line 513 "pddl.yy" /* yacc.c:1646  */
    { name_kind = CONSTANT_KIND; }
#line 2323 "pddl.cc" /* yacc.c:1646  */
    break;

  case 73:
#line 514 "pddl.yy" /* yacc.c:1646  */
    { name_kind = VOID_KIND; }
#line 2329 "pddl.cc" /* yacc.c:1646  */
    break;

  case 75:
#line 520 "pddl.yy" /* yacc.c:1646  */
    { require_fluents(); }
#line 2335 "pddl.cc" /* yacc.c:1646  */
    break;

  case 79:
#line 531 "pddl.yy" /* yacc.c:1646  */
    { make_predicate((yyvsp[0].str)); }
#line 2341 "pddl.cc" /* yacc.c:1646  */
    break;

  case 80:
#line 532 "pddl.yy" /* yacc.c:1646  */
    { predicate = 0; }
#line 2347 "pddl.cc" /* yacc.c:1646  */
    break;

  case 86:
#line 544 "pddl.yy" /* yacc.c:1646  */
    { require_typing(); }
#line 2353 "pddl.cc" /* yacc.c:1646  */
    break;

  case 88:
#line 547 "pddl.yy" /* yacc.c:1646  */
    { make_function((yyvsp[0].str)); }
#line 2359 "pddl.cc" /* yacc.c:1646  */
    break;

  case 89:
#line 548 "pddl.yy" /* yacc.c:1646  */
    { function = 0; }
#line 2365 "pddl.cc" /* yacc.c:1646  */
    break;

  case 90:
#line 555 "pddl.yy" /* yacc.c:1646  */
    { make_action((yyvsp[0].str), false, false); }
#line 2371 "pddl.cc" /* yacc.c:1646  */
    break;

  case 91:
#line 555 "pddl.yy" /* yacc.c:1646  */
    { add_action(); }
#line 2377 "pddl.cc" /* yacc.c:1646  */
    break;

  case 92:
#line 556 "pddl.yy" /* yacc.c:1646  */
    { make_action((yyvsp[0].str), true, false); }
#line 2383 "pddl.cc" /* yacc.c:1646  */
    break;

  case 93:
#line 556 "pddl.yy" /* yacc.c:1646  */
    { add_action(); }
#line 2389 "pddl.cc" /* yacc.c:1646  */
    break;

  case 102:
#line 575 "pddl.yy" /* yacc.c:1646  */
    { formula_time = AT_START; }
#line 2395 "pddl.cc" /* yacc.c:1646  */
    break;

  case 103:
#line 575 "pddl.yy" /* yacc.c:1646  */
    { action->set_condition(*(yyvsp[0].formula)); }
#line 2401 "pddl.cc" /* yacc.c:1646  */
    break;

  case 104:
#line 578 "pddl.yy" /* yacc.c:1646  */
    { effect_time = Effect::AT_END; }
#line 2407 "pddl.cc" /* yacc.c:1646  */
    break;

  case 106:
#line 581 "pddl.yy" /* yacc.c:1646  */
    { require_decompositions(); action->set_composite(true); }
#line 2413 "pddl.cc" /* yacc.c:1646  */
    break;

  case 107:
#line 582 "pddl.yy" /* yacc.c:1646  */
    { require_decompositions(); action->set_composite(false); }
#line 2419 "pddl.cc" /* yacc.c:1646  */
    break;

  case 108:
#line 585 "pddl.yy" /* yacc.c:1646  */
    { action->set_condition(*(yyvsp[-1].formula)); }
#line 2425 "pddl.cc" /* yacc.c:1646  */
    break;

  case 112:
#line 598 "pddl.yy" /* yacc.c:1646  */
    { make_decomposition((yyvsp[-2].str), (yyvsp[0].str)); }
#line 2431 "pddl.cc" /* yacc.c:1646  */
    break;

  case 113:
#line 599 "pddl.yy" /* yacc.c:1646  */
    { add_decomposition(); decomposition_pseudo_steps.clear(); }
#line 2437 "pddl.cc" /* yacc.c:1646  */
    break;

  case 121:
#line 618 "pddl.yy" /* yacc.c:1646  */
    { decomposition_pseudo_steps.insert( std::make_pair(*(yyvsp[-2].str), (yyvsp[-1].step)) ); add_pseudo_step(*(yyvsp[-1].step)); }
#line 2443 "pddl.cc" /* yacc.c:1646  */
    break;

  case 122:
#line 621 "pddl.yy" /* yacc.c:1646  */
    { prepare_pseudostep((yyvsp[0].str)); }
#line 2449 "pddl.cc" /* yacc.c:1646  */
    break;

  case 123:
#line 622 "pddl.yy" /* yacc.c:1646  */
    { (yyval.step) = make_pseudostep(); }
#line 2455 "pddl.cc" /* yacc.c:1646  */
    break;

  case 129:
#line 636 "pddl.yy" /* yacc.c:1646  */
    { (yyval.ordering) = make_ordering((yyvsp[-2].str), (yyvsp[-1].str)); }
#line 2461 "pddl.cc" /* yacc.c:1646  */
    break;

  case 131:
#line 643 "pddl.yy" /* yacc.c:1646  */
    { require_duration_inequalities(); }
#line 2467 "pddl.cc" /* yacc.c:1646  */
    break;

  case 132:
#line 646 "pddl.yy" /* yacc.c:1646  */
    { require_duration_inequalities(); action->set_max_duration(*(yyvsp[-1].expr)); }
#line 2473 "pddl.cc" /* yacc.c:1646  */
    break;

  case 133:
#line 647 "pddl.yy" /* yacc.c:1646  */
    { require_duration_inequalities(); action->set_min_duration(*(yyvsp[-1].expr)); }
#line 2479 "pddl.cc" /* yacc.c:1646  */
    break;

  case 134:
#line 648 "pddl.yy" /* yacc.c:1646  */
    { action->set_duration(*(yyvsp[-1].expr)); }
#line 2485 "pddl.cc" /* yacc.c:1646  */
    break;

  case 138:
#line 661 "pddl.yy" /* yacc.c:1646  */
    { (yyval.formula) = (yyvsp[-1].formula); }
#line 2491 "pddl.cc" /* yacc.c:1646  */
    break;

  case 139:
#line 664 "pddl.yy" /* yacc.c:1646  */
    { (yyval.formula) = &Formula::TRUE; }
#line 2497 "pddl.cc" /* yacc.c:1646  */
    break;

  case 140:
#line 665 "pddl.yy" /* yacc.c:1646  */
    { (yyval.formula) = &(*(yyvsp[-1].formula) && *(yyvsp[0].formula)); }
#line 2503 "pddl.cc" /* yacc.c:1646  */
    break;

  case 141:
#line 668 "pddl.yy" /* yacc.c:1646  */
    { formula_time = AT_START; }
#line 2509 "pddl.cc" /* yacc.c:1646  */
    break;

  case 142:
#line 668 "pddl.yy" /* yacc.c:1646  */
    { (yyval.formula) = (yyvsp[-1].formula); }
#line 2515 "pddl.cc" /* yacc.c:1646  */
    break;

  case 143:
#line 669 "pddl.yy" /* yacc.c:1646  */
    { formula_time = AT_END; }
#line 2521 "pddl.cc" /* yacc.c:1646  */
    break;

  case 144:
#line 669 "pddl.yy" /* yacc.c:1646  */
    { (yyval.formula) = (yyvsp[-1].formula); }
#line 2527 "pddl.cc" /* yacc.c:1646  */
    break;

  case 145:
#line 670 "pddl.yy" /* yacc.c:1646  */
    { formula_time = OVER_ALL; }
#line 2533 "pddl.cc" /* yacc.c:1646  */
    break;

  case 146:
#line 670 "pddl.yy" /* yacc.c:1646  */
    { (yyval.formula) = (yyvsp[-1].formula); }
#line 2539 "pddl.cc" /* yacc.c:1646  */
    break;

  case 149:
#line 679 "pddl.yy" /* yacc.c:1646  */
    { prepare_forall_effect(); }
#line 2545 "pddl.cc" /* yacc.c:1646  */
    break;

  case 150:
#line 679 "pddl.yy" /* yacc.c:1646  */
    { pop_forall_effect(); }
#line 2551 "pddl.cc" /* yacc.c:1646  */
    break;

  case 151:
#line 680 "pddl.yy" /* yacc.c:1646  */
    { formula_time = AT_START; }
#line 2557 "pddl.cc" /* yacc.c:1646  */
    break;

  case 152:
#line 680 "pddl.yy" /* yacc.c:1646  */
    { prepare_conditional_effect(*(yyvsp[0].formula)); }
#line 2563 "pddl.cc" /* yacc.c:1646  */
    break;

  case 153:
#line 680 "pddl.yy" /* yacc.c:1646  */
    { effect_condition = 0; }
#line 2569 "pddl.cc" /* yacc.c:1646  */
    break;

  case 158:
#line 691 "pddl.yy" /* yacc.c:1646  */
    { add_effect(*(yyvsp[0].atom)); }
#line 2575 "pddl.cc" /* yacc.c:1646  */
    break;

  case 159:
#line 692 "pddl.yy" /* yacc.c:1646  */
    { add_effect(Negation::make(*(yyvsp[-1].atom))); }
#line 2581 "pddl.cc" /* yacc.c:1646  */
    break;

  case 164:
#line 701 "pddl.yy" /* yacc.c:1646  */
    { prepare_forall_effect(); }
#line 2587 "pddl.cc" /* yacc.c:1646  */
    break;

  case 165:
#line 702 "pddl.yy" /* yacc.c:1646  */
    { pop_forall_effect(); }
#line 2593 "pddl.cc" /* yacc.c:1646  */
    break;

  case 166:
#line 703 "pddl.yy" /* yacc.c:1646  */
    { prepare_conditional_effect(*(yyvsp[0].formula)); }
#line 2599 "pddl.cc" /* yacc.c:1646  */
    break;

  case 167:
#line 704 "pddl.yy" /* yacc.c:1646  */
    { effect_condition = 0; }
#line 2605 "pddl.cc" /* yacc.c:1646  */
    break;

  case 170:
#line 712 "pddl.yy" /* yacc.c:1646  */
    { effect_time = Effect::AT_START; formula_time = AT_START; }
#line 2611 "pddl.cc" /* yacc.c:1646  */
    break;

  case 172:
#line 715 "pddl.yy" /* yacc.c:1646  */
    { effect_time = Effect::AT_END; formula_time = AT_END; }
#line 2617 "pddl.cc" /* yacc.c:1646  */
    break;

  case 176:
#line 721 "pddl.yy" /* yacc.c:1646  */
    { prepare_forall_effect(); }
#line 2623 "pddl.cc" /* yacc.c:1646  */
    break;

  case 177:
#line 722 "pddl.yy" /* yacc.c:1646  */
    { pop_forall_effect(); }
#line 2629 "pddl.cc" /* yacc.c:1646  */
    break;

  case 178:
#line 723 "pddl.yy" /* yacc.c:1646  */
    { prepare_conditional_effect(*(yyvsp[0].formula)); }
#line 2635 "pddl.cc" /* yacc.c:1646  */
    break;

  case 179:
#line 724 "pddl.yy" /* yacc.c:1646  */
    { effect_condition = 0; }
#line 2641 "pddl.cc" /* yacc.c:1646  */
    break;

  case 182:
#line 736 "pddl.yy" /* yacc.c:1646  */
    { make_problem((yyvsp[-5].str), (yyvsp[-1].str)); }
#line 2647 "pddl.cc" /* yacc.c:1646  */
    break;

  case 183:
#line 737 "pddl.yy" /* yacc.c:1646  */
    { delete requirements; }
#line 2653 "pddl.cc" /* yacc.c:1646  */
    break;

  case 190:
#line 752 "pddl.yy" /* yacc.c:1646  */
    { name_kind = OBJECT_KIND; }
#line 2659 "pddl.cc" /* yacc.c:1646  */
    break;

  case 191:
#line 753 "pddl.yy" /* yacc.c:1646  */
    { name_kind = VOID_KIND; }
#line 2665 "pddl.cc" /* yacc.c:1646  */
    break;

  case 195:
#line 763 "pddl.yy" /* yacc.c:1646  */
    { prepare_atom((yyvsp[0].str)); }
#line 2671 "pddl.cc" /* yacc.c:1646  */
    break;

  case 196:
#line 764 "pddl.yy" /* yacc.c:1646  */
    { problem->add_init_atom(*make_atom()); }
#line 2677 "pddl.cc" /* yacc.c:1646  */
    break;

  case 197:
#line 765 "pddl.yy" /* yacc.c:1646  */
    { prepare_atom((yyvsp[0].str)); }
#line 2683 "pddl.cc" /* yacc.c:1646  */
    break;

  case 198:
#line 766 "pddl.yy" /* yacc.c:1646  */
    { problem->add_init_atom(*make_atom()); }
#line 2689 "pddl.cc" /* yacc.c:1646  */
    break;

  case 199:
#line 768 "pddl.yy" /* yacc.c:1646  */
    { Formula::register_use((yyvsp[-1].atom)); Formula::unregister_use((yyvsp[-1].atom)); }
#line 2695 "pddl.cc" /* yacc.c:1646  */
    break;

  case 200:
#line 770 "pddl.yy" /* yacc.c:1646  */
    { problem->add_init_value(*(yyvsp[-2].fluent), (yyvsp[-1].num)); }
#line 2701 "pddl.cc" /* yacc.c:1646  */
    break;

  case 201:
#line 772 "pddl.yy" /* yacc.c:1646  */
    { add_init_literal((yyvsp[-2].num), *(yyvsp[-1].literal)); }
#line 2707 "pddl.cc" /* yacc.c:1646  */
    break;

  case 204:
#line 779 "pddl.yy" /* yacc.c:1646  */
    { problem->set_goal(*(yyvsp[-1].formula)); }
#line 2713 "pddl.cc" /* yacc.c:1646  */
    break;

  case 205:
#line 782 "pddl.yy" /* yacc.c:1646  */
    { metric_fluent = true; }
#line 2719 "pddl.cc" /* yacc.c:1646  */
    break;

  case 206:
#line 783 "pddl.yy" /* yacc.c:1646  */
    { problem->set_metric(*(yyvsp[-1].expr), true); metric_fluent = false; }
#line 2725 "pddl.cc" /* yacc.c:1646  */
    break;

  case 207:
#line 784 "pddl.yy" /* yacc.c:1646  */
    { metric_fluent = true; }
#line 2731 "pddl.cc" /* yacc.c:1646  */
    break;

  case 208:
#line 785 "pddl.yy" /* yacc.c:1646  */
    { problem->set_metric(*(yyvsp[-1].expr)); metric_fluent = false; }
#line 2737 "pddl.cc" /* yacc.c:1646  */
    break;

  case 209:
#line 792 "pddl.yy" /* yacc.c:1646  */
    { (yyval.formula) = &TimedLiteral::make(*(yyvsp[0].atom), formula_time); }
#line 2743 "pddl.cc" /* yacc.c:1646  */
    break;

  case 210:
#line 793 "pddl.yy" /* yacc.c:1646  */
    { (yyval.formula) = make_equality((yyvsp[-2].term), (yyvsp[-1].term)); }
#line 2749 "pddl.cc" /* yacc.c:1646  */
    break;

  case 211:
#line 794 "pddl.yy" /* yacc.c:1646  */
    { (yyval.formula) = make_negation(*(yyvsp[-1].formula)); }
#line 2755 "pddl.cc" /* yacc.c:1646  */
    break;

  case 212:
#line 795 "pddl.yy" /* yacc.c:1646  */
    { (yyval.formula) = (yyvsp[-1].formula); }
#line 2761 "pddl.cc" /* yacc.c:1646  */
    break;

  case 213:
#line 796 "pddl.yy" /* yacc.c:1646  */
    { require_disjunction(); }
#line 2767 "pddl.cc" /* yacc.c:1646  */
    break;

  case 214:
#line 796 "pddl.yy" /* yacc.c:1646  */
    { (yyval.formula) = (yyvsp[-1].formula); }
#line 2773 "pddl.cc" /* yacc.c:1646  */
    break;

  case 215:
#line 797 "pddl.yy" /* yacc.c:1646  */
    { require_disjunction(); }
#line 2779 "pddl.cc" /* yacc.c:1646  */
    break;

  case 216:
#line 798 "pddl.yy" /* yacc.c:1646  */
    { (yyval.formula) = &(!*(yyvsp[-2].formula) || *(yyvsp[-1].formula)); }
#line 2785 "pddl.cc" /* yacc.c:1646  */
    break;

  case 217:
#line 799 "pddl.yy" /* yacc.c:1646  */
    { prepare_exists(); }
#line 2791 "pddl.cc" /* yacc.c:1646  */
    break;

  case 218:
#line 800 "pddl.yy" /* yacc.c:1646  */
    { (yyval.formula) = make_exists(*(yyvsp[-1].formula)); }
#line 2797 "pddl.cc" /* yacc.c:1646  */
    break;

  case 219:
#line 801 "pddl.yy" /* yacc.c:1646  */
    { prepare_forall(); }
#line 2803 "pddl.cc" /* yacc.c:1646  */
    break;

  case 220:
#line 802 "pddl.yy" /* yacc.c:1646  */
    { (yyval.formula) = make_forall(*(yyvsp[-1].formula)); }
#line 2809 "pddl.cc" /* yacc.c:1646  */
    break;

  case 221:
#line 805 "pddl.yy" /* yacc.c:1646  */
    { (yyval.formula) = &Formula::TRUE; }
#line 2815 "pddl.cc" /* yacc.c:1646  */
    break;

  case 222:
#line 806 "pddl.yy" /* yacc.c:1646  */
    { (yyval.formula) = &(*(yyvsp[-1].formula) && *(yyvsp[0].formula)); }
#line 2821 "pddl.cc" /* yacc.c:1646  */
    break;

  case 223:
#line 809 "pddl.yy" /* yacc.c:1646  */
    { (yyval.formula) = &Formula::FALSE; }
#line 2827 "pddl.cc" /* yacc.c:1646  */
    break;

  case 224:
#line 810 "pddl.yy" /* yacc.c:1646  */
    { (yyval.formula) = &(*(yyvsp[-1].formula) || *(yyvsp[0].formula)); }
#line 2833 "pddl.cc" /* yacc.c:1646  */
    break;

  case 225:
#line 813 "pddl.yy" /* yacc.c:1646  */
    { prepare_atom((yyvsp[0].str)); }
#line 2839 "pddl.cc" /* yacc.c:1646  */
    break;

  case 226:
#line 814 "pddl.yy" /* yacc.c:1646  */
    { (yyval.atom) = make_atom(); }
#line 2845 "pddl.cc" /* yacc.c:1646  */
    break;

  case 227:
#line 817 "pddl.yy" /* yacc.c:1646  */
    { prepare_atom((yyvsp[0].str)); }
#line 2851 "pddl.cc" /* yacc.c:1646  */
    break;

  case 228:
#line 818 "pddl.yy" /* yacc.c:1646  */
    { (yyval.atom) = make_atom(); }
#line 2857 "pddl.cc" /* yacc.c:1646  */
    break;

  case 229:
#line 821 "pddl.yy" /* yacc.c:1646  */
    { (yyval.literal) = (yyvsp[0].atom); }
#line 2863 "pddl.cc" /* yacc.c:1646  */
    break;

  case 230:
#line 822 "pddl.yy" /* yacc.c:1646  */
    { (yyval.literal) = &Negation::make(*(yyvsp[-1].atom)); }
#line 2869 "pddl.cc" /* yacc.c:1646  */
    break;

  case 231:
#line 829 "pddl.yy" /* yacc.c:1646  */
    { (yyval.expr) = new Value((yyvsp[0].num)); }
#line 2875 "pddl.cc" /* yacc.c:1646  */
    break;

  case 232:
#line 830 "pddl.yy" /* yacc.c:1646  */
    { (yyval.expr) = &Addition::make(*(yyvsp[-2].expr), *(yyvsp[-1].expr)); }
#line 2881 "pddl.cc" /* yacc.c:1646  */
    break;

  case 233:
#line 831 "pddl.yy" /* yacc.c:1646  */
    { (yyval.expr) = make_subtraction(*(yyvsp[-2].expr), (yyvsp[-1].expr)); }
#line 2887 "pddl.cc" /* yacc.c:1646  */
    break;

  case 234:
#line 832 "pddl.yy" /* yacc.c:1646  */
    { (yyval.expr) = &Multiplication::make(*(yyvsp[-2].expr), *(yyvsp[-1].expr)); }
#line 2893 "pddl.cc" /* yacc.c:1646  */
    break;

  case 235:
#line 833 "pddl.yy" /* yacc.c:1646  */
    { (yyval.expr) = &Division::make(*(yyvsp[-2].expr), *(yyvsp[-1].expr)); }
#line 2899 "pddl.cc" /* yacc.c:1646  */
    break;

  case 236:
#line 834 "pddl.yy" /* yacc.c:1646  */
    { (yyval.expr) = (yyvsp[0].fluent); }
#line 2905 "pddl.cc" /* yacc.c:1646  */
    break;

  case 237:
#line 837 "pddl.yy" /* yacc.c:1646  */
    { (yyval.expr) = 0; }
#line 2911 "pddl.cc" /* yacc.c:1646  */
    break;

  case 239:
#line 841 "pddl.yy" /* yacc.c:1646  */
    { prepare_fluent((yyvsp[0].str)); }
#line 2917 "pddl.cc" /* yacc.c:1646  */
    break;

  case 240:
#line 842 "pddl.yy" /* yacc.c:1646  */
    { (yyval.fluent) = make_fluent(); }
#line 2923 "pddl.cc" /* yacc.c:1646  */
    break;

  case 241:
#line 843 "pddl.yy" /* yacc.c:1646  */
    { prepare_fluent((yyvsp[0].str)); (yyval.fluent) = make_fluent(); }
#line 2929 "pddl.cc" /* yacc.c:1646  */
    break;

  case 242:
#line 846 "pddl.yy" /* yacc.c:1646  */
    { (yyval.expr) = new Value((yyvsp[0].num)); }
#line 2935 "pddl.cc" /* yacc.c:1646  */
    break;

  case 243:
#line 848 "pddl.yy" /* yacc.c:1646  */
    { (yyval.expr) = &Addition::make(*(yyvsp[-2].expr), *(yyvsp[-1].expr)); }
#line 2941 "pddl.cc" /* yacc.c:1646  */
    break;

  case 244:
#line 850 "pddl.yy" /* yacc.c:1646  */
    { (yyval.expr) = make_subtraction(*(yyvsp[-2].expr), (yyvsp[-1].expr)); }
#line 2947 "pddl.cc" /* yacc.c:1646  */
    break;

  case 245:
#line 852 "pddl.yy" /* yacc.c:1646  */
    { (yyval.expr) = &Multiplication::make(*(yyvsp[-2].expr), *(yyvsp[-1].expr)); }
#line 2953 "pddl.cc" /* yacc.c:1646  */
    break;

  case 246:
#line 854 "pddl.yy" /* yacc.c:1646  */
    { (yyval.expr) = &Division::make(*(yyvsp[-2].expr), *(yyvsp[-1].expr)); }
#line 2959 "pddl.cc" /* yacc.c:1646  */
    break;

  case 247:
#line 855 "pddl.yy" /* yacc.c:1646  */
    { (yyval.expr) = (yyvsp[0].fluent); }
#line 2965 "pddl.cc" /* yacc.c:1646  */
    break;

  case 248:
#line 858 "pddl.yy" /* yacc.c:1646  */
    { (yyval.expr) = 0; }
#line 2971 "pddl.cc" /* yacc.c:1646  */
    break;

  case 250:
#line 862 "pddl.yy" /* yacc.c:1646  */
    { prepare_fluent((yyvsp[0].str)); }
#line 2977 "pddl.cc" /* yacc.c:1646  */
    break;

  case 251:
#line 863 "pddl.yy" /* yacc.c:1646  */
    { (yyval.fluent) = make_fluent(); }
#line 2983 "pddl.cc" /* yacc.c:1646  */
    break;

  case 252:
#line 864 "pddl.yy" /* yacc.c:1646  */
    { prepare_fluent((yyvsp[0].str)); (yyval.fluent) = make_fluent(); }
#line 2989 "pddl.cc" /* yacc.c:1646  */
    break;

  case 254:
#line 872 "pddl.yy" /* yacc.c:1646  */
    { add_term((yyvsp[0].str)); }
#line 2995 "pddl.cc" /* yacc.c:1646  */
    break;

  case 255:
#line 873 "pddl.yy" /* yacc.c:1646  */
    { add_term((yyvsp[0].str)); }
#line 3001 "pddl.cc" /* yacc.c:1646  */
    break;

  case 257:
#line 877 "pddl.yy" /* yacc.c:1646  */
    { add_term((yyvsp[0].str)); }
#line 3007 "pddl.cc" /* yacc.c:1646  */
    break;

  case 258:
#line 880 "pddl.yy" /* yacc.c:1646  */
    { (yyval.term) = new Term(make_term((yyvsp[0].str))); }
#line 3013 "pddl.cc" /* yacc.c:1646  */
    break;

  case 259:
#line 881 "pddl.yy" /* yacc.c:1646  */
    { (yyval.term) = new Term(make_term((yyvsp[0].str))); }
#line 3019 "pddl.cc" /* yacc.c:1646  */
    break;

  case 261:
#line 885 "pddl.yy" /* yacc.c:1646  */
    { add_variables((yyvsp[0].strs), TypeTable::OBJECT); }
#line 3025 "pddl.cc" /* yacc.c:1646  */
    break;

  case 262:
#line 886 "pddl.yy" /* yacc.c:1646  */
    { add_variables((yyvsp[-1].strs), *(yyvsp[0].type)); delete (yyvsp[0].type); }
#line 3031 "pddl.cc" /* yacc.c:1646  */
    break;

  case 264:
#line 890 "pddl.yy" /* yacc.c:1646  */
    { (yyval.strs) = new std::vector<const std::string*>(1, (yyvsp[0].str)); }
#line 3037 "pddl.cc" /* yacc.c:1646  */
    break;

  case 265:
#line 891 "pddl.yy" /* yacc.c:1646  */
    { (yyval.strs) = (yyvsp[-1].strs); (yyval.strs)->push_back((yyvsp[0].str)); }
#line 3043 "pddl.cc" /* yacc.c:1646  */
    break;

  case 267:
#line 895 "pddl.yy" /* yacc.c:1646  */
    { add_names((yyvsp[0].strs), TypeTable::OBJECT); }
#line 3049 "pddl.cc" /* yacc.c:1646  */
    break;

  case 268:
#line 896 "pddl.yy" /* yacc.c:1646  */
    { add_names((yyvsp[-1].strs), *(yyvsp[0].type)); delete (yyvsp[0].type); }
#line 3055 "pddl.cc" /* yacc.c:1646  */
    break;

  case 270:
#line 899 "pddl.yy" /* yacc.c:1646  */
    { (yyval.strs) = new std::vector<const std::string*>(1, (yyvsp[0].str)); }
#line 3061 "pddl.cc" /* yacc.c:1646  */
    break;

  case 271:
#line 900 "pddl.yy" /* yacc.c:1646  */
    { (yyval.strs) = (yyvsp[-1].strs); (yyval.strs)->push_back((yyvsp[0].str)); }
#line 3067 "pddl.cc" /* yacc.c:1646  */
    break;

  case 272:
#line 903 "pddl.yy" /* yacc.c:1646  */
    { require_typing(); }
#line 3073 "pddl.cc" /* yacc.c:1646  */
    break;

  case 273:
#line 903 "pddl.yy" /* yacc.c:1646  */
    { (yyval.type) = (yyvsp[0].type); }
#line 3079 "pddl.cc" /* yacc.c:1646  */
    break;

  case 274:
#line 906 "pddl.yy" /* yacc.c:1646  */
    { (yyval.type) = new Type(TypeTable::OBJECT); }
#line 3085 "pddl.cc" /* yacc.c:1646  */
    break;

  case 275:
#line 907 "pddl.yy" /* yacc.c:1646  */
    { (yyval.type) = new Type(make_type((yyvsp[0].str))); }
#line 3091 "pddl.cc" /* yacc.c:1646  */
    break;

  case 276:
#line 908 "pddl.yy" /* yacc.c:1646  */
    { (yyval.type) = new Type(make_type(*(yyvsp[-1].types))); delete (yyvsp[-1].types); }
#line 3097 "pddl.cc" /* yacc.c:1646  */
    break;

  case 277:
#line 911 "pddl.yy" /* yacc.c:1646  */
    { (yyval.types) = new TypeSet(); }
#line 3103 "pddl.cc" /* yacc.c:1646  */
    break;

  case 278:
#line 912 "pddl.yy" /* yacc.c:1646  */
    { (yyval.types) = new TypeSet(); (yyval.types)->insert(make_type((yyvsp[0].str))); }
#line 3109 "pddl.cc" /* yacc.c:1646  */
    break;

  case 279:
#line 913 "pddl.yy" /* yacc.c:1646  */
    { (yyval.types) = (yyvsp[-1].types); }
#line 3115 "pddl.cc" /* yacc.c:1646  */
    break;

  case 280:
#line 914 "pddl.yy" /* yacc.c:1646  */
    { (yyval.types) = (yyvsp[-1].types); (yyval.types)->insert(make_type((yyvsp[0].str))); }
#line 3121 "pddl.cc" /* yacc.c:1646  */
    break;

  case 282:
#line 924 "pddl.yy" /* yacc.c:1646  */
    { delete (yyvsp[0].str); }
#line 3127 "pddl.cc" /* yacc.c:1646  */
    break;

  case 283:
#line 927 "pddl.yy" /* yacc.c:1646  */
    { delete (yyvsp[0].str); }
#line 3133 "pddl.cc" /* yacc.c:1646  */
    break;

  case 284:
#line 930 "pddl.yy" /* yacc.c:1646  */
    { delete (yyvsp[0].str); }
#line 3139 "pddl.cc" /* yacc.c:1646  */
    break;

  case 285:
#line 933 "pddl.yy" /* yacc.c:1646  */
    { delete (yyvsp[0].str); }
#line 3145 "pddl.cc" /* yacc.c:1646  */
    break;

  case 286:
#line 936 "pddl.yy" /* yacc.c:1646  */
    { delete (yyvsp[0].str); }
#line 3151 "pddl.cc" /* yacc.c:1646  */
    break;

  case 287:
#line 939 "pddl.yy" /* yacc.c:1646  */
    { delete (yyvsp[0].str); }
#line 3157 "pddl.cc" /* yacc.c:1646  */
    break;

  case 288:
#line 942 "pddl.yy" /* yacc.c:1646  */
    { delete (yyvsp[0].str); }
#line 3163 "pddl.cc" /* yacc.c:1646  */
    break;

  case 289:
#line 945 "pddl.yy" /* yacc.c:1646  */
    { delete (yyvsp[0].str); }
#line 3169 "pddl.cc" /* yacc.c:1646  */
    break;

  case 290:
#line 948 "pddl.yy" /* yacc.c:1646  */
    { delete (yyvsp[0].str); }
#line 3175 "pddl.cc" /* yacc.c:1646  */
    break;

  case 291:
#line 951 "pddl.yy" /* yacc.c:1646  */
    { delete (yyvsp[0].str); }
#line 3181 "pddl.cc" /* yacc.c:1646  */
    break;

  case 292:
#line 954 "pddl.yy" /* yacc.c:1646  */
    { delete (yyvsp[0].str); }
#line 3187 "pddl.cc" /* yacc.c:1646  */
    break;

  case 293:
#line 957 "pddl.yy" /* yacc.c:1646  */
    { delete (yyvsp[0].str); }
#line 3193 "pddl.cc" /* yacc.c:1646  */
    break;

  case 294:
#line 960 "pddl.yy" /* yacc.c:1646  */
    { delete (yyvsp[0].str); }
#line 3199 "pddl.cc" /* yacc.c:1646  */
    break;

  case 295:
#line 963 "pddl.yy" /* yacc.c:1646  */
    { delete (yyvsp[0].str); }
#line 3205 "pddl.cc" /* yacc.c:1646  */
    break;

  case 296:
#line 966 "pddl.yy" /* yacc.c:1646  */
    { delete (yyvsp[0].str); }
#line 3211 "pddl.cc" /* yacc.c:1646  */
    break;

  case 297:
#line 969 "pddl.yy" /* yacc.c:1646  */
    { delete (yyvsp[0].str); }
#line 3217 "pddl.cc" /* yacc.c:1646  */
    break;

  case 298:
#line 972 "pddl.yy" /* yacc.c:1646  */
    { delete (yyvsp[0].str); }
#line 3223 "pddl.cc" /* yacc.c:1646  */
    break;

  case 299:
#line 975 "pddl.yy" /* yacc.c:1646  */
    { delete (yyvsp[0].str); }
#line 3229 "pddl.cc" /* yacc.c:1646  */
    break;

  case 300:
#line 978 "pddl.yy" /* yacc.c:1646  */
    { delete (yyvsp[0].str); }
#line 3235 "pddl.cc" /* yacc.c:1646  */
    break;

  case 301:
#line 981 "pddl.yy" /* yacc.c:1646  */
    { delete (yyvsp[0].str); }
#line 3241 "pddl.cc" /* yacc.c:1646  */
    break;

  case 302:
#line 984 "pddl.yy" /* yacc.c:1646  */
    { delete (yyvsp[0].str); }
#line 3247 "pddl.cc" /* yacc.c:1646  */
    break;


#line 3251 "pddl.cc" /* yacc.c:1646  */
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
#line 1020 "pddl.yy" /* yacc.c:1906  */


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
        return new_pseudo_step;
    }
	
    return NULL;
}


/* Adds a pseudo-step to the current decomposition. */
static void add_pseudo_step(const Step& pseudo_step) 
{
	decomposition->add_pseudo_step(pseudo_step);
	pseudo_step_action = 0;
}

/* Creates an ordering from pseudo-steps with the parameter names. */
static const Ordering* make_ordering(const std::string* pseudo_step_name1, const std::string* pseudo_step_name2)
{
	// Check that each decomposition pseudo-step exists, and store references to them if they do
	const Step* pseudo_step1;
	const Step* pseudo_step2;
	std::map<const std::string, const Step*>::const_iterator si;

	si = decomposition_pseudo_steps.find(*pseudo_step_name1);
	if (si == decomposition_pseudo_steps.end()) {
		yyerror("psuedo-step" + *pseudo_step_name1 + " referenced in ordering for decomposition " 
			+ decomposition->name() + " does not exist");
	}
	else {
		pseudo_step1 = (*si).second;
	}

	si = decomposition_pseudo_steps.find(*pseudo_step_name2);
	if (si == decomposition_pseudo_steps.end()) {
		yyerror("psuedo-step" + *pseudo_step_name2 + " referenced in ordering for decomposition "
			+ decomposition->name() + " does not exist");
	}
	else {
		pseudo_step2 = (*si).second;
	}

	// Check that the names of the pseudo-steps are not the same. This check is done after 
	// verifying they exist, because it doesn't make sense to check before.
	if (*pseudo_step_name1 == *pseudo_step_name2) {
		yyerror("illegal ordering constraint (cannot order step " + *pseudo_step_name1 
			+ " relative to itself in decomposition " + decomposition->name() + ")");
	}

	// Create ordering and return it. I assume that the ordering is constructed in between the end-points.
	return new Ordering(pseudo_step1->id(), StepTime::AT_END, 
		pseudo_step2->id(), StepTime::AT_START);
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
