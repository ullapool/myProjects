#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H
#include <QString>
#include <QPainter>

#include <QWidget>


class GameObject : public QWidget
{
    Q_OBJECT

public:
    GameObject(int x, int y, QString imgPath, int width);
    virtual void move();
    void paint(QPainter *painter);
    int getY();
    void setY(int value);
    int getX();
    void setX(int value);
    int width();
    int height();

protected:
    int x;
    int y;

private:
    QImage *img;

};

#endif // GAMEOBJECT_H
