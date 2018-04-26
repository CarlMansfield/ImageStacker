#ifndef IMAGEDATA_H
#define IMAGEDATA_H
#include <QString>

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
    QString getPath(){return file;}
    QString getCamera(){return model;}
    int getISO(){return iso;}
    int getExposure(){return exposure;}
    QString getDateTime(){return dateTime;}
    QString getDimensions();
private:
    QString file;
    QString model;
    int iso;
    int exposure;
    QString dateTime;
    int width;
    int height;
};

#endif // IMAGEDATA_H
