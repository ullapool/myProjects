#ifndef EVENTHANDLER_H
#define EVENTHANDLER_H

#include <QDebug>
#include <QObject>


class Eventhandler : public QObject
{

    Q_OBJECT
public slots:

    void onButtonClicked();

signals:

};

#endif // EVENTHANDLER_H
