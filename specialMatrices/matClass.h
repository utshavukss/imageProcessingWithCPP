#ifndef CONSTRUCTORS_N_FUNC
#define CONSTRUCTORS_N_FUNC

#include <opencv2/core.hpp>

class Matt{
    public:
    int rows, cols, step;
    int* refcount;
    int* matData;
    void create(int m, int n);
    void setValues();
    void setValues(int num);
    void identity();
    void diagonal();
    Matt();
    Matt(int m, int n);
    Matt(int size);
    Matt(Matt &M);
    Matt( Matt &M, int rowStart, int rowEnd, int colStart, int colEnd);
    int& at(int i, int j);
    
    void display();
    ~Matt();
};

#endif