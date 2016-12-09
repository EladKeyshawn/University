#########################################################
# Student information
#########################################################
# change to your ID as it appears in moodle!
ID= 12345678
#########################################################

#########################################################
# compiler stuff 
#########################################################
CC= gcc
CFLAGS= -Wall -Wvla -Werror -g
#COPTFLAGS= -O -DNDEBUG

CXX= g++
CXXFLAGS= $(CFLAGS) 

CEXELINKFLAGS=
CXXTEST1LINKFLAGS= -lgtest -lgtest_main -pthread
##########################################################

#######################
# executables name
#######################
EXE1= LinSeperatorMain
TEST1= LinSeperatorTest
EXE2= MeanWindowMain
TEST2= MeanWindowTest

#######################

##########################################################
# sources files
##########################################################
SRCSEXE1NOMAIN= LinSeperator.c
SRCSEXE1MAIN= $(EXE1).c
SRCSEXE2NOMAIN= MeanWindow.c
SRCSEXE2MAIN= $(EXE2).c
SRCSEXE1= $(SRCSEXE1NOMAIN) $(SRCSEXE1MAIN)
SRCSEXE2= $(SRCSEXE2NOMAIN) $(SRCSEXE2MAIN)
HEADERMEAN= MeanWindow.h
HEADERLIN= LinSeperator.h
HEADERMEANHELPER= MeanWindowHelperFunctions.h
HEADERLINHELPER= LinSeperatorHelperFunctions.h

# There is no SRCTEST1MAIN as we are linking with gtest_main that has main
SRCSTEST1NOMAIN= $(TEST1).cpp
SRCSTEST2NOMAIN= $(TEST2).cpp
##########################################################

#########################################################
# actions
#########################################################
all: $(EXE1) $(EXE2) $(TEST1) $(TEST2) 

$(EXE1): $(subst .c,.o,$(SRCSEXE1))
	$(CC) $(CFLAGS) $(CEXELINKFLAGS) $^ -o $@

$(EXE2): $(subst .c,.o,$(SRCSEXE2))
	$(CC) $(CFLAGS) $(CEXELINKFLAGS) $^ -o $@

$(TEST1): $(subst .c,.o,$(SRCSEXE1NOMAIN)) $(subst .cpp,.o,$(SRCSTEST1NOMAIN))
	$(CXX) $(CXXFLAGS) $^ -o $@ $(CXXLINKFLAGS) $(CXXTEST1LINKFLAGS)
	./$@

$(TEST2): $(subst .c,.o,$(SRCSEXE2NOMAIN)) $(subst .cpp,.o,$(SRCSTEST2NOMAIN))
	$(CXX) $(CXXFLAGS) $^ -o $@ $(CXXLINKFLAGS) $(CXXTEST1LINKFLAGS)
	./$@

clean:
	rm *.o $(EXE1) $(EXE2) $(TEST2) $(TEST1) $(ID).zip -f

depend: $(SRCSEXE1) $(SRCSEXE2) $(SRCSTEST2) $(SRCSTEST1NOMAIN) 
	makedepend -Y -- $(CXXFLAGS) -- $^

zipfile:
	zip $(ID).zip $(SRCSEXE1NOMAIN) $(SRCSTEST1NOMAIN) $(SRCSEXE2NOMAIN) $(SRCSTEST2NOMAIN) $(HEADERLINHELPER) $(HEADERMEANHELPER) LinSeperator.in.* LinSeperator.out.* MeanWindow.in.* MeanWindow.out.*

checkzipfile:
	rm checkSubmission -fr ; \
	mkdir checkSubmission ; \
	cd checkSubmission ; \
	mkdir Examples ; \
	cp ../$(ID).zip . ;\
	unzip $(ID).zip ;\
	cp ../Examples/*.*.* Examples ;\
	cp ../Makefile . ;\
	cp ../$(SRCSEXE1MAIN) . ;\
	cp ../$(SRCSEXE2MAIN) . ;\
	cp ../$(HEADERMEAN) . ;\
	cp ../$(HEADERLIN) . ;\
	make ;\
	cd ..

# There is no SRCTEST1MAIN as we are linking with gtest_main that has main
SRCSTEST1NOMAIN= $(TEST1).cpp
##############################################
# installs that should be done once
##############################################
installonce: gtestinstall makedependinstall valgrindinstall

gtestinstall: 
	sudo apt-get install libgtest-dev
	sudo apt-get install cmake
	cd /usr/src/gtest; \
	sudo cmake CMakeLists.txt; \
	sudo make; \
	sudo cp *.a /usr/lib
	sudo chmod u+r /usr/lib/libgtest.a
	sudo chmod u+r /usr/lib/libgtest_main.a

makedependinstall:
	sudo apt-get install xutils-dev

valgrindinstall:
	sudo apt-get install valgrind
##############################################

.PHONY: all clean depend installonce gtestinstall makedependinstall valgrindinstall zipfile


# DO NOT DELETE THIS LINE -- make depend depends on it.

LinSeperator.o: LinSeperator.h LinSeperatorHelperFunctions.h
LinSeperatorMain.o: LinSeperator.h
MeanWindow.o: MeanWindow.h MeanWindowHelperFunctions.h
MeanWindowMain.o: MeanWindow.h
LinSeperatorTest.o: LinSeperator.h LinSeperatorHelperFunctions.h
