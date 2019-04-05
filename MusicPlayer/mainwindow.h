#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <MainWidget.h>


class MainWindow : public QMainWindow
{
  Q_OBJECT

private:
    MainWidget *widget;
    QStatusBar *statusBar;

    void createLayout();
    void setupEventHandler();
public:
    MainWindow(QWidget *parent = 0);

    ~MainWindow();

public slots:
    void updateStatusBar(const QString&);
};

#endif // MAINWINDOW_H
