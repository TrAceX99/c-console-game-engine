#include "object.h"

int Object::currID;
std::vector<Object*> Object::objects;

Object::Object() {
    id = currID++;
    objects.push_back(this);
}

void Object::Update(double& deltaTime) {
    relativePosition = position - cameraPos;
}

bool Object::BoundingBoxInCamera() {
    return (relativePosition.x + sprite.width - sprite.origin.x > 0.5 &&
            relativePosition.y + sprite.height - sprite.origin.y > 0.5 &&
            relativePosition.x - sprite.origin.x < WINDOW_WIDTH - 0.5 &&
            relativePosition.y - sprite.origin.y < WINDOW_HEIGHT - 0.5);
}

void Object::Draw() {
    if (!sprite.image) return;

    //if (!BoundingBoxInCamera()) return;
    int relativeX = Round(relativePosition.x);
    int relativeY = Round(relativePosition.y);
    int cutoutLeft = Clamp(sprite.origin.x - relativeX, 0, sprite.width);
    int cutoutRight = Clamp(relativeX + sprite.width - sprite.origin.x - WINDOW_WIDTH, 0, sprite.width);
    int cutoutTop = Clamp(sprite.origin.y - relativeY, 0, sprite.height);
    int cutoutBottom = Clamp(relativeY + sprite.height - sprite.origin.y - WINDOW_HEIGHT, 0, sprite.height);

    int pixel = cutoutTop * sprite.width + cutoutLeft;
    int location = BufferLocation(relativeX - sprite.origin.x + cutoutLeft, relativeY - sprite.origin.y + cutoutTop);

    for (int i = 0; i < sprite.height - cutoutBottom - cutoutTop; i++) {
        for (int j = 0; j < sprite.width - cutoutLeft - cutoutRight; j++) {
            activeBuffer[location] = sprite.image[pixel];
            pixel++;
            location++;
        }
        pixel += cutoutLeft + cutoutRight;
        location += WINDOW_WIDTH - sprite.width + cutoutLeft + cutoutRight; // New line on screen
    }

    return;
}

void Object::DrawAll() {
    for (auto object : objects)
        object->Draw();
}

void Object::UpdateAll(double& deltaTime) {
    for (auto object : objects)
        object->Update(deltaTime);
}