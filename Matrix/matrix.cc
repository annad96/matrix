#include "matrix.h"
#include <iomanip>
#include <iostream>
#include <cstdlib>

template <typename T>
void Matrix<T>::resize(T numRows_, T numCols_)
{
    entries.resize(numRows_);
    for (size_t i = 0; i < entries.size(); ++i)
        entries[i].resize(numCols_);
    numRows = numRows_;
    numCols = numCols_;
}
template <typename T>
void Matrix<T>::resize(T numRows_, T numCols_, T value)
{
    entries.resize(numRows_);
    for (size_t i = 0; i < entries.size(); ++i)
    {
        entries[i].resize(numCols_);
        for (size_t j = 0; j < entries[i].size(); ++j)
            entries[i][j] = value;
    }
    numRows = numRows_;
    numCols = numCols_;
}
template <typename T>
T& Matrix<T>::operator()(T i, T j)
{
    if (i < 0 || i >= numRows)
    {
        std::cerr << "Illegal row index " << i;
        std::cerr << " valid range is [0:" << numRows-1 << "]";
        std::cerr << std::endl;
        exit(EXIT_FAILURE);
    }
    if (j < 0 || j >= numCols)
    {
        std::cerr << "Illegal column index " << j;
        std::cerr << " valid range is [0:" << numCols-1 << "]";
        std::cerr << std::endl;
        exit(EXIT_FAILURE);
    }
    return entries[i][j];
}

template <typename T>
T Matrix<T>::operator()(T i, T j) const
{
    if ( i < 0 || i >= numRows)
    {
        std::cerr << "Illegal row index " << i;
        std::cerr << " valid range is [0:" << numRows-1 << "]";
        std::cerr << std::endl;
        exit(EXIT_FAILURE);
    }
    if (j < 0 || j >= numCols)
    {
        std::cerr << "Illegal column index " << j;
        std::cerr << " valid range is [0:" << numCols-1 << "]";
        std::cerr << std::endl;
        exit(EXIT_FAILURE);
    }
    return entries[i][j];
}

template <typename T>
std::vector<T>& Matrix<T>::operator[](T i)
{
    if (i < 0 || i >= numRows)
    {
        std::cerr << "Illegal row index " << i;
        std::cerr << " valid range is [0:" << numRows-1 << "]";
        std::cerr << std::endl;
        exit(EXIT_FAILURE);
    }
    return entries[i];
}

template <typename T>
const std::vector<T>& Matrix<T>::operator[](T i) const
{
    if (i < 0 || i >= numRows)
    {
        std::cerr << "Illegal row index " << i;
        std::cerr << " valid range is [0:" << numRows-1 << "]";
        std::cerr << std::endl;
        exit(EXIT_FAILURE);
    }
    return entries[i];
}

template <typename T>
Matrix<T>& Matrix<T>::operator*=(T x)
{
    for (T i = 0; i < numRows; ++i)
        for (T j = 0; j < numCols; ++j)
            entries[i][j] *= x;
    return *this;
}

template <typename T>
Matrix<T>& Matrix<T>::operator+=(const Matrix<T>& x)
{
    if (x.numRows != numRows || x.numCols != numCols)
    {
        std::cerr << "Dimensions of matrix a (" << numRows
                  << "x" << numCols << ") and matrix x (" 
                  << x.numRows << "x" << x.numCols << ") do not match!";
        exit(EXIT_FAILURE);
    }
    for (T i = 0; i < numRows; ++i)
        for (T j = 0;j < numCols; ++j)
            entries[i][j] += x[i][j];
    return *this;
}

template <typename T>
std::vector<T> Matrix<T>::vec_mult(const std::vector<T>& x) const
{
    if (x.size() != numCols)
    {
        std::cerr << "Dimensions of vector " << x.size();
        std::cerr << " and matrix " << numCols << " do not match!";
        std::cerr << std::endl;
        exit(EXIT_FAILURE);
    }
    std::vector<T> y(numRows);
    for (T i = 0; i < numRows; ++i)
    {
        y[i] = 0.;
        for (T j = 0; j < numCols; ++j)
            y[i] += entries[i][j] * x[j];
    }
    return y;
}

template <typename T>
void Matrix<T>::print() const
{
    std::cout << "(" << numRows << "x";
    std::cout << numCols << ") matrix:" << std::endl;
    for (T i = 0; i < numRows; ++i)
    {
        std::cout << std::setprecision(3);
        for (T j = 0; j < numCols; ++j)
            std::cout << std::setw(5) << entries[i][j] << " ";
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

template <typename T>
Matrix<T> operator*(const Matrix<T>& a, T x)
{
    Matrix output(a);
    output *= x;
    return output;
}

template <typename T>
Matrix<T> operator*(T x, const Matrix<T>& a)
{
    Matrix<T> output(a);
    output *= x;
    return output;
}

template <typename T>
std::vector<T> operator*(const Matrix<T>& a, const std::vector<T>& x)
{
    std::vector<T> y = a.vec_mult(x);
    return y;
}

template <typename T>
Matrix<T> operator+(const Matrix<T>& a, const Matrix<T>& b)
{
    Matrix output(a);
    output += b;
    return output;
}
