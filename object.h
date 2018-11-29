#ifndef OBJECT_H
#define OBJECT_H

#include "defines.h"
#include "sprite.h"

class Object
{
    protected:
        fpoint_t position = {0, 0};
    public:
        Sprite sprite;
        void draw(wchar_t * screenBuffer);
};

#endif