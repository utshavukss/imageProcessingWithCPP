#include <iostream>
#include <vector>
#include "declarations.h"


int main(){
    int i, j, n, q, temp;
    std::vector<int> tempOp;
    std::vector<int> ip;    //inputs
    std::vector<std::vector<int>> opp;     //operations 2D vector

    std::cin >> n;

    for (i = 0; i < n; i++){
        std::cin >> temp ;
        ip.push_back(temp);
    }

    std::cin >> q ;

    for (i = 0; i < q; i++){
        for(j = 0; j < OPERATOR_SIZE; j++){
            std::cin >> temp;
            tempOp.push_back(temp);
        }
        opp.push_back(tempOp);
        tempOp.clear();
    }
    for (i = 0; i < q; i++){
        for(j = 0; j < OPERATOR_SIZE; j++){
            std::cout<<"\t"<<opp[i][j];
        }
        std::cout<<std::endl;    
    }

    for (i = 0; i < q; i++){
        reverseArrayWithOperators(ip, opp[i]);
    }

    for (i = 0; i < n; i++){
        std::cout << ip[i] <<"\t";
    }
    
}