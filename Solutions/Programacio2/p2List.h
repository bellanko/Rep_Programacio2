#ifndef __p2List_H__
#define __p2List_H__

#include "p2Defs.h"
#include "p2Assert.h"

/**
* Contains items from double linked list
*/
template<class tdata>
struct p2List_item
{
	tdata                 data;
	p2List_item<tdata>*   next;
	p2List_item<tdata>*   prev;

	inline p2List_item(const tdata& _data)
	{
		data = _data;
		next = prev = NULL;
	}

	~p2List_item()
	{}
};

/**
* Manages a double linked list
*/
template<class tdata>
class p2List
{

public:

	p2List_item<tdata>*   start;
	p2List_item<tdata>*   end;

private:

	unsigned int  size;

public:

	/**
	* Constructor
	*/
	inline p2List()
	{
		start = end = NULL;
		size = 0;
	}

	/**
	* Destructor
	*/
	~p2List()
	{
		clear();
	}

	/**
	* Get Size
	*/
	unsigned int count() const
	{
		return size;
	}

	/**
	* Add new item
	*/
	unsigned int add(const tdata& item)
	{
		p2List_item<tdata>*   p_data_item;
		p_data_item = new p2List_item < tdata >(item);

		if(start == NULL)
		{
			start = end = p_data_item;
		}
		else
		{
			p_data_item->prev = end;
			end->next = p_data_item;
			end = p_data_item;
		}

		return(++size);
	}

	/**
	* Deletes an item from the list
	*/
	bool del(p2List_item<tdata>* item)
	{
		if(item == NULL)
		{
			return (false);
		}

		// Now reconstruct the list
		if(item->prev != NULL)
		{
			item->prev->next = item->next;

			if(item->next != NULL)
			{
				item->next->prev = item->prev;
			}
			else
			{
				end = item->prev;
			}
		}
		else
		{
			if(item->next)
			{
				item->next->prev = NULL;
				start = item->next;
			}
			else
			{
				start = end = NULL;
			}
		}

		RELEASE(item);
		--size;
		return(true);
	}

	/**
	* Destroy and free all mem
	*/
	void clear()
	{
		p2List_item<tdata>*   p_data;
		p2List_item<tdata>*   p_next;
		p_data = start;

		while(p_data != NULL)
		{
			p_next = p_data->next;
			RELEASE(p_data);
			p_data = p_next;
		}

		start = end = NULL;
		size = 0;
	}

	/**
	* read / write operator access directly to a position in the list
	*/
	tdata& operator  [](const unsigned int index)
	{
		long                  pos;
		p2List_item<tdata>*   p_item;
		pos = 0;
		p_item = start;

		while(p_item != NULL)
		{
			if(pos == index)
			{
				break;
			}

			++pos;
			p_item = p_item->next;
		}

		ASSERT(p_item);

		return(p_item->data);
	}

	/**
	* const read operator access directly to a position in the list
	*/
	const tdata& operator  [](const unsigned int index) const
	{
		long                  pos;
		p2List_item<tdata>*   p_item;
		pos = 0;
		p_item = start;

		while(p_item != NULL)
		{
			if(pos == index)
			{
				break;
			}

			++pos;
			p_item = p_item->next;
		}

		ASSERT(p_item);

		return(p_item->data);
	}

	/**
	* const read operator access directly to a position in the list
	*/
	const p2List<tdata>& operator +=(const p2List<tdata>& other_list)
	{
		p2List_item<tdata>*   p_item = other_list.start;

		while(p_item != NULL)
		{
			add(p_item->data);
			p_item = p_item->next;
		}

		return(*this);
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

	/**
	* const access to a node in a position in the list
	*/
	const p2List<tdata>* At(unsigned int index) const
	{
		long                  pos = 0;
		p2List_item<tdata>*   p_item = start;

		while(p_item != NULL)
		{
			if(pos++ == index)
				break;

			p_item = p_item->next;
		}

		return data;
	}

	/**
	* access to a node in a position in the list
	*/
	p2List_item<tdata>* At(unsigned int index)
	{
		long                  pos = 0;
		p2List_item<tdata>*   p_item = start;

		while(p_item != NULL)
		{
			if(pos++ == index)
				break;

			p_item = p_item->next;
		}

		return p_item;
	}

	// Sort
	int BubbleSort()
	{
		int ret = 0;
		bool swapped = true;

		while(swapped)
		{
			swapped = false;
			p2List_item<tdata>* tmp = start;

			while(tmp != NULL && tmp->next != NULL)
			{
				++ret;
				if(tmp->data > tmp->next->data)
				{
					SWAP(tmp->data, tmp->next->data);
					swapped = true;
				}

				tmp = tmp->next;
			}
		}

		return ret;
	}

	/**
	* returns the first apperance of data as index (-1 if not found)
	*/
	int find(const tdata& data)
	{
		p2List_item<tdata>* tmp = start;
		int index = 0;

		while(tmp != NULL)
		{
			if(tmp->data == data)
				return(index);

			++index;
			tmp = tmp->next;
		}
		return (-1);
	}
};
#endif /*__p2List_H__*/