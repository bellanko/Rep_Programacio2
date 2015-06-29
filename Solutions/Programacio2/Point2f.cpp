#include "Point2f.h"
#include <math.h>



Point2f Point2f::operator+ (const Point2f& a) const
{
	Point2f tmp;
	tmp.x = x + a.x;
	tmp.y = y + a.y;

	return tmp;
}

Point2f Point2f::operator- (const Point2f& a) const
{
	Point2f tmp;
	tmp.x = x - a.x;
	tmp.y = y - a.y;

	return tmp;
}


Point2f Point2f::operator+= (const Point2f& a)
{
	x += a.x;
	y += a.y;

	return (*this);
}

Point2f Point2f::operator-= (const Point2f& a)
{
	x -= a.x;
	y -= a.y;

	return(*this);
}

bool Point2f::operator== (const Point2f& a) const
{
	return (x == a.x) && (y == a.y);
}

bool Point2f::operator!= (const Point2f& a) const
{
	return (x != a.x) || (y != a.y);
}

void Point2f::setZero()
{
	x = y = 0.0f;
}

bool Point2f::isZero() const
{
	return x == 0.0f && y == 0.0f;
}

float Point2f::distanceTo(const Point2f& a) const
{
	return sqrt((x - a.x) * (x - a.x)) + ((y - a.y) * (y - a.y));
}

