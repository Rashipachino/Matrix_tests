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

TEST_CASE("addition"){
    std::vector<double> vec1 = {1, 0, 0, 0, 1, 0, 0, 0, 1};
    std::vector<double> vec2 = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    zich::Matrix m{vec1, 3, 3};
    CHECK((cout << m._mat << endl) == "{2, 2, 3, 4, 6, 6, 7, 8, 10}")
}