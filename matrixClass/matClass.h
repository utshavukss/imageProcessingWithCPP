#ifndef MATCLASS_H
#define MATCLASS_H
#include <opencv2/core.hpp>
class Matt{
    public:
    int* matData;
    int row, col, step, refCount;
    void create (const int m, const int n);
    Matt(int m, int n);
    Matt(int size);
    int& at(int r, int c);
    ~Matt();
    void display();
};

#endif