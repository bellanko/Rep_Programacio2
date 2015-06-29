#ifndef _point2D_
#define _point2D_

#include <math.h>

class point2D {

public:

	//Variables
	float x, y;

	//Operators
	point2D operator+ (const point2D& a) const
	{
		point2D tmp;
		tmp.x = x + a.x;
		tmp.y = y + a.y;

		return tmp;
	}

	point2D operator- (const point2D& a) const
	{
		point2D tmp;
		tmp.x = x - a.x;
		tmp.y = y - a.y;

		return tmp;
	}

	point2D operator+= (const point2D& a) 
	{
		x += a.x;
		y += a.y;

		return (*this);
	}

	point2D operator-= (const point2D& a) 
	{
		x -= a.x;
		y -= a.y;

		return (*this);
	}

	bool operator== (const point2D& a) const
	{
		return (x == a.x) && (y == a.y);
	}

	bool operator!= (const point2D& a) const
	{
		return (x != a.x) || (y != a.y);
	}

	//Methods
	void setZero()
	{
		x = y = 0;
	}

	bool isZero() const
	{
		return (x == 0) && (y == 0);
	}

	float distanceTo(const point2D& a)
	{
		return (sqrt((x - a.x) * (x - a.x)) + ((y - a.y) * (y - a.y)));
	}

};

#endif // 0
