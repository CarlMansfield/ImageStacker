#include "stardetection.h"
#include <iostream>

StarDetection::StarDetection()
{

}

cv::Mat StarDetection::getBackground(cv::Mat inputImage)
{
    cv::Mat output = inputImage.clone();

    int medianFilter = 5;
    cv::medianBlur(output, output, medianFilter);
    int gaussianKernel = 25;
    cv::GaussianBlur(output, output, cv::Size(gaussianKernel, gaussianKernel), 0);

    return output;
}

cv::Mat StarDetection::detectStars(cv::Mat inputImage, std::vector<std::vector<cv::Point>> &contours, std::vector<cv::Vec4i> &hierarchy)
{
    cv::Mat inputGrey;

    if (inputImage.channels() == 1) {
        inputGrey = inputImage.clone();
    } else {
        inputGrey = cv::Mat(inputImage.rows, inputImage.cols, CV_32FC1);
        cv::cvtColor(inputImage, inputGrey, CV_RGB2GRAY);
    }

    cv::Mat background = getBackground(inputGrey);
    cv::Mat stars = inputGrey - background;
    cv::Mat thresholdImg = stars.clone();

    cv::threshold(stars, thresholdImg, 25, 255, cv::THRESH_BINARY);
    cv::findContours(thresholdImg, contours, hierarchy, CV_RETR_TREE, CV_CHAIN_APPROX_SIMPLE, cv::Point(0, 0));

    cv::Mat drawnCircles = cv::Mat::zeros(thresholdImg.size(), CV_8UC3);
    for (int i = 0; i < contours.size(); i++) {
        cv::Scalar colour = cv::Scalar(255, 0 , 255);
        cv::drawContours(drawnCircles, contours, i, colour, 2, 8, hierarchy, 0, cv::Point(0, 0));
    }

    return drawnCircles;
}
