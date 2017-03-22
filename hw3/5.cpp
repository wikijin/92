#include <vector>
#include <cmath>
#include "png.h"
#include <stdlib.h>

using namespace std;

/**
 * Computes the average of the neighbors of v[i][j]. There are 
 * eight neighbors if the element is in the interior of the 2D array,
 * fewer if it is on a boundary. The element itself is not contained
 * in the average.
 */
double neighbor_average(const vector<vector<int>>& v, int i, int j)
{
	int count = 0;
	int sum = 0;
	
	for (int di = -1; di <= 1; di++)
	   for (int dj = -1; dj <= 1; dj++)
	      if (((i+di)>=0)&&((i+di)<v.size())&&((j+dj)<v[0].size())&&((j+dj)>=0)&&(abs(di)+abs(dj)!=0)))
			{
				count++;
				sum = sum + v[i+di][j+dj];
			}
	         
	
	return sum * 1.0 / count;
}

int main(int argc, char *argv[])
{
	vector<vector<int>> image = readGrayscaleImage("blimp.png");
	int width = image[0].size();
	int height = image.size();

	vector<vector<int>> image2(height);
	for (int i = 0; i < height; i++) {
		 image2[i] = vector <int> (width);
		 for (int j = 0; j < width; j++) {  
				if (fabs(neighbor_average(image, i, j) - image[i][j]) > 10) 
					 {
						image2[i][j]=0;
					}	
				else
					 {
						image2[i][j]=255;
					}
		 }
	}
		 
	writeGrayscaleImage("out.png", image2);
}
