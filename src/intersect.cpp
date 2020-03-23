#include"intersect.h"
using namespace std;
void InputProcess(vector <Shape*>& g_allshape) {
    long long linenumber = 0;
    cin >> linenumber;
    for (int i = 0; i < linenumber; i++) {
        string type;
        cin >> type;
        g_allshape.emplace_back((Line*)ShapeFactory::GetShape(type));
    }
}
int DirectionGet(double rootx, double rooty, double assistx, double assisty) {
    int direction = 0;
    bool comparex = assistx > rootx;
    bool comparey = assisty > rooty;
    bool samex = abs(assistx - rootx) < EPS;
    bool samey = abs(assisty - rooty) < EPS;
    if (samex && samey) return 0;
    if (samex) {
        if (assisty > rooty) direction = -3;
        else direction = -4;
    }
    else if (samey) {
        if (assistx > rootx) direction = -1;
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
    return direction;
}
bool Ray_Process(double x, double y, Ray* input1) {
    double mx1 = input1->mx1, my1 = input1->my1;
    int direction = 0;
    bool comparex = x > mx1;
    bool comparey = y > my1;
    bool samex = abs(mx1 - x) < EPS;
    bool samey = abs(my1 - y) < EPS;
    if (samex && samey) return true;
    if (samex) {
        if (y > my1) direction = -3;
        else direction = -4;
    }
    else if (samey) {
        if (x > mx1) direction = -1;
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
    return direction == input1->direction;
}
bool Seg_Process(double x, double y, Seg* input1) {
    double largex = input1->mx1 > input1->mx2 ? input1->mx1 : input1->mx2;
    double largey = input1->my1 > input1->my2 ? input1->my1 : input1->my2;
    double smallx = input1->mx2 > input1->mx1 ? input1->mx1 : input1->mx2;
    double smally = input1->my2 > input1->my1 ? input1->my1 : input1->my2;
    return smally - EPS <= y && smallx - EPS <= x && largex + EPS > x&& largey + EPS > y;
}
bool Line_Process(Line* input1, double x, double y) {
    if (input1->mtype == "L") return true;
    if (input1->mtype == "R") return Ray_Process(x, y, (Ray*)input1);
    if (input1->mtype == "S") return Seg_Process(x, y, (Seg*)input1);
}
void L2L_Special(Line* input1, Line* input2, int ifspecial, unordered_set<Point*, Hash_Point, Equal_Point>& g_allpoint) {
    if (input1->mtype == "L" || input2->mtype == "L");//throw string("infinite point");
    else if (input1->mtype == "R" && input2->mtype == "R") {
        if (abs(input1->ma - input2->ma) <= EPS && abs(input1->mb - input2->mb) <= EPS) {
            if (((Ray*)input1)->direction == ((Ray*)input2)->direction) {
                //throw string("infinite point");
            }
            else {
                g_allpoint.insert(new Point(input1->ma, input1->mb));
                return;
            }
        }
        else {
            int direction = DirectionGet(((Ray*)input1)->mx1, ((Ray*)input1)->my1, ((Ray*)input2)->mx1, ((Ray*)input2)->my1);
            if (direction == ((Ray*)input1)->direction);// throw string("infinite point");
            else return;
        }
    }
    else if (input1->mtype == "R" || input2->mtype == "R") {
        Ray* r1;
        Seg* s1;
        if (input1->mtype == "R") {
            r1 = (Ray*)input1;
            s1 = (Seg*)input2;
        }
        else {
            r1 = (Ray*)input2;
            s1 = (Seg*)input1;
        }
        int direction1 = DirectionGet(r1->mx1, r1->my1, s1->mx1, s1->my1);
        int direction2 = DirectionGet(r1->mx1, r1->my1, s1->mx2, s1->my2);
        if (direction1 == r1->direction || direction2 == r1->direction);// throw string("infinite point");
        else if (direction1 == 0 || direction2 == 0) g_allpoint.insert(new Point(r1->mx1, r1->my1));
        else return;
    }
    else {
        Seg* s1 = (Seg*)input1;
        Seg* s2 = (Seg*)input2;
        double largex1 = s1->mx1 > s1->mx2 ? s1->mx1 : s1->mx2;
        double smallx1 = s1->mx2 > s1->mx1 ? s1->mx1 : s1->mx2;
        double largex2 = s2->mx1 > s2->mx2 ? s2->mx1 : s2->mx2;
        double smallx2 = s2->mx2 > s2->mx1 ? s2->mx1 : s2->mx2;
        if (abs(smallx1 - largex2) <= EPS) {
            if (abs(smallx1 - s1->mx1) <= EPS) g_allpoint.insert(new Point(s1->mx1, s1->my1));
            else g_allpoint.insert(new Point(s1->mx2, s1->my2));
        }
        else if (abs(largex1 - smallx2) <= EPS) {
            if (abs(largex1 - s1->mx1) <= EPS) g_allpoint.insert(new Point(s1->mx1, s1->my1));
            else g_allpoint.insert(new Point(s1->mx2, s1->my2));
        }
        else if (smallx1 > largex2 || smallx2 > largex1) return;
        else;// throw string("infinite point");
    }
}
void L2L(Line* input1, Line* input2, unordered_set<Point*, Hash_Point, Equal_Point>& g_allpoint) {
    if (input1->mspecial == 0 && input2->mspecial == 0) {
        if (abs(input1->ma - input2->ma) <= EPS) {
            if (abs(input1->mb - input2->mb) <= EPS)
                L2L_Special(input1, input2, 0, g_allpoint);
            return;
        }
        double x = (input2->mb - input1->mb) / (input1->ma - input2->ma);
        double y = x * input1->ma + input1->mb;
        if (Line_Process(input1, x, y) && Line_Process(input2, x, y))
            g_allpoint.insert(new Point(x, y));
        return;
    }
    else if (input1->mspecial == 1 && input2->mspecial == 1) {
        if (input1->ma == input2->ma)
            L2L_Special(input1, input2, 1, g_allpoint);
        return;
    }
    else {
        if (input1->mspecial == 1) {
            double x = input1->ma;
            double y = input1->ma * input2->ma + input2->mb;
            if (Line_Process(input1, x, y) && Line_Process(input2, x, y))
                g_allpoint.insert(new Point(x, y));
        }
        else {
            double x = input2->ma;
            double y = input1->ma * input2->ma + input1->mb;
            if (Line_Process(input1, x, y) && Line_Process(input2, x, y))
                g_allpoint.insert(new Point(input2->ma, input1->ma * input2->ma + input1->mb));
        }
    }
}
void C2C(Circle* input1, Circle* input2, unordered_set<Point*, Hash_Point, Equal_Point>& g_allpoint) {
    double r2 = input2->mr, r1 = input1->mr, a1 = input1->mx, a2 = input2->mx, b1 = input1->my, b2 = input2->my;
    double x1 = 0, y1 = 0, x2 = 0, y2 = 0;
    if (abs(a1 - a2) < EPS && abs(b1 - b2) < EPS) {
        if (abs(r1 - r2) < EPS) {
            throw string("same circle error");
        }
        else return;
    }
    else if (!Circle::C2DisJudge(input1, input2)) return;
    else if (abs(b1 - b2) < EPS) {
        x1 = (r2 * r2 - r1 * r1 + a1 * a1 - a2 * a2) / (2 * a1 - 2 * a2);
        y1 = sqrt(r1 * r1 - (x1 - a1) * (x1 - a1)) + b1;
        y2 = -sqrt(r1 * r1 - (x1 - a1) * (x1 - a1)) + b1;
        g_allpoint.insert(new Point(x1, y1));
        g_allpoint.insert(new Point(x1, y2));
        return;
    }
    else {
        double tempm = (r2 * r2 - r1 * r1 + a1 * a1 - a2 * a2 + b1 * b1 - b2 * b2) / (2 * b1 - 2 * b2);
        double tempk = -(2 * a1 - 2 * a2) / (2 * b1 - 2 * b2);
        double temp1 = (1 + tempk * tempk);
        double temp2 = 2 * tempk * (tempm - b1) - 2 * a1;
        double temp3 = a1 * a1 + (tempm - b1) * (tempm - b1) - r1 * r1;
        x1 = (-temp2 + sqrt(temp2 * temp2 - 4 * temp1 * temp3)) / (2 * temp1);
        x2 = (-temp2 - sqrt(temp2 * temp2 - 4 * temp1 * temp3)) / (2 * temp1);
        y1 = tempk * x1 + tempm;
        y2 = tempk * x2 + tempm;
        g_allpoint.insert(new Point(x1, y1));
        g_allpoint.insert(new Point(x2, y2));
    }
    return;
}
void C2L(Circle* input1, Line* input2, unordered_set<Point*, Hash_Point, Equal_Point>& g_allpoint) {
    if (!Circle::CLDisJudge(input1, input2)) return;
    double x1 = 0, x2 = 0, y1 = 0, y2 = 0;
    double  r1 = input1->mr, a1 = input1->mx, b1 = input1->my;
    if (input2->mspecial == 1) {
        x1 = input2->ma;
        y1 = sqrt(r1 * r1 - (x1 - a1) * (x1 - a1)) + b1;
        y2 = -sqrt(r1 * r1 - (x1 - a1) * (x1 - a1)) + b1;
        if (Line_Process(input2, x1, y1))
            g_allpoint.insert(new Point(x1, y1));
        if (Line_Process(input2, x1, y2))
            g_allpoint.insert(new Point(x1, y2));
        return;
    }
    else {
        double tempm = input2->mb;
        double tempk = input2->ma;
        double temp1 = (1 + tempk * tempk);
        double temp2 = 2 * tempk * (tempm - b1) - 2 * a1;
        double temp3 = a1 * a1 + (tempm - b1) * (tempm - b1) - r1 * r1;
        x1 = (-temp2 + sqrt(temp2 * temp2 - 4 * temp1 * temp3)) / (2 * temp1);
        x2 = (-temp2 - sqrt(temp2 * temp2 - 4 * temp1 * temp3)) / (2 * temp1);
        y1 = tempk * x1 + tempm;
        y2 = tempk * x2 + tempm;
        if (Line_Process(input2, x1, y1))
            g_allpoint.insert(new Point(x1, y1));
        if (Line_Process(input2, x2, y2))
            g_allpoint.insert(new Point(x2, y2));
    }
}
void GetPoint(vector <Shape*>& g_allshape, unordered_set<Point*, Hash_Point, Equal_Point>& g_allpoint) {
    for (unsigned int i = 0; i < g_allshape.size(); i++) {
        for (unsigned int j = i + 1; j < g_allshape.size(); j++) {
            bool iisline = g_allshape.at(i)->mtype == "L" || g_allshape.at(i)->mtype == "R" || g_allshape.at(i)->mtype == "S";
            bool jisline = g_allshape.at(j)->mtype == "L" || g_allshape.at(j)->mtype == "R" || g_allshape.at(j)->mtype == "S";
            if (iisline && jisline) {
                L2L((Line*)g_allshape.at(i), (Line*)g_allshape.at(j), g_allpoint);//线和线相交
            }
            else if (g_allshape.at(i)->mtype == "C" && g_allshape.at(j)->mtype == "C") {
                C2C((Circle*)g_allshape.at(i), (Circle*)g_allshape.at(j), g_allpoint);//圆和圆相交
            }
            else if (g_allshape.at(i)->mtype == "C" && jisline) {
                C2L((Circle*)g_allshape.at(i), (Line*)g_allshape.at(j), g_allpoint);//圆和线相交
            }
            else if (iisline && g_allshape.at(j)->mtype == "C") {
                C2L((Circle*)g_allshape.at(j), (Line*)g_allshape.at(i), g_allpoint);
            }
        }
    }
}



