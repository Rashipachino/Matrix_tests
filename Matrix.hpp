#include <iostream>
#include <vector>
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
            Matrix(const Matrix& other)
                : _rows(other._rows), _cols(other._cols), _mat(other._mat){

                }
            //getters and setters
            vector<double> mat() const {
                return _mat;
            }

            int rows() const {
            return _rows;
            }

            int cols() const {
            return _cols;
            }
            Matrix operator-() const;
            Matrix operator-(const Matrix& other);
            void operator-=(const Matrix& other);
            Matrix operator+() const;
            Matrix operator+(const Matrix& other);
            void operator+=(const Matrix& other);
            bool operator<(const Matrix& other) const;
            bool operator<=(const Matrix& other) const;
            bool operator>(const Matrix& other) const;
            bool operator>=(const Matrix& other) const;
            bool operator==(const Matrix& other) const;
            bool operator!=(const Matrix& other) const;
            Matrix operator++();
            Matrix operator++(int dummy_flag_for_postfix_increment);
            Matrix operator--();
            Matrix operator--(int dummy_flag_for_postfix_increment);
            void operator*=(const double num);
            friend Matrix operator*(const double num, const Matrix& other);
            Matrix operator*(const Matrix& other);
            friend ostream& operator<< (std::ostream& output, const Matrix& mat);
            friend istream& operator>> (std::istream& input , Matrix& mat);
    };
}
