#include "object.h"

#define SPEED 10

class Player : public Object
{
    using Object::Object;
    private:
        int direction;
    public:
        void Update(double& deltaTime);
};

class UIObject : public Object
{
    using Object::Object;
    public:
        void Update(double &deltaTime);
};