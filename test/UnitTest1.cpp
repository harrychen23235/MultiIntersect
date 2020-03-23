#define _CRT_SECURE_NO_WARNINGS
#include "pch.h"
#include "CppUnitTest.h"
#include <iostream>
#include <vector>
#include<unordered_set>
#include<math.h>
#include <ctime>
#include<Windows.h>
#include"G:\360MoveData\Users\HP\Desktop\IntersectProject\IntersectProject\intersect.h"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;
extern vector <Shape*> myallshape;
extern unordered_set<Point*, Hash_Point, Equal_Point> myallpoint;
namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		TEST_METHOD(TestMethod1) {
			Assert::AreEqual(3, 3);
		}

		TEST_METHOD(TestMethod2)
		{
			vector <Shape*> allshape1;
			unordered_set<Point*, Hash_Point, Equal_Point> allpoint1;
			allshape1.emplace_back(ShapeFactory::GetShape("L", 0, 0, 0, 1));
			allshape1.emplace_back(ShapeFactory::GetShape("L", 0, 0, 1, 0));
			allshape1.emplace_back(ShapeFactory::GetShape("L", 0, 0, 1, 1));
			allshape1.emplace_back(ShapeFactory::GetShape("L", 0, 1, 1, 1));
			GetPoint(allshape1, allpoint1);
			Assert::AreEqual(3, (int)allpoint1.size());
		}
		TEST_METHOD(TestMethod3)
		{
			vector <Shape*> allshape1;
			unordered_set<Point*, Hash_Point, Equal_Point> allpoint1;
			allshape1.emplace_back(ShapeFactory::GetShape("L", -10, -9, -9, 10));
			allshape1.emplace_back(ShapeFactory::GetShape("L", -9, 10, 10, 9));
			allshape1.emplace_back(ShapeFactory::GetShape("L", 10, 9, 9, -10));
			allshape1.emplace_back(ShapeFactory::GetShape("L", 9, -10, -10, -9));
			GetPoint(allshape1, allpoint1);
			Assert::AreEqual(4, (int)allpoint1.size());
		}
		TEST_METHOD(TestMethod4)
		{
			vector <Shape*> allshape1;
			unordered_set<Point*, Hash_Point, Equal_Point> allpoint1;
			allshape1.emplace_back(ShapeFactory::GetShape("L", -100, -99, -99, 100));
			allshape1.emplace_back(ShapeFactory::GetShape("L", -99, 100, 100, 99));
			allshape1.emplace_back(ShapeFactory::GetShape("L", 100, 99, 99, -100));
			allshape1.emplace_back(ShapeFactory::GetShape("L", 90, -100, -100, -99));
			GetPoint(allshape1, allpoint1);
			Assert::AreEqual(5, (int)allpoint1.size());
		}
		TEST_METHOD(TestMethod5)
		{
			vector <Shape*> allshape1;
			unordered_set<Point*, Hash_Point, Equal_Point> allpoint1;
			allshape1.emplace_back(ShapeFactory::GetShape("L", -99999, 0, 99999, 1));
			allshape1.emplace_back(ShapeFactory::GetShape("L", 0, 0, 1, 0));
			allshape1.emplace_back(ShapeFactory::GetShape("L", -99998, 0, -99998, 1));
			GetPoint(allshape1, allpoint1);
			Assert::AreEqual(3, (int)allpoint1.size());
		}
		TEST_METHOD(TestMethod6)
		{
			vector <Shape*> allshape1;
			unordered_set<Point*, Hash_Point, Equal_Point> allpoint1;
			allshape1.emplace_back(ShapeFactory::GetShape("L", 0, 0, 99998, 2));
			allshape1.emplace_back(ShapeFactory::GetShape("L", 0, 2, 49999, 3));
			allshape1.emplace_back(ShapeFactory::GetShape("L", 0, 0, -99999, 0));
			GetPoint(allshape1, allpoint1);
			Assert::AreEqual(2, (int)allpoint1.size());
		}
		TEST_METHOD(TestMethod7)
		{
			vector <Shape*> allshape1;
			unordered_set<Point*, Hash_Point, Equal_Point> allpoint1;
			allshape1.emplace_back(ShapeFactory::GetShape("L", 0, 0, 1, 1));
			allshape1.emplace_back(ShapeFactory::GetShape("L", 1, 0, 0, 1));
			allshape1.emplace_back(ShapeFactory::GetShape("L", 1, 2, 2, 0));
			allshape1.emplace_back(ShapeFactory::GetShape("L", 0, 3, 1, 2));
			allshape1.emplace_back(ShapeFactory::GetShape("L", 0, 1, 2, 2));
			GetPoint(allshape1, allpoint1);
			Assert::AreEqual(9, (int)allpoint1.size());
		}
		TEST_METHOD(TestMethod8)
		{
			vector <Shape*> allshape1;
			unordered_set<Point*, Hash_Point, Equal_Point> allpoint1;
			allshape1.emplace_back(ShapeFactory::GetShape("L", 0, 0, 0, 1));
			allshape1.emplace_back(ShapeFactory::GetShape("L", 2, 0, 2, 1));
			allshape1.emplace_back(ShapeFactory::GetShape("C", 1, 0, 1, 0));
			GetPoint(allshape1, allpoint1);
			Assert::AreEqual(2, (int)allpoint1.size());
		}
		TEST_METHOD(TestMethod9)
		{
			vector <Shape*> allshape1;
			unordered_set<Point*, Hash_Point, Equal_Point> allpoint1;
			allshape1.emplace_back(ShapeFactory::GetShape("C", 1, 0, 2, 0));
			allshape1.emplace_back(ShapeFactory::GetShape("C", 2, 2, 1, 0));
			allshape1.emplace_back(ShapeFactory::GetShape("C", 3, -2, 6, 0));
			allshape1.emplace_back(ShapeFactory::GetShape("L", -1, 4, 4, -1));
			GetPoint(allshape1, allpoint1);
			Assert::AreEqual(6, (int)allpoint1.size());
		}
		TEST_METHOD(TestMethod10)
		{
			Circle c1 = Circle(1, 0, 1);
			Circle c2 = Circle(3, 0, 1);
			Circle c3 = Circle(4, 0, 1);
			Circle c4 = Circle(-5, 0, 7);
			Assert::AreEqual(true, Circle::C2DisJudge(&c1, &c2));
			Assert::AreEqual(false, Circle::C2DisJudge(&c1, &c3));
			Assert::AreEqual(true, Circle::C2DisJudge(&c1, &c4));
		}
		TEST_METHOD(TestMethod11)
		{
			Circle c1 = Circle(5, 0, 5);
			Line l1 = Line(0, 5, 0);
			Line l2 = Line(0, 4, 0);
			Line l3 = Line(0, 6, 0);
			Assert::AreEqual(true, Circle::CLDisJudge(&c1, &l1));
			Assert::AreEqual(true, Circle::CLDisJudge(&c1, &l2));
			Assert::AreEqual(false, Circle::CLDisJudge(&c1, &l3));
		}
		TEST_METHOD(TestMethod12)
		{
			vector <Shape*> allshape1;
			unordered_set<Point*, Hash_Point, Equal_Point> allpoint1;
			allshape1.emplace_back(ShapeFactory::GetShape("C", 1, 0, 1, 0));
			allshape1.emplace_back(ShapeFactory::GetShape("C", 3, 0, 1, 0));
			GetPoint(allshape1, allpoint1);
			Assert::AreEqual(1, (int)allpoint1.size());
		}
		TEST_METHOD(TestMethod13)
		{
			vector <Shape*> allshape1;
			unordered_set<Point*, Hash_Point, Equal_Point> allpoint1;
			allshape1.emplace_back(ShapeFactory::GetShape("C", 1, 0, 1, 0));
			allshape1.emplace_back(ShapeFactory::GetShape("L", 1, 0, 1, 1));
			GetPoint(allshape1, allpoint1);
			Assert::AreEqual(2, (int)allpoint1.size());
		}
		TEST_METHOD(TestMethod14)
		{
			vector <Shape*> allshape1;
			unordered_set<Point*, Hash_Point, Equal_Point> allpoint1;
			allshape1.emplace_back(ShapeFactory::GetShape("S", -1, 3, 2, -1));
			allshape1.emplace_back(ShapeFactory::GetShape("L", -2, 2, 3, 0));
			allshape1.emplace_back(ShapeFactory::GetShape("R", -3, 0, 4, 2));
			GetPoint(allshape1, allpoint1);
			Assert::AreEqual(1, (int)allpoint1.size());
		}
		TEST_METHOD(TestMethod15)
		{
			vector <Shape*> allshape1;
			unordered_set<Point*, Hash_Point, Equal_Point> allpoint1;
			allshape1.emplace_back(ShapeFactory::GetShape("C", 3, 3, 3, 0));
			allshape1.emplace_back(ShapeFactory::GetShape("S", 2, 4, 3, 2));
			allshape1.emplace_back(ShapeFactory::GetShape("L", -1, 4, 5, 2));
			allshape1.emplace_back(ShapeFactory::GetShape("R", 2, 5, -1, 2));
			GetPoint(allshape1, allpoint1);
			Assert::AreEqual(5, (int)allpoint1.size());
		}
		TEST_METHOD(TestMethod16) {
			Seg* tempseg = (Seg*)ShapeFactory::GetShape("S", 0, 0, 1, 1);
			bool temp1 = Seg_Process(0, 0, tempseg);
			bool temp2 = Seg_Process(1, 1, tempseg);
			bool temp3 = Seg_Process(-1, -1, tempseg);
			bool temp4 = Seg_Process(2, 2, tempseg);
			Assert::AreEqual(true, temp1);
			Assert::AreEqual(true, temp2);
			Assert::AreEqual(false, temp3);
			Assert::AreEqual(false, temp4);
		}
		TEST_METHOD(TestMethod17) {
			Ray* tempray = (Ray*)ShapeFactory::GetShape("R", 0, 0, 1, 1);
			bool temp1 = Ray_Process(0, 0, tempray);
			bool temp2 = Ray_Process(1, 1, tempray);
			bool temp3 = Ray_Process(-1, -1, tempray);
			bool temp4 = Ray_Process(2, 2, tempray);
			Assert::AreEqual(true, temp1);
			Assert::AreEqual(true, temp2);
			Assert::AreEqual(false, temp3);
			Assert::AreEqual(true, temp4);
		}
		TEST_METHOD(TestMethod18) {

			int matrix1 = DirectionGet(2, 3, 4, 5);
			int matrix2 = DirectionGet(2, 3, 1, 4);
			int matrix3 = DirectionGet(2, 3, 1, 2);
			int matrix4 = DirectionGet(2, 3, 3, 2);
			int matrix_1 = DirectionGet(0, 0, 1, 0);
			int matrix_2 = DirectionGet(0, 0, -1, 0);
			int matrix_3 = DirectionGet(1, 1, 1, 2);
			int matrix_4 = DirectionGet(1, 1, 1, 0);
			Assert::AreEqual(1, matrix1);
			Assert::AreEqual(2, matrix2);
			Assert::AreEqual(3, matrix3);
			Assert::AreEqual(4, matrix4);
			Assert::AreEqual(-1, matrix_1);
			Assert::AreEqual(-2, matrix_2);
			Assert::AreEqual(-3, matrix_3);
			Assert::AreEqual(-4, matrix_4);
		}
		TEST_METHOD(TestMethod19) {
			unordered_set<Point*, Hash_Point, Equal_Point> allpoint1;
			L2L_Special((Line*)ShapeFactory::GetShape("R", 0, 0, 1, 1), (Line*)ShapeFactory::GetShape("R", 0, 0, -1, -1), 0, allpoint1);
			Assert::AreEqual(1, (int)allpoint1.size());
			allpoint1.clear();
			L2L_Special((Line*)ShapeFactory::GetShape("R", 0, 0, 1, 0), (Line*)ShapeFactory::GetShape("R", 0, 0, -1, 0), 0, allpoint1);
			Assert::AreEqual(1, (int)allpoint1.size());
			allpoint1.clear();
			L2L_Special((Line*)ShapeFactory::GetShape("R", 0, 0, 0, 1), (Line*)ShapeFactory::GetShape("R", 0, 0, 0, -1), 1, allpoint1);
			Assert::AreEqual(1, (int)allpoint1.size());
			allpoint1.clear();
			L2L_Special((Line*)ShapeFactory::GetShape("S", 1, 2, 3, 4), (Line*)ShapeFactory::GetShape("R", 3, 4, 5, 6), 0, allpoint1);
			Assert::AreEqual(1, (int)allpoint1.size());
			allpoint1.clear();
			L2L_Special((Line*)ShapeFactory::GetShape("S", 1, 2, 1, 3), (Line*)ShapeFactory::GetShape("R", 1, 3, 1, 4), 1, allpoint1);
			Assert::AreEqual(1, (int)allpoint1.size());
		}
		TEST_METHOD(TestMethod20) {
			bool b1 = RangeJudge(-100000);
			bool b2 = RangeJudge(100000);
			bool b3 = RangeJudge(-100001);
			bool b4 = RangeJudge(100001);
			bool b5 = RangeJudge(-99999);
			bool b6 = RangeJudge(99999);
			Assert::AreEqual(b1, true);
			Assert::AreEqual(b2, true);
			Assert::AreEqual(b3, true);
			Assert::AreEqual(b4, true);
			Assert::AreEqual(b5, false);
			Assert::AreEqual(b6, false);
		}		TEST_METHOD(TestMethod53) {
			Add_Diagram("C 1 0 2 0", 1);
			Add_Diagram("C 2 2 1 0", 1);
			Add_Diagram("C 3 -2 6 0", 1);
			Add_Diagram("L -1 4 4 -1", 1);
			Calculate();
			Assert::AreEqual(6, (int)myallpoint.size());
			Clear();
			Calculate();
			Assert::AreEqual(0, (int)myallpoint.size());
			Add_Diagram("C 1 0 2 0", 1);
			Add_Diagram("C 2 2 1 0", 1);
			Add_Diagram("C 3 -2 6 0", 1);
			Add_Diagram("L -1 4 4 -1", 1);
			Calculate();
			Assert::AreEqual(6, (int)myallpoint.size());
			Sub_Diagram("C 1 0 2 0", 1);
			Sub_Diagram("C 2 2 1 0", 1);
			Sub_Diagram("C 3 -2 6 0", 1);
			Sub_Diagram("L -1 4 4 -1", 1);
			myallpoint.clear();
			Calculate();
			Assert::AreEqual(0, (int)myallpoint.size());
		}
		TEST_METHOD(TestMethod21)
		{
			FILE* stream1;
			FILE* stream2;
			freopen_s(&stream1, "G:\\360MoveData\\Users\\HP\\Desktop\\nt\\input.txt", "w", stdout);
			printf("%d\n", 4);
			printf("C 3 3 3\n");
			printf("S 2 4 3 2\n");
			printf("L -1 4 5 2\n");
			printf("R 2 5 -1 2\n");
			fclose(stdout);
			PROCESS_INFORMATION ProcessInfo;
			STARTUPINFO StartupInfo; //入口参数
			ZeroMemory(&StartupInfo, sizeof(StartupInfo));
			StartupInfo.cb = sizeof StartupInfo; //分配大小
			if (CreateProcess("G:\\360MoveData\\Users\\HP\\Desktop\\nt\\IntersectProject.exe", "G:\\360MoveData\\Users\\HP\\Desktop\\nt\\IntersectProject.exe -i G:\\360MoveData\\Users\\HP\\Desktop\\nt\\input.txt -o G:\\360MoveData\\Users\\HP\\Desktop\\nt\\output.txt",
				NULL, NULL, FALSE, HIGH_PRIORITY_CLASS, NULL,
				NULL, &StartupInfo, &ProcessInfo))
			{
				WaitForSingleObject(ProcessInfo.hProcess, INFINITE);
				CloseHandle(ProcessInfo.hThread);
				CloseHandle(ProcessInfo.hProcess);
			}

			//WinExec("G:\\360MoveData\\Users\\HP\\Desktop\\nt\\IntersectProject.exe -i G:\\360MoveData\\Users\\HP\\Desktop\\nt\\input.txt -o G:\\360MoveData\\Users\\HP\\Desktop\\nt\\output.txt", SW_HIDE); 
			int result = 0;
			FILE* open = fopen("G:\\360MoveData\\Users\\HP\\Desktop\\nt\\output.txt", "r");
			fscanf(open, "%d", &result);
			fclose(open);
			Assert::AreEqual(5, result);
		}

		TEST_METHOD(TestMethod22)
		{
			FILE* stream1;
			FILE* stream2;
			freopen_s(&stream1, "G:\\360MoveData\\Users\\HP\\Desktop\\nt\\input.txt", "w", stdout);
			printf("%d\n", 3);
			printf("L 0 0 1 1\n");
			printf("L 0 0 1 2\n");
			printf("L 0 0 1 3\n");

			fclose(stdout);
			PROCESS_INFORMATION ProcessInfo;
			STARTUPINFO StartupInfo; //入口参数
			ZeroMemory(&StartupInfo, sizeof(StartupInfo));
			StartupInfo.cb = sizeof StartupInfo; //分配大小
			if (CreateProcess("G:\\360MoveData\\Users\\HP\\Desktop\\nt\\IntersectProject.exe", "G:\\360MoveData\\Users\\HP\\Desktop\\nt\\IntersectProject.exe -i G:\\360MoveData\\Users\\HP\\Desktop\\nt\\input.txt -o G:\\360MoveData\\Users\\HP\\Desktop\\nt\\output.txt",
				NULL, NULL, FALSE, HIGH_PRIORITY_CLASS, NULL,
				NULL, &StartupInfo, &ProcessInfo))
			{
				WaitForSingleObject(ProcessInfo.hProcess, INFINITE);
				CloseHandle(ProcessInfo.hThread);
				CloseHandle(ProcessInfo.hProcess);
			}

			//WinExec("G:\\360MoveData\\Users\\HP\\Desktop\\nt\\IntersectProject.exe -i G:\\360MoveData\\Users\\HP\\Desktop\\nt\\input.txt -o G:\\360MoveData\\Users\\HP\\Desktop\\nt\\output.txt", SW_HIDE); 
			int result = 0;
			FILE* open = fopen("G:\\360MoveData\\Users\\HP\\Desktop\\nt\\output.txt", "r");
			fscanf(open, "%d", &result);
			fclose(open);
			Assert::AreEqual(1, result);

		};
		TEST_METHOD(TestMethod23)
		{
			FILE* stream1;
			FILE* stream2;
			freopen_s(&stream1, "G:\\360MoveData\\Users\\HP\\Desktop\\nt\\input.txt", "w", stdout);
			printf("%d\n", 3);
			printf("L 0 0 1 1\n");
			printf("L 0 0 1 3\n");
			printf("L -1 -1 1 2\n");

			fclose(stdout);
			PROCESS_INFORMATION ProcessInfo;
			STARTUPINFO StartupInfo; //入口参数
			ZeroMemory(&StartupInfo, sizeof(StartupInfo));
			StartupInfo.cb = sizeof StartupInfo; //分配大小
			if (CreateProcess("G:\\360MoveData\\Users\\HP\\Desktop\\nt\\IntersectProject.exe", "G:\\360MoveData\\Users\\HP\\Desktop\\nt\\IntersectProject.exe -i G:\\360MoveData\\Users\\HP\\Desktop\\nt\\input.txt -o G:\\360MoveData\\Users\\HP\\Desktop\\nt\\output.txt",
				NULL, NULL, FALSE, HIGH_PRIORITY_CLASS, NULL,
				NULL, &StartupInfo, &ProcessInfo))
			{
				WaitForSingleObject(ProcessInfo.hProcess, INFINITE);
				CloseHandle(ProcessInfo.hThread);
				CloseHandle(ProcessInfo.hProcess);
			}

			//WinExec("G:\\360MoveData\\Users\\HP\\Desktop\\nt\\IntersectProject.exe -i G:\\360MoveData\\Users\\HP\\Desktop\\nt\\input.txt -o G:\\360MoveData\\Users\\HP\\Desktop\\nt\\output.txt", SW_HIDE); 
			int result = 0;
			FILE* open = fopen("G:\\360MoveData\\Users\\HP\\Desktop\\nt\\output.txt", "r");
			fscanf(open, "%d", &result);
			fclose(open);
			Assert::AreEqual(3, result);

		};
		TEST_METHOD(TestMethod24)
		{
			FILE* stream1;
			FILE* stream2;
			freopen_s(&stream1, "G:\\360MoveData\\Users\\HP\\Desktop\\nt\\input.txt", "w", stdout);
			printf("%d\n", 3);
			printf("L 0 0 1 1\n");
			printf("L 0 1 1 3\n");
			printf("L 0 6 1 9\n");

			fclose(stdout);
			PROCESS_INFORMATION ProcessInfo;
			STARTUPINFO StartupInfo; //入口参数
			ZeroMemory(&StartupInfo, sizeof(StartupInfo));
			StartupInfo.cb = sizeof StartupInfo; //分配大小
			if (CreateProcess("G:\\360MoveData\\Users\\HP\\Desktop\\nt\\IntersectProject.exe", "G:\\360MoveData\\Users\\HP\\Desktop\\nt\\IntersectProject.exe -i G:\\360MoveData\\Users\\HP\\Desktop\\nt\\input.txt -o G:\\360MoveData\\Users\\HP\\Desktop\\nt\\output.txt",
				NULL, NULL, FALSE, HIGH_PRIORITY_CLASS, NULL,
				NULL, &StartupInfo, &ProcessInfo))
			{
				WaitForSingleObject(ProcessInfo.hProcess, INFINITE);
				CloseHandle(ProcessInfo.hThread);
				CloseHandle(ProcessInfo.hProcess);
			}

			//WinExec("G:\\360MoveData\\Users\\HP\\Desktop\\nt\\IntersectProject.exe -i G:\\360MoveData\\Users\\HP\\Desktop\\nt\\input.txt -o G:\\360MoveData\\Users\\HP\\Desktop\\nt\\output.txt", SW_HIDE); 
			int result = 0;
			FILE* open = fopen("G:\\360MoveData\\Users\\HP\\Desktop\\nt\\output.txt", "r");
			fscanf(open, "%d", &result);
			fclose(open);
			Assert::AreEqual(3, result);

		};
		TEST_METHOD(TestMethod25)
		{
			FILE* stream1;
			FILE* stream2;
			freopen_s(&stream1, "G:\\360MoveData\\Users\\HP\\Desktop\\nt\\input.txt", "w", stdout);
			printf("%d\n", 3);
			printf("C 2 2 2\n");
			printf("L 0 0 0 1\n");
			printf("L 0 0 1 0\n");

			fclose(stdout);
			PROCESS_INFORMATION ProcessInfo;
			STARTUPINFO StartupInfo; //入口参数
			ZeroMemory(&StartupInfo, sizeof(StartupInfo));
			StartupInfo.cb = sizeof StartupInfo; //分配大小
			if (CreateProcess("G:\\360MoveData\\Users\\HP\\Desktop\\nt\\IntersectProject.exe", "G:\\360MoveData\\Users\\HP\\Desktop\\nt\\IntersectProject.exe -i G:\\360MoveData\\Users\\HP\\Desktop\\nt\\input.txt -o G:\\360MoveData\\Users\\HP\\Desktop\\nt\\output.txt",
				NULL, NULL, FALSE, HIGH_PRIORITY_CLASS, NULL,
				NULL, &StartupInfo, &ProcessInfo))
			{
				WaitForSingleObject(ProcessInfo.hProcess, INFINITE);
				CloseHandle(ProcessInfo.hThread);
				CloseHandle(ProcessInfo.hProcess);
			}

			//WinExec("G:\\360MoveData\\Users\\HP\\Desktop\\nt\\IntersectProject.exe -i G:\\360MoveData\\Users\\HP\\Desktop\\nt\\input.txt -o G:\\360MoveData\\Users\\HP\\Desktop\\nt\\output.txt", SW_HIDE); 
			int result = 0;
			FILE* open = fopen("G:\\360MoveData\\Users\\HP\\Desktop\\nt\\output.txt", "r");
			fscanf(open, "%d", &result);
			fclose(open);
			Assert::AreEqual(3, result);

		};
		TEST_METHOD(TestMethod26)
		{
			FILE* stream1;
			FILE* stream2;
			freopen_s(&stream1, "G:\\360MoveData\\Users\\HP\\Desktop\\nt\\input.txt", "w", stdout);
			printf("%d\n", 3);
			printf("C 2 2 2\n");
			printf("L 0 4 2 4\n");
			printf("L 0 0 1 0\n");

			fclose(stdout);
			PROCESS_INFORMATION ProcessInfo;
			STARTUPINFO StartupInfo; //入口参数
			ZeroMemory(&StartupInfo, sizeof(StartupInfo));
			StartupInfo.cb = sizeof StartupInfo; //分配大小
			if (CreateProcess("G:\\360MoveData\\Users\\HP\\Desktop\\nt\\IntersectProject.exe", "G:\\360MoveData\\Users\\HP\\Desktop\\nt\\IntersectProject.exe -i G:\\360MoveData\\Users\\HP\\Desktop\\nt\\input.txt -o G:\\360MoveData\\Users\\HP\\Desktop\\nt\\output.txt",
				NULL, NULL, FALSE, HIGH_PRIORITY_CLASS, NULL,
				NULL, &StartupInfo, &ProcessInfo))
			{
				WaitForSingleObject(ProcessInfo.hProcess, INFINITE);
				CloseHandle(ProcessInfo.hThread);
				CloseHandle(ProcessInfo.hProcess);
			}

			//WinExec("G:\\360MoveData\\Users\\HP\\Desktop\\nt\\IntersectProject.exe -i G:\\360MoveData\\Users\\HP\\Desktop\\nt\\input.txt -o G:\\360MoveData\\Users\\HP\\Desktop\\nt\\output.txt", SW_HIDE); 
			int result = 0;
			FILE* open = fopen("G:\\360MoveData\\Users\\HP\\Desktop\\nt\\output.txt", "r");
			fscanf(open, "%d", &result);
			fclose(open);
			Assert::AreEqual(2, result);
		};
		TEST_METHOD(TestMethod27)
		{
			FILE* stream1;
			FILE* stream2;
			freopen_s(&stream1, "G:\\360MoveData\\Users\\HP\\Desktop\\nt\\input.txt", "w", stdout);
			printf("%d\n", 4);
			printf("C 2 2 2\n");
			printf("L 0 0 0 1\n");
			printf("L 0 0 1 0\n");
			printf("S 0 0 2 2\n");
			fclose(stdout);
			PROCESS_INFORMATION ProcessInfo;
			STARTUPINFO StartupInfo; //入口参数
			ZeroMemory(&StartupInfo, sizeof(StartupInfo));
			StartupInfo.cb = sizeof StartupInfo; //分配大小
			if (CreateProcess("G:\\360MoveData\\Users\\HP\\Desktop\\nt\\IntersectProject.exe", "G:\\360MoveData\\Users\\HP\\Desktop\\nt\\IntersectProject.exe -i G:\\360MoveData\\Users\\HP\\Desktop\\nt\\input.txt -o G:\\360MoveData\\Users\\HP\\Desktop\\nt\\output.txt",
				NULL, NULL, FALSE, HIGH_PRIORITY_CLASS, NULL,
				NULL, &StartupInfo, &ProcessInfo))
			{
				WaitForSingleObject(ProcessInfo.hProcess, INFINITE);
				CloseHandle(ProcessInfo.hThread);
				CloseHandle(ProcessInfo.hProcess);
			}

			//WinExec("G:\\360MoveData\\Users\\HP\\Desktop\\nt\\IntersectProject.exe -i G:\\360MoveData\\Users\\HP\\Desktop\\nt\\input.txt -o G:\\360MoveData\\Users\\HP\\Desktop\\nt\\output.txt", SW_HIDE); 
			int result = 0;
			FILE* open = fopen("G:\\360MoveData\\Users\\HP\\Desktop\\nt\\output.txt", "r");
			fscanf(open, "%d", &result);
			fclose(open);
			Assert::AreEqual(4, result);
		};
		TEST_METHOD(TestMethod28)
		{
			FILE* stream1;
			FILE* stream2;
			freopen_s(&stream1, "G:\\360MoveData\\Users\\HP\\Desktop\\nt\\input.txt", "w", stdout);
			printf("%d\n", 4);
			printf("C 2 2 2\n");
			printf("L 0 0 0 1\n");
			printf("L 0 0 1 0\n");
			printf("R 0 0 2 2\n");
			fclose(stdout);
			PROCESS_INFORMATION ProcessInfo;
			STARTUPINFO StartupInfo; //入口参数
			ZeroMemory(&StartupInfo, sizeof(StartupInfo));
			StartupInfo.cb = sizeof StartupInfo; //分配大小
			if (CreateProcess("G:\\360MoveData\\Users\\HP\\Desktop\\nt\\IntersectProject.exe", "G:\\360MoveData\\Users\\HP\\Desktop\\nt\\IntersectProject.exe -i G:\\360MoveData\\Users\\HP\\Desktop\\nt\\input.txt -o G:\\360MoveData\\Users\\HP\\Desktop\\nt\\output.txt",
				NULL, NULL, FALSE, HIGH_PRIORITY_CLASS, NULL,
				NULL, &StartupInfo, &ProcessInfo))
			{
				WaitForSingleObject(ProcessInfo.hProcess, INFINITE);
				CloseHandle(ProcessInfo.hThread);
				CloseHandle(ProcessInfo.hProcess);
			}

			//WinExec("G:\\360MoveData\\Users\\HP\\Desktop\\nt\\IntersectProject.exe -i G:\\360MoveData\\Users\\HP\\Desktop\\nt\\input.txt -o G:\\360MoveData\\Users\\HP\\Desktop\\nt\\output.txt", SW_HIDE); 
			int result = 0;
			FILE* open = fopen("G:\\360MoveData\\Users\\HP\\Desktop\\nt\\output.txt", "r");
			fscanf(open, "%d", &result);
			fclose(open);
			Assert::AreEqual(5, result);

		};
		TEST_METHOD(TestMethod29)
		{
			FILE* stream1;
			FILE* stream2;
			freopen_s(&stream1, "G:\\360MoveData\\Users\\HP\\Desktop\\nt\\input.txt", "w", stdout);
			printf("%d\n", 4);
			printf("C 2 2 2\n");
			printf("L 0 4 2 4\n");
			printf("L 0 0 1 0\n");
			printf("R 0 0 2 2\n");
			fclose(stdout);
			PROCESS_INFORMATION ProcessInfo;
			STARTUPINFO StartupInfo; //入口参数
			ZeroMemory(&StartupInfo, sizeof(StartupInfo));
			StartupInfo.cb = sizeof StartupInfo; //分配大小
			if (CreateProcess("G:\\360MoveData\\Users\\HP\\Desktop\\nt\\IntersectProject.exe", "G:\\360MoveData\\Users\\HP\\Desktop\\nt\\IntersectProject.exe -i G:\\360MoveData\\Users\\HP\\Desktop\\nt\\input.txt -o G:\\360MoveData\\Users\\HP\\Desktop\\nt\\output.txt",
				NULL, NULL, FALSE, HIGH_PRIORITY_CLASS, NULL,
				NULL, &StartupInfo, &ProcessInfo))
			{
				WaitForSingleObject(ProcessInfo.hProcess, INFINITE);
				CloseHandle(ProcessInfo.hThread);
				CloseHandle(ProcessInfo.hProcess);
			}

			//WinExec("G:\\360MoveData\\Users\\HP\\Desktop\\nt\\IntersectProject.exe -i G:\\360MoveData\\Users\\HP\\Desktop\\nt\\input.txt -o G:\\360MoveData\\Users\\HP\\Desktop\\nt\\output.txt", SW_HIDE); 
			int result = 0;
			FILE* open = fopen("G:\\360MoveData\\Users\\HP\\Desktop\\nt\\output.txt", "r");
			fscanf(open, "%d", &result);
			fclose(open);
			Assert::AreEqual(6, result);

		};
		TEST_METHOD(TestMethod30)
		{
			FILE* stream1;
			FILE* stream2;
			freopen_s(&stream1, "G:\\360MoveData\\Users\\HP\\Desktop\\nt\\input.txt", "w", stdout);
			printf("%d\n", 4);
			printf("C 2 2 2\n");
			printf("L 0 4 2 4\n");
			printf("L 0 0 1 0\n");
			printf("S 1 1 2 2\n");
			fclose(stdout);
			PROCESS_INFORMATION ProcessInfo;
			STARTUPINFO StartupInfo; //入口参数
			ZeroMemory(&StartupInfo, sizeof(StartupInfo));
			StartupInfo.cb = sizeof StartupInfo; //分配大小
			if (CreateProcess("G:\\360MoveData\\Users\\HP\\Desktop\\nt\\IntersectProject.exe", "G:\\360MoveData\\Users\\HP\\Desktop\\nt\\IntersectProject.exe -i G:\\360MoveData\\Users\\HP\\Desktop\\nt\\input.txt -o G:\\360MoveData\\Users\\HP\\Desktop\\nt\\output.txt",
				NULL, NULL, FALSE, HIGH_PRIORITY_CLASS, NULL,
				NULL, &StartupInfo, &ProcessInfo))
			{
				WaitForSingleObject(ProcessInfo.hProcess, INFINITE);
				CloseHandle(ProcessInfo.hThread);
				CloseHandle(ProcessInfo.hProcess);
			}

			//WinExec("G:\\360MoveData\\Users\\HP\\Desktop\\nt\\IntersectProject.exe -i G:\\360MoveData\\Users\\HP\\Desktop\\nt\\input.txt -o G:\\360MoveData\\Users\\HP\\Desktop\\nt\\output.txt", SW_HIDE); 
			int result = 0;
			FILE* open = fopen("G:\\360MoveData\\Users\\HP\\Desktop\\nt\\output.txt", "r");
			fscanf(open, "%d", &result);
			fclose(open);
			Assert::AreEqual(2, result);

		};
		TEST_METHOD(TestMethod31)
		{
			FILE* stream1;
			FILE* stream2;
			freopen_s(&stream1, "G:\\360MoveData\\Users\\HP\\Desktop\\nt\\input.txt", "w", stdout);
			printf("%d\n", 4);
			printf("C 2 2 2\n");
			printf("L 0 4 2 4\n");
			printf("L 0 0 1 0\n");
			printf("S 2 0 2 2\n");
			fclose(stdout);
			PROCESS_INFORMATION ProcessInfo;
			STARTUPINFO StartupInfo; //入口参数
			ZeroMemory(&StartupInfo, sizeof(StartupInfo));
			StartupInfo.cb = sizeof StartupInfo; //分配大小
			if (CreateProcess("G:\\360MoveData\\Users\\HP\\Desktop\\nt\\IntersectProject.exe", "G:\\360MoveData\\Users\\HP\\Desktop\\nt\\IntersectProject.exe -i G:\\360MoveData\\Users\\HP\\Desktop\\nt\\input.txt -o G:\\360MoveData\\Users\\HP\\Desktop\\nt\\output.txt",
				NULL, NULL, FALSE, HIGH_PRIORITY_CLASS, NULL,
				NULL, &StartupInfo, &ProcessInfo))
			{
				WaitForSingleObject(ProcessInfo.hProcess, INFINITE);
				CloseHandle(ProcessInfo.hThread);
				CloseHandle(ProcessInfo.hProcess);
			}

			//WinExec("G:\\360MoveData\\Users\\HP\\Desktop\\nt\\IntersectProject.exe -i G:\\360MoveData\\Users\\HP\\Desktop\\nt\\input.txt -o G:\\360MoveData\\Users\\HP\\Desktop\\nt\\output.txt", SW_HIDE); 
			int result = 0;
			FILE* open = fopen("G:\\360MoveData\\Users\\HP\\Desktop\\nt\\output.txt", "r");
			fscanf(open, "%d", &result);
			fclose(open);
			Assert::AreEqual(2, result);
		};
		TEST_METHOD(TestMethod32)
		{
			FILE* stream1;
			FILE* stream2;
			freopen_s(&stream1, "G:\\360MoveData\\Users\\HP\\Desktop\\nt\\input.txt", "w", stdout);
			printf("%d\n", 4);
			printf("C 2 2 2\n");
			printf("L 0 4 2 4\n");
			printf("L 0 0 1 0\n");
			printf("S 2 0 2 4\n");
			fclose(stdout);
			PROCESS_INFORMATION ProcessInfo;
			STARTUPINFO StartupInfo; //入口参数
			ZeroMemory(&StartupInfo, sizeof(StartupInfo));
			StartupInfo.cb = sizeof StartupInfo; //分配大小
			if (CreateProcess("G:\\360MoveData\\Users\\HP\\Desktop\\nt\\IntersectProject.exe", "G:\\360MoveData\\Users\\HP\\Desktop\\nt\\IntersectProject.exe -i G:\\360MoveData\\Users\\HP\\Desktop\\nt\\input.txt -o G:\\360MoveData\\Users\\HP\\Desktop\\nt\\output.txt",
				NULL, NULL, FALSE, HIGH_PRIORITY_CLASS, NULL,
				NULL, &StartupInfo, &ProcessInfo))
			{
				WaitForSingleObject(ProcessInfo.hProcess, INFINITE);
				CloseHandle(ProcessInfo.hThread);
				CloseHandle(ProcessInfo.hProcess);
			}

			//WinExec("G:\\360MoveData\\Users\\HP\\Desktop\\nt\\IntersectProject.exe -i G:\\360MoveData\\Users\\HP\\Desktop\\nt\\input.txt -o G:\\360MoveData\\Users\\HP\\Desktop\\nt\\output.txt", SW_HIDE); 
			int result = 0;
			FILE* open = fopen("G:\\360MoveData\\Users\\HP\\Desktop\\nt\\output.txt", "r");
			fscanf(open, "%d", &result);
			fclose(open);
			Assert::AreEqual(2, result);
		};
		TEST_METHOD(TestMethod33)
		{
			FILE* stream1;
			FILE* stream2;
			freopen_s(&stream1, "G:\\360MoveData\\Users\\HP\\Desktop\\nt\\input.txt", "w", stdout);
			printf("%d\n", 5);
			printf("C 2 2 2\n");
			printf("C 6 2 2\n");
			printf("L 0 4 2 4\n");
			printf("L 0 0 1 0\n");
			printf("S 2 0 2 4\n");
			fclose(stdout);
			PROCESS_INFORMATION ProcessInfo;
			STARTUPINFO StartupInfo; //入口参数
			ZeroMemory(&StartupInfo, sizeof(StartupInfo));
			StartupInfo.cb = sizeof StartupInfo; //分配大小
			if (CreateProcess("G:\\360MoveData\\Users\\HP\\Desktop\\nt\\IntersectProject.exe", "G:\\360MoveData\\Users\\HP\\Desktop\\nt\\IntersectProject.exe -i G:\\360MoveData\\Users\\HP\\Desktop\\nt\\input.txt -o G:\\360MoveData\\Users\\HP\\Desktop\\nt\\output.txt",
				NULL, NULL, FALSE, HIGH_PRIORITY_CLASS, NULL,
				NULL, &StartupInfo, &ProcessInfo))
			{
				WaitForSingleObject(ProcessInfo.hProcess, INFINITE);
				CloseHandle(ProcessInfo.hThread);
				CloseHandle(ProcessInfo.hProcess);
			}

			//WinExec("G:\\360MoveData\\Users\\HP\\Desktop\\nt\\IntersectProject.exe -i G:\\360MoveData\\Users\\HP\\Desktop\\nt\\input.txt -o G:\\360MoveData\\Users\\HP\\Desktop\\nt\\output.txt", SW_HIDE); 
			int result = 0;
			FILE* open = fopen("G:\\360MoveData\\Users\\HP\\Desktop\\nt\\output.txt", "r");
			fscanf(open, "%d", &result);
			fclose(open);
			Assert::AreEqual(5, result);

		};
		TEST_METHOD(TestMethod34)
		{
			FILE* stream1;
			FILE* stream2;
			freopen_s(&stream1, "G:\\360MoveData\\Users\\HP\\Desktop\\nt\\input.txt", "w", stdout);
			printf("%d\n", 5);
			printf("C 2 2 2\n");
			printf("C 6 2 2\n");
			printf("L 0 4 2 4\n");
			printf("L 0 0 1 0\n");
			printf("L 4 0 4 4\n");
			fclose(stdout);
			PROCESS_INFORMATION ProcessInfo;
			STARTUPINFO StartupInfo; //入口参数
			ZeroMemory(&StartupInfo, sizeof(StartupInfo));
			StartupInfo.cb = sizeof StartupInfo; //分配大小
			if (CreateProcess("G:\\360MoveData\\Users\\HP\\Desktop\\nt\\IntersectProject.exe", "G:\\360MoveData\\Users\\HP\\Desktop\\nt\\IntersectProject.exe -i G:\\360MoveData\\Users\\HP\\Desktop\\nt\\input.txt -o G:\\360MoveData\\Users\\HP\\Desktop\\nt\\output.txt",
				NULL, NULL, FALSE, HIGH_PRIORITY_CLASS, NULL,
				NULL, &StartupInfo, &ProcessInfo))
			{
				WaitForSingleObject(ProcessInfo.hProcess, INFINITE);
				CloseHandle(ProcessInfo.hThread);
				CloseHandle(ProcessInfo.hProcess);
			}

			//WinExec("G:\\360MoveData\\Users\\HP\\Desktop\\nt\\IntersectProject.exe -i G:\\360MoveData\\Users\\HP\\Desktop\\nt\\input.txt -o G:\\360MoveData\\Users\\HP\\Desktop\\nt\\output.txt", SW_HIDE); 
			int result = 0;
			FILE* open = fopen("G:\\360MoveData\\Users\\HP\\Desktop\\nt\\output.txt", "r");
			fscanf(open, "%d", &result);
			fclose(open);
			Assert::AreEqual(7, result);

		};
		TEST_METHOD(TestMethod35)
		{
			FILE* stream1;
			FILE* stream2;
			freopen_s(&stream1, "G:\\360MoveData\\Users\\HP\\Desktop\\nt\\input.txt", "w", stdout);
			printf("%d\n", 6);
			printf("C 2 2 2\n");
			printf("C 6 2 2\n");
			printf("L 0 4 2 4\n");
			printf("L 0 0 1 0\n");
			printf("L 4 0 4 4\n");
			printf("L 0 7 1 5\n");
			fclose(stdout);
			PROCESS_INFORMATION ProcessInfo;
			STARTUPINFO StartupInfo; //入口参数
			ZeroMemory(&StartupInfo, sizeof(StartupInfo));
			StartupInfo.cb = sizeof StartupInfo; //分配大小
			if (CreateProcess("G:\\360MoveData\\Users\\HP\\Desktop\\nt\\IntersectProject.exe", "G:\\360MoveData\\Users\\HP\\Desktop\\nt\\IntersectProject.exe -i G:\\360MoveData\\Users\\HP\\Desktop\\nt\\input.txt -o G:\\360MoveData\\Users\\HP\\Desktop\\nt\\output.txt",
				NULL, NULL, FALSE, HIGH_PRIORITY_CLASS, NULL,
				NULL, &StartupInfo, &ProcessInfo))
			{
				WaitForSingleObject(ProcessInfo.hProcess, INFINITE);
				CloseHandle(ProcessInfo.hThread);
				CloseHandle(ProcessInfo.hProcess);
			}

			//WinExec("G:\\360MoveData\\Users\\HP\\Desktop\\nt\\IntersectProject.exe -i G:\\360MoveData\\Users\\HP\\Desktop\\nt\\input.txt -o G:\\360MoveData\\Users\\HP\\Desktop\\nt\\output.txt", SW_HIDE); 
			int result = 0;
			FILE* open = fopen("G:\\360MoveData\\Users\\HP\\Desktop\\nt\\output.txt", "r");
			fscanf(open, "%d", &result);
			fclose(open);
			Assert::AreEqual(12, result);
		};
		TEST_METHOD(TestMethod36)
		{
			FILE* stream1;
			FILE* stream2;
			freopen_s(&stream1, "G:\\360MoveData\\Users\\HP\\Desktop\\nt\\input.txt", "w", stdout);
			printf("%d\n", 6);
			printf("C 2 2 2\n");
			printf("C 6 2 2\n");
			printf("L 0 4 2 4\n");
			printf("L 0 0 1 0\n");
			printf("L 4 0 4 4\n");
			printf("L 0 10 1 8\n");
			fclose(stdout);
			PROCESS_INFORMATION ProcessInfo;
			STARTUPINFO StartupInfo; //入口参数
			ZeroMemory(&StartupInfo, sizeof(StartupInfo));
			StartupInfo.cb = sizeof StartupInfo; //分配大小
			if (CreateProcess("G:\\360MoveData\\Users\\HP\\Desktop\\nt\\IntersectProject.exe", "G:\\360MoveData\\Users\\HP\\Desktop\\nt\\IntersectProject.exe -i G:\\360MoveData\\Users\\HP\\Desktop\\nt\\input.txt -o G:\\360MoveData\\Users\\HP\\Desktop\\nt\\output.txt",
				NULL, NULL, FALSE, HIGH_PRIORITY_CLASS, NULL,
				NULL, &StartupInfo, &ProcessInfo))
			{
				WaitForSingleObject(ProcessInfo.hProcess, INFINITE);
				CloseHandle(ProcessInfo.hThread);
				CloseHandle(ProcessInfo.hProcess);
			}

			//WinExec("G:\\360MoveData\\Users\\HP\\Desktop\\nt\\IntersectProject.exe -i G:\\360MoveData\\Users\\HP\\Desktop\\nt\\input.txt -o G:\\360MoveData\\Users\\HP\\Desktop\\nt\\output.txt", SW_HIDE); 
			int result = 0;
			FILE* open = fopen("G:\\360MoveData\\Users\\HP\\Desktop\\nt\\output.txt", "r");
			fscanf(open, "%d", &result);
			fclose(open);
			Assert::AreEqual(11, result);

		};
		TEST_METHOD(TestMethod37)
		{
			FILE* stream1;
			FILE* stream2;
			freopen_s(&stream1, "G:\\360MoveData\\Users\\HP\\Desktop\\nt\\input.txt", "w", stdout);
			printf("%d\n", 6);
			printf("C 2 2 2\n");
			printf("C 6 2 2\n");
			printf("L 0 4 2 4\n");
			printf("L 0 0 1 0\n");
			printf("L 4 0 4 4\n");
			printf("S 2 2 6 4\n");
			fclose(stdout);
			PROCESS_INFORMATION ProcessInfo;
			STARTUPINFO StartupInfo; //入口参数
			ZeroMemory(&StartupInfo, sizeof(StartupInfo));
			StartupInfo.cb = sizeof StartupInfo; //分配大小
			if (CreateProcess("G:\\360MoveData\\Users\\HP\\Desktop\\nt\\IntersectProject.exe", "G:\\360MoveData\\Users\\HP\\Desktop\\nt\\IntersectProject.exe -i G:\\360MoveData\\Users\\HP\\Desktop\\nt\\input.txt -o G:\\360MoveData\\Users\\HP\\Desktop\\nt\\output.txt",
				NULL, NULL, FALSE, HIGH_PRIORITY_CLASS, NULL,
				NULL, &StartupInfo, &ProcessInfo))
			{
				WaitForSingleObject(ProcessInfo.hProcess, INFINITE);
				CloseHandle(ProcessInfo.hThread);
				CloseHandle(ProcessInfo.hProcess);
			}

			//WinExec("G:\\360MoveData\\Users\\HP\\Desktop\\nt\\IntersectProject.exe -i G:\\360MoveData\\Users\\HP\\Desktop\\nt\\input.txt -o G:\\360MoveData\\Users\\HP\\Desktop\\nt\\output.txt", SW_HIDE); 
			int result = 0;
			FILE* open = fopen("G:\\360MoveData\\Users\\HP\\Desktop\\nt\\output.txt", "r");
			fscanf(open, "%d", &result);
			fclose(open);
			Assert::AreEqual(10, result);

		};
		TEST_METHOD(TestMethod38)
		{
			FILE* stream1;
			FILE* stream2;
			freopen_s(&stream1, "G:\\360MoveData\\Users\\HP\\Desktop\\nt\\input.txt", "w", stdout);
			printf("%d\n", 6);
			printf("C 2 2 2\n");
			printf("C 6 2 2\n");
			printf("L 0 4 2 4\n");
			printf("L 0 0 1 0\n");
			printf("L 4 0 4 4\n");
			printf("S 2 2 6 2\n");
			fclose(stdout);
			PROCESS_INFORMATION ProcessInfo;
			STARTUPINFO StartupInfo; //入口参数
			ZeroMemory(&StartupInfo, sizeof(StartupInfo));
			StartupInfo.cb = sizeof StartupInfo; //分配大小
			if (CreateProcess("G:\\360MoveData\\Users\\HP\\Desktop\\nt\\IntersectProject.exe", "G:\\360MoveData\\Users\\HP\\Desktop\\nt\\IntersectProject.exe -i G:\\360MoveData\\Users\\HP\\Desktop\\nt\\input.txt -o G:\\360MoveData\\Users\\HP\\Desktop\\nt\\output.txt",
				NULL, NULL, FALSE, HIGH_PRIORITY_CLASS, NULL,
				NULL, &StartupInfo, &ProcessInfo))
			{
				WaitForSingleObject(ProcessInfo.hProcess, INFINITE);
				CloseHandle(ProcessInfo.hThread);
				CloseHandle(ProcessInfo.hProcess);
			}

			//WinExec("G:\\360MoveData\\Users\\HP\\Desktop\\nt\\IntersectProject.exe -i G:\\360MoveData\\Users\\HP\\Desktop\\nt\\input.txt -o G:\\360MoveData\\Users\\HP\\Desktop\\nt\\output.txt", SW_HIDE); 
			int result = 0;
			FILE* open = fopen("G:\\360MoveData\\Users\\HP\\Desktop\\nt\\output.txt", "r");
			fscanf(open, "%d", &result);
			fclose(open);
			Assert::AreEqual(7, result);

		};
		TEST_METHOD(TestMethod39)
		{
			FILE* stream1;
			FILE* stream2;
			freopen_s(&stream1, "G:\\360MoveData\\Users\\HP\\Desktop\\nt\\input.txt", "w", stdout);
			printf("%d\n", 4);
			printf("C 2 2 2\n");
			printf("C 6 2 2\n");
			printf("L 0 0 1 0\n");
			printf("S 1 4 3 4\n");
			fclose(stdout);
			PROCESS_INFORMATION ProcessInfo;
			STARTUPINFO StartupInfo; //入口参数
			ZeroMemory(&StartupInfo, sizeof(StartupInfo));
			StartupInfo.cb = sizeof StartupInfo; //分配大小
			if (CreateProcess("G:\\360MoveData\\Users\\HP\\Desktop\\nt\\IntersectProject.exe", "G:\\360MoveData\\Users\\HP\\Desktop\\nt\\IntersectProject.exe -i G:\\360MoveData\\Users\\HP\\Desktop\\nt\\input.txt -o G:\\360MoveData\\Users\\HP\\Desktop\\nt\\output.txt",
				NULL, NULL, FALSE, HIGH_PRIORITY_CLASS, NULL,
				NULL, &StartupInfo, &ProcessInfo))
			{
				WaitForSingleObject(ProcessInfo.hProcess, INFINITE);
				CloseHandle(ProcessInfo.hThread);
				CloseHandle(ProcessInfo.hProcess);
			}

			//WinExec("G:\\360MoveData\\Users\\HP\\Desktop\\nt\\IntersectProject.exe -i G:\\360MoveData\\Users\\HP\\Desktop\\nt\\input.txt -o G:\\360MoveData\\Users\\HP\\Desktop\\nt\\output.txt", SW_HIDE); 
			int result = 0;
			FILE* open = fopen("G:\\360MoveData\\Users\\HP\\Desktop\\nt\\output.txt", "r");
			fscanf(open, "%d", &result);
			fclose(open);
			Assert::AreEqual(4, result);

		};
		TEST_METHOD(TestMethod40)
		{
			FILE* stream1;
			FILE* stream2;
			freopen_s(&stream1, "G:\\360MoveData\\Users\\HP\\Desktop\\nt\\input.txt", "w", stdout);
			printf("%d\n", 5);
			printf("C 2 2 2\n");
			printf("C 6 2 2\n");
			printf("L 0 0 1 0\n");
			printf("S 1 4 3 4\n");
			printf("L 1 4 11 37\n");
			fclose(stdout);
			PROCESS_INFORMATION ProcessInfo;
			STARTUPINFO StartupInfo; //入口参数
			ZeroMemory(&StartupInfo, sizeof(StartupInfo));
			StartupInfo.cb = sizeof StartupInfo; //分配大小
			if (CreateProcess("G:\\360MoveData\\Users\\HP\\Desktop\\nt\\IntersectProject.exe", "G:\\360MoveData\\Users\\HP\\Desktop\\nt\\IntersectProject.exe -i G:\\360MoveData\\Users\\HP\\Desktop\\nt\\input.txt -o G:\\360MoveData\\Users\\HP\\Desktop\\nt\\output.txt",
				NULL, NULL, FALSE, HIGH_PRIORITY_CLASS, NULL,
				NULL, &StartupInfo, &ProcessInfo))
			{
				WaitForSingleObject(ProcessInfo.hProcess, INFINITE);
				CloseHandle(ProcessInfo.hThread);
				CloseHandle(ProcessInfo.hProcess);
			}

			//WinExec("G:\\360MoveData\\Users\\HP\\Desktop\\nt\\IntersectProject.exe -i G:\\360MoveData\\Users\\HP\\Desktop\\nt\\input.txt -o G:\\360MoveData\\Users\\HP\\Desktop\\nt\\output.txt", SW_HIDE); 
			int result = 0;
			FILE* open = fopen("G:\\360MoveData\\Users\\HP\\Desktop\\nt\\output.txt", "r");
			fscanf(open, "%d", &result);
			fclose(open);
			Assert::AreEqual(8, result);

		};
		TEST_METHOD(TestMethod41)
		{
			FILE* stream1;
			freopen_s(&stream1, "G:\\360MoveData\\Users\\HP\\Desktop\\nt\\input.txt", "w", stdout);
			printf("%d\n", 5);
			printf("C 2 2 2\n");
			printf("C 6 2 2\n");
			printf("L 0 0 1 0\n");
			printf("R 1 4 3 4\n");
			printf("L 1 4 11 37\n");
			fclose(stdout);
			PROCESS_INFORMATION ProcessInfo;
			STARTUPINFO StartupInfo; //入口参数
			ZeroMemory(&StartupInfo, sizeof(StartupInfo));
			StartupInfo.cb = sizeof StartupInfo; //分配大小
			if (CreateProcess("G:\\360MoveData\\Users\\HP\\Desktop\\nt\\IntersectProject.exe", "G:\\360MoveData\\Users\\HP\\Desktop\\nt\\IntersectProject.exe -i G:\\360MoveData\\Users\\HP\\Desktop\\nt\\input.txt -o G:\\360MoveData\\Users\\HP\\Desktop\\nt\\output.txt",
				NULL, NULL, FALSE, HIGH_PRIORITY_CLASS, NULL,
				NULL, &StartupInfo, &ProcessInfo))
			{
				WaitForSingleObject(ProcessInfo.hProcess, INFINITE);
				CloseHandle(ProcessInfo.hThread);
				CloseHandle(ProcessInfo.hProcess);
			}

			//WinExec("G:\\360MoveData\\Users\\HP\\Desktop\\nt\\IntersectProject.exe -i G:\\360MoveData\\Users\\HP\\Desktop\\nt\\input.txt -o G:\\360MoveData\\Users\\HP\\Desktop\\nt\\output.txt", SW_HIDE); 
			int result = 0;
			FILE* open = fopen("G:\\360MoveData\\Users\\HP\\Desktop\\nt\\output.txt", "r");
			fscanf(open, "%d", &result);
			fclose(open);
			Assert::AreEqual(9, result);

		};
		TEST_METHOD(TestMethod42)
		{
			FILE* stream1;
			freopen_s(&stream1, "G:\\360MoveData\\Users\\HP\\Desktop\\nt\\input.txt", "wt", stdout);
			printf("%d\n", 4);
			printf("C 3 3 3\n");
			printf("S 2 4 3 2\n");
			printf("L -1 4 5 2\n");
			printf("R 2 5 -1 2\n");
			fclose(stdout);
			PROCESS_INFORMATION ProcessInfo;
			STARTUPINFO StartupInfo; //入口参数
			ZeroMemory(&StartupInfo, sizeof(StartupInfo));
			StartupInfo.cb = sizeof StartupInfo; //分配大小
			if (CreateProcess("G:\\360MoveData\\Users\\HP\\Desktop\\nt\\IntersectProject.exe", "G:\\360MoveData\\Users\\HP\\Desktop\\nt\\IntersectProject.exe -i G:\\360MoveData\\Users\\HP\\Desktop\\nt\\input.txt -o G:\\360MoveData\\Users\\HP\\Desktop\\nt\\output.txt",
				NULL, NULL, FALSE, HIGH_PRIORITY_CLASS, NULL,
				NULL, &StartupInfo, &ProcessInfo))
			{
				WaitForSingleObject(ProcessInfo.hProcess, INFINITE);
				CloseHandle(ProcessInfo.hThread);
				CloseHandle(ProcessInfo.hProcess);
			}

			//WinExec("G:\\360MoveData\\Users\\HP\\Desktop\\nt\\IntersectProject.exe -i G:\\360MoveData\\Users\\HP\\Desktop\\nt\\input.txt -o G:\\360MoveData\\Users\\HP\\Desktop\\nt\\output.txt", SW_HIDE); 
			int result = 0;
			FILE* open = fopen("G:\\360MoveData\\Users\\HP\\Desktop\\nt\\output.txt", "r");
			fscanf(open, "%d", &result);
			fclose(open);
			Assert::AreEqual(5, result);

		};
		TEST_METHOD(TestMethod43)
		{
			FILE* stream1;
			freopen_s(&stream1, "G:\\360MoveData\\Users\\HP\\Desktop\\nt\\input.txt", "wt", stdout);
			printf("%d\n", 6);
			printf("C 2 2 2\n");
			printf("C 2 2 3\n");
			printf("C 2 2 4\n");
			printf("L 0 2 2 2\n");
			printf("S 0 0 2 5\n");
			printf("L 0 0 1 1\n");
			fclose(stdout);
			PROCESS_INFORMATION ProcessInfo;
			STARTUPINFO StartupInfo; //入口参数
			ZeroMemory(&StartupInfo, sizeof(StartupInfo));
			StartupInfo.cb = sizeof StartupInfo; //分配大小
			if (CreateProcess("G:\\360MoveData\\Users\\HP\\Desktop\\nt\\IntersectProject.exe", "G:\\360MoveData\\Users\\HP\\Desktop\\nt\\IntersectProject.exe -i G:\\360MoveData\\Users\\HP\\Desktop\\nt\\input.txt -o G:\\360MoveData\\Users\\HP\\Desktop\\nt\\output.txt",
				NULL, NULL, FALSE, HIGH_PRIORITY_CLASS, NULL,
				NULL, &StartupInfo, &ProcessInfo))
			{
				WaitForSingleObject(ProcessInfo.hProcess, INFINITE);
				CloseHandle(ProcessInfo.hThread);
				CloseHandle(ProcessInfo.hProcess);
			}

			//WinExec("G:\\360MoveData\\Users\\HP\\Desktop\\nt\\IntersectProject.exe -i G:\\360MoveData\\Users\\HP\\Desktop\\nt\\input.txt -o G:\\360MoveData\\Users\\HP\\Desktop\\nt\\output.txt", SW_HIDE); 
			int result = 0;
			FILE* open = fopen("G:\\360MoveData\\Users\\HP\\Desktop\\nt\\output.txt", "r");
			fscanf(open, "%d", &result);
			fclose(open);
			Assert::AreEqual(18, result);

		};
		TEST_METHOD(TestMethod44)
		{
			FILE* stream1;
			freopen_s(&stream1, "G:\\360MoveData\\Users\\HP\\Desktop\\nt\\input.txt", "wt", stdout);
			printf("%d\n", 7);
			printf("C 2 2 2\n");
			printf("C 2 2 3\n");
			printf("C 2 2 4\n");
			printf("C 4 2 2\n");
			printf("L 0 2 2 2\n");
			printf("S 0 0 2 5\n");
			printf("L 0 0 1 1\n");
			fclose(stdout);
			PROCESS_INFORMATION ProcessInfo;
			STARTUPINFO StartupInfo; //入口参数
			ZeroMemory(&StartupInfo, sizeof(StartupInfo));
			StartupInfo.cb = sizeof StartupInfo; //分配大小
			if (CreateProcess("G:\\360MoveData\\Users\\HP\\Desktop\\nt\\IntersectProject.exe", "G:\\360MoveData\\Users\\HP\\Desktop\\nt\\IntersectProject.exe -i G:\\360MoveData\\Users\\HP\\Desktop\\nt\\input.txt -o G:\\360MoveData\\Users\\HP\\Desktop\\nt\\output.txt",
				NULL, NULL, FALSE, HIGH_PRIORITY_CLASS, NULL,
				NULL, &StartupInfo, &ProcessInfo))
			{
				WaitForSingleObject(ProcessInfo.hProcess, INFINITE);
				CloseHandle(ProcessInfo.hThread);
				CloseHandle(ProcessInfo.hProcess);
			}

			//WinExec("G:\\360MoveData\\Users\\HP\\Desktop\\nt\\IntersectProject.exe -i G:\\360MoveData\\Users\\HP\\Desktop\\nt\\input.txt -o G:\\360MoveData\\Users\\HP\\Desktop\\nt\\output.txt", SW_HIDE); 
			int result = 0;
			FILE* open = fopen("G:\\360MoveData\\Users\\HP\\Desktop\\nt\\output.txt", "r");
			fscanf(open, "%d", &result);
			fclose(open);
			Assert::AreEqual(23, result);

		};
		TEST_METHOD(TestMethod45)
		{
			FILE* stream1;
			freopen_s(&stream1, "G:\\360MoveData\\Users\\HP\\Desktop\\nt\\input.txt", "wt", stdout);
			printf("%d\n", 2);
			printf("S 0 0 2 5\n");
			printf("R 0 0 1 1\n");
			fclose(stdout);
			PROCESS_INFORMATION ProcessInfo;
			STARTUPINFO StartupInfo; //入口参数
			ZeroMemory(&StartupInfo, sizeof(StartupInfo));
			StartupInfo.cb = sizeof StartupInfo; //分配大小
			if (CreateProcess("G:\\360MoveData\\Users\\HP\\Desktop\\nt\\IntersectProject.exe", "G:\\360MoveData\\Users\\HP\\Desktop\\nt\\IntersectProject.exe -i G:\\360MoveData\\Users\\HP\\Desktop\\nt\\input.txt -o G:\\360MoveData\\Users\\HP\\Desktop\\nt\\output.txt",
				NULL, NULL, FALSE, HIGH_PRIORITY_CLASS, NULL,
				NULL, &StartupInfo, &ProcessInfo))
			{
				WaitForSingleObject(ProcessInfo.hProcess, INFINITE);
				CloseHandle(ProcessInfo.hThread);
				CloseHandle(ProcessInfo.hProcess);
			}
			//WinExec("G:\\360MoveData\\Users\\HP\\Desktop\\nt\\IntersectProject.exe -i G:\\360MoveData\\Users\\HP\\Desktop\\nt\\input.txt -o G:\\360MoveData\\Users\\HP\\Desktop\\nt\\output.txt", SW_HIDE); 
			int result = 0;
			FILE* open = fopen("G:\\360MoveData\\Users\\HP\\Desktop\\nt\\output.txt", "r");
			fscanf(open, "%d", &result);
			fclose(open);
			Assert::AreEqual(1, result);

		};
		TEST_METHOD(TestMethod50) {
			vector <Shape*> allshape1;
			unordered_set<Point*, Hash_Point, Equal_Point> allpoint1;
			allshape1.emplace_back(ShapeFactory::GetShape("C 3 3 3", 1));
			allshape1.emplace_back(ShapeFactory::GetShape("S 2 4 3 2", 1));
			allshape1.emplace_back(ShapeFactory::GetShape("L -1 4 5 2", 1));
			allshape1.emplace_back(ShapeFactory::GetShape("R 2 5 -1 2", 1));
			GetPoint(allshape1, allpoint1);
			Assert::AreEqual(5, (int)allpoint1.size());
		}
		TEST_METHOD(TestMethod51)
		{
			FILE* stream1, *stream2;
			vector <Shape*> allshape1;
			unordered_set<Point*, Hash_Point, Equal_Point> allpoint1;
			freopen_s(&stream1, "G:\\360MoveData\\Users\\HP\\Desktop\\nt\\input.txt", "wt", stdout);
			printf("%d\n", 7);
			printf("C 2 2 2\n");
			printf("C 2 2 3\n");
			printf("C 2 2 4\n");
			printf("C 4 2 2\n");
			printf("L 0 2 2 2\n");
			printf("S 0 0 2 5\n");
			printf("L 0 0 1 1\n");
			fclose(stdout);
			freopen_s(&stream2, "G:\\360MoveData\\Users\\HP\\Desktop\\nt\\input.txt", "r", stdin);
			InputProcess(allshape1);
			GetPoint(allshape1, allpoint1);
			fclose(stdin);
			Assert::AreEqual(23, (int)allpoint1.size());

		};
		TEST_METHOD(TestMethod52)
		{
			FILE* stream1, * stream2;
			vector <Shape*> allshape1;
			unordered_set<Point*, Hash_Point, Equal_Point> allpoint1;
			freopen_s(&stream1, "G:\\360MoveData\\Users\\HP\\Desktop\\nt\\input.txt", "wt", stdout);
			printf("%d\n", 4);
			printf("C 3 3 3\n");
			printf("S 2 4 3 2\n");
			printf("L -1 4 5 2\n");
			printf("R 2 5 -1 2\n");
			fclose(stdout);
			fclose(stdout);
			freopen_s(&stream2, "G:\\360MoveData\\Users\\HP\\Desktop\\nt\\input.txt", "r", stdin);
			InputProcess(allshape1);
			GetPoint(allshape1, allpoint1);
			fclose(stdin);
			Assert::AreEqual(5, (int)allpoint1.size());

		};
	};
}
