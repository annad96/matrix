#include "matrix.h"
#include <iostream>

template <typename T>
int main()
{   // define matrix
    Matrix<T> A(4, 6, 0.);
    for (T i = 0; i < A.rows(); ++i)
        A[i][i] = 2.;
    for (T i = 0; i < A.rows() - 1; ++i)
        A[i + 1][i] = A[i][i + 1] = -1.;
    Matrix<T> B(6, 4, 0.);
    for (T i = 0; i < B.cols(); ++i)
        B[i][i] = 2.;
    for (T i = 0; i < B.cols() - 1; ++i)
        B[i + 1][i] = B[i][i + 1] = -1.;

    // print matrix
    A.print();
    B.print();
    Matrix<T> C(A);
    A = 2 * C;
    A.print();
    A = C * 2.;
    A.print();
    A = C + A;
    A.print();
    const Matrix<T> D(A);
    std::cout << "Element 1,1 of D is " << D(1, 1) << std::endl;
    std::cout << std::endl;
    A.resize(5, 5, 0.);
    for (T i = 0; i < A.rows(); ++i)
        A(i, i) = 2.;
    for (T i = 0; i < A.rows() - 1; ++i)
        A(i + 1, i) = A(i, i + 1) = -1.;

    // define vector b
    std::vector<T> b(5);
    b[0] = b[4] = 5.;
    b[1] = b[3] = -4.;
    b[2] = 4.;
    std::vector<T>x = A * b;
    std::cout << "A*b = ( ";
    for (size_t i = 0; i < x.size(); ++i)
        std::cout << x[i] << "  ";
    std::cout << ")" << std::endl;
    std::cout << std::endl;
}
