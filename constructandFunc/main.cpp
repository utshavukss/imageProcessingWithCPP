#include <iostream>
#include "matClass.h"

int main(){
    Matt M1(5);
    M1.init();

    Matt M2(M1);
    M2.display();

    Matt M3(M2);
    M3.display();

    Matt M4(M1, 2 , 4, 0, 4);
    M4.display();

    Matt M5(M4);
    M5.display();

    std::cout<<"\nDot Product:\n";
    Matt A(3,1);
    Matt B(3,1);
    A.init(); 
    B.init();
    int dotPr = A.dot(B);
    std::cout<<std::endl<<dotPr;

    std::cout<<"\nCross Product:\n";
    Matt E = A.cross(B);
    E.display();

    dotPr = A.lOneNorm();
    std::cout<<"\n L1 Normalized value: "<<dotPr<<std::endl;

    float Pr = A.lTwoNorm();
    std::cout<<"\n L2 Normalized value: "<<Pr<<std::endl;

    //cv::Mat class implementation
    std::cout<<"\nCV::Mat class implementation\n";

    cv::Mat vec1 = (cv::Mat_<int>(1, 3) << 0, 1, 2);
    cv::Mat vec2 = (cv::Mat_<int>(1, 3) << 0, 1, 2);

    int dotProduct = vec1.dot(vec2);

    std::cout << "\n Dot Product: " << dotProduct << std::endl;

    cv:: Mat vec3 = vec1.cross(vec2);
    std::cout<<"\nCross Product: "<< vec3;

    int l1Norm = cv::norm(vec1, cv::NORM_L1);
    float l2Norm = cv::norm(vec1, cv::NORM_L2);

    std::cout<<"\nL1 Norm: "<< l1Norm<<"\t L2 Norm: "<< l2Norm<<std::endl;
    }