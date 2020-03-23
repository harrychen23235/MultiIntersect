#ifndef RESULT_H
#define RESULT_H
#include"intersect.h"
#include"global.h"
#include <QMainWindow>

namespace Ui {
class result;
}

class result : public QMainWindow
{
    Q_OBJECT

public:
    explicit result(QWidget *parent = nullptr);
    ~result();

private:
    Ui::result *ui;
};

#endif // RESULT_H
