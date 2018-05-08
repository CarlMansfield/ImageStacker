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
    static void increaseBrightness(ImageData& image, int value, uchar* temp);
};

#endif // IMAGETOOLS_H
