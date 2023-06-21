#ifndef INV_DET
#define INV_DET

#include <opencv2/core.hpp>
#include <opencv2/imgproc.hpp>

class Matt{
    public:
    int rows, cols, step;
    int* refcount;
    float* matData;
    void create(int m, int n);
    void init();
    Matt();
    Matt(int m, int n);
    Matt(int size);
    Matt(Matt &M);
    Matt( Matt &M, int rowStart, int rowEnd, int colStart, int colEnd);
    float& at(int i, int j);
    void copyTo(Matt&);
    Matt triangularU();
    bool swapCols(int);
    double determinant();

    Matt& operator/(double);
    void transpose();
    void setMinor(Matt& child, int r, int c);
    Matt inverse();
    void display();
    ~Matt();
};

#endif