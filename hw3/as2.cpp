#include <iostream>
using namespace std;

const int MAX_SIZE  = 101;  // maximum size of the square matrix
const int MAX_START = 50;   // maximum starting number

/***** Complete this program. *****/

//declaration the function
int row, col;

void do_spiral(const int n, const int start);
void make_spiral(int matrix[row][col],int start);
void print_spiral(int matrix[row][col]);
void make_array(const int n, const int start);



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



void make_spiral(int matrix[row][col],int start)
{
	int x=0; //current x position
	int y=0; //current y position
	int d=0; //direction 0:right 1:up 2:left 3:down
	int k=1; //the distance for direction change
	
	//set the start position
	x=(row-1)/2;
	y=(row-1)/2;
	int t = (row)*(row);
	
	int n;
	for (int b=start; b<((n)*(n)+start-1); b++)
	{
		
		
		for (int g=0; g<k ; g++)
		{
			int b;
			matrix[x][y]=b;
			cout << matrix[x][y];
			
			switch(d)
			{
				case 0 : y = y + 1; break;
				case 1 : x = x - 1; break;
				case 2 : y = y - 1; break;
				case 3 : x = x + 1; break;
			}
			d = (d+1) % 4;
		}
		k=k+1;
	}
	
}



void  do_spiral(const int n, const int start)
{
	
	if (n%2==0)
	{
		cout << "***** Error: Size " << n <<  "must be odd."<<endl;
	}
	else {
		
		int mat[n][n]; // make a 0 matrix
		
		
		make_spiral(mat, start);
		
	}
	
}
