#ifndef LIBR_H
    #include "libr.h"
#endif
int main() {
    Matrix <double, 4, 3> a;
    Matrix <double, 3, 4> b;
    Matrix <double, 3, 3> E(1);
    Matrix <double, 4, 4> buf;
    a.input();
    std::cout<<"\n";
    b = a.T();
   // b = a.gaussMethod(0, buf);
    //b = a.inverse();
  //  b.output();
    std::cout<<"\n";
    //buf.output();
     std::cout<<"\n";
    //b = a.inverse();
    b.output();
   // b.input();
    //Matrix <int, 2, 2> c;
    return 0;
}
