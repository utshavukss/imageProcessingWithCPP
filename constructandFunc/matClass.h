#ifndef CONSTRUCTORS_N_FUNC
#define CONSTRUCTORS_N_FUNC

#include <opencv2/core.hpp>

class Matt{
    public:
    int rows, cols, step;
    int* refcount;
    int* matData;
    void create(int m, int n);
    void init();
    Matt();
    Matt(int m, int n);
    Matt(int size);
    Matt(Matt &M);
    Matt( Matt &M, int rowStart, int rowEnd, int colStart, int colEnd);
    int& at(int i, int j);
    int dot(Matt& M);
    Matt cross(Matt& M);
    int lOneNorm();
    float lTwoNorm();
    void display();
    ~Matt();
};

#endif