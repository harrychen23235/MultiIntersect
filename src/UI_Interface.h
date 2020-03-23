#pragma once
#ifndef UI_INTERFACE_H
#define UI_INTERFACE_H
#include"intersect.h"
using namespace std;
extern vector <Shape*> myallshape;
extern unordered_set<Point*, Hash_Point, Equal_Point> myallpoint;
void Add_Diagram(char* input1, int ifoutsource);
void Sub_Diagram(char* input2, int ifoutsource);
void File_InputProcess();
void Clear();
void Calculate();
#endif