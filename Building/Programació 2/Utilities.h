template<class TYPE>

void swap(TYPE& a, TYPE& b)
{
	TYPE tmp;
	tmp = a;
	a = b;
	b = tmp;
}

#define MIN(a, b) (a < b ? a:b)

#define MAX(a, b) (a > b ? a:b)