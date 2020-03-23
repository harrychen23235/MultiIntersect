#pragma once
#ifndef SHAPE_H
#define SHAPE_H
#include <iostream>
#include<math.h>
#include<fstream>
#include<functional>
using namespace std;

const double EPS = 1e-6;
bool RangeJudge(double input1);
class Shape {
public:string mtype;
      Shape(string i_type);
};
class Line :public Shape {
public:double ma, mb;
      int mspecial;//常规直线mspecial=0,垂直于X轴的直线mspecial=1,ma为X轴对应值
      Line();
      Line(double input1, double input2, int ifspecial);
};
class Ray :public Line {
public:double mx1, my1, mx2, my2;
    int direction;//1,2,3,4表示延长到的象限位置,-1表示朝x轴正方向延伸,-2,表示朝x轴负方向延伸,-3表示向y轴正方向延伸,-4表示向y轴负方向延伸
    Ray(double input1, double input2, int ifspecial, double input3, double input4, double input5, double input6);
};
class Seg :public Line {
public:double  mx2, my2, mx1, my1;
      Seg(double input1, double input2, int ifspecial, double input3, double input4, double input5, double input6);
};
class Circle :public Shape {
public:double mx, my, mr;
      Circle();
      Circle(double input1, double input2, double input3);
      static bool C2DisJudge(Circle* input1, Circle* input2);//圆和圆是否相交
      static bool CLDisJudge(Circle* input1, Line* input2);//圆和线是否相交

};
class ShapeFactory {//工厂模式处理
public:static Shape* GetShape(string type);
      static Shape* GetShape(string type, double temp1, double temp2, double temp3, double temp4);
      static Shape* GetShape(const char* input1, int outsource);
};
class Point {
public:double x, y;
      Point(double input1, double input2);

};

struct Hash_Point {
    size_t operator()(const class Point* input1)const;
};

struct Equal_Point {
    bool operator()(const class Point* input1, const class Point* input2)const;
};

#endif

