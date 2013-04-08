#ifndef LIBR_H
    #include "libr.h"
#endif
int main() {
    Matrix <double, 4, 3> a;
    Matrix <double, 3, 5> b;
    Matrix <double, 4, 5> c;
    Matrix <int, 3, 3> d;
    Matrix <int, 3, 4> e;
    Matrix <int, 4, 2> f;
    Matrix <int, 3, 2> g;
    a.input();
    b.input();
    Product <double, 4, 5, 3, 3, Matrix, Matrix, Matrix> pr(a,b);
    c = pr.result;
    c.output();
    c.input();
    b.output();
    std::cout<<"\n";
    //b = a.T();
    b.output();
   // b = a.gaussMethod(0, buf);
    //d = a.inverse();

    std::cout<<"\n";
    //buf.output();
     std::cout<<"\n";
    //b = a.inverse();
    b.output();
   // b.input();
    //Matrix <int, 2, 2> c;
    return 0;
}
