#include "Image.h"

void Image::setImage(QString path) {
    img.load(path);
}

QImage Image::getImage() {
    return this -> img;
}
