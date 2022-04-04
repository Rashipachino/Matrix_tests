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
            Matrix operator-() const;
            Matrix& operator-(const Matrix& other);
            Matrix& operator-=(const double num);
            Matrix operator+() const;
            Matrix& operator+(const Matrix& other);
            Matrix& operator+=(const double num);
            bool operator<(const Matrix& other) const;
            bool operator<=(const Matrix& other) const;
            bool operator>(const Matrix& other) const;
            bool operator>=(const Matrix& other) const;
            bool operator==(const Matrix& other) const;
            bool operator!=(const Matrix& other) const;
            Matrix& operator++();
            Matrix operator++(int dummy_flag_for_postfix_increment);
            Matrix& operator--();
            Matrix operator--(int dummy_flag_for_postfix_increment);
            Matrix& operator*=(const double num);
            Matrix& operator*(const Matrix& other);
            friend std::ostream& operator<< (std::ostream& output, const Matrix& mat);
            friend std::istream& operator>> (std::istream& input , Matrix& mat);
    };
}
