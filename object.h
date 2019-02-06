#ifndef OBJECT_H
#define OBJECT_H

#include "defines.h"
#include "sprite.h"

extern fpoint_t cameraPos;

class Object
{
    private:
        static int currID;
        static std::vector<Object*> objects;
    protected:
        fpoint_t relativePosition = {0, 0};
    public:
        static Sprite dummySprite;
        Object(fpoint_t position = {0, 0}, Sprite& spr = dummySprite, int depth = 0);
        fpoint_t position = {0, 0};
        int id;
        int depth;
        Sprite* sprite;
        virtual void Update(double &deltaTime);
        static void DrawAll();
        static void UpdateAll(double &deltaTime);
        ~Object();

        bool operator<(const Object& a) const {
            return depth < a.depth;
        }
};

#endif