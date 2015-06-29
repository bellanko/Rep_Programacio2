#ifndef _Point2fTemplate_
#define _Point2fTemplate_

template<class TYPE>
class Point2fTemplate
{
public:

	TYPE x, y;

	Point2fTemplate& create(const TYPE& x, const TYPE& y)
	{
		TYPE x = x;
		TYPE y = y;
	}

	Point2fTemplate operator+(const Point2fTemplate& a) const
	{
		Point2fTemplate tmp;
		tmp.x = x + a.x;
		tmp.y = y + a.y;

		return tmp;
	}

	Point2fTemplate operator-(const Point2fTemplate& a) const
	{
		Point2fTemplate tmp;
		tmp.x = x - a.x;
		tmp.y = y - a.y;

		return tmp;
	}

	Point2fTemplate operator+=(const Point2fTemplate& a)
	{
		x += a.x;
		y += a.y;

		return (*this);
	}

	Point2fTemplate operator-=(const Point2fTemplate& a)
	{
		x -= a.x;
		y -= a.y;

		return(*this);
	}

	bool operator==(const Point2fTemplate& a) const
	{
		return (x == a.x) && (y == a.y);
	}

	bool operator!=(const Point2fTemplate& a) const
	{
		return (x != a.x) || (y != a.y);
	}

	void setZero()
	{
		x = y = 0.0f;
	}

	bool isZero() const
	{
		return x == 0.0f && y == 0.0f;
	}

	TYPE distanceTo(const Point2fTemplate& a) const
	{
		return sqrt((x - a.x) * (x - a.x)) + ((y - a.y) * (y - a.y));
	}
};

#endif