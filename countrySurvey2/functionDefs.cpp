#include <iostream>
#include "headerFile.h"
#include <bits/stdc++.h>

int Age_More_than_k(std::vector<personDetails>& arr, int n, int k){
    int i, count=0;
    for(i = 0; i < n; i++){
        if(arr[i].age > k) count++;
    }
    std::cout<<"\nrun the vako cha\n";
    return count;
}

int Persons_from_city(std::vector<personDetails>& arr, int n, std::string cityChoice){
    int i, count=0;
    for (i = 0; i < n; i++){
        if(arr[i].city == cityChoice) count++;
    }
    return count;
}

int salary_between(std::vector<personDetails>& arr, int n, double low, double high){
    int i, count=0;
    for (i = 0; i < n; i++){
        if(arr[i].salary >= low && arr[i].salary <= high) count++;
    }
    return count;
}

std::vector<std::string> splitStrings(std::string& input){
    
    std::stringstream ss(input);
    std::string temp;
    std::vector<std::string> output;

    while(ss >> temp){
        output.push_back(temp);
    }

    return output;
}