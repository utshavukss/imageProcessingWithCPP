#include <iostream>
#include "matClass.h"

int main(){
    Matt A(5);
    A.init();
    std::cout<<"\nThe original Matrix:\n";
    A.display();
    std::cout<<"\nEnter the row number:\n";
    int choice;
    std::cin >> choice;
    Matt B = A.getRow(choice);
    B.display();
    std::cout<<"\nEnter the column number:\n";
    std::cin >> choice ;
    Matt M = A.getCol(choice);
    M.display();
    std::cout<<std::endl<<"rowRange(2,4):"<<std::endl;
    Matt C = A.rowRange(2,4);
    C.display();
    std::cout<<std::endl<<"colRange(0,1):"<<std::endl;
    Matt F = C.colRange(0,3);
    F.display();
    std::cout<<std::endl<<"colRange(1,3):"<<std::endl;
    Matt D = A.colRange(1,3);
    D.display();

    //using cv::Mat class

    cv::Mat M1 = (cv::Mat_<int>(3,3)<<0, 1, 2, 3, 4, 5, 6, 7, 8);
    std::cout<<std::endl<<M1<<std::endl;

    std::cout<<"\nEnter the column/row number:\n";
    std::cin>>choice;

    cv::Mat M2 = M1.row(choice);
    std::cout<<std::endl<<M2<<std::endl;
    M2 = M1.col(choice);
    std::cout<<std::endl<<M2<<std::endl;

    std::cout<<"\nSubmatrices with rowRange(0,2), and colRange(0,2)\n";

    M2 = M1.rowRange(0,2);
    std::cout<<std::endl<<M2<<std::endl;

    M2 = M1.colRange(0,2);
    std::cout<<std::endl<<M2<<std::endl;

}