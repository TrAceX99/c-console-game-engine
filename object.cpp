#include "object.h"

int Object::currID;
std::vector<Object*> Object::objects;

Object::Object(fpoint_t position, Sprite& spr, int depth) :
    position(position), sprite(&spr), depth(depth)
{
    id = currID++;
    objects.push_back(this);
    std::sort(objects.begin(), objects.end(), [](auto a, auto b) { return *a < *b; });
}

Object::~Object() {
    objects.erase(std::remove_if(objects.begin(), objects.end(), [this](const Object* a) { return a == this; }), objects.end());
}

void Object::Update(double& deltaTime) {
    relativePosition = position - cameraPos;
}

void Object::DrawAll() {
    for (auto object : objects)
        object->sprite->Draw(Round(object->relativePosition.x), Round(object->relativePosition.y));
}

void Object::UpdateAll(double& deltaTime) {
    for (auto object : objects)
        object->Update(deltaTime);
}