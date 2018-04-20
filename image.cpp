#include "image.h"

Image::Image(int width, int height, QString path, QString type, int exposure, int iso)
{
    this->width = width;
    this->height = height;
    this->path = path;
    this->type = type;
    this->exposure = exposure;
    this->iso = iso;
}
