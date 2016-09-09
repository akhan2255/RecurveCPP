# Recurve

<p align="center">
  <img src="https://raw.githubusercontent.com/recardona/Recurve/recardona/dpocl-parsing/img/icon.png" width="350"/>
</p>

Recurve is a decompositional planner; i.e. a planning system that combines *hierarchical reasoning* as discussed in hierarchical task networks (HTNs) and *least-commitment refinement reasoning* as discussed in partial-order causal link planning. For details on the decompositional planning process, [consult this paper](http://www.research.ed.ac.uk/portal/files/18535716/Young_Pollack_ET_AL_1994_Decomposition_and_Casuality_in_Partial_Order_Planning.pdf).
More details for this section are forthcoming.

Recurve is a variant of the [versatile heuristic partial order planner](http://www.tempastic.org/vhpop/) originally developed by [Håkan L. S. Younes](http://www.cs.cmu.edu/~lorens/).

## Etymology

The system is called *Recurve* in reference to its predecessor, the [Longbow planning system](https://web.archive.org/web/19991010235639/http://www.isp.pitt.edu/~young/longbow/). Longbow was the more popular of the two publicly available planners able to perform decompositional planning (the other being the [DPOCL](https://web.archive.org/web/19990427093301/http://www.isp.pitt.edu/%7Eyoung/dpocl/dpocl.html)). Like Longbow, a [Recurve is a type of bow](https://en.wikipedia.org/wiki/Recurve_bow).  VHPOP was designed to enable POCL planners to compete with state-of-the-art heuristic search planners in terms of speed, and so I thought it appropriate to name the system after a type of bow designed for speed. 

## Install

### Installing as a Visual Studio Project
Currently, the only "installation" this project supports is installing as a Visual Studio 2013 (VS2013) project on Windows (7+).  The following instructions assume you have access to a VS2013 development environment.

#### Instructions
In the instructions that follow, I'm going to assume that you have no blank characters in any of the paths that I reference. Blank characters can wreak havoc on Cygwin (which is needed), so use them at your own risk.

First, install [Cygwin](https://www.cygwin.com/) (I use the 64-bit version, but in theory it should work with the 32-bit version as well). When prompted for packages, install the following ones (both Developer and Libs when available):
   1. mercurial
   2. git
   3. make
   4. python
   5. gcc
   6. g++
   7. flex
   8. bison
   9. gawk

Second, place the cygwin bin folder (`$PATH_TO_CYGWIN\bin\`) on the Environment Path
   1. Right-click on **My Computer** (in Windows 8.1, this is called **This PC**), and select **Properties**. Click on **Advanced systems settings** and then click on **Environment Variables** (it should be in the Advanced Tab).
   2. Find the *Path* variable within the **System variables** table, click-on it, and then click on **Edit**. 
   3. Append `$PATH_TO_CYGWIN\bin\` to the Variable value.

Third, startup Cygwin (which creates a folder `$PATH_TO_CYGWIN\home\$USER`, and places you there), and enter:
```bash
mkdir -p Developer/include
cd Developer/include
touch unistd.h
```

Fourth, open the file `unistd.h` in a text editor of your choice and copy the following into it:
```c
#ifdef __MINGW32__
#include_next <unistd.h>
#else
#include <io.h>
#include <process.h>
#endif
```

Fifth, add the following new System variable in the Environment Variables:
 * Variable Name: `BISONFLEX_INC`
 * Variable Value: `$PATH_TO_CYGWIN\home\$USER\Developer\include\`



 
 
------------
### VHPOP Details
VHPOP is a versatile heuristic partial order planner loosely based on
UCPOP with the following main features:
* Can plan with either ground or lifted actions.
* Can enforce joint parameter domain constraints when using lifted actions.
* Has several different plan ranking heuristics to choose from that can be combined into complex plan ranking functions.
* Efficiently implements all common flaw selection strategies, including LCFR and ZLIFO, and many novel ones, and allows flaw selection strategies to be specified using a concise notation.
* Several flaw selection strategies can be used simultaneously.
* Implements A\* , IDA\*, and hill climbing search.
* Fully supports levels 1 and 3 of PDDL2.1.

For installation instructions, see `INSTALL`.
For copyright information and distribution restrictions, see `COPYING`.


#### Search Algorithms
You can select the search algorithms to use with the `-s` flag.  The
options are as follows:
* `A` for A*.
* `IDA` for IDA*.
* `HC` for hill climbing.


#### Action Costs
VHPOP currently provides three definitions of action costs, selected through the `-a` flag, to use in conjunction with the additive heuristic:
* `UNIT` uses unit cost for all actions.
* `DURATION` uses absolute duration as action costs.
* `RELATIVE` uses relative duration as action costs.


#### Plan Selection
The plan ranking function is specified with the `-h` flag.  A plan ranking function is a sequence of simple heuristic plan ranking functions in decreasing order of significance.  

For example, `S+OC/LIFO` uses the number of steps plus the number of open conditions of a plan as primary rank, and selects plans in LIFO order in case the primary rank of several plans are the same.  Some simple plan ranking functions use a weight, which can be specified with the `-w` flag.  VHPOP implements the following simple plan ranking functions:

* `LIFO` gives priority to plans created later.
* `FIFO` gives priority to plans created earlier.
* `OC` gives priority to plans with few open conditions.
* `UC` gives priority to plans with few threatened links.
* `BUC` gives priority to plans with no threatened links.
* `S+OC` uses `h(p) = |S(p)| + w*|OC(p)|` for plan `p`.
* `UCPOP` uses `h(p) = |S(p)| + w(|OC(p)| + |UC(p)|)` for plan `p`.
* `ADD_COST` uses the additive cost heuristic.
* `ADD_WORK` uses the additive work heuristic.
* `ADD` uses `h(p) = |S(p)| + w*ADD_COST` for plan `p`.
* `ADDR` is like `ADD`, but tries to take reuse into account.
* `ADDR_COST` uses the `ADDR` cost heuristic.
* `ADDR_WORK` uses the `ADDR` work heuristic.
* `MAX` uses the max heuristic.
* `MAX_COST` uses the max cost heuristic.
* `MAX_WORK` uses the max work heuristic.
* `MAXR` is like `MAX`, but tries to take reuse into account.
* `MAXR_COST` uses the `MAXR` cost heuristic.
* `MAXR_WORK` uses the `MAXR` work heuristic.

#### Flaw Selection
A flaw selection strategy is an ordered list of selection criteria. Each selection criterion is of the form:
```
{flaw types}[max refinements]ordering criterion
```
This applies to flaws of the given types which can be resolved in at most "max refinements" ways.  The limit on number of refinements is optional and can be left out.  The ordering criterion is used to order flaws that the selection criterion applies to.  LIFO order is used if the ordering criterion cannot be used to distinguish two or more flaws.

The different flaw types are:
* `o` (open condition), 
* `t` (static open condition), 
* `l` (local open condition), 
* `u` (unsafe open condition),
* `n` (non-separable threat), and 
* `s` (separable threat).  

The different ordering criteria are: 
* `LIFO`, 
* `FIFO`, 
* `R` (random), 
* `LR` (least refinements first), 
* `MR` (opposite of `LR`), 
* `New` (open conditions that can be resolved with new step first), 
* `Reuse` (opposite of `New`),
* `MC_h` (most cost with heuristic `h`), 
* `LC_h` (opposite of `MC_h`), 
* `MW_h` (most work with heuristic `h`), 
* `LW_h` (opposite of `MW_h`).

Flaws are matched with selection criteria, and it is required for completeness that every flaw matches at least one selection criterion in a flaw selection strategy.  The flaw that matches the earliest selection criterion, and is ordered before any other flaws matching the same criterion (according to the ordering criterion), is the flaw that gets selected by the flaw selection strategy.  

Note that we do not always need to test all flaws.  If, for example, the first selection criterion is `{n,s}LIFO`, and we have found a threat, then we do not need to consider any other flaws for selection.

Most common flaw selection strategies are predefined, along with several novel ones:

* `UCPOP` &rarr; `{n,s}LIFO/{o}LIFO`
* `UCPOP-LC` &rarr; `{n,s}LIFO/{o}LR`
* `DSep-LIFO` &rarr; `{n}LIFO/{o}LIFO/{s}LIFO`
* `DSep-FIFO` &rarr; `{n}LIFO/{o}FIFO/{s}LIFO`
* `DSep-LC` &rarr; `{n}LIFO/{o}LR/{s}LIFO`
* `DUnf-LIFO` &rarr; `{n,s}0LIFO/{n,s}1LIFO/{o}LIFO/{n,s}LIFO`
* `DUnf-FIFO` &rarr; `{n,s}0LIFO/{n,s}1LIFO/{o}FIFO/{n,s}LIFO`
* `DUnf-LC` &rarr;	`{n,s}0LIFO/{n,s}1LIFO/{o}LR/{n,s}LIFO`
* `DUnf-Gen` &rarr;	`{n,s,o}0LIFO/{n,s,o}1LIFO/{n,s,o}LIFO`
* `DRes-LIFO` &rarr; `{n,s}0LIFO/{o}LIFO/{n,s}LIFO`
* `DRes-FIFO` &rarr; `{n,s}0LIFO/{o}FIFO/{n,s}LIFO`
* `DRes-LC` &rarr; `{n,s}0LIFO/{o}LR/{n,s}LIFO`
* `DEnd-LIFO` &rarr; `{o}LIFO/{n,s}LIFO`
* `DEnd-FIFO` &rarr; `{o}FIFO/{n,s}LIFO`
* `DEnd-LC` &rarr; `{o}LR/{n,s}LIFO`
* `LCFR` &rarr;	`{n,s,o}LR`
* `LCFR-DSep` &rarr; `{n,o}LR/{s}LR`
* `ZLIFO` &rarr; `{n}LIFO/{o}0LIFO/{o}1NEW/{o}LIFO/{s}LIFO`
* `ZLIFO*` &rarr; `{o}0LIFO/{n,s}LIFO/{o}1NEW/{o}LIFO`
* `Static` &rarr; `{t}LIFO/{n,s}LIFO/{o}LIFO`
* `LCFR-Loc` &rarr;	`{n,s,l}LR`
* `LCFR-Conf` &rarr; `{n,s,u}LR/{o}LR`
* `LCFR-Loc-Conf` &rarr; `{n,s,u}LR/{l}LR`
* `MC` &rarr; `{n,s}LR/{o}MC_add`
* `MC-Loc` &rarr; `{n,s}LR/{l}MC_add`
* `MC-Loc-Conf`	&rarr; `{n,s}LR/{u}MC_add/{l}MC_add`
* `MW`	&rarr; `{n,s}LR/{o}MW_add`
* `MW-Loc` &rarr; `{n,s}LR/{l}MW_add`
* `MW-Loc-Conf` &rarr; `{n,s}LR/{u}MW_add/{l}MW_add`

Several flaw selection strategies can be used simultaneously in a
round-robin scheme.  For example,

```sh
  ./vhpop -f LCFR -l 10000 -f MW -l unlimited <domain> <problem>
```
specifies that both `LCFR` and `MW` should be used.  The search limit with `LCFR` is 10,000 generated search nodes, and with `MW` the number of search nodes generated is only limited by the physical memory of the machine.  

The use of multiple flaw selection strategies is similar to running multiple instances of VHPOP concurrently.  A separate search queue is kept for each flaw selection strategy.  Flaw selection strategies are switched after 1,000; 2,000; 4,000; 8,000; etc. generated search nodes or when the search limit is reached for a strategy.  The first plan, if any, found is returned as the solution regardless of which flaw selection strategy was used.


#### Plans for Future Improvements
* Add better support for plan optimization metric (currently ignored).
* Allow secondary ordering criterion for flaw selection strategies.
* Add support for numeric effects and preconditions (level 2 of PDDL2.1).
* Add support for axioms (PDDL2.2).

------------

## Credits
- bow (icon) by Christopher T. Howlett from the Noun Project
- Robot (icon) by Roman Zhigora from the Noun Project
