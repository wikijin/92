#include <iostream>
using namespace std;

/**
	Computes the smallest of four values.
*/
int min(int a, int b, int c, int d)
{
	int result = a;
	if (b < result) result = b;
	if (c < result) result = c;
	if (d < result) result = d;
	return result;
}

int max(int a, int b, int c, int d)
{
	int mresult = a;
	if (b > mresult) mresult = b;
	if (c > mresult) mresult = c;
	if (d > mresult) mresult = d;
	return mresult;
}

/**
	Computes the average of the middle values of four given values
	(that is, without the largest and smallest value).
	Hint: Use the given min function. You may also want to define a
	max helper function or take advantage of the fact that max can be 
	computed from the min of the negative values.
*/
double middle(int a, int b, int c, int d)
{
	int sum = a +b +c +d;
		 return (sum - min(a,b,c,d) - max(a,b,c,d));
			
}

int a,b,c,d,mid;

int main()
{
	cin >> a;
	cin >> b;
	cin >> c;
	cin >> d;
	mid = middle(a,b,c,d);
	double average = (static_cast<double>(mid))/2;

	cout << average ;

	return 0;
}