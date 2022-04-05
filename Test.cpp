#include "doctest.h"
#include "Matrix.hpp"
#include <vector>
using namespace zich;

#include <string>
#include <algorithm>
using namespace std;
std::vector<double> vec1 = {1, 0, 0, 0, 1, 0, 0, 0, 1};
std::vector<double> vec2 = {1, 2, 3, 4, 5, 6, 7, 8, 9};
std::vector<double> vec3 = {1, 2, 3, 4, 5, 6};
std::vector<double> vec4 = {20, 8, 4, 2, 3, 5, 6, 6, 6, 0, 2, 4};
std::vector<double> vec6 = {1, 3, 5, 7, 2, 4};
std::vector<double> vec7 = {2, 4, 6, 8, 1, 3};
std::vector<double> vec8 = {0, 0, 0, 0, 0, 0, 0, 0};
std::vector<double> vec9 = {4, 4, 4, 4, 4, 4};
zich::Matrix m1{vec1, 3, 3};
zich::Matrix m2{vec2, 3, 3};
zich::Matrix m3{vec3, 2, 3};
zich::Matrix m4{vec4, 3, 4};
zich::Matrix m5{vec4, 3, 4};
zich::Matrix m6{vec6, 2, 3};
zich::Matrix m7{vec7, 3, 2};
zich::Matrix m8{vec8, 4, 2};
zich::Matrix m9{vec9, 2, 3};

TEST_CASE("constructor"){
	CHECK_THROWS(zich::Matrix wrong1(vec8, 4, -2));
	CHECK_THROWS(zich::Matrix wrong2(vec8, -4, -2));
	CHECK_THROWS(zich::Matrix wrong3(vec8, -4, 2));
	CHECK_THROWS(zich::Matrix wrong4(vec8, 0, -2));
	CHECK_THROWS(zich::Matrix wrong1(vec8, 3, 3));
}

TEST_CASE("matrix addition"){
	vector<double> v2 = {2, 2, 3, 4, 6, 6, 7, 8, 10};
	zich::Matrix check2(v2, 2, 3);
	zich::Matrix m1m2 = m1+m2;
	CHECK(m1m2 == check2);
	CHECK_THROWS(m1+m3);
}

TEST_CASE("addition"){
	vector<double> v3 = {5, 6, 7, 8, 9, 10};
	zich::Matrix check3(v3, 2, 3);
	m3+=m9;
	CHECK(m3 == check3);
	CHECK_THROWS(m1+=m3);
}

TEST_CASE("positive"){
	vector<double> v4 = {20, 8, 4, 2, 3, 5, 6, 6, 6, 0, 2, 4};
	zich::Matrix m4plus = +m4;
	zich::Matrix check4(v4, 3, 4);
	CHECK(m4plus == check4);
}

TEST_CASE("matrix subtraction"){
	vector<double> v5 = {0, -2, -3, -4, -4, -6, -7, -8, -8};
	zich::Matrix m1m2 = m1-m2;
	zich::Matrix check5(v5, 3, 3);
	CHECK(m1m2 == check5);
	CHECK_THROWS(m1-m4);
}

TEST_CASE("subtraction"){
	vector<double> v6 = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	m4-=m5;
	zich::Matrix check6(v6, 3, 4);
	CHECK(m4 == check6);
}

TEST_CASE("negative"){
	vector<double> v7 = {-1, 0, 0, 0, -1, 0, 0, 0, -1};
	zich::Matrix m1minus = -m1;
	zich::Matrix check7(v7, 3, 3);
	CHECK(m1minus == check7);
}

TEST_CASE("gte"){
	CHECK(m2>=m1);
	CHECK(m4>=m5);
	CHECK_FALSE(m1>=m2);
	bool temp;
	CHECK_THROWS(temp=m4>=m1);
}

TEST_CASE("gt"){
	CHECK(m2>m1);
	CHECK_FALSE(m1>m2);
	bool temp;
	CHECK_THROWS(temp=m5>m3);
}

TEST_CASE("lte"){
	CHECK(m4<=m5);
	CHECK(m5<=m4);
	CHECK_FALSE(m2<=m1);
	bool temp;
	CHECK_THROWS(temp=m5<=m3);
}

TEST_CASE("lt"){
	CHECK(m1<m2);
	CHECK_FALSE(m1>m2);
	bool temp;
	CHECK_THROWS(temp=m2<m3);	
}

TEST_CASE("equals"){
	CHECK(m4==m5);
	CHECK_FALSE(m1==m2);
	bool temp;
	CHECK_THROWS(temp=m5==m3);
}

TEST_CASE("not equal"){
	CHECK(m1!=m2);
	CHECK_FALSE(m4!=m5);
	bool temp;
	CHECK_THROWS(temp=m5!=m3);
}

TEST_CASE("increment++"){
	vector<double> v8 = {1, 0, 0, 0, 1, 0, 0, 0, 1};
	zich::Matrix m1incr = m1++;
	zich::Matrix check8(v8, 3, 3);
	CHECK(m1incr == check8);
}

TEST_CASE("++increment"){
	vector<double> v9 = {2, 3, 4, 5, 6, 7};
	zich::Matrix incrm3 = ++m3;
	zich::Matrix check9(v9, 2, 3);
	CHECK(incrm3 == check9);
}

TEST_CASE("decrement--"){
	vector<double> v10 = {1, 2, 3, 4, 5, 6, 7, 8, 9};
	zich::Matrix check10(v10, 3, 3);
	zich::Matrix m2dec = m2--;
	CHECK(m2dec == check10);
}

TEST_CASE("--decrement"){
	vector<double> v11 = {19, 7, 3, 1, 2, 4, 5, 5, 5, -1, 1, 3};
	zich::Matrix check11(v11, 3, 4);
	zich::Matrix decm4 = --m4;
	CHECK(decm4 == check11);
}

TEST_CASE("scalor mutliplication"){
	vector<double> v12 = {10, 20, 30, 40, 5, 15};
	zich::Matrix check12(v12, 3, 2);
	m7*=5;
	CHECK(m7 == check12);
}

TEST_CASE("matrix multiplication"){
	vector<double> v13 = {25, 43, 30, 56};
	zich::Matrix m6m7 = m6*m7;
	zich::Matrix check13(v13, 2, 2);
	CHECK(m6m7 == check13);
	CHECK_THROWS(m5*m6);
}
