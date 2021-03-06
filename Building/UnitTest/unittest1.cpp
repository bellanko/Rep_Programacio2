#include "stdafx.h"
#include "CppUnitTest.h"

#include "../Programació 2/point2D.h"
#include "../Programació 2/Projectile.h"
#include "../Programació 2/String.h"
#include "../Programació 2/DynArray.h"
#include "../Programació 2/DLinked_List.h"
#include "../Programació 2/Stack.h"
#include "../Programació 2/Qeue.h"


using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{	

	// point2D ----------------------------------------
	TEST_CLASS(point2DClass)
	{
	public:

		TEST_METHOD(point2D_operatorPlus)
		{
			point2D p1;
			point2D p2;
			point2D result;

			p1.x = 1.f;
			p1.y = 4.f;

			p2.x = 2.f;
			p2.y = 5.f;

			result = p1 + p2;

			Assert::AreEqual(result.x, 3.f);
			Assert::AreEqual(result.y, 9.f);
		}

		TEST_METHOD(point2D_operatorRes)
		{
			point2D p1;
			point2D p2;
			point2D result;

			p1.x = 4;
			p1.y = 6;

			p2.x = 2;
			p2.y = 5;

			result = p1 - p2;

			Assert::AreEqual(result.x, 2.f);
			Assert::AreEqual(result.y, 1.f);
		}

		TEST_METHOD(point2D_operatorPlusEq)
		{
			point2D p1;
			point2D p2;

			p1.x = 4;
			p1.y = 6;

			p2.x = 2;
			p2.y = 5;

			p1 += p2;

			Assert::AreEqual(p1.x, 6.f);
			Assert::AreEqual(p1.y, 11.f);
		}

		TEST_METHOD(point2D_operatorResEq)
		{
			point2D p1;
			point2D p2;

			p1.x = 4;
			p1.y = 6;

			p2.x = 2;
			p2.y = 5;

			p1 -= p2;

			Assert::AreEqual(p1.x, 2.f);
			Assert::AreEqual(p1.y, 1.f);
		}

		TEST_METHOD(point2D_operatorEqEq)
		{
			point2D p1;
			point2D p2;

			p1.x = 4;
			p1.y = 6;

			p2.x = 4;
			p2.y = 6;

			Assert::IsTrue(p1 == p2);
		}

		TEST_METHOD(point2D_operatorDifEq)
		{
			point2D p1;
			point2D p2;

			p1.x = 4;
			p1.y = 6;

			p2.x = 4;
			p2.y = 3;

			Assert::IsTrue(p1 != p2);
		}

		TEST_METHOD(point2D_setZero)
		{
			point2D p1;

			p1.x = 4;
			p1.y = 6;

			p1.setZero();

			Assert::AreEqual(p1.x, 0.f);
			Assert::AreEqual(p1.y, 0.f);
		}

		TEST_METHOD(point2D_isZero)
		{
			point2D p1;

			p1.x = 4;
			p1.y = 6;

			p1.setZero();

			Assert::IsTrue(p1.isZero());
		}

		TEST_METHOD(point2D_distanceTo)
		{
			point2D p1;
			point2D p2;

			p1.x = 0;
			p1.y = 0;

			p2.x = 1;
			p2.y = 1;

			Assert::AreEqual(p1.distanceTo(p2), 2.f);
		}
	};

	// Projectile ----------------------------------------
	TEST_CLASS(ProjectileClass)
	{
	public:

		TEST_METHOD(Projectile_getCurrentPosition)

		{
			Projectile p;

			p.point.x = 10.0f;

			p.point.y = 10.0f;

			p.speed.x = 2.0f;

			p.speed.y = 0.0f;

			point2D current = p.getCurrentPosition(3.0f);

			Assert::AreEqual((float)16.0f, current.x, 0.00001f);

			Assert::AreEqual((float)10.0f, current.y, 0.00001f);
		}
	};

	// String ----------------------------------------
	TEST_CLASS(StringClass)
	{
	public:

		TEST_METHOD(String_constructEmpty)
		{
			String s;

			Assert::IsTrue(s.size == 1);
			Assert::AreEqual(s.string, "\0");
		}

		TEST_METHOD(String_constructChain)
		{
			String s("%s", "hello");

			Assert::IsTrue(s.size == 6);
			Assert::AreEqual(s.string, "hello");
		}

		TEST_METHOD(String_constructChainClass)
		{
			String s("hello");
			String a(s);

			Assert::AreEqual(a.string, "hello");
		}

		TEST_METHOD(String_operatorEqualEqual)
		{
			String s("hello world");

			Assert::IsTrue(s == "hello world");
		}

		TEST_METHOD(String_operatorEqualEqualClass)
		{
			String s("hello world");
			String a("hello world");

			Assert::IsTrue(s == a);
		}

		TEST_METHOD(String_operatorNotEqual)
		{
			String s("hello world");

			Assert::IsTrue(s != "bye");
		}

		TEST_METHOD(String_operatorNotEqualClass)
		{
			String s("hello world");
			String a("bye");

			Assert::IsTrue(s != a);
		}

		TEST_METHOD(String_operatorEqual)
		{
			String s("world");
			s = "hello";

			Assert::IsTrue(s == "hello");
		}

		TEST_METHOD(String_operatorEqualClass)
		{
			String s("hello");
			String a("world");
			a = s;

			Assert::IsTrue(a == s);
		}

		TEST_METHOD(String_operatorPlusEqual)
		{
			String s("hello");

			s += " world";

			Assert::IsTrue(s == "hello world");
		}

		TEST_METHOD(String_operatorPlusEqualClass)
		{
			String s("hello");
			String a(" world");

			s += a;

			Assert::IsTrue(s == "hello world");
		}

		TEST_METHOD(String_operatorLength)
		{
			String s("hello");

			Assert::IsTrue(s.length() == 5);
		}

		TEST_METHOD(String_operatorCapacity)
		{
			String s("hello");

			Assert::IsTrue(s.capacity() == 6);
		}

		TEST_METHOD(String_operatorGetString)
		{
			String s("hello");

			Assert::AreEqual(s.getString(), "hello");
		}

		TEST_METHOD(String_operatorClear)
		{
			String s("hello");
			s.clear();

			Assert::IsTrue(s.string[0] == '\0');
		}

		TEST_METHOD(String_prefix)
		{
			String a("1234567890");
			String b(50);
			b = "hola";
			a.prefix(b);
			b.prefix("1234567890");
			Assert::AreEqual(strcmp(a.getString(), "hola1234567890"), 0);
			Assert::AreEqual(strcmp(b.getString(), "1234567890hola"), 0);
		}

		TEST_METHOD(String_find)
		{
			String s("hola mundo hola mundo hola");

			Assert::AreEqual((int)3, (int)s.find("hola"));
			Assert::AreEqual((int)2, (int)s.find("mundo"));
			Assert::AreEqual((int)0, (int)s.find("error"));
			Assert::AreEqual((int)4, (int)s.find(" "));
		}

		TEST_METHOD(String_cut)
		{
			String s1("Hola mundo");
			s1.cut(2, 5);
			Assert::AreEqual((int)strcmp("Houndo", s1.getString()), 0);
			s1.cut(3, 0);
			Assert::AreEqual((int)strcmp("Hou", s1.getString()), 0);

			String s2("Hola mundo");
			s2.cut(5, 2);
			Assert::AreEqual((int)strcmp("Houndo", s2.getString()), 0);
		}

	};


	// DynArray ----------------------------------------
	TEST_CLASS(DynArrayClass)
	{
	public:

		TEST_METHOD(DynArray_constructEmpty)
		{
			DynArray<int> array;
			Assert::AreEqual((int)array.getCapacity(), 16);
		}

		TEST_METHOD(DynArray_constructCapacity)
		{
			DynArray<int> array(33);
			Assert::AreEqual((int)array.getCapacity(), 33);
		}

		TEST_METHOD(DynArray_pushback)
		{
			DynArray<int> array;

			array.pushback(1);
			array.pushback(2);
			array.pushback(3);

			Assert::AreEqual((int)array.getCapacity(), 16);
			Assert::AreEqual((int)array.count(), 3);
		}

		TEST_METHOD(DynArray_pop)
		{
			DynArray<int> array;

			array.pushback(1);
			array.pushback(2);
			array.pushback(3);

			array.pop();

			Assert::AreEqual((int)array.getCapacity(), 16);
			Assert::AreEqual((int)array.count(), 2);
		}

		TEST_METHOD(DynArray_clear)
		{
			DynArray<int> array;

			array.pushback(1);
			array.pushback(2);
			array.pushback(3);
			array.clear();

			Assert::AreEqual((int)array.getCapacity(), 16);
			Assert::AreEqual((int)array.count(), 0);
		}


		TEST_METHOD(DynArray_operatorPop)
		{
			DynArray<int> array;

			array.pushback(1);
			array.pushback(2);
			array.pushback(3);

			Assert::AreEqual(array[0], 1);
			Assert::AreEqual(array[1], 2);
			Assert::AreEqual(array[2], 3);
		}

		TEST_METHOD(DynArray_operatorPlusEqual)
		{
			DynArray<int> array(5);

			array.pushback(1);
			array.pushback(2);
			array.pushback(4);
			array.pushback(5);
			array.pushback(8);

			DynArray<int> array2;

			array2.pushback(991);
			array2.pushback(992);
			array2.pushback(993);

			array += array2;

			Assert::AreEqual((int)array.count(), 8);
			Assert::AreEqual((int)array[0], 1);
			Assert::AreEqual((int)array[1], 2);
			Assert::AreEqual((int)array[2], 4);
			Assert::AreEqual((int)array[3], 5);
			Assert::AreEqual((int)array[4], 8);
			Assert::AreEqual((int)array[5], 991);
			Assert::AreEqual((int)array[6], 992);
			Assert::AreEqual((int)array[7], 993);
		}

		TEST_METHOD(DynArray_insert)
		{
			DynArray<int> array;

			for (int i = 0; i < 16; ++i)
			{
				array.pushback(i);
			}

			array.insert(999, 3);
			array.insert(888, 17);
			array.insert(777, 50);


			Assert::IsFalse(array.insert(777, 50));
			Assert::AreEqual((int)array.getCapacity(), 32);
			Assert::AreEqual((int)array.count(), 18);
			Assert::AreEqual((int)array[3], 999);
			Assert::AreEqual((int)array[17], 888);
		}

		TEST_METHOD(DynArray_insertDynArrayt)
		{
			DynArray<int> array(4);
			array.pushback(1);
			array.pushback(2);
			array.pushback(5);

			DynArray<int> array2(3);
			array2.pushback(3);
			array2.pushback(4);

			array.insertDynArray(array2, 2);

			Assert::AreEqual((int)1, array[0]);
			Assert::AreEqual((int)2, array[1]);
			Assert::AreEqual((int)3, array[2]);
			Assert::AreEqual((int)4, array[3]);
			Assert::AreEqual((int)5, array[4]);
		}

		TEST_METHOD(DynArray_removeWastedMemory)
		{
			DynArray<int> array(10);
			array.pushback(1);
			array.pushback(2);
			array.pushback(3);
			Assert::AreEqual((unsigned int)10, array.getCapacity());
			unsigned int wasted = array.removeWastedMemory();
			Assert::AreEqual((unsigned int)3, array.getCapacity());
			Assert::AreEqual((unsigned int)7, wasted);
			Assert::AreEqual((int)1, array[0]);
			Assert::AreEqual((int)2, array[1]);
			Assert::AreEqual((int)3, array[2]);
		}
	};


	// DLinkedList ----------------------------------------
	TEST_CLASS(DLinked_ListClass)
	{
	public:

		// P2List delete few nodes ----------------------------------------
		TEST_METHOD(DoubleLinkedList_delNodes_mid)
		{
			DSList<int> l;
			l.add(1);
			l.add(2);
			l.add(3);
			l.add(4);
			l.delNodes(1, 2);
			Assert::AreEqual((int)1, l.start->value);
			Assert::AreEqual((int)4, l.end->value);
			Assert::AreEqual((unsigned int)2, l.count());
		}
		// P2List delete few nodes ----------------------------------------
		TEST_METHOD(DoubleLinkedList_delNodes_begin)
		{
			DSList<int> l;
			l.add(1);
			l.add(2);
			l.add(3);
			l.add(4);
			l.delNodes(0, 3);
			Assert::AreEqual((int)4, l.start->value);
			Assert::AreEqual((int)4, l.end->value);
			Assert::AreEqual((unsigned int)1, l.count());
		}
		// P2List delete few nodes ----------------------------------------
		TEST_METHOD(DoubleLinkedList_delNodes_end)
		{
			DSList<int> l;
			l.add(1);
			l.add(2);
			l.add(3);
			l.add(4);
			l.delNodes(2, 100);
			Assert::AreEqual((int)1, l.start->value);
			Assert::AreEqual((int)2, l.end->value);
			Assert::AreEqual((unsigned int)2, l.count());
		}

		TEST_METHOD(DoubleLinkedList_operator_Test)
		{
			DSList<int> array;
			array.add(3);
			array.add(2);
			array.add(1);

			Assert::AreEqual((int)3, array[0]);
			Assert::AreEqual((int)2, array[1]);
			Assert::AreEqual((int)1, array[2]);
		}

		TEST_METHOD(DoubleLinkedList_BubbleSort_Test)
		{
			DSList<int> array;
			array.add(1);
			array.add(3);
			array.add(2);

			array.DoBubbleSort();


			Assert::AreEqual((int)1, array[0]);
			Assert::AreEqual((int)2, array[1]);
			Assert::AreEqual((int)3, array[2]);
		}

		TEST_METHOD(DoubleLinkedList_operatorPlusEqualTest)
		{
			DSList<int> a;
			a.add(1);
			a.add(2);
			a.add(3);

			DSList<int> b;
			b.add(4);
			b.add(5);
			b.add(6);

			a += b;

			Assert::AreEqual((int)1, a[0]);
			Assert::AreEqual((int)2, a[1]);
			Assert::AreEqual((int)3, a[2]);
			Assert::AreEqual((int)4, a[3]);
			Assert::AreEqual((int)5, a[4]);
			Assert::AreEqual((int)6, a[5]);
		}

		TEST_METHOD(ListInsert)
		{
			DSList<int> mylist;
			DSList<int> mylist2;
			mylist2.add(1);
			mylist2.add(2);
			mylist2.add(3);
			DSList<int> mylist3;
			mylist3.add(4);
			mylist3.add(5);
			mylist3.add(6);
			mylist.InsertAfter(0, mylist2);
			Assert::AreEqual(mylist[0], 1);
			Assert::AreEqual(mylist[1], 2);
			Assert::AreEqual(mylist[2], 3);
			mylist.InsertAfter(1, mylist3);
			Assert::AreEqual(mylist[0], 1);
			Assert::AreEqual(mylist[1], 2);
			Assert::AreEqual(mylist[2], 4);
			Assert::AreEqual(mylist[3], 5);
			Assert::AreEqual(mylist[4], 6);
			Assert::AreEqual(mylist[5], 3);
			mylist.InsertAfter(0, mylist3);
			Assert::AreEqual(mylist[0], 1);
			Assert::AreEqual(mylist[1], 4);
			Assert::AreEqual(mylist[2], 5);
			Assert::AreEqual(mylist[3], 6);
			Assert::AreEqual(mylist[4], 2);
			Assert::AreEqual(mylist[5], 4);
			Assert::AreEqual(mylist[6], 5);
			Assert::AreEqual(mylist[7], 6);
			Assert::AreEqual(mylist[8], 3);
			Assert::IsTrue((DSLNode<int>*) &mylist[0] == mylist.start);
			Assert::IsTrue((DSLNode<int>*) &mylist[8] == mylist.end);
		}
	};

	// Qeue ----------------------------------------
	TEST_CLASS(UnitTestQeue)
	{
	public:
		TEST_METHOD(qeue_Pop)
		{
			Qeue<int> a;

			a.push(1);
			a.push(2);
			a.push(3);

			int pop;

			a.pop(pop);

			Assert::AreEqual((int)1, pop);
		}

	};

	// Stack ----------------------------------------
	TEST_CLASS(UnitTestStack)
	{
	public:
		TEST_METHOD(stack_Pop)
		{
			Stack<int> a;

			a.pushBack(1);
			a.pushBack(2);
			a.pushBack(3);

			int pop;

			a.pop(pop);

			Assert::AreEqual((int)3, pop);
		}
	};

}