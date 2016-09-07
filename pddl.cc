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

/* Checks that each named pseudo-step exists, and returns a pair of respective references to 
   them if they do */
static std::pair<const Step*, const Step*> 
make_pseudo_step_pair(const std::string* pseudo_step_name1, const std::string* pseudo_step_name2);

/* Creates an ordering from pseudo-steps with the parameter names. */
static const Ordering* make_ordering(const std::string* pseudo_step_name1, 
    const std::string* pseudo_step_name2);

/* Adds an ordering to the current decomposition. */
static void add_ordering(const Ordering& ordering);

/* Returns a binding between the terms, or 0 if they cannot be bound. Two terms cannot be bound 
   if they are incompatible types or if they're both objects (neither one is a variable). */
static Binding* bind_terms(const Term& first, int first_id, const Term& second, int second_id);

/* Creates a causal link between the pseudo-steps with the parameter names, 
   over the given literal. */
static const Link* make_link(const std::string* pseudo_step_name1,
    const Literal& literal, const std::string* pseudo_step_name2);

/* Adds a link to the current decomposition. */
static void add_link(const Link& link);

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

#line 398 "pddl.cc" /* yacc.c:339  */

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
#line 375 "pddl.yy" /* yacc.c:355  */

  const Link* link;
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

#line 525 "pddl.cc" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_PDDL_HH_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 542 "pddl.cc" /* yacc.c:358  */

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
#define YYLAST   1305

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  79
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  170
/* YYNRULES -- Number of rules.  */
#define YYNRULES  358
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  602

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
       0,   415,   415,   415,   419,   420,   421,   428,   428,   432,
     433,   434,   435,   438,   439,   440,   443,   444,   445,   446,
     447,   448,   449,   452,   453,   454,   455,   456,   459,   460,
     461,   462,   463,   466,   467,   468,   469,   470,   473,   474,
     475,   478,   479,   480,   483,   484,   485,   488,   489,   492,
     493,   496,   499,   500,   503,   504,   505,   507,   509,   510,
     512,   514,   516,   517,   518,   519,   520,   522,   524,   529,
     532,   532,   536,   536,   540,   543,   543,   550,   551,   554,
     554,   558,   559,   560,   563,   564,   567,   567,   570,   570,
     578,   578,   579,   579,   582,   583,   586,   587,   590,   591,
     594,   595,   598,   598,   601,   601,   604,   605,   608,   609,
     612,   613,   621,   620,   625,   628,   629,   633,   634,   637,
     638,   641,   644,   644,   648,   649,   652,   655,   656,   659,
     665,   666,   669,   670,   671,   674,   675,   683,   684,   687,
     688,   691,   691,   692,   692,   693,   693,   700,   701,   702,
     702,   703,   703,   703,   706,   707,   710,   711,   714,   715,
     718,   719,   722,   723,   724,   724,   726,   726,   730,   731,
     735,   734,   738,   737,   742,   743,   744,   744,   746,   746,
     750,   751,   759,   758,   763,   764,   767,   768,   771,   772,
     775,   775,   779,   782,   783,   786,   786,   788,   788,   790,
     792,   794,   798,   799,   802,   805,   805,   807,   807,   815,
     816,   817,   818,   819,   819,   820,   820,   821,   821,   822,
     822,   825,   826,   829,   830,   833,   834,   837,   837,   840,
     840,   843,   844,   851,   852,   853,   854,   855,   856,   859,
     860,   863,   863,   865,   868,   869,   871,   873,   875,   877,
     880,   881,   884,   884,   886,   893,   894,   895,   898,   899,
     902,   903,   906,   907,   908,   908,   912,   913,   916,   917,
     918,   918,   921,   922,   925,   925,   928,   929,   930,   933,
     934,   935,   936,   939,   946,   949,   952,   955,   958,   961,
     964,   967,   970,   973,   976,   979,   982,   985,   988,   991,
     994,   997,  1000,  1003,  1006,  1009,  1009,  1009,  1010,  1011,
    1011,  1011,  1011,  1011,  1012,  1012,  1012,  1013,  1016,  1017,
    1017,  1020,  1020,  1020,  1021,  1022,  1022,  1022,  1022,  1023,
    1023,  1023,  1024,  1025,  1025,  1028,  1031,  1031,  1031,  1032,
    1032,  1032,  1033,  1033,  1033,  1033,  1033,  1033,  1033,  1034,
    1034,  1034,  1034,  1034,  1035,  1035,  1035,  1036,  1039
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
  "conjuncts", "disjuncts", "term_formula", "atomic_term_formula", "$@37",
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

#define YYPACT_NINF -450

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-450)))

#define YYTABLE_NINF -295

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -450,    35,  -450,  -450,   -28,    58,  -450,  -450,  -450,     6,
     103,  -450,  -450,  1247,  1247,  -450,  -450,  -450,  -450,  -450,
    -450,  -450,  -450,  -450,  -450,  -450,  -450,  -450,  -450,  -450,
    -450,  -450,  -450,  -450,  -450,  -450,  -450,    15,    34,  -450,
      44,    64,   113,    38,    65,  -450,  -450,    87,  -450,    89,
     106,   118,   120,   144,  -450,  -450,  1247,  1055,  -450,  -450,
    -450,  -450,  1247,  1247,  1247,  -450,     2,  -450,    30,  -450,
      70,  -450,    80,  -450,    87,   148,   155,    55,  -450,    87,
     148,   160,   130,  -450,    87,   155,   160,   115,  -450,  -450,
    -450,  -450,  -450,  -450,  -450,  -450,  -450,  -450,  -450,  -450,
    -450,  -450,  -450,  -450,   658,  -450,  1247,  1247,   152,   162,
    -450,  -450,   131,   139,  -450,    87,    87,   138,  -450,    87,
      87,  -450,    47,  -450,    87,    87,  -450,  -450,  -450,  -450,
    -450,   163,   596,  -450,   172,   909,  -450,  -450,  1247,   176,
     -41,  -450,   233,   233,  1247,    87,    87,    87,   185,  -450,
    -450,  -450,  -450,  -450,  -450,  -450,  -450,  -450,  -450,  -450,
    -450,  -450,  -450,  -450,  -450,  -450,  -450,  -450,  -450,  -450,
    -450,  -450,  -450,  -450,  -450,   162,  -450,   194,     5,   236,
    -450,   127,   200,   205,  -450,  -450,   215,   230,  -450,   235,
     558,  1247,   231,   231,   255,  -450,   231,  -450,  -450,   135,
     238,  -450,  -450,    -5,   246,  -450,   243,   233,  -450,  -450,
     249,   116,  -450,  -450,   193,  -450,   276,  -450,   283,  -450,
    -450,   266,  -450,  -450,  -450,  -450,  -450,   251,    -2,  -450,
     252,  -450,  -450,  -450,   258,   249,   261,  -450,  -450,  -450,
    -450,  -450,   156,    72,  -450,   267,  1247,   167,   540,   263,
    -450,   189,  -450,   965,  -450,  -450,  -450,  -450,  -450,  -450,
     738,  -450,  -450,  -450,  -450,   277,   277,   277,  -450,   265,
     268,   269,  -450,   272,   273,   278,   321,  -450,  -450,  -450,
    -450,  -450,  -450,  -450,  1224,   249,  -450,  -450,  -450,  -450,
    -450,  -450,  -450,  -450,  -450,  -450,  -450,   405,  -450,  -450,
     231,  -450,  -450,   281,  -450,  -450,  -450,  1050,  1050,  1050,
     171,   147,  -450,  -450,    52,   310,  -450,  -450,  -450,  -450,
    -450,  -450,  -450,  -450,   282,  -450,  -450,  -450,  -450,  -450,
    -450,  -450,  -450,  -450,  -450,  -450,  1168,   284,   291,  -450,
    1224,  -450,  -450,   293,   179,  -450,   249,   285,   295,  -450,
    1109,  1109,  -450,  -450,  -450,  -450,   249,   909,   306,   181,
     308,  -450,   390,   309,  -450,  -450,   311,   312,    27,  -450,
    -450,  -450,   268,  -450,  -450,   206,  -450,  -450,   206,   304,
    -450,   187,  -450,  1247,   320,  -450,   909,   313,   316,  -450,
     317,  -450,  -450,  -450,   207,   249,   231,   231,   652,  -450,
     470,   319,  -450,   326,  -450,  -450,  -450,  -450,   231,  1050,
    1050,  1050,  1050,  -450,  -450,  -450,  -450,  -450,   209,   322,
    -450,  -450,  -450,  -450,   211,  -450,  -450,  -450,  -450,  1247,
     216,  -450,   826,  -450,   327,  -450,  -450,   853,  -450,   328,
     882,  -450,  -450,  -450,   329,   330,   331,  -450,  -450,  -450,
    1109,  1109,  1109,  1109,  -450,  -450,   333,   334,  1050,  1050,
    1050,  1050,  -450,   336,  -450,  -450,   231,   337,   337,   242,
    -450,  -450,   249,   249,   249,   341,   342,   343,  -450,  -450,
    -450,  -450,  -450,  -450,  -450,   284,  -450,  -450,  -450,   249,
     249,  1109,  1109,  1109,  1109,   795,   344,  -450,   261,  -450,
     346,   347,   349,   350,   710,   359,   351,   352,   738,  -450,
     353,   354,   355,   375,   376,  1247,   378,  -450,  -450,   938,
     994,   387,   393,   394,  -450,   398,   399,   400,   401,  -450,
    -450,   406,  -450,  -450,  -450,  -450,  -450,  -450,   265,   249,
    -450,  -450,  -450,  -450,  -450,  -450,  -450,  -450,  -450,   219,
     222,  -450,  -450,  -450,  -450,  -450,  -450,  -450,  -450,  -450,
     224,  -450,   407,  -450,   228,   391,  -450,  1247,   323,  -450,
    1247,  -450,  -450,   853,  -450,  -450,  -450,   333,  -450,  -450,
     231,   768,   409,  -450,  1247,   410,   411,  -450,   853,  1247,
    -450,   412,  -450,   337,   281,   413,  -450,   414,   415,  -450,
    -450,  -450
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
       2,     0,     4,     1,     3,     0,     5,     6,   284,     0,
       0,   285,   286,     0,     0,   336,   337,   338,   342,   343,
     344,   345,   346,   347,   348,   349,   350,   351,   352,   353,
     354,   355,   356,   339,   340,   341,   357,     0,     0,     7,
       0,     9,     0,     0,     0,    12,    15,    22,    47,    10,
      13,    16,    17,    18,    49,    50,     0,     0,    70,    72,
      77,    75,     0,     0,     0,     8,     0,    48,     0,    11,
       0,    14,     0,    19,    27,    23,    24,     0,    20,    32,
      28,    29,     0,    21,    37,    33,    34,     0,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    68,    69,     0,    52,   268,   268,     0,    81,
      90,    92,     0,     0,    25,    40,    38,     0,    26,    43,
      41,    30,     0,    31,    46,    44,    35,    36,   182,    51,
      53,     0,   269,   272,     0,     0,    74,    78,     0,     0,
      82,    84,    94,    94,     0,    39,    42,    45,     0,    71,
     274,   270,   273,    73,   305,   306,   307,   309,   310,   311,
     312,   313,   314,   315,   316,   320,   319,   308,   317,   318,
      79,    88,   335,    76,    86,    81,    85,     0,   100,     0,
     112,     0,     0,     0,   185,   187,     0,     0,   189,   202,
       0,   268,   262,   262,     0,    83,   262,   102,   104,     0,
       0,    97,    99,   100,   100,   101,     0,    94,   190,   193,
       0,     0,   184,   183,     0,   186,     0,   188,     0,   203,
     303,     0,   275,   276,   277,   271,   358,     0,   263,   266,
       0,   302,    87,   283,     0,     0,     0,   106,   107,    91,
      96,    98,     0,   110,   130,     0,   268,     0,     0,     0,
     209,     0,   304,     0,    80,   264,   267,    89,    95,   103,
       0,   105,   147,   158,   289,     0,     0,     0,   135,     0,
       0,     0,   109,     0,     0,     0,     0,   192,   194,   288,
     290,   291,   292,   293,     0,     0,   221,   213,   215,   217,
     219,   227,   204,   300,   301,   207,   205,     0,   279,   280,
     262,   287,   151,     0,   154,   149,   299,     0,     0,     0,
       0,     0,   111,   162,     0,   110,   137,    93,   119,   113,
     191,   321,   322,   323,   197,   325,   326,   327,   328,   329,
     330,   331,   334,   333,   324,   332,     0,     0,     0,   195,
       0,   260,   261,     0,     0,   223,     0,     0,     0,   255,
       0,     0,   278,   281,   282,   265,     0,     0,     0,     0,
       0,   233,     0,     0,   238,   243,     0,     0,     0,   131,
     136,   294,     0,   168,   164,     0,   295,   139,     0,     0,
     108,     0,   258,     0,     0,   254,     0,     0,     0,   258,
       0,   211,   212,   222,     0,     0,   262,   262,     0,   244,
       0,     0,   249,     0,   152,   159,   148,   155,   262,     0,
       0,     0,     0,   241,   132,   133,   134,   166,     0,     0,
     296,   297,   170,   172,     0,   141,   143,   298,   145,     0,
     117,   120,     0,   252,     0,   229,   199,     0,   231,     0,
       0,   210,   214,   224,     0,     0,     0,   228,   256,   257,
       0,     0,     0,     0,   208,   206,     0,     0,   239,     0,
       0,     0,   255,     0,   163,   169,   262,     0,     0,     0,
     138,   140,     0,     0,     0,     0,     0,     0,   114,   116,
     198,   259,   258,   200,   258,     0,   201,   196,   216,     0,
       0,   250,     0,     0,     0,     0,     0,   156,     0,   240,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   174,
       0,     0,     0,     0,     0,     0,     0,   124,   127,     0,
       0,     0,     0,     0,   251,     0,     0,     0,     0,   160,
     153,     0,   235,   234,   236,   237,   242,   167,     0,     0,
     180,   176,   171,   173,   142,   144,   146,   122,   121,     0,
       0,   253,   230,   232,   218,   220,   246,   245,   247,   248,
       0,   150,     0,   178,     0,     0,   255,     0,   117,   125,
       0,   118,   128,     0,   157,   161,   165,     0,   175,   181,
     262,     0,     0,   115,     0,     0,     0,   123,     0,     0,
     225,     0,   179,     0,     0,     0,   129,     0,     0,   126,
     177,   226
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -450,  -450,  -450,  -450,  -450,  -450,  -450,   338,   364,  -450,
    -450,  -450,   408,   395,   403,   221,    74,   339,  -450,   386,
    -450,  -450,     1,  -450,   126,   119,  -450,  -450,  -450,  -450,
     318,  -450,  -450,  -450,   356,  -450,  -450,  -450,  -450,  -116,
    -450,   289,   290,  -450,  -450,  -450,  -450,  -450,  -450,   180,
    -450,  -450,  -450,  -450,   -71,  -450,  -450,  -450,  -450,  -450,
    -450,  -450,  -450,  -450,   188,  -450,   128,  -450,    75,  -450,
    -450,  -450,  -343,  -450,  -450,  -450,  -450,   -76,  -230,  -450,
    -401,  -450,  -450,  -450,    40,  -450,  -450,  -449,  -450,  -450,
    -450,  -450,  -450,  -450,   345,   340,  -450,  -450,  -450,  -450,
    -450,  -450,  -450,   348,  -450,  -450,  -450,  -450,  -228,  -450,
    -450,  -450,  -450,  -450,  -450,  -450,  -232,  -450,  -368,  -450,
    -450,  -286,  -450,  -450,  -450,  -310,  -450,   168,  -450,  -436,
    -371,   165,  -191,  -450,  -450,   -92,  -450,  -450,   301,  -450,
    -450,  -450,  -450,  -450,  -450,  -450,  -298,  -240,  -239,  -450,
    -450,  -450,  -249,  -262,  -450,   153,   154,  -450,    37,  -450,
    -450,  -450,  -223,  -450,  -165,  -123,  -450,  -135,   -13,  -218
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,     2,     4,     6,    41,    44,    45,    46,    73,
      78,    83,   114,   118,   123,    47,    48,    49,   104,   105,
      50,   106,    51,   107,    52,    53,   109,   108,   137,   192,
     139,   140,   175,   194,   141,   193,    54,   142,   143,   178,
     200,   201,   202,   203,   235,   204,   236,   205,   271,   272,
      55,   207,   274,   478,   479,   381,   431,   516,   566,   549,
     569,   550,   572,   243,   244,   310,   315,   424,   316,   472,
     473,   474,   261,   360,   356,   456,   359,   496,   509,   560,
     312,   419,   463,   418,   313,   467,   468,   510,   565,   577,
     564,     7,   148,   183,   184,   185,   186,   246,   187,   247,
     278,   389,   382,   188,   189,   219,   351,   350,   249,   345,
     346,   347,   348,   344,   394,   589,   250,   349,   387,   484,
     439,   363,   500,   364,   462,   401,   525,   402,   482,   398,
     432,   340,   227,   300,   228,   131,   191,   132,   151,   190,
     222,   297,   232,     9,    13,    14,   302,   303,   268,   287,
     288,   289,   290,   375,   379,   422,   423,   428,   307,   295,
     296,   233,   223,   253,   169,   291,   339,   365,   172,   229
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      37,    38,   230,   171,   263,   234,   262,   259,   285,   286,
     256,   305,   170,   372,   338,   134,   407,   465,   440,   511,
     438,   304,   366,   367,   198,   224,   504,   179,    62,   138,
     298,   174,    63,   197,   198,     3,   337,    58,    59,    60,
      61,   403,     5,    87,    57,    58,    59,    60,    61,   110,
     111,   112,   378,    80,    85,    59,    62,   343,   226,   199,
      63,     8,   374,    59,    62,    61,   342,    64,    63,   199,
     150,   358,   373,    62,   353,   377,    10,    63,    59,    60,
      61,    62,   125,   265,   266,    63,    39,   125,   299,    60,
      61,   245,   264,   133,   133,    64,    62,   371,   376,   225,
      63,   269,   267,    64,   270,    40,    62,    11,    12,   355,
      63,   519,    64,   520,    42,   579,   393,   521,   395,   152,
      64,    67,   342,   458,   459,   460,   461,   263,   404,   262,
     581,   180,   354,    57,    43,    64,    65,   562,    59,    60,
     491,   492,   493,   494,   597,    64,    56,    60,    67,    61,
     208,   209,   210,    67,   275,   531,    62,    66,    67,    68,
      63,   208,   209,   210,    62,    62,   443,   444,    63,    63,
      76,    81,   499,   501,   502,   503,    70,    75,   133,    86,
     449,   524,   526,   527,   528,   301,   128,   264,    72,    67,
      77,   283,   371,    67,   116,    64,   264,   485,    67,   116,
     144,   385,   120,    64,    64,   445,   446,   378,   237,   238,
     539,   120,   265,   266,    82,   385,   385,   457,   113,    67,
      67,    67,   135,   136,   263,   117,   497,   413,   209,   210,
     122,   267,   138,   133,   149,   263,   263,   276,   277,   293,
     294,   368,   369,   153,   512,   513,   514,   173,   433,   248,
     392,   260,   406,   420,   421,   181,   529,   429,   430,   541,
     177,   522,   523,   435,   196,   433,   263,   206,   262,   540,
     211,   341,    74,    79,    84,   507,   213,   248,   442,   311,
     464,   469,   470,   476,   477,   214,   449,   371,   376,   567,
     568,   226,   570,   571,   573,   574,   115,   119,   508,   578,
     216,   115,   124,   308,   309,   218,   119,   124,   231,   239,
     199,   563,   210,   242,   435,   385,   385,   385,   385,   248,
     251,   252,   254,   257,   321,   322,   323,   341,   263,   258,
     575,   260,   263,   273,   292,   311,   306,   145,   314,   269,
     317,   146,   318,  -294,   319,   263,   147,   497,   594,   320,
     590,   357,   388,   427,   386,   396,   385,   385,   385,   385,
     279,   263,   598,   449,   391,   397,   324,   325,   326,   327,
     328,   329,   330,   331,   332,   333,   334,   405,   408,   335,
     414,   434,   415,   416,   436,   448,   437,    69,   441,   586,
     454,   477,   466,    15,    16,    17,   336,   455,   483,   486,
     488,   489,   490,   495,   371,   498,   505,   508,   154,   155,
     156,   515,   517,   518,    71,   530,   475,   532,   533,   481,
     534,   535,   537,   538,   542,   543,   544,   481,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,   545,   546,    36,   548,
     157,   158,   159,   160,   161,   162,   163,   164,   553,   220,
     167,   580,   409,   168,   554,   555,   410,   411,   412,   556,
     557,   558,   559,    15,    16,    17,   352,   561,   576,   588,
     126,   592,   593,   596,   599,   600,   601,   182,   121,   127,
     130,   448,   240,   195,   241,   380,   176,   583,   370,   471,
     417,   585,   547,   506,   384,   390,   481,   481,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,   215,   212,    36,   255,
       0,   425,   426,     0,     0,   217,     0,     0,     0,     0,
       0,     0,   450,   154,   155,   156,   451,   452,   453,     0,
       0,     0,     0,     0,   582,     0,     0,   584,     0,     0,
       0,   154,   155,   156,     0,     0,     0,     0,   448,     0,
       0,   591,     0,     0,     0,     0,   595,     0,     0,   279,
     264,   280,   281,   282,   283,   157,   158,   159,   160,   161,
     162,   163,   164,   165,   166,   167,     0,     0,   168,    15,
      16,    17,     0,   157,   158,   159,   160,   161,   162,   163,
     164,     0,   220,   167,     0,   284,   168,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   221,     0,
       0,     0,     0,     0,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,     0,     0,    36,    15,    16,    17,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   150,    88,
      89,    90,    91,    92,    93,    94,    95,    96,    97,    98,
      99,   100,   101,   102,     0,     0,     0,     0,     0,     0,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,     0,     0,
      36,     0,   226,    15,    16,    17,     0,     0,     0,     0,
       0,   103,     0,   447,     0,     0,     0,     0,     0,   129,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   154,   155,   156,     0,     0,     0,     0,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,     0,     0,    36,     0,
     226,    15,    16,    17,     0,     0,   301,   279,   264,     0,
       0,   536,   283,   157,   158,   159,   160,   161,   162,   163,
     164,   165,   166,   167,     0,     0,   168,     0,   154,   155,
     156,     0,     0,     0,     0,     0,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,     0,     0,    36,     0,   226,    15,
      16,    17,     0,     0,   279,   264,     0,     0,     0,   587,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     167,     0,     0,   168,     0,     0,   154,   155,   156,     0,
       0,     0,     0,     0,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,     0,     0,    36,    15,    16,    17,     0,     0,
       0,     0,   279,     0,     0,     0,     0,   480,   157,   158,
     159,   160,   161,   162,   163,   164,   165,   166,   167,     0,
       0,   168,   154,   155,   156,     0,     0,     0,     0,     0,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,     0,     0,
      36,    15,    16,    17,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   487,   157,   158,   159,   160,   161,   162,
     163,   164,   165,   166,   167,     0,     0,   168,   154,   155,
     156,     0,     0,     0,     0,     0,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,     0,     0,    36,    15,    16,    17,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   551,
     157,   158,   159,   160,   161,   162,   163,   164,     0,   220,
     167,     0,     0,   168,     0,     0,     0,     0,     0,     0,
       0,     0,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
       0,     0,    36,    15,    16,    17,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   552,    88,    89,    90,    91,
      92,    93,    94,    95,    96,    97,    98,    99,   100,   101,
     102,     0,     0,     0,     0,     0,     0,     0,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,     0,     0,    36,     0,
       0,   361,    15,    16,    17,     0,     0,     0,   103,     0,
     362,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,     0,     0,    36,     0,     0,
     399,    15,    16,    17,     0,     0,     0,     0,     0,   400,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,     0,     0,    36,    15,    16,    17,
       0,     0,     0,     0,     0,     0,     0,     0,   383,     0,
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
      13,    14,   193,   138,   236,   196,   236,   235,   248,   248,
     228,   260,   135,   311,   276,   107,   359,   418,   389,   468,
     388,   260,   308,   309,    29,   190,   462,   143,    26,    70,
     253,    72,    30,    28,    29,     0,   276,     7,     8,     9,
      10,   351,    70,    56,     6,     7,     8,     9,    10,    62,
      63,    64,   314,    52,    53,     8,    26,   285,    60,    64,
      30,     3,   311,     8,    26,    10,   284,    65,    30,    64,
      72,   303,   311,    26,   297,   314,    70,    30,     8,     9,
      10,    26,    81,    56,    57,    30,    71,    86,   253,     9,
      10,   207,    40,   106,   107,    65,    26,    45,    46,   191,
      30,    29,    75,    65,    32,    71,    26,     4,     5,   300,
      30,   482,    65,   484,    70,   564,   344,   485,   346,   132,
      65,    47,   340,   409,   410,   411,   412,   359,   356,   359,
     566,   144,   297,     6,    70,    65,    71,   538,     8,     9,
     450,   451,   452,   453,   593,    65,    33,     9,    74,    10,
      34,    35,    36,    79,   246,   498,    26,    70,    84,    70,
      30,    34,    35,    36,    26,    26,   394,   395,    30,    30,
      51,    52,   458,   459,   460,   461,    70,    51,   191,    53,
     398,   491,   492,   493,   494,    38,    71,    40,    70,   115,
      70,    44,    45,   119,    75,    65,    40,   437,   124,    80,
      69,   336,    76,    65,    65,   396,   397,   469,    73,    74,
     508,    85,    56,    57,    70,   350,   351,   408,    70,   145,
     146,   147,    70,    71,   456,    70,   456,   362,    35,    36,
      70,    75,    70,   246,    71,   467,   468,    70,    71,    50,
      51,    70,    71,    71,   472,   473,   474,    71,   383,    70,
      71,    70,    71,    47,    48,    70,   495,    70,    71,   508,
      27,   489,   490,   386,    70,   400,   498,    31,   498,   508,
      70,   284,    51,    52,    53,   466,    71,    70,    71,    70,
      71,    70,    71,    67,    68,    70,   504,    45,    46,    70,
      71,    60,    70,    71,    70,    71,    75,    76,    70,    71,
      70,    80,    81,   266,   267,    70,    85,    86,    53,    71,
      64,   539,    36,    70,   437,   450,   451,   452,   453,    70,
      37,    55,    71,    71,     3,     4,     5,   340,   560,    71,
     560,    70,   564,    66,    71,    70,    59,   116,    70,    29,
      71,   120,    70,    61,    71,   577,   125,   577,   588,    71,
     582,    70,    61,    49,    70,    70,   491,   492,   493,   494,
      39,   593,   594,   581,    71,    70,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    71,    70,    58,
      71,    61,    71,    71,    71,   398,    70,    49,    71,   580,
      71,    68,    70,     3,     4,     5,    75,    71,    71,    71,
      71,    71,    71,    70,    45,    71,    70,    70,     3,     4,
       5,    70,    70,    70,    50,    71,   429,    71,    71,   432,
      71,    71,    71,    71,    71,    71,    71,   440,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    71,    71,    58,    71,
      45,    46,    47,    48,    49,    50,    51,    52,    71,    54,
      55,    70,    72,    58,    71,    71,    76,    77,    78,    71,
      71,    71,    71,     3,     4,     5,    71,    71,    71,    70,
      85,    71,    71,    71,    71,    71,    71,   148,    80,    86,
     104,   504,   203,   175,   204,   315,   140,   568,   310,   424,
     372,   577,   515,   463,   336,   340,   519,   520,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,   186,   182,    58,   228,
      -1,   378,   378,    -1,    -1,   187,    -1,    -1,    -1,    -1,
      -1,    -1,    72,     3,     4,     5,    76,    77,    78,    -1,
      -1,    -1,    -1,    -1,   567,    -1,    -1,   570,    -1,    -1,
      -1,     3,     4,     5,    -1,    -1,    -1,    -1,   581,    -1,
      -1,   584,    -1,    -1,    -1,    -1,   589,    -1,    -1,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    -1,    -1,    58,     3,
       4,     5,    -1,    45,    46,    47,    48,    49,    50,    51,
      52,    -1,    54,    55,    -1,    75,    58,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    70,    -1,
      -1,    -1,    -1,    -1,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    -1,    -1,    58,     3,     4,     5,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    72,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    -1,    -1,    -1,    -1,    -1,    -1,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    -1,    -1,
      58,    -1,    60,     3,     4,     5,    -1,    -1,    -1,    -1,
      -1,    63,    -1,    71,    -1,    -1,    -1,    -1,    -1,    71,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,     3,     4,     5,    -1,    -1,    -1,    -1,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    -1,    -1,    58,    -1,
      60,     3,     4,     5,    -1,    -1,    38,    39,    40,    -1,
      -1,    71,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    -1,    -1,    58,    -1,     3,     4,
       5,    -1,    -1,    -1,    -1,    -1,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    -1,    -1,    58,    -1,    60,     3,
       4,     5,    -1,    -1,    39,    40,    -1,    -1,    -1,    71,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    -1,    -1,    58,    -1,    -1,     3,     4,     5,    -1,
      -1,    -1,    -1,    -1,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    -1,    -1,    58,     3,     4,     5,    -1,    -1,
      -1,    -1,    39,    -1,    -1,    -1,    -1,    71,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    -1,
      -1,    58,     3,     4,     5,    -1,    -1,    -1,    -1,    -1,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    -1,    -1,
      58,     3,     4,     5,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    71,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    -1,    -1,    58,     3,     4,
       5,    -1,    -1,    -1,    -1,    -1,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    -1,    -1,    58,     3,     4,     5,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    71,
      45,    46,    47,    48,    49,    50,    51,    52,    -1,    54,
      55,    -1,    -1,    58,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      -1,    -1,    58,     3,     4,     5,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    71,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    -1,    -1,    58,    -1,
      -1,    61,     3,     4,     5,    -1,    -1,    -1,    63,    -1,
      70,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    -1,    -1,    58,    -1,    -1,
      61,     3,     4,     5,    -1,    -1,    -1,    -1,    -1,    70,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    -1,    -1,    58,     3,     4,     5,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    70,    -1,
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
       0,    80,    81,     0,    82,    70,    83,   170,     3,   222,
      70,     4,     5,   223,   224,     3,     4,     5,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    58,   247,   247,    71,
      71,    84,    70,    70,    85,    86,    87,    94,    95,    96,
      99,   101,   103,   104,   115,   129,    33,     6,     7,     8,
       9,    10,    26,    30,    65,    71,    70,    95,    70,    86,
      70,    87,    70,    88,    94,   103,   104,    70,    89,    94,
     101,   104,    70,    90,    94,   101,   103,   247,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    63,    97,    98,   100,   102,   106,   105,
     247,   247,   247,    70,    91,    94,   104,    70,    92,    94,
     103,    91,    70,    93,    94,   101,    92,    93,    71,    71,
      98,   214,   216,   247,   214,    70,    71,   107,    70,   109,
     110,   113,   116,   117,    69,    94,    94,    94,   171,    71,
      72,   217,   247,    71,     3,     4,     5,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    58,   243,
     244,   246,   247,    71,    72,   111,   113,    27,   118,   118,
     247,    70,    96,   172,   173,   174,   175,   177,   182,   183,
     218,   215,   108,   114,   112,   109,    70,    28,    29,    64,
     119,   120,   121,   122,   124,   126,    31,   130,    34,    35,
      36,    70,   173,    71,    70,   174,    70,   182,    70,   184,
      54,    70,   219,   241,   243,   214,    60,   211,   213,   248,
     211,    53,   221,   240,   211,   123,   125,    73,    74,    71,
     120,   121,    70,   142,   143,   118,   176,   178,    70,   187,
     195,    37,    55,   242,    71,   217,   248,    71,    71,   187,
      70,   151,   157,   195,    40,    56,    57,    75,   227,    29,
      32,   127,   128,    66,   131,   214,    70,    71,   179,    39,
      41,    42,    43,    44,    75,   226,   227,   228,   229,   230,
     231,   244,    71,    50,    51,   238,   239,   220,   241,   243,
     212,    38,   225,   226,   227,   231,    59,   237,   237,   237,
     144,    70,   159,   163,    70,   145,   147,    71,    70,    71,
      71,     3,     4,     5,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    58,    75,   226,   232,   245,
     210,   247,   248,   187,   192,   188,   189,   190,   191,   196,
     186,   185,    71,   241,   243,   211,   153,    70,   195,   155,
     152,    61,    70,   200,   202,   246,   200,   200,    70,    71,
     143,    45,   225,   227,   231,   232,    46,   227,   232,   233,
     128,   134,   181,    70,   206,   246,    70,   197,    61,   180,
     210,    71,    71,   187,   193,   187,    70,    70,   208,    61,
      70,   204,   206,   204,   187,    71,    71,   151,    70,    72,
      76,    77,    78,   246,    71,    71,    71,   145,   162,   160,
      47,    48,   234,   235,   146,   234,   235,    49,   236,    70,
      71,   135,   209,   246,    61,   244,    71,    70,   197,   199,
     209,    71,    71,   187,   187,   211,   211,    71,   247,   248,
      72,    76,    77,    78,    71,    71,   154,   211,   200,   200,
     200,   200,   203,   161,    71,   159,    70,   164,   165,    70,
      71,   147,   148,   149,   150,   247,    67,    68,   132,   133,
      71,   247,   207,    71,   198,   226,    71,    71,    71,    71,
      71,   204,   204,   204,   204,    70,   156,   157,    71,   200,
     201,   200,   200,   200,   208,    70,   163,   211,    70,   157,
     166,   166,   187,   187,   187,    70,   136,    70,    70,   209,
     209,   197,   187,   187,   204,   205,   204,   204,   204,   227,
      71,   151,    71,    71,    71,    71,    71,    71,    71,   225,
     227,   231,    71,    71,    71,    71,    71,   247,    71,   138,
     140,    71,    71,    71,    71,    71,    71,    71,    71,    71,
     158,    71,   159,   187,   169,   167,   137,    70,    71,   139,
      70,    71,   141,    70,    71,   157,    71,   168,    71,   166,
      70,   208,   247,   133,   247,   156,   211,    71,    70,   194,
     195,   247,    71,    71,   226,   247,    71,   166,   195,    71,
      71,    71
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
     187,   192,   192,   193,   193,   194,   194,   196,   195,   198,
     197,   199,   199,   200,   200,   200,   200,   200,   200,   201,
     201,   203,   202,   202,   204,   204,   204,   204,   204,   204,
     205,   205,   207,   206,   206,   208,   208,   208,   209,   209,
     210,   210,   211,   211,   212,   211,   213,   213,   214,   214,
     215,   214,   216,   216,   218,   217,   219,   219,   219,   220,
     220,   220,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   243,   243,   243,   243,
     243,   243,   243,   243,   243,   243,   243,   243,   244,   244,
     244,   245,   245,   245,   245,   245,   245,   245,   245,   245,
     245,   245,   245,   245,   245,   246,   247,   247,   247,   247,
     247,   247,   247,   247,   247,   247,   247,   247,   247,   247,
     247,   247,   247,   247,   247,   247,   247,   247,   248
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
       0,     2,     0,     9,     5,     5,     1,     0,     4,     0,
       2,     4,     0,     5,     0,     2,     5,     0,     2,     4,
       1,     4,     5,     5,     5,     0,     2,     1,     4,     0,
       2,     0,     6,     0,     6,     0,     6,     1,     4,     0,
       8,     0,     0,     7,     0,     2,     1,     4,     1,     4,
       0,     2,     1,     4,     0,     8,     0,     6,     0,     2,
       0,     6,     0,     6,     1,     4,     0,     8,     0,     6,
       0,     2,     0,    13,     2,     1,     2,     1,     2,     1,
       0,     5,     4,     0,     2,     0,     5,     0,     5,     4,
       5,     5,     1,     2,     4,     0,     6,     0,     6,     1,
       5,     4,     4,     0,     5,     0,     6,     0,     8,     0,
       8,     0,     2,     0,     2,     1,     4,     0,     5,     0,
       5,     1,     4,     1,     5,     5,     5,     5,     1,     0,
       1,     0,     5,     1,     1,     5,     5,     5,     5,     1,
       0,     1,     0,     5,     1,     0,     2,     2,     0,     2,
       1,     1,     0,     1,     0,     4,     1,     2,     0,     1,
       0,     4,     1,     2,     0,     3,     1,     1,     4,     1,
       1,     2,     2,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1
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
#line 415 "pddl.yy" /* yacc.c:1646  */
    { success = true; line_number = 1; }
#line 2243 "pddl.cc" /* yacc.c:1646  */
    break;

  case 3:
#line 416 "pddl.yy" /* yacc.c:1646  */
    { if (!success) YYERROR; }
#line 2249 "pddl.cc" /* yacc.c:1646  */
    break;

  case 7:
#line 428 "pddl.yy" /* yacc.c:1646  */
    { make_domain((yyvsp[-1].str)); }
#line 2255 "pddl.cc" /* yacc.c:1646  */
    break;

  case 54:
#line 503 "pddl.yy" /* yacc.c:1646  */
    { requirements->strips = true; }
#line 2261 "pddl.cc" /* yacc.c:1646  */
    break;

  case 55:
#line 504 "pddl.yy" /* yacc.c:1646  */
    { requirements->typing = true; }
#line 2267 "pddl.cc" /* yacc.c:1646  */
    break;

  case 56:
#line 506 "pddl.yy" /* yacc.c:1646  */
    { requirements->negative_preconditions = true; }
#line 2273 "pddl.cc" /* yacc.c:1646  */
    break;

  case 57:
#line 508 "pddl.yy" /* yacc.c:1646  */
    { requirements->disjunctive_preconditions = true; }
#line 2279 "pddl.cc" /* yacc.c:1646  */
    break;

  case 58:
#line 509 "pddl.yy" /* yacc.c:1646  */
    { requirements->equality = true; }
#line 2285 "pddl.cc" /* yacc.c:1646  */
    break;

  case 59:
#line 511 "pddl.yy" /* yacc.c:1646  */
    { requirements->existential_preconditions = true; }
#line 2291 "pddl.cc" /* yacc.c:1646  */
    break;

  case 60:
#line 513 "pddl.yy" /* yacc.c:1646  */
    { requirements->universal_preconditions = true; }
#line 2297 "pddl.cc" /* yacc.c:1646  */
    break;

  case 61:
#line 515 "pddl.yy" /* yacc.c:1646  */
    { requirements->quantified_preconditions(); }
#line 2303 "pddl.cc" /* yacc.c:1646  */
    break;

  case 62:
#line 516 "pddl.yy" /* yacc.c:1646  */
    { requirements->conditional_effects = true; }
#line 2309 "pddl.cc" /* yacc.c:1646  */
    break;

  case 63:
#line 517 "pddl.yy" /* yacc.c:1646  */
    { requirements->fluents = true; }
#line 2315 "pddl.cc" /* yacc.c:1646  */
    break;

  case 64:
#line 518 "pddl.yy" /* yacc.c:1646  */
    { requirements->adl(); }
#line 2321 "pddl.cc" /* yacc.c:1646  */
    break;

  case 65:
#line 519 "pddl.yy" /* yacc.c:1646  */
    { requirements->durative_actions = true; }
#line 2327 "pddl.cc" /* yacc.c:1646  */
    break;

  case 66:
#line 521 "pddl.yy" /* yacc.c:1646  */
    { requirements->duration_inequalities = true; }
#line 2333 "pddl.cc" /* yacc.c:1646  */
    break;

  case 67:
#line 523 "pddl.yy" /* yacc.c:1646  */
    { yyerror("`:continuous-effects' not supported"); }
#line 2339 "pddl.cc" /* yacc.c:1646  */
    break;

  case 68:
#line 525 "pddl.yy" /* yacc.c:1646  */
    {
                    requirements->durative_actions = true;
                    requirements->timed_initial_literals = true;
                }
#line 2348 "pddl.cc" /* yacc.c:1646  */
    break;

  case 69:
#line 529 "pddl.yy" /* yacc.c:1646  */
    { requirements->decompositions = true; }
#line 2354 "pddl.cc" /* yacc.c:1646  */
    break;

  case 70:
#line 532 "pddl.yy" /* yacc.c:1646  */
    { require_typing(); name_kind = TYPE_KIND; }
#line 2360 "pddl.cc" /* yacc.c:1646  */
    break;

  case 71:
#line 533 "pddl.yy" /* yacc.c:1646  */
    { name_kind = VOID_KIND; }
#line 2366 "pddl.cc" /* yacc.c:1646  */
    break;

  case 72:
#line 536 "pddl.yy" /* yacc.c:1646  */
    { name_kind = CONSTANT_KIND; }
#line 2372 "pddl.cc" /* yacc.c:1646  */
    break;

  case 73:
#line 537 "pddl.yy" /* yacc.c:1646  */
    { name_kind = VOID_KIND; }
#line 2378 "pddl.cc" /* yacc.c:1646  */
    break;

  case 75:
#line 543 "pddl.yy" /* yacc.c:1646  */
    { require_fluents(); }
#line 2384 "pddl.cc" /* yacc.c:1646  */
    break;

  case 79:
#line 554 "pddl.yy" /* yacc.c:1646  */
    { make_predicate((yyvsp[0].str)); }
#line 2390 "pddl.cc" /* yacc.c:1646  */
    break;

  case 80:
#line 555 "pddl.yy" /* yacc.c:1646  */
    { predicate = 0; }
#line 2396 "pddl.cc" /* yacc.c:1646  */
    break;

  case 86:
#line 567 "pddl.yy" /* yacc.c:1646  */
    { require_typing(); }
#line 2402 "pddl.cc" /* yacc.c:1646  */
    break;

  case 88:
#line 570 "pddl.yy" /* yacc.c:1646  */
    { make_function((yyvsp[0].str)); }
#line 2408 "pddl.cc" /* yacc.c:1646  */
    break;

  case 89:
#line 571 "pddl.yy" /* yacc.c:1646  */
    { function = 0; }
#line 2414 "pddl.cc" /* yacc.c:1646  */
    break;

  case 90:
#line 578 "pddl.yy" /* yacc.c:1646  */
    { make_action((yyvsp[0].str), false, false); }
#line 2420 "pddl.cc" /* yacc.c:1646  */
    break;

  case 91:
#line 578 "pddl.yy" /* yacc.c:1646  */
    { add_action(); }
#line 2426 "pddl.cc" /* yacc.c:1646  */
    break;

  case 92:
#line 579 "pddl.yy" /* yacc.c:1646  */
    { make_action((yyvsp[0].str), true, false); }
#line 2432 "pddl.cc" /* yacc.c:1646  */
    break;

  case 93:
#line 579 "pddl.yy" /* yacc.c:1646  */
    { add_action(); }
#line 2438 "pddl.cc" /* yacc.c:1646  */
    break;

  case 102:
#line 598 "pddl.yy" /* yacc.c:1646  */
    { formula_time = AT_START; }
#line 2444 "pddl.cc" /* yacc.c:1646  */
    break;

  case 103:
#line 598 "pddl.yy" /* yacc.c:1646  */
    { action->set_condition(*(yyvsp[0].formula)); }
#line 2450 "pddl.cc" /* yacc.c:1646  */
    break;

  case 104:
#line 601 "pddl.yy" /* yacc.c:1646  */
    { effect_time = Effect::AT_END; }
#line 2456 "pddl.cc" /* yacc.c:1646  */
    break;

  case 106:
#line 604 "pddl.yy" /* yacc.c:1646  */
    { require_decompositions(); action->set_composite(true); }
#line 2462 "pddl.cc" /* yacc.c:1646  */
    break;

  case 107:
#line 605 "pddl.yy" /* yacc.c:1646  */
    { require_decompositions(); action->set_composite(false); }
#line 2468 "pddl.cc" /* yacc.c:1646  */
    break;

  case 108:
#line 608 "pddl.yy" /* yacc.c:1646  */
    { action->set_condition(*(yyvsp[-1].formula)); }
#line 2474 "pddl.cc" /* yacc.c:1646  */
    break;

  case 112:
#line 621 "pddl.yy" /* yacc.c:1646  */
    { make_decomposition((yyvsp[-2].str), (yyvsp[0].str)); }
#line 2480 "pddl.cc" /* yacc.c:1646  */
    break;

  case 113:
#line 622 "pddl.yy" /* yacc.c:1646  */
    { add_decomposition(); decomposition_pseudo_steps.clear(); }
#line 2486 "pddl.cc" /* yacc.c:1646  */
    break;

  case 121:
#line 641 "pddl.yy" /* yacc.c:1646  */
    { decomposition_pseudo_steps.insert( std::make_pair(*(yyvsp[-2].str), (yyvsp[-1].step)) ); add_pseudo_step(*(yyvsp[-1].step)); }
#line 2492 "pddl.cc" /* yacc.c:1646  */
    break;

  case 122:
#line 644 "pddl.yy" /* yacc.c:1646  */
    { prepare_pseudostep((yyvsp[0].str)); }
#line 2498 "pddl.cc" /* yacc.c:1646  */
    break;

  case 123:
#line 645 "pddl.yy" /* yacc.c:1646  */
    { (yyval.step) = make_pseudostep(); }
#line 2504 "pddl.cc" /* yacc.c:1646  */
    break;

  case 125:
#line 649 "pddl.yy" /* yacc.c:1646  */
    { add_link(*(yyvsp[0].link)); }
#line 2510 "pddl.cc" /* yacc.c:1646  */
    break;

  case 126:
#line 652 "pddl.yy" /* yacc.c:1646  */
    { (yyval.link) = make_link((yyvsp[-3].str), *(yyvsp[-2].literal), (yyvsp[-1].str)); }
#line 2516 "pddl.cc" /* yacc.c:1646  */
    break;

  case 128:
#line 656 "pddl.yy" /* yacc.c:1646  */
    { add_ordering(*(yyvsp[0].ordering)); }
#line 2522 "pddl.cc" /* yacc.c:1646  */
    break;

  case 129:
#line 659 "pddl.yy" /* yacc.c:1646  */
    { (yyval.ordering) = make_ordering((yyvsp[-2].str), (yyvsp[-1].str)); }
#line 2528 "pddl.cc" /* yacc.c:1646  */
    break;

  case 131:
#line 666 "pddl.yy" /* yacc.c:1646  */
    { require_duration_inequalities(); }
#line 2534 "pddl.cc" /* yacc.c:1646  */
    break;

  case 132:
#line 669 "pddl.yy" /* yacc.c:1646  */
    { require_duration_inequalities(); action->set_max_duration(*(yyvsp[-1].expr)); }
#line 2540 "pddl.cc" /* yacc.c:1646  */
    break;

  case 133:
#line 670 "pddl.yy" /* yacc.c:1646  */
    { require_duration_inequalities(); action->set_min_duration(*(yyvsp[-1].expr)); }
#line 2546 "pddl.cc" /* yacc.c:1646  */
    break;

  case 134:
#line 671 "pddl.yy" /* yacc.c:1646  */
    { action->set_duration(*(yyvsp[-1].expr)); }
#line 2552 "pddl.cc" /* yacc.c:1646  */
    break;

  case 138:
#line 684 "pddl.yy" /* yacc.c:1646  */
    { (yyval.formula) = (yyvsp[-1].formula); }
#line 2558 "pddl.cc" /* yacc.c:1646  */
    break;

  case 139:
#line 687 "pddl.yy" /* yacc.c:1646  */
    { (yyval.formula) = &Formula::TRUE; }
#line 2564 "pddl.cc" /* yacc.c:1646  */
    break;

  case 140:
#line 688 "pddl.yy" /* yacc.c:1646  */
    { (yyval.formula) = &(*(yyvsp[-1].formula) && *(yyvsp[0].formula)); }
#line 2570 "pddl.cc" /* yacc.c:1646  */
    break;

  case 141:
#line 691 "pddl.yy" /* yacc.c:1646  */
    { formula_time = AT_START; }
#line 2576 "pddl.cc" /* yacc.c:1646  */
    break;

  case 142:
#line 691 "pddl.yy" /* yacc.c:1646  */
    { (yyval.formula) = (yyvsp[-1].formula); }
#line 2582 "pddl.cc" /* yacc.c:1646  */
    break;

  case 143:
#line 692 "pddl.yy" /* yacc.c:1646  */
    { formula_time = AT_END; }
#line 2588 "pddl.cc" /* yacc.c:1646  */
    break;

  case 144:
#line 692 "pddl.yy" /* yacc.c:1646  */
    { (yyval.formula) = (yyvsp[-1].formula); }
#line 2594 "pddl.cc" /* yacc.c:1646  */
    break;

  case 145:
#line 693 "pddl.yy" /* yacc.c:1646  */
    { formula_time = OVER_ALL; }
#line 2600 "pddl.cc" /* yacc.c:1646  */
    break;

  case 146:
#line 693 "pddl.yy" /* yacc.c:1646  */
    { (yyval.formula) = (yyvsp[-1].formula); }
#line 2606 "pddl.cc" /* yacc.c:1646  */
    break;

  case 149:
#line 702 "pddl.yy" /* yacc.c:1646  */
    { prepare_forall_effect(); }
#line 2612 "pddl.cc" /* yacc.c:1646  */
    break;

  case 150:
#line 702 "pddl.yy" /* yacc.c:1646  */
    { pop_forall_effect(); }
#line 2618 "pddl.cc" /* yacc.c:1646  */
    break;

  case 151:
#line 703 "pddl.yy" /* yacc.c:1646  */
    { formula_time = AT_START; }
#line 2624 "pddl.cc" /* yacc.c:1646  */
    break;

  case 152:
#line 703 "pddl.yy" /* yacc.c:1646  */
    { prepare_conditional_effect(*(yyvsp[0].formula)); }
#line 2630 "pddl.cc" /* yacc.c:1646  */
    break;

  case 153:
#line 703 "pddl.yy" /* yacc.c:1646  */
    { effect_condition = 0; }
#line 2636 "pddl.cc" /* yacc.c:1646  */
    break;

  case 158:
#line 714 "pddl.yy" /* yacc.c:1646  */
    { add_effect(*(yyvsp[0].atom)); }
#line 2642 "pddl.cc" /* yacc.c:1646  */
    break;

  case 159:
#line 715 "pddl.yy" /* yacc.c:1646  */
    { add_effect(Negation::make(*(yyvsp[-1].atom))); }
#line 2648 "pddl.cc" /* yacc.c:1646  */
    break;

  case 164:
#line 724 "pddl.yy" /* yacc.c:1646  */
    { prepare_forall_effect(); }
#line 2654 "pddl.cc" /* yacc.c:1646  */
    break;

  case 165:
#line 725 "pddl.yy" /* yacc.c:1646  */
    { pop_forall_effect(); }
#line 2660 "pddl.cc" /* yacc.c:1646  */
    break;

  case 166:
#line 726 "pddl.yy" /* yacc.c:1646  */
    { prepare_conditional_effect(*(yyvsp[0].formula)); }
#line 2666 "pddl.cc" /* yacc.c:1646  */
    break;

  case 167:
#line 727 "pddl.yy" /* yacc.c:1646  */
    { effect_condition = 0; }
#line 2672 "pddl.cc" /* yacc.c:1646  */
    break;

  case 170:
#line 735 "pddl.yy" /* yacc.c:1646  */
    { effect_time = Effect::AT_START; formula_time = AT_START; }
#line 2678 "pddl.cc" /* yacc.c:1646  */
    break;

  case 172:
#line 738 "pddl.yy" /* yacc.c:1646  */
    { effect_time = Effect::AT_END; formula_time = AT_END; }
#line 2684 "pddl.cc" /* yacc.c:1646  */
    break;

  case 176:
#line 744 "pddl.yy" /* yacc.c:1646  */
    { prepare_forall_effect(); }
#line 2690 "pddl.cc" /* yacc.c:1646  */
    break;

  case 177:
#line 745 "pddl.yy" /* yacc.c:1646  */
    { pop_forall_effect(); }
#line 2696 "pddl.cc" /* yacc.c:1646  */
    break;

  case 178:
#line 746 "pddl.yy" /* yacc.c:1646  */
    { prepare_conditional_effect(*(yyvsp[0].formula)); }
#line 2702 "pddl.cc" /* yacc.c:1646  */
    break;

  case 179:
#line 747 "pddl.yy" /* yacc.c:1646  */
    { effect_condition = 0; }
#line 2708 "pddl.cc" /* yacc.c:1646  */
    break;

  case 182:
#line 759 "pddl.yy" /* yacc.c:1646  */
    { make_problem((yyvsp[-5].str), (yyvsp[-1].str)); }
#line 2714 "pddl.cc" /* yacc.c:1646  */
    break;

  case 183:
#line 760 "pddl.yy" /* yacc.c:1646  */
    { delete requirements; }
#line 2720 "pddl.cc" /* yacc.c:1646  */
    break;

  case 190:
#line 775 "pddl.yy" /* yacc.c:1646  */
    { name_kind = OBJECT_KIND; }
#line 2726 "pddl.cc" /* yacc.c:1646  */
    break;

  case 191:
#line 776 "pddl.yy" /* yacc.c:1646  */
    { name_kind = VOID_KIND; }
#line 2732 "pddl.cc" /* yacc.c:1646  */
    break;

  case 195:
#line 786 "pddl.yy" /* yacc.c:1646  */
    { prepare_atom((yyvsp[0].str)); }
#line 2738 "pddl.cc" /* yacc.c:1646  */
    break;

  case 196:
#line 787 "pddl.yy" /* yacc.c:1646  */
    { problem->add_init_atom(*make_atom()); }
#line 2744 "pddl.cc" /* yacc.c:1646  */
    break;

  case 197:
#line 788 "pddl.yy" /* yacc.c:1646  */
    { prepare_atom((yyvsp[0].str)); }
#line 2750 "pddl.cc" /* yacc.c:1646  */
    break;

  case 198:
#line 789 "pddl.yy" /* yacc.c:1646  */
    { problem->add_init_atom(*make_atom()); }
#line 2756 "pddl.cc" /* yacc.c:1646  */
    break;

  case 199:
#line 791 "pddl.yy" /* yacc.c:1646  */
    { Formula::register_use((yyvsp[-1].atom)); Formula::unregister_use((yyvsp[-1].atom)); }
#line 2762 "pddl.cc" /* yacc.c:1646  */
    break;

  case 200:
#line 793 "pddl.yy" /* yacc.c:1646  */
    { problem->add_init_value(*(yyvsp[-2].fluent), (yyvsp[-1].num)); }
#line 2768 "pddl.cc" /* yacc.c:1646  */
    break;

  case 201:
#line 795 "pddl.yy" /* yacc.c:1646  */
    { add_init_literal((yyvsp[-2].num), *(yyvsp[-1].literal)); }
#line 2774 "pddl.cc" /* yacc.c:1646  */
    break;

  case 204:
#line 802 "pddl.yy" /* yacc.c:1646  */
    { problem->set_goal(*(yyvsp[-1].formula)); }
#line 2780 "pddl.cc" /* yacc.c:1646  */
    break;

  case 205:
#line 805 "pddl.yy" /* yacc.c:1646  */
    { metric_fluent = true; }
#line 2786 "pddl.cc" /* yacc.c:1646  */
    break;

  case 206:
#line 806 "pddl.yy" /* yacc.c:1646  */
    { problem->set_metric(*(yyvsp[-1].expr), true); metric_fluent = false; }
#line 2792 "pddl.cc" /* yacc.c:1646  */
    break;

  case 207:
#line 807 "pddl.yy" /* yacc.c:1646  */
    { metric_fluent = true; }
#line 2798 "pddl.cc" /* yacc.c:1646  */
    break;

  case 208:
#line 808 "pddl.yy" /* yacc.c:1646  */
    { problem->set_metric(*(yyvsp[-1].expr)); metric_fluent = false; }
#line 2804 "pddl.cc" /* yacc.c:1646  */
    break;

  case 209:
#line 815 "pddl.yy" /* yacc.c:1646  */
    { (yyval.formula) = &TimedLiteral::make(*(yyvsp[0].atom), formula_time); }
#line 2810 "pddl.cc" /* yacc.c:1646  */
    break;

  case 210:
#line 816 "pddl.yy" /* yacc.c:1646  */
    { (yyval.formula) = make_equality((yyvsp[-2].term), (yyvsp[-1].term)); }
#line 2816 "pddl.cc" /* yacc.c:1646  */
    break;

  case 211:
#line 817 "pddl.yy" /* yacc.c:1646  */
    { (yyval.formula) = make_negation(*(yyvsp[-1].formula)); }
#line 2822 "pddl.cc" /* yacc.c:1646  */
    break;

  case 212:
#line 818 "pddl.yy" /* yacc.c:1646  */
    { (yyval.formula) = (yyvsp[-1].formula); }
#line 2828 "pddl.cc" /* yacc.c:1646  */
    break;

  case 213:
#line 819 "pddl.yy" /* yacc.c:1646  */
    { require_disjunction(); }
#line 2834 "pddl.cc" /* yacc.c:1646  */
    break;

  case 214:
#line 819 "pddl.yy" /* yacc.c:1646  */
    { (yyval.formula) = (yyvsp[-1].formula); }
#line 2840 "pddl.cc" /* yacc.c:1646  */
    break;

  case 215:
#line 820 "pddl.yy" /* yacc.c:1646  */
    { require_disjunction(); }
#line 2846 "pddl.cc" /* yacc.c:1646  */
    break;

  case 216:
#line 820 "pddl.yy" /* yacc.c:1646  */
    { (yyval.formula) = &(!*(yyvsp[-2].formula) || *(yyvsp[-1].formula)); }
#line 2852 "pddl.cc" /* yacc.c:1646  */
    break;

  case 217:
#line 821 "pddl.yy" /* yacc.c:1646  */
    { prepare_exists(); }
#line 2858 "pddl.cc" /* yacc.c:1646  */
    break;

  case 218:
#line 821 "pddl.yy" /* yacc.c:1646  */
    { (yyval.formula) = make_exists(*(yyvsp[-1].formula)); }
#line 2864 "pddl.cc" /* yacc.c:1646  */
    break;

  case 219:
#line 822 "pddl.yy" /* yacc.c:1646  */
    { prepare_forall(); }
#line 2870 "pddl.cc" /* yacc.c:1646  */
    break;

  case 220:
#line 822 "pddl.yy" /* yacc.c:1646  */
    { (yyval.formula) = make_forall(*(yyvsp[-1].formula)); }
#line 2876 "pddl.cc" /* yacc.c:1646  */
    break;

  case 221:
#line 825 "pddl.yy" /* yacc.c:1646  */
    { (yyval.formula) = &Formula::TRUE; }
#line 2882 "pddl.cc" /* yacc.c:1646  */
    break;

  case 222:
#line 826 "pddl.yy" /* yacc.c:1646  */
    { (yyval.formula) = &(*(yyvsp[-1].formula) && *(yyvsp[0].formula)); }
#line 2888 "pddl.cc" /* yacc.c:1646  */
    break;

  case 223:
#line 829 "pddl.yy" /* yacc.c:1646  */
    { (yyval.formula) = &Formula::FALSE; }
#line 2894 "pddl.cc" /* yacc.c:1646  */
    break;

  case 224:
#line 830 "pddl.yy" /* yacc.c:1646  */
    { (yyval.formula) = &(*(yyvsp[-1].formula) || *(yyvsp[0].formula)); }
#line 2900 "pddl.cc" /* yacc.c:1646  */
    break;

  case 225:
#line 833 "pddl.yy" /* yacc.c:1646  */
    { (yyval.literal) = (yyvsp[0].atom); }
#line 2906 "pddl.cc" /* yacc.c:1646  */
    break;

  case 226:
#line 834 "pddl.yy" /* yacc.c:1646  */
    { (yyval.literal) = &Negation::make(*(yyvsp[-1].atom)); }
#line 2912 "pddl.cc" /* yacc.c:1646  */
    break;

  case 227:
#line 837 "pddl.yy" /* yacc.c:1646  */
    { prepare_atom((yyvsp[0].str)); }
#line 2918 "pddl.cc" /* yacc.c:1646  */
    break;

  case 228:
#line 837 "pddl.yy" /* yacc.c:1646  */
    { (yyval.atom) = make_atom(); }
#line 2924 "pddl.cc" /* yacc.c:1646  */
    break;

  case 229:
#line 840 "pddl.yy" /* yacc.c:1646  */
    { prepare_atom((yyvsp[0].str)); }
#line 2930 "pddl.cc" /* yacc.c:1646  */
    break;

  case 230:
#line 840 "pddl.yy" /* yacc.c:1646  */
    { (yyval.atom) = make_atom(); }
#line 2936 "pddl.cc" /* yacc.c:1646  */
    break;

  case 231:
#line 843 "pddl.yy" /* yacc.c:1646  */
    { (yyval.literal) = (yyvsp[0].atom); }
#line 2942 "pddl.cc" /* yacc.c:1646  */
    break;

  case 232:
#line 844 "pddl.yy" /* yacc.c:1646  */
    { (yyval.literal) = &Negation::make(*(yyvsp[-1].atom)); }
#line 2948 "pddl.cc" /* yacc.c:1646  */
    break;

  case 233:
#line 851 "pddl.yy" /* yacc.c:1646  */
    { (yyval.expr) = new Value((yyvsp[0].num)); }
#line 2954 "pddl.cc" /* yacc.c:1646  */
    break;

  case 234:
#line 852 "pddl.yy" /* yacc.c:1646  */
    { (yyval.expr) = &Addition::make(*(yyvsp[-2].expr), *(yyvsp[-1].expr)); }
#line 2960 "pddl.cc" /* yacc.c:1646  */
    break;

  case 235:
#line 853 "pddl.yy" /* yacc.c:1646  */
    { (yyval.expr) = make_subtraction(*(yyvsp[-2].expr), (yyvsp[-1].expr)); }
#line 2966 "pddl.cc" /* yacc.c:1646  */
    break;

  case 236:
#line 854 "pddl.yy" /* yacc.c:1646  */
    { (yyval.expr) = &Multiplication::make(*(yyvsp[-2].expr), *(yyvsp[-1].expr)); }
#line 2972 "pddl.cc" /* yacc.c:1646  */
    break;

  case 237:
#line 855 "pddl.yy" /* yacc.c:1646  */
    { (yyval.expr) = &Division::make(*(yyvsp[-2].expr), *(yyvsp[-1].expr)); }
#line 2978 "pddl.cc" /* yacc.c:1646  */
    break;

  case 238:
#line 856 "pddl.yy" /* yacc.c:1646  */
    { (yyval.expr) = (yyvsp[0].fluent); }
#line 2984 "pddl.cc" /* yacc.c:1646  */
    break;

  case 239:
#line 859 "pddl.yy" /* yacc.c:1646  */
    { (yyval.expr) = 0; }
#line 2990 "pddl.cc" /* yacc.c:1646  */
    break;

  case 241:
#line 863 "pddl.yy" /* yacc.c:1646  */
    { prepare_fluent((yyvsp[0].str)); }
#line 2996 "pddl.cc" /* yacc.c:1646  */
    break;

  case 242:
#line 864 "pddl.yy" /* yacc.c:1646  */
    { (yyval.fluent) = make_fluent(); }
#line 3002 "pddl.cc" /* yacc.c:1646  */
    break;

  case 243:
#line 865 "pddl.yy" /* yacc.c:1646  */
    { prepare_fluent((yyvsp[0].str)); (yyval.fluent) = make_fluent(); }
#line 3008 "pddl.cc" /* yacc.c:1646  */
    break;

  case 244:
#line 868 "pddl.yy" /* yacc.c:1646  */
    { (yyval.expr) = new Value((yyvsp[0].num)); }
#line 3014 "pddl.cc" /* yacc.c:1646  */
    break;

  case 245:
#line 870 "pddl.yy" /* yacc.c:1646  */
    { (yyval.expr) = &Addition::make(*(yyvsp[-2].expr), *(yyvsp[-1].expr)); }
#line 3020 "pddl.cc" /* yacc.c:1646  */
    break;

  case 246:
#line 872 "pddl.yy" /* yacc.c:1646  */
    { (yyval.expr) = make_subtraction(*(yyvsp[-2].expr), (yyvsp[-1].expr)); }
#line 3026 "pddl.cc" /* yacc.c:1646  */
    break;

  case 247:
#line 874 "pddl.yy" /* yacc.c:1646  */
    { (yyval.expr) = &Multiplication::make(*(yyvsp[-2].expr), *(yyvsp[-1].expr)); }
#line 3032 "pddl.cc" /* yacc.c:1646  */
    break;

  case 248:
#line 876 "pddl.yy" /* yacc.c:1646  */
    { (yyval.expr) = &Division::make(*(yyvsp[-2].expr), *(yyvsp[-1].expr)); }
#line 3038 "pddl.cc" /* yacc.c:1646  */
    break;

  case 249:
#line 877 "pddl.yy" /* yacc.c:1646  */
    { (yyval.expr) = (yyvsp[0].fluent); }
#line 3044 "pddl.cc" /* yacc.c:1646  */
    break;

  case 250:
#line 880 "pddl.yy" /* yacc.c:1646  */
    { (yyval.expr) = 0; }
#line 3050 "pddl.cc" /* yacc.c:1646  */
    break;

  case 252:
#line 884 "pddl.yy" /* yacc.c:1646  */
    { prepare_fluent((yyvsp[0].str)); }
#line 3056 "pddl.cc" /* yacc.c:1646  */
    break;

  case 253:
#line 885 "pddl.yy" /* yacc.c:1646  */
    { (yyval.fluent) = make_fluent(); }
#line 3062 "pddl.cc" /* yacc.c:1646  */
    break;

  case 254:
#line 886 "pddl.yy" /* yacc.c:1646  */
    { prepare_fluent((yyvsp[0].str)); (yyval.fluent) = make_fluent(); }
#line 3068 "pddl.cc" /* yacc.c:1646  */
    break;

  case 256:
#line 894 "pddl.yy" /* yacc.c:1646  */
    { add_term((yyvsp[0].str)); }
#line 3074 "pddl.cc" /* yacc.c:1646  */
    break;

  case 257:
#line 895 "pddl.yy" /* yacc.c:1646  */
    { add_term((yyvsp[0].str)); }
#line 3080 "pddl.cc" /* yacc.c:1646  */
    break;

  case 259:
#line 899 "pddl.yy" /* yacc.c:1646  */
    { add_term((yyvsp[0].str)); }
#line 3086 "pddl.cc" /* yacc.c:1646  */
    break;

  case 260:
#line 902 "pddl.yy" /* yacc.c:1646  */
    { (yyval.term) = new Term(make_term((yyvsp[0].str))); }
#line 3092 "pddl.cc" /* yacc.c:1646  */
    break;

  case 261:
#line 903 "pddl.yy" /* yacc.c:1646  */
    { (yyval.term) = new Term(make_term((yyvsp[0].str))); }
#line 3098 "pddl.cc" /* yacc.c:1646  */
    break;

  case 263:
#line 907 "pddl.yy" /* yacc.c:1646  */
    { add_variables((yyvsp[0].strs), TypeTable::OBJECT); }
#line 3104 "pddl.cc" /* yacc.c:1646  */
    break;

  case 264:
#line 908 "pddl.yy" /* yacc.c:1646  */
    { add_variables((yyvsp[-1].strs), *(yyvsp[0].type)); delete (yyvsp[0].type); }
#line 3110 "pddl.cc" /* yacc.c:1646  */
    break;

  case 266:
#line 912 "pddl.yy" /* yacc.c:1646  */
    { (yyval.strs) = new std::vector<const std::string*>(1, (yyvsp[0].str)); }
#line 3116 "pddl.cc" /* yacc.c:1646  */
    break;

  case 267:
#line 913 "pddl.yy" /* yacc.c:1646  */
    { (yyval.strs) = (yyvsp[-1].strs); (yyval.strs)->push_back((yyvsp[0].str)); }
#line 3122 "pddl.cc" /* yacc.c:1646  */
    break;

  case 269:
#line 917 "pddl.yy" /* yacc.c:1646  */
    { add_names((yyvsp[0].strs), TypeTable::OBJECT); }
#line 3128 "pddl.cc" /* yacc.c:1646  */
    break;

  case 270:
#line 918 "pddl.yy" /* yacc.c:1646  */
    { add_names((yyvsp[-1].strs), *(yyvsp[0].type)); delete (yyvsp[0].type); }
#line 3134 "pddl.cc" /* yacc.c:1646  */
    break;

  case 272:
#line 921 "pddl.yy" /* yacc.c:1646  */
    { (yyval.strs) = new std::vector<const std::string*>(1, (yyvsp[0].str)); }
#line 3140 "pddl.cc" /* yacc.c:1646  */
    break;

  case 273:
#line 922 "pddl.yy" /* yacc.c:1646  */
    { (yyval.strs) = (yyvsp[-1].strs); (yyval.strs)->push_back((yyvsp[0].str)); }
#line 3146 "pddl.cc" /* yacc.c:1646  */
    break;

  case 274:
#line 925 "pddl.yy" /* yacc.c:1646  */
    { require_typing(); }
#line 3152 "pddl.cc" /* yacc.c:1646  */
    break;

  case 275:
#line 925 "pddl.yy" /* yacc.c:1646  */
    { (yyval.type) = (yyvsp[0].type); }
#line 3158 "pddl.cc" /* yacc.c:1646  */
    break;

  case 276:
#line 928 "pddl.yy" /* yacc.c:1646  */
    { (yyval.type) = new Type(TypeTable::OBJECT); }
#line 3164 "pddl.cc" /* yacc.c:1646  */
    break;

  case 277:
#line 929 "pddl.yy" /* yacc.c:1646  */
    { (yyval.type) = new Type(make_type((yyvsp[0].str))); }
#line 3170 "pddl.cc" /* yacc.c:1646  */
    break;

  case 278:
#line 930 "pddl.yy" /* yacc.c:1646  */
    { (yyval.type) = new Type(make_type(*(yyvsp[-1].types))); delete (yyvsp[-1].types); }
#line 3176 "pddl.cc" /* yacc.c:1646  */
    break;

  case 279:
#line 933 "pddl.yy" /* yacc.c:1646  */
    { (yyval.types) = new TypeSet(); }
#line 3182 "pddl.cc" /* yacc.c:1646  */
    break;

  case 280:
#line 934 "pddl.yy" /* yacc.c:1646  */
    { (yyval.types) = new TypeSet(); (yyval.types)->insert(make_type((yyvsp[0].str))); }
#line 3188 "pddl.cc" /* yacc.c:1646  */
    break;

  case 281:
#line 935 "pddl.yy" /* yacc.c:1646  */
    { (yyval.types) = (yyvsp[-1].types); }
#line 3194 "pddl.cc" /* yacc.c:1646  */
    break;

  case 282:
#line 936 "pddl.yy" /* yacc.c:1646  */
    { (yyval.types) = (yyvsp[-1].types); (yyval.types)->insert(make_type((yyvsp[0].str))); }
#line 3200 "pddl.cc" /* yacc.c:1646  */
    break;

  case 284:
#line 946 "pddl.yy" /* yacc.c:1646  */
    { delete (yyvsp[0].str); }
#line 3206 "pddl.cc" /* yacc.c:1646  */
    break;

  case 285:
#line 949 "pddl.yy" /* yacc.c:1646  */
    { delete (yyvsp[0].str); }
#line 3212 "pddl.cc" /* yacc.c:1646  */
    break;

  case 286:
#line 952 "pddl.yy" /* yacc.c:1646  */
    { delete (yyvsp[0].str); }
#line 3218 "pddl.cc" /* yacc.c:1646  */
    break;

  case 287:
#line 955 "pddl.yy" /* yacc.c:1646  */
    { delete (yyvsp[0].str); }
#line 3224 "pddl.cc" /* yacc.c:1646  */
    break;

  case 288:
#line 958 "pddl.yy" /* yacc.c:1646  */
    { delete (yyvsp[0].str); }
#line 3230 "pddl.cc" /* yacc.c:1646  */
    break;

  case 289:
#line 961 "pddl.yy" /* yacc.c:1646  */
    { delete (yyvsp[0].str); }
#line 3236 "pddl.cc" /* yacc.c:1646  */
    break;

  case 290:
#line 964 "pddl.yy" /* yacc.c:1646  */
    { delete (yyvsp[0].str); }
#line 3242 "pddl.cc" /* yacc.c:1646  */
    break;

  case 291:
#line 967 "pddl.yy" /* yacc.c:1646  */
    { delete (yyvsp[0].str); }
#line 3248 "pddl.cc" /* yacc.c:1646  */
    break;

  case 292:
#line 970 "pddl.yy" /* yacc.c:1646  */
    { delete (yyvsp[0].str); }
#line 3254 "pddl.cc" /* yacc.c:1646  */
    break;

  case 293:
#line 973 "pddl.yy" /* yacc.c:1646  */
    { delete (yyvsp[0].str); }
#line 3260 "pddl.cc" /* yacc.c:1646  */
    break;

  case 294:
#line 976 "pddl.yy" /* yacc.c:1646  */
    { delete (yyvsp[0].str); }
#line 3266 "pddl.cc" /* yacc.c:1646  */
    break;

  case 295:
#line 979 "pddl.yy" /* yacc.c:1646  */
    { delete (yyvsp[0].str); }
#line 3272 "pddl.cc" /* yacc.c:1646  */
    break;

  case 296:
#line 982 "pddl.yy" /* yacc.c:1646  */
    { delete (yyvsp[0].str); }
#line 3278 "pddl.cc" /* yacc.c:1646  */
    break;

  case 297:
#line 985 "pddl.yy" /* yacc.c:1646  */
    { delete (yyvsp[0].str); }
#line 3284 "pddl.cc" /* yacc.c:1646  */
    break;

  case 298:
#line 988 "pddl.yy" /* yacc.c:1646  */
    { delete (yyvsp[0].str); }
#line 3290 "pddl.cc" /* yacc.c:1646  */
    break;

  case 299:
#line 991 "pddl.yy" /* yacc.c:1646  */
    { delete (yyvsp[0].str); }
#line 3296 "pddl.cc" /* yacc.c:1646  */
    break;

  case 300:
#line 994 "pddl.yy" /* yacc.c:1646  */
    { delete (yyvsp[0].str); }
#line 3302 "pddl.cc" /* yacc.c:1646  */
    break;

  case 301:
#line 997 "pddl.yy" /* yacc.c:1646  */
    { delete (yyvsp[0].str); }
#line 3308 "pddl.cc" /* yacc.c:1646  */
    break;

  case 302:
#line 1000 "pddl.yy" /* yacc.c:1646  */
    { delete (yyvsp[0].str); }
#line 3314 "pddl.cc" /* yacc.c:1646  */
    break;

  case 303:
#line 1003 "pddl.yy" /* yacc.c:1646  */
    { delete (yyvsp[0].str); }
#line 3320 "pddl.cc" /* yacc.c:1646  */
    break;

  case 304:
#line 1006 "pddl.yy" /* yacc.c:1646  */
    { delete (yyvsp[0].str); }
#line 3326 "pddl.cc" /* yacc.c:1646  */
    break;


#line 3330 "pddl.cc" /* yacc.c:1646  */
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
#line 1042 "pddl.yy" /* yacc.c:1906  */


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

/* Checks that each named pseudo-step exists, and returns a pair of respective references to 
   them if they do */
static std::pair<const Step*, const Step*> 
make_pseudo_step_pair(const std::string* pseudo_step_name1, const std::string* pseudo_step_name2)
{
    const Step* pseudo_step1;
    const Step* pseudo_step2;
    std::map<const std::string, const Step*>::const_iterator si;

    si = decomposition_pseudo_steps.find(*pseudo_step_name1);
    if (si == decomposition_pseudo_steps.end()) {
        yyerror("psuedo-step" + *pseudo_step_name1 + " referenced in decomposition "
            + decomposition->name() + " does not exist");
    }
    else {
        pseudo_step1 = (*si).second;
    }

    si = decomposition_pseudo_steps.find(*pseudo_step_name2);
    if (si == decomposition_pseudo_steps.end()) {
        yyerror("psuedo-step" + *pseudo_step_name2 + " referenced in decomposition "
            + decomposition->name() + " does not exist");
    }
    else {
        pseudo_step2 = (*si).second;
    }

    return std::make_pair(pseudo_step1, pseudo_step2);
}

/* Creates an ordering from pseudo-steps with the parameter names. */
static const Ordering* make_ordering(const std::string* pseudo_step_name1, const std::string* pseudo_step_name2)
{
    // Check that each decomposition pseudo-step exists, and store references to them if they do
    std::pair<const Step*, const Step*> pseudo_steps = 
        make_pseudo_step_pair(pseudo_step_name1, pseudo_step_name2);

    // Check that the names of the pseudo-steps are not the same. This check is done after 
    // verifying they exist, because it doesn't make sense to check before.
    if (*pseudo_step_name1 == *pseudo_step_name2) {
        yyerror("illegal ordering constraint (cannot order step " + *pseudo_step_name1 
            + " relative to itself in decomposition " + decomposition->name() + ")");
    }

    // Create ordering and return it. I assume that the ordering is constructed in between the end-points.
    return new Ordering(pseudo_steps.first->id(), StepTime::AT_END,
        pseudo_steps.second->id(), StepTime::AT_START);
}

/* Adds an ordering to the current decomposition. */
static void add_ordering(const Ordering& ordering)
{
    decomposition->add_ordering(ordering);
}

/* Returns a binding between the terms, or 0 if they cannot be bound. Two terms cannot be bound 
   if they are incompatible types or if they're both objects (neither one is a variable). */
static Binding* bind_terms(const Term& first, int first_id, const Term& second, int second_id)
{
    // Return zero if both terms are objects.
    if (first.object() && second.object()) {
        return 0;
    }

    else if (first.variable() && second.variable()) 
    {
        // Check for type compatibility.
        Type first_t = TermTable::type(first);
        Type second_t = TermTable::type(second);

        const Type* most_specific = TypeTable::most_specific(first_t, second_t);
        if (most_specific == 0) {
            return 0; // incompatible types
        }

        else
        {
            // The most specific Term will serve as Term for the binding.
            // The other will serve as a Variable.
            if (*most_specific == first_t) {
                return new Binding(first.as_variable(), first_id, second, second_id, true);
            }

            else {
                return new Binding(second.as_variable(), second_id, first, first_id, true);
            }
        }
    }

    else  
    {
        // Only one of them will be a variable (the other will be a term)
        Variable variable = first.variable() ? first.as_variable() : second.as_variable();
        Term term = first.variable() ? second : first;
 
        // Check for type compatibility; the term should be the most specific type, so
        // its type should be the subtype of the variable.
        Type variable_t = TermTable::type(variable);
        Type term_t = TermTable::type(term);

        if (! TypeTable::subtype(term_t, variable_t)) {
            return 0; // incompatible types
        }

        else 
        {
            // return the binding!
            return new Binding(variable, first.variable() ? first_id : second_id,
                               term, first.variable() ? second_id : first_id, true);
        }
    }
}


/* Creates a causal link between the pseudo-steps with the parameter names, 
   over the given literal. */
static const Link* make_link(const std::string* pseudo_step_name1, 
     const Literal& literal, const std::string* pseudo_step_name2)
{
    // Check that each decomposition pseudo-step exists, and store references to them if they do
    std::pair<const Step*, const Step*> pseudo_steps = 
        make_pseudo_step_pair(pseudo_step_name1, pseudo_step_name2);

    // Check that the names of the pseudo-steps are not the same. This check is done after 
    // verifying they exist, because it doesn't make sense to check before.
    if (*pseudo_step_name1 == *pseudo_step_name2) {
        yyerror("illegal causal link (cannot link step " + *pseudo_step_name1 
            + " to itself in decomposition " + decomposition->name() + ")");
    }

    // Check that the Literal exists as an effect of the first pseudo-step
    // If so, store the effect for the causal link
    const Effect* effect_match = 0;

    for (EffectList::const_iterator ei = pseudo_steps.first->action().effects().begin();
        ei != pseudo_steps.first->action().effects().end();
        ++ei)
    {
        const Literal* el = &(*ei)->literal();

        if (literal.predicate() == el->predicate() && literal.arity() == el->arity()) {
            effect_match = (*ei);
        }
    }

    if (effect_match == 0) 
    {
        yyerror("literal " + domain->predicates().name(literal.predicate()) +
            " not found as effect of pseudo-step" + pseudo_steps.first->action().name());
    }
    
    // Check that the Literal exists as a precondition of the second pseudo-step
    // If so, store the literal as an open precondition for the causal link
    const OpenCondition* op_match = 0;

    const Formula& pseudo_step_condition = pseudo_steps.second->action().condition();

    if (typeid(pseudo_step_condition) == typeid(Atom))
    {
        const Atom& atom = dynamic_cast<const Atom&>(pseudo_step_condition);
        if (atom.predicate() == literal.predicate() && atom.arity() == literal.arity()) {
            op_match = new OpenCondition(pseudo_steps.second->id(), atom);
        }        
    }

    else if (typeid(pseudo_step_condition) == typeid(Negation))
    {
        const Negation& negation = dynamic_cast<const Negation&>(pseudo_step_condition);
        if (negation.predicate() == literal.predicate() && negation.arity() == literal.arity()) {
            op_match = new OpenCondition(pseudo_steps.second->id(), negation);
        }
    }

    else if (typeid(pseudo_step_condition) == typeid(Conjunction))
    {
        // for each conjunct, check if it's an Atom or Negation; skip any other types
        const Conjunction& conj = dynamic_cast<const Conjunction&>(pseudo_step_condition);
        for (FormulaList::const_iterator fi = conj.conjuncts().begin();
            fi != conj.conjuncts().end();
            ++fi)
        {
            if (typeid(**fi) == typeid(Atom))
            {
                const Atom& atom = dynamic_cast<const Atom&>(**fi);
                if (atom.predicate() == literal.predicate() && atom.arity() == literal.arity()) {
                    op_match = new OpenCondition(pseudo_steps.second->id(), atom);
                }
            }

            else if (typeid(**fi) == typeid(Negation))
            {
                const Negation& negation = dynamic_cast<const Negation&>(**fi);
                if (negation.predicate() == literal.predicate() && negation.arity() == literal.arity()) {
                    op_match = new OpenCondition(pseudo_steps.second->id(), negation);
                }

            }

            else  {
                continue;
            }
        }
    }

    else
    {
        yywarning("unable to create causal link to precondition within " + pseudo_steps.second->action().name()
            + "; linked pseudo-step preconditions are limited to literals");
    }

    if (op_match == 0)
    {
        yyerror("literal " + domain->predicates().name(literal.predicate()) +
            " not found as a precondition of pseudo-step" + pseudo_steps.second->action().name());
    }

    const Link* link = new Link(pseudo_steps.first->id(), StepTime::AT_END, *op_match);


    // For each of the literal's terms, corresponding Bindings must be added to the decomposition.
    for (size_t i = 0; i < literal.arity(); ++i)
    {
        // Add a term binding between the terms of:
        // the effect of the first pseudo-step and
        // the precondition of the second pseudo-step
        Term effect_term = effect_match->literal().term(i);        
        Term precondition_term = op_match->literal()->term(i);

        Binding* new_binding = bind_terms(effect_term, pseudo_steps.first->id(),
            precondition_term, pseudo_steps.second->id());

        if (new_binding == 0) {
            yyerror("cannot create needed binding for causal link due to incompatibility of terms");
        }

        else {
            decomposition->add_binding(*new_binding);
        }
    }

    return link;
}

/* Adds a link to the current decomposition. */
static void add_link(const Link& link)
{
    decomposition->add_link(link);
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
static void add_effect(const Literal& literal) 
{
    PredicateTable::make_dynamic(literal.predicate());
    Effect* effect = new Effect(literal, effect_time);
    
    for (TermList::const_iterator vi = quantified.begin(); vi != quantified.end(); vi++) 
    {
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
