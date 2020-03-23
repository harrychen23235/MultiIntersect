#include "fileinput.h"
#include "ui_fileinput.h"
#include "global.h"
fileinput::fileinput(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::fileinput)
{
    ui->setupUi(this);
    connect(ui->confirm, SIGNAL(clicked()), this, SLOT(handout()));
    ui->lineEdit->setText("enter your file name here");
}

fileinput::~fileinput()
{
    delete ui;
}
void fileinput::handout(){

    std::string str=ui->lineEdit->text().toStdString();
    const char*  ch=str.c_str();
    freopen(ch,"r",stdin);
    File_InputProcess();
    fclose(stdin);
    ui->lineEdit->setText("successful input from file");

}
