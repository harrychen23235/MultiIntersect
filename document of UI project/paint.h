#ifndef PAINT_H
#define PAINT_H
#include"intersect.h"
#include"global.h"
#include <QWidget>
#include "qcustomplot.h"
namespace Ui {
class paint;
}

class paint : public QWidget
{
    Q_OBJECT

public:
    void paintLine(QCustomPlot *customPlot, double x1, double y1, double x2, double y2);
    void paintRay(QCustomPlot *customPlot, double x1, double y1, double x2, double y2);
    void paintSegment(QCustomPlot *customPlot, double x1, double y1, double x2, double y2);
    void paintCircle(QCustomPlot *customPlot, double x1, double y1, double x2, double y2);
    explicit paint(QWidget *parent = nullptr);
    ~paint();
protected:void paintEvent(QPaintEvent *);
private:
    Ui::paint *ui;

};


#endif
