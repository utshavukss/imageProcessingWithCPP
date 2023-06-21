#include <iostream>
#include <vector>
#include <algorithm>
#include "declarations.h"

void reverseArrayWithOperators(std::vector<int>& ip, std::vector<int> tempOp){
    // std::vector<int> toReverse;
    // int i, j;

    // for (i = tempOp[0]; i <= tempOp[1]; i++){
    //     toReverse.push_back(ip[tempOp[0]]);
    //     ip.erase(ip.begin()+tempOp[0]);
    // }
    // reverse(toReverse.begin(),toReverse.end());
    // ip.insert(ip.begin()+tempOp[0], toReverse.begin(),toReverse.end());

    while(tempOp[0] < tempOp[1]){
        std::swap(ip[tempOp[0]], ip[tempOp[1]]);
        tempOp[0] += 1;
        tempOp[1] -= 1;
        //std::cout<<"\nLOOPING\n";
    }
    std::cout<<"\n\n";
}