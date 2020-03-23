#ifndef FILEINPUT_H
#define FILEINPUT_H

#include <QMainWindow>
#include"intersect.h"
namespace Ui {
class fileinput;
}

class fileinput : public QMainWindow
{
    Q_OBJECT

public:
    explicit fileinput(QWidget *parent = nullptr);
    ~fileinput();

private:
    Ui::fileinput *ui;
    private slots:
    void handout();
};

#endif // FILEINPUT_H
