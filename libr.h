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
    Matrix operator + (const Matrix &a) const;
    Matrix operator - (const Matrix &a) const;
    template <int wi>
    Matrix<Type, _hi, wi> operator * (Matrix<Type, _wid, wi> const & other) const {
        Matrix<Type, _hi, wi> result;
        Type null(0);
        for (int i = 0; i < _hi; ++i) {
            for (int j = 0; j < wi; ++j) {
                result[i][j] = null;
                for (int k = 0; k < _wid; ++k) {
                    result[i][j] = result[i][j] + (*this)[i][k] * other[k][j];
                }
            }
        }
        return result;
    }

    Type* operator [](int i) const; //не обязан быть const, но иначе работать для const не будет
    Matrix& operator = (Matrix &a);
    Matrix& operator = (const Matrix &a);
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
    Matrix operator + (const Matrix &a) const;
    Matrix operator - (const Matrix &a) const;
    Matrix operator * (const Matrix &a) const;
    Type* operator [] (int i) const;
    Matrix& operator = (Matrix &a);
    Matrix& operator = (const Matrix &a) ;
    Matrix T() const;
    Matrix<double, _n,_n> inverse() const;
    Matrix<double, _n, _n> gaussMethod(double, Matrix <double, _n,_n> &B) const;
    Type trace() ;
    double det();
    void input();
    void output();
};
#ifndef MATRIX_H
    #include "Matrix.h"
    #define MATRIX_H
#endif

#endif // LIBR_H
