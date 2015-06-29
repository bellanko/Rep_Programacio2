#ifndef _DynamicArray_
#define _DynamicArray_

#include <stdio.h>
#include <assert.h>


template<class TYPE>
class DynArray
{
private:
	TYPE* data;
	unsigned int allocatedMemory;
	unsigned int numElements;

public:
	//Constructors
	DynArray() : data(NULL), allocatedMemory(0), numElements(0){}

	DynArray(unsigned int memSize) : data(NULL), numElements(0)
	{
		reallocate(memSize);
	}

	//Destructor
	~DynArray()
	{
		if (data != NULL)
		delete[] data;
	}

	//Operators
	TYPE& operator[] (unsigned int index) //modificar
	{
		assert(index <= numElements);
		return data[index];
	}

	const TYPE& operator[] (unsigned int index) const //lectura
	{
		assert(index <= numElements);
		return data[index];
	}

	const DynArray<TYPE>& operator+=(const DynArray<TYPE>& toAdd)
	{
		if ((numElements + toAdd.numElements + 1) > allocatedMemory)
			reallocate(allocatedMemory + toAdd.numElements);

		for (unsigned int i = 0; i < toAdd.numElements; i++)
			pushBack(toAdd[i]);

		return (*this);
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

	//mirror
	void mirror()
	{
		unsigned int x = 0;
		for (unsigned int i = (numElements / 2); i > 0; i--)
		{
			swap(data[numElements - 1 - x], data[x]);
			x++;
		}
	}

	//insertarray
	bool insertDynArray(DynArray<TYPE>& toAdd, unsigned int position)
	{
		if (position > numElements)
		{
			return false;
		}

		if (numElements + toAdd.numElements > allocatedMemory)
		{
			reallocate(numElements + toAdd.numElements + 1);
		}

		for (unsigned int i = position; i < position + toAdd.numElements; i++)
		{
			data[i + toAdd.numElements] = data[i];
			data[i] = toAdd[i - position];
			numElements++;
		}

		return true;
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