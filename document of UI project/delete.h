#ifndef DELETE_H
#define DELETE_H

#include <QMainWindow>

namespace Ui {
class delete;
delete
}

class delete : public QMainWindow
{
    Q_OBJECT

public:
    explicit delete(QWidget *parent = nullptr);
    ~delete();

private:
    Ui::delete *ui;
};

#endif // DELETE_H
