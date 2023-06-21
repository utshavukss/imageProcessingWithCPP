#ifndef BASIC_O
#define BASIC_O
#include <opencv2/core.hpp>

class Matt{
    public:
    int rows, cols, step, refcount;
    int* matData;
    void create(int m, int n);
    void init();
    Matt(int m, int n);
    Matt(int size);
    int& at(int i, int j);
    Matt operator + (Matt& Mat2);
    Matt operator - (Matt& Mat2);
    Matt operator * (Matt& Mat2);
    Matt operator + (int num);
    void operator - (int num);
    Matt operator / (int num);
    Matt operator * (int num);
    Matt transpose();
    void display();
    // ~Matt();
};

#endif