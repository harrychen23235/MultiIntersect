#include"UI_Interface.h"
using namespace std;
vector <Shape*> myallshape;
unordered_set<Point*, Hash_Point, Equal_Point> myallpoint;
void Add_Diagram(char* input1, int ifoutsource) {
    myallshape.push_back(ShapeFactory::GetShape(input1, ifoutsource));
}
void Sub_Diagram(char* input2, int ifoutsource) {
    Shape* tempshape = ShapeFactory::GetShape(input2, 1);
    for (int i = 0; i < (int)myallshape.size(); i++) {
        int ifdelete = 0;
        if (tempshape->mtype == myallshape.at(i)->mtype) {
            if (tempshape->mtype == "L") {
                Line* c1 = (Line*)tempshape;
                Line* c2 = (Line*)myallshape.at(i);
                if (c1->mspecial != c2->mspecial) continue;
                else if (c1->mspecial == 0) {
                    if (abs(c1->ma - c2->ma) < EPS && abs(c1->mb - c2->mb) < EPS) ifdelete = 1;

                }
                else if (c1->mspecial == 1) {
                    if (abs(c1->ma - c2->ma) < EPS) ifdelete = 1;
                }
            }
            else if (tempshape->mtype == "R") {
                Ray* c1 = (Ray*)tempshape;
                Ray* c2 = (Ray*)myallshape.at(i);
                if (c1->mspecial == 0 && c2->mspecial == 0) {
                    if (abs(c1->mx1 - c2->mx1) < EPS && abs(c1->my1 - c2->my1) < EPS && c1->direction == c2->direction && abs(c1->ma - c2->ma) < EPS) ifdelete = 1;
                }
                else if (c1->mspecial == 1 && c2->mspecial == 1) {
                    if (c1->direction == c2->direction && abs(c1->ma - c2->ma) < EPS) ifdelete = 1;
                }
            }
            else if (tempshape->mtype == "S") {
                Seg* c1 = (Seg*)tempshape;
                Seg* c2 = (Seg*)myallshape.at(i);
                if (abs(c1->mx1 - c2->mx1) < EPS && abs(c1->my1 - c2->my1) < EPS && abs(c1->mx2 - c2->mx2) < EPS && abs(c1->my2 - c2->my2) < EPS) ifdelete = 1;
            }
            else if (tempshape->mtype == "C") {
                Circle* c1 = (Circle*)tempshape;
                Circle* c2 = (Circle*)myallshape.at(i);
                if (abs(c1->mr - c2->mr) < EPS && abs(c1->mx - c2->mx) < EPS && abs(c1->my - c2->my) < EPS) ifdelete = 1;
            }
        }
        if (ifdelete == 1) {
            myallshape.erase(myallshape.begin() + i);
            i--;
        }
    }
}
void File_InputProcess() {
    InputProcess(myallshape);
}
void Calculate() {
    GetPoint(myallshape, myallpoint);
}
void Clear() {
    myallshape.clear();
    myallpoint.clear();
}