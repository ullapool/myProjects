#include <QGridLayout>
#include <QLabel>
#include <QComboBox>
#include <QLineEdit>
#include <QPushButton>
#include <QString>
#include <QDebug>
#include <QPixmap>
#include <QDateTime>
#include <QMessageBox>
#include <QIntValidator>
#include <string>
#include "mainwidget.h"
#include <QMessageBox>
using namespace std;

MainWidget::MainWidget()
{
    createLayout();
    setupEventHandling();
}

MainWidget::~MainWidget() {
}

void MainWidget::createLayout()
{
    QPixmap icon("creditcards.png");
    QLabel *iconLabel;
    if (icon.isNull()) {
        iconLabel = new QLabel("icon not found!");
    } else {
        iconLabel = new QLabel();
        iconLabel->setPixmap(icon.scaledToHeight(100));
    }


    QLabel *titleLabel = new QLabel("<H1>Credit Card Checker</H1>");


    //Validator
    auto val = new QIntValidator();
    val->setRange(0, 9999);
    blockInput = new QLineEdit*[4];
    for (int i = 0; i < 4; i++){
         blockInput[i] = new QLineEdit();
         blockInput[i]->setMaxLength(4);
         blockInput[i]->setValidator(val);
    }
    monthBox = new QComboBox();
    yearBox = new QComboBox();
    checkButton = new QPushButton("Check");
    clearButton = new QPushButton("Clear");

    this->setDefaultValues();



    // create layout
    QGridLayout *layout = new QGridLayout();
    layout->addWidget(titleLabel, 0, 0, 1, 3);
    layout->addWidget(iconLabel, 0, 3);

    for (int i = 0; i < 4; i++){
         layout->addWidget(blockInput[i], 1, i);
    }
    layout->addWidget(new QLabel("Month"), 2, 0);
    layout->addWidget(monthBox, 2, 1);
    layout->addWidget(new QLabel("Year"), 2, 2);
    layout->addWidget(yearBox, 2, 3);
    layout->addWidget(checkButton, 3, 0, 1, 2);
    layout->addWidget(clearButton, 3, 2, 1, 2);


    // set layout
    this->setLayout(layout);
}

void MainWidget::setDefaultValues()
{
    for(int i = 0; i < 4; i++){
        blockInput[i]->setPlaceholderText("");
    }
    QString monthNames [] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Okt", "Nov", "Dez"};
    for (QString mName : monthNames) {
        monthBox->addItem(mName);
    }

    // for the year, take the current year and add the next 10 years
    QDateTime currentDate = QDateTime::currentDateTime();
    int currentYear = currentDate.date().year();
    const int NUMBER_OF_YEARS = 10;
    for (int i=0; i<NUMBER_OF_YEARS; i++) {
        QString year = QString::number(currentYear + i);
        yearBox->addItem(year);
    }
}

void MainWidget::setupEventHandling()
{
    EventHandler *handler = new EventHandler();
    QObject::connect(checkButton, SIGNAL(clicked(bool) ), handler, SLOT(onCheckButtonClicked()));
    QObject::connect(handler, SIGNAL(retreiveGuiData(CreditCard&) ),this, SLOT(getDate(CreditCard& ) ));
    QObject::connect(handler, SIGNAL(updateResult(CreditCard& )),this, SLOT(onResultUpdate(CreditCard& ) ));
    QObject::connect(clearButton, SIGNAL(clicked() ), this, SLOT(onClearButtonClicked() ));
}

void MainWidget:: onResultUpdate(CreditCard& cc )
{

    qDebug() <<"Credit Card reslut is: "<<cc.getValidationStatus();
    //QString color = (cc.getValidationStatus()) ? "red" : "green";
    cc.getValidationStatus() ?
                QMessageBox::information(nullptr, "Mastercard Validator", "It's a valid Mastercard"):
                QMessageBox::warning(nullptr, "Mastercard Validator", "Not a Mastercard");


    for(int i = 0; i < 4; i++){
        cc.getValidationStatus() ?
        this->blockInput[i]->setStyleSheet("border: 2px solid; border-color: green;"):
        this->blockInput[i]->setStyleSheet("border: 2px solid; border-color: red;");

        cc.getValidationStatus() ?
        this->checkButton->setStyleSheet("color: green;"):
        this->checkButton->setStyleSheet("color: red;");

    }
}

QString MainWidget::getCreditCardNumber()
{
    QString number;
    for(int i = 0; i < 4; i++){
        number += this->blockInput[i]->displayText();

    }
    return number;
}
void MainWidget:: getDate(CreditCard& cc )
{
    qDebug() <<"getData was called with cc object (address): " <<&cc;
    cc.setNumber(this->getCreditCardNumber());
    cc.setMonth(monthBox->currentText());
    cc.setYear(yearBox->currentText().toInt());
}

void MainWidget::onClearButtonClicked()
{
    for(int i = 0; i < 4; i++){
        this->blockInput[i]->clear();
        this->blockInput[i]->setStyleSheet("");

    }
    checkButton->setStyleSheet("");
    monthBox->setCurrentIndex(0);
    yearBox->setCurrentIndex(0);
}



