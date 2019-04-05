#include "mainwindow.h"
#include "MainWidget.h"
#include <QStatusBar>
#include <QString>


MainWindow::MainWindow(QWidget *parent): QMainWindow(parent)
{

  this->createLayout();
  this->setupEventHandler();

}

MainWindow::~MainWindow()
{
    delete widget;
}

void MainWindow::createLayout()
{
    //Layout Window
    this->setWindowTitle("Music Player");
    this->setFixedSize(500, 200);

    //layout Widget
    this->widget = new MainWidget();
    this->setCentralWidget(widget);

    //StatusBar
    this->statusBar = new QStatusBar();
    this->statusBar->showMessage("Press 'load' to load any files");
    this->setStatusBar(statusBar);

}

void MainWindow::setupEventHandler()
{
    //function is in Mainwidget     this is the funct.         //updateSTBar ist from *this class thats why this
    QObject::connect(widget, SIGNAL(fileSelect(const QString&)),this, SLOT(updateStatusBar(const QString& )));
}

void MainWindow::updateStatusBar(const QString &message)
{
    this->statusBar->showMessage(message);
}


