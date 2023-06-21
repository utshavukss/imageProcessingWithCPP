#include <bits/stdc++.h>
#include <iostream>
#include <sstream>
#include "loganalysis.h"

void calculateFrequencies(std::vector<std::string>& logList, std::map<std::string , int>& transacFreq, int n){
    int loopCount = 0;
    std::string word, prevWord; 
    for(int i = 0; i < n; i ++){
        prevWord = " ";
        std::stringstream str_obj(logList[i]);

        while (loopCount < 2){
            str_obj >> word;
            if (prevWord != word) transacFreq[word]++;
            prevWord = word;
            loopCount++;
        }
        loopCount = 0;
    }
}

std::vector<std::string> findSuspiciousUsers(std::map<std::string, int>& transacFreq, int threshold){
    std::vector<std::string> output;
    for(const auto& [key, value] : transacFreq){
        if (value >= threshold) output.push_back(key);
    }
    return output;
}