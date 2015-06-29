#ifndef _LinkedList_
#define _LinkedList_

#include <stdio.h>

template<class TYPE>
struct lNode
{
	TYPE value;
	lNode<TYPE>* next;

	inline lNode(const TYPE& _value)
	{
		value = _value;
		next = NULL;
	}

	~lNode()
	{}
};

template<class TYPE>
class SList
{
public:
	lNode* start;
	
	SList() : start(NULL){}

	void add(TYPE value)
	{
		lNode* newlNode = new lNode;
		newlNode->value = value;
		newlNode->next = NULL;
		lNode* tmp = start;

		if (tmp != NULL){
			while (tmp->next != NULL)
			{
				tmp = tmp->next;
			}
		}
		tmp->next = newlNode;
	}

	void del(lNode* dellNode)
	{
		if (dellNode != NULL)
		{
			if (dellNode != start && start != NULL)
			{
				lNode* tmp = start;
				while (tmp->next != dellNode)
				{
					if (tmp == NULL)
					{
						delete dellNode;
						return;
					}
					tmp = tmp->next;
				}
				tmp->next = dellNode->next;
			}
			else
			{
				start = start->next;
			}
			delete dellNode;
		}
	}

	void del(unsigned int x)
	{
			if (start != NULL)
			{
				lNode* tmp = start;
				lNode* tmp2;
				if (x == 0)
				{
					start = start->next;
					delete tmp;
				}
				for (unsigned int i = 1; i < x; i ++)
				{
					if (tmp == NULL)
					{
						return;
					}
					tmp = tmp->next;
				}
				tmp2 = tmp->next;
				tmp->next = tmp2->next;
			}
			delete tmp2;
	}

	void delAll()
	{
		if (start != NULL)
		{
			lNode* tmp = start;
			while (start != NULL)
			{
				tmp = start;
				start = start->next;
				delete tmp;
			}
			delete start;
		}
	}

	unsigned int count() const
	{
		unsigned int result = 0;
		lNode* tmp = start;
		if (tmp != NULL)
		{
			while (tmp->next != NULL)
			{
				tmp = tmp->next;
				result++;
			}
		}
		return (result);
	}

};


#endif