#ifndef _Projectile_
#define _Projectile_

#include "point2D.h"

class Projectile {

public:

	//Variables
	point2D point;
	point2D speed;

	//Methods
	point2D& getCurrentPosition(float time) const
	{
		point2D current;

		current.x = point.x + speed.x * time;
		current.y = point.y + speed.y * time;

		return (current);
	}
	
};

#endif