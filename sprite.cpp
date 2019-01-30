#include "sprite.h"

void Sprite::SetImage(wchar_t * _image, int _width, int _height) {
    width = _width;
    height = _height;
    image = _image;
}

void Sprite::SetOriginCenter() {
    origin.x = width / 2;
    origin.y = height / 2;
}