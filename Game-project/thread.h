#ifndef THREAD_H
#define THREAD_H
#include <QThread>
#include <QObject>


class Thread : public QThread
{
    Q_OBJECT
public:
    Thread();
    void run();

signals:
    void refresh();
};

#endif // THREAD_H
