#include "stdafx.h"
#include "CppUnitTest.h"
#include "../Programacio2/Point2f.cpp"
#include "../Programacio2/Projectile.h"
#include "../Programacio2/Point2fTemplate.h"
#include "../Programacio2/String.cpp"
#include "../Programacio2/DynamicArray.h"
#include "../Programacio2/DoubleLinkedList.h"
#include "../Programacio2/LinkedList.h"
#include "../Programacio2/Stack.h"
#include "../Programacio2/Qeue.h"
#include "../Programacio2/Tree.h"
#include "../Programacio2/BubbleSort.h"


#include "../Programacio2/p2List.h"



using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{
	TEST_CLASS(UnitTest1)
	{
	public:

		TEST_METHOD(TestMethod_operatorPlus)
		{
			Point2f point1, point2, point3;
			point1.x = 5.0f;
			point1.y = 11.0f;

			point2.x = 7.0f;
			point2.y = 8.0f;

			point3 = point1 + point2;

			Assert::AreEqual(point3.x, 12.0f && point3.y, 19.0f);
		}

		TEST_METHOD(TestMethod_operatorMinus)
		{
			Point2f point1, point2, point3;
			point1.x = 5.0f;
			point1.y = 11.0f;

			point2.x = 7.0f;
			point2.y = 8.0f;

			point3 = point1 - point2;

			Assert::AreEqual(point3.x, -2.0f && point3.y, 3.0f);
		}

		TEST_METHOD(TestMethod_operatorPlusEqual)
		{
			Point2f point1, point2;

			point1.x = 5.0f;
			point1.y = 11.0f;

			point2.x = 7.0f;
			point2.y = 8.0f;

			point1 += point2;

			Assert::AreEqual(point1.x, 12.0f && point1.y, 19.0f);
		}

		TEST_METHOD(TestMethod_operatorMinusEqual)
		{
			Point2f point1, point2;

			point1.x = 5.0f;
			point1.y = 11.0f;

			point2.x = 7.0f;
			point2.y = 8.0f;

			point1 -= point2;

			Assert::AreEqual(point1.x, -2.0f && point1.y, 3.0f);
		}

		TEST_METHOD(TestMethod_operatorEqualEqual)
		{
			Point2f point1, point2;

			point1.x = 5.0f;
			point1.y = 11.0f;

			point2.x = 5.0f;
			point2.y = 11.0f;

			Assert::IsTrue(point1 == point2);
		}

		TEST_METHOD(TestMethod_operatorNotEqual)
		{
			Point2f point1, point2;

			point1.x = 5.0f;
			point1.y = 11.0f;

			point2.x = 7.0f;
			point2.y = 8.0f;

			Assert::IsTrue(point1 != point2);
		}

		TEST_METHOD(TestMethod_isZero)
		{
			Point2f point;

			point.x = 0.0f;
			point.y = 0.0f;

			Assert::IsTrue(point.isZero());
		}

		TEST_METHOD(TestMethod_setZero)
		{
			Point2f point;

			point.setZero();

			Assert::IsTrue(point.isZero());
		}

		TEST_METHOD(TestMethod_distanceTo)
		{
			Point2f point1, point2;

			point1.x = 5.0f;
			point1.y = 11.0f;

			point2.x = 7.0f;
			point2.y = 8.0f;

			Assert::AreEqual(point1.distanceTo(point2), sqrt((point1.x - point2.x) * (point1.x - point2.x)) + ((point1.y - point2.y) * (point1.y - point2.y)));
		}

	};
}

namespace UnitTest2
{
	TEST_CLASS(UnitTest2)
	{
	public:

		TEST_METHOD(TestMethod_constructEmpty)
		{
			String s;

			Assert::IsTrue(s.size == 1);
			Assert::AreEqual(s.string, "\0");
		}

		TEST_METHOD(TestMethod_constructChain)
		{
			String s("%s", "hello");

			Assert::IsTrue(s.size == 6);
			Assert::AreEqual(s.string, "hello");
		}

		TEST_METHOD(TestMethod_constructChainClass)
		{
			String s("hello");
			String a(s);

			Assert::AreEqual(a.string, "hello");
		}

		/*TEST_METHOD(TestMethod_destructor)
		{
			String s("hello");
			s.~String();

			Assert::IsTrue(s.string == NULL);
		}*/

		TEST_METHOD(TestMethod_operatorEqualEqual)
		{
			String s("hello world");

			Assert::IsTrue(s == "hello world");
		}

		TEST_METHOD(TestMethod_operatorEqualEqualClass)
		{
			String s("hello world");
			String a("hello world");

			Assert::IsTrue(s == a);
		}

		TEST_METHOD(TestMethod_operatorNotEqual)
		{
			String s("hello world");

			Assert::IsTrue(s != "bye");
		}

		TEST_METHOD(TestMethod_operatorNotEqualClass)
		{
			String s("hello world");
			String a("bye");

			Assert::IsTrue(s != a);
		}

		TEST_METHOD(TestMethod_operatorEqual)
		{
			String s("world");
			s = "hello";

			Assert::IsTrue(s == "hello");
		}

		TEST_METHOD(TestMethod_operatorEqualClass)
		{
			String s("hello");
			String a("world");
			a = s;

			Assert::IsTrue(a == s);
		}

		TEST_METHOD(TestMethod_operatorPlusEqual)
		{
			String s("hello");

			s += " world";

			Assert::IsTrue(s == "hello world");
		}

		TEST_METHOD(TestMethod_operatorPlusEqualClass)
		{
			String s("hello");
			String a(" world");

			s += a;

			Assert::IsTrue(s == "hello world");
		}

		TEST_METHOD(TestMethod_operatorLength)
		{
			String s("hello");

			Assert::IsTrue(s.length() == 5);
		}

		TEST_METHOD(TestMethod_operatorCapacity)
		{
			String s("hello");

			Assert::IsTrue(s.capacity() == 6);
		}

		TEST_METHOD(TestMethod_operatorGetString)
		{
			String s("hello");

			Assert::AreEqual(s.getString(), "hello");
		}

		TEST_METHOD(TestMethod_operatorClear)
		{
			String s("hello");
			s.clear();

			Assert::IsTrue(s.string[0] == '\0');
		}
	};
}

namespace UnitTest3
{
	TEST_CLASS(UnitTest3)
	{
	public:

		TEST_METHOD(DynArray_ctor)
		{
			DynArray<int> array;
			Assert::AreEqual((int)array.getCapacity(), NULL);
		}

		TEST_METHOD(DynArray_ctor_capacity)
		{
			DynArray<int> array(33);
			Assert::AreEqual((int)array.getCapacity(), 33);
		}

		TEST_METHOD(DynArray_push_back)
		{
			DynArray<int> array;

			array.pushBack(1);
			array.pushBack(2);
			array.pushBack(3);
			Assert::AreEqual((int)array.getCapacity(), 3);
			Assert::AreEqual((int)array.count(), 3);
		}

		TEST_METHOD(DynArray_pop)
		{
			DynArray<int> array;

			array.pushBack(1);
			array.pushBack(2);
			array.pushBack(3);

			int a, b;

			Assert::IsTrue(array.pop(a));
			Assert::IsTrue(array.pop(b));

			Assert::AreEqual((int)array.getCapacity(), 3);
			Assert::AreEqual((int)array.count(), 1);
			Assert::AreEqual(a, 3);
			Assert::AreEqual(b, 2);
		}

		TEST_METHOD(DynArray_clear)
		{
			DynArray<int> array;

			array.pushBack(1);
			array.pushBack(2);
			array.pushBack(3);
			array.clear();

			Assert::AreEqual((int)array.getCapacity(), 3);
			Assert::AreEqual((int)array.count(), 0);
		}


		TEST_METHOD(DynArray_op)
		{
			DynArray<int> array;

			array.pushBack(1);
			array.pushBack(2);
			array.pushBack(3);

			Assert::AreEqual(array[0], 1);
			Assert::AreEqual(array[1], 2);
			Assert::AreEqual(array[2], 3);
		}

		TEST_METHOD(DynArray_at)
		{
			DynArray<int> array;

			array.pushBack(1);
			array.pushBack(2);
			array.pushBack(3);

			Assert::AreEqual(*(array.at(0)), 1);
			Assert::AreEqual(*(array.at(1)), 2);
			Assert::AreEqual(*(array.at(2)), 3);
			Assert::IsNull(array.at(3));
		}

		TEST_METHOD(DynArray_resize)
		{
			DynArray<int> array;

			for (int i = 0; i < 999; ++i)
			{
				array.pushBack(i);
			}

			Assert::AreEqual(*(array.at(900)), 900);
			Assert::IsNull(array.at(1000));

			Assert::AreEqual((int)array.getCapacity(), 999);
			Assert::AreEqual((int)array.count(), 999);
		}

		TEST_METHOD(DynArray_insert)
		{
			DynArray<int> array;

			for (int i = 0; i < 16; ++i)
			{
				array.pushBack(i);
			}

			array.insert(999, 3);
			array.insert(888, 17);
			array.insert(777, 50);

			Assert::IsFalse(array.insert(777, 50));
			Assert::AreEqual((int)array.getCapacity(), 18);
			Assert::AreEqual((int)array.count(), 18);
			Assert::AreEqual((int)array[3], 999);
			Assert::AreEqual((int)array[17], 888);
		}
	};
}

namespace UnitTestExam
{
	TEST_CLASS(UnitTestExam)
	{
	public:
		TEST_METHOD(Projectile_test)
		{
			Projectile/*<float>*/ p;
			p.point.x = 10.0f;
			p.point.y = 10.0f;
			p.speed.x = 2.0f;
			p.speed.y = 0.0f;
			Point2f/*Template<float>*/ current = p.getCurrentPosition(3.0f);
			Assert::AreEqual((float)16.0f, current.x, 0.00001f);
			Assert::AreEqual((float)10.0f, current.y, 0.00001f);
		}
		// ArrDyn remove wasted memory ----------------------------------------
		TEST_METHOD(ArrDyn_optimizeMem)
		{
			DynArray<int> array(10);
			array.pushBack(1);
			array.pushBack(2);
			array.pushBack(3);
			Assert::AreEqual((unsigned int)10, array.getCapacity());
			unsigned int wasted = array.removeWastedMemory();
			Assert::AreEqual((unsigned int)3, array.getCapacity());
			Assert::AreEqual((unsigned int)7, wasted);
			Assert::AreEqual((int)1, array[0]);
			Assert::AreEqual((int)2, array[1]);
			Assert::AreEqual((int)3, array[2]);
		}
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

	};
}

namespace UnitTestStack
{
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

namespace UnitTestQeue
{
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
}

/*namespace UnitTestTree
{
	TEST_CLASS(UnitTestTree)
	{
	public:
		TEST_METHOD(tree_Add)
		{
			Tree<int> a;
			tNode<int>* x;

			x = a.add(1, NULL);
			a.add(2, x);

			Assert::AreEqual((int)1, x->value);
			//Assert::AreEqual((int)2, x->sons->start->value);
		}

	};
}*/


// BubbleSort  ----------------------------------------
namespace Bubble_Sort
{
	TEST_CLASS(Bubble_Sort)
	{
	public:
		TEST_METHOD(Bubble_Sort_Test)
		{
			BubbleSort<int> array(4);
			array.pushBack(3);
			array.pushBack(2);
			array.pushBack(1);

			Assert::AreEqual((unsigned int)4, array.getCapacity());

			Assert::AreEqual((unsigned int)3, array.count());

			array.DoBubbleSort();

			Assert::AreEqual((int)1, array[0]);
			Assert::AreEqual((int)2, array[1]);
			Assert::AreEqual((int)3, array[2]);
		}
	};
}

// DoubleLinkedList  ----------------------------------------
namespace DoubleLinkedList
{
	TEST_CLASS(DoubleLinkedList_operator)
	{
	public:
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
	};

	TEST_CLASS(DoubleLinkedList_BubbleSort)
	{
	public:
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
	};

	TEST_CLASS(DoubleLinkedList_operatorPlusEqual)
	{
	public:
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
	};
}

// DynamicArray_mirror  ----------------------------------------
namespace DynamicArray
{
	TEST_CLASS(DynamicArray_mirror)
	{
	public:
		TEST_METHOD(DynamicArray_mirror_Test)
		{
			DynArray<int> array(4);
			array.pushBack(3);
			array.pushBack(2);
			array.pushBack(1);

			Assert::AreEqual((unsigned int)4, array.getCapacity());

			Assert::AreEqual((unsigned int)3, array.count());

			array.mirror();

			Assert::AreEqual((int)1, array[0]);
			Assert::AreEqual((int)2, array[1]);
			Assert::AreEqual((int)3, array[2]);
		}
	};

	TEST_CLASS(DynamicArray_insertDynArray)
	{
	public:
		TEST_METHOD(DynamicArray_insertDynArray_Test)
		{
			DynArray<int> array(4);
			array.pushBack(1);
			array.pushBack(2);
			array.pushBack(5);

			DynArray<int> array2(3);
			array2.pushBack(3);
			array2.pushBack(4);

			array.insertDynArray(array2, 2);

			Assert::AreEqual((int)1, array[0]);
			Assert::AreEqual((int)2, array[1]);
			Assert::AreEqual((int)3, array[2]);
			Assert::AreEqual((int)4, array[3]);
			Assert::AreEqual((int)5, array[4]);
		}
	};
}

// String_find  ----------------------------------------
namespace StringTest
{
	TEST_CLASS(String_find)
	{
	public:
		TEST_METHOD(String_find_Test)
		{
			String s("hola mundo hola mundo hola");

			Assert::AreEqual((int)3, (int)s.find("hola"));
			Assert::AreEqual((int)2, (int)s.find("mundo"));
			Assert::AreEqual((int)0, (int)s.find("error"));
			Assert::AreEqual((int)4, (int)s.find(" "));
		}
	};
}



//EXAMEN FINAL
namespace ExamenFinal
{
	TEST_CLASS(Examen_Final)
	{
	public:
		TEST_METHOD(SString_cut)
		{
			String s1("Hola mundo");
			s1.cut(2, 5);
			Assert::AreEqual((int)strcmp("Houndo", s1.getString()), 0);
			s1.cut(3, 0);
			Assert::AreEqual((int)strcmp("Hou", s1.getString()), 0);
		}

		TEST_METHOD(DynArray_Operator_concat)
		{
			DynArray<int> array(5);
			array.pushBack(1);
			array.pushBack(2);
			array.pushBack(4);
			array.pushBack(5);
			array.pushBack(8);
			DynArray<int> array2;
			array2.pushBack(991);
			array2.pushBack(992);
			array2.pushBack(993);
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

		TEST_METHOD(ListInsert)
		{
			p2List<int> mylist;
			p2List<int> mylist2;
			mylist2.add(1);
			mylist2.add(2);
			mylist2.add(3);
			p2List<int> mylist3;
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
			Assert::IsTrue((p2List_item<int>*) &mylist[0] == mylist.start);
			Assert::IsTrue((p2List_item<int>*) &mylist[8] == mylist.end);
		}

		/*TEST_METHOD(TreeCalcAddition)
		{
			p2Tree<int> tree(1);
			tree.Add(2, 1);
			tree.Add(3, 1);
			tree.Add(4, 1);
			tree.Add(5, 2);
			tree.Add(6, 2);
			tree.Add(7, 2);
			tree.Add(8, 4);
			tree.Add(9, 4);
			tree.Add(10, 9);
			Assert::AreEqual((int)tree.CalcAdditionRecursive(), 55);
			Assert::AreEqual((int)tree.CalcAdditionIterative(), 55);
		}*/
	};


}