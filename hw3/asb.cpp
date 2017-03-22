#include <iostream>
#include <iomanip>

using namespace std;

const int MAX_SIZE  = 101;  // maximum size of the square matrix
const int MAX_START = 50;   // maximum starting number

/***** Complete this program. *****/

//function declaration

void do_spiral(const int n, const int start);
void make_spiral(int **matrix, const int size, const int start);
void print_spiral(int **matrix, const int size);

void do_spiral(const int n, const int start)
{
	cout <<"Spiral of size "<< n << " starting at " << start; 
	cout << endl;
	if (n % 2 == 0)  ///size must be odd
	{
		cout << "***** Error: Size " << n << " must be odd."<< endl;
		cout << endl;
		return ;
	}
	cout << endl;
	int **matrix = new int* [n];   ///declare a matrix with size n
	for (int i = 0;i < n; i++)
	{
		matrix[i] = new int[n];
	}
	make_spiral(matrix, n, start);
	print_spiral(matrix, n);
}

void make_spiral(int **matrix, const int size, const int start)
{
	int current_number = start;
	int x = size / 2, y = size / 2;
	matrix[x][y] = start;			///set the start position
	
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
				matrix[x][y] = current_number;
			}
			//top scan_length step
			for (int i = 0;i < scan_length; i++)
			{
				x -= 1;
				current_number += 1;
				matrix[x][y] = current_number;
			}
		}
		else
		{
			//left scan_length step
			for (int i = 0;i < scan_length; i++)
			{
				y -= 1;
				current_number += 1;
				matrix[x][y] = current_number;
			}
			//down scan_length step
			for (int i = 0;i < scan_length; i++)
			{
				x += 1;
				current_number += 1;
				matrix[x][y] = current_number;
			}
		}
		scan_length += 1;
	}
	for (int i = 0;i < scan_length - 1; i++)
	{
		y += 1;
		current_number += 1;
		matrix[x][y] = current_number;
	}
	
}

void print_spiral(int **matrix, const int size)  ///print the matrix
{
	for (int i = 0;i < size; i++)
	{
		for (int j = 0;j < size; j++)
		{
			cout<<setw(3) << matrix[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}

/**
 * The main: Generate and print spirals of various sizes.
*/

int main()
{
	do_spiral(1, 1);
	do_spiral(5, 1);
	do_spiral(9, 11);
	do_spiral(12, 13);
	do_spiral(15, 17);
}