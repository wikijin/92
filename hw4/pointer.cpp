#include <iostream>

using namespace std;

void display(int n, int (*arr)[10]);

void display(int n, int (*arr)[10])
{
for(int i=0; i<n; i++)
{
	cout << (*arr)[i]<<" ";
}
}

void display2 (int n, int *p)
{
	for (int j=0; j<n; j++)
	{
		cout<< p[j] << " ";
	}
}

void display3 (int arr[][3], int row ,int col)
{
	for (int k =0 ; k< row; k++)
	{
		for (int l=0 ; l<col ; l++)
		{
			cout << arr[k][l];
		}
	}
}

void display4(int **q, int row, int col )
{
	for (int k =0 ; k< row; k++)
	{
		for (int l=0 ; l<col ; l++)
		{
			cout << q[k][l];
		}
	}
}

int main() 
{
	int array[10] ={1,2,3,4,5,6,7,8,9,10};
	display(10,&array);
	
	int* p;
	p = array;
	display2 (10, p);
	
	int m[2][3] ={{1,2,3},{4,5,6}};
	display3(m, 2, 3);
	
	int** q;
	q = new int*[3];
	int i;
	for(int s =0; s<3 ; s++)
	{
		q[s] =new int [2];
	}
	
	for(int s =0; s<2 ; s++)
	{
		for (int k =0 ;k<3; k++)
		{
		q[s][k] =m[s][k];
		}
	}
	
	display4(q, 2, 3);
	
	return 0;
	
}