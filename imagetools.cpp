#include "imagetools.h"
#include <QDebug>

ImageTools::ImageTools(QObject *parent) : QObject(parent)
{

}

cv::Mat ImageTools::increaseBrightness(ImageData& image, int value)
{
    cv::Mat imagecv = cv::Mat(image.getHeight(), image.getWidth(), CV_8UC4, image.data, 0);
    cv::Mat new_image = cv::Mat::zeros(imagecv.rows, imagecv.cols, imagecv.type());
    for (int i = 0; i < imagecv.rows; i++) {
        for (int j = 0; j < imagecv.cols; j++) {
            for (int c = 0; c < 3; c++) {
                new_image.at<cv::Vec4b>(i,j)[c] = cv::saturate_cast<uchar>(1.0*(imagecv.at<cv::Vec4b>(i,j)[c]) + value);
            }
        }
    }

    return new_image;
}

void ImageTools::doSetup(QThread &thread)
{
    connect(&thread, SIGNAL(started()), this, SLOT(loadFromFile()));
}

void ImageTools::loadFromFile()
{
    qDebug() << "before thread start";
    qDebug() << "before thread start";
    processor.open_file(tempData->getPath().toStdString().c_str());
    processor.unpack();
    processor.imgdata.params.no_auto_bright = 1;
    processor.dcraw_process();
    qDebug() << "before thread start";
    libraw_processed_image_t *output = processor.dcraw_make_mem_image();
    int pixelCount = tempData->getWidth() * tempData->getHeight();
    int colorSize = output->bits / 8;
    qDebug(QString::number(colorSize).toStdString().c_str());
    int pixelSize = output->colors * colorSize;
    qDebug(QString::number(pixelSize).toStdString().c_str());
    pixels = new uchar[pixelCount * 4];
    uchar *outputData = output->data;
    for (int i = 0; i < pixelCount; i++, outputData += pixelSize) {
        if (output->colors == 3) {
            pixels[i * 4] = outputData[2 * colorSize];
            pixels[i * 4 + 1] = outputData[1 * colorSize];
            pixels[i * 4 + 2] = outputData[0];
        } else {
            pixels[i * 4] = outputData[0];
            pixels[i * 4 + 1] = outputData[0];
            pixels[i * 4 + 2] = outputData[0];
        }
    }
    processor.dcraw_clear_mem(output);
    qDebug("Image loaded");

    tempData->data = pixels;
    emit imageRead();
}

void ImageTools::clearCache() {
    delete pixels;
}

