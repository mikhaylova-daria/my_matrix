#ifndef LIBR_H
    #ifndef _IOSTREAM
        #include <iostream>
        #define  _IOSTREAM
    #endif
    #ifndef _NEW
        #include <new>
        #define  _NEW
    #endif
    #ifndef MATH_H
        #include <math.h>
        #define MATH_H
    #endif
    #ifndef STDIO_H
       #include <stdio.h>
       #define STDIO_H
    #endif
#define LIBR_H


template <typename Type, int _hi, int _wid> class Matrix {
    int hi;
    int wid;
    Type **matrix;
public:
    Matrix();
    Matrix (const Matrix&);
    ~Matrix();
    Matrix operator + (Matrix a);
    Matrix operator - (Matrix a);
    Type* operator [](int i);
    Matrix& operator = (Matrix a);
    Matrix<Type, _wid, _hi> T();
    void input();
    void output();
};

template <typename Type, int _n> class Matrix <Type, _n, _n> {
    int n;
    Type **matrix;
public:
    Matrix ();
    Matrix (Type);
    Matrix (const Matrix&);
    ~Matrix ();
    Matrix operator + (Matrix a);
    Matrix operator - (Matrix a);
    Matrix operator * (Matrix a);
    Type* operator [] (int i);
    Matrix& operator = (Matrix a);
    Matrix T();
    Matrix<double, _n,_n> inverse();
    Matrix<double, _n, _n> gaussMethod(double, Matrix <double, _n,_n> &B);
    Type trace();
    double det();
    void input();
    void output();
};
#ifndef MATRIX_H
    #include "Matrix.h"
    #define MATRIX_H
#endif

#endif // LIBR_H
