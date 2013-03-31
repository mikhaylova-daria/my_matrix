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
Matrix<Type, _hi, _wid>::Matrix (Matrix<Type, _hi, _wid> const& a):hi(_hi), wid(_wid){
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
    for (int i = 0; i < _hi; ++i) {
        for (int j = 0; j < wid; ++j) {
            this->matrix[i][j] = a.matrix[i][j];
        }
    }
}

template <typename Type, int _hi, int _wid>
Matrix<Type, _hi, _wid>::~Matrix() {
    for (int i = 0; i < hi; ++i) {
        delete[](this->matrix[i]);
    }
    delete[] (this->matrix);
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

template <typename Type, int _hi, int _wid>
Matrix <Type, _hi, _wid> Matrix<Type, _hi, _wid>::operator + (Matrix a){
    Matrix<Type, _hi, _wid> result;
    for (int i = 0; i < _hi; ++i) {
        for (int j = 0; j < wid; ++j) {
            result.matrix[i][j] = matrix[i][j] + a.matrix[i][j];
        }
    }
    return result;
}

template <typename Type, int _hi, int _wid>
Matrix <Type, _hi, _wid> Matrix<Type, _hi, _wid>::operator - (Matrix a){
    Matrix result;
    for (int i = 0; i < _hi; ++i) {
        for (int j = 0; j < wid; ++j) {
            result.matrix[i][j] = matrix[i][j] - a.matrix[i][j];
        }
    }
    return result;
}

template <typename Type, int _hi, int _wid>
Matrix<Type, _hi, _wid> & Matrix<Type, _hi, _wid>::operator = (Matrix a){
    for (int i = 0; i < _hi; ++i) {
        for (int j = 0; j < wid; ++j) {
            this->matrix[i][j] = a.matrix[i][j];
        }
    }
    return *this;
}

template <typename Type, int _hi, int _wid>
Matrix <Type, _wid, _hi>  Matrix <Type, _hi, _wid>::T()
{
    Matrix <Type, _wid, _hi> A;
    for (int i = 0; i < _wid; ++i) {
        for (int j = 0; j < _hi; ++j){
            A[i][j] = (*this)[j][i];
        }
    }
    return A;
}

//////-----КВАДРАТНЫЕ МАТРИЦЫ------\\\\\\\\\\\

template <typename Type, int _n>
Matrix<Type, _n, _n>::Matrix():n(_n){
    try {
        matrix = new Type* [n];
    } catch (std::bad_alloc& ba) {
       std::cerr << "bad_alloc caught: " << ba.what() << '\n';
    }
    for (int i = 0; i < _n; ++i) {
        try {
            matrix[i] = new Type [_n];
        } catch (std::bad_alloc& ba) {
          std::cerr << "bad_alloc caught: " << ba.what() << '\n';
        }
    }
}


template <typename Type, int _n>
Matrix<Type, _n, _n>::Matrix(Type x):n(_n){
    Type null(0);
    try {
        matrix = new Type* [n];
    } catch (std::bad_alloc& ba) {
       std::cerr << "bad_alloc caught: " << ba.what() << '\n';
    }
    for (int i = 0; i < _n; ++i) {
        try {
            matrix[i] = new Type [_n];
            for (int j = 0; j< _n; ++j){
                matrix[i][j] = null;
            }
        } catch (std::bad_alloc& ba) {
          std::cerr << "bad_alloc caught: " << ba.what() << '\n';
        }
    }
    for (int i = 0; i < _n; ++i){
        matrix[i][i] = x;
    }
}

template <typename Type, int _n>
Matrix<Type, _n, _n>::Matrix (Matrix<Type, _n, _n> const& a):n(_n){
    try {
        matrix = new Type* [n];
    } catch (std::bad_alloc& ba) {
       std::cerr << "bad_alloc caught: " << ba.what() << '\n';
    }
    for (int i = 0; i < _n; ++i) {
        try {
            matrix[i] = new Type [n];
        } catch (std::bad_alloc& ba) {
          std::cerr << "bad_alloc caught: " << ba.what() << '\n';
        }
    }
    for (int i = 0; i < _n; ++i) {
        for (int j = 0; j < n; ++j) {
            this->matrix[i][j] = a.matrix[i][j];
        }
    }
}

template <typename Type, int _n>
Matrix<Type, _n, _n>::~Matrix() {
    for (int i = 0; i < n; ++i) {
        delete[](this->matrix[i]);
    }
    delete[] (this->matrix);
}

template <typename Type, int _n>
Type* Matrix <Type , _n, _n>::operator [](int i) {
    if (i < _n) {
        return matrix[i];
    } else {
        throw ("trespassing");
        return NULL;
    }
}

template <typename Type, int _n>
void Matrix <Type, _n, _n>::input () {
    for (int i = 0; i < _n; ++i) {
        for (int j = 0; j < _n; ++j) {
            std::cin>>matrix[i][j];
        }
    }
}

template <typename Type, int _n>
void Matrix <Type, _n, _n>::output() {
    for (int i = 0; i < _n; ++i) {
        for (int j = 0; j < _n; ++j) {
            std::cout<<matrix[i][j];
            std::cout<<' ';
        }
        std::cout<<'\n';
    }
}

template <typename Type, int _n>
Matrix <Type, _n, _n> Matrix<Type, _n,_n>::operator + (Matrix a){
    Matrix<Type, _n, _n> result;
    for (int i = 0; i < _n; ++i) {
        for (int j = 0; j < n; ++j) {
            result.matrix[i][j] = matrix[i][j] + a.matrix[i][j];
        }
    }
    return result;
}

template <typename Type, int _n>
Matrix <Type, _n, _n> Matrix<Type, _n, _n>::operator - (Matrix a){
    Matrix result;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            result.matrix[i][j] = matrix[i][j] - a.matrix[i][j];
        }
    }
    return result;
}

template <typename Type, int _n>
Matrix<Type, _n, _n> & Matrix<Type, _n, _n>::operator = (Matrix a){
    for (int i = 0; i < _n; ++i) {
        for (int j = 0; j < n; ++j) {
            this->matrix[i][j] = a.matrix[i][j];
        }
    }
    return *this;
}


template <typename Type, int _n>
    Matrix<Type, _n, _n>  Matrix<Type, _n, _n>::operator * (Matrix a){
    Matrix<Type, _n, _n> result;
    Type sum(0);
    Type null(0);
    for (int i = 0; i < _n; ++i) {
        for (int j = 0; j < _n; ++j) {
            for (int k = 0; k < _n; ++k){
                sum = sum + a[i][k] * (this->matrix[k][j]);
            }
            result[i][j] = sum;
            sum = null;
        }
    }
    return result;
}


template <typename Type, int _n>
Type Matrix<Type, _n, _n>::trace(){
    Type result(0);
    for (int i = 0; i < _n; ++i) {
        result = result + *this[i][i];
    }
    return result;
}

template <typename Type, int _n>
double Matrix <Type, _n, _n>::det(){
    Type null(0);
    Matrix <double, _n, _n> buf;
    Matrix <double, _n, _n> a(this->gaussMethod(null, buf));
    Type result(1);
    for (int i = 0; i < _n; ++i) {
        result = result * a[i][i];
    }
    return result;
}

template <typename Type, int _n>
Matrix<Type, _n, _n>  Matrix <Type, _n, _n>::T()
{
    Matrix <Type, _n, _n> A;
    for (int i = 0; i < _n; ++i) {
        for (int j = 0; j < _n; ++j){
            A[i][j] = (*this)[j][i];
        }
    }
    return A;
}

template <typename Type, int _n>
Matrix <double, _n, _n> Matrix<Type, _n, _n>::gaussMethod(double eps, Matrix <double, _n,_n> &B)
{
    Matrix <double, _n, _n> E(1.0);
    B = E;
    Matrix<double, _n, _n> a;
    for (int i = 0; i < _n; ++i){
        for (int j = 0; j < _n; ++j){
            a[i][j] = (double) this->matrix[i][j];
        }
    }
    int i, j, k, l;
    i = 0; j = 0;
    double null(0);
    while (i < n && j < n) {
        double r(0);
        for (k = i; k < n; ++k) {
            if (fabs(a[k][j]) > r) {
                l = k;      // Запомним номер строки
                r = fabs(a[k][j]);
            }
        }
        if (r <= eps) {
            for (k = i; k < n; ++k) {
                a[k][j] = null;
            }
            ++j;      // Увеличим индекс столбца
            continue; // Переходим к следующей итерации
        }

        if (l != i) {
            for (k = j; k < n; ++k) {
                r = a[i][k];
                a[i][k] = a[l][k];
                a[l][k] = (-r); // Меняем знак строки
            }
            for (int h = 0; h < _n;++h){
                r = B[i][h];
                B[i][h] = B[l][h];
                B[l][h] = (-r);
            }
        }
        for (k = i+1; k < n; ++k) {
            r = (-a[k][j] / a[i][j]);
            a[k][j] = null;
            for (l = j+1; l < n; ++l) {
                a[k][l] += r * (a[i][l]);
                B[k][l] = B[k][l] + r * (B[i][l]);
            }
            for (int h = 0; h < _n; ++h) {
                B[k][h] = B[k][h] + r * B[i][h];
            }
        }

        ++i; ++j;
    }
    return a;
}


template <typename Type, int _n>
Matrix <double, _n, _n> Matrix<Type, _n, _n>::inverse() {
    Type null(0);
    Matrix <double, _n, _n> answer(0);
    Matrix <double, _n, _n> half;
    Matrix <double, _n, _n> A(this->gaussMethod(null, half));
    if (A.det() == null) {
        std::cout<<"Матрица вырождена\n";
        return answer;
    }
    //Обратный ход Гаусса:
    for (int i = _n - 1; i >= 0; --i) {
        for ( int j = 0; j < _n; ++j) { 
            half[i][j] = half[i][j] / A[i][i];
        }
        A[i][i] = 1;
        if( i > 0) {
            for (int g = i - 1; g >= 0; --g){ //обратный ход Гаусса - убиваем все числа, над полученной в предыдущем цикле 1
                for ( int j = 0; j < _n; ++j) {
                    half[g][j] = half[g][j] - A[g][i] * half[i][j];
                 }
                 A[g][i] = 0;
            }
        }
    }
    return half;

}



template <typename Type, int _hi, int _wid,  int _wid_1, int _hi_2, template <typename Type, int _hi, int _wid> class Matrix_answer, template <typename Type, int _hi, int _wid_1> class Matrix_1, template <typename Type, int _hi_2, int _wid> class Matrix_2 >
class Product
{
public:
    Matrix_answer <Type, _hi, _wid> result;
    Matrix_1 <Type, _hi, _wid_1> a;
    Matrix_2 <Type, _hi_2, _wid> b;
public:
    Product(Matrix_1 <Type, _hi, _wid_1> _a, Matrix_2 <Type, _hi_2, _wid> _b){
        a = _a;
        b = _b;
        Type null (0);
        Type sum(0);
        for (int i = 0; i < _hi; ++i) {
            for (int j = 0; j < _wid; ++j) {
                for (int k = 0; k < _wid_1; ++k){
                    sum = sum + a[i][k] * b[k][j];
                }
                result[i][j] = sum;
                sum = null;
            }
        }
    }
    ~Product() {;
    }

};



#endif // MATRIX_H
