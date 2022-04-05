#include "doctest.h"
#include "Matrix.hpp"
using namespace zich;

#include <string>
#include <algorithm>
using namespace std;
// string nospaces(string input) {
// 	std::erase(input, ' ');
// 	std::erase(input, '\t');
// 	std::erase(input, '\n');
// 	std::erase(input, '\r');
// 	return input;
// }
std::vector<double> vec1 = {1, 0, 0, 0, 1, 0, 0, 0, 1};
std::vector<double> vec2 = {1, 2, 3, 4, 5, 6, 7, 8, 9};
std::vector<double> vec3 = {1, 2, 3, 4, 5, 6};
std::vector<double> vec4 = {20, 8, 4, 2, 3, 5, 6, 6, 6, 0, 2, 4};
std::vector<double> vec6 = {1, 3, 5, 7, 2, 4};
std::vector<double> vec7 = {2, 4, 6, 8, 1, 3};
std::vector<double> vec8 = {0, 0, 0, 0, 0, 0, 0, 0};
zich::Matrix m1{vec1, 3, 3};
zich::Matrix m2{vec2, 3, 3};
zich::Matrix m3{vec3, 2, 3};
zich::Matrix m4{vec4, 3, 4};
zich::Matrix m5{vec4, 3, 4};
zich::Matrix m6{vec6, 2, 3};
zich::Matrix m7{vec7, 3, 2};
zich::Matrix m8{vec8, 4, 2};

TEST_CASE("constructor"){
	// CHECK(nospaces(cout << m1 << endl) == nospaces("[1 2 3]\n"
	// 											"[4 5 6]\n"
	// 											"[7 8 9]"));
	CHECK(m1.mat() == {1, 2, 3, 4, 5, 6, 7,  8,  9});
}

TEST_CASE("matrix addition"){
	// CHECK(nospaces(cout << m1+m2 << endl) == nospaces("[2 2 3]\n"
	// 												"[4 6 6]\n"
	// 												"[7 8 10]"));
	CHECK((m1+m2).mat() == {2, 2, 3, 4, 6, 6, 7, 8, 10});
	CHECK_THROWS(m1+m3);
}

TEST_CASE("addition"){
	// CHECK(nospaces(cout << m3+=4) == nospaces("[5 6 7]\n"
	// 										"[8 9 10]"));
	CHECK((m3+=4).mat() == {5, 6, 7, 8, 9, 10});
}

TEST_CASE("positive"){
	// CHECK(nospaces(cout << +m4) == nospaces("[20 8 4 2]\n"
	// 										"[3 5 6 6]\n"
	// 										"[6 0 2 4]"));
	CHECK((+m4).mat() == {20, 8, 4, 2, 3, 5, 6, 6, 6, 0, 2, 4});
}

TEST_CASE("matrix subtraction"){
	CHECK((m1-m2).mat() == {0, -2, -3, -4, -4, -6, -7, -8, -8});
	CHECK_THROWS(m1-m4);
}

TEST_CASE("subtraction"){
	// CHECK(nospaces(cout << m4-=12 << endl) == nospaces("[8 -4 -8 -10]\n"
	// 												"[-9 -7 -6 -6]\n"
	// 												"[-6 -12 -10 -8]"));
	CHECK((m4-=12).mat() == {8, -4, -8, -10, -9, -7, -6, -6, -6, -12, -10, -8});
}

TEST_CASE("negative"){
	CHECK((-m1).mat() == {-1, 0, 0, 0, -1, 0, 0, 0, -1});
}

TEST_CASE("gte"){
	CHECK(m2>=m1);
	CHECK(m4>=m5);
	CHECK_FALSE(m1>=m2);
	CHECK_THROWS(m4>=m1);
}

TEST_CASE("gt"){
	CHECK(m2>m1);
	CHECK_FALSE(m1>m2);
	CHECK_THROWS(m5>m3);
}

TEST_CASE("lte"){
	CHECK(m4<=m5);
	CHECK(m5<=m4);
	CHECK_FALSE(m2<=m1);
	CHECK_THROWS(m5<=m3);
}

TEST_CASE("lt"){
	CHECK(m1<m2);
	CHECK_FALSE(m1>m2);
	CHECK_THROWS(m2<m3);	
}

TEST_CASE("equals"){
	CHECK(m4==m5);
	CHECK_FALSE(m1==m2);
	CHECK_THROWS(m5==m3);
}

TEST_CASE("not equal"){
	CHECK(m1!=m2);
	CHECK_FALSE(m4!=m5);
	CHECK_THROWS(m5!=m3);
}

TEST_CASE("increment++"){
	CHECK((m1++).mat() == {1, 0, 0, 0, 1, 0, 0, 0, 1});
}

TEST_CASE("++increment"){
	CHECK((++m3).mat() == {2, 3, 4, 5, 6, 7});
}

TEST_CASE("decrement--"){
	CHECK((m2--).mat() == {1, 2, 3, 4, 5, 6, 7, 8, 9});
}

TEST_CASE("--decrement"){
	CHECK((--m4).mat() == {19, 7, 3, 1, 2, 4, 5, 5, 5, -1, 1, 3});
}

TEST_CASE("scalor mutliplication"){
	CHECK((m7*=5).mat() == {10, 20, 30, 40, 5, 15});
}

TEST_CASE("matrix multiplication"){
	CHECK((m6*m7).mat() == {25, 43, 30, 56});
	CHECK_THROWS(m5*m6);
}

TEST_CASE("cout and cin"){
	CHECK(cout << m8 << endl == "[0 0]\n"
								"[0 0]\n"
								"[0 0]\n"
								"[0 0]");
}
