#include <iostream>
#include <iomanip>
#include <cmath>
#include "matClass.h"
#include <random>

std::random_device rd;
std::mt19937 generator(rd());

int minNumber = 0;
int maxNumber = 11;

std::uniform_int_distribution<int> distribution(minNumber, maxNumber);

template class Matt<int>;
template class Matt<float>;
template class Matt<char>;
template class Matt<double>;

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
    for(int i = 0; i < this->rows; i++){
        for(int j = 0; j < this->cols; j++){
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
    Matt temp;
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

// Special matrices:

template <class T>
Matt<T> Matt<T>::diag(int row, std::vector<T>& vec){
    Matt<T> temp(row);
    for(int i = 0; i < temp.rows; i++){
        for(int j = 0; j < temp.cols; j++){
            if (i == j) temp.at(i,j) = vec[i];
            else temp.at(i,j) = 0;
        }
    }
    return temp;
}
template <class T>
Matt<T> Matt<T>::identity(int row){
    std::vector<T> vec(row, static_cast<T>(1));
    Matt<T> temp = Matt<T>::diag(row, vec);
    return temp;
}

template <class T>
Matt<T> Matt<T>::zeroes(int row, int col){
    Matt<T> temp(row,col);
    for(int i = 0; i < temp.rows; i++){
        for(int j = 0; j < temp.cols; j++){
            temp.at(i,j) = 0;
        }
    }
    return temp;
}
template <class T>
Matt<T> Matt<T>::ones(int row, int col){
    Matt<T> temp(row,col);
    for(int i = 0; i < temp.rows; i++){
        for(int j = 0; j < temp.cols; j++){
            temp.at(i,j) = 1;
        }
    }
    return temp;
}

//subMatrices
template <class T>
Matt<T> Matt<T>::getRow(int row){
    Matt temp(*(this), row, row, 0, this->cols - 1);
    return temp;
}

template <class T>
Matt<T> Matt<T>::getCol(int col){
    Matt temp(*(this), 0, this->rows - 1, col, col);
    return temp;
}

template <class T>
Matt<T> Matt<T>::rowRange(int a, int b){
    Matt temp(*(this), a, b, 0, this->cols - 1);
    return temp;
}

template <class T>
Matt<T> Matt<T>::colRange(int a, int b){
    Matt temp(*(this), 0, this->rows - 1, a, b);
    return temp;
}

//basic Matrix Operations
template <class T>
Matt<T> Matt<T>::operator+(Matt& Mat2){
    if(Mat2.rows != rows || Mat2.cols != cols) {
        std::cout<<"\nCan't Add\n";
        return 0;
        }
    Matt<T> temp(Mat2.rows, Mat2.cols);
    for(int i = 0; i < this->rows; i++){
        for(int j = 0; j < this->cols; j++){
            temp.at(i,j) = this->at(i,j) + Mat2.at(i,j);
        }
    }
    return temp;
}

template <class T>
Matt<T> Matt<T>::operator - (Matt<T>& Mat2){
    if(Mat2.rows != rows || Mat2.cols != cols) {
        std::cout<<"\nCan't Add\n";
        return 0;
        }
    Matt<T> temp(Mat2.rows, Mat2.cols);
    for(int i = 0; i < this->rows; i++){
        for(int j = 0; j < this->cols; j++){
            temp.at(i,j) = at(i,j) - Mat2.at(i,j);
        }
    }
    return temp;
}

template <class T>
Matt<T> Matt<T>::operator * (Matt<T>& Mat2){
    if(this->cols != Mat2.rows){
        std::cout<<"\nCan't multiply\n";
        Matt<T> temp(this->rows, this->cols);
        return temp;
    }
    Matt<T> temp(this->rows, Mat2.cols);
    for(int i = 0; i < this->rows; i++){
        for(int j = 0; j < Mat2.cols; j++){
            for(int k = 0; k < Mat2.rows; k++){
                temp.at(i,j) += (*this).at(i,k) * Mat2.at(k,j);
            }
        }
    }
    return temp;
}

template <class T>
void Matt<T>::operator - (int num){
    for(int i = 0; i < this->rows; i++){
        for(int j = 0; j < this->cols; j++){
            this->at(i,j) -= num;
        }
    }
}

template <class T>
Matt<T> Matt<T>::operator + (int num){
    Matt<T> temp(this->rows, this->cols);
    for(int i = 0; i < this->rows; i++){
        for(int j = 0; j < this->cols; j++){
            temp.at(i,j) = this->at(i,j) + num;
        }
    }
    return temp;
}

template <class T>
Matt<T> Matt<T>::operator * (int num){
    Matt<T> temp(this->rows, this->cols);
    for(int i = 0; i < this->rows; i++){
        for(int j = 0; j < this->cols; j++){
            temp.at(i,j) = this->at(i,j) * num;
        }
    }
    return temp;
}

template <class T>
Matt<T> Matt<T>::operator / (int num){
    Matt<T> temp(this->rows, this->cols);
    for(int i = 0; i < this->rows; i++){
        for(int j = 0; j < this->cols; j++){
            temp.at(i,j) = this->at(i,j) / num;
        }
    }
    return temp;
}

template<class T>
Matt<T>& Matt<T>::operator = (Matt<T>& M){
    delete[] this->matData;
    this->create(M.rows, M.cols);
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
    }
}
