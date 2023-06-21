#include<iostream>
#include "matClass.h"


int main(){
    Matt<int> A(16,13);
    A.init();
    A.display();
    Matt<int> B;
    Matt<int>::adThreshold(A,B,3,3);
    A.display();

    //Using custom Matt Class

    cv::Mat image = cv::imread("/home/utshavuks/Documents/project1/utshavp/thresholding/images/pp.jpg", cv::IMREAD_GRAYSCALE);
    Matt<unsigned char> C(image.rows, image.cols);
    Matt<unsigned char>::copyToMatt(image, C);
    Matt<unsigned char> G;
    Matt<unsigned char>::adThreshold(C, G, 19, 3);

    Matt<unsigned char>::copyToMat(G, image);
    if(image.empty()) std::cout<<"error";
    // cv::namedWindow("Image displayed");
    // cv::imshow("Image displayed", image);
    cv::imwrite("Image.png", image);

    image = cv::imread("/home/utshavuks/Documents/project1/utshavp/thresholding/images/pp.jpg", cv::IMREAD_GRAYSCALE);
    Matt<unsigned char> D(image.rows, image.cols);
    Matt<unsigned char>::copyToMatt(image, D);
    Matt<unsigned char>::binThreshold(D, 80);
    Matt<unsigned char>::copyToMat(D, image);
    if(image.empty()) std::cout<<"error";
    // cv::Mat dst;
    // cv::threshold(image, dst, 80, 255, cv::THRESH_BINARY);
    // cv::imwrite("Image2.png", dst);

    //USING cv::Mat
    image = cv::imread("/home/utshavuks/Documents/project1/utshavp/thresholding/images/pp.jpg", cv::IMREAD_GRAYSCALE);
    cv::Mat result;
    cv::adaptiveThreshold(image, result, 255, cv::ADAPTIVE_THRESH_MEAN_C, cv::THRESH_BINARY, 19, 3);
    cv::imwrite("openCVAdaptiveimage.png", result);


    //BGR TO YUV(Y value only)
    image = cv::imread("/home/utshavuks/Documents/project1/utshavp/thresholding/images/pp.jpg",cv::IMREAD_COLOR);
    cv::Mat yuv;
    yuv = Matt<unsigned char>::bgrToYuv(image);
    cv::imwrite("BGRToYUV.png", yuv);

    //BGR TO YUV422
    image = cv::imread("/home/utshavuks/Documents/project1/utshavp/thresholding/images/pp.jpg",cv::IMREAD_COLOR);
    cv::Mat yuv422;
    yuv422 = Matt<unsigned char>::bgrToYuv422(image);
    cv::cvtColor(yuv422, image, cv::COLOR_YUV2BGR_YUYV);
    cv::imwrite("BGRToYUV422.png", image);
}