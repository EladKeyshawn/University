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

CXXTESTLINKFLAGS= -lgtest -lgtest_main -pthread
##########################################################


##########################################################
# sources files
##########################################################
SRCSNOMAIN= MyString.c

# There is no SRCTESTMAIN as we are linking with gtest_main that has main
SRCSTESTNOMAIN= MyStringTest.cpp
##########################################################


#######################
# executables name
#######################
TEST= MyStringTest
#######################


#########################################################
# actions
#########################################################
# all: $(TEST)

all: main
main: main.o MyString.o
		 gcc -o main main.o MyString.o

main.o: main.c MyString.h
		 gcc -c main.c

MyString.o: MyString.c MyString.h
		 gcc -c MyString.c
$(TEST): $(subst .c,.o,$(SRCSNOMAIN)) $(subst .cpp,.o,$(SRCSTESTNOMAIN))
	$(CXX) $(CXXFLAGS) $^ -o $@ $(CXXLINKFLAGS) $(CXXTESTLINKFLAGS)
	./$@

clean:
	rm *.o $(TEST) -f

depend: $(SRCSTESTNOMAIN)
	makedepend -Y -- $(CXXFLAGS) -- $^

zipfile:
	zip $(ID).zip MyString.h $(SRCSNOMAIN) $(SRCSTESTNOMAIN)

checkzipfile:
	rm checkSubmission -fr ; \
	mkdir checkSubmission ; \
	cd checkSubmission ; \
	cp ../$(ID).zip . ;\
	unzip $(ID).zip ;\
	cp ../MyString.h . ;\
	cp ../$(SRCSNOMAIN) . ;\
	cp ../$(SRCSTESTNOMAIN) . ;\
	cp ../Makefile . ;\
	make ;\
	cd ..

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
##############################################

.PHONY: all clean depend installonce gtestinstall makedependinstall valgrindinstall


# DO NOT DELETE THIS LINE -- make depend depends on it.

MyString.o: MyString.h
MyStringTest.o: MyString.h
