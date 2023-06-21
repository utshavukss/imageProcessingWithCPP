#ifndef MATTEMPLATE
#define MATTEMPLATE

#include <opencv2/core.hpp>
#include <opencv2/imgproc.hpp>

template <class T>
class Matt{
    public:
    int rows, cols, step;
    int* refcount;
    T* matData;
    //INITIALIZE
    void create(int m, int n);
    void init();
    //CONSTRUCT
    Matt();
    Matt(int m, int n);
    Matt(int size);
    Matt(Matt &M);
    Matt( Matt &M, int rowStart, int rowEnd, int colStart, int colEnd);
    //ACCESS
    T& at(int i, int j);
    //INVERSE AND DETERMINANTS
    void copyTo(Matt&);
    Matt triangularU();
    bool swapCols(int);
    double determinant();
    Matt& operator/(double);
    void transpose();
    void setMinor(Matt& child, int r, int c);
    Matt inverse();

    //resize reshape
    Matt resize(int, int);
    Matt reshape(int row, int col);
    Matt clone();
    bool empty();

    //special matrices
    static Matt<T> diag(int row, std::vector<T>& vec);
    static Matt<T> identity(int row);
    static Matt<T> ones(int row, int col);
    static Matt<T> zeroes(int row, int col);

    //subMatrices
    Matt<T> getRow(int row);
    Matt<T> getCol(int col);
    Matt<T> rowRange(int, int);
    Matt<T> colRange(int, int);

    //basicMatOperations
    Matt<T> operator + (Matt<T>& Mat2);
    Matt operator - (Matt& Mat2);
    Matt operator * (Matt& Mat2);
    Matt operator + (int num);
    void operator - (int num);
    Matt operator / (int num);
    Matt operator * (int num);
    Matt& operator = (Matt& M);


    //DISPLAY AND DESTRUCT
    void display();
    ~Matt();
};

extern template class Matt<int>;
extern template class Matt<float>;
extern template class Matt<double>;
extern template class Matt<char>;

#endif