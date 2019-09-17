#include "MainWidget.h"
#include <QLabel>
#include <QPushButton>
#include <QGridLayout>
#include <QObject>
#include <QFileDialog>
#include <QDebug>
//#include <QtMultimedia/QMediaPlayer>

MainWidget::MainWidget()
{
    this->createLayout();
    this->mPlayer = new QMediaPlayer();
    this->playing = false;
    this->setupEventHandler();

}


void MainWidget::createLayout()
{
    QLabel *label = new QLabel("Welcome to TomTit's Music Player");
    buttonLoad = new QPushButton("load");
    buttonPlayStop = new QPushButton("Play");

    QGridLayout *layout = new QGridLayout();
    layout->addWidget(label,0,0,1,2);
    layout->addWidget(buttonLoad, 1, 0);
    layout->addWidget(buttonPlayStop, 1,1);




    this->setLayout(layout);
}

void MainWidget::setupEventHandler()
{
    QObject::connect(buttonLoad, SIGNAL(clicked()), this, SLOT(load()));
    QObject::connect(buttonPlayStop, SIGNAL(clicked()), this, SLOT(play()));

}

void MainWidget::load()
{
    QFileDialog dialog(this);
    dialog.setFileMode(QFileDialog::ExistingFiles);
    dialog.setNameFilter(tr("MP3 (*.mp3)")); //set pre File Type
    if(dialog.exec()){
        this->file = dialog.selectedFiles()[0];
        qDebug() <<"selected: " <<this->file;
        mPlayer->setMedia(QUrl::fromLocalFile(this->file));
        emit fileSelect(this->file);
    }
}

void MainWidget::play()
{
    if(!this->playing){
        this->buttonPlayStop->setText("Stop");
        this->mPlayer->play();
    }
    else{
        this->buttonPlayStop->setText("Play");
        this->mPlayer->stop();
    }
    this->playing = !this->playing;
}

MainWidget::~MainWidget()
{

}

