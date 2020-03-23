#pragma once
#ifndef INTERSECT_H
#define INTERSECT_H

#include <iostream>
#include <vector>
#include<unordered_set>
#include<math.h>
#include <ctime>
#include<fstream>
#include"shape.h"

using namespace std;
extern vector <Shape*> myallshape;
extern unordered_set<Point*, Hash_Point, Equal_Point> myallpoint;
void Add_Diagram(char* input1, int ifoutsource);
void Sub_Diagram(char* input2, int ifoutsource);
void File_InputProcess();
void Clear();
void Calculate();
void InputProcess(vector <Shape*>& g_allshape);
void L2L_Special(Line* input1, Line* input2, int ifspecial, unordered_set<Point*, Hash_Point, Equal_Point>& g_allpoint);
bool Ray_Process(double x, double y, Ray* input1);
bool Seg_Process(double x, double y, Seg* input1);
bool Line_Process(Line* input1, double x, double y);
int DirectionGet(double rootx, double rooty, double assistx, double assisty);
void L2L(Line* input1, Line* input2, unordered_set<Point*, Hash_Point, Equal_Point>& g_allpoint);
void C2C(Circle* input1, Circle* input2, unordered_set<Point*, Hash_Point, Equal_Point>& g_allpoint);
void C2L(Circle* input1, Line* input2, unordered_set<Point*, Hash_Point, Equal_Point>& g_allpoint);
void GetPoint(vector <Shape*>& g_allshape, unordered_set<Point*, Hash_Point, Equal_Point>& g_allpoint);

#endif // !INTERSECT_H

