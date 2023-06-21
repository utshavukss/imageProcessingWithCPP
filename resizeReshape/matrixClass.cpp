#include <iostream>
#include <iomanip>
#include <cmath>
#include "matClass.h"


void Matt::create(int m, int n){
    rows = m;
    cols = n;
    step = cols;
    refcount = new int(1);

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
Matt::Matt(){
    this->create(0,0);
}

Matt::Matt(int m, int n){
 this->create(m,n);
}

Matt::Matt(int size){
 this->create(size, size);
}
Matt::Matt(Matt &M){
    this->matData = M.matData;
    this->step = M.cols;
    this->rows = M.rows;
    this->cols = M.cols;
    this->refcount = M.refcount;
    *(refcount)++;
}

Matt::Matt( Matt &M, int rowStart, int rowEnd, int colStart, int colEnd){
    
    this->matData = M.matData + rowStart * M.step + colStart;
    this->step = M.cols;
    this->rows = rowEnd - rowStart + 1;
    this->cols = colEnd - colStart + 1;
    this->refcount = M.refcount;
    *(refcount)++;
    
}

int& Matt::at(int i, int j){
    return *(matData +  i  * step + j);
}

Matt Matt::resize(int row, int col){
    Matt temp(*(this), 0, row-1, 0, col - 1);
    temp.step = col;
    // for (int i = 0; i < temp.rows; i++){
    //     for(int j = 0; j < temp.cols; j++){
    //         if (i >= this->rows || j >= this->cols) temp.at(i,j) = 0;
    //     }
    // }
    return temp;
}

Matt Matt::reshape(int row, int col){
    if (row * col == this->rows * this->cols){
        Matt temp(*(this), 0, (row - 1), 0, (col - 1));
        temp.step = col;
        return temp;
    }
    return 0;
}

void Matt::copyTo(Matt& M){
    M.create(this->rows, this->cols);
    for(int i = 0; i < this->rows; i++){
        for(int j = 0; j < this->cols; j++){
            M.at(i,j) = this->at(i,j);
        }
    }
}

Matt Matt::clone(){
    Matt temp(this->rows, this->cols);
    for(int i = 0; i < this->rows; i++){
        for(int j = 0; j < this->cols; j++){
            temp.at(i,j) = this->at(i,j);
        }
    }
    return temp;
}

bool Matt::empty(){
    if (matData) return false;
    return true;
    
}

void Matt::display(){
    for(int i = 0; i < this->rows; i++){
        for(int j = 0; j < this->cols; j++){
            std::cout<<" "<<std::setw(3)<<std::right<<std::setfill(' ')<<this->at(i,j);
        }
        std::cout<<std::endl;
    }
    std::cout<<std::endl;
}

Matt::~Matt(){
    if(refcount && --*(refcount) == 0){
        delete[] matData;
        delete refcount;
    }
}
