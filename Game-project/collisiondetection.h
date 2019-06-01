#ifndef COLLISIONDETECTION_H
#define COLLISIONDETECTION_H

#include <gameobject.h>

class CollisionDetection
{
public:
    CollisionDetection();
    static bool check(GameObject *go1, GameObject *go2);
};

#endif // COLLISIONDETECTION_H
