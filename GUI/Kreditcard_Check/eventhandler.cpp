#include "mainwidget.h"
#include "mainwindow.h"
#include "eventhandler.h"
#include <QMessageBox>


void EventHandler:: onCheckButtonClicked()
{

    qDebug() <<"check button has been clicked";
    CreditCard cc;



//    if(num.size() < 14){
//        QMessageBox::information(nullptr, "CC-Checker", "Invalid Card");

//    }
    qDebug() <<"Model memory address: " <<&cc;

    emit retreiveGuiData(cc);
    qDebug() <<cc.getNumber();
    cc.validate();
    //cc.setValidationStatus(1);


    emit updateResult(cc);


}


