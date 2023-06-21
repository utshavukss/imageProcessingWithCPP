#include <iostream>
#include "matClass.h"
#include <boost/tuple/tuple.hpp>
#include "matplotlibcpp.h"
// #include <boost/iostreams/device/file_descriptor.hpp>
// #include <gnuplot-iostream.h>
#include <map>

namespace plt = matplotlibcpp;

int main(int arg, char** argv){
    if (arg!=2){
        std::cout<<"Provide path to one image!";
        return -1;
    }
    cv::Mat gimage = cv::imread(argv[1], cv::IMREAD_GRAYSCALE);
    cv::imwrite("grayscaleImage.png", gimage);
    Matt<unsigned char> gi(gimage.rows, gimage.cols);
    Matt<unsigned char>::copyToMatt(gimage, gi);
    std::map<unsigned char, int> hist = Matt<unsigned char>::createHist(gi);

    std::vector<int> keys;
    std::vector<int> values;
    for (const auto& pair : hist) {
        keys.push_back(static_cast<int>(pair.first));
        values.push_back(pair.second);
    }

    // Plot the histogram
   
    plt::bar(keys, values);
    plt::title("Histogram");
    plt::xlabel("Keys");
    plt::ylabel("Values");
    plt::show();

    Matt<unsigned char>::contrastStretch(hist, gi);
    Matt<unsigned char>::copyToMat(gi, gimage);
    cv::imwrite("Enhanced image.png", gimage);

    keys.clear(); values.clear();

    for (const auto& pair : hist) {
        keys.push_back(static_cast<int>(pair.first));
        values.push_back(pair.second);
    }

    plt::bar(keys, values);
    plt::title("Histogram");
    plt::xlabel("Keys");
    plt::ylabel("Values");

    plt::show();

    return 0;


}