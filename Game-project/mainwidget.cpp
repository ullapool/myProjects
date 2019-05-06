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
    angelInput = new QLineEdit();
    gamearea = new GameArea(this);
}

void MainWidget::createLayout()
{

   QVBoxLayout *vBox = new QVBoxLayout();
   QLabel *title = new QLabel("<h1>Monkeytastic</h1>");
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
   hBox->addWidget(angelInput);
   vBox->addLayout(hBox);

   this->setLayout(vBox);

}

void MainWidget::connectObjects()
{
    connect(speedSlider, SIGNAL(valueChanged(int)), this, SLOT(speedSliderMoved(int)) );
}

void MainWidget::speedSliderMoved(int value)
{
   qDebug() <<"speedSliderMoved"<<endl;
   QString valueStr = (QString)value;
   this->speedInput = new QLineEdit(valueStr);

}

MainWidget::~MainWidget()
{

}
