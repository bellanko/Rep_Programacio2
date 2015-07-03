#ifndef _LinkedList_
#define _LinkedList_

#include <stdio.h>

template<class TYPE>
struct DSLNode
{
	TYPE value;
	DSLNode<TYPE>* next;
	DSLNode<TYPE>* previous;

	inline DSLNode(const TYPE& _value)
	{
		value = _value;
		next = previous = NULL;
	}

	~DSLNode(){}
};

template<class TYPE>
class DSList
{
public:

	DSLNode<TYPE>* start;
	DSLNode<TYPE>* end;

private:

	unsigned int size;

public:

	//Constructor
	DSList() : start(NULL), end(NULL), size(0){}

	//Destructor
	~DSList()
	{
		delAll();
	}

	//Get Size
	unsigned int count()
	{
		return size;
	}

	//operators
	TYPE& operator[](unsigned int index)
	{
		DSLNode<TYPE>* tmp = start;
		assert(index < size);

		for (unsigned int i = index; i > 0; i--)
		{
			tmp = tmp->next;
		}
		return tmp->value;
	}

	const TYPE& operator[](unsigned int index) const
	{
		DSLNode<TYPE>* tmp = start;
		assert(index < size);

		for (unsigned int i = index; i > 0; i--)
		{
			tmp = tmp->next;
		}
		return tmp->value;
	}

	//find node
	int find(const TYPE& value)
	{
		DSLNode<TYPE>* tmp = start;
		int index = 0;

		while (tmp != NULL)
		{
			if (tmp->value == value)
				return(index);

			index++;
			tmp = tmp->next;
		}
		return (-1);
	}

	//Add new item
	unsigned int add(const TYPE& value)
	{
		DSLNode<TYPE>* newDSLNode;
		newDSLNode = new DSLNode<TYPE>(value);

		if (start == NULL)
		{
			start = end = newDSLNode;
		}
		else
		{
			newDSLNode->previous = end;
			end->next = newDSLNode;
			end = newDSLNode;
		}
		return(++size);
	}

	//Bubblesort
	unsigned int DoBubbleSort()
	{
		unsigned int ifs = 0;
		bool repeat = true;
		DSLNode<TYPE>* tmp = start;

		while (repeat)
		{
			repeat = false;
			//for (unsigned int i = 0; i < (size - 1); i++)
			while (tmp != NULL && tmp->next != NULL)
			{
				ifs++;
				if (tmp->value > tmp->next->value)
				{
					//swap(tmp->value, tmp->next->value);
					if (tmp->previous != NULL)
						tmp->previous->next = tmp->next;

					else
						start = tmp->next;

					tmp->next->previous = tmp->previous;
					tmp->previous = tmp->next;
					tmp->next = tmp->next->next;
					tmp->previous->next = tmp;

					if (tmp->next != NULL)
						tmp->next->previous = tmp;

					else
						end = tmp;

					repeat = true;
				}
				tmp = tmp->next;
			}
		}
		return ifs;
	}

	//operator +=
	const DSList<TYPE>& operator+=(DSList<TYPE>& toAdd)//toAdd no es const pk size es privat (fer Count)
	{
		if (toAdd.start != NULL)
		{
			for (unsigned int i = 0; i < toAdd.count(); i++)
			{
				add(toAdd[i]);
			}
		}
		return (*this);
	}

	const DSList<TYPE>& operator+=(const DSList<TYPE>& toAdd)
	{
		DSLNode<TYPE>* tmpToAdd = toAdd.start;
		while (tmpToAdd != NULL)
		{
			add(tmpToAdd->value);
			tmpToAdd = tmpToAdd->next;
		}
		return (*this);
	}

	//Deletes an item from the list
	bool del(DSLNode<TYPE>* delDSLNode)
	{
		if (delDSLNode == NULL || start == NULL || end == NULL)
		{
			return false;
		}
		else
		{
			if (delDSLNode != start && delDSLNode != end)
			{
				DSLNode<TYPE>* tmp = start;
				while (tmp != delDSLNode)
				{
					if (tmp == NULL)
					{
						return false;
					}
					tmp = tmp->next;
				}
				tmp->next = delDSLNode->next;
				tmp = tmp->next;
				tmp->previous = delDSLNode->previous;
			}
			else if (delDSLNode == start)
			{
				start = start->next;
				start->previous = NULL;
			}
			else
			{
				end = end->previous;
				end->next = NULL;
			}
			--size;
			return true;
		}
	}

	/*bool del(unsigned int x)
	{
	if (start == NULL || end == NULL)
	{
	return false;
	}
	else
	{

	DSLNode<TYPE>* tmp = start;

	if (x == 0)
	{
	start = start->next;
	start->previous = NULL;
	size--;
	return true;
	}

	for (unsigned int i = 0; i < x; i++)
	{
	if (tmp == NULL)
	{
	return false;
	}
	tmp = tmp->next;
	}

	if (tmp->next != NULL)
	{

	tmp->previous->next = tmp->next;
	tmp->next->previous = tmp->previous;
	}
	else
	{
	end = end->previous;
	end->next = NULL;
	}
	}
	--size;
	return true;
	}*/

	//delNodes
	/*void delNodes(unsigned int position, unsigned int quantity)
	{
	DSLNode<TYPE>*   p_value;
	DSLNode<TYPE>*   p_next;
	p_value = start;

	unsigned int pos = 0;
	unsigned int q = 0;
	while (p_value != NULL)
	{
	p_next = p_value->next;
	if (pos >= position || q <= quantity)
	{
	delete p_value;
	q++;
	}
	pos++;
	p_value = p_next;
	}
	if (position == 0)
	{
	start = end = p_value->previous;
	}

	start = end = NULL;
	size -= quantity;
	}*/

	void delNodes(unsigned int position, unsigned int quantity)
	{
		DSLNode<TYPE>*   p_value = start;

		unsigned int pos = 0;
		unsigned int q = 0;
		while (p_value != NULL && q < quantity)
		{
			if (pos >= position && q < quantity)
			{
				del(p_value);
				q++;
			}
			pos++;

			p_value = p_value->next;
		}
		/*if (position == 0)
		{
		start = p_value;
		}

		if (position + quantity + 1 == size)
		{
		end = p_value;
		}*/
	}


	//Destroy and free all mem
	void delAll()
	{
		if (start != NULL)
		{
			DSLNode<TYPE>* tmp;
			while (start != NULL)
			{
				tmp = start;
				start = start->next;
				delete tmp;
			}
			start = end = NULL;
			size = 0;
		}
	}

		const p2List<tdata>& InsertAfter(unsigned int after, const p2List<tdata>& other_list)
	{
		if(other_list.start != NULL)
		{
						
			for (unsigned int i = 0; i < other_list.count(); i++)
			{
				if (start == NULL || after == size)
				{
					*this += other_list;
					//add(other_list[i]);
				}
				
				else if (start != NULL)
				{
					p2List_item<tdata>* p_item = start;
					p2List_item<tdata>* p_itemLast;
					while (p_item != NULL)
					{
						unsigned int pos = 0;
						if (pos == after)
						{
							break;
						}

						++pos;
						p_item = p_item->next;
					}
					/*this[after + 1]->prev = other_list.end;
					*this[after + 1]->prev->next = *this[after + 1];
					*this[after]->next = other_list.start;
					*this[after]->next->prev = *this[after];*/

					p2List_item<tdata>* p_item_other_start = other_list.start;
					p2List_item<tdata>* p_item_other_end = other_list.end;

					p_itemLast = p_item->next;
					p_item->next = p_item_other_start;
					p_item->next->prev = p_item;
					p_itemLast->prev = p_item_other_end;
					p_itemLast->prev->next = p_itemLast;
				}
			}
			size += other_list.count();
		}
		return (*this);
	}

};



#endif