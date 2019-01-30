#include "object.h"

#define SPEED 10

class Player : public Object
{
    public:
        Player(double startingX, double startingY);
        void Update(double& deltaTime);
};