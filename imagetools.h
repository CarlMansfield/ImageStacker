#ifndef IMAGETOOLS_H
#define IMAGETOOLS_H
#include "imagedata.h"
#include <iostream>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv/cv.h>
#include <QThread>

class ImageTools : public QObject
{
    Q_OBJECT
public:
    ImageTools(QObject *parent = 0);
    static cv::Mat increaseBrightness(ImageData& image, int value);
    void doSetup(QThread &thread);
    void clearCache();
    ImageData *tempData;
public slots:
    void loadFromFile();
signals:
    void imageRead();
private:
    uchar* pixels = nullptr;
};

#endif // IMAGETOOLS_H
