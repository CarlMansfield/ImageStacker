#include "imagedata.h"

ImageData::ImageData()
{

}

QString ImageData::getDimensions() {
    QString dimensions = QString::number(width);
    dimensions.append(" x ").append(QString::number(height));

    return dimensions;
}
