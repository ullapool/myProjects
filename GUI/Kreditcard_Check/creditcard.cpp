//#include "mainwidget.h"
//#include "mainwindow.h"
#include <QDebug>


#include "creditcard.h"

QString CreditCard::getMonth() const
{
    return month;
}

void CreditCard::setMonth(QString value)
{
    month = value;
}

int CreditCard::getYear() const
{
    return year;
}

void CreditCard::setYear(int value)
{
    year = value;
}

int CreditCard::getValidationStatus() const
{
    return validationStatus;
}

void CreditCard::setValidationStatus(bool value)
{
    validationStatus = value;
}

void CreditCard::setNumber(QString value)
{
    number = value;
}

QString CreditCard::getNumber()
{
    return number;
}

bool CreditCard::validate()
{
    qDebug() <<"number[0] = "<<number.at(0);

    if(number.size() != 16 && number.at(0) != 5)return false;
    //|| number[0] != 5
       qDebug() <<"size check ok";
    int sum = 0;
    bool check = false;

    for(int i = number.size()-1; i >= 0; i--){
        int digit = number.at(i).digitValue();

        if(check == true){
            digit = digit * 2;
            if(digit > 9)
                digit = digit - 9;

            sum += digit;

        }
        check = !check;

    }
    qDebug() <<"Sum: "<<sum;
    bool result = sum % 10 == 0;
    qDebug() <<"Result: "<<result;
    setValidationStatus(result);
    return result;

}
