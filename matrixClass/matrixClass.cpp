#include <iostream>
#include "matClass.h"
using namespace std;

    void Matt::create(int m, int n){
        row = m;
        col = n;
        refCount = 0;
        if(m == 0 || n == 0){
            matData = 0;
            return;
        }
        matData = new int[m * n];
    }
    Matt::Matt(int m, int n){
        create (m,n);
        }
    Matt::Matt(int size) {
        create(size, size);
        }

    int& Matt::at(int r, int c){
        return *(matData + r*col +c);
    }

    Matt::~Matt(){
        if(matData != 0 && refCount == 0) delete[] matData;
    }

    void Matt::display(){
        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
            cout<< *(matData+i*col+j) <<"\t";
        }
        cout<<endl;
        }
    }