#include <iostream>
#include <cmath>

using namespace std;

#include "point.h"

int main()
{
	Point p(1, 2);
	Point q(4, 6);
	Point r = p.midpoint(q);
	cout << r.get_x() << " " << r.get_y() << endl;
	cout << "Expected: 2.5 4" << endl;
	Point o(0, 0);
	r = p.midpoint(o);
	cout << r.get_x() << " " << r.get_y() << endl;
	cout << "Expected: 0.5 1" << endl;
	
	return 0;
}