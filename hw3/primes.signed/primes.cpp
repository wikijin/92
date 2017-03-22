#include <iostream>
#include <math.h>
#include <iomanip>
using namespace std;

const int MAX_NUMBER = 1000;  // maximum possible prime number
const int ROW_SIZE   = 20;    // row size for printing

/***** Complete this program. *****/

/**
 * The main: Compute and print the prime numbers up to MAX_NUMBER.
 */
int main()
{
	int number[MAX_NUMBER+1];
	for (int i=1; i<= MAX_NUMBER; i++)
		{
			number[i]=i;
		}
	number[1]=0;
	
	for (int k=2;k<sqrt(MAX_NUMBER);k++) //mark the number to 0 when it has a factor of 2, 3, 5...
	
	{
		if(number[k]!=0)
		{
	
			
			for (int j=3; j<= MAX_NUMBER;j++)
			
				{
					if ((j%k==0)&&(j>k))
					{
						number[j]=0;
					
					}
				}
		}
	 }
	
	int l=21;   ///set the size per line and print the matrix
	for (int a=1; a<=MAX_NUMBER; a++)
	{
		
		if (number[a]!=0)
		
		{
			if((l)%20==0)
			{
			cout << setw(3)<<number[a]<<" "<< endl;
			l++;
			}
			else
			{
			cout << setw(3)<< number[a]<<" ";
			l++;
			}
		}
	}
	cout<<endl<<endl;
	cout<<"Done!";
	
}

