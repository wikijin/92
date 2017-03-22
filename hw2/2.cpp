#include <string>
#include <iostream>

using namespace std;
/**
	Turn a string of the form firstname lastname or 
	firstname middlename(s) lastname into lastname, firstname 
	(and middlenames if present). 
	For example, lastfirst("John Pierpont Flathead") should return
	"Flathead, John Pierpont". If the string contains no spaces, return
	it unchanged.
	Hint: If s is a string, then s.substr(i, n) is the substring
	starting at index i of length n. And if s and t are two strings,
	then s + t is the concatenation of the two strings. You will want
	to return a string of the form 
	s.substr(i1, n1) + ", " + s.substr(i2, n2)
	except if s contains no spaces.
*/
int i,j=0,a=0,b=0,c=0;
string lastfirst(string s)
{
	for (i=0;i<s.length();i++)
	{
	  if (s[i]==' ')
	  {
	  j++;
	  if (a==0)
	  {
	  a=i;
	  }
	  if((b==0)&&(a!=0))
	  {
		 b=i;
	  }
	  if((a!=0)&&(b!=0))
	  {
		 c=i;
	  }
	}
	}
	if (j==0)
	{
	  return(s);
	}
	if (j==1)
	{
	  return(s.substr(a+1,i-a)+", "+s.substr(0,a));
	}
	if (j==2)
	{
	  return(s.substr(c+1,i-c)+", "+s.substr(0,c));
	}
	if (j==3)
	{
	  return(s.substr(c+1,i-c)+", "+s.substr(0,c));
	}
	}

