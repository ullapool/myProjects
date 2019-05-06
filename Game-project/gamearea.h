#ifndef GAMEAREA_H
#define GAMEAREA_H
#include <QImage>
#include <QPaintEvent>
#include <QVector>
#include <QObject>
#include <QPaintEvent>

#include <QWidget>


class GameArea : public QWidget
{


public:
    GameArea(QWidget *parent = 0);
    void paintEvent(QPaintEvent *event);
    ~GameArea();
    void startGame();
    void shoot(int speed, int angle);
    void next();

protected:
    void gameFinished();
private:


    QImage *background;

};

#endif // GAMEAREA_H
