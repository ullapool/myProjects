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
#include <cmath>
#include <algorithm>
#include "collisiondetection.h"

GameArea::GameArea(QWidget *parent) : QWidget(parent)
{
    //collisiondetection = new CollisionDetection;
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
    //MainWidget *mw = new MainWidget();

    this->activeShot = new Shoot(20, 350, speed, angle);
    gameObject.push_back(activeShot);
    //emit shotStatusChanged(true);
    //update();

}
void GameArea::removeShot()
{
    auto itGameOjects = std::find(gameObject.begin(),gameObject.end(), this->activeShot );
    gameObject.erase(itGameOjects);
    delete this->activeShot;
    this->activeShot = nullptr;
    //emit shotStatusChanged(false);

}

void GameArea::next()
{
    for(int i = 0; i < gameObject.size(); i++) {
        GameObject *go = gameObject.at(i);
        go->move();
    }

    if(gameObject.size() >= 3) {
        if(collisiondetection->check(gameObject.at(1), gameObject.at(gameObject.size() -1)) ) {
            gameObject.clear();
            gameFinished();
        }
    }
    update();


}



GameArea::~GameArea()
{

}
