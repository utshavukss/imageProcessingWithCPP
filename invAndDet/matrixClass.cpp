#include <iostream>
#include <iomanip>
#include <cmath>
#include "matClass.h"
#include <random>

std::random_device rd;
std::mt19937 generator(rd());

int minNumber = 0;
int maxNumber = 10;

std::uniform_int_distribution<int> distribution(minNumber, maxNumber);


void Matt::create(int m, int n){
    rows = m;
    cols = n;
    step = cols;
    refcount = new int(1);

    if (rows == 0 || cols == 0) {
        matData = 0;
        return;
        }
    matData = new float[rows * cols];
}
void Matt::init (){
    for (int i = 0; i < rows; i++){
        for (int j = 0; j < cols; j++){
            this->at(i,j) = distribution(generator);
            // this->at(i,j) = i * step + j;
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

float& Matt::at(int i, int j){
    return *(matData +  i  * step + j);
}
void Matt::copyTo(Matt& M){
    M.create(this->rows, this->cols);
    for(int i = 0; i < this->rows; i++){
        for(int j = 0; j < this->cols; j++){
            M.at(i,j) = this->at(i,j);
        }
    }
}

double Matt::determinant(){
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

Matt Matt::triangularU(){
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

bool Matt::swapCols(int i){
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

Matt Matt::inverse(){
    Matt temp;
    if (this->rows != this->cols){
        std::cout<<"\nNot invertible!!!\n";
        return temp;
    }
    double det = this->determinant();
    if(!det) return temp;
    this->copyTo(temp);
    Matt minor(temp.rows - 1);

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

void Matt::setMinor(Matt& child, int r, int c){
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

void Matt::transpose(){
    for(int i = 0; i < this->rows; i++){
        for(int j = i + 1; j < this->cols; j++){
           std::swap(this->at(i,j), this->at(j,i)) ;
        }
    }
}

Matt& Matt::operator/(double det){
    for(int i = 0; i < this->rows; i++){
        for(int j = 0; j < this->cols; j++){
            this->at(i,j) = static_cast<float>(this->at(i,j)/det);
        }
    }
    return *(this);
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
