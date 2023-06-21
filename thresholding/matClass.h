#ifndef MATTEMPLATE
#define MATTEMPLATE

#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>

const unsigned char MAXVAL = 255;
const unsigned char MINVAL = 0;

template <class T>
class Matt{
    public:
    int rows, cols, step;
    int* refcount;
    T* matData;
    /*******MATRIX OPERATION FUNCTIONS**********/
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

    //DISPLAY MATRIX
    void display();
    ~Matt();

    /*******IMAGE FUNCTIONS FUNCTIONS**********/
    static void binThreshold(Matt&, T thr);
    static void copyToMatt(cv::Mat, Matt);
    static void copyToMat(Matt, cv::Mat);
    static void adThreshold(Matt&, Matt&, int blocksize, int c);
    static cv::Mat bgrToYuv(cv::Mat&);
    static cv::Mat bgrToYuv422(cv::Mat&);
};

extern template class Matt<int>;
extern template class Matt<float>;
extern template class Matt<double>;
extern template class Matt<char>;
extern template class Matt<unsigned char>;

#endif