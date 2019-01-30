#ifndef OBJECT_H
#define OBJECT_H

#include "defines.h"
#include "sprite.h"
#include <vector>

extern wchar_t* activeBuffer;
extern fpoint_t cameraPos;

class Object
{
    private:
        static int currID;
        static std::vector<Object*> objects;
        bool BoundingBoxInCamera();
        void Draw();
    protected:
        fpoint_t relativePosition = {0, 0};
    public:
        Object();
        fpoint_t position = {0, 0};
        int id;
        Sprite sprite;
        virtual void Update(double& deltaTime);
        static void DrawAll();
        static void UpdateAll(double& deltaTime);
};

#endif