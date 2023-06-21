#include <iostream>
#include <vector>
#include "matClass.h"

using namespace std;

int main(){

    cv::Mat mat(100, 100, CV_8UC3);
    cv::Vec3b pixel(97, 96, 97);

    // Set the values of the matrix
    for (int i = 0; i < mat.rows; i++){
        for(int j = 0; j < mat.cols; j++){
            mat.at<cv::Vec3b>(i,j) = pixel;
        }
    }
    // Print the values of the matrix to the console
    for (int i = 0; i < mat.rows; i++) {
        for (int j = 0; j < mat.cols; j++) {
            cv::Vec3b pixxel = mat.at<cv::Vec3b>(i,j);
                std::cout<<"[ ";
            for (int channel = 0; channel < 3; channel++) {
                std::cout << pixxel[channel] << ", ";
            }
            std::cout<<"]\t";
            //std::cout<<mat.at<cv::Vec3b>(i,j)[1];
        }
        std::cout << std::endl;
    }
    //using the Matt class
    Matt M(3,3);
    for (int i = 0; i < M.row; i++) {
            for (int j = 0; j < M.col; j++) {
                M.at(i,j) = i * M.col + j;
            }
    }

    Matt M1(2);
    for (int i = 0; i < M1.row; i++) {
            for (int j = 0; j < M1.col; j++) {
                M1.at(i,j) = M.at(i,j);
            }
    }

    M.display();
    M1.display();
   
    return 0;
}