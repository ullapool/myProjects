#include "mainwindow.h"
#include "mainwidget.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{

    MainWidget *mw = new MainWidget();
    setCentralWidget(mw);


}

MainWindow::~MainWindow()
{

}
