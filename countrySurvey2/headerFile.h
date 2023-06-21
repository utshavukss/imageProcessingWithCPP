#ifndef HEADERFILE_H
#define HEADERFILE_H

#include <iostream>
#include <string>
#include <vector>

struct personDetails {
    std::string name;
    int age;
    double salary;
    std::string city;
};

int Age_More_than_k(std::vector<personDetails>& arr, int n, int k);
int Persons_from_city(std::vector<personDetails>& arr, int n, std::string cityChoice);
int salary_between(std::vector<personDetails>& arr, int n, double s_lower, double s_higher);
std::vector<std::string> splitStrings(std::string& input);
#endif