#include "collisiondetection.h"

CollisionDetection::CollisionDetection() {}

bool CollisionDetection::check(GameObject *go1, GameObject *go2)
{
    int xCenterGo1 = go1->getX() + (go1->width()/2);
    int yCenterGo1 = go1->getY() + (go1->width()/2);

    int xCenterGo2 = go2->getX() + (go2->width()/2);
    int yCenterGo2 = go2->getY() + (go2->width()/2);

    int rGo1 = (go1->height()/2 + go1->width()/2) /2;
       int rGo2 = (go2->height()/2 + go2->width()/2) /2;

       int distX = abs(xCenterGo1 - xCenterGo2);
       int distY = abs(yCenterGo1 - yCenterGo2);
       int dist = sqrt(pow(distX, 2) + pow(distY, 2));

       bool isCollision = dist - rGo1 - rGo2 < 0;

       return isCollision;
}
