#include <iostream>
#include "matClass.h"


void Matt::create(int m, int n){
    rows = m;
    cols = n;
    refcount = 0;

    if (rows == 0 || cols == 0) {
        matData = 0;
        return;
        }
    matData = new int[rows * cols];
}
void Matt::init (){
    for (int i = 0; i < rows; i++){
        for (int j = 0; j < cols; j++){
            this->at(i,j) = i * cols + j;
        }
    }
}
Matt::Matt(int m, int n){
 this->create(m,n);
}

Matt::Matt(int size){
 this->create(size, size);
}

int& Matt::at(int i, int j){
    return *(matData + i * cols + j);
}

void Matt::display(){
    for(int i = 0; i < this->rows; i++){
        for(int j = 0; j < this->cols; j++){
            std::cout<<" "<<this->at(i,j);
        }
        std::cout<<std::endl;
    }
    std::cout<<std::endl;
}

Matt Matt::operator+(Matt& Mat2){
    if(Mat2.rows != rows || Mat2.cols != cols) {
        std::cout<<"\nCan't Add\n";
        return 0;
        }
    Matt temp(Mat2.rows, Mat2.cols);
    for(int i = 0; i < this->rows; i++){
        for(int j = 0; j < this->cols; j++){
            temp.at(i,j) = at(i,j) + Mat2.at(i,j);
        }
    }
    return temp;
}

Matt Matt::operator - (Matt& Mat2){
    if(Mat2.rows != rows || Mat2.cols != cols) {
        std::cout<<"\nCan't Add\n";
        return 0;
        }
    Matt temp(Mat2.rows, Mat2.cols);
    for(int i = 0; i < this->rows; i++){
        for(int j = 0; j < this->cols; j++){
            temp.at(i,j) = at(i,j) - Mat2.at(i,j);
        }
    }
    return temp;
}

Matt Matt::operator*(Matt& Mat2){
    if(this->cols != Mat2.rows){
        std::cout<<"\nCan't multiply\n";
        Matt temp(this->rows, this->cols);
        return temp;
    }
    Matt temp(this->rows, Mat2.cols);
    for(int i = 0; i < this->rows; i++){
        for(int j = 0; j < Mat2.cols; j++){
            for(int k = 0; k < Mat2.rows; k++){
                temp.at(i,j) += (*this).at(i,k) * Mat2.at(k,j);
            }
        }
    }
    return temp;
}

void Matt::operator - (int num){
    for(int i = 0; i < this->rows; i++){
        for(int j = 0; j < this->cols; j++){
            this->at(i,j) -= num;
        }
    }
}
Matt Matt::operator + (int num){
    Matt temp(this->rows, this->cols);
    for(int i = 0; i < this->rows; i++){
        for(int j = 0; j < this->cols; j++){
            temp.at(i,j) = this->at(i,j) + num;
        }
    }
    return temp;
}
Matt Matt::operator * (int num){
    Matt temp(this->rows, this->cols);
    for(int i = 0; i < this->rows; i++){
        for(int j = 0; j < this->cols; j++){
            temp.at(i,j) = this->at(i,j) * num;
        }
    }
    return temp;
}
Matt Matt::operator / (int num){
    Matt temp(this->rows, this->cols);
    for(int i = 0; i < this->rows; i++){
        for(int j = 0; j < this->cols; j++){
            temp.at(i,j) = this->at(i,j) / num;
        }
    }
    return temp;
}
Matt Matt::transpose(){
    Matt temp(this->cols, this->rows);
    for(int i = 0; i < temp.cols; i++){
        for(int j = 0; j < temp.rows; j++){
            temp.at(i,j) = this->at(j,i);
        }
    }
    return temp;
}

// Matt::~Matt(){
//     if(refcount == 0) delete[] matData;
// }
