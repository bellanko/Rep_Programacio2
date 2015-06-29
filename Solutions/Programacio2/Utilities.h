template<class TYPE>
void swap(TYPE& a, TYPE& b)
{
	TYPE tmp;
	tmp = a;
	a = b;
	b = tmp;
}


unsigned int fib(unsigned int pos)
{
	unsigned int x = 0;

	if (pos == 0 || pos == 1)
	{
		return 1;
	}

	return (fib(pos - 1) + fib(pos - 2));
}

unsigned int fibIterative(unsigned int pos)
{
	unsigned int x = 1;
	unsigned int prev = 0;

	for (unsigned int i = pos; i < 0; i--)
	{
		x += prev;
		prev = x - prev;
	}

	return x;
}