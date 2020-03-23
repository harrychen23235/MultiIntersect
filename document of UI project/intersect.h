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

#endif // !INTERSECT_H

