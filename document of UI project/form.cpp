#include "form.h"
#include "ui_form.h"
#include"intersect.h"


//extern vector <Shape*> global::myallshape;
//extern unordered_set<Point*, global::Hash_Point, Equal_Point> myallpoint;
Form::Form(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form)
{
    ui->setupUi(this);
    connect(ui->first_confirm, SIGNAL(clicked()), this, SLOT(hand_out()));
    ui->first_edit->setText("enter your shape here");
}
void Form::hand_out(){
string str=ui->first_edit->text().toStdString();
     const char*  ch=str.c_str();
    Shape*temp=ShapeFactory::GetShape(ch,1);
    if(temp==NULL){
        ui->first_edit->setText("illegal input");
    }
    else{
    Add_Diagram((char*)ch,1);
    ui->first_edit->setText("successful insert");}
    //close();}

}
Form::~Form()
{
    delete ui;
}
