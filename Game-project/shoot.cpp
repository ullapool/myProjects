#include "shoot.h"
#include "constants.h"
#include <gamearea.h>
#include <QDebug>

Shoot::Shoot(int x, int y, int speed, int angle) : GameObject (x, y, Constants::imageFolder + Constants::shootImg, 20)
{
    this->speed = speed;
    this->angle = angle;
    this->t = 0;

}

void Shoot::move()
{
   qDebug() <<"shootMove Called" <<endl;
   const double g = 9.81;
   double rad = 3.1415926 / 180 * this->angle;
   int dx = this->speed/3 * cos(rad) * t;
   int dy = this->speed/3 * sin(rad) * t - (g/2) * pow(t, 2);
   this->t += 0.1;
   this->x += dx / 2;
   this->y -= dy / 2;

}
