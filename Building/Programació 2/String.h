#ifndef _String_
#define _String_

#include <string.h>
#include <stdio.h>
#include <windows.h>

#define TMP_STRING_SIZE 4096

#define MIN(a, b) (a < b ? a:b)
#define MAX(a, b) (a > b ? a:b)

template<class TYPE>
void swap_values(TYPE& a, TYPE& b)
{
	TYPE tmp;
	tmp = a;
	a = b;
	b = tmp;
}

class String {

public:

	//Variables
	unsigned int size;
	char* string;


	//Constructors
	String()
	{
		alloc(1);
		clear();
	}

	String(const char* format, ...)
	{
		size = 0;

		if (format != NULL)
		{
			static char tmp[TMP_STRING_SIZE];
			static va_list ap;

			//Construct the string from variable arguments
			va_start(ap, format);
			int res = vsprintf_s(tmp, TMP_STRING_SIZE, format, ap);
			va_end(ap);

			if (res > 0)
			{
				size = res + 1;
				string = new char[size];
				strcpy_s(string, size, tmp);
			}
		}

		if (size == 0)
		{
			size = 1;
			string = new char[size];
			clear();
		}
	}

	String(unsigned int size)
	{
		if (size > 0)
			alloc(size);

		else
			alloc(1);

		clear();
	}

	String(const String& s)
	{
		alloc(s.size + 1);
		strcpy_s(string, size, s.string);
	}

	~String()
	{
		delete[] string;
	}

	//Operators
	bool operator==(const String& s) const
	{
		return strcmp(string, s.string) == 0;
	}

	bool operator==(const char* s) const
	{
		if (s != NULL)
		{
			return strcmp(s, string) == 0;
		}

		return false;
	}

	bool operator!=(const String& s) const
	{
		return strcmp(string, s.string) != 0;
	}

	bool operator!=(const char* s) const
	{
		if (s != NULL)
		{
			return strcmp(s, string) != 0;
		}

	}

	const String operator=(const String& s)
	{
		if (s.length() + 1 > size)
		{
			delete[] string;
			alloc(s.length() + 1);
		}
		else
			clear();

		strcpy_s(string, size, s.string);
		return (*this);
	}

	const String operator=(const char* s)
	{
		if (s != NULL)
		{
			if (strlen(s) + 1 > size)
			{
				delete[] string;
				alloc(strlen(s) + 1);
			}

			strcpy_s(string, size, s);
		}
			else
				clear();

			return (*this);
	}

	const String& operator+=(const String& s)
	{
		if (size < length() + s.length())
		{
			char* tmp_string = string;
			alloc(length() + s.length() + 1);
			strcpy_s(string, size, tmp_string);
			delete[] tmp_string;		
		}

		strcat_s(string, size, s.string);
		return (*this);
	}

	const String& operator+=(const char* s)
	{
		if (s != NULL)
		{
			if (size < length() + strlen(s))
			{
				char* tmp_string = string;
				alloc(length() + strlen(s) + 1);
				strcpy_s(string, size, tmp_string);
				delete[] tmp_string;
			}

			strcat_s(string, size, s);
		}
		return (*this);
	}

	const String& prefix(const String& s)
	{
		char* tmp_string = string;
		
		alloc(length() + s.length() + 1);

		strcpy_s(string, size, s.string);
		strcat_s(string, size, tmp_string);

		delete[] tmp_string;
		return (*this);
	}

	const String& prefix(const char* s)
	{
		char* tmp_string = string;

		alloc(length() + strlen(s) + 1);

		strcpy_s(string, size, s);
		strcat_s(string, size, tmp_string);

		delete[] tmp_string;
		return (*this);
	}

	//Utility Methods 
	void alloc(unsigned int requiered_memory)
	{
		size = requiered_memory;
		string = new char[size];
	}

	void clear()
	{
		if (string != NULL)
		{
			string[0] = '\0';
		}
	}

	unsigned int length() const
	{
		return strlen(string);
	}

	unsigned int capacity() const
	{
		return size;
	}

	const char* getString() const
	{
		return string;
	}

	void cut(unsigned int first, unsigned int last)
	{
		if (string != NULL)
		{
			if (last == 0)
				last = size;

			if (last < first)
				swap_values(first, last);

			unsigned int x = last + 1;

			for (int i = first; i < size; i++, x++)
			{
				if (x < size)
					string[i] = string[x];

				else
					string[i] = NULL;
			}

			size = strlen(string) + 1;
		}

	}

	unsigned int find(const String& s) const
	{
		unsigned int x = 0;

		for (unsigned int i = 0; i < capacity(); i++)
		{
			if (string[i] == s.string[0])
			{
				if (s.capacity() > 1)
				{
					unsigned int count = 1;
					for (unsigned int u = 1; u < s.capacity(); u++)
					{
						i++;
						if (string[i] == s.string[u])
						{
							count++;
							if (count == s.capacity())
							{
								x++;
							}
						}
					}
				}
				else
				{
					x++;
				}
			}
		}
		return x;
	}

	unsigned int find(const char* s) const
	{
		unsigned int x = 0;

		unsigned int sCapacity = strlen(s);

		for (unsigned int i = 0; i < capacity(); i++)
		{
			if (string[i] == s[0])
			{
				if (sCapacity > 1)
				{
					unsigned int count = 1;
					for (unsigned int u = 1; u < sCapacity; u++)
					{
						unsigned int ii = i + 1;;
						if (string[ii] == s[u])
						{
							count++;
							if (count == sCapacity)
							{
								x++;
							}
						}
						i++;
					}
				}
				else
				{
					x++;
				}
			}
		}
		return x;
	}

};

#endif