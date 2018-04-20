#ifndef IMAGE_H
#define IMAGE_H


class Image
{
public:
    Image(int width, int height, QString path, QString type, int exposure, int iso);
private:
    int width, height;
    QString type;
    QString path;
    int exposure;
    int iso;

};

#endif // IMAGE_H
