#include <bits/stdc++.h>
#include <iostream>
#include "loganalysis.h"

int main(){
    int n,i = 0, threshold;
    std::string logs;
    std::vector<std::string> logList, output;
    std::map<std::string, int> transacFreq;
    //input size of log list
    std::cout<<"\nInput size of log list\n";
    std::cin >> n;
    std::cin.ignore();
    //Input log list elements
    std::cout<<"\nInput log list elements\n";
    do{
        std::getline(std::cin, logs);
        logList.push_back(logs);
        i++;
    }while(i < n);
    for (i = 0; i < n; i++){
        std::cout<<"\n"<<i<<". "<<logList[i];
    }
    //Input threshold
    std::cout<<"\nInput threshold\n";
    std::cin >> threshold; 

    calculateFrequencies(logList, transacFreq, n);

    output = findSuspiciousUsers(transacFreq, threshold);

    std::cout<<"\nSuspicious users:\n";
    for(i = 0; i < output.size(); i++){
        std::cout<<output[i]<<std::endl;
    }
}