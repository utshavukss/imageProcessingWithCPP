#include <iostream>
#include "matClass.h"
#include <random>
#include <chrono>
#include "matrixClass.cpp"

int main(){
    
   
    // Matt<float> A(5);
    // A.init();
    // A.display();

    // auto startt = std::chrono::high_resolution_clock::now();

    // double result = A.determinant();
    // auto endt = std::chrono::high_resolution_clock::now();
    // auto durationt = std::chrono::duration_cast<std::chrono::microseconds>(endt - startt);

    // std::cout<<"\n"<<result<<std::endl;
    // std::cout << "Runtime: " << durationt.count() << " microseconds" << std::endl;

    // startt = std::chrono::high_resolution_clock::now();
    // Matt<float> B = A.inverse();
    // B.display();
    // endt = std::chrono::high_resolution_clock::now();
    // durationt = std::chrono::duration_cast<std::chrono::microseconds>(endt - startt);
    // std::cout << "Runtime: " << durationt.count() << " microseconds" << std::endl;



    // //cv::Mat

    // cv::Mat M1(5,5,CV_32F);
    // for(int i = 0; i < M1.rows; i++){
    //     for(int j = 0; j < M1.cols; j++){
    //         M1.at<float>(i,j) = A.at(i,j);
    //     }
    // }
    // std::cout<<std::endl<<M1;

    // startt = std::chrono::high_resolution_clock::now();

    // double d = cv::determinant(M1);

    // endt = std::chrono::high_resolution_clock::now();
    // durationt = std::chrono::duration_cast<std::chrono::microseconds>(endt - startt);

    // std::cout<<"\n"<<d<<std::endl;
    // std::cout << "Runtime: " << durationt.count() << " microseconds" << std::endl;

    // startt = std::chrono::high_resolution_clock::now();
    // cv::Mat M2;
    // cv::invert(M1,M2);

    // endt = std::chrono::high_resolution_clock::now();
    // durationt = std::chrono::duration_cast<std::chrono::microseconds>(endt - startt);
    // std::cout<<std::endl<<M2;
    // std::cout << "\nRuntime: " << durationt.count() << " microseconds" << std::endl;

    std::vector<int> vec = {1,2,3,4,5,6,7};

    Matt<int> A = Matt<int>::diag(vec.size(), vec);
    A.init();
    A.display();

    Matt<int> X = Matt<int>::identity(vec.size());
    X.init();
    X.display();
    Matt<int> Y = X * A;

    std::cout<<"\n"<<X.at(0,0)<<std::endl;
    Y.display();

    // Matt<int> B = A.getRow(3);
    // B.display();
    // B = A.getCol(3);
    // B.display();

    // B = A.rowRange(0, 2);  
    // B.display();
    // B = A.colRange(2,4);
    // B.display();

    // Matt<int> C(B, 3, 4, 1, 2);
    // C.display();

    // cv::Mat input = (cv::Mat_<int>(1,5)<<1,2,4,5,6);
    // cv::Mat diagm = cv::Mat::diag(input);
    // std::cout<<diagm<<"\n";
    // cv::Mat M2 = diagm.col(2);
    // std::cout<<M2<<"\n";
    
}