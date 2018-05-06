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
    void setPath(QString file) {this->file = file;}
    void setCamera(QString model) {this->model = model;}
    void setISO(int iso) {this->iso = iso;}
    void setExposure(int exposure) {this->exposure = exposure;}
    void setDateTime(QString dateTime) {this->dateTime = dateTime;}
    void setWidth(int width) {this->width = width;}
    void setHeight(int height) {this->height = height;}
    void setTemp(float temp) {this->temperature = temp;}
    QString getPath(){return file;}
    QString getCamera(){return model;}
    int getISO(){return iso;}
    int getHeight(){return height;}
    int getWidth(){return width;}
    int getExposure(){return exposure;}
    float getTemp() {return temperature;}
    QString getDateTime(){return dateTime;}
    QString getDimensions();
    static uchar* loadFromFile(QString filename, int width, int height);
private:
    QString file;
    QString model;
    int iso;
    int exposure;
    QString dateTime;
    int width;
    int height;
    float temperature;
};

#endif // IMAGEDATA_H
