#ifndef CREDITCARD_H
#define CREDITCARD_H

#include<QString>

class CreditCard
{
private:
    // input values
    QString number;
    QString month;
    int year;

    // output values
    bool validationStatus;
    QString type;

public:
    void setNumber(QString number);
    QString getNumber();
    QString getMonth() const;
    void setMonth(QString value);
    int getYear() const;
    void setYear(int value);
    QString getType() const;
    void setType(const QString &value);
    int getValidationStatus() const;
    void setValidationStatus(bool value);
    bool validate();
};



#endif // CREDITCARD_H
