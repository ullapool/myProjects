#include "mainwindow.h"
#include "mainwidget.h"
#include <QStatusBar>
#include <QMenuBar>
#include <QMenu>
#include <QAction>

MainWindow::MainWindow()
{
    mainWidget = new MainWidget();
    this->setCentralWidget(mainWidget);
    QMenuBar *menuBar = this->menuBar();
    QMenu *fileMenu = new QMenu("File");
    QMenu *aboutMenu = new QMenu("about");
    QAction *clearAction = fileMenu->addAction("Clear");
    QAction *exitAction = fileMenu->addAction("Exit");
    QObject::connect(clearAction, SIGNAL(triggered()), mainWidget,SLOT(onClearButtonClicked()));

    menuBar->addMenu(fileMenu);



    statusBar()->showMessage("Welcome to secure pay  -  By TomTiT.corp");
}

MainWindow::~MainWindow()
{
    delete mainWidget;
}
