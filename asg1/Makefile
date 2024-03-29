# $Id: Makefile,v 1.1 2019-04-15 14:56:06-07 - - $

WARNING     = -Wall -Wextra -Wpedantic -Wshadow -Wold-style-cast
COMPILECPP  = g++ -std=gnu++17 -g -O0 ${WARNING}
MAKEDEPCPP  = g++ -std=gnu++17 -MM

MKFILE   = Makefile
DEPFILE  = Makefile.dep
SOURCES  = string_set.cpp main.cpp auxlib.cpp 
HEADERS  = string_set.h auxlib.h
OBJECTS  = ${SOURCES:.cpp=.o}
EXECBIN  = oc
SRCFILES = ${HEADERS} ${SOURCES} ${MKFILE}

all : ${EXECBIN}

${EXECBIN} : ${OBJECTS}
	${COMPILECPP} ${OBJECTS} -o ${EXECBIN}

%.o : %.cpp
	${COMPILECPP} -c $<

ci :
	cid + ${SRCFILES}

clean :
	-rm ${OBJECTS} ${DEPFILE}

spotless : clean
	- rm ${EXECBIN} Listing.ps Listing.pdf test.out test.grind

${DEPFILE} :
	${MAKEDEPCPP} ${SOURCES} >${DEPFILE}

dep :
	- rm ${DEPFILE}
	${MAKE} --no-print-directory ${DEPFILE}

include ${DEPFILE}

test : ${EXECBIN}
	valgrind --log-file=test.grind --leak-check=full\
                ${EXECBIN} * * * >test.out 2>&1

lis : test
	mkpspdf Listing.ps ${SRCFILES} ${DEPFILE} test.out test.grind

again : ${SRCFILES}
	make --no-print-directory spotless dep ci test lis
