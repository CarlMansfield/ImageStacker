#ifndef IMAGETOOLS_H
#define IMAGETOOLS_H
#include "imagedata.h"
#include <iostream>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv/cv.h>

class ImageTools
{
public:
    ImageTools();
    static cv::Mat increaseBrightness(ImageData& image, int value);
};

#endif // IMAGETOOLS_H
