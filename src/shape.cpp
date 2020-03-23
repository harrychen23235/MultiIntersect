#pragma once
#include"shape.h"
using namespace std;
      Shape::Shape(string i_type) {
          mtype = i_type;
      }

      Line::Line() :Shape("L") {
          ma = 0;
          mb = 0;
          mspecial = 0;
      }
      Line::Line(double input1, double input2, int ifspecial) :Shape("L") {
          ma = input1;
          mb = input2;
          mspecial = ifspecial;

      }


      Ray::Ray(double input1, double input2, int ifspecial, double input3, double input4, double input5, double input6) :Line(input1, input2, ifspecial) {
          mtype = "R";
          mx1 = input3;
          my1 = input4;
          bool comparex = input5 > mx1;
          bool comparey = input6 > my1;
          bool samex = abs(mx1 - input5) < EPS;
          bool samey = abs(my1 - input6) < EPS;
          if (samex) {
              if (input6 > my1) direction = -3;
              else direction = -4;
          }
          else if (samey) {
              if (input5 > mx1) direction = -1;
              else direction = -2;
          }
          else if (comparex && comparey)
              direction = 1;
          else if (!comparex && comparey)
              direction = 2;
          else if (!comparex && !comparey)
              direction = 3;
          else if (comparex && !comparey)
              direction = 4;
      }



      Seg::Seg(double input1, double input2, int ifspecial, double input3, double input4, double input5, double input6) :Line(input1, input2, ifspecial) {
          mx1 = input3;
          my1 = input4;
          mx2 = input5;
          my2 = input6;
          mtype = "S";

      }

      Circle::Circle() :Shape("C") {
          mx = 0;
          my = 0;
          mr = 0;
      }
      Circle::Circle(double input1, double input2, double input3) :Shape("C") {
          mx = input1;
          my = input2;
          mr = input3;

      }
       bool Circle::C2DisJudge(Circle* input1, Circle* input2) {//圆和圆是否相交
          double distance = (input1->mx - input2->mx) * (input1->mx - input2->mx) + (input1->my - input2->my) * (input1->my - input2->my);
          double radium1 = (input1->mr + input2->mr) * (input1->mr + input2->mr);
          double radium2 = (input1->mr - input2->mr) * (input1->mr - input2->mr);
          return distance - EPS < radium1 && distance + EPS>radium2;
      }
       bool Circle::CLDisJudge(Circle* input1, Line* input2) {//圆和线是否相交
          double A = 0, B = 0, C = 0;
          if (input2->mspecial == 1) {
              A = 1;
              B = 0;
              C = -input2->mb;
          }
          else {
              A = input2->ma;
              B = -1;
              C = input2->mb;
          }
          double temp1 = (A * input1->mx + B * input1->my + C) * (A * input1->mx + B * input1->my + C);
          double temp2 = temp1 / (A * A + B * B);
          return temp2 - EPS < input1->mr * input1->mr;

      }

bool RangeJudge(double input1) {
           return (input1 - EPS) < -100000 || (input1 + EPS) > 100000;
}
Shape* ShapeFactory:: GetShape(string type){
    if (type == "L") {
        double temp1, temp2, temp3, temp4;
        cin >> temp1;
        cin >> temp2;
        cin >> temp3;
        cin >> temp4;
        if (RangeJudge(temp1) || RangeJudge(temp2) || RangeJudge(temp3) || RangeJudge(temp4))
         //   throw string("coordinate out of range");
        if (abs(temp1 - temp3) <= EPS && abs(temp2 - temp4) <= EPS) {
          //  throw string("same point in a line");
        }
        if (temp1 == temp3) return new Line(temp1, 0, 1);
        else return new Line((temp4 - temp2) / (temp3 - temp1), temp2 - (temp4 - temp2) / (temp3 - temp1) * temp1, 0);
    }
    else if (type == "C") {
        double temp1, temp2, temp3;
        cin >> temp1;
        cin >> temp2;
        cin >> temp3;
        if (RangeJudge(temp1) || RangeJudge(temp2))
         //   throw string("coordinate out of range");
        if ( temp3 <= 0 ) {
           // throw string("radius must be greater than 0");
        }
        return new Circle(temp1, temp2, temp3);
    }
    else if (type == "R") {
        double temp1, temp2, temp3, temp4;
        cin >> temp1;
        cin >> temp2;
        cin >> temp3;
        cin >> temp4;
        if (RangeJudge(temp1) || RangeJudge(temp2) || RangeJudge(temp3) || RangeJudge(temp4))
          //  throw string("coordinate out of range");
        if (abs(temp1 - temp3) <= EPS && abs(temp2 - temp4) <= EPS) {
          //  throw string("same point in a line");
        }
        if (temp1 == temp3) return new Ray(temp1, 0, 1, temp1, temp2, temp3, temp4);
        else return new Ray((temp4 - temp2) / (temp3 - temp1), temp2 - (temp4 - temp2) / (temp3 - temp1) * temp1, 0, temp1, temp2, temp3, temp4);
    }
    else if (type == "S") {
        double temp1, temp2, temp3, temp4;
        cin >> temp1;
        cin >> temp2;
        cin >> temp3;
        cin >> temp4;
        if (RangeJudge(temp1) || RangeJudge(temp2) || RangeJudge(temp3) || RangeJudge(temp4))
           // throw string("coordinate out of range");
        if (abs(temp1 - temp3) <= EPS && abs(temp2 - temp4) <= EPS) {
          //  throw string("same point in a line");
        }
        if (temp1 == temp3) return new Seg(temp1, 0, 1, temp1, temp2, temp3, temp4);
        else return new Seg((temp4 - temp2) / (temp3 - temp1), temp2 - (temp4 - temp2) / (temp3 - temp1) * temp1, 0, temp1, temp2, temp3, temp4);
    }
    else {
        //throw"UNKNOWN TYPE";
    }
    return NULL;

}
Shape* ShapeFactory::GetShape(string type, double temp1, double temp2, double temp3, double temp4) {
    if (type == "L" || type == "R" || type == "S") {
        if (abs(temp1 - temp3) <= EPS && abs(temp2 - temp4) <= EPS) {
            //throw string("same point in a line");
        }
        if (RangeJudge(temp1) || RangeJudge(temp2) || RangeJudge(temp3) || RangeJudge(temp4));
           // throw string("coordinate out of range");
    }
    if (type == "C") {
        if (RangeJudge(temp1) || RangeJudge(temp2))
            //throw string("coordinate out of range");
        if ( temp3 <= 0 ) {
           // throw string("radius must be greater than 0");
        }
    }
          if (type == "L") {
              if (temp1 == temp3) return new Line(temp1, 0, 1);
              else return new Line((temp4 - temp2) / (temp3 - temp1), temp2 - (temp4 - temp2) / (temp3 - temp1) * temp1, 0);
          }
          else if (type == "R") {
              if (temp1 == temp3) return new Ray(temp1, 0, 1, temp1, temp2, temp3, temp4);
              else return new Ray((temp4 - temp2) / (temp3 - temp1), temp2 - (temp4 - temp2) / (temp3 - temp1) * temp1, 0, temp1, temp2, temp3, temp4);
          }
          else if (type == "S") {
              if (temp1 == temp3) return new Seg(temp1, 0, 1, temp1, temp2, temp3, temp4);
              else return new Seg((temp4 - temp2) / (temp3 - temp1), temp2 - (temp4 - temp2) / (temp3 - temp1) * temp1, 0, temp1, temp2, temp3, temp4);
          }
          else if (type == "C") {
              return new Circle(temp1, temp2, temp3);
          }
          else {
              throw"UNKNOWN TYPE";
          }
          return NULL;

      }
Shape* ShapeFactory::GetShape(const char* input, int outsource) {
    double inputa, inputb, inputc, inputd;
    char type[100];
    sscanf(input, "%s %lf %lf %lf %lf", type, &inputa, &inputb, &inputc, &inputd);
    string temp = type;
    return ShapeFactory::GetShape(type, inputa, inputb, inputc, inputd);

}
      Point::Point(double input1, double input2) {
          x = input1;
          y = input2;
      }





