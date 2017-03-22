/**
	Now we make a teeny-tiny change to the runner. Instead of

		Path p2(2);

	it is

		Path p2 = p1;

	The result: disaster. Now both p1 and p2 get destroyed, and 
	the destructor deletes the same memory block twice. If you are
	lucky, your program dumps core. If you are unlucky, it does 
	something completely random.

	Fix this by implementing a copy constructor. Allocate 
	a new array of the same capacity as the original, 
	and copy over all points 

	You will also need to provide the constructor, add method, and
	destructor  again since we don't want to give away the solution 
	to the preceding problems. Sorry about that.
*/
#include "path.h"

Path::Path(int n)
{
	...
}

// Destructor...

// Copy constructor

Path::Path(const Path& other)
{
	_capacity = other._capacity;
	_length = other._length;
	...
}

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
