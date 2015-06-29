#ifndef _String_
#define _String_

#include <string.h>
#include <stdio.h>
#include <windows.h>

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

	//String(const char* format, ...);

	~String();

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

	const String operator=(const char* s);

	const String& operator+=(const String& s);

	const String& operator+=(const char* s);


	const String& prefix(const String& s);

	const String& prefix(const char* s);

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

	unsigned int capacity() const;

	const char* getString() const;

	void cut(unsigned int first, unsigned int last);

	unsigned int find(const String& s) const;

	unsigned int find(const char* s) const;



};

#endif