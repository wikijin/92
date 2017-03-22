#include <iostream>
#include <string>

using namespace std;

void firstLastVowel(string, int&, int&);

int main()
{
	int f = -2;
	int l = -2;
	firstLastVowel("meat", f, l);
	cout << f << " " << l << endl;
	cout << "Expected: 1 2" << endl;
	firstLastVowel("Expectation", f, l);
	cout << f << " " << l << endl;
	cout << "Expected: 0 9" << endl;
	firstLastVowel("Tom", f, l);
	cout << f << " " << l << endl;
	cout << "Expected: 1 1" << endl;
	firstLastVowel("Brrrh", f, l);
	cout << f << " " << l << endl;
	cout << "Expected: -1 -1" << endl;   
	return 0;
}

#include <string>
#include <iostream>

using namespace std;

/**
	Returns true if c is a vowel.
*/
bool isVowel(char c)
{
	return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u'
		|| c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U';
}

/**
	Sets first to the index of the first vowel in the string s
	and last to the index of the last vowel in s. If s has no vowels,
	first and last are set to -1.
*/



void firstLastVowel(string s, int& first, int& last)
{
	int i,j;
	
	char b[s.size()+1];
	for(j=0; j<= s.size();j++)
	{
		b[j]=s[j];
	}
	
	int k=0,l[256],y=0;
	
	for (i=0; i<=s.size();i++)
	{
		if (isVowel(s[i]))
		{
			l[k]=i;
			k++;
		}
	}
	if(k==0)
	{
		first=-1;
		last = -1;
	}
	else {
		
	
	first=l[0];
	last =l[k-1];
	}
	
	
}