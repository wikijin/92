#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

void swapFirstLastVowel(string&);

int main()
{
	string s = "Hello";
	swapFirstLastVowel(s);
	cout << s << endl;
	cout << "Expected: Holle" << endl;
	s = "Goodbye";
	swapFirstLastVowel(s);
	cout << s << endl;
	cout << "Expected: Geodbyo" << endl;
	s = "Tom";
	swapFirstLastVowel(s);
	cout << s << endl;
	cout << "Expected: Tom" << endl;
	s = "Bzzzt";
	cout << s << endl;
	cout << "Expected: Bzzzt" << endl;
	return 0;
}

#include <string>

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
	Swaps the first and last vowel in the string s. 
	For example, if s is "Farewell", it is changed to "Ferewall".
*/
#include <string>
#include <algorithm>
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
   Swaps the first and last vowel in the string s. 
   For example, if s is "Farewell", it is changed to "Ferewall".
*/
void swapFirstLastVowel(string& s)
{
	int i,j,l[256],k=0;
	char b[s.size()+1];
	for(j=0; j<= s.size()+1;j++)
	{
		b[j]=s[j];
	}
	for (i=0; i<=s.size()+1;i++)
	{
		if (isVowel(s[i]))
		{
			l[k]=i;
			k++;
		}
	}
	
	if (k==0)
	{
		cout<<s;
	}
	else{
	swap(s[l[0]],s[l[k-1]]);
		
	}
	
	
}
