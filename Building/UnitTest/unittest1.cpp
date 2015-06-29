#include "stdafx.h"
#include "CppUnitTest.h"

#include "../Programació 2/point2D.h"
#include "../Programació 2/Projectile.h"
#include "../Programació 2/String.h"

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

	TEST_CLASS(StringClass)
	{
	public:

		TEST_METHOD(TestMethod_constructEmpty)
		{
			String s;

			Assert::IsTrue(s.size == 1);
			Assert::AreEqual(s.string, "\0");
		}

		/*
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

		TEST_METHOD(TestMethod_destructor)
		{
		String s("hello");
		s.~String();
		Assert::IsTrue(s.string == NULL);
		}

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
		}*/

	};
}