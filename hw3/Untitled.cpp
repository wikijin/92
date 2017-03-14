#include <iostream>
#include <fstream>
using namespace std;

const string INPUT_FILE_NAME = "presidents.in";

/**
 * The main: Read the input file and print the report.
 */
int main()
{
	
	// Open the input file.
	ifstream input;
	input.open(INPUT_FILE_NAME);
	if (input.fail())
	{
		cout << "Failed to open " << INPUT_FILE_NAME << endl;
		return -1;
	}
	
	/***** Complete this program. *****/
	string line;
	int i, n;
	
	for(n = 1; n <=44; n++){
	std::getline(input,line);
	cout << line << endl;
	
	}
	input.close();
	

	return 0;
}
