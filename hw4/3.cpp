#include <iostream>

using namespace std;

void print(char* arg);

int main()
{
	char a1[] = "Hello*2";
	print(a1);
	cout << "Expected: HelloHello" << endl;   
	char a2[] = "Goodbye*3";
	print(a2);
	cout << "Expected: GoodbyeGoodbyeGoodbye" << endl;
	char a3[] = "HI*10";
	print(a3);
	cout << "Expected: HIHIHIHIHIHIHIHIHIHI" << endl;
	char a4[] = "Bonjour";
	print(a4);
	cout << "Expected: Bonjour" << endl;
	char a5[] = "4*4*4";
	print(a5);
	cout << "Expected: 4*44*44*44*4" << endl;

	return 0;
}

/*
	The print method receives as input a string followed by an asterisk 
	and an integer. Print out the string as many time as indicated 
	by the integer. For example, when called as print("Hi*3"), 
	you print HiHiHi. If no integer is specified, print the string
	once.

	Hint: Look for the '*' starting from the back of the string. 
	Then call atoi, passing a pointer to the integer starting after
	the '*'. You can also replace the '*' with a '\0' for easy
	printing of the first part.
*/

#include <iostream>
#include <cstdlib>
#include <cstring>

using namespace std;

void print(char* arg)
{    
	 int k=0,n=0 ;
	 for (int i=strlen(arg); i>0 ;i--)
	{
		k++;
		if (arg[i]=='*')
		{
			
			arg[i] = '\0';
			n= atoi(arg+i+1);
			break;
		}
				
	} 

	
	if(n==0)
	{
		cout << arg;
	}
	else{
	
	for (int b=0; b<n; b++)
	{
		cout << arg; 
	}
	}
	
	
	cout<<endl;
	
}
