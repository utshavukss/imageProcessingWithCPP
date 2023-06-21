#include <iostream>
#include "matClass.h"
#include <random>
#include <chrono>

int main(){
    
   
    Matt A(5);
    A.init();
    A.display();

    auto startt = std::chrono::high_resolution_clock::now();

    double result = A.determinant();
    auto endt = std::chrono::high_resolution_clock::now();
    auto durationt = std::chrono::duration_cast<std::chrono::microseconds>(endt - startt);

    std::cout<<"\n"<<result<<std::endl;
    std::cout << "Runtime: " << durationt.count() << " microseconds" << std::endl;

    startt = std::chrono::high_resolution_clock::now();
    Matt B = A.inverse();
    B.display();
    endt = std::chrono::high_resolution_clock::now();
    durationt = std::chrono::duration_cast<std::chrono::microseconds>(endt - startt);
    std::cout << "Runtime: " << durationt.count() << " microseconds" << std::endl;



    //cv::Mat

    cv::Mat M1(5,5,CV_32F);
    for(int i = 0; i < M1.rows; i++){
        for(int j = 0; j < M1.cols; j++){
            M1.at<float>(i,j) = A.at(i,j);
        }
    }
    std::cout<<std::endl<<M1;

    startt = std::chrono::high_resolution_clock::now();

    double d = cv::determinant(M1);

    endt = std::chrono::high_resolution_clock::now();
    durationt = std::chrono::duration_cast<std::chrono::microseconds>(endt - startt);

    std::cout<<"\n"<<d<<std::endl;
    std::cout << "Runtime: " << durationt.count() << " microseconds" << std::endl;

    startt = std::chrono::high_resolution_clock::now();
    cv::Mat M2;
    cv::invert(M1,M2);

    endt = std::chrono::high_resolution_clock::now();
    durationt = std::chrono::duration_cast<std::chrono::microseconds>(endt - startt);
    std::cout<<std::endl<<M2;
    std::cout << "\nRuntime: " << durationt.count() << " microseconds" << std::endl;
}