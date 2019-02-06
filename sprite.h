#ifndef SPRITE_H
#define SPRITE_H

#include "defines.h"

extern wchar_t *activeBuffer;

class Sprite
{
    private:
    public:
        const wchar_t** image;
        int imageIndex = 0;
        ipoint_t origin;
        int width, height;
        Sprite();
        Sprite(const wchar_t** image, const int& width, const int& height, const ipoint_t& origin = {0, 0});
        void SetImage(const int& index, const wchar_t* image, const int& width, const int& height);
        void SetOriginCenter();
        void Draw(const int& x, const int& y) const;
};

#endif