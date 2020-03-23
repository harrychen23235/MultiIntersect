#include "mydelete.h"
#include "ui_mydelete.h"

mydelete::mydelete(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::mydelete)
{
    ui->setupUi(this);
    connect(ui->pushButton, SIGNAL(clicked()), this, SLOT(delete_this()));
    ui->lineEdit->setText("enter your shape here");
}

mydelete::~mydelete()
{
    delete ui;
}
void mydelete::delete_this(){
    string str=ui->lineEdit->text().toStdString();
    const char*  ch=str.c_str();
    Sub_Diagram((char*)ch,1);
   ui->lineEdit->setText("successful delete");
}
