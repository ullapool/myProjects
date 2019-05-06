#include "mainwidget.h"
#include "gamearea.h"
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QLabel>
#include <QSlider>

MainWidget::MainWidget(QWidget *parent) : QWidget (parent)
{
    this->createLayout();
}

void MainWidget::createLayout()
{

   QVBoxLayout *vBox = new QVBoxLayout();
   QLabel *title = new QLabel("<h1>Monkeytastic</h1>");
   vBox->addWidget(title, Qt::AlignTop);

   QHBoxLayout *hBox = new QHBoxLayout();
   actionButton = new QPushButton("Start");
   QLabel *shoot = new QLabel("#Shoot");
   QLabel *speed = new QLabel("Speed");
   QLabel *angle = new QLabel("Angle");
   QLineEdit *shootLine = new QLineEdit();

   speedSlider = new QSlider(Qt::Horizontal);
   speedSlider->setRange(0, 10);
   angelSlider = new QSlider(Qt::Horizontal);
   angelSlider->setRange(0,10);
   speedInput = new QLineEdit();
   angelInput = new QLineEdit();

   gamearea = new GameArea(this);
//   QHBoxLayout *hImage = new QHBoxLayout();
//   hImage->addWidget(gamearea);


   hBox->addWidget(actionButton);
   hBox->addWidget(gamearea);
   hBox->addWidget(shoot);
   hBox->addWidget(shootLine);
   hBox->addWidget(speed);
   hBox->addWidget(speedSlider);
   hBox->addWidget(speedInput);
   hBox->addWidget(angle);
   hBox->addWidget(angelSlider);
   hBox->addWidget(angelInput);
   vBox->addLayout(hBox);
   //vBox->addWidget(gamearea);



   // this->setLayout(hImage);

   this->setLayout(vBox);



}

MainWidget::~MainWidget()
{

}
