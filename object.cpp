#include "object.h"

void Object::draw(wchar_t * buffer) {
    // Draw only if we are on screen
    int location = bufferLocation(round(position.x) - sprite.origin.x, round(position.y) - sprite.origin.y);
    int pixel = 0;
    for (int i = 0; i < sprite.height; i++) {
        for (int j = 0; j < sprite.width; j++) {
            if (location >= 0 && location <= screenSize) buffer[location] = sprite.image[pixel];
            pixel++;
            location++;
        }
        location += WINDOW_WIDTH - sprite.width;
    }

    return;
}