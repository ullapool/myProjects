#include "mainwidget.h"
#include "gamearea.h"
#include "player.h"
#include "obstacle.h"
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QLabel>
#include <QSlider>
#include <QString>
#include <QDebug>
#include <QMessageBox>
#include <QApplication>

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
    connect(actionButton, SIGNAL(clicked()), this, SLOT(actionButtonClicked() ));
    QObject::connect(gamearea, SIGNAL(gameFinished()),this, SLOT(onGameFinished() ) );
    //connect(this->gamearea, &GameArea::shotStatusChanged, this->actionButton, &QPushButton::setDisabled );
}

void MainWidget::speedSliderMoved(int value)
{
   this->speedInput->setText(QString::number(value));



}

void MainWidget::angleSliderMoved(int value)
{
    this->angleInput->setText(QString::number(value));

}



void MainWidget::actionButtonClicked()
{
    if(this->actionButton->text() == "Start"){
    this->actionButton->setText("Shoot");
    this->gamearea->startGame();
    this->numberOfShootInput->setText("0");
    }
    else{
    this->numberOfShootInput->setText(QString::number(shootCounter + 1));
    shootCounter++;
    this->gamearea->shoot(speedSlider->value(), angelSlider->value());
    }


}

void MainWidget::onGameFinished()
{
    qDebug() <<"onGameFinished called" <<endl;
    QString score = numberOfShootInput->text();
    const QString finalScore = "It took you " + score + "!";
    messageBox = QMessageBox::question(this, finalScore, "Wanna play again?", QMessageBox::Yes | QMessageBox::No);

    if(messageBox == QMessageBox::Yes) {

    gamearea->startGame();
     actionButton->setText("Start");

    }
}

MainWidget::~MainWidget()
{

}
