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
	Compute the distance between this point and another point.
	@param other the other point
	@return the distance between them.
*/
double Point::distance(Point other)
{
	double sum = (other.x - x) * (other.x - x) + (other.y - y) * (other.y - y);
    return sqrt(sum);
}
