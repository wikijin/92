

class Point
{
 public:
	Point(double xvalue, double yvalue);
	double get_x();
	double get_y();
	Point midpoint(Point other);
 private:
	double x;
	double y;
};