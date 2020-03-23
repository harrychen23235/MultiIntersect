#ifndef MYDELETE_H
#define MYDELETE_H
#include"intersect.h"
#include"global.h"
#include <QMainWindow>

namespace Ui {
class mydelete;
}

class mydelete : public QMainWindow
{
    Q_OBJECT

public:
    explicit mydelete(QWidget *parent = nullptr);
    ~mydelete();

private:
    Ui::mydelete *ui;
private slots:
 void delete_this();
};

#endif // MYDELETE_H
