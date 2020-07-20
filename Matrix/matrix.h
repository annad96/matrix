#include <vector>
#include <complex>
#ifndef MATRIX_H
#define MATRIX_H

template <typename T>

class Matrix
{
  public:
    void resize(T numRows_, T numCols_);
    void resize(T numRows_, T numCols_, T value);
    
    // access elements
    T& operator()(T i, T j);
    T  operator()(T i, T j) const;
    std::vector<T>& operator[](T i);
    const std::vector<T>& operator[](T i) const;

    // arithmetic functions
    Matrix<T>& operator*=(T x);
    Matrix<T>& operator+=(const Matrix<T>& b);
    std::vector<T> vec_mult(const std::vector<T>& x) const;

    // output
    void print() const;
    T rows() const
    {
        return numRows;
    }
    T cols() const
    {
        return numCols;
    }
    
    Matrix(T numRows_, T numCols_) :
            entries(numRows_), numRows(numRows_), numCols(numCols_)
    {
        for (T i = 0; i < numRows_; ++i)
            entries[i].resize(numCols_);
    };
    
    Matrix(T dim) : Matrix(dim,dim)
    {};
    
    Matrix(T numRows_, T numCols_, T value)
    {
        resize(numRows_,numCols_,value);
    };
    
    Matrix(std::vector<std::vector<T> > a)
    {
        entries = a;
        numRows = a.size();
        if (numRows > 0)
            numCols = a[0].size();
        else
            numCols = 0;
    }
    
    Matrix(const Matrix<T>& b)
    {
        entries = b.entries;
        numRows = b.numRows;
        numCols = b.numCols;
    }
    
  private:
    std::vector<std::vector<T> > entries;
    T numRows = 0;
    T numCols = 0;
};
template <typename T>
Matrix<T> operator*(const Matrix<T>& a, T x);
template <typename T>
Matrix<T> operator*(T x, const Matrix<T>& a);
template <typename T>
std::vector<T> operator*(const Matrix<T>& a, const std::vector<T>& x);
template <typename T>
Matrix<T> operator+(const Matrix<T>& a, const Matrix<T>& b);

#endif // !MATRIX_H
