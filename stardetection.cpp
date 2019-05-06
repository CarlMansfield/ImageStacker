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

cv::Mat StarDetection::detectStars(cv::Mat inputImage)
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

    cv::threshold(stars, thresholdImg, 50, 255, cv::THRESH_BINARY);

    std::vector<cv::Vec3f> circles;
    cv::HoughCircles(thresholdImg, circles, cv::HOUGH_GRADIENT, 1, thresholdImg.rows/8, 1, 10, 0, 0);
    cv::Mat drawnCircles = thresholdImg.clone();

    cv::imshow("Thresholded", circles);
    cvWaitKey(0);

    cv::cvtColor(thresholdImg, drawnCircles, CV_GRAY2RGB);
    std::cout << "Stars found: " << circles.size() << std::endl;
    for (int i = 0; i < circles.size(); i++) {
        cv::Vec3i c = circles[i];
        cv::Point center = cv::Point(c[0], c[1]);
        int radius = c[2];
        cv::circle(drawnCircles, center, radius, cv::Scalar(255, 0, 255), 2, cv::LINE_AA);
    }

    return drawnCircles;
}
