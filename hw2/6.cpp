#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

int main()
{
	vector<char> vec1;
	vector<int> vec2;

	
	
	ifstream input("in.txt",ifstream::in);

	if (!input.is_open())
	{
		cout << "no such a file" << endl;
	}

	
	int i=0;
	char a;
	int b;
	while(input >>a >>b)
	{
		
		vec1.push_back(a);
		vec2.push_back(b);
		
	}

	input.close();

	ofstream output("out.txt",ofstream:: out);
	if(!output.is_open())
	{
		cout << "no such file"<< endl;
	}

	for (int j = 0; j<vec1.size(); j++)
	{
		output << vec1[j]<< " ";
	}
		output << endl;
	for (int k = 0; k<vec2.size(); k++)
	{
		output<< vec2[k]<<" ";
	}

	output.close();

	return 0;
}