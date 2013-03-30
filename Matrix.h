#ifndef MATRIX_H
#define MATRIX_H
#ifndef LIBR_H
    #include "libr.h"
#endif
template <typename Type, int _hi, int _wid>
Matrix<Type, _hi, _wid>::Matrix():hi(_hi), wid(_wid){
    try {
        matrix = new Type* [hi];
    } catch (std::bad_alloc& ba) {
       std::cerr << "bad_alloc caught: " << ba.what() << '\n';
    }
    for (int i = 0; i < _hi; ++i) {
        try {
            matrix[i] = new Type [wid];
        } catch (std::bad_alloc& ba) {
          std::cerr << "bad_alloc caught: " << ba.what() << '\n';
        }
    }
}


template <typename Type, int _hi, int _wid>
Matrix<Type, _hi, _wid>::~Matrix() {
    for (int i = 0; i < hi; ++i) {
        delete[](matrix[i]);
    }
    delete[] (matrix);
}

template <typename Type, int _hi, int _wid>
Type* Matrix <Type , _hi, _wid>::operator [](int i) {
    if (i < _hi) {
        return matrix[i];
    } else {
        throw ("trespassing");
        return NULL;
    }
}

template <typename Type, int _hi, int _wid>
void Matrix<Type, _hi, _wid>::input () {
    for (int i = 0; i < _hi; ++i) {
        for (int j = 0; j < wid; ++j) {
            std::cin>>matrix[i][j];
        }
    }
}

template <typename Type, int _hi, int _wid>
void Matrix<Type, _hi, _wid>::output() {
    for (int i = 0; i < _hi; ++i) {
        for (int j = 0; j < wid; ++j) {
            std::cout<<matrix[i][j];
            std::cout<<' ';
        }
        std::cout<<'\n';
    }
}

#endif // MATRIX_H
