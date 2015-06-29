#ifndef _BubbleSort_
#define _BubbleSort_

#include "Utilities.h"

#include <stdio.h>
#include <assert.h>


template<class TYPE>
class BubbleSort
{
private:
	TYPE* data;
	unsigned int allocatedMemory;
	unsigned int numElements;

public:
	//Constructors
	BubbleSort() : data(NULL), allocatedMemory(0), numElements(0){}

	BubbleSort(unsigned int memSize) : data(NULL), numElements(0)
	{
		reallocate(memSize);
	}

	//Destructor
	~BubbleSort()
	{
		if (data != NULL)
			delete[] data;
	}

	//Operators
	TYPE& operator[] (unsigned int index) //modificar
	{
		assert(index < numElements);
		return data[index];
	}

	const TYPE& operator[] (unsigned int index) const //lectura
	{
		assert(index < numElements);
		return data[index];
	}

	//Data Managment
	void pushBack(const TYPE& value)
	{
		if (numElements >= allocatedMemory)
		{
			reallocate(allocatedMemory + 1);
		}
		data[numElements++] = value;
	}

	bool pop(TYPE& value)
	{
		if (numElements > 0)
		{
			value = data[--numElements];
			return true;
		}
		return false;
	}

	void clear()
	{
		numElements = 0;
	}

	bool insert(const TYPE& value, unsigned int position)
	{
		if (position > numElements)
		{
			return false;
		}

		if (position == numElements)
		{
			pushBack(value);
			return true;
		}

		if (numElements + 1 > allocatedMemory)
		{
			reallocate(allocatedMemory + (numElements + 1 - allocatedMemory));
		}

		for (unsigned int i = numElements; i > position; --i)
		{
			data[i] = data[i - 1];
		}
		data[position] = value;
		++numElements;

		return true;
	}

	TYPE* at(unsigned int index)
	{
		TYPE* result = NULL;
		if (index < numElements)
		{
			return result = &data[index];
		}
		return result;
	}

	const TYPE* at(unsigned int index) const
	{
		TYPE* result = NULL;
		if (index < numElements)
		{
			return result = &data[index];
		}
		return result;
	}

	unsigned int DoBubbleSort()
	{
		unsigned int ifs = 0;
		bool repeat = true;

		while (repeat)
		{
			repeat = false;
			for (unsigned int i = 0; i < (numElements - 1); i++)
			{
				ifs++;
				if (data[i] > data[(i + 1)])
				{
					swap(data[i], data[(i + 1)]);
					repeat = true;
				}
			}
		}
		return ifs;
	}

	unsigned int DoBubbleSortBetter()
	{
		unsigned int ifs = 0;
		bool repeat = true;
		unsigned int lastSwap = numElements;
		unsigned int lastSwapCount = numElements;

		while (repeat)
		{
			repeat = false;
			for (unsigned int i = 0; i < (lastSwap - 1); i++)
			{
				ifs++;
				if (data[i] > data[(i + 1)])
				{
					swap(data[i], data[(i + 1)]);
					repeat = true;
					lastSwapCount = i - 1;
				}
			}
			lastSwap = lastSwapCount;
		}
		return ifs;
	}//

	unsigned int CombSort()
	{
		unsigned int ifs = 0;
		bool repeat = true;
		unsigned int compare = 1;

		compare = numElements * 0.7;

		while (repeat)
		{
			repeat = false;
			for (unsigned int i = 0; i < (numElements - compare); i++)
			{
				ifs++;
				if (data[i] > data[(i + compare)])
				{
					swap(data[i], data[(i + compare)]);
					repeat = true;
				}
			}
			if (compare > 1)
			{
				compare--;
				repeat = true;//sino podria quedar desordenat igualment (?)
			}
		}
		return ifs;
	}

	//removeWastedMemory
	const unsigned int removeWastedMemory()
	{
		unsigned int lastAllocatedMemory = allocatedMemory;
		DynArray<TYPE> tmp(count());
		reallocate(count());
		return(lastAllocatedMemory - allocatedMemory);
	}

	//Utilities
	unsigned int getCapacity() const
	{
		return allocatedMemory;
	}

	unsigned int count() const
	{
		return numElements;
	}

private:
	//Private Utilities
	void reallocate(unsigned int newMemorySize)
	{
		TYPE* tmp = data;
		allocatedMemory = newMemorySize;
		data = new TYPE[allocatedMemory];
		if (numElements > allocatedMemory)
		{
			numElements = allocatedMemory;
		}
		if (tmp != NULL)
		{
			for (unsigned int i = 0; i < numElements; ++i)
			{
				data[i] = tmp[i];
			}
			delete[] tmp;
		}
	}
};


#endif