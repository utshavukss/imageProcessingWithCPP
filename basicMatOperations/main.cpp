#include <iostream>
#include "matClass.h"

int main(){
    //Use of OpenCV Mat class:
    cv::Mat mat1(2,2,CV_32FC1);
    cv::Mat mat2(2,2,CV_32FC1);

    for(int i = 0; i < mat1.rows; i++){
        for(int j = 0; j < mat1.cols; j++){
            mat1.at<float>(i,j) = i * mat1.cols + j;
        }
    }
    for(int i = 0; i < mat2.rows; i++){
        for(int j = 0; j < mat2.cols; j++){
            mat2.at<float>(i,j) = i * mat2.cols + j;
        }
    }

    cv::Mat mat3 = mat1 + mat2;
    std::cout<<std::endl<<"ADDITION USING cv::Mat: \n";
    for(int i = 0; i < mat3.rows; i++){
        for(int j = 0; j < mat3.cols; j++){
            std::cout<<" "<<mat3.at<float>(i,j);
        }
        std::cout<<std::endl;
    }

    mat3 = mat1 - mat2;
    std::cout<<std::endl<<"Subtraction USING cv::Mat: \n";
    for(int i = 0; i < mat3.rows; i++){
        for(int j = 0; j < mat3.cols; j++){
            std::cout<<" "<<mat3.at<float>(i,j);
        }
        std::cout<<std::endl;
    }

    mat3 = mat1 * mat2;
    std::cout<<std::endl<<"Multiplication USING cv::Mat: \n";
    for(int i = 0; i < mat3.rows; i++){
        for(int j = 0; j < mat3.cols; j++){
            std::cout<<" "<<mat3.at<float>(i,j);
        }
        std::cout<<std::endl;
    }

    //Use of defined Matrix class:
    Matt M(10,10);
    M.init();

    Matt M1(10);
    M1.init();

    Matt M2(10);
    std::cout<<"\n Initialized matrices:\n";
    M.display();
    M1.display();

    std::cout<<std::endl<<"Addition USING Matt class \n";
    M2 = M + M1;
    M2.display();
    
    std::cout<<std::endl<<"Subtraction USING class \n";
    M2 = M - M1;
    M2.display();

    std::cout<<std::endl<<"Multiplication USING Matt class\n";
    M2 = M * M1;
    M2.display();

    std::cout<<std::endl<<"transpose of above matrix\n";
    M2 = M2.transpose();
    M2.display();

    std::cout<<std::endl<<"Scalar addition\n";
    M2 = M2 + 5;
    M2.display();

    std::cout<<std::endl<<"Scalar Multiplication\n";
    M2 = M2 * 2;
    M2.display();

    std::cout<<std::endl<<"Scalar divison\n";
    M2 = M2 / 5;
    M2.display();

    std::cout<<std::endl<<"Scalar subtraction\n";
    M2 - 5;
    M2.display();

}