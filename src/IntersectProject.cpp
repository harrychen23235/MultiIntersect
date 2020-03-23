// IntersectProject.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>
#include<unordered_set>
#include<math.h>
#include <ctime>
#include <fstream>
#include"shape.h"
#include"intersect.h"

using namespace std;
int main(int argc,char*argv[])
{
	FILE* stream1;
	FILE* stream2;
	for (int arg = 0; arg < argc; arg++) {
		if ((string)argv[arg] == "-i") {
			freopen_s(&stream1,argv[arg + 1], "r", stdin);
		}
		else if ((string)argv[arg] == "-o") {
			freopen_s(&stream2,argv[arg + 1], "w", stdout);
		}
	}
	vector <Shape*> g_allshape;
	unordered_set<Point*, Hash_Point, Equal_Point> g_allpoint;
	try {
		//freopen_s(&stream1, "G:\\360MoveData\\Users\\HP\\Desktop\\IntersectProject\\Debug\\test.txt", "r", stdin);
		InputProcess(g_allshape);//所有的输入操作处理
		GetPoint(g_allshape, g_allpoint);//得到最终节点
		cout << g_allpoint.size() << endl;
		unordered_set<Point*, Hash_Point, Equal_Point>::iterator iter = g_allpoint.begin();
	}
	catch (string e) {
		cout << e << endl;
	}
	/*struct Hash_Point a;
	unordered_set<Point*>::iterator iter = g_allpoint.begin();
	while (iter != g_allpoint.end())
	{
		cout << a.operator()(*iter) << endl;
		cout << (*iter)->x;
		cout << "\n";
		cout << (*iter)->y;
		cout << "\n";
		iter++;
	}*/
    fclose(stdin);
	fclose(stdout);
	//system("PAUSE");
    return 0;
}


