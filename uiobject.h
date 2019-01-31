#include "object.h"

class UIObject : public Object
{
    using Object::Object;
    public:
        void Update(double &deltaTime);
};