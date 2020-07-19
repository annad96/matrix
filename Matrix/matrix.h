#include <vector>
#include <complex>
#ifndef MATRIX_H
#define MATRIX_H
template <typename T>
class Matrix
{
  public:
    void resize(int numRows_, int numCols_);
    void resize(int numRows_, int numCols_, double value);
    
    // access elements
    double& operator()(int i, int j);
    double  operator()(int i, int j) const;
    std::vector<double>& operator[](int i);
    const std::vector<double>& operator[](int i) const;

    // arithmetic functions
    Matrix& operator*=(double x);
    Matrix& operator+=(const Matrix& b);
    std::vector<double> vec_mult(const std::vector<double>& x) const;

    // output
    void print() const;
    int rows() const
    {
        return numRows;
    }
    int cols() const
    {
        return numCols;
    }
    
    Matrix(int numRows_, int numCols_) :
            entries(numRows_), numRows(numRows_), numCols(numCols_)
    {
        for (int i = 0; i < numRows_; ++i)
            entries[i].resize(numCols_);
    };
    
    Matrix(int dim) : Matrix(dim,dim)
    {};
    
    Matrix(int numRows_, int numCols_, double value)
    {
        resize(numRows_,numCols_,value);
    };
    
    Matrix(std::vector<std::vector<double> > a)
    {
        entries = a;
        numRows = a.size();
        if (numRows > 0)
            numCols = a[0].size();
        else
            numCols = 0;
    }
    
    Matrix(const Matrix& b)
    {
        entries = b.entries;
        numRows = b.numRows;
        numCols = b.numCols;
    }

    std::vector<T> operator*(const Matrix<T>& a, std::vector<T>& x)
    {
        std::vector<T> y = a.vec_mult(x);
        return y;
    }

    std::vector<T> operator*(std::vector<T>& x, const Matrix<T>& a)
    {
        std::vector<T> y = x.vec_mult(a);
        return y;
    }

    std::vector<T> operator*(const Matrix<T>& a, const std::vector<T>& x)
    {
        std::vector<T> y = a.vec_mult(x);
        return y;
    }

    Matrix<T> operator+(const Matrix<T>& a, const Matrix<T>& b)
    {
        std::vector<T> y = std::vector(a + b);
        return y;
    }
    
  private:
    std::vector<std::vector<double> > entries;
    int numRows = 0;
    int numCols = 0;
};

#endif // !MATRIX_H
