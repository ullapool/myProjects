#include "mainwindow.h"
#include "mainwidget.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{

    MainWidget *mw = new MainWidget();
    setCentralWidget(mw);
    setFixedSize(900,650);


}

MainWindow::~MainWindow()
{

}
