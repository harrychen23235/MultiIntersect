#include "paint.h"
#include "ui_paint.h"
#include"qpainter.h"
paint::paint(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::paint)
{
    ui->setupUi(this);

}

paint::~paint()
{
    delete ui;
}
void paint::paintLine(QCustomPlot *customPlot, double x1, double y1, double x2, double y2){
    QCPItemStraightLine *line = new QCPItemStraightLine(customPlot);
    line->point1->setType(QCPItemPosition::PositionType::ptPlotCoords);
    line->point2->setType(QCPItemPosition::PositionType::ptPlotCoords);
    line->point1->setCoords(x1,y1);
    line->point2->setCoords(x2,y2);
}
void paint::paintRay(QCustomPlot *customPlot, double x1, double y1, double x2, double y2){
    QCPItemLine *ray = new QCPItemLine(customPlot);
    ray->setHead(QCPLineEnding::esFlatArrow);
    ray->setTail(QCPLineEnding::esBar);
    ray->start->setType(QCPItemPosition::PositionType::ptPlotCoords);
    ray->end->setType(QCPItemPosition::PositionType::ptPlotCoords);
    ray->start->setCoords(x1,y1);
    ray->end->setCoords(x2,y2);
}
void paint::paintSegment(QCustomPlot *customPlot,double x1, double y1, double x2, double y2){
    QCPItemLine *seg = new QCPItemLine(customPlot);
    seg->setHead(QCPLineEnding::esHalfBar);
    seg->setTail(QCPLineEnding::esHalfBar);
    seg->start->setType(QCPItemPosition::PositionType::ptPlotCoords);
    seg->end->setType(QCPItemPosition::PositionType::ptPlotCoords);
    seg->start->setCoords(x1,y1);
    seg->end->setCoords(x2,y2);
}
void paint::paintCircle(QCustomPlot *customPlot,double x1, double y1, double x2, double y2){
    QCPItemEllipse *circle = new  QCPItemEllipse(customPlot);
    circle->topLeft->setType(QCPItemPosition::PositionType::ptPlotCoords);
    circle->bottomRight->setType(QCPItemPosition::PositionType::ptPlotCoords);
    circle->topLeft->setCoords(x1,y1);
    circle->bottomRight->setCoords(x2,y2);
}
void paint::paintEvent(QPaintEvent *){

    QCustomPlot *customPlot = ui->qcustomPlot;
       customPlot->clearItems();
       customPlot->clearGraphs();
       ui->qcustomPlot->addGraph();
       ui->qcustomPlot->graph(0)->setLineStyle(QCPGraph::LineStyle::lsNone);
       ui->qcustomPlot->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom | QCP::iSelectPlottables);
       ui->qcustomPlot->axisRect()->setupFullAxesBox();
       ui->qcustomPlot->rescaleAxes();
       ui->qcustomPlot->xAxis->setRange(-100000,100000);
        ui->qcustomPlot->yAxis->setRange(-100000,100000);
       for (int i = 0 ; i <(int) myallshape.size();i++){
           double x1,y1,x2,y2;
           string type=myallshape.at(i)->mtype;
            if(type=="R"){
           Ray* myray=(Ray*)myallshape.at(i);
           x1= myray->mx1;
           y1 = myray->my1;
           x2 = x1+myray->mx2;
           y2 = y1+ myray->my2;
           paintRay(customPlot,x1,y1,x2,y2);
           }
           else if(type=="S"){
                Seg* myray=(Seg*)myallshape.at(i);
                x1= myray->mx1;
                y1 = myray->my1;
                x2 = x1+myray->mx2;
                y2 = y1+ myray->my2;
                paintSegment(customPlot,x1,y1,x2,y2);
            }
            else if(type=="L"){
                 Line* myline=(Line*)myallshape.at(i);
                  if(myline->mspecial==0){
                      x1=1;
                      y1=myline->ma+myline->mb;
                      x2=2;
                      y2=2*myline->ma+myline->mb;
                      paintLine(customPlot,x1,y1,x2,y2);
                  }
                  if(myline->mspecial==1){
                      x1=myline->ma;
                      y1=1;
                      x2=myline->ma;
                      y2=2;
                      paintLine(customPlot,x1,y1,x2,y2);
                  }
            }
                  else if(type=="C"){
                   Circle* mycircle=(Circle*)myallshape.at(i);
                   x1=mycircle->mx;
                   y1=mycircle->my;
                   x2=mycircle->mr;
                   paintCircle(customPlot,x1-x2,y1+x2,x1+x2,y1-y2);
                  }


           if (i%5 == 0)   customPlot->replot();
       }

       customPlot->replot();

}
