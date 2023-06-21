#include "matClass.h"
#include <random>
#include <map>

std::random_device rd;
std::mt19937 generator(rd());

int minNumber = -100;
int maxNumber = 100;

std::uniform_int_distribution<int> distribution(minNumber, maxNumber);

template class Matt<int>;
template class Matt<float>;
template class Matt<char>;
template class Matt<double>;
template class Matt<unsigned char>;

template <class T>
void Matt<T>::create(int m, int n){
    rows = m;
    cols = n;
    step = cols;
    refcount = new int(1);

    if (rows == 0 || cols == 0) {
        matData = 0;
        return;
        }
    matData = new T[rows * cols];
}
template <class T>
void Matt<T>::init (){
    for (int i = 0; i < rows; i++){
        for (int j = 0; j < cols; j++){
            this->at(i,j) = distribution(generator);
            // this->at(i,j) = i * step + j;
        }
    }
}
template <class T>
Matt<T>::Matt(){
    this->create(0,0);
}

template <class T>
Matt<T>::Matt(int m, int n){
 this->create(m,n);
}

template <class T>
Matt<T>::Matt(int size){
 this->create(size, size);
}

template <class T>
Matt<T>::Matt(Matt& M){
    this->create(M.rows, M.cols);
    for(int i = 0; i < M.rows; i++){
        for(int j = 0; j < M.cols; j++){
            this->at(i,j) = M.at(i,j);
        }
    }
}

template <class T>
Matt<T>::Matt( Matt& M, int rowStart, int rowEnd, int colStart, int colEnd){
    
    this->matData = M.matData + rowStart * M.step + colStart;
    this->step = M.step;
    this->rows = rowEnd - rowStart + 1;
    this->cols = colEnd - colStart + 1;
    this->refcount = M.refcount;
    *(refcount)++;
    
}

template <class T>
T& Matt<T>::at(int i, int j){
    return *(matData +  i  * step + j);
}

template <class T>
void Matt<T>::copyTo(Matt& M){
    M.create(this->rows, this->cols);
    for(int i = 0; i < this->rows; i++){
        for(int j = 0; j < this->cols; j++){
            M.at(i,j) = this->at(i,j);
        }
    }
}

template <class T>
double Matt<T>::determinant(){
    if (this->rows != this->cols){
        std::cout<<"\nCannot find determinant!\n";
        return 0;
    }
    double result = 1;
    Matt temp = this->triangularU();
    if(!temp.matData) return 0;
    for (int i = 0; i < temp.rows; i++){
        result *= temp.at(i,i);
    }
    return result;
}

template <class T>
Matt<T> Matt<T>::triangularU(){
    Matt temp; bool success = true;
    this->copyTo(temp);
    for (int i = 0; i < temp.rows; i++){
        if(temp.at(i,i) == 0) success = temp.swapCols(i);
        if(!success){
            delete temp.matData;
            *(temp.refcount)--;
            break;
        }
            for(int j = i + 1; j < temp.rows; j++){
                float factor = static_cast<float>(temp.at(j,i))/static_cast<float>(temp.at(i,i));
                for(int k = i; k < temp.cols; k++){
                    temp.at(j,k) -= factor*temp.at(i,k);
                }
            }
    }
    return temp;
}

template <class T>
bool Matt<T>::swapCols(int i){
    int colIndex = -1;
    for (int j = i + 1; j < this->cols; j++){
        if(this->at(i,j) !=0){
            colIndex = j;
            break;
        }
    }
    if(colIndex == -1) return false;
    for (int k = 0; k < this->rows; k++){
        std::swap(this->at(k,i), this->at(k,colIndex));
    }
    return true;
}

template <class T>
Matt<T> Matt<T>::inverse(){
    Matt<T> temp;
    if (this->rows != this->cols){
        std::cout<<"\nNot invertible!!!\n";
        return temp;
    }
    double det = this->determinant();
    if(!det) return temp;
    this->copyTo(temp);
    Matt<T> minor(temp.rows - 1);

    for(int i = 0; i < temp.rows; i++){
        for(int j = 0; j < temp.cols; j++){
            this->setMinor(minor, i,j);
            temp.at(i,j) = pow((-1), (i+j)) * minor.determinant();
        }
    }
    temp.transpose();
    temp = temp / det;
    return temp;
}

template <class T>
void Matt<T>::setMinor(Matt& child, int r, int c){
    int minorRow = 0, minorCol = 0;

    for (int i = 0; i < this->rows; i++){
        if(i == r) continue;
        for (int j = 0; j < this->cols; j++){
            if (j == c) continue;
            child.at(minorRow, minorCol) = this->at(i,j);
            minorCol++;
        }
        minorRow++;
        minorCol = 0;
    }

}

template <class T>
void Matt<T>::transpose(){
    for(int i = 0; i < this->rows; i++){
        for(int j = i + 1; j < this->cols; j++){
           std::swap(this->at(i,j), this->at(j,i)) ;
        }
    }
}

template <class T>
Matt<T>& Matt<T>::operator/(double det){
    for(int i = 0; i < this->rows; i++){
        for(int j = 0; j < this->cols; j++){
            this->at(i,j) = static_cast<float>(this->at(i,j)/det);
        }
    }
    return *(this);
}

//resizereshape

template <class T>
Matt<T> Matt<T>::resize(int row, int col){
    Matt temp(*(this), 0, row-1, 0, col - 1);
    temp.step = col;
    // for (int i = 0; i < temp.rows; i++){
    //     for(int j = 0; j < temp.cols; j++){
    //         if (i >= this->rows || j >= this->cols) temp.at(i,j) = 0;
    //     }
    // }
    return temp;
}

template <class T>
Matt<T> Matt<T>::reshape(int row, int col){
    if (row * col == this->rows * this->cols){
        Matt temp(*(this), 0, (row - 1), 0, (col - 1));
        temp.step = col;
        return temp;
    }
    return 0;
}


template <class T>
Matt<T> Matt<T>::clone(){
    Matt temp(this->rows, this->cols);
    for(int i = 0; i < this->rows; i++){
        for(int j = 0; j < this->cols; j++){
            temp.at(i,j) = this->at(i,j);
        }
    }
    return temp;
}

template <class T>
bool Matt<T>::empty(){
    if (matData) return false;
    return true;
    
}

//COPY MAT OBJECT TO MATT OBJECT AND VICE VERSA
template <class T>
void Matt<T>::copyToMatt(cv::Mat& M1, Matt<T>& M2){
    for(int i = 0; i < M2.rows; i++){
        for(int j = 0; j < M2.cols; j++){
            M2.at(i,j) = M1.at<T>(i,j);
        }
    }
}

template <class T>
void Matt<T>::copyToMat(Matt& M1, cv::Mat& M2){
    for(int i = 0; i < M1.rows; i++){
        for(int j = 0; j < M1.cols; j++){
            M2.at<T>(i,j) = M1.at(i,j);
        }
    }
}


//Binary and Adaptive Thresholding

template <class T>
void Matt<T>::binThreshold(Matt& M, T thr){
    for(int i=0; i < M.rows; i++){
        for(int j = 0; j < M.cols; j++){
            if(M.at(i,j) < thr){
                M.at(i,j) = MINVAL;
                continue;
            }
            M.at(i,j) = MAXVAL;
        }
    }
}

template <class T>
void Matt<T>::adThreshold(Matt& M, Matt& dest, int bs, int c){
    M.copyTo(dest);
    for(int i = 0; i < M.rows; i++){
        for(int j = 0; j < M.cols; j++){
            int sum = 0; int count = bs * bs;
            for(int m = i - (bs / 2); m <= i + (bs / 2); m++){
                for(int n = j - (bs / 2); n <= j + (bs / 2); n++){
                    if(m < 0 || n < 0 || m > M.rows || n > M.cols) {
                        count--;
                        continue;
                    }
                    sum += static_cast<int>(M.at(m,n));
                }
            }
            int avg = sum / count - c;
            
            if(static_cast<int>(M.at(i,j)) <= avg){
                dest.at(i,j) = MINVAL;
                continue;
            }
            dest.at(i,j) = MAXVAL;
        }
    }

}

// Colour Space Conversion

template <class T>
cv::Mat Matt<T>::bgrToYuv(cv::Mat& bgr){
    cv::Mat temp(bgr.rows, bgr.cols, CV_8UC1);
    for(int i = 0; i < temp.rows; i++){
        for(int j = 0; j < temp.cols; j++){
            cv::Vec3b rgbPixel = bgr.at<cv::Vec3b>(i,j);
            T y = static_cast<T>(0.299 * rgbPixel[2] + 0.587 * rgbPixel[1] + 0.114 * rgbPixel[0]);
            temp.at<T>(i,j) = y;
        }
    }
    return temp;
}

template <class T>
cv::Mat Matt<T>::bgrToYuv422(cv::Mat& bgr){
    cv::Mat temp(bgr.rows, bgr.cols, CV_8UC2);
    for(int i = 0; i < temp.rows; i++){
        for(int j = 0; j < temp.cols; j++){
            cv::Vec3b rgbPixel = bgr.at<cv::Vec3b>(i,j);
            T y = static_cast<T>(0.299 * rgbPixel[2] + 0.587 * rgbPixel[1] + 0.114 * rgbPixel[0]);
            T u = static_cast<T>(0.492 * (rgbPixel[0] - y));
            T v = static_cast<T>(0.877 * (rgbPixel[2] - y));
            temp.at<cv::Vec2b>(i,j)[0] = y;
            if(j%2 == 0) temp.at<cv::Vec2b>(i,j)[1] = u;
            else temp.at<cv::Vec2b>(i,j)[1] = v;
        }
    }
    return temp;
}

//histogram
template <class T>
std::map<T, int> Matt<T>::createHist(Matt& image){
    std::map<T,int> hist;
    for(int i = 0; i < image.rows; i++){
        for(int j = 0; j < image.cols; j++){
            T intensity = image.at(i,j);
            hist[intensity]++;
        }
    }
    return hist;
}

template <class T>
void Matt<T>::histEqualize(std::map<T,int>& hist, Matt& image){
    
    std::map<T, T> newVals;
    for(auto& pair: hist){
        if(pair.first == 0) {
            newVals[pair.first] = static_cast<T>(round(pair.second/static_cast<double>(image.rows * image.cols)));
            continue;
            }
        pair.second += hist[pair.first - 1];
        newVals[pair.first] = static_cast<T>(round(255 * pair.second/static_cast<double>(image.rows * image.cols)));
    }

   
    for(int i = 0; i < image.rows; i++){
        for(int j = 0; j < image.cols; j++){
            image.at(i,j) = static_cast<unsigned char>(newVals[image.at(i,j)]);
        }
    }
}

template <class T>
void Matt<T>::contrastStretch(std::map<T, int>& hist, Matt& image){
    T min, max;
    for(const auto& i: hist){
        if (i.second == 0) {
            continue;
        }
        min = i.first;
        break;
    }
    typename std::map<T, int>::reverse_iterator it;
    for(it = hist.rbegin(); it != hist.rend(); ++it){
        if(it->second == 0) continue;
        max = it->first;
        break;
    }
    std::cout<<"\n "<<static_cast<int>(max)<<"\t"<<static_cast<int>(min);

    for(int i = 0; i < image.rows; i++){
        for(int j = 0; j < image.cols; j++){
            image.at(i,j) = static_cast<T>(255 * (image.at(i,j) - min)/static_cast<float>(max - min));
        }
    }

    hist = Matt<T>::createHist(image);
    
}

// Image Filtering

template <class T>
void Matt<T>::convolve(Matt& image, Matt& result, Matt<int>& kernel){
    int blocksize = kernel.rows;
    int normalizationFactor = kernel.sums();
    if(!normalizationFactor) normalizationFactor = 1;
    Matt<int> temp(image.rows, image.cols);
     for(int i = 0; i < image.rows; i++){
        for (int j = 0; j < image.cols; j++){
            int weightedSum = 0;
            for(int m = i - blocksize/2, k = 0; m <= i + blocksize/2 && k < kernel.rows; m++, k++){
                for(int n = j - blocksize/2, l = 0; n <= j + blocksize/2 && l < kernel.cols; n++, l++){
                    if (m < 0 || n < 0  || m >= image.rows || n >= image.cols) {
                        weightedSum += static_cast<int>(kernel.at(k,l) * 0);
                        continue;
                    }
                    weightedSum += kernel.at(k,l) * static_cast<int>(image.at(m,n));
                }
            }
            temp.at(i,j) = static_cast<int>(weightedSum / normalizationFactor);
        }
    }
    
   int min = temp.minim(); int max = temp.maxim();
   for(int i = 0; i < result.rows; i++){
        for(int j = 0; j < result.cols; j++){
                result.at(i,j) = (temp.at(i,j) - min) * 255.0 / (max - min);
        }
    }
}

template<class T>
T Matt<T>::minim(){
    T min = this->at(0,0);
    for(int i = 0; i < this->rows; i++){
        for(int j = 0; j < this->cols; j++){
            if(static_cast<int>(this->at(i,j)) < min) min = this->at(i,j);
        }
    }
    return min;
}

template<class T>
T Matt<T>::maxim(){
    T max = this->at(0,0);
    for(int i = 0; i < this->rows; i++){
        for(int j = 0; j < this->cols; j++){
            if(static_cast<int>(this->at(i,j)) > max) max = this->at(i,j);
        }
    }
    return max;
}
//basic functions:

template<class T>
int Matt<T>::sums(){
    int sum = 0;
    for(int i = 0; i < this->rows; i++){
        for(int j = 0; j < this->cols; j++){
            sum += static_cast<int>(this->at(i,j));
        }
    }
    return sum;
} 

//special matrices

template<class T>
Matt<T> Matt<T>::zeroes(int row){
    Matt<T> zeros(row);
    for(int i = 0; i < zeros.rows; i++){
        for(int j = 0; j < zeros.cols; j++){
            zeros.at(i,j) = 0;
        }
    }
    return zeros;
}

template<class T>
Matt<int> Matt<T>::ones(int row){
    Matt<int> temp(row);
    for(int i = 0; i < temp.rows; i++){
        for(int j = 0; j < temp.cols; j++){
            temp.at(i,j) = 1;
        }
    }
    return temp;
}

template<class T>
Matt<int> Matt<T>::boxKarnel(int row){
    Matt<int> karnel = Matt<T>::ones(row);
    return karnel;
}

template<class T>
Matt<int> Matt<T>::gaussianKernel(int row, float var){
    int center = row/2;
    double pi = 3.142459;
    Matt<double> gaussianDouble(row);
    for(int i = 0; i < gaussianDouble.rows; i++){
        for(int j = 0; j < gaussianDouble.cols; j++){
            double ex = ((i-center) * (i - center) + (j - center) * (j - center))/(2 * var * var);
            //std::cout<<"\n"<<ex<<"\n";
            gaussianDouble.at(i,j) = 1/(2 * pi * var * var) * std::exp(-1 * ex);
        }
    }
    double min = gaussianDouble.minim();
    double max = gaussianDouble.maxim();
    Matt<int> result(row);
    for(int i = 0; i < gaussianDouble.rows; i++){
        for(int j = 0; j < gaussianDouble.cols; j++){
            result.at(i,j) = round(gaussianDouble.at(i,j)/min);
        }
    }
    return result;

}

template<class T>
Matt<T> Matt<T>::sobelEdgeDetector(Matt<T>& gimage){
    cv::Mat_<int> sobX = (cv::Mat_<int>(3,3)<< 1, 0, -1, 2, 0, -2, 1, 0, -1);
    Matt<int> sobelX(sobX.rows, sobX.cols);
    Matt<int>::copyToMatt(sobX, sobelX);

    cv::Mat_<int> sobY = (cv::Mat_<int>(3,3)<< 1, 2, 1, 0, 0, 0, -1, -2, -1);
    Matt<int> sobelY(sobY.rows, sobY.cols);
    Matt<int>::copyToMatt(sobY, sobelY);

    Matt<int> edgeMapX = Matt<T>::sobelGradient(gimage, sobelX);
    Matt<int> edgeMapY = Matt<T>::sobelGradient(gimage, sobelY);

    Matt<T> temp = Matt<T>::gradientMagnitude(edgeMapX, edgeMapY);
    return temp;
}

template<class T>
Matt<int> Matt<T>::sobelGradient(Matt<T>& image, Matt<int>& kernel){
    
    int blocksize = kernel.rows;
    int normalizationFactor = kernel.sums();
    if(!normalizationFactor) normalizationFactor = 1;
    Matt<int> temp(image.rows, image.cols);
     for(int i = 0; i < image.rows; i++){
        for (int j = 0; j < image.cols; j++){
            int weightedSum = 0;
            for(int m = i - blocksize/2, k = 0; m <= i + blocksize/2 && k < kernel.rows; m++, k++){
                for(int n = j - blocksize/2, l = 0; n <= j + blocksize/2 && l < kernel.cols; n++, l++){
                    if (m < 0 || n < 0  || m >= image.rows || n >= image.cols) {
                        weightedSum += static_cast<int>(kernel.at(k,l) * 0);
                        continue;
                    }
                    weightedSum += kernel.at(k,l) * static_cast<int>(image.at(m,n));
                }
            }
            temp.at(i,j) = static_cast<int>(weightedSum / normalizationFactor);
        }
    }
    return temp;
}

template<class T>
Matt<T> Matt<T>::gradientMagnitude(Matt<int>& sobelX, Matt<int>& sobelY){
    Matt<int> temp(sobelX.rows, sobelX.cols);
    for(int i = 0; i < temp.rows; i++){
        for(int j = 0; j < temp.cols; j++){
            int value = static_cast<int>(sqrt(pow(sobelX.at(i,j),2) + pow(sobelY.at(i,j),2)));
            temp.at(i,j) = value;
        }
    }
    int min = temp.minim(); int max = temp.maxim();

    Matt<T> result(temp.rows, temp.cols);

    for(int i = 0; i < temp.rows; i++){
        for(int j = 0; j < temp.cols; j++){
            result.at(i,j) = static_cast<T>((temp.at(i,j) - min) * 255.0 / (max - min));
        }
    }
    return result;
}

template<class T>
Matt<int> Matt<T>::gradientPhase(Matt<int>& gX, Matt<int>& gY){
    Matt<int> temp(gX.rows, gX.cols);
    for(int i = 0; i < temp.rows; i++){
        for(int j = 0; j < temp.cols; j++){
            double angle = std::atan2(gY.at(i,j), gX.at(i,j)) * 180 / M_PI;
            if (angle < 0) angle += 180;
            if(angle <= 22 || angle >= 157) angle = 0;
            else if(angle > 22 && angle <= 67) angle = 45;
            else if(angle > 67 && angle <=107) angle = 90;
            else angle =135;
            temp.at(i,j) = static_cast<int>(angle);
        }
    }
    return temp;
}

template<class T>
void Matt<T>::nonMaximalFilter(Matt<T>& mag, Matt<int>& ph){
    Matt<T> temp(mag.rows, mag.cols);
    T a,b;
    for(int i = 0; i < temp.rows; i++){
        for(int j = 0; j < temp.cols; j++){

            if((i -1) < 0 || (i + 1) >= temp.rows || (j - 1) < 0 || (j+1) >= temp.cols){
                temp.at(i,j) = MINVAL;
                continue;
            }
            if(ph.at(i,j) == 0){
                a = mag.at(i, j - 1);
                b = mag.at(i, j + 1);
                if(mag.at(i,j) < a || mag.at(i,j) < b) temp.at(i,j) = MINVAL;
                else temp.at(i,j) = mag.at(i,j);
            }
            else if(ph.at(i,j) == 45){
                a = mag.at(i - 1, j + 1);
                b = mag.at(i + 1, j - 1);
                if(mag.at(i,j) < a || mag.at(i,j) < b) temp.at(i,j) = MINVAL;
                else temp.at(i,j) = mag.at(i,j);
            }
            else if(ph.at(i,j) == 90){
                a = mag.at(i - 1, j);
                b = mag.at(i + 1, j);
                if(mag.at(i,j) < a || mag.at(i,j) < b) temp.at(i,j) = MINVAL;
                else temp.at(i,j) = mag.at(i,j);
            }
            
            else{
                a = mag.at(i - 1, j - 1);
                b = mag.at(i + 1, j + 1);
                if(mag.at(i,j) < a || mag.at(i,j) < b) temp.at(i,j) = MINVAL;
                else temp.at(i,j) = mag.at(i,j);
            }
            
        }
    }
    mag = temp;
}

template<class T>
void Matt<T>::histThreshold(Matt<T>& edgeMap, T min, T max){
    // Matt<T> temp(edgeMap.rows, edgeMap.cols);
    for(int i = 0; i < edgeMap.rows; i++){
        for(int j = 0; j < edgeMap.cols; j++){
            if(edgeMap.at(i,j) <= min) edgeMap.at(i,j) = MINVAL;
            else if (edgeMap.at(i,j) >= max) edgeMap.at(i,j) = MAXVAL;
        }
    }
    for(int i = 0; i < edgeMap.rows; i++){
        for(int j = 0; j < edgeMap.cols; j++){
            if(edgeMap.at(i,j) > min && edgeMap.at(i,j) < max){
                bool x = 0;
                for(int m = i - 1; m <= (i + 1); m++){
                    for(int n = j - 1; n <= (j + 1); n++){
                        if(edgeMap.at(m,n) == MAXVAL) {
                            edgeMap.at(i,j) = MAXVAL;
                            x = 1;
                        }
                    }
                }
                if(!x) edgeMap.at(i,j) = MINVAL;
            }
        }
    }
    // edgeMap = temp;
}

template<class T>
void Matt<T>::cannyEdgeDetector(Matt<T>& gimage){
    cv::Mat_<int> sobX = (cv::Mat_<int>(3,3)<< 1, 0, -1, 2, 0, -2, 1, 0, -1);
    Matt<int> sobelX(sobX.rows, sobX.cols);
    Matt<int>::copyToMatt(sobX, sobelX);

    cv::Mat_<int> sobY = (cv::Mat_<int>(3,3)<< 1, 2, 1, 0, 0, 0, -1, -2, -1);
    Matt<int> sobelY(sobY.rows, sobY.cols);
    Matt<int>::copyToMatt(sobY, sobelY);

    Matt<int> edgeMapX = Matt<T>::sobelGradient(gimage, sobelX);
    Matt<int> edgeMapY = Matt<T>::sobelGradient(gimage, sobelY);

    Matt<T> temp = Matt<T>::gradientMagnitude(edgeMapX, edgeMapY);
    Matt<int> phase = Matt<T>::gradientPhase(edgeMapX, edgeMapY);
    Matt<T>::nonMaximalFilter(temp, phase);
    Matt<T>::histThreshold(temp, 10, 40);
    gimage = temp;
}

template<class T>
Matt<T>& Matt<T>::operator = (Matt<T>& M){
    this->rows = M.rows;
    this->cols = M.cols;
    this->step = M.step;
    for(int i = 0; i < M.rows; i++){
        for(int j = 0; j < M.cols; j++){
            this->at(i,j) = M.at(i,j);
        }
    }
    return *(this);
}


template <class T>
void Matt<T>::display(){
    for(int i = 0; i < this->rows; i++){
        for(int j = 0; j < this->cols; j++){
            std::cout<<" "<<std::setw(3)<<std::right<<std::setfill(' ')<<this->at(i,j);
        }
        std::cout<<std::endl;
    }
    std::cout<<std::endl;
}

template <class T>
Matt<T>::~Matt(){
    if(refcount && --*(refcount) == 0){
        delete[] matData;
        delete refcount;
       //std::cout<<"\nDestructorCalled\n";
    }
}
