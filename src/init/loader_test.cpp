
#include "../../include/catch.h"

#include "../../include/init/loader.h"

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#include <cstdio>

std::string testFileName = "testFile.txt";
std::string lineOne = "first test line";
std::string lineTwo = "second test line";

const int BAD_INDEX = -1;

void initTestFile()
{
    std::ofstream testFile(testFileName);
    testFile << lineOne << std::endl;
    testFile << lineTwo << std::endl;
    testFile.close();
}

TEST_CASE("test loader getLine")
{
    initTestFile();
    Loader testLoader(testFileName);
    REQUIRE(testLoader.getLine(0) == lineOne);
    REQUIRE(testLoader.getLine(1) == lineTwo);
    remove(testFileName.c_str());
}

TEST_CASE("test loader getData")
{
    initTestFile();
    Loader testLoader(testFileName);
    std::vector<std::string> testData = {lineOne, lineTwo};
    REQUIRE(testData == testLoader.getData());
    remove(testFileName.c_str());
}

TEST_CASE("test loader getLine incorrectIndex")
{
    initTestFile();
    Loader testLoader(testFileName);
    REQUIRE(testLoader.getLine(BAD_INDEX) == "");
    remove(testFileName.c_str());
}


