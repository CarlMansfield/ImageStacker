#include "imagetools.h"

ImageTools::ImageTools()
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
