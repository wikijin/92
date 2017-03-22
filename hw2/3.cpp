grades.h
{

enum Grade { A, B, C, D, F };
enum Suffix { None, Plus, Minus };
}

#include "grades.h"
/**
	Given a letter grade (A, B, C, D, F) and a suffix (None, Plus, Minus),
	produce the numerical value of the grade. An A is a 4, B a 3, 
	C a 2, D a 1, and F a zero. The suffix Plus adds 0.3, the suffix
	Minus subtracts 0.3. However, an A+ has value 4 and an F+ and F- 
	have value zero.
 */
double gradeValue(Grade g, Suffix s)
{
	double r=0.0;
	
	if (g== A)
	{
		r=r+4.0;
	}
	
	if (g == B)
	{
		r=r+3.0;
	}
	
	if (g == C)
	{
		r= r+2.0;
	}
	
	if ( g == D)
	{
		r = r+1.0;
	}
	
	if (g == F)
	{
		r=0.0;
	}
	
	if (s == None)
	{
		s=s;
	}
	
	if ( s == Minus)
	{
		s=s-0.3;
	}
	
	if ( s == Plus)
	{
		s=s+0.4;
	}
	
	return(s);
  
}
