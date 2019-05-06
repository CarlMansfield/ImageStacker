#ifndef IMAGEDATA_H
#define IMAGEDATA_H
#include <QString>
#include <QImage>
#include <libraw/libraw.h>
#include <exiv2/exiv2.hpp>

class ImageData
{
public:
    ImageData();
    ImageData(const ImageData &image);
    ~ImageData();
    void clear();
    uchar* data = nullptr;
    uchar* pixels = nullptr;
    void setPath(QString file) {this->file = file;}
    void setCamera(QString model) {this->model = model;}
    void setISO(int iso) {this->iso = iso;}
    void setExposure(QString exposure) {this->exposure = exposure;}
    void setDateTime(QString dateTime) {this->dateTime = dateTime;}
    void setWidth(int width) {this->width = width;}
    void setHeight(int height) {this->height = height;}
    void setTemp(float temp) {this->temperature = temp;}
    QString getPath() const {return file;}
    QString getCamera() const {return model;}
    int getISO() const {return iso;}
    int getHeight() const {return height;}
    int getWidth() const {return width;}
    QString getExposure() const {return exposure;}
    float getTemp() const  {return temperature;}
    QString getDateTime() const {return dateTime;}
    QString getDimensions();
    uchar* loadFromFile();
private:
    QString file;
    QString model;
    int iso;
    QString exposure;
    QString dateTime;
    int width;
    int height;
    float temperature;
};

#endif // IMAGEDATA_H
