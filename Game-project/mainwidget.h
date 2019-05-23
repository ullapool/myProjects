#ifndef MAINWIDGET_H
#define MAINWIDGET_H
#include <QSlider>
#include <QPushButton>
#include <QLineEdit>
#include <QWidget>

class GameArea;

class MainWidget : public QWidget
{
   Q_OBJECT

public:
    MainWidget(QWidget *parent = 0);
    ~MainWidget();
    int shootCounter = 0;

private:
    QSlider *angelSlider;
    QLineEdit *numberOfShootInput;
    QSlider * speedSlider;
    QPushButton *actionButton;
    QLineEdit *speedInput;
    QLineEdit *angleInput;
    GameArea *gamearea;

    void createLayout();
    void createObjects();
    void connectObjects();

public slots:
    void speedSliderMoved(int value);
    void angleSliderMoved(int value);
    void actionButtonClicked();
    //void onGameFinished();


};

#endif // MAINWIDGET_H
