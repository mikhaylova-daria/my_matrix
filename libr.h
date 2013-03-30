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
    ~Matrix();
    Matrix operator + (Matrix a);
    Matrix operator - (Matrix a);
    Matrix operator * (Matrix a);
    Type* operator [](int i);
    Matrix T();
    Matrix inverse();
    void input();
    void output();
};
#ifndef MATRIX_H
    #include "Matrix.h"
    #define MATRIX_H
#endif

#endif // LIBR_H
