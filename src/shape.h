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
      int mspecial;//����ֱ��mspecial=0,��ֱ��X���ֱ��mspecial=1,maΪX���Ӧֵ
      Line();
      Line(double input1, double input2, int ifspecial);
};
class Ray :public Line {
public:double mx1, my1, mx2, my2;
    int direction;//1,2,3,4��ʾ�ӳ���������λ��,-1��ʾ��x������������,-2,��ʾ��x�Ḻ��������,-3��ʾ��y������������,-4��ʾ��y�Ḻ��������
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
      static bool C2DisJudge(Circle* input1, Circle* input2);//Բ��Բ�Ƿ��ཻ
      static bool CLDisJudge(Circle* input1, Line* input2);//Բ�����Ƿ��ཻ

};
class ShapeFactory {//����ģʽ����
public:static Shape* GetShape(string type);
      static Shape* GetShape(string type, double temp1, double temp2, double temp3, double temp4);
      static Shape* GetShape(const char* input1, int outsource);
};
class Point {
public:double x, y;
      Point(double input1, double input2);

};

struct Hash_Point {
    size_t operator()(const class Point* input1)const {
        //return (int)(((int)input1.x) * 1e6 / 10 + ((int)input1.y) * 1e6 / 10);
        double x = input1->x;
        double y = input1->y;
        long temp1 = (long)floor(x);
        long temp2 =(long) floor(y);
        if (abs(x - ((long long)temp1+1)) <= EPS) temp1++;
        if (abs(y- ((long long)temp2+1)) <= EPS) temp2++;
        std::hash<long> long_hash;
        return long_hash.operator()(temp1)+ long_hash.operator()(temp2);
        
    }
};

struct Equal_Point {
    bool operator()(const class Point* input1, const class Point* input2)const {
        return abs(input1->x - input2->x) <= EPS && abs(input1->y - input2->y) <= EPS;
    }
};

#endif 

