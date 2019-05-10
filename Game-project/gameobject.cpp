#include "gameobject.h"
#include "constants.h"
#include <QImage>

GameObject::GameObject(int x, int y, QString imgPath, int width)
{
   x = 100;
   y = 150;
   this->img = new QImage(imgPath);
   img->scaledToWidth(width);
}

void GameObject::paint(QPainter *painter)
{

    painter->drawImage(this->x, this->y, *img);
}


void GameObject::move()
{

}
