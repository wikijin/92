#include "path.h"

/*
  Produce a class Path that represents a path of points.
  Use a vector to store Point objects.
*/

void Path::add(int x, int y)
{
	...
}

void Path::add(const Point& p)
{
	...
}

Point& Path::at(int index)
{
	...
}

int Path::length()
{
	...
}

void Path::print()
{
	for (int i = 0; i < length(); i++)
	{
		if (i > 0) cout << "->";
		cout << "(" << at(i).x() << "," << at(i).y() << ")";
	}
	cout << endl;
}
