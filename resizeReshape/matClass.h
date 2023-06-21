#ifndef CONSTRUCTORS_N_FUNC
#define CONSTRUCTORS_N_FUNC

#include <opencv2/core.hpp>
#include <opencv2/imgproc.hpp>

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
    Matt resize(int row, int col);
    Matt reshape(int, int);
    void copyTo(Matt& M);
    Matt clone();
    bool empty();
    void display();
    ~Matt();
};

#endif