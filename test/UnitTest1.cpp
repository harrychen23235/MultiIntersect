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
		
	};
}
