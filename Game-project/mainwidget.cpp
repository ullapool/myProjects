#include "mainwidget.h"
#include "gamearea.h"
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QLabel>
#include <QSlider>
#include <QString>
#include <QDebug>

MainWidget::MainWidget(QWidget *parent) : QWidget (parent)
{
    this->createObjects();
    this->createLayout();
    this->connectObjects();

}

void MainWidget::createObjects()
{
    actionButton = new QPushButton("Start");
    speedSlider = new QSlider(Qt::Horizontal);
    speedSlider->setRange(1, 100);
    speedSlider->setTickInterval(1);
    angelSlider = new QSlider(Qt::Horizontal);
    angelSlider->setRange(0, 90);
    angelSlider->setTickInterval(1);
    numberOfShootInput = new QLineEdit();
    speedInput = new QLineEdit();
    speedInput->setReadOnly(true);
    angleInput = new QLineEdit();
    angleInput->setReadOnly(true);
    gamearea = new GameArea(this);
}

void MainWidget::createLayout()
{

   QVBoxLayout *vBox = new QVBoxLayout();
   QLabel *title = new QLabel("<h1>Take nae monkey shite</h1>");
   vBox->addWidget(title);

   QHBoxLayout *hBox = new QHBoxLayout();

   QLabel *shoot = new QLabel("#Shoot");
   QLabel *speed = new QLabel("Speed");
   QLabel *angle = new QLabel("Angle");

   hBox->addWidget(actionButton);
   vBox->addWidget(gamearea, Qt::AlignCenter);
   hBox->addWidget(shoot);
   hBox->addWidget(numberOfShootInput);
   hBox->addWidget(speed);
   hBox->addWidget(speedSlider);
   hBox->addWidget(speedInput);
   hBox->addWidget(angle);
   hBox->addWidget(angelSlider);
   hBox->addWidget(angleInput);
   vBox->addLayout(hBox);

   this->setLayout(vBox);


}

void MainWidget::connectObjects()
{
    connect(speedSlider, SIGNAL(valueChanged(int)), this, SLOT(speedSliderMoved(int)) );
    connect(angelSlider, SIGNAL(valueChanged(int)), this, SLOT(angleSliderMoved(int)) );
}


void MainWidget::speedSliderMoved(int value)
{
   qDebug() <<"speedSliderMoved"<<endl;
   QString valueStr = QString::number(value); //casting int into string
   this->speedInput->setText(valueStr);

}

void MainWidget::angleSliderMoved(int value)
{
    QString valueStr = QString::number(value);
    this->angleInput->setText(valueStr);
}

MainWidget::~MainWidget()
{

}
