#ifndef MAINWIDGET_H
#define MAINWIDGET_H
#include <QSlider>
#include <QPushButton>
#include <QLineEdit>


#include <QWidget>
class GameArea;


class MainWidget : public QWidget
{


public:
    MainWidget(QWidget *parent = 0);
    ~MainWidget();
    void createLayout();
    void createObjects();


private:
    QSlider *angelSlider;
    QSlider * speedSlider;
    QPushButton *actionButton;
    QLineEdit *speedInput;
    QLineEdit *angelInput;
    GameArea *gamearea;

public slots:
    void speedSliderMoved(int value);
    void angleSliderMoved(int value);
    void actionButtonClicked();
    //void onGameFinished();


};

#endif // MAINWIDGET_H
