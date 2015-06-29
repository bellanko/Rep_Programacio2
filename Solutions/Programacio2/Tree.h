#ifndef _Tree_
#define _Tree_

#include "DoubleLinkedList.h"
#include "Stack.h"

template<class TYPE>
struct tNode
{
	TYPE value;
	tNode<TYPE>* father;
	DSList<tNode<TYPE>*> sons;

	inline tNode(const TYPE& _value)
	{
		value = _value;
		father = NULL;
	}

	~tNode()
	{}
};

template<class TYPE>
class Tree
{
	tNode<TYPE>* root;

public:

	Tree() : root(NULL){}

	Tree(const TYPE& value)
	{
		root->value = value;
	}

	tNode<TYPE>* add(const TYPE& value, tNode<TYPE>* father)
	{
		tNode<TYPE>* tmp = new tNode<TYPE> (value);
		
		if (father != NULL)
		{
			tmp->father = father;
			tmp->father->sons.add(tmp);
		}

		else
		{
			root = tmp;
		}
		
		return tmp;
	}

	tNode<TYPE>* add(const TYPE& value)
	{
		tNode<TYPE>* tmp = new tNode<TYPE>(value);

		
		tmp->father = root;
		tmp->father->sons.add(tmp);

		return tmp;
	}

	bool clear()
	{
		if (root != NULL)
		{
			DSList<tNode<TYPE>*> toDelete;
			postorderRecursive(&toDelete, root);

			DSLNode<tNode<TYPE>*>* tmp = toDelete.start;
			for (tmp; tmp != NULL; tmp = tmp->next)
			{
				tmp->value->father = NULL;
				tmp->value->sons.delAll();
			}
			return true;
		}
		return false;
	}

	bool clear(tNode<TYPE>* first)
	{
		if (first != NULL)
		{
			DSList<tNode<TYPE>*> toDelete;
			postorderRecursive(&toDelete, first);

			if (first->father != NULL)
			{
				first->father->sons.del(first);
			}
			else
			{
				delete first;
			}

			toDelete.delAll();
			return true;
		}
		return false;
	}

	void preorderRecursive(DSList<tNode<TYPE>*>* list, tNode<TYPE>* start)
	{
		if (start == NULL)
		{
			start = root;
		}

		list->add(start);

		DSLNode<tNode<TYPE>*>* tmp = start->sons.start;

		for (tmp; tmp != NULL; tmp = tmp->next)
		{
			preorderRecursive(list, tmp->value);
		}
	}

	void inorderRecursive(DSList<tNode<TYPE>*>* list, tNode<TYPE>* start)
	{
		if (start == NULL)
		{
			start = root;
		}

		unsigned int numberSons = start->sons.count();
		unsigned int visited;
		DSLNode<tNode<TYPE>*>* son = start->sons.start;

		for (visited = 0; visited < numberSons / 2; visited++)
		{
			inorderRecursive(list, son->value);

			son = son->next;
		}

		list->add(start);

		for (visited; visited < numberSons; visited++)
		{
			inorderRecursive(list, son->value);
			
			son = son->next;
		}

	}

	void postorderRecursive(DSList<tNode<TYPE>*>* list, tNode<TYPE>* start)
	{
		if (start == NULL)
		{
			start = root;
		}

		DSLNode<tNode<TYPE>*>* tmp = start->sons.start;

		for (tmp; tmp != NULL; tmp = tmp->next)
		{
			postorderRecursive(list, tmp->value);
		}

		list->add(start);
	}


	void preorderIterative(DSList<tNode<TYPE>*>* list, tNode<TYPE>* start)
	{
		if (start == NULL)
		{
			start = root;
		}

		tNode<TYPE>* tmp = start;
		Stack<tNode<TYPE>*> stack;

		bool bucle = true;

		while (bucle)
		{
			list->add(tmp);

			DSLNode<tNode<TYPE>*>* tmp2 = tmp->sons.end;

			for (tmp2; tmp2 != tmp->sons.start; tmp2 = tmp2->previous)
			{
				stack.pushBack(tmp2->value);
			}
			if (tmp2 != NULL)
			{
				tmp = tmp2->value;
			}
			else
			{
				tmp = NULL;
			}

			if (tmp == NULL)
			{
				stack.pop(tmp);
				if (tmp == NULL)
				{
					bucle = false;
				}
			}
		}

	}

	void inorderIterative(DSList<tNode<TYPE>*>* list, tNode<TYPE>* start)
	{
		if (start == NULL)
		{
			start = root;
		}

		tNode<TYPE>* tmp = start;
		Stack<tNode<TYPE>*> stack;
		bool bucle = true;

		while (bucle)
		{
			if (tmp != NULL)
			{
				if (list->find(tmp) == -1)
				{
					stack.pushBack(tmp);
				}
				if (tmp->sons.count() != 0)
				{
					tmp = tmp->sons.start->value;
				}
				else
				{
					tmp = NULL;
				}
			}
			else if (stack.count() > 0)
			{
				stack.pop(tmp);
				list->add(tmp);
				if (tmp->sons.count() != 0)
				{
					tmp = tmp->sons.end->value;
				}
				else
				{
					tmp = NULL;
				}
			}
			else
			{
				bucle = false;
			}
		}
}

	void postorderIterative(DSList<tNode<TYPE>*>* list, tNode<TYPE>* start)
	{
		if (start == NULL)
		{
			start = root;
		}

		tNode<TYPE>* tmp = start;
		Stack<tNode<TYPE>*> stack;

		bool bucle = true;
		bool inList = false;

		while (bucle)
		{
			DSLNode<tNode<TYPE>*>* tmp2 = tmp->sons.end;

			if (tmp2 != NULL && list->find(tmp2->value) == -1)
			{
				stack.pushBack(tmp);
				for (tmp2; tmp2 != tmp->sons.start; tmp2 = tmp2->previous)
				{
					stack.pushBack(tmp2->value);
				}

				tmp = tmp2->value;
			}

			else
			{
				list->add(tmp);
				tmp = NULL;
			}

			if (tmp == NULL)
			{
				stack.pop(tmp);
				if (tmp == NULL)
				{
					bucle = false;
				}
			}
		}

	}
};

#endif