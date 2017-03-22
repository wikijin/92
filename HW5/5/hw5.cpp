#include <cmath>

#include "point.h"

Point::Point(double xvalue, double yvalue)
{
	x = xvalue;
	y = yvalue;
}

double Point::get_x() { return x; }
double Point::get_y() { return y; }

/**
	Compute the midpoint between this point and another point.
	@param other the other point
	@return the point halfway between them.
*/
Point Point::midpoint(Point other)
{
	...   
}
