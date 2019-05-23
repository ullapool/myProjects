#ifndef GAMEAREA_H
#define GAMEAREA_H
#include "gameobject.h"
#include "player.h"
#include "shoot.h"
#include "obstacle.h"
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
    //QVector<Player*> getPlayer() const;
public slots:
    void next();

protected:
    void gameFinished();

private:
    //QVector<Player *> player;
    QVector<GameObject*> gameObject;
    QImage *background;


};

#endif // GAMEAREA_H
