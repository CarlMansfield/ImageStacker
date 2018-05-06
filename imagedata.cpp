#include "imagedata.h"

ImageData::ImageData()
{

}

QString ImageData::getDimensions() {
    QString dimensions = QString::number(width);
    dimensions.append(" x ").append(QString::number(height));

    return dimensions;
}

uchar* ImageData::loadFromFile(QString filename, int width, int height) {
    LibRaw processor;
    processor.open_file(filename.toStdString().c_str());
    processor.unpack();
    processor.imgdata.params.no_auto_bright = 1;
    processor.dcraw_process();
    libraw_processed_image_t *output = processor.dcraw_make_mem_image();
    uchar *pixels;
    int pixelCount = width * height;
    int colorSize = output->bits / 8;
    qDebug(QString::number(colorSize).toStdString().c_str());
    int pixelSize = output->colors * colorSize;
    qDebug(QString::number(pixelSize).toStdString().c_str());
    pixels = new uchar[pixelCount * 4];
    uchar *data = output->data;
    for (int i = 0; i < pixelCount; i++, data += pixelSize) {
        if (output->colors == 3) {
            pixels[i * 4] = data[2 * colorSize];
            pixels[i * 4 + 1] = data[1 * colorSize];
            pixels[i * 4 + 2] = data[0];
        } else {
            pixels[i * 4] = data[0];
            pixels[i * 4 + 1] = data[0];
            pixels[i * 4 + 2] = data[0];
        }
    }
    processor.dcraw_clear_mem(output);

    return pixels;
}
