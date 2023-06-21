#ifndef LOGANALYSIS_H
#define LOGANALYSIS_H
#include <bits/stdc++.h>

void calculateFrequencies(std::vector<std::string>& logList, std::map<std::string , int>& transacFreq, int n);
std::vector<std::string> findSuspiciousUsers(std::map<std::string , int>& transacFreq, int threshold);

#endif