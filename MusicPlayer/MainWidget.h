#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <QWidget>
#include <QObject>
#include <QPushButton>
#include <QString>
#include <QtMultimedia/QMediaPlayer>



class MainWidget : public QWidget
{
    Q_OBJECT

public:
    MainWidget();
    ~MainWidget();

    //MainWidget(const MainWidget &obj);
    //MainWidget operator=(const MainWidget &obj);

private:
    void createLayout();
    void setupEventHandler();
    QPushButton *buttonLoad;
    QPushButton *buttonPlayStop;
    QMediaPlayer *mPlayer;
    QString file;
    bool playing;

public slots:

    void load();
    void play();
signals:
    void fileSelect (const QString &file);



};

#endif // MAINWIDGET_H
