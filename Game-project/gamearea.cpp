#include "gamearea.h"
#include "mainwidget.h"
#include <QImage>
#include <QPaintEvent>
#include <QPainter>
#include <QDebug>
#include <QVector>

GameArea::GameArea(QWidget *parent)
{
    QImage image("C:\\SynologyDrive\\GUI\\the_game\\images\\background.jpg");
    background = new QImage(image.scaledToWidth(1000));


}
void GameArea::paintEvent(QPaintEvent *event) {
  //create Background
  QPainter *painter = new QPainter(this);
  painter->drawImage(0, 0, *background);

  //create Objects
  for(GameObject *gameObject : this->gameObject) {
      gameObject->paint(painter);
  }


}

GameArea::~GameArea()
{

}
