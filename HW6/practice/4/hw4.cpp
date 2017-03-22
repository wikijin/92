/**
	The eagle-eyed among you will have noticed that in the preceding
	exercise many points were constructed, and few were destroyed.
	Fix that by providing a destructor forr the Path class. You will 
	also need to provide the constructor and add method again since 
	we don't want to give away the solution to the preceding problem.
*/
#include "path.h"

Path::Path(int n)
{
	...
}

// Destructor...

/*
  Produce a class Path that represents a path of points.
  Use a vector to store Point objects.
*/
void Path::add(int x, int y)
{
	...
}

Point& Path::at(int index)
{  
	return _points[index];  
}

int Path::length()
{  
	return _length;  
}

void Path::print()
{
	for (int i = 0; i < length(); i++)
	{
		if (i > 0) cout << "->";
		Point& p = at(i);
		cout << "(" << p.x() << "," << p.y() << ")";
	}
	cout << endl;
}
