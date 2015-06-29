#ifndef _Point2f_
#define _Point2f_

class Point2f
{
    public:

		float x, y;

		Point2f operator+(const Point2f& a) const;

		Point2f operator-(const Point2f& a) const;

		Point2f operator+=(const Point2f& a);

		Point2f operator-=(const Point2f& a);
		
		bool operator==(const Point2f& a) const;

		bool operator!=(const Point2f& a) const;

		void setZero();

		bool isZero() const;

		float distanceTo(const Point2f& a) const;
};

#endif