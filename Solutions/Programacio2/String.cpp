#include "String.h"


String::String()
{
	size = 1;
	string = new char[size];
	string[0] = '\0';
}

String::String(const char* format, ...)
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

String::String(unsigned int size)
{
	if (size > 0)
		alloc(size);
	else
		alloc(1);

	clear();
}

String::String(const String& s)
{
	size = strlen(s.string) + 1;
	string = new char[size];
	strcpy_s(string, size, s.string);
}

String::~String()
{
	delete[] string;
}

//Operators
bool String::operator== (const String& s)const
{
	return strcmp(s.string, string) == 0;
}

bool String::operator== (const char* s)const
{
	if (s != NULL)
	{
		return strcmp(s, string) == 0;
	}
	return false;
}

bool String::operator!=(const String& s)const
{
	return strcmp(s.string, string) != 0;
}

bool String::operator!=(const char* s)const
{
	if (s != NULL)
		return strcmp(s, string) != 0;
	return false;
}

const String String::operator=(const String& s)
{
	if ((s.length() + 1) > size)
	{
		delete[] string;
		size = s.length() + 1;
		string = new char[size];
	}
	else
		clear();

	strcpy_s(string, size, s.string);
	return (*this);
}

const String String::operator=(const char* s)
{
	if (s != NULL)
	{
		if (strlen(s) + 1 > size)
		{
			delete[] string;
			size = strlen(s) + 1;
			string = new char[size];
		}
		else
			clear();

		strcpy_s(string, size, s);
	}
	else
	{
		clear();
	}
	return (*this);
}

const String& String::operator+=(const String& s)
{
	if (size < strlen(string) + strlen(s.string))
	{
		char* string2 = string;
		size = strlen(string) + strlen(s.string) + 1;
		string = new char[size];
		strcpy_s(string, size, string2);
		delete[] string2;
	}

	strcat_s(string, size, s.string);
	return (*this);
}

const String& String::operator+=(const char* s)
{
	if (s != NULL)
	{
		if (size < strlen(string) + strlen(s))
		{
			char* string2 = string;
			size = strlen(string) + strlen(s) + 1;
			string = new char[size];
			strcpy_s(string, size, string2);
			delete[] string2;
		}

		strcat_s(string, size, s);
	}
	return (*this);
}

//prefix
const String& String::prefix(const String& s)
{
	unsigned int need_size = s.length() + length() + 1;
	char* tmp = string;


	alloc(need_size);

	strcpy_s(string, size, s.string);
	strcat_s(string, size, tmp);
	delete[] tmp;

	return(*this);
}

const String& String::prefix(const char* s)
{
	if (s != NULL)
	{
		unsigned int need_size = strlen(s) + length() + 1;
		char* tmp = string;


		alloc(need_size);

		strcpy_s(string, size, s);
		strcat_s(string, size, tmp);
		delete[] tmp;
	}

	return(*this);
}

//Utility
unsigned int String::length() const
{
	return strlen(string);
}

unsigned int String::capacity() const
{
	return size;
}

const char* String::getString() const
{
	return (string);
}

void String::clear()
{
	if (string != NULL)
	{
		string[0] = '\0';
	}
}

void String::cut(unsigned int first, unsigned int last)
{
	if (string != NULL)
	{
		if (last == 0)
		{
			last = size;
		}

		unsigned int x = last + 1;
		for (unsigned int i = first; i < size; i++, x++)
		{
			if (x < size)
				string[i] = string[x];

			else
				string[i] = NULL;
		}
		size = strlen(string) + 1;
	}
}

/*unsigned int String::find(const String& s) const
{
	unsigned int x = 0;

	for (unsigned int i = 0; i <= capacity() - s.capacity(); i++)
	{
		if (string[i] == s.string[0])
		{
			
			if (strncmp(string, s.string, s.capacity()))
			{
				i += s.capacity();
				x++;
			}
		}
	}
	return x;
}

unsigned int String::find(const char* s) const
{
	unsigned int x = 0;

	unsigned int sCapacity = strlen(s);

	for (unsigned int i = 0; i <= capacity() - sCapacity; i++)
	{
		if (string[i] == s[0])
		{
			if (strncmp(string, s, sCapacity))
			{
				i += sCapacity;
				x++;
			}
		}
	}
	return x;
}*/

unsigned int String::find(const String& s) const
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

unsigned int String::find(const char* s) const
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


void String::alloc(unsigned int requiered_memory)
{
	size = requiered_memory;
	string = new char[size];
}


