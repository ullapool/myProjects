#include "gamearea.h"
#include "mainwidget.h"
#include "shoot.h"
#include "obstacle.h"
#include "player.h"
#include "constants.h"
#include "thread.h"
#include <QImage>
#include <QPaintEvent>
#include <QPainter>
#include <QDebug>
#include <QVector>
#include <QThread>

GameArea::GameArea(QWidget *parent) : QWidget(parent)
{
    QImage image(Constants::imageFolder + Constants::bg);
    background = new QImage(image.scaledToWidth(1000));
    Thread *t = new Thread();
    t->start();
    QObject::connect(t, SIGNAL(refresh()), this, SLOT(next()));

}

void GameArea::paintEvent(QPaintEvent *event) {
  //create Background
  QPainter *painter = new QPainter(this);
  painter->drawImage(0, 0, *this->background);


  //create Objects
  for(GameObject *gameObject : this->gameObject) {
      gameObject->paint(painter);
  }


    delete painter;
}

void GameArea::startGame()
{
  Player *player = new Player(20, 350);
  gameObject.push_back(player);

  int w = width();
  int x = rand() % (w / 4) + 3 * w / 4 - 50;
  int y = rand() % (height() - 100 + 50);
  Obstacle *obstacle = new Obstacle(x, y);
  gameObject.push_back(obstacle);

  this->update();
}
void GameArea::shoot(int speed, int angle)
{

    Shoot *s = new Shoot(20, 350, speed, angle);
    gameObject.push_back(s);
    update();

}

void GameArea::next()
{
    for(int i = 0; i < gameObject.size(); i++) {
        GameObject *go = gameObject.at(i);
        go->move();
    }
    update();
}

GameArea::~GameArea()
{

}
