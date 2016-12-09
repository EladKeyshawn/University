extern "C" {
    #include "LinSeperator.h"
	#include "LinSeperatorHelperFunctions.h"
}
#include "gtest/gtest.h"
#include <iostream>
#include <cstdlib>
#include <string>
#include <sstream>

// example of BlackBox Testing
TEST(LinSeperator, FirstTest) {
	std::string TestInFile = "Examples/LinSeperator.in.1";              // given Input example
	std::string TestOutFile = "Examples/LinSeperator.out.1";            // givem Output example for comppersion
	std::string TestOutDest = "testLin.out";                            // output for the test
    LinSeperator(TestInFile.c_str(), TestOutDest.c_str());              // Call for the LinSeperator function with the inut and output file
    std::string diffCMD = "diff -w " + TestOutFile + " " + TestOutDest;
	int result = std::system(diffCMD.c_str());                          // should return 0 on success. 1 for difference
    ASSERT_EQ(0, result);
}

// also make sure you test your helper functions
