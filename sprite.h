#include "defines.h"

class Sprite
{
    private:
    public:
        wchar_t *image = nullptr;
        ipoint_t origin = {0, 0};
        int width = 0, height = 0;
        void setImage(wchar_t * image, int width, int height);
        void setOriginCenter();
};