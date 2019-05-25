#ifndef STARDETECTION_H
#define STARDETECTION_H
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/imgcodecs/imgcodecs.hpp>
#include <opencv/cv.h>

class StarDetection
{
public:
    StarDetection();

    cv::Mat getBackground(cv::Mat inputImage);
    cv::Mat detectStars(cv::Mat inputImage, std::vector<std::vector<cv::Point>> &contours, std::vector<cv::Vec4i> &hierarchy);
};

#endif // STARDETECTION_H
