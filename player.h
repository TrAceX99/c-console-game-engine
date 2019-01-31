#include "object.h"

#define SPEED 10

class Player : public Object
{
    using Object::Object;
    public:
        void Update(double& deltaTime);
};