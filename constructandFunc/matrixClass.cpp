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

int Matt::dot(Matt& M){
    int r = ((this->rows <= M.rows)? this->rows : M.rows);
    int c = ((this->cols <= M.cols)? this->cols : M.cols);
    int result = 0;
    for(int i = 0; i < r ; i++){
        for(int j = 0; j < c ; j++){
            result += this->at(i,j) * M.at(i,j);
        }
    }
    return result;
}

Matt Matt::cross(Matt& M){
        int r = this->rows;
        int c = this->cols;

        Matt result(r,c);
        if(r >= c){
            for(int i = 0; i < r ; i++){
                for(int j = 0; j < c ; j++){
                    result.at(i,j) = (this->at((i+1)%3, j) * M.at((i+2)%3, j) - this->at((i+2)%3, j) * M.at((i+1)%3, j)) * ( (i+j)%2==0? 1 : -1);
                }
            }
        }
        else{
            for(int i = 0; i < r ; i++){
                for(int j = 0; j < c ; j++){
                    result.at(i,j) = (this->at(i, (j+2)%3) * M.at(i, (j+2)%3) - this->at(i, (j+2)%3) * M.at(i, (j+1)%3)) * ( (i+j)%2==0? 1 : -1);
                }
            }
        }
        return result;
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

int Matt::lOneNorm(){
    int result = 0;
    for(int i = 0; i < this->rows; i++){
        for(int j = 0; j < this->cols; j++){
            result += abs(this->at(i,j));
        }
    }
    return result;
}

float Matt::lTwoNorm(){
    float result = 0;
    for(int i = 0; i < this->rows; i++){
        for(int j = 0; j < this->cols; j++){
            result += pow(this->at(i,j) , 2);
        }
    }
    result = sqrt(result);
    return result;
}



Matt::~Matt(){
    if(refcount && --*(refcount) == 0){
        delete[] matData;
        delete refcount;
    }
}
