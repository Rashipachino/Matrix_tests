#include <iostream>
#include <vector>
#include "Matrix.hpp"
using namespace std;

namespace zich{
        Matrix Matrix::operator-() const{ 
            std::vector<double> identity = {1, 0, 0, 0, 1, 0, 0, 0, 1};
            std::vector<double> arr = {3, 0, 0, 0, 3, 0, 0, 0, 3};
            Matrix a{identity, 3, 3};            
            // Matrix mat2{_mat, _rows, _cols};
            // for (unsigned long i = 0; i < _rows*_cols; i++)
            // {
            //     mat2._mat[i] = -_mat[i];
            // }
            // return mat2;
            return a;
        }

        Matrix Matrix::operator-(const Matrix& other){
            std::vector<double> identity = {1, 0, 0, 0, 1, 0, 0, 0, 1};
            std::vector<double> arr = {3, 0, 0, 0, 3, 0, 0, 0, 3};
            Matrix a{identity, 3, 3};
            return a;
        }

        void Matrix::operator-=(const Matrix& other) {
            // for (unsigned long i = 0; i < _rows*_cols; i++)
            // {
            //     _mat[i] -= num;
            // }
            // return *this;
        }

        Matrix Matrix::operator+() const {
            std::vector<double> identity = {1, 0, 0, 0, 1, 0, 0, 0, 1};
            std::vector<double> arr = {3, 0, 0, 0, 3, 0, 0, 0, 3};
            Matrix a{identity, 3, 3};
            return a;           
        }

        Matrix Matrix::operator+(const Matrix& other){
            std::vector<double> identity = {1, 0, 0, 0, 1, 0, 0, 0, 1};
            std::vector<double> arr = {3, 0, 0, 0, 3, 0, 0, 0, 3};
            Matrix a{identity, 3, 3};
            return a;
        }

        void Matrix::operator+=(const Matrix& other) {
            // for (unsigned long i = 0; i < _rows*_cols; i++)
            // {
            //     _mat[i] += num;
            // }
            // return *this;
        }

        bool Matrix::operator<(const Matrix& other) const{
            return true;
        }
        bool Matrix::operator<=(const Matrix& other) const{
            return true;
        }
        bool Matrix::operator>(const Matrix& other) const{
            return true;
        }
        bool Matrix::operator>=(const Matrix& other) const{
            return true;
        }
        bool Matrix::operator==(const Matrix& other) const{
            return true;
        }
        bool Matrix::operator!=(const Matrix& other) const{
            return true;
        }

        Matrix Matrix::operator++() {
            std::vector<double> identity = {1, 0, 0, 0, 1, 0, 0, 0, 1};
            std::vector<double> arr = {3, 0, 0, 0, 3, 0, 0, 0, 3};
            Matrix a{identity, 3, 3};
            // for (unsigned long i = 0; i < _rows*_cols; i++)
            // {
            //     _mat[i] += 1;
            // }
            return a;
        }

        Matrix Matrix::operator++(int dummy_flag_for_postfix_increment) {
            // Matrix copy = *this;
            // for (unsigned long i = 0; i < _rows*_cols; i++)
            // {
            //     _mat[i] += 1;
            // }
            // return copy;
            std::vector<double> identity = {1, 0, 0, 0, 1, 0, 0, 0, 1};
            std::vector<double> arr = {3, 0, 0, 0, 3, 0, 0, 0, 3};
            Matrix a{identity, 3, 3};
            return a;          
        }

        Matrix Matrix::operator--() {
            // for (unsigned long i = 0; i < _rows*_cols; i++)
            // {
            //     _mat[i] -= 1;
            // }
            // return *this;
            std::vector<double> identity = {1, 0, 0, 0, 1, 0, 0, 0, 1};
            std::vector<double> arr = {3, 0, 0, 0, 3, 0, 0, 0, 3};
            Matrix a{identity, 3, 3};
            return a;          
        }

        // postfix increment:
        Matrix Matrix::operator--(int dummy_flag_for_postfix_increment) {
            // Matrix copy = *this;
            // for (unsigned long i = 0; i < _rows*_cols; i++)
            // {
            //     _mat[i] -= 1;
            // }
            // return copy;
            std::vector<double> identity = {1, 0, 0, 0, 1, 0, 0, 0, 1};
            std::vector<double> arr = {3, 0, 0, 0, 3, 0, 0, 0, 3};
            Matrix a{identity, 3, 3};
            return a;
        }

        void Matrix::operator*=(const double num){}
        Matrix Matrix::operator*(const Matrix& other){
            std::vector<double> identity = {1, 0, 0, 0, 1, 0, 0, 0, 1};
            std::vector<double> arr = {3, 0, 0, 0, 3, 0, 0, 0, 3};
            Matrix a{identity, 3, 3};
            return a;
        }
        Matrix operator*(const double num, const Matrix& other){
            std::vector<double> identity = {1, 0, 0, 0, 1, 0, 0, 0, 1};
            std::vector<double> arr = {3, 0, 0, 0, 3, 0, 0, 0, 3};
            Matrix a{identity, 3, 3};
            return a;
        }
        std::ostream& operator<< (std::ostream& output, const Matrix& mat){
            return output;
        }
        std::istream& operator>> (std::istream& input , Matrix& mat){
            return input;
        }
}
