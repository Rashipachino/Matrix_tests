#include "doctest.h"
#include "Matrix.hpp"
using namespace zich;

#include <string>
#include <algorithm>
using namespace std;
string nospaces(string input) {
	std::erase(input, ' ');
	std::erase(input, '\t');
	std::erase(input, '\n');
	std::erase(input, '\r');
	return input;
}

TEST_CASE("constructor"){
    std::vector<double> vec1 = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    zich::Matrix m{vec1, 3, 3};
	CHECK(nospaces(cout << a << endl) == nospaces("[1 2 3]\n"
												"[4 5 6]\n"
												"[7 8 9]"));
}
TEST_CASE("addition"){
    std::vector<double> vec1 = {1, 0, 0, 0, 1, 0, 0, 0, 1};
    std::vector<double> vec2 = {1, 2, 3, 4, 5, 6, 7, 8, 9};
	std::vector<double> vec3 = {1, 2, 3, 4, 5, 6};
    zich::Matrix m1{vec1, 3, 3};
	zich::Matrix m2{vec2, 3, 3};
	CHECK(nospaces(cout << m1 + m2 << endl) == nospaces("[2 2 3]\n"
														"[4 6 6]\n"
														"[7 8 10]"));
	CHECK_THROWS(cout << m1 + m3 << endl);
}
TEST_CASE("plus"){}
TEST_CASE("positive"){}
TEST_CASE("subtraction"){}
TEST_CASE("minus"){}
TEST_CASE("negative"){}
TEST_CASE("gte"){}
TEST_CASE("gt"){}
TEST_CASE("lte"){}
TEST_CASE("lt"){}
TEST_CASE("equals"){}
TEST_CASE("not equal"){}
TEST_CASE("increment++"){}
TEST_CASE("++increment"){}
TEST_CASE("decrement--"){}
TEST_CASE("--decrement"){}
TEST_CASE("scalor mutliplication"){}
TEST_CASE("matrix multiplication"){}
