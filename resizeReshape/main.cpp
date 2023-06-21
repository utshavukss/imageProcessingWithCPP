#include <iostream>
#include "matClass.h"

using namespace std;
using namespace cv;

int main(){
    //using custom Matt class:
    std::cout<<"\nInitial Matrix:\n";
    Matt A(4);
    A.init();
    A.display();

    std::cout<<"\nResized to 3 x 6 Matrix:\n";
    Matt B = A.resize(3,6);
    B.display();
    A.display();

    std::cout<<"\nReshaped to to 2 x 8 Matrix:\n";
    Matt C = A.reshape(2,8);
    C.display();

    std::cout<<"\nCopied Original matrix to new Matrix:\n";
    Matt D;
    A.copyTo(D);
    D.display();

    std::cout<<"\nCloned the reshaped Matrix\n";
    Matt E = C.clone();
    E.display();

    cout<<"\nEmpty or not:\n";
    Matt X(0,4);
    cout<<endl<<(X.empty()? "true": "false");
    cout<<endl<<(A.empty()? "true": "false")<<endl;

    Matt U;
    U = A;
    U.display();


    Mat matrix;
    std::cout<<"\nUsinv cv::Mat class\n";
    matrix.create(4,4,CV_16S);
    for (int i = 0; i < matrix.rows; i++){
        for(int j =0; j < matrix.cols; j++){
            matrix.at<short>(i,j) = i*matrix.cols+j;
        }
    }
    cout<<matrix;

    Mat resMat;
    Size outputSize(5,5);

    std::cout<<"\nResized to 5x5 Matrix:\n";
    cv::resize(matrix, resMat, outputSize);
    cout<<endl<<resMat;

    Mat M = matrix.reshape(0,2);
    
    std::cout<<"\nReshaped to Matrix with two rows:\n";
    cout<<endl<<M;

    Mat cpm;
    matrix.copyTo(cpm);
    std::cout<<"\nCopyTo using cv::Mat :\n";
    cout<<cpm;

    Mat clm = resMat.clone();
    std::cout<<"\nClone resized Matrix using cv::Mat :\n";
    cout<<clm;

    Mat m;

    cout<<endl<<(m.empty()? "true": "false");
    cout<<endl<<(clm.empty()? "true": "false")<<endl;
}