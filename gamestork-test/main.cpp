//-----------------------------------------------------------------------------
/**
File: main.cpp
System: Gamestork RPG Character Generator
License: LGPL
(c) Chris Aiken 2017

Description: Unit test runner
*/
//-----------------------------------------------------------------------------

#include <UnitTest++.h>
#include <iostream>


/**	Unit test for unit test framework
*/
TEST(Sanity) {
	CHECK_EQUAL(1, 1);
}


int main() {
	std::cout << std::endl;
	return UnitTest::RunAllTests();
}