#ifndef _Stack_
#define _Stack_

#include <stdio.h>
#include <assert.h>


template<class TYPE>
class Stack
{
private:
	TYPE* data;
	unsigned int allocatedMemory;
	unsigned int numElements;

public:
	//Constructors
	Stack() : data(NULL), allocatedMemory(0), numElements(0){}

	Stack(unsigned int memSize) : data(NULL), numElements(0)
	{
		reallocate(memSize);
	}

	//Destructor
	~Stack()
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

	//removeWastedMemory
	const unsigned int removeWastedMemory()
	{
		unsigned int lastAllocatedMemory = allocatedMemory;
		Stack<TYPE> tmp(count());
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