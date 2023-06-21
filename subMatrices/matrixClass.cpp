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
    this->step = M.step;
    this->rows = M.rows;
    this->cols = M.cols;
    this->refcount = M.refcount;
    *(refcount)++;
}

Matt::Matt( Matt &M, int rowStart, int rowEnd, int colStart, int colEnd){
    if ((rowEnd - rowStart + 1) > M.rows || (colEnd - colStart + 1) > M.cols){
        std::cout<<"\nOUT OF BOUNDS\n";
        return;
    }
    
    this->matData = M.matData + rowStart * M.step + colStart;
    this->step = M.step;
    this->rows = rowEnd - rowStart + 1;
    this->cols = colEnd - colStart + 1;
    this->refcount = M.refcount;
    *(refcount)++;
    
}

int& Matt::at(int i, int j){
    return *(matData +  i  * step + j);
}

Matt Matt::getRow(int row){
    Matt temp(*(this), row, row, 0, (this->cols - 1));
    return temp;
}

Matt Matt::getCol(int col){
    Matt temp(*(this), 0, (this->rows - 1), col, col);
    return temp;
}

Matt Matt::rowRange(int rowStart, int rowEnd){
    Matt temp(*(this), rowStart, rowEnd, 0, (this->cols-1));
    return temp;
}
Matt Matt::colRange(int colStart, int colEnd){
    Matt temp(*(this), 0, (this->rows-1), colStart, colEnd);
    return temp;
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
