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



namespace UnitTestStack
{

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