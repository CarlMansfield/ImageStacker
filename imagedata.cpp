#include "imagedata.h"

ImageData::ImageData()
{

}

ImageData::ImageData(const ImageData &image)
{
    this->width = image.getWidth();
    this->height = image.getHeight();
    this->model = image.getCamera();
    this->dateTime = image.getDateTime();
    this->file = image.getPath();
    this->iso = image.getISO();
    this->temperature = image.getTemp();
    this->data = image.data;
    this->exposure = image.getExposure();
}

ImageData::~ImageData()
{
    qDebug("Destructor called");
    delete data;
}

void ImageData::clear()
{
    delete data;
}

QString ImageData::getDimensions() {
    QString dimensions = QString::number(width);
    dimensions.append(" x ").append(QString::number(height));

    return dimensions;
}

uchar* ImageData::loadFromFile() {
    LibRaw processor;
    processor.open_file(file.toStdString().c_str());
    processor.unpack();
    processor.imgdata.params.no_auto_bright = 1;
    processor.dcraw_process();
    libraw_processed_image_t *output = processor.dcraw_make_mem_image();
    int pixelCount = width * height;
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
    qDebug("Before return");
    return pixels;
}
