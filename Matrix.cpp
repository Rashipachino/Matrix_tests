#include <iostream>
#include <vector>
#include Matrix.hpp
using namespace std;

namespace zich{
    class Matrix{
        private: 
            int _rows;
            int _cols;
            vector<double> _mat;
        public:
            //constructor
            Matrix(vector<double> vect, int rows, int cols)
                : _rows(rows), _cols(cols), _mat(vect){
                }

            //getters and setters
            vector<double> _mat() const {
                return _mat;
            }

            double _rows() const {
            return _rows;
            }

            double _cols() const {
            return _cols;
            }

            Matrix& operator-() { 
                Matrix mat2{_mat, _rows, _cols};
                for (int i = 0; i < _rows*_cols; i++)
                {
                    mat2._mat[i] = -_mat[i];
                }
                return *mat2;
            }

            Matrix& operator-(const Matrix& other);

            Matrix& operator-=(const double num) {
                for (int i = 0; i < _rows*_cols; i++)
                {
                    _mat[i] -= num;
                }
                return *this;
            }

            Matrix& operator+() const {
                return *this;
            }

            Matrix& operator+(const Matrix& other);

            Matrix& operator+=(const double num) {
                for (int i = 0; i < _rows*_cols; i++)
                {
                    _mat[i] += num;
                }
                return *this;
            }

            Matrix operator<(const Matrix& other) const;
            Matrix operator<=(const Matrix& other) const;
            Matrix operator>(const Matrix& other) const;
            Matrix operator>=(const Matrix& other) const;
            Matrix operator==(const Matrix& other) const;
            Matrix operator!=(const Matrix& other) const;

            Matrix& operator++() {
                for (int i = 0; i < _rows*_cols; i++)
                {
                    _mat[i] += 1;
                }
                return *this;
                }

            // postfix increment:
            Matrix operator++(int dummy_flag_for_postfix_increment) {
                Matrix copy = *this;
                for (int i = 0; i < _rows*_cols; i++)
                {
                    _mat[i] += 1;
                }
                return copy;
            }

            Matrix& operator--() {
                for (int i = 0; i < _rows*_cols; i++)
                {
                    _mat[i] -= 1;
                }
                return *this;
                }

            // postfix increment:
            Matrix operator--(int dummy_flag_for_postfix_increment) {
                Matrix copy = *this;
                for (int i = 0; i < _rows*_cols; i++)
                {
                    _mat[i] -= 1;
                }
                return copy;
            }

            Matrix& operator*=(const double num);
            Matrix& operator*(const Matrix& other);
            friend std::ostream& operator<< (std::ostream& output, const Matrix& mat);
            friend std::istream& operator>> (std::istream& input , Matrix& mat);
            
            

    };
}