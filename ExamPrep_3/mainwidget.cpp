#include "mainwidget.h"
#include <QPushButton>
#include <QLineEdit>
#include <QObject>
#include <QBoxLayout>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QFileDialog>
#include <QString>

MainWidget::MainWidget()
{
    this->createLayout();
    this->setupEventHandler();

}

void MainWidget::createLayout()
{
    button1 = new QPushButton("Press Me");
    loadFile = new QPushButton("load");
    input1 = new QLineEdit();
    input1->setPlaceholderText("Enter your Text here");

    QHBoxLayout *hlayout = new QHBoxLayout();
    hlayout->addWidget(button1);
    hlayout->addWidget(input1);
    QVBoxLayout *vLayout = new QVBoxLayout();
    vLayout->addWidget(loadFile);

    QVBoxLayout *MainLayout = new QVBoxLayout;
    MainLayout->addLayout(hlayout);
    MainLayout->addLayout(vLayout);


    this->setLayout(MainLayout);


}

void MainWidget::setupEventHandler()
{
    QObject::connect(button1,SIGNAL(clicked()), this,SLOT(clearTextField()));
    QObject::connect(loadFile, SIGNAL(clicked()), this, SLOT(load()));
   // QObject::connect(this, SIGNAL(getFile(const QString &)), this, SLOT(textInput(const QString &)));
}

void MainWidget::clearTextField()
{
    this->input1->clear();
}


void MainWidget::load()
{

    QFileDialog dialog(this);
    dialog.setFileMode(QFileDialog::AnyFile);
    if(dialog.exec()){
        this->input1 = dialog.selectFile();


    }
}

