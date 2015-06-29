#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "BubbleSort.h"
#include "String.h"
#include "p2List.h"


int main()
{
	/*BubbleSort<int> array(10001);
	BubbleSort<int> array1(10001);
	BubbleSort<int> array2(10001);

	srand(time(NULL));

	for (unsigned int i = 0; i < 10000; i++)
	{
		array.pushBack(rand());
		array1.pushBack(rand());
		array2.pushBack(rand());
	}

	int x = array.DoBubbleSort();
	int y = array1.DoBubbleSortBetter();
	int z = array2.CombSort();

	printf("Standart bubble sort: %i\nBetter bubble sort: %i\nCombSort: %i",x, y, z);

	unsigned int f = fib(5);
	printf("\n\n%i", f);*/

	String s1("Hola mundo");

	printf("%i\n\n", s1.size);

	s1.cut(2, 5);

	printf(s1.string);

	printf("\n\n%i\n\n", s1.size);

	s1.cut(3, 0);

	printf(s1.string);

	printf("\n\n%i", s1.size);

	getchar();
}







/*#include <stdio.h>
#include "Tree.h"

int factorial(int f)
{
	int result = 1;
	
	for (int x = 1; x < f; x++)
	{
		result *= x;
	}
	return result;
}

int factorialRecursivitat(int f)
{
	return (f > 1) ? f*factorialRecursivitat(f - 1) : 1;
	
	//if (f > 1)
	//{
		//return f * factorialRecursivitat(f - 1);
	//}
	//else
	//{
	    //return 1;
	//}
}

int main(int argc, char** argv)
{
	int x = factorialRecursivitat(5);
	printf("%i", x);
	getchar();
	return(0);
}*/