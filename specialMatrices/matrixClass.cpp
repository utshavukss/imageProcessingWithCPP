#include <iostream>
#include <iomanip>
#include <cmath>
#include "matClass.h"


void Matt::create(int m, int n){
    rows = m;
    cols = n;
    refcount = new int(1);

    if (rows == 0 || cols == 0) {
        matData = 0;
        return;
        }
    matData = new int[rows * cols];
}
void Matt::setValues(){
    for (int i = 0; i < rows; i++){
        for (int j = 0; j < cols; j++){
            this->at(i,j) = i * cols + j;
        }
    }
}

void Matt::setValues(int num){
    for(int i = 0; i < this->rows; i++){
        for(int j = 0; j < this->cols; j++){
            this->at(i,j) = num;
        }
    }
}

void Matt::identity(){
    if (this->rows != this->cols) return;
    for(int i = 0; i < this->rows; i++){
        for(int j = 0; j < this->cols; j++){
            this->at(i,j) = ((i == j)? 1: 0);
        }
    }
}

void Matt::diagonal(){
    if (this->rows != this->cols) return;
    for(int i = 0; i < this->rows; i++){
        for(int j = 0; j < this->cols; j++){
            this->at(i,j) = ((i == j)? (i * this->cols + j): 0);
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
    this->rows = M.rows;
    this->cols = M.cols;
    this->refcount = M.refcount;
    *(M.refcount)++;
}

Matt::Matt( Matt &M, int rowStart, int rowEnd, int colStart, int colEnd){
    if ((rowEnd - rowStart + 1) > M.rows || (colEnd - colStart + 1) > M.cols){
        std::cout<<"\nOUT OF BOUNDS\n";
        return;
    }
    this->create((rowEnd - rowStart + 1), (colEnd - colStart + 1));
    for(int i = 0; i < this-> rows ; i++){
        for(int j = 0; j < this->cols; j++){
            this->at(i,j) = M.at((i+rowStart) , (j + colStart));
        }
    }
    
}

int& Matt::at(int i, int j){
    return *(matData + i * cols + j);
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
