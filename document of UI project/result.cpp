#include "result.h"
#include "ui_result.h"
#include <QStringListModel>
#include <QStandardItemModel>
result::result(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::result)
{
    ui->setupUi(this);
    myallpoint.clear();
    Calculate();
   QStandardItemModel* ItemModel = new QStandardItemModel(this);
    int result=myallpoint.size();
    QString string = QString::number(result);
      QStandardItem *item = new QStandardItem(string);
      ItemModel->appendRow(item);
      ui->listView->setModel(ItemModel);
     //ui->listView->setFixedSize(600,600);
}

result::~result()
{
    delete ui;
}
