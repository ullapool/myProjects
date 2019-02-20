#include "mainwindow.h"
#include "mainwidget.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    this->createLayout();

}

void MainWindow::createLayout()
{
    this->setWindowTitle("My Widget");
    this->setFixedSize(500, 200);

    this->widget = new MainWidget();
    this->setCentralWidget(widget);



}

MainWindow::~MainWindow()
{

}
