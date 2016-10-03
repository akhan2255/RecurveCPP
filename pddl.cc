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

/* Adds: :durative-actions to the requirements. */
static void require_durative_actions();

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

/* Registers the relevant dummy initial and final steps to the pseudo-steps of the current 
   decomposition. */
static void register_dummy_pseudo_steps();

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

#line 405 "pddl.cc" /* yacc.c:339  */

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
#line 382 "pddl.yy" /* yacc.c:355  */

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

#line 532 "pddl.cc" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_PDDL_HH_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 549 "pddl.cc" /* yacc.c:358  */

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
#define YYLAST   1282

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  79
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  171
/* YYNRULES -- Number of rules.  */
#define YYNRULES  359
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  603

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
       0,   422,   422,   422,   426,   427,   428,   435,   435,   439,
     440,   441,   442,   445,   446,   447,   450,   451,   452,   453,
     454,   455,   456,   459,   460,   461,   462,   463,   466,   467,
     468,   469,   470,   473,   474,   475,   476,   477,   480,   481,
     482,   485,   486,   487,   490,   491,   492,   495,   496,   499,
     500,   503,   506,   507,   510,   511,   512,   513,   514,   515,
     516,   517,   518,   519,   520,   521,   531,   532,   533,   538,
     550,   550,   554,   554,   558,   561,   561,   568,   569,   572,
     572,   576,   577,   578,   581,   582,   585,   585,   588,   588,
     596,   596,   597,   597,   601,   602,   605,   606,   609,   610,
     613,   614,   617,   617,   620,   620,   623,   624,   627,   628,
     631,   632,   640,   639,   644,   644,   648,   654,   658,   659,
     667,   668,   671,   674,   674,   678,   679,   682,   685,   686,
     689,   695,   696,   699,   700,   701,   704,   705,   713,   714,
     717,   718,   721,   721,   722,   722,   723,   723,   730,   731,
     732,   732,   733,   733,   733,   736,   737,   740,   741,   744,
     745,   748,   749,   752,   753,   754,   754,   756,   756,   760,
     761,   765,   764,   768,   767,   772,   773,   774,   774,   776,
     776,   780,   781,   789,   788,   793,   794,   797,   798,   801,
     802,   805,   805,   809,   812,   813,   816,   816,   818,   818,
     820,   822,   824,   828,   829,   832,   835,   835,   837,   837,
     845,   846,   847,   848,   849,   849,   850,   850,   851,   851,
     852,   852,   855,   856,   859,   860,   863,   864,   867,   867,
     870,   870,   873,   874,   881,   882,   883,   884,   885,   886,
     889,   890,   893,   893,   895,   898,   899,   901,   903,   905,
     907,   910,   911,   914,   914,   916,   923,   924,   925,   928,
     929,   932,   933,   936,   937,   938,   938,   942,   943,   946,
     947,   948,   948,   951,   952,   955,   955,   958,   959,   960,
     963,   964,   965,   966,   969,   976,   979,   982,   985,   988,
     991,   994,   997,  1000,  1003,  1006,  1009,  1012,  1015,  1018,
    1021,  1024,  1027,  1030,  1033,  1036,  1039,  1039,  1039,  1040,
    1041,  1041,  1041,  1041,  1041,  1042,  1042,  1042,  1043,  1046,
    1047,  1047,  1050,  1050,  1050,  1051,  1052,  1052,  1052,  1052,
    1053,  1053,  1053,  1054,  1055,  1055,  1058,  1061,  1061,  1061,
    1062,  1062,  1062,  1063,  1063,  1063,  1063,  1063,  1063,  1063,
    1064,  1064,  1064,  1064,  1064,  1065,  1065,  1065,  1066,  1069
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
  "$@14", "decomposition_body2", "decomposition_body3", "steps", "step",
  "pseudo_step", "$@15", "links", "link", "orderings", "ordering",
  "duration_constraint", "simple_duration_constraint",
  "simple_duration_constraints", "da_gd", "timed_gds", "timed_gd", "$@16",
  "$@17", "$@18", "eff_formula", "$@19", "$@20", "$@21", "eff_formulas",
  "one_eff_formula", "term_literal", "term_literals", "da_effect", "$@22",
  "$@23", "da_effects", "timed_effect", "$@24", "$@25", "a_effect", "$@26",
  "$@27", "a_effects", "problem_def", "$@28", "problem_body",
  "problem_body2", "problem_body3", "object_decl", "$@29", "init",
  "init_elements", "init_element", "$@30", "$@31", "goal_spec", "goal",
  "metric_spec", "$@32", "$@33", "formula", "$@34", "$@35", "$@36", "$@37",
  "conjuncts", "disjuncts", "term_formula", "atomic_term_formula", "$@38",
  "atomic_name_formula", "$@39", "name_literal", "f_exp", "opt_f_exp",
  "f_head", "$@40", "ground_f_exp", "opt_ground_f_exp", "ground_f_head",
  "$@41", "terms", "names", "term", "variables", "$@42", "variable_seq",
  "typed_names", "$@43", "name_seq", "type_spec", "$@44", "type", "types",
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

#define YYTABLE_NINF -296

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -450,    18,  -450,  -450,   -41,    34,  -450,  -450,  -450,   -16,
     177,  -450,  -450,  1224,  1224,  -450,  -450,  -450,  -450,  -450,
    -450,  -450,  -450,  -450,  -450,  -450,  -450,  -450,  -450,  -450,
    -450,  -450,  -450,  -450,  -450,  -450,  -450,    26,    28,  -450,
      11,    32,    82,    38,    47,  -450,  -450,    55,  -450,    64,
      84,    89,    96,    98,  -450,  -450,  1224,   864,  -450,  -450,
    -450,  -450,  1224,  1224,  1224,  -450,     1,  -450,   135,  -450,
     147,  -450,   137,  -450,    55,   106,   113,   154,  -450,    55,
     106,   119,    70,  -450,    55,   113,   119,   123,  -450,  -450,
    -450,  -450,  -450,  -450,  -450,  -450,  -450,  -450,  -450,  -450,
    -450,  -450,  -450,  -450,   427,  -450,  1224,  1224,   140,   129,
    -450,  -450,   149,   259,  -450,    55,    55,   166,  -450,    55,
      55,  -450,   171,  -450,    55,    55,  -450,  -450,  -450,  -450,
    -450,   133,   573,  -450,   145,   714,  -450,  -450,  1224,   153,
      88,  -450,   205,   205,  1224,    55,    55,    55,   169,  -450,
    -450,  -450,  -450,  -450,  -450,  -450,  -450,  -450,  -450,  -450,
    -450,  -450,  -450,  -450,  -450,  -450,  -450,  -450,  -450,  -450,
    -450,  -450,  -450,  -450,  -450,   129,  -450,   176,    10,   241,
    -450,    71,   196,   203,  -450,  -450,   206,   224,  -450,   238,
     252,  1224,   245,   245,   268,  -450,   245,  -450,  -450,   148,
     254,  -450,  -450,    -9,   267,  -450,   253,   205,  -450,  -450,
     274,    94,  -450,  -450,   192,  -450,   312,  -450,   319,  -450,
    -450,   303,  -450,  -450,  -450,  -450,  -450,   291,     3,  -450,
     299,  -450,  -450,  -450,   300,   274,   302,  -450,  -450,  -450,
    -450,  -450,   239,    72,  -450,   307,  1224,   174,   473,   304,
    -450,   209,  -450,   772,  -450,  -450,  -450,  -450,  -450,  -450,
     602,  -450,  -450,  -450,  -450,   315,   315,   315,  -450,   306,
     313,   311,  -450,   316,   317,   318,   535,  -450,  -450,  -450,
    -450,  -450,  -450,  -450,  1201,   274,  -450,  -450,  -450,  -450,
    -450,  -450,  -450,  -450,  -450,  -450,  -450,    37,  -450,  -450,
     245,  -450,  -450,   320,  -450,  -450,  -450,  1027,  1027,  1027,
     210,    27,  -450,  -450,    12,   348,  -450,  -450,  -450,  -450,
    -450,  -450,  -450,  -450,   326,  -450,  -450,  -450,  -450,  -450,
    -450,  -450,  -450,  -450,  -450,  -450,  1145,   321,   331,  -450,
    1201,  -450,  -450,   322,   213,  -450,   274,   342,   343,  -450,
    1086,  1086,  -450,  -450,  -450,  -450,   274,   714,   344,   242,
     347,  -450,   356,   352,  -450,  -450,   353,   354,   134,  -450,
    -450,  -450,   313,  -450,  -450,   269,  -450,  -450,   269,   369,
    -450,   248,  -450,  1224,   365,  -450,   714,   358,   360,  -450,
     364,  -450,  -450,  -450,   258,   274,   245,   245,   629,  -450,
     417,   366,  -450,   382,  -450,  -450,  -450,  -450,   245,  1027,
    1027,  1027,  1027,  -450,  -450,  -450,  -450,  -450,   263,   361,
    -450,  -450,  -450,  -450,   265,  -450,  -450,  -450,  -450,  1224,
    -450,  -450,   803,  -450,   383,  -450,  -450,   658,  -450,   402,
     859,  -450,  -450,  -450,   403,   408,   409,  -450,  -450,  -450,
    1086,  1086,  1086,  1086,  -450,  -450,   411,   412,  1027,  1027,
    1027,  1027,  -450,   414,  -450,  -450,   245,   415,   415,   292,
    -450,  -450,   274,   274,   274,   416,   279,  -450,  -450,  -450,
    -450,  -450,   321,  -450,  -450,  -450,   274,   274,  1086,  1086,
    1086,  1086,   504,   420,  -450,   302,  -450,   421,   425,   426,
     429,   687,   391,   430,   431,   602,  -450,   432,   433,   439,
     440,   458,  1224,   459,   462,   463,  -450,  -450,   915,   971,
     464,   465,   466,  -450,   470,   471,   474,   475,  -450,  -450,
     476,  -450,  -450,  -450,  -450,  -450,  -450,   306,   274,  -450,
    -450,  -450,  -450,  -450,  -450,  -450,  -450,  -450,  -450,  -450,
    -450,  -450,  -450,  -450,  -450,  -450,  -450,  -450,  -450,   280,
    -450,   489,  -450,   284,   491,  -450,   294,   296,   658,  -450,
    -450,  -450,   411,  -450,  -450,   245,   745,  1224,   419,  -450,
    1224,  -450,  -450,   494,   495,  -450,   498,  -450,  1224,  -450,
     415,   658,  1224,  -450,   499,   500,   320,   501,  -450,  -450,
     502,  -450,  -450
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
       2,     0,     4,     1,     3,     0,     5,     6,   285,     0,
       0,   286,   287,     0,     0,   337,   338,   339,   343,   344,
     345,   346,   347,   348,   349,   350,   351,   352,   353,   354,
     355,   356,   357,   340,   341,   342,   358,     0,     0,     7,
       0,     9,     0,     0,     0,    12,    15,    22,    47,    10,
      13,    16,    17,    18,    49,    50,     0,     0,    70,    72,
      77,    75,     0,     0,     0,     8,     0,    48,     0,    11,
       0,    14,     0,    19,    27,    23,    24,     0,    20,    32,
      28,    29,     0,    21,    37,    33,    34,     0,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    68,    69,     0,    52,   269,   269,     0,    81,
      90,    92,     0,     0,    25,    40,    38,     0,    26,    43,
      41,    30,     0,    31,    46,    44,    35,    36,   183,    51,
      53,     0,   270,   273,     0,     0,    74,    78,     0,     0,
      82,    84,    94,    94,     0,    39,    42,    45,     0,    71,
     275,   271,   274,    73,   306,   307,   308,   310,   311,   312,
     313,   314,   315,   316,   317,   321,   320,   309,   318,   319,
      79,    88,   336,    76,    86,    81,    85,     0,   100,     0,
     112,     0,     0,     0,   186,   188,     0,     0,   190,   203,
       0,   269,   263,   263,     0,    83,   263,   102,   104,     0,
       0,    97,    99,   100,   100,   101,     0,    94,   191,   194,
       0,     0,   185,   184,     0,   187,     0,   189,     0,   204,
     304,     0,   276,   277,   278,   272,   359,     0,   264,   267,
       0,   303,    87,   284,     0,     0,     0,   106,   107,    91,
      96,    98,     0,   110,   131,     0,   269,     0,     0,     0,
     210,     0,   305,     0,    80,   265,   268,    89,    95,   103,
       0,   105,   148,   159,   290,     0,     0,     0,   136,     0,
       0,     0,   109,     0,     0,     0,     0,   193,   195,   289,
     291,   292,   293,   294,     0,     0,   222,   214,   216,   218,
     220,   228,   205,   301,   302,   208,   206,     0,   280,   281,
     263,   288,   152,     0,   155,   150,   300,     0,     0,     0,
       0,     0,   111,   163,     0,   110,   138,    93,   120,   113,
     192,   322,   323,   324,   198,   326,   327,   328,   329,   330,
     331,   332,   335,   334,   325,   333,     0,     0,     0,   196,
       0,   261,   262,     0,     0,   224,     0,     0,     0,   256,
       0,     0,   279,   282,   283,   266,     0,     0,     0,     0,
       0,   234,     0,     0,   239,   244,     0,     0,     0,   132,
     137,   295,     0,   169,   165,     0,   296,   140,     0,     0,
     108,     0,   259,     0,     0,   255,     0,     0,     0,   259,
       0,   212,   213,   223,     0,     0,   263,   263,     0,   245,
       0,     0,   250,     0,   153,   160,   149,   156,   263,     0,
       0,     0,     0,   242,   133,   134,   135,   167,     0,     0,
     297,   298,   171,   173,     0,   142,   144,   299,   146,     0,
     114,   121,     0,   253,     0,   230,   200,     0,   232,     0,
       0,   211,   215,   225,     0,     0,     0,   229,   257,   258,
       0,     0,     0,     0,   209,   207,     0,     0,   240,     0,
       0,     0,   256,     0,   164,   170,   263,     0,     0,     0,
     139,   141,     0,     0,     0,     0,   118,   199,   260,   259,
     201,   259,     0,   202,   197,   217,     0,     0,   251,     0,
       0,     0,     0,     0,   157,     0,   241,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   175,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   115,   117,     0,     0,
       0,     0,     0,   252,     0,     0,     0,     0,   161,   154,
       0,   236,   235,   237,   238,   243,   168,     0,     0,   181,
     177,   172,   174,   143,   145,   147,   123,   122,   125,   128,
     254,   231,   233,   219,   221,   247,   246,   248,   249,     0,
     151,     0,   179,     0,     0,   256,     0,     0,     0,   158,
     162,   166,     0,   176,   182,   263,     0,     0,   118,   126,
       0,   119,   129,     0,     0,   124,     0,   116,     0,   180,
       0,     0,     0,   226,     0,     0,     0,     0,   130,   178,
       0,   127,   227
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -450,  -450,  -450,  -450,  -450,  -450,  -450,   485,   519,  -450,
    -450,  -450,   511,   397,   506,   162,   146,   446,  -450,   492,
    -450,  -450,   117,  -450,   235,   -19,  -450,  -450,  -450,  -450,
     422,  -450,  -450,  -450,   455,  -450,  -450,  -450,  -450,  -117,
    -450,   395,   396,  -450,  -450,  -450,  -450,  -450,  -450,   286,
    -450,  -450,  -450,  -450,  -450,    21,  -450,  -450,  -450,  -450,
    -450,  -450,  -450,  -450,  -450,   293,  -450,   230,  -450,   180,
    -450,  -450,  -450,  -343,  -450,  -450,  -450,  -450,    36,  -227,
    -450,  -397,  -450,  -450,  -450,   167,  -450,  -450,  -449,  -450,
    -450,  -450,  -450,  -450,  -450,   447,   423,  -450,  -450,  -450,
    -450,  -450,  -450,  -450,   448,  -450,  -450,  -450,  -450,  -223,
    -450,  -450,  -450,  -450,  -450,  -450,  -450,  -233,  -450,  -365,
    -450,  -450,  -273,  -450,  -450,  -450,  -340,  -450,   301,  -450,
    -438,  -359,   298,  -191,  -450,  -450,   -93,  -450,  -450,   436,
    -450,  -450,  -450,  -450,  -450,  -450,  -450,  -298,  -242,  -238,
    -450,  -450,  -450,  -252,  -261,  -450,   261,   266,  -450,   102,
    -450,  -450,  -450,  -228,  -450,  -173,  -128,  -450,  -110,   -13,
    -224
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,     2,     4,     6,    41,    44,    45,    46,    73,
      78,    83,   114,   118,   123,    47,    48,    49,   104,   105,
      50,   106,    51,   107,    52,    53,   109,   108,   137,   192,
     139,   140,   175,   194,   141,   193,    54,   142,   143,   178,
     200,   201,   202,   203,   235,   204,   236,   205,   271,   272,
      55,   207,   274,   476,   516,   517,   381,   431,   513,   565,
     566,   579,   567,   582,   243,   244,   310,   315,   424,   316,
     472,   473,   474,   261,   360,   356,   456,   359,   493,   506,
     559,   312,   419,   463,   418,   313,   467,   468,   507,   564,
     572,   563,     7,   148,   183,   184,   185,   186,   246,   187,
     247,   278,   389,   382,   188,   189,   219,   351,   350,   249,
     345,   346,   347,   348,   344,   394,   592,   250,   349,   387,
     481,   439,   363,   497,   364,   462,   401,   524,   402,   479,
     398,   432,   340,   227,   300,   228,   131,   191,   132,   151,
     190,   222,   297,   232,     9,    13,    14,   302,   303,   268,
     287,   288,   289,   290,   375,   379,   422,   423,   428,   307,
     295,   296,   233,   223,   253,   169,   291,   339,   365,   172,
     229
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      37,    38,   230,   263,   256,   234,   285,   170,   305,   262,
     286,   403,   259,   372,   134,   338,   407,   224,     3,   508,
     198,   465,   304,   438,   501,   298,   179,    62,   171,     5,
     440,    63,    76,    81,   337,   366,   367,     8,   197,   198,
     154,   155,   156,    87,    57,    58,    59,    60,    61,   110,
     111,   112,   264,   378,    10,   199,   116,   371,   376,   374,
     342,   116,   343,   226,    62,   301,    64,   264,    63,   353,
     358,   283,   371,   373,   199,   150,   377,    57,    59,    60,
     299,    42,   157,   158,   159,   160,   161,   162,   163,   164,
     245,   220,   167,   133,   133,   168,    62,    39,   225,    40,
      63,   269,    43,    64,   270,   208,   209,   210,   352,   355,
     488,   489,   490,   491,   574,    56,   342,   520,    65,   152,
     518,   393,   519,   395,   354,    66,   263,   576,   208,   209,
     210,   180,   262,   404,    68,    64,   458,   459,   460,   461,
     561,   595,    58,    59,    60,    61,    60,    61,   523,   525,
     526,   527,   530,   275,    70,    59,    60,    61,   138,    72,
     174,    62,    59,    62,    61,    63,    77,    63,    82,    80,
      85,   443,   444,    62,   449,    60,   113,    63,   133,    59,
      62,    11,    12,   117,    63,   496,   498,   499,   500,   122,
     265,   266,    62,    67,   128,   482,    63,    62,   125,   138,
      64,    63,    64,   125,   149,   445,   446,   538,   378,   267,
     135,   136,    64,    74,    79,    84,   153,   457,   144,    64,
      67,   237,   238,   263,   173,    67,   385,   209,   210,   494,
      67,    64,   177,   133,   263,   263,    64,   115,   119,   181,
     385,   385,   115,   124,   276,   277,   196,   119,   124,   509,
     510,   511,   413,   540,   528,   154,   155,   156,   435,   293,
     294,    67,   263,   521,   522,    67,   211,   539,   262,    61,
      67,   341,   206,   433,   213,   504,   214,   449,   145,   264,
     368,   369,   146,   248,   392,    62,    75,   147,    86,    63,
     433,    67,    67,    67,   216,   265,   266,   157,   158,   159,
     160,   161,   162,   163,   164,   226,   220,   167,   218,   435,
     168,   120,   260,   406,   267,   562,   420,   421,   429,   430,
     120,   231,   221,   242,    64,   239,   263,   341,   248,   442,
     263,   199,   570,   311,   464,   469,   470,   371,   376,   263,
     385,   385,   385,   385,   248,   494,   514,   515,   210,   596,
     568,   569,   449,   593,   505,   573,   251,   263,   252,    15,
      16,    17,   254,   600,   577,   578,   580,   581,   308,   309,
     257,   258,   260,   273,   306,   292,   311,   269,   385,   385,
     385,   385,   317,   314,   584,   448,   318,  -295,   319,   320,
     357,   386,   388,   391,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,   396,   397,    36,   405,   475,   408,   427,   478,
      15,    16,    17,   414,   415,   416,   434,   478,   409,   436,
     437,   466,   410,   411,   412,   441,   371,   454,    88,    89,
      90,    91,    92,    93,    94,    95,    96,    97,    98,    99,
     100,   101,   102,   455,   480,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,   483,   485,    36,   154,   155,   156,   486,
     487,   492,   126,   495,   502,   505,   512,   515,   448,   450,
     103,   529,   531,   451,   452,   453,   532,   533,   129,   546,
     534,   536,   537,   541,   542,   478,   478,   154,   155,   156,
     543,   544,   279,   264,   280,   281,   282,   283,   157,   158,
     159,   160,   161,   162,   163,   164,   165,   166,   167,   545,
     547,   168,   548,   549,    69,   552,   553,   554,   321,   322,
     323,   555,   556,   279,   264,   557,   558,   560,   284,   157,
     158,   159,   160,   161,   162,   163,   164,   165,   166,   167,
     571,   575,   168,   448,   586,   589,   590,   588,   591,    71,
     598,   599,   601,   602,   279,   594,    15,    16,    17,   597,
     324,   325,   326,   327,   328,   329,   330,   331,   332,   333,
     334,   121,   127,   335,   182,   176,   130,   195,   240,   587,
     241,   380,   417,   370,   471,   154,   155,   156,   583,   215,
     336,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,   212,
     503,    36,    15,    16,    17,   217,     0,   384,   390,   425,
     301,   279,   264,     0,   426,   150,   283,   157,   158,   159,
     160,   161,   162,   163,   164,   165,   166,   167,     0,     0,
     168,   154,   155,   156,   255,     0,     0,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,     0,     0,    36,     0,   226,
      15,    16,    17,     0,     0,     0,     0,   279,     0,     0,
     447,     0,     0,   157,   158,   159,   160,   161,   162,   163,
     164,   165,   166,   167,     0,     0,   168,   154,   155,   156,
       0,     0,     0,     0,     0,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,     0,     0,    36,     0,   226,    15,    16,
      17,     0,     0,     0,     0,     0,     0,     0,   535,   157,
     158,   159,   160,   161,   162,   163,   164,   165,   166,   167,
       0,     0,   168,     0,     0,   154,   155,   156,     0,     0,
       0,     0,     0,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,     0,     0,    36,     0,   226,    15,    16,    17,     0,
       0,     0,     0,     0,     0,     0,   585,   157,   158,   159,
     160,   161,   162,   163,   164,     0,   220,   167,     0,     0,
     168,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,     0,
       0,    36,    15,    16,    17,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   477,    88,    89,    90,    91,    92,
      93,    94,    95,    96,    97,    98,    99,   100,   101,   102,
       0,     0,     0,     0,     0,     0,     0,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,     0,     0,    36,    15,    16,
      17,     0,     0,     0,     0,     0,     0,   103,     0,     0,
     484,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,     0,     0,    36,    15,    16,    17,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   550,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,     0,     0,    36,
      15,    16,    17,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   551,     0,     0,     0,     0,     0,     0,     0,
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
      13,    14,   193,   236,   228,   196,   248,   135,   260,   236,
     248,   351,   235,   311,   107,   276,   359,   190,     0,   468,
      29,   418,   260,   388,   462,   253,   143,    26,   138,    70,
     389,    30,    51,    52,   276,   308,   309,     3,    28,    29,
       3,     4,     5,    56,     6,     7,     8,     9,    10,    62,
      63,    64,    40,   314,    70,    64,    75,    45,    46,   311,
     284,    80,   285,    60,    26,    38,    65,    40,    30,   297,
     303,    44,    45,   311,    64,    72,   314,     6,     8,     9,
     253,    70,    45,    46,    47,    48,    49,    50,    51,    52,
     207,    54,    55,   106,   107,    58,    26,    71,   191,    71,
      30,    29,    70,    65,    32,    34,    35,    36,    71,   300,
     450,   451,   452,   453,   563,    33,   340,   482,    71,   132,
     479,   344,   481,   346,   297,    70,   359,   565,    34,    35,
      36,   144,   359,   356,    70,    65,   409,   410,   411,   412,
     537,   590,     7,     8,     9,    10,     9,    10,   488,   489,
     490,   491,   495,   246,    70,     8,     9,    10,    70,    70,
      72,    26,     8,    26,    10,    30,    70,    30,    70,    52,
      53,   394,   395,    26,   398,     9,    70,    30,   191,     8,
      26,     4,     5,    70,    30,   458,   459,   460,   461,    70,
      56,    57,    26,    47,    71,   437,    30,    26,    81,    70,
      65,    30,    65,    86,    71,   396,   397,   505,   469,    75,
      70,    71,    65,    51,    52,    53,    71,   408,    69,    65,
      74,    73,    74,   456,    71,    79,   336,    35,    36,   456,
      84,    65,    27,   246,   467,   468,    65,    75,    76,    70,
     350,   351,    80,    81,    70,    71,    70,    85,    86,   472,
     473,   474,   362,   505,   492,     3,     4,     5,   386,    50,
      51,   115,   495,   486,   487,   119,    70,   505,   495,    10,
     124,   284,    31,   383,    71,   466,    70,   501,   116,    40,
      70,    71,   120,    70,    71,    26,    51,   125,    53,    30,
     400,   145,   146,   147,    70,    56,    57,    45,    46,    47,
      48,    49,    50,    51,    52,    60,    54,    55,    70,   437,
      58,    76,    70,    71,    75,   538,    47,    48,    70,    71,
      85,    53,    70,    70,    65,    71,   559,   340,    70,    71,
     563,    64,   559,    70,    71,    70,    71,    45,    46,   572,
     450,   451,   452,   453,    70,   572,    67,    68,    36,   591,
      70,    71,   576,   586,    70,    71,    37,   590,    55,     3,
       4,     5,    71,   596,    70,    71,    70,    71,   266,   267,
      71,    71,    70,    66,    59,    71,    70,    29,   488,   489,
     490,   491,    71,    70,   575,   398,    70,    61,    71,    71,
      70,    70,    61,    71,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    70,    70,    58,    71,   429,    70,    49,   432,
       3,     4,     5,    71,    71,    71,    61,   440,    72,    71,
      70,    70,    76,    77,    78,    71,    45,    71,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    71,    71,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    71,    71,    58,     3,     4,     5,    71,
      71,    70,    85,    71,    70,    70,    70,    68,   501,    72,
      63,    71,    71,    76,    77,    78,    71,    71,    71,   512,
      71,    71,    71,    71,    71,   518,   519,     3,     4,     5,
      71,    71,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    71,
      71,    58,    70,    70,    49,    71,    71,    71,     3,     4,
       5,    71,    71,    39,    40,    71,    71,    71,    75,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      71,    70,    58,   576,   577,    71,    71,   580,    70,    50,
      71,    71,    71,    71,    39,   588,     3,     4,     5,   592,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    80,    86,    58,   148,   140,   104,   175,   203,   578,
     204,   315,   372,   310,   424,     3,     4,     5,   572,   186,
      75,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,   182,
     463,    58,     3,     4,     5,   187,    -1,   336,   340,   378,
      38,    39,    40,    -1,   378,    72,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    -1,    -1,
      58,     3,     4,     5,   228,    -1,    -1,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    -1,    -1,    58,    -1,    60,
       3,     4,     5,    -1,    -1,    -1,    -1,    39,    -1,    -1,
      71,    -1,    -1,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    -1,    -1,    58,     3,     4,     5,
      -1,    -1,    -1,    -1,    -1,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    -1,    -1,    58,    -1,    60,     3,     4,
       5,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    71,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      -1,    -1,    58,    -1,    -1,     3,     4,     5,    -1,    -1,
      -1,    -1,    -1,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    -1,    -1,    58,    -1,    60,     3,     4,     5,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    71,    45,    46,    47,
      48,    49,    50,    51,    52,    -1,    54,    55,    -1,    -1,
      58,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
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
      55,    -1,    -1,    58,     3,     4,     5,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    71,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    -1,    -1,    58,
       3,     4,     5,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
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
       0,    80,    81,     0,    82,    70,    83,   171,     3,   223,
      70,     4,     5,   224,   225,     3,     4,     5,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    58,   248,   248,    71,
      71,    84,    70,    70,    85,    86,    87,    94,    95,    96,
      99,   101,   103,   104,   115,   129,    33,     6,     7,     8,
       9,    10,    26,    30,    65,    71,    70,    95,    70,    86,
      70,    87,    70,    88,    94,   103,   104,    70,    89,    94,
     101,   104,    70,    90,    94,   101,   103,   248,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    63,    97,    98,   100,   102,   106,   105,
     248,   248,   248,    70,    91,    94,   104,    70,    92,    94,
     103,    91,    70,    93,    94,   101,    92,    93,    71,    71,
      98,   215,   217,   248,   215,    70,    71,   107,    70,   109,
     110,   113,   116,   117,    69,    94,    94,    94,   172,    71,
      72,   218,   248,    71,     3,     4,     5,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    58,   244,
     245,   247,   248,    71,    72,   111,   113,    27,   118,   118,
     248,    70,    96,   173,   174,   175,   176,   178,   183,   184,
     219,   216,   108,   114,   112,   109,    70,    28,    29,    64,
     119,   120,   121,   122,   124,   126,    31,   130,    34,    35,
      36,    70,   174,    71,    70,   175,    70,   183,    70,   185,
      54,    70,   220,   242,   244,   215,    60,   212,   214,   249,
     212,    53,   222,   241,   212,   123,   125,    73,    74,    71,
     120,   121,    70,   143,   144,   118,   177,   179,    70,   188,
     196,    37,    55,   243,    71,   218,   249,    71,    71,   188,
      70,   152,   158,   196,    40,    56,    57,    75,   228,    29,
      32,   127,   128,    66,   131,   215,    70,    71,   180,    39,
      41,    42,    43,    44,    75,   227,   228,   229,   230,   231,
     232,   245,    71,    50,    51,   239,   240,   221,   242,   244,
     213,    38,   226,   227,   228,   232,    59,   238,   238,   238,
     145,    70,   160,   164,    70,   146,   148,    71,    70,    71,
      71,     3,     4,     5,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    58,    75,   227,   233,   246,
     211,   248,   249,   188,   193,   189,   190,   191,   192,   197,
     187,   186,    71,   242,   244,   212,   154,    70,   196,   156,
     153,    61,    70,   201,   203,   247,   201,   201,    70,    71,
     144,    45,   226,   228,   232,   233,    46,   228,   233,   234,
     128,   135,   182,    70,   207,   247,    70,   198,    61,   181,
     211,    71,    71,   188,   194,   188,    70,    70,   209,    61,
      70,   205,   207,   205,   188,    71,    71,   152,    70,    72,
      76,    77,    78,   247,    71,    71,    71,   146,   163,   161,
      47,    48,   235,   236,   147,   235,   236,    49,   237,    70,
      71,   136,   210,   247,    61,   245,    71,    70,   198,   200,
     210,    71,    71,   188,   188,   212,   212,    71,   248,   249,
      72,    76,    77,    78,    71,    71,   155,   212,   201,   201,
     201,   201,   204,   162,    71,   160,    70,   165,   166,    70,
      71,   148,   149,   150,   151,   248,   132,    71,   248,   208,
      71,   199,   227,    71,    71,    71,    71,    71,   205,   205,
     205,   205,    70,   157,   158,    71,   201,   202,   201,   201,
     201,   209,    70,   164,   212,    70,   158,   167,   167,   188,
     188,   188,    70,   137,    67,    68,   133,   134,   210,   210,
     198,   188,   188,   205,   206,   205,   205,   205,   228,    71,
     152,    71,    71,    71,    71,    71,    71,    71,   226,   228,
     232,    71,    71,    71,    71,    71,   248,    71,    70,    70,
      71,    71,    71,    71,    71,    71,    71,    71,    71,   159,
      71,   160,   188,   170,   168,   138,   139,   141,    70,    71,
     158,    71,   169,    71,   167,    70,   209,    70,    71,   140,
      70,    71,   142,   157,   212,    71,   248,   134,   248,    71,
      71,    70,   195,   196,   248,   167,   227,   248,    71,    71,
     196,    71,    71
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
     128,   128,   130,   129,   132,   131,   133,   133,   134,   134,
     135,   135,   136,   138,   137,   139,   139,   140,   141,   141,
     142,   143,   143,   144,   144,   144,   145,   145,   146,   146,
     147,   147,   149,   148,   150,   148,   151,   148,   152,   152,
     153,   152,   154,   155,   152,   156,   156,   157,   157,   158,
     158,   159,   159,   160,   160,   161,   160,   162,   160,   163,
     163,   165,   164,   166,   164,   167,   167,   168,   167,   169,
     167,   170,   170,   172,   171,   173,   173,   174,   174,   175,
     175,   177,   176,   178,   179,   179,   181,   180,   182,   180,
     180,   180,   180,   183,   183,   184,   186,   185,   187,   185,
     188,   188,   188,   188,   189,   188,   190,   188,   191,   188,
     192,   188,   193,   193,   194,   194,   195,   195,   197,   196,
     199,   198,   200,   200,   201,   201,   201,   201,   201,   201,
     202,   202,   204,   203,   203,   205,   205,   205,   205,   205,
     205,   206,   206,   208,   207,   207,   209,   209,   209,   210,
     210,   211,   211,   212,   212,   213,   212,   214,   214,   215,
     215,   216,   215,   217,   217,   219,   218,   220,   220,   220,
     221,   221,   221,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   244,   244,   244,
     244,   244,   244,   244,   244,   244,   244,   244,   244,   245,
     245,   245,   246,   246,   246,   246,   246,   246,   246,   246,
     246,   246,   246,   246,   246,   246,   247,   248,   248,   248,
     248,   248,   248,   248,   248,   248,   248,   248,   248,   248,
     248,   248,   248,   248,   248,   248,   248,   248,   248,   249
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
       0,     2,     0,     9,     0,     6,     5,     1,     0,     4,
       0,     2,     4,     0,     5,     0,     2,     5,     0,     2,
       4,     1,     4,     5,     5,     5,     0,     2,     1,     4,
       0,     2,     0,     6,     0,     6,     0,     6,     1,     4,
       0,     8,     0,     0,     7,     0,     2,     1,     4,     1,
       4,     0,     2,     1,     4,     0,     8,     0,     6,     0,
       2,     0,     6,     0,     6,     1,     4,     0,     8,     0,
       6,     0,     2,     0,    13,     2,     1,     2,     1,     2,
       1,     0,     5,     4,     0,     2,     0,     5,     0,     5,
       4,     5,     5,     1,     2,     4,     0,     6,     0,     6,
       1,     5,     4,     4,     0,     5,     0,     6,     0,     8,
       0,     8,     0,     2,     0,     2,     1,     4,     0,     5,
       0,     5,     1,     4,     1,     5,     5,     5,     5,     1,
       0,     1,     0,     5,     1,     1,     5,     5,     5,     5,
       1,     0,     1,     0,     5,     1,     0,     2,     2,     0,
       2,     1,     1,     0,     1,     0,     4,     1,     2,     0,
       1,     0,     4,     1,     2,     0,     3,     1,     1,     4,
       1,     1,     2,     2,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1
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
#line 422 "pddl.yy" /* yacc.c:1646  */
    { success = true; line_number = 1; }
#line 2248 "pddl.cc" /* yacc.c:1646  */
    break;

  case 3:
#line 423 "pddl.yy" /* yacc.c:1646  */
    { if (!success) YYERROR; }
#line 2254 "pddl.cc" /* yacc.c:1646  */
    break;

  case 7:
#line 435 "pddl.yy" /* yacc.c:1646  */
    { make_domain((yyvsp[-1].str)); }
#line 2260 "pddl.cc" /* yacc.c:1646  */
    break;

  case 54:
#line 510 "pddl.yy" /* yacc.c:1646  */
    { requirements->strips = true; }
#line 2266 "pddl.cc" /* yacc.c:1646  */
    break;

  case 55:
#line 511 "pddl.yy" /* yacc.c:1646  */
    { requirements->typing = true; }
#line 2272 "pddl.cc" /* yacc.c:1646  */
    break;

  case 56:
#line 512 "pddl.yy" /* yacc.c:1646  */
    { requirements->negative_preconditions = true; }
#line 2278 "pddl.cc" /* yacc.c:1646  */
    break;

  case 57:
#line 513 "pddl.yy" /* yacc.c:1646  */
    { requirements->disjunctive_preconditions = true; }
#line 2284 "pddl.cc" /* yacc.c:1646  */
    break;

  case 58:
#line 514 "pddl.yy" /* yacc.c:1646  */
    { requirements->equality = true; }
#line 2290 "pddl.cc" /* yacc.c:1646  */
    break;

  case 59:
#line 515 "pddl.yy" /* yacc.c:1646  */
    { requirements->existential_preconditions = true; }
#line 2296 "pddl.cc" /* yacc.c:1646  */
    break;

  case 60:
#line 516 "pddl.yy" /* yacc.c:1646  */
    { requirements->universal_preconditions = true; }
#line 2302 "pddl.cc" /* yacc.c:1646  */
    break;

  case 61:
#line 517 "pddl.yy" /* yacc.c:1646  */
    { requirements->quantified_preconditions(); }
#line 2308 "pddl.cc" /* yacc.c:1646  */
    break;

  case 62:
#line 518 "pddl.yy" /* yacc.c:1646  */
    { requirements->conditional_effects = true; }
#line 2314 "pddl.cc" /* yacc.c:1646  */
    break;

  case 63:
#line 519 "pddl.yy" /* yacc.c:1646  */
    { requirements->fluents = true; }
#line 2320 "pddl.cc" /* yacc.c:1646  */
    break;

  case 64:
#line 520 "pddl.yy" /* yacc.c:1646  */
    { requirements->adl(); }
#line 2326 "pddl.cc" /* yacc.c:1646  */
    break;

  case 65:
#line 522 "pddl.yy" /* yacc.c:1646  */
    {
                    if(requirements->decompositions == true) {
                        yyerror(":durative-actions cannot be combined with :decompositions at this time");
                    }
                    
                    else{
                        requirements->durative_actions = true; 
                    }
                }
#line 2340 "pddl.cc" /* yacc.c:1646  */
    break;

  case 66:
#line 531 "pddl.yy" /* yacc.c:1646  */
    { requirements->duration_inequalities = true; }
#line 2346 "pddl.cc" /* yacc.c:1646  */
    break;

  case 67:
#line 532 "pddl.yy" /* yacc.c:1646  */
    { yyerror("`:continuous-effects' not supported"); }
#line 2352 "pddl.cc" /* yacc.c:1646  */
    break;

  case 68:
#line 534 "pddl.yy" /* yacc.c:1646  */
    {
                    requirements->durative_actions = true;
                    requirements->timed_initial_literals = true;
                }
#line 2361 "pddl.cc" /* yacc.c:1646  */
    break;

  case 69:
#line 539 "pddl.yy" /* yacc.c:1646  */
    {
                    if(requirements->durative_actions == true) {
                        yyerror(":decompositions cannot be combined with :durative-actions at this time");
                    }

                    else {
                        requirements->decompositions = true; 
                    }
                }
#line 2375 "pddl.cc" /* yacc.c:1646  */
    break;

  case 70:
#line 550 "pddl.yy" /* yacc.c:1646  */
    { require_typing(); name_kind = TYPE_KIND; }
#line 2381 "pddl.cc" /* yacc.c:1646  */
    break;

  case 71:
#line 551 "pddl.yy" /* yacc.c:1646  */
    { name_kind = VOID_KIND; }
#line 2387 "pddl.cc" /* yacc.c:1646  */
    break;

  case 72:
#line 554 "pddl.yy" /* yacc.c:1646  */
    { name_kind = CONSTANT_KIND; }
#line 2393 "pddl.cc" /* yacc.c:1646  */
    break;

  case 73:
#line 555 "pddl.yy" /* yacc.c:1646  */
    { name_kind = VOID_KIND; }
#line 2399 "pddl.cc" /* yacc.c:1646  */
    break;

  case 75:
#line 561 "pddl.yy" /* yacc.c:1646  */
    { require_fluents(); }
#line 2405 "pddl.cc" /* yacc.c:1646  */
    break;

  case 79:
#line 572 "pddl.yy" /* yacc.c:1646  */
    { make_predicate((yyvsp[0].str)); }
#line 2411 "pddl.cc" /* yacc.c:1646  */
    break;

  case 80:
#line 573 "pddl.yy" /* yacc.c:1646  */
    { predicate = 0; }
#line 2417 "pddl.cc" /* yacc.c:1646  */
    break;

  case 86:
#line 585 "pddl.yy" /* yacc.c:1646  */
    { require_typing(); }
#line 2423 "pddl.cc" /* yacc.c:1646  */
    break;

  case 88:
#line 588 "pddl.yy" /* yacc.c:1646  */
    { make_function((yyvsp[0].str)); }
#line 2429 "pddl.cc" /* yacc.c:1646  */
    break;

  case 89:
#line 589 "pddl.yy" /* yacc.c:1646  */
    { function = 0; }
#line 2435 "pddl.cc" /* yacc.c:1646  */
    break;

  case 90:
#line 596 "pddl.yy" /* yacc.c:1646  */
    { make_action((yyvsp[0].str), false, false); }
#line 2441 "pddl.cc" /* yacc.c:1646  */
    break;

  case 91:
#line 596 "pddl.yy" /* yacc.c:1646  */
    { add_action(); }
#line 2447 "pddl.cc" /* yacc.c:1646  */
    break;

  case 92:
#line 597 "pddl.yy" /* yacc.c:1646  */
    { require_durative_actions(); make_action((yyvsp[0].str), true, false); }
#line 2453 "pddl.cc" /* yacc.c:1646  */
    break;

  case 93:
#line 598 "pddl.yy" /* yacc.c:1646  */
    { add_action(); }
#line 2459 "pddl.cc" /* yacc.c:1646  */
    break;

  case 102:
#line 617 "pddl.yy" /* yacc.c:1646  */
    { formula_time = AT_START; }
#line 2465 "pddl.cc" /* yacc.c:1646  */
    break;

  case 103:
#line 617 "pddl.yy" /* yacc.c:1646  */
    { action->set_condition(*(yyvsp[0].formula)); }
#line 2471 "pddl.cc" /* yacc.c:1646  */
    break;

  case 104:
#line 620 "pddl.yy" /* yacc.c:1646  */
    { effect_time = Effect::AT_END; }
#line 2477 "pddl.cc" /* yacc.c:1646  */
    break;

  case 106:
#line 623 "pddl.yy" /* yacc.c:1646  */
    { require_decompositions(); action->set_composite(true); }
#line 2483 "pddl.cc" /* yacc.c:1646  */
    break;

  case 107:
#line 624 "pddl.yy" /* yacc.c:1646  */
    { require_decompositions(); action->set_composite(false); }
#line 2489 "pddl.cc" /* yacc.c:1646  */
    break;

  case 108:
#line 627 "pddl.yy" /* yacc.c:1646  */
    { action->set_condition(*(yyvsp[-1].formula)); }
#line 2495 "pddl.cc" /* yacc.c:1646  */
    break;

  case 112:
#line 640 "pddl.yy" /* yacc.c:1646  */
    { make_decomposition((yyvsp[-2].str), (yyvsp[0].str)); }
#line 2501 "pddl.cc" /* yacc.c:1646  */
    break;

  case 113:
#line 641 "pddl.yy" /* yacc.c:1646  */
    { add_decomposition(); decomposition_pseudo_steps.clear(); }
#line 2507 "pddl.cc" /* yacc.c:1646  */
    break;

  case 114:
#line 644 "pddl.yy" /* yacc.c:1646  */
    { register_dummy_pseudo_steps(); }
#line 2513 "pddl.cc" /* yacc.c:1646  */
    break;

  case 116:
#line 649 "pddl.yy" /* yacc.c:1646  */
    {
                          if (decomposition->link_list().contains_cycle()) {
                           yyerror("cycle detected in links for decomposition " + decomposition->name());
                          }
                        }
#line 2523 "pddl.cc" /* yacc.c:1646  */
    break;

  case 119:
#line 660 "pddl.yy" /* yacc.c:1646  */
    {
                          if (decomposition->ordering_list().contains_cycle()) {
                            yyerror("cycle detected in orderings for decomposition " + decomposition->name());
                          } 
                        }
#line 2533 "pddl.cc" /* yacc.c:1646  */
    break;

  case 122:
#line 671 "pddl.yy" /* yacc.c:1646  */
    { decomposition_pseudo_steps.insert( std::make_pair(*(yyvsp[-2].str), (yyvsp[-1].step)) ); add_pseudo_step(*(yyvsp[-1].step)); }
#line 2539 "pddl.cc" /* yacc.c:1646  */
    break;

  case 123:
#line 674 "pddl.yy" /* yacc.c:1646  */
    { prepare_pseudostep((yyvsp[0].str)); }
#line 2545 "pddl.cc" /* yacc.c:1646  */
    break;

  case 124:
#line 675 "pddl.yy" /* yacc.c:1646  */
    { (yyval.step) = make_pseudostep(); }
#line 2551 "pddl.cc" /* yacc.c:1646  */
    break;

  case 126:
#line 679 "pddl.yy" /* yacc.c:1646  */
    { add_link(*(yyvsp[0].link)); }
#line 2557 "pddl.cc" /* yacc.c:1646  */
    break;

  case 127:
#line 682 "pddl.yy" /* yacc.c:1646  */
    { (yyval.link) = make_link((yyvsp[-3].str), *(yyvsp[-2].literal), (yyvsp[-1].str)); }
#line 2563 "pddl.cc" /* yacc.c:1646  */
    break;

  case 129:
#line 686 "pddl.yy" /* yacc.c:1646  */
    { add_ordering(*(yyvsp[0].ordering)); }
#line 2569 "pddl.cc" /* yacc.c:1646  */
    break;

  case 130:
#line 689 "pddl.yy" /* yacc.c:1646  */
    { (yyval.ordering) = make_ordering((yyvsp[-2].str), (yyvsp[-1].str)); }
#line 2575 "pddl.cc" /* yacc.c:1646  */
    break;

  case 132:
#line 696 "pddl.yy" /* yacc.c:1646  */
    { require_duration_inequalities(); }
#line 2581 "pddl.cc" /* yacc.c:1646  */
    break;

  case 133:
#line 699 "pddl.yy" /* yacc.c:1646  */
    { require_duration_inequalities(); action->set_max_duration(*(yyvsp[-1].expr)); }
#line 2587 "pddl.cc" /* yacc.c:1646  */
    break;

  case 134:
#line 700 "pddl.yy" /* yacc.c:1646  */
    { require_duration_inequalities(); action->set_min_duration(*(yyvsp[-1].expr)); }
#line 2593 "pddl.cc" /* yacc.c:1646  */
    break;

  case 135:
#line 701 "pddl.yy" /* yacc.c:1646  */
    { action->set_duration(*(yyvsp[-1].expr)); }
#line 2599 "pddl.cc" /* yacc.c:1646  */
    break;

  case 139:
#line 714 "pddl.yy" /* yacc.c:1646  */
    { (yyval.formula) = (yyvsp[-1].formula); }
#line 2605 "pddl.cc" /* yacc.c:1646  */
    break;

  case 140:
#line 717 "pddl.yy" /* yacc.c:1646  */
    { (yyval.formula) = &Formula::TRUE; }
#line 2611 "pddl.cc" /* yacc.c:1646  */
    break;

  case 141:
#line 718 "pddl.yy" /* yacc.c:1646  */
    { (yyval.formula) = &(*(yyvsp[-1].formula) && *(yyvsp[0].formula)); }
#line 2617 "pddl.cc" /* yacc.c:1646  */
    break;

  case 142:
#line 721 "pddl.yy" /* yacc.c:1646  */
    { formula_time = AT_START; }
#line 2623 "pddl.cc" /* yacc.c:1646  */
    break;

  case 143:
#line 721 "pddl.yy" /* yacc.c:1646  */
    { (yyval.formula) = (yyvsp[-1].formula); }
#line 2629 "pddl.cc" /* yacc.c:1646  */
    break;

  case 144:
#line 722 "pddl.yy" /* yacc.c:1646  */
    { formula_time = AT_END; }
#line 2635 "pddl.cc" /* yacc.c:1646  */
    break;

  case 145:
#line 722 "pddl.yy" /* yacc.c:1646  */
    { (yyval.formula) = (yyvsp[-1].formula); }
#line 2641 "pddl.cc" /* yacc.c:1646  */
    break;

  case 146:
#line 723 "pddl.yy" /* yacc.c:1646  */
    { formula_time = OVER_ALL; }
#line 2647 "pddl.cc" /* yacc.c:1646  */
    break;

  case 147:
#line 723 "pddl.yy" /* yacc.c:1646  */
    { (yyval.formula) = (yyvsp[-1].formula); }
#line 2653 "pddl.cc" /* yacc.c:1646  */
    break;

  case 150:
#line 732 "pddl.yy" /* yacc.c:1646  */
    { prepare_forall_effect(); }
#line 2659 "pddl.cc" /* yacc.c:1646  */
    break;

  case 151:
#line 732 "pddl.yy" /* yacc.c:1646  */
    { pop_forall_effect(); }
#line 2665 "pddl.cc" /* yacc.c:1646  */
    break;

  case 152:
#line 733 "pddl.yy" /* yacc.c:1646  */
    { formula_time = AT_START; }
#line 2671 "pddl.cc" /* yacc.c:1646  */
    break;

  case 153:
#line 733 "pddl.yy" /* yacc.c:1646  */
    { prepare_conditional_effect(*(yyvsp[0].formula)); }
#line 2677 "pddl.cc" /* yacc.c:1646  */
    break;

  case 154:
#line 733 "pddl.yy" /* yacc.c:1646  */
    { effect_condition = 0; }
#line 2683 "pddl.cc" /* yacc.c:1646  */
    break;

  case 159:
#line 744 "pddl.yy" /* yacc.c:1646  */
    { add_effect(*(yyvsp[0].atom)); }
#line 2689 "pddl.cc" /* yacc.c:1646  */
    break;

  case 160:
#line 745 "pddl.yy" /* yacc.c:1646  */
    { add_effect(Negation::make(*(yyvsp[-1].atom))); }
#line 2695 "pddl.cc" /* yacc.c:1646  */
    break;

  case 165:
#line 754 "pddl.yy" /* yacc.c:1646  */
    { prepare_forall_effect(); }
#line 2701 "pddl.cc" /* yacc.c:1646  */
    break;

  case 166:
#line 755 "pddl.yy" /* yacc.c:1646  */
    { pop_forall_effect(); }
#line 2707 "pddl.cc" /* yacc.c:1646  */
    break;

  case 167:
#line 756 "pddl.yy" /* yacc.c:1646  */
    { prepare_conditional_effect(*(yyvsp[0].formula)); }
#line 2713 "pddl.cc" /* yacc.c:1646  */
    break;

  case 168:
#line 757 "pddl.yy" /* yacc.c:1646  */
    { effect_condition = 0; }
#line 2719 "pddl.cc" /* yacc.c:1646  */
    break;

  case 171:
#line 765 "pddl.yy" /* yacc.c:1646  */
    { effect_time = Effect::AT_START; formula_time = AT_START; }
#line 2725 "pddl.cc" /* yacc.c:1646  */
    break;

  case 173:
#line 768 "pddl.yy" /* yacc.c:1646  */
    { effect_time = Effect::AT_END; formula_time = AT_END; }
#line 2731 "pddl.cc" /* yacc.c:1646  */
    break;

  case 177:
#line 774 "pddl.yy" /* yacc.c:1646  */
    { prepare_forall_effect(); }
#line 2737 "pddl.cc" /* yacc.c:1646  */
    break;

  case 178:
#line 775 "pddl.yy" /* yacc.c:1646  */
    { pop_forall_effect(); }
#line 2743 "pddl.cc" /* yacc.c:1646  */
    break;

  case 179:
#line 776 "pddl.yy" /* yacc.c:1646  */
    { prepare_conditional_effect(*(yyvsp[0].formula)); }
#line 2749 "pddl.cc" /* yacc.c:1646  */
    break;

  case 180:
#line 777 "pddl.yy" /* yacc.c:1646  */
    { effect_condition = 0; }
#line 2755 "pddl.cc" /* yacc.c:1646  */
    break;

  case 183:
#line 789 "pddl.yy" /* yacc.c:1646  */
    { make_problem((yyvsp[-5].str), (yyvsp[-1].str)); }
#line 2761 "pddl.cc" /* yacc.c:1646  */
    break;

  case 184:
#line 790 "pddl.yy" /* yacc.c:1646  */
    { delete requirements; }
#line 2767 "pddl.cc" /* yacc.c:1646  */
    break;

  case 191:
#line 805 "pddl.yy" /* yacc.c:1646  */
    { name_kind = OBJECT_KIND; }
#line 2773 "pddl.cc" /* yacc.c:1646  */
    break;

  case 192:
#line 806 "pddl.yy" /* yacc.c:1646  */
    { name_kind = VOID_KIND; }
#line 2779 "pddl.cc" /* yacc.c:1646  */
    break;

  case 196:
#line 816 "pddl.yy" /* yacc.c:1646  */
    { prepare_atom((yyvsp[0].str)); }
#line 2785 "pddl.cc" /* yacc.c:1646  */
    break;

  case 197:
#line 817 "pddl.yy" /* yacc.c:1646  */
    { problem->add_init_atom(*make_atom()); }
#line 2791 "pddl.cc" /* yacc.c:1646  */
    break;

  case 198:
#line 818 "pddl.yy" /* yacc.c:1646  */
    { prepare_atom((yyvsp[0].str)); }
#line 2797 "pddl.cc" /* yacc.c:1646  */
    break;

  case 199:
#line 819 "pddl.yy" /* yacc.c:1646  */
    { problem->add_init_atom(*make_atom()); }
#line 2803 "pddl.cc" /* yacc.c:1646  */
    break;

  case 200:
#line 821 "pddl.yy" /* yacc.c:1646  */
    { Formula::register_use((yyvsp[-1].atom)); Formula::unregister_use((yyvsp[-1].atom)); }
#line 2809 "pddl.cc" /* yacc.c:1646  */
    break;

  case 201:
#line 823 "pddl.yy" /* yacc.c:1646  */
    { problem->add_init_value(*(yyvsp[-2].fluent), (yyvsp[-1].num)); }
#line 2815 "pddl.cc" /* yacc.c:1646  */
    break;

  case 202:
#line 825 "pddl.yy" /* yacc.c:1646  */
    { add_init_literal((yyvsp[-2].num), *(yyvsp[-1].literal)); }
#line 2821 "pddl.cc" /* yacc.c:1646  */
    break;

  case 205:
#line 832 "pddl.yy" /* yacc.c:1646  */
    { problem->set_goal(*(yyvsp[-1].formula)); }
#line 2827 "pddl.cc" /* yacc.c:1646  */
    break;

  case 206:
#line 835 "pddl.yy" /* yacc.c:1646  */
    { metric_fluent = true; }
#line 2833 "pddl.cc" /* yacc.c:1646  */
    break;

  case 207:
#line 836 "pddl.yy" /* yacc.c:1646  */
    { problem->set_metric(*(yyvsp[-1].expr), true); metric_fluent = false; }
#line 2839 "pddl.cc" /* yacc.c:1646  */
    break;

  case 208:
#line 837 "pddl.yy" /* yacc.c:1646  */
    { metric_fluent = true; }
#line 2845 "pddl.cc" /* yacc.c:1646  */
    break;

  case 209:
#line 838 "pddl.yy" /* yacc.c:1646  */
    { problem->set_metric(*(yyvsp[-1].expr)); metric_fluent = false; }
#line 2851 "pddl.cc" /* yacc.c:1646  */
    break;

  case 210:
#line 845 "pddl.yy" /* yacc.c:1646  */
    { (yyval.formula) = &TimedLiteral::make(*(yyvsp[0].atom), formula_time); }
#line 2857 "pddl.cc" /* yacc.c:1646  */
    break;

  case 211:
#line 846 "pddl.yy" /* yacc.c:1646  */
    { (yyval.formula) = make_equality((yyvsp[-2].term), (yyvsp[-1].term)); }
#line 2863 "pddl.cc" /* yacc.c:1646  */
    break;

  case 212:
#line 847 "pddl.yy" /* yacc.c:1646  */
    { (yyval.formula) = make_negation(*(yyvsp[-1].formula)); }
#line 2869 "pddl.cc" /* yacc.c:1646  */
    break;

  case 213:
#line 848 "pddl.yy" /* yacc.c:1646  */
    { (yyval.formula) = (yyvsp[-1].formula); }
#line 2875 "pddl.cc" /* yacc.c:1646  */
    break;

  case 214:
#line 849 "pddl.yy" /* yacc.c:1646  */
    { require_disjunction(); }
#line 2881 "pddl.cc" /* yacc.c:1646  */
    break;

  case 215:
#line 849 "pddl.yy" /* yacc.c:1646  */
    { (yyval.formula) = (yyvsp[-1].formula); }
#line 2887 "pddl.cc" /* yacc.c:1646  */
    break;

  case 216:
#line 850 "pddl.yy" /* yacc.c:1646  */
    { require_disjunction(); }
#line 2893 "pddl.cc" /* yacc.c:1646  */
    break;

  case 217:
#line 850 "pddl.yy" /* yacc.c:1646  */
    { (yyval.formula) = &(!*(yyvsp[-2].formula) || *(yyvsp[-1].formula)); }
#line 2899 "pddl.cc" /* yacc.c:1646  */
    break;

  case 218:
#line 851 "pddl.yy" /* yacc.c:1646  */
    { prepare_exists(); }
#line 2905 "pddl.cc" /* yacc.c:1646  */
    break;

  case 219:
#line 851 "pddl.yy" /* yacc.c:1646  */
    { (yyval.formula) = make_exists(*(yyvsp[-1].formula)); }
#line 2911 "pddl.cc" /* yacc.c:1646  */
    break;

  case 220:
#line 852 "pddl.yy" /* yacc.c:1646  */
    { prepare_forall(); }
#line 2917 "pddl.cc" /* yacc.c:1646  */
    break;

  case 221:
#line 852 "pddl.yy" /* yacc.c:1646  */
    { (yyval.formula) = make_forall(*(yyvsp[-1].formula)); }
#line 2923 "pddl.cc" /* yacc.c:1646  */
    break;

  case 222:
#line 855 "pddl.yy" /* yacc.c:1646  */
    { (yyval.formula) = &Formula::TRUE; }
#line 2929 "pddl.cc" /* yacc.c:1646  */
    break;

  case 223:
#line 856 "pddl.yy" /* yacc.c:1646  */
    { (yyval.formula) = &(*(yyvsp[-1].formula) && *(yyvsp[0].formula)); }
#line 2935 "pddl.cc" /* yacc.c:1646  */
    break;

  case 224:
#line 859 "pddl.yy" /* yacc.c:1646  */
    { (yyval.formula) = &Formula::FALSE; }
#line 2941 "pddl.cc" /* yacc.c:1646  */
    break;

  case 225:
#line 860 "pddl.yy" /* yacc.c:1646  */
    { (yyval.formula) = &(*(yyvsp[-1].formula) || *(yyvsp[0].formula)); }
#line 2947 "pddl.cc" /* yacc.c:1646  */
    break;

  case 226:
#line 863 "pddl.yy" /* yacc.c:1646  */
    { (yyval.literal) = (yyvsp[0].atom); }
#line 2953 "pddl.cc" /* yacc.c:1646  */
    break;

  case 227:
#line 864 "pddl.yy" /* yacc.c:1646  */
    { (yyval.literal) = &Negation::make(*(yyvsp[-1].atom)); }
#line 2959 "pddl.cc" /* yacc.c:1646  */
    break;

  case 228:
#line 867 "pddl.yy" /* yacc.c:1646  */
    { prepare_atom((yyvsp[0].str)); }
#line 2965 "pddl.cc" /* yacc.c:1646  */
    break;

  case 229:
#line 867 "pddl.yy" /* yacc.c:1646  */
    { (yyval.atom) = make_atom(); }
#line 2971 "pddl.cc" /* yacc.c:1646  */
    break;

  case 230:
#line 870 "pddl.yy" /* yacc.c:1646  */
    { prepare_atom((yyvsp[0].str)); }
#line 2977 "pddl.cc" /* yacc.c:1646  */
    break;

  case 231:
#line 870 "pddl.yy" /* yacc.c:1646  */
    { (yyval.atom) = make_atom(); }
#line 2983 "pddl.cc" /* yacc.c:1646  */
    break;

  case 232:
#line 873 "pddl.yy" /* yacc.c:1646  */
    { (yyval.literal) = (yyvsp[0].atom); }
#line 2989 "pddl.cc" /* yacc.c:1646  */
    break;

  case 233:
#line 874 "pddl.yy" /* yacc.c:1646  */
    { (yyval.literal) = &Negation::make(*(yyvsp[-1].atom)); }
#line 2995 "pddl.cc" /* yacc.c:1646  */
    break;

  case 234:
#line 881 "pddl.yy" /* yacc.c:1646  */
    { (yyval.expr) = new Value((yyvsp[0].num)); }
#line 3001 "pddl.cc" /* yacc.c:1646  */
    break;

  case 235:
#line 882 "pddl.yy" /* yacc.c:1646  */
    { (yyval.expr) = &Addition::make(*(yyvsp[-2].expr), *(yyvsp[-1].expr)); }
#line 3007 "pddl.cc" /* yacc.c:1646  */
    break;

  case 236:
#line 883 "pddl.yy" /* yacc.c:1646  */
    { (yyval.expr) = make_subtraction(*(yyvsp[-2].expr), (yyvsp[-1].expr)); }
#line 3013 "pddl.cc" /* yacc.c:1646  */
    break;

  case 237:
#line 884 "pddl.yy" /* yacc.c:1646  */
    { (yyval.expr) = &Multiplication::make(*(yyvsp[-2].expr), *(yyvsp[-1].expr)); }
#line 3019 "pddl.cc" /* yacc.c:1646  */
    break;

  case 238:
#line 885 "pddl.yy" /* yacc.c:1646  */
    { (yyval.expr) = &Division::make(*(yyvsp[-2].expr), *(yyvsp[-1].expr)); }
#line 3025 "pddl.cc" /* yacc.c:1646  */
    break;

  case 239:
#line 886 "pddl.yy" /* yacc.c:1646  */
    { (yyval.expr) = (yyvsp[0].fluent); }
#line 3031 "pddl.cc" /* yacc.c:1646  */
    break;

  case 240:
#line 889 "pddl.yy" /* yacc.c:1646  */
    { (yyval.expr) = 0; }
#line 3037 "pddl.cc" /* yacc.c:1646  */
    break;

  case 242:
#line 893 "pddl.yy" /* yacc.c:1646  */
    { prepare_fluent((yyvsp[0].str)); }
#line 3043 "pddl.cc" /* yacc.c:1646  */
    break;

  case 243:
#line 894 "pddl.yy" /* yacc.c:1646  */
    { (yyval.fluent) = make_fluent(); }
#line 3049 "pddl.cc" /* yacc.c:1646  */
    break;

  case 244:
#line 895 "pddl.yy" /* yacc.c:1646  */
    { prepare_fluent((yyvsp[0].str)); (yyval.fluent) = make_fluent(); }
#line 3055 "pddl.cc" /* yacc.c:1646  */
    break;

  case 245:
#line 898 "pddl.yy" /* yacc.c:1646  */
    { (yyval.expr) = new Value((yyvsp[0].num)); }
#line 3061 "pddl.cc" /* yacc.c:1646  */
    break;

  case 246:
#line 900 "pddl.yy" /* yacc.c:1646  */
    { (yyval.expr) = &Addition::make(*(yyvsp[-2].expr), *(yyvsp[-1].expr)); }
#line 3067 "pddl.cc" /* yacc.c:1646  */
    break;

  case 247:
#line 902 "pddl.yy" /* yacc.c:1646  */
    { (yyval.expr) = make_subtraction(*(yyvsp[-2].expr), (yyvsp[-1].expr)); }
#line 3073 "pddl.cc" /* yacc.c:1646  */
    break;

  case 248:
#line 904 "pddl.yy" /* yacc.c:1646  */
    { (yyval.expr) = &Multiplication::make(*(yyvsp[-2].expr), *(yyvsp[-1].expr)); }
#line 3079 "pddl.cc" /* yacc.c:1646  */
    break;

  case 249:
#line 906 "pddl.yy" /* yacc.c:1646  */
    { (yyval.expr) = &Division::make(*(yyvsp[-2].expr), *(yyvsp[-1].expr)); }
#line 3085 "pddl.cc" /* yacc.c:1646  */
    break;

  case 250:
#line 907 "pddl.yy" /* yacc.c:1646  */
    { (yyval.expr) = (yyvsp[0].fluent); }
#line 3091 "pddl.cc" /* yacc.c:1646  */
    break;

  case 251:
#line 910 "pddl.yy" /* yacc.c:1646  */
    { (yyval.expr) = 0; }
#line 3097 "pddl.cc" /* yacc.c:1646  */
    break;

  case 253:
#line 914 "pddl.yy" /* yacc.c:1646  */
    { prepare_fluent((yyvsp[0].str)); }
#line 3103 "pddl.cc" /* yacc.c:1646  */
    break;

  case 254:
#line 915 "pddl.yy" /* yacc.c:1646  */
    { (yyval.fluent) = make_fluent(); }
#line 3109 "pddl.cc" /* yacc.c:1646  */
    break;

  case 255:
#line 916 "pddl.yy" /* yacc.c:1646  */
    { prepare_fluent((yyvsp[0].str)); (yyval.fluent) = make_fluent(); }
#line 3115 "pddl.cc" /* yacc.c:1646  */
    break;

  case 257:
#line 924 "pddl.yy" /* yacc.c:1646  */
    { add_term((yyvsp[0].str)); }
#line 3121 "pddl.cc" /* yacc.c:1646  */
    break;

  case 258:
#line 925 "pddl.yy" /* yacc.c:1646  */
    { add_term((yyvsp[0].str)); }
#line 3127 "pddl.cc" /* yacc.c:1646  */
    break;

  case 260:
#line 929 "pddl.yy" /* yacc.c:1646  */
    { add_term((yyvsp[0].str)); }
#line 3133 "pddl.cc" /* yacc.c:1646  */
    break;

  case 261:
#line 932 "pddl.yy" /* yacc.c:1646  */
    { (yyval.term) = new Term(make_term((yyvsp[0].str))); }
#line 3139 "pddl.cc" /* yacc.c:1646  */
    break;

  case 262:
#line 933 "pddl.yy" /* yacc.c:1646  */
    { (yyval.term) = new Term(make_term((yyvsp[0].str))); }
#line 3145 "pddl.cc" /* yacc.c:1646  */
    break;

  case 264:
#line 937 "pddl.yy" /* yacc.c:1646  */
    { add_variables((yyvsp[0].strs), TypeTable::OBJECT); }
#line 3151 "pddl.cc" /* yacc.c:1646  */
    break;

  case 265:
#line 938 "pddl.yy" /* yacc.c:1646  */
    { add_variables((yyvsp[-1].strs), *(yyvsp[0].type)); delete (yyvsp[0].type); }
#line 3157 "pddl.cc" /* yacc.c:1646  */
    break;

  case 267:
#line 942 "pddl.yy" /* yacc.c:1646  */
    { (yyval.strs) = new std::vector<const std::string*>(1, (yyvsp[0].str)); }
#line 3163 "pddl.cc" /* yacc.c:1646  */
    break;

  case 268:
#line 943 "pddl.yy" /* yacc.c:1646  */
    { (yyval.strs) = (yyvsp[-1].strs); (yyval.strs)->push_back((yyvsp[0].str)); }
#line 3169 "pddl.cc" /* yacc.c:1646  */
    break;

  case 270:
#line 947 "pddl.yy" /* yacc.c:1646  */
    { add_names((yyvsp[0].strs), TypeTable::OBJECT); }
#line 3175 "pddl.cc" /* yacc.c:1646  */
    break;

  case 271:
#line 948 "pddl.yy" /* yacc.c:1646  */
    { add_names((yyvsp[-1].strs), *(yyvsp[0].type)); delete (yyvsp[0].type); }
#line 3181 "pddl.cc" /* yacc.c:1646  */
    break;

  case 273:
#line 951 "pddl.yy" /* yacc.c:1646  */
    { (yyval.strs) = new std::vector<const std::string*>(1, (yyvsp[0].str)); }
#line 3187 "pddl.cc" /* yacc.c:1646  */
    break;

  case 274:
#line 952 "pddl.yy" /* yacc.c:1646  */
    { (yyval.strs) = (yyvsp[-1].strs); (yyval.strs)->push_back((yyvsp[0].str)); }
#line 3193 "pddl.cc" /* yacc.c:1646  */
    break;

  case 275:
#line 955 "pddl.yy" /* yacc.c:1646  */
    { require_typing(); }
#line 3199 "pddl.cc" /* yacc.c:1646  */
    break;

  case 276:
#line 955 "pddl.yy" /* yacc.c:1646  */
    { (yyval.type) = (yyvsp[0].type); }
#line 3205 "pddl.cc" /* yacc.c:1646  */
    break;

  case 277:
#line 958 "pddl.yy" /* yacc.c:1646  */
    { (yyval.type) = new Type(TypeTable::OBJECT); }
#line 3211 "pddl.cc" /* yacc.c:1646  */
    break;

  case 278:
#line 959 "pddl.yy" /* yacc.c:1646  */
    { (yyval.type) = new Type(make_type((yyvsp[0].str))); }
#line 3217 "pddl.cc" /* yacc.c:1646  */
    break;

  case 279:
#line 960 "pddl.yy" /* yacc.c:1646  */
    { (yyval.type) = new Type(make_type(*(yyvsp[-1].types))); delete (yyvsp[-1].types); }
#line 3223 "pddl.cc" /* yacc.c:1646  */
    break;

  case 280:
#line 963 "pddl.yy" /* yacc.c:1646  */
    { (yyval.types) = new TypeSet(); }
#line 3229 "pddl.cc" /* yacc.c:1646  */
    break;

  case 281:
#line 964 "pddl.yy" /* yacc.c:1646  */
    { (yyval.types) = new TypeSet(); (yyval.types)->insert(make_type((yyvsp[0].str))); }
#line 3235 "pddl.cc" /* yacc.c:1646  */
    break;

  case 282:
#line 965 "pddl.yy" /* yacc.c:1646  */
    { (yyval.types) = (yyvsp[-1].types); }
#line 3241 "pddl.cc" /* yacc.c:1646  */
    break;

  case 283:
#line 966 "pddl.yy" /* yacc.c:1646  */
    { (yyval.types) = (yyvsp[-1].types); (yyval.types)->insert(make_type((yyvsp[0].str))); }
#line 3247 "pddl.cc" /* yacc.c:1646  */
    break;

  case 285:
#line 976 "pddl.yy" /* yacc.c:1646  */
    { delete (yyvsp[0].str); }
#line 3253 "pddl.cc" /* yacc.c:1646  */
    break;

  case 286:
#line 979 "pddl.yy" /* yacc.c:1646  */
    { delete (yyvsp[0].str); }
#line 3259 "pddl.cc" /* yacc.c:1646  */
    break;

  case 287:
#line 982 "pddl.yy" /* yacc.c:1646  */
    { delete (yyvsp[0].str); }
#line 3265 "pddl.cc" /* yacc.c:1646  */
    break;

  case 288:
#line 985 "pddl.yy" /* yacc.c:1646  */
    { delete (yyvsp[0].str); }
#line 3271 "pddl.cc" /* yacc.c:1646  */
    break;

  case 289:
#line 988 "pddl.yy" /* yacc.c:1646  */
    { delete (yyvsp[0].str); }
#line 3277 "pddl.cc" /* yacc.c:1646  */
    break;

  case 290:
#line 991 "pddl.yy" /* yacc.c:1646  */
    { delete (yyvsp[0].str); }
#line 3283 "pddl.cc" /* yacc.c:1646  */
    break;

  case 291:
#line 994 "pddl.yy" /* yacc.c:1646  */
    { delete (yyvsp[0].str); }
#line 3289 "pddl.cc" /* yacc.c:1646  */
    break;

  case 292:
#line 997 "pddl.yy" /* yacc.c:1646  */
    { delete (yyvsp[0].str); }
#line 3295 "pddl.cc" /* yacc.c:1646  */
    break;

  case 293:
#line 1000 "pddl.yy" /* yacc.c:1646  */
    { delete (yyvsp[0].str); }
#line 3301 "pddl.cc" /* yacc.c:1646  */
    break;

  case 294:
#line 1003 "pddl.yy" /* yacc.c:1646  */
    { delete (yyvsp[0].str); }
#line 3307 "pddl.cc" /* yacc.c:1646  */
    break;

  case 295:
#line 1006 "pddl.yy" /* yacc.c:1646  */
    { delete (yyvsp[0].str); }
#line 3313 "pddl.cc" /* yacc.c:1646  */
    break;

  case 296:
#line 1009 "pddl.yy" /* yacc.c:1646  */
    { delete (yyvsp[0].str); }
#line 3319 "pddl.cc" /* yacc.c:1646  */
    break;

  case 297:
#line 1012 "pddl.yy" /* yacc.c:1646  */
    { delete (yyvsp[0].str); }
#line 3325 "pddl.cc" /* yacc.c:1646  */
    break;

  case 298:
#line 1015 "pddl.yy" /* yacc.c:1646  */
    { delete (yyvsp[0].str); }
#line 3331 "pddl.cc" /* yacc.c:1646  */
    break;

  case 299:
#line 1018 "pddl.yy" /* yacc.c:1646  */
    { delete (yyvsp[0].str); }
#line 3337 "pddl.cc" /* yacc.c:1646  */
    break;

  case 300:
#line 1021 "pddl.yy" /* yacc.c:1646  */
    { delete (yyvsp[0].str); }
#line 3343 "pddl.cc" /* yacc.c:1646  */
    break;

  case 301:
#line 1024 "pddl.yy" /* yacc.c:1646  */
    { delete (yyvsp[0].str); }
#line 3349 "pddl.cc" /* yacc.c:1646  */
    break;

  case 302:
#line 1027 "pddl.yy" /* yacc.c:1646  */
    { delete (yyvsp[0].str); }
#line 3355 "pddl.cc" /* yacc.c:1646  */
    break;

  case 303:
#line 1030 "pddl.yy" /* yacc.c:1646  */
    { delete (yyvsp[0].str); }
#line 3361 "pddl.cc" /* yacc.c:1646  */
    break;

  case 304:
#line 1033 "pddl.yy" /* yacc.c:1646  */
    { delete (yyvsp[0].str); }
#line 3367 "pddl.cc" /* yacc.c:1646  */
    break;

  case 305:
#line 1036 "pddl.yy" /* yacc.c:1646  */
    { delete (yyvsp[0].str); }
#line 3373 "pddl.cc" /* yacc.c:1646  */
    break;


#line 3377 "pddl.cc" /* yacc.c:1646  */
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
#line 1072 "pddl.yy" /* yacc.c:1906  */


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

/* Adds :durative-actions to the requirements. */
static void require_durative_actions() {

  if(requirements->decompositions == true) {
    yyerror(":durative-actions cannot be combined with :decompositions at this time");
  }

  else {
      if (!requirements->durative_actions) {
        yywarning("assuming `:durative-actions' requirement");
        requirements->durative_actions = true;
      }
  }

}

/* Adds :decompositions to the requirements. */
static void require_decompositions() {

  if(requirements->durative_actions == true) {
    yyerror(":decompositions cannot be combined with :durative-actions at this time");
  }

  else {
      if (!requirements->decompositions) {
        yywarning("assuming `:decompositions' requirement");
        requirements->decompositions = true;
      }
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

/* Registers the relevant dummy initial and final steps to the pseudo-steps of the current 
   decomposition. */
static void register_dummy_pseudo_steps()
{
    const Step  dummy_initial_step = decomposition->pseudo_steps()[0];
	const Step* dummy_initial = new Step(dummy_initial_step);

    const Step  dummy_goal_step = decomposition->pseudo_steps()[1];
	const Step* dummy_final = new Step(dummy_goal_step);

	decomposition_pseudo_steps.insert( std::make_pair(std::string("init"), dummy_initial) );
	decomposition_pseudo_steps.insert( std::make_pair(std::string("goal"), dummy_final) );
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

        // To be a match, it first has to match the predicate type and the arity...
        if (Literal::syntactically_equal(literal, *el)) {
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

    if (typeid(pseudo_step_condition) == typeid(Atom) || typeid(pseudo_step_condition) == typeid(Negation))
    {
        const Literal* cond = dynamic_cast<const Literal*>(&pseudo_step_condition);
        if (Literal::syntactically_equal(literal, *cond)) {
            op_match = new OpenCondition(pseudo_steps.second->id(), *cond);
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
            if (typeid(**fi) == typeid(Atom) || typeid(**fi) == typeid(Negation))
            {
                const Literal* cond = dynamic_cast<const Literal*>(*fi);
                if (Literal::syntactically_equal(literal, *cond)) {
                    op_match = new OpenCondition(pseudo_steps.second->id(), *cond);
                }
            }

            else  {
                // skip this literal, and see if we can find another one in the conjunction to link to.
                continue; 
            }
        }
    }

    else
    {
        yyerror("unable to create causal link to precondition within " + pseudo_steps.second->action().name()
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
		Term t = literal.term(i);

        // Add a term binding between the terms of:
        // the effect of the first pseudo-step and
        // the precondition of the second pseudo-step
        Term effect_term = effect_match->literal().term(i);        
        Term precondition_term = op_match->literal()->term(i);

        Binding* new_binding = bind_terms(effect_term, pseudo_steps.first->id(), precondition_term, pseudo_steps.second->id());

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
