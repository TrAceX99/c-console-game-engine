#include "defines.h"

extern wchar_t *activeBuffer;

class Sprite
{
    private:
    public:
        const wchar_t* image;
        ipoint_t origin;
        int width, height;
        Sprite();
        Sprite(const wchar_t image[], int width, int height, ipoint_t origin = {0, 0});
        void SetImage(const wchar_t image[], int width, int height);
        void SetOriginCenter();
        void Draw(int x, int y);
};