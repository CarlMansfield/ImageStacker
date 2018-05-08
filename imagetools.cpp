#include "imagetools.h"

ImageTools::ImageTools()
{

}

void ImageTools::increaseBrightness(ImageData &image, int value, uchar* temp)
{
    qDebug("Before cv mat");
    cv::Mat imagecv = cv::Mat(image.getHeight(), image.getWidth(), CV_8UC4, image.data, 0);
    qDebug("Before new image");
    cv::Mat new_image = cv::Mat::zeros(imagecv.rows, imagecv.cols, imagecv.type());

    qDebug("Before brightness");

    for (int i = 0; i < imagecv.rows; i++) {
        for (int j = 0; j < imagecv.cols; j++) {
            for (int c = 0; c < 3; c++) {
                //qDebug("Before edit");
                new_image.at<cv::Vec4b>(i,j)[c] = cv::saturate_cast<uchar>(1.0*(imagecv.at<cv::Vec4b>(i,j)[c]) + value);

            }
        }
    }

    qDebug("After edit");
    int image_size = new_image.total() * new_image.elemSize();
    qDebug("Before memcpy");
    std::cout << image_size << std::endl;
    std::memcpy(temp, new_image.data, image_size * sizeof(uchar));
    qDebug("After memcpy");
}
