#ifndef LIBR_H
    #include "libr.h"
#endif
int main() {
    Matrix<int, 2, 3> a;
    a.input();
    a.output();
    std::cout<<a[1][2];
    return 0;
}
