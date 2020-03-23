#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    ,ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->quit, SIGNAL(clicked()), this, SLOT(close()));
    connect(ui->input,SIGNAL(clicked()),this,SLOT(F_INPUT()));
    connect(ui->load,SIGNAL(clicked()),this,SLOT(FILE_INPUT()));
    connect(ui->show_result,SIGNAL(clicked()),this,SLOT(RESULT()));
    connect(ui->clear,SIGNAL(clicked()),this,SLOT(CLEAR()));
    connect(ui->delete_2,SIGNAL(clicked()),SLOT(SHOWDELETE()));
    connect(ui->draw,SIGNAL(clicked()),this,SLOT(myPaint()));
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_input_clicked()
{

}
void MainWindow::FILE_INPUT(){
    newfile=new fileinput;
    newfile->show();
}
void MainWindow::F_INPUT(){
    newform=new Form;
    newform->show();
}
void MainWindow::RESULT(){
    newresult=new result;
    newresult->show();
}
void MainWindow::CLEAR(){
    myallpoint.clear();
    myallshape.clear();
}
void MainWindow::SHOWDELETE(){
    md=new mydelete;
    md->show();
}
void MainWindow::myPaint(){
    mp=new paint;
    mp->show();
}
