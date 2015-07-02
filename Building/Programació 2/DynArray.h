#ifndef DYNARRAY_H
#define DYNARRAY_H

#include <stdlib.h>
#include <assert.h>

#define DYN_ARRAY_BLOCK_SIZE 16

template<class VALUE>
class DynArray
{
private:
	VALUE* data;	//Array data.
	unsigned int allocated_memory;	//Allocated Memory of the array.
	unsigned int num_elements;	//Number of elements that contains the array. (Number can't be higher than allocated memory).

public:
	DynArray() : data(NULL), allocated_memory(0), num_elements(0)	//Constructor, gives 0 or NULL values to each variable.
	{
		reallocate(DYN_ARRAY_BLOCK_SIZE);
	}

	DynArray(unsigned int mem_size) : data(NULL), allocated_memory(0), num_elements(0){ reallocate(mem_size); }	//Constructor that allocates a new memory size to our Array.
	~DynArray(){ delete[] data; }	//Destructor, deletes our Array if it isn't NULL.

	//Operators
	VALUE& operator[](unsigned int index) //Returns the value of a determined position in our array.
	{
		assert(index < num_elements);
		return data[index];
	}

	const VALUE& operator[](unsigned int index) const //Returns the value of a determined position in our array.
	{
		assert(index < num_elements);
		return data[index];
	}

	//Memory Managment
	void pushback(const VALUE& value)	//Inserts a new value at the end of our array.
	{
		if (num_elements >= allocated_memory)
		{
			reallocate(allocated_memory + DYN_ARRAY_BLOCK_SIZE);
		}

		data[num_elements++] = value;
	}

	void pop()	//Deletes the last value of our array.
	{
		if (num_elements >= 1) num_elements -= 1;	//Deleletes the last member of our array by decreasing num_element in 1.
	}

	bool insert(const VALUE value, const unsigned int position)	//Inserts a value on designed position and moves positions of the rest of the values.
	{
		if (position > num_elements)
			return false;

		if (position == num_elements)
		{
			pushback(value);
			return true;
		}

		if (num_elements + 1 > allocated_memory)
			reallocate(allocated_memory + DYN_ARRAY_BLOCK_SIZE);

		for (unsigned int i = num_elements; i > position; --i)
		{
			data[i] = data[i - 1];
		}

		data[position] = value;
		++num_elements;

		return true;
	}

	void clear()	//Deletes all the elements of the array.
	{
		num_elements = 0;
	}


	//Utility Methods
	unsigned int getCapacity() const
	{
		return allocated_memory;
	}

	unsigned int count() const
	{
		return num_elements;
	}

	/*void flip()
	{
		for (int i = 0; i < num_elements / 2; i++)
		{
			swap_values(data[i], data[num_elements - i]);
		}
	}*/

	bool insertDynArray(DynArray<VALUE>& toAdd, unsigned int position)
	{
		if (position > num_elements)
		{
			return false;
		}

		if (num_elements + toAdd.num_elements > allocated_memory)
		{
			reallocate(num_elements + toAdd.num_elements + 1);
		}

		for (unsigned int i = position; i < position + toAdd.num_elements; i++)
		{
			data[i + toAdd.num_elements] = data[i];
			data[i] = toAdd[i - position];
			num_elements++;
		}

		return true;
	}

	 const unsigned int removeWastedMemory()
	{
		unsigned int WastedMemory = 0;

		if (allocated_memory > num_elements){

			WastedMemory = allocated_memory - num_elements;

			allocated_memory = num_elements;
			reallocate(allocated_memory);
		}

		return WastedMemory;
	}


private:

	// Private Methods
	void reallocate(const unsigned int new_memory_size)
	{
		VALUE* tmp = data;

		allocated_memory = new_memory_size;
		data = new VALUE[allocated_memory];

		if (num_elements > allocated_memory) num_elements = allocated_memory;

		if (tmp != NULL)
		{
			for (unsigned int i = 0; i < num_elements; ++i) data[i] = tmp[i];
			delete[] tmp;
		}
	}


};

#endif