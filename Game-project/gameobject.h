#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H
#include <QString>
#include <QPainter>
#include <QImage>
#include <QWidget>


class GameObject //: public QWidget
{

public:
    GameObject();
    GameObject(int x, int y, QString imgPath, int width);
    virtual void move() = 0;
    virtual void paint(QPainter *painter);
    virtual int getY();
    virtual void setY(int value);
    virtual int getX();
    virtual void setX(int value);
    virtual int width();
    virtual int height();

protected:
    QImage *img;
    int x;
    int y;

private:


};

#endif // GAMEOBJECT_H
