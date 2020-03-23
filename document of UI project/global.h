#ifndef GLOBAL_H
#define GLOBAL_H
#include"intersect.h"

class global
{
public:
    global();
    static vector <Shape*> myallshape;
    static unordered_set<Point*, Hash_Point, Equal_Point> myallpoint;
};

#endif // GLOBAL_H
