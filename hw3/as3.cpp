#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

const int MAX_SIZE  = 101;  // maximum size of the square matrix
const int MAX_START = 50;   // maximum starting number

/***** Complete this program. *****/

void do_spiral(const int n, const int start);
void make_spiral(vector<vector<int> >& matrix, vector<int> number,const int size, const int start);
void print_spiral(vector<vector<int> >& matrix, const int size);
void do_prime(vector<int>& number, const int n, const int start);
/**
 * The main: Generate and print spirals of various sizes.
*/

void do_prime(vector<int>& prime, const int n, const int start) //create a vector of prime
{
	
	prime[1]=0;
	
	for (int k=2;k<sqrt(n*n+start);k++) //mark the number to 0 when it has a factor of 2, 3, 5...
	
	{
		if(prime[k]!=0)
		{
	
			
			for (int j=3; j<= prime.size();j++)
			
				{
					if ((j%k==0)&&(j>k))
					{
						prime[j]=0;
					
					}
					
				}
		}
	 }


}

void do_prime_spiral(const int n, const int start)
{
	cout <<"Prime spiral of size "<< n << " starting at " << start ; ///do the size check
	cout << endl;
	if (n % 2 == 0)
	{
		cout << "***** Error: Size " << n << " must be odd."<< endl;
		return ;
	}
	else if ((start<1)| (start >50))
	{
		cout<<"***** Error: Starting value 0 < 1 or > 50"<< endl;
	}
	else 
	{
	vector<vector<int> > matrix;   ///declare a vector matrix with the given size
	cout << endl;
	for (int i = 0;i < n; i++)
	{
		vector<int> subvec;
		for (int j = 0;j < n; j++)
		{
			subvec.push_back(0);
		}
		matrix.push_back(subvec);
	}
	
	vector <int> prime;
	for (int o=0; o < n*n+start; o++)
	{
		prime.push_back(o);
	}
	
	do_prime(prime,n,start);
	make_spiral(matrix , prime, n, start);
	print_spiral(matrix, n);
	}
}

void make_spiral(vector<vector<int> >& matrix, vector<int> number,const int size, const int start)  ///do the matrix spiral
{
	int current_number = start;
	int x = size / 2, y = size / 2;
	matrix[x][y] = start;
	int scan_length = 1;
	while (scan_length < size)
	{
		if (scan_length % 2)
		{
			//right scan_length step
			for (int i = 0;i < scan_length; i++)
			{
				y += 1;
				current_number += 1;
				matrix[x][y] = number[current_number];
			}
			//top scan_length step
			for (int i = 0;i < scan_length; i++)
			{
				x -= 1;
				current_number += 1;
				matrix[x][y] = number[current_number];
			}
		}
		else
		{
			//left scan_length step
			for (int i = 0;i < scan_length; i++)
			{
				y -= 1;
				current_number += 1;
				matrix[x][y] = number[current_number];
			}
			//down scan_length step
			for (int i = 0;i < scan_length; i++)
			{
				x += 1;
				current_number += 1;
				matrix[x][y] = number[current_number];
			}
		}
		scan_length += 1;
	}
	for (int i = 0;i < scan_length - 1; i++)
	{
		y += 1;
		current_number += 1;
		matrix[x][y] = number[current_number];
	}
}

void print_spiral(vector<vector<int> >& matrix, const int size)   /// print the matrix
{
	for (int i = 0;i < size; i++)
	{
		for (int j = 0;j < size; j++)
		{
			if ((matrix[i][j]==0)|(matrix[i][j]==1))
			{
				cout << ".";
			}
			else
			{
				cout << "#";
			}
			
		}
		cout << endl;
	}
}

int main()
{
	do_prime_spiral(5, 1);
	cout << endl;
	do_prime_spiral(25, 11);
	cout << endl;
	do_prime_spiral(35, 0);
	cout << endl;
	do_prime_spiral(50, 31);
	cout << endl;
	do_prime_spiral(101, 41);
}
