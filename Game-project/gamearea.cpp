#include "gamearea.h"
#include "mainwidget.h"
#include <QImage>
#include <QPaintEvent>
#include <QPainter>
#include <QDebug>

GameArea::GameArea(QWidget *parent)
{
    qDebug() << " ga-const. called"<<endl;
    QImage image("C:\\SynologyDrive\\GUI\\the_game\\images\\background.jpg");
    background = new QImage(image.scaledToWidth(1000));



}
void GameArea::paintEvent(QPaintEvent *event)
{
    qDebug() << " pe-funct. called"<<endl;
  QPainter painter(this);
  painter.drawImage(0, 0, *background);
}

GameArea::~GameArea()
{

}
