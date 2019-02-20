#ifndef MAINWIGDGET_H
#define MAINWIGDGET_H
#include <QPushButton>
#include <QLineEdit>
#include <QObject>
#include <QWidget>
#include <qString>

class MainWidget : public QWidget
{
    Q_OBJECT
public:
    MainWidget();

private:

    QPushButton *button1;
    QPushButton *loadFile;
    QLineEdit *input1;
    QString *file;

    void createLayout();
    void setupEventHandler();

public slots:
    void clearTextField();
    void load();
   // void textInput(const QString &);

signals:
    //void getFile(const QString &);



};

#endif // MAINWIGDGET_H
