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