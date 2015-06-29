#ifndef _Projectile_
#define _Projectile_

/*#include "../Programacio2/Point2fTemplate.h"

template<class TYPE>
class Projectile
{
public:

	Point2fTemplate<TYPE> point;
	Point2fTemplate<TYPE> speed;


	Point2fTemplate<TYPE>& getCurrentPosition(float time)
	{
		Point2fTemplate<TYPE>* current;
		current->x = point.x + speed.x * time;
		current->y = point.y + speed.y * time;

		return (current);
	}*/


#include "../Programacio2/Point2f.h"

class Projectile
{
public:

	Point2f point;
	Point2f speed;


	Point2f& getCurrentPosition(float time) const
	{
		Point2f current;
		current.x = point.x + speed.x * time;
		current.y = point.y + speed.y * time;

		return(current);
	}



};

#endif