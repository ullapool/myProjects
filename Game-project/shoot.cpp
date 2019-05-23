#include "shoot.h"
#include "constants.h"
#include <QDebug>

Shoot::Shoot(int x, int y, int speed, int angle) : GameObject (x, y, Constants::imageFolder + Constants::shootImg, 20)
{

}

void Shoot::move()
{
   qDebug() <<"shootMove Called" <<endl;
  this->x = x + 3;
}
