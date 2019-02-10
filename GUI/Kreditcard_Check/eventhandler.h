#ifndef EVENTHANDLER_H
#define EVENTHANDLER_H

#include <QDebug>
#include <QObject>
#include <QMessageBox>
#include "creditcard.h"

class EventHandler : public QObject
{
    Q_OBJECT

public slots:
    void onCheckButtonClicked();
    //void onClearButtonClicked();

signals:
    void retreiveGuiData(CreditCard& );
    void updateResult(CreditCard& );

};

#endif // EVENTHANDLER_H
