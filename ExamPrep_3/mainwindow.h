#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QObject>

#include <QMainWindow>
#include <mainwidget.h>

class MainWindow : public QMainWindow
{
    Q_OBJECT

private:
    void createLayout();
    MainWidget *widget;

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();
};

#endif // MAINWINDOW_H
