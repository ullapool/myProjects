#include "mainwidget.h"
#include "mainwindow.h"
#include "eventhandler.h"
#include <QMessageBox>


void EventHandler:: onCheckButtonClicked()
{

    qDebug() <<"check button has been clicked";
    CreditCard cc;

    qDebug() <<"Model memory address: " <<&cc;

    emit retreiveGuiData(cc);
    qDebug() <<cc.getNumber();
    cc.validate();
    //manually set Status -->//cc.setValidationStatus(1);


    emit updateResult(cc);


}


