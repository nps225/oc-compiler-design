# $Id: Makefile,v 1.40 2019-04-18 13:38:03-07 - - $

DEPSFILE  = Makefile.deps
NOINCLUDE = ci clean spotless
NEEDINCL  = ${filter ${NOINCLUDE}, ${MAKECMDGOALS}}
WARNING   = -Wall -Wextra -Wpedantic -Wshadow -Wold-style-cast
GPP       = g++ -std=gnu++17 -g -O0
GPPWARN   = ${GPP} ${WARNING} -fdiagnostics-color=never
GPPYY     = ${GPP} -Wno-sign-compare -Wno-register
MKDEPS    = g++ -std=gnu++17 -MM
GRIND     = valgrind --leak-check=full --show-reachable=yes
UTILBIN   = /afs/cats.ucsc.edu/courses/cmps104a-wm/bin/

MODULES   = astree lyutils string_set auxlib asg3 symbol 
HDRSRC    = ${MODULES:=.h}
CPPSRC    = ${MODULES:=.cpp} main.cpp
FLEXSRC   = scanner.l
BISONSRC  = parser.y
PARSEHDR  = yyparse.h
LEXCPP    = yylex.cpp
PARSECPP  = yyparse.cpp
# LEXOUT    = yylex.output
PARSEOUT  = yyparse.output
REPORTS   = ${PARSEOUT} #${LEXOUT}
CGENS     = ${LEXCPP} ${PARSECPP}
ALLGENS   = ${PARSEHDR} ${CGENS}
EXECBIN   = oc
ALLCSRC   = ${CPPSRC} ${CGENS}
OBJECTS   = ${ALLCSRC:.cpp=.o}
MODSRC    = ${foreach MOD, ${MODULES}, ${MOD}.h ${MOD}.cpp}
MISCSRC   = ${filter-out ${MODSRC}, ${HDRSRC} ${CPPSRC}}
ALLSRC    = README ${FLEXSRC} ${BISONSRC} ${MODSRC} ${MISCSRC} Makefile
TESTINS   = ${wildcard test*.in}
EXECTEST  = ${EXECBIN} -ly
LISTSRC   = ${ALLSRC} ${DEPSFILE} ${PARSEHDR}

all : ${EXECBIN}

${EXECBIN} : ${OBJECTS}
	${GPPWARN} -o${EXECBIN} ${OBJECTS}

yylex.o : yylex.cpp
	${GPPYY} -c $<

yyparse.o : yyparse.cpp
	${GPPYY} -c $<

%.o : %.cpp
	${GPPWARN} -c $<

${LEXCPP} : ${FLEXSRC}
	flex --outfile=${LEXCPP} ${FLEXSRC}

${PARSECPP} ${PARSEHDR} : ${BISONSRC}
	bison --defines=${PARSEHDR} --output=${PARSECPP} ${BISONSRC}

ci : ${ALLSRC} ${TESTINS}


clean :
	- rm ${OBJECTS} ${ALLGENS} ${DEPSFILE} ${REPORTS}

spotless : clean
	- rm ${EXECBIN}

deps : ${ALLCSRC}
	@ echo "# ${DEPSFILE} created `date` by ${MAKE}" >${DEPSFILE}
	${MKDEPS} ${ALLCSRC} >>${DEPSFILE}

${DEPSFILE} :
	@ touch ${DEPSFILE}
	${MAKE} --no-print-directory deps

tests : ${EXECBIN}
	touch ${TESTINS}
	gmake --no-print-directory ${TESTINS:.in=.out}

%.out %.err : %.in
	${GRIND} --log-file=$*.log ${EXECTEST} $< 1>$*.out 2>$*.err; \
	echo EXIT STATUS = $$? >>$*.log

again :
	gmake --no-print-directory spotless deps ci all

ifeq "${NEEDINCL}" ""
include ${DEPSFILE}
endif
