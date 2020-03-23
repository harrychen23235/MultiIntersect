#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include "form.h"
#include"fileinput.h"
#include"result.h"
#include"mydelete.h"
#include"paint.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT
    Form* newform;
    fileinput*newfile;
    result*newresult;
    mydelete*md;
    paint*mp;
public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_input_clicked();
    void F_INPUT();
    void FILE_INPUT();
    void RESULT();
    void CLEAR();
    void SHOWDELETE();
    void myPaint();
private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
