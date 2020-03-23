#ifndef FORM_H
#define FORM_H
#include "intersect.h"

#include <QWidget>

namespace Ui {
class Form;
}

class Form : public QWidget
{
    Q_OBJECT

public:
    explicit Form(QWidget *parent = nullptr);
    ~Form();

private:
    Ui::Form *ui;
    private slots:
     void hand_out();
};

#endif // FORM_H
