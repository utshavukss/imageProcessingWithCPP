#include <iostream>
#include "matClass.h"

int main(){
    Matt M(5);
    // Matrix M pre-initialized with zeroes
    M.display();
    //diagonal matrix M
    M.diagonal();
    M.display();
    //identity matrix M
    M.identity();
    M.display();
    //Matrix with all values entered by the user
    int choice;
    std::cin >> choice;
    M.setValues(choice);
    M.display();
    //matrix Initialized with position number.
    M.setValues();
    M.display();

    //cv::Mat implementation for above purposes
    cv::Mat idMatrix = cv::Mat::eye(5,5,CV_32S);
    std::cout<<std::endl<<"IDENTITY MATRIX\n";
    for(int i = 0; i < idMatrix.rows; i++){
        for(int j = 0; j < idMatrix.cols; j++){
            std::cout<<" "<<idMatrix.at<int>(i,j);
        }
        std::cout<<std::endl;
    }

    cv::Mat_<int> vector = (cv::Mat_<int>(1,6) << 1, 2, 3, 4, 5, 6);

    idMatrix = cv::Mat::diag(vector);
    std::cout<<"\nDiagonal Matrix\n";
    std::cout<<idMatrix;

    std::cout<<"\nZero Matrix and One matrix\n";
    cv::Mat zeroes = cv::Mat::zeros(5,5,CV_32S);
    cv::Mat ones = cv::Mat::ones(5,5,CV_32F);

    std::cout<<zeroes;
    std::cout<<std::endl<<ones;

}