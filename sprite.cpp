#include "sprite.h"

Sprite::Sprite() {
    width = 0;
    height = 0;
    origin = {0, 0};
}

Sprite::Sprite(const wchar_t _image[], int _width, int _height, ipoint_t _origin) {
    width = _width;
    height = _height;
    image = _image;
    origin = _origin;
}

void Sprite::SetImage(const wchar_t _image[], int _width, int _height)
{
    width = _width;
    height = _height;
    image = _image;
}

void Sprite::SetOriginCenter() {
    origin.x = width / 2;
    origin.y = height / 2;
}

void Sprite::Draw(int x, int y) {
    if (!image)
        return;

    int cutoutLeft = Clamp(origin.x - x, 0, width);
    int cutoutRight = Clamp(x + width - origin.x - WINDOW_WIDTH, 0, width);
    int cutoutTop = Clamp(origin.y - y, 0, height);
    int cutoutBottom = Clamp(y + height - origin.y - WINDOW_HEIGHT, 0, height);

    int pixel = cutoutTop * width + cutoutLeft;
    int location = BufferLocation(x - origin.x + cutoutLeft, y - origin.y + cutoutTop);

    for (int i = 0; i < height - cutoutBottom - cutoutTop; i++)
    {
        for (int j = 0; j < width - cutoutLeft - cutoutRight; j++)
        {
            if (image[pixel]) activeBuffer[location] = image[pixel];
            pixel++;
            location++;
        }
        pixel += cutoutLeft + cutoutRight;
        location += WINDOW_WIDTH - width + cutoutLeft + cutoutRight; // New line on screen
    }

    return;
}