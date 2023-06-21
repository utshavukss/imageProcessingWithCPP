#include "matClass.h"

using namespace std;

int main(int argc, char* argv[]){
    if(argc != 2){
        return 1;
    }
    cv::Mat image = cv::imread(argv[1], cv::IMREAD_GRAYSCALE);
    cv::imwrite("gscaleimage.png", image);
    Matt<unsigned char> mattImage(image.rows, image.cols);
    Matt<unsigned char>::copyToMatt(image, mattImage);
    Matt<unsigned char> op(mattImage.rows, mattImage.cols);
    
    //gaussian kernel
    Matt<int> k = Matt<int>::gaussianKernel(7,1);
    k.display();

    Matt<int> box = Matt<unsigned char>::ones(7);
    Matt<unsigned char>::convolve(mattImage, op, box);
    cv::Mat blurImage = cv::Mat(op.rows, op.cols, CV_8UC1);
    Matt<unsigned char>::copyToMat(op,blurImage);
    cv::imwrite("blured_image_with_boxFilter.png", blurImage);

    Matt<unsigned char>::convolve(mattImage, op, k);
    Matt<unsigned char>::copyToMat(op,blurImage);
    cv::imwrite("blured_image_with_gaussianFilter.png", blurImage);

    Matt<int> lap(3);
    cv::Mat laplacianK = (cv::Mat_<int>(3,3)<<0,-1,0,-1,5,-1,0,-1,0);
    Matt<int>::copyToMatt(laplacianK, lap);
    lap.display();
    Matt<unsigned char>::copyToMatt(blurImage, mattImage);
    Matt<unsigned char>::convolve(mattImage, op, lap);
    Matt<unsigned char>::copyToMat(op,blurImage);
    cv::imwrite("sharpened_image_with_laplacian.png", blurImage);
    
    cv::Mat blurredImage;
    cv::GaussianBlur(image, blurredImage, cv::Size(11, 11), 0);
    cv::imwrite("openCV_blur.png", blurredImage);
    // Apply the Laplacian filter
    cv::Mat laplacianImage;
    cv::Laplacian(blurredImage, laplacianImage, CV_8U);
    cv::imwrite("openCV_laplacian.png", laplacianImage);

    // Perform image enhancement
    cv::Mat sharpenedImage = image - laplacianImage;
    cv::imwrite("openCV_sharp.png", sharpenedImage);
    
}