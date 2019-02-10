#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <QWidget>
#include "eventhandler.h"
#include "creditcard.h"


class QComboBox;
class QLineEdit;
class QPushButton;

class MainWidget : public QWidget
{
    Q_OBJECT

public:
    MainWidget();
    ~MainWidget();

public slots:
    void getDate(CreditCard& );
    void onResultUpdate(CreditCard& );
    void onClearButtonClicked();

private:
    MainWidget(const MainWidget & obj);
    MainWidget operator=(const MainWidget & obj);


    void createLayout();
    void setDefaultValues();
    void setupEventHandling();
    QString getCreditCardNumber();

    QComboBox *monthBox;
    QComboBox *yearBox;

    QPushButton *checkButton;
    QPushButton *clearButton;
    QLineEdit **blockInput;
};

#endif // MAINWIDGET_H
