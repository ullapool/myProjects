#include "gameobject.h"
#include "constants.h"
#include <QImage>
#include <QDebug>

int GameObject::getX()
{
    return x;
}
void GameObject::setX(int value)
{
    x = value;
}

int GameObject::getY()
{
    return y;
}
void GameObject::setY(int value)
{
    y = value;
}
int GameObject::width()
{
  return this->img->width();
}

int GameObject::height()
{
  return this->img->height();
}
GameObject::GameObject() {}
GameObject::GameObject(int x, int y, QString imgPath, int width)
{

   QImage getImg(imgPath);
   this->img = new QImage(getImg.scaledToWidth(width));

   this->setX(x);
   this->setY(y);
}

void GameObject::paint(QPainter *painter)
{
    painter->drawImage(this->x, this->y, *this->img);
}


void GameObject::move()
{

}
