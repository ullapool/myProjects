#ifndef GAMEAREA_H
#define GAMEAREA_H
#include "gameobject.h"
#include "player.h"
#include "shoot.h"
#include "obstacle.h"
#include "collisiondetection.h"
#include <QImage>
#include <QPaintEvent>
#include <QVector>
#include <QObject>
#include <QPaintEvent>

#include <QWidget>


class GameArea : public QWidget
{
    Q_OBJECT

public:
    GameArea(QWidget *parent = 0);
    void paintEvent(QPaintEvent *event);
    ~GameArea();
    void startGame();
    void shoot(int speed, int angle);
    void removeShot();

public slots:
    void next();

signals:
    void gameFinished();
     void shotStatusChanged(bool active);

private:
    Shoot *activeShot;
    CollisionDetection *collisiondetection;
    bool collision;
    QVector<GameObject*> gameObject;
    QImage *background;


};

#endif // GAMEAREA_H
