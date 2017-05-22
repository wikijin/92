#include <vector>
#include <map>
#include <string>
using namespace std;

/**
	Makes a map associating integers with the number of words 
	whose length is the given integer.
	@param words a vector of strings
	@return the map

*/
map<int, int> lengthFrequency(vector<string> words)
{
    map<int, int> counter;
    for (vector<string>::iterator it = words.begin();
        it != words.end(); ++it)
    {
        int size = it->size();
        counter[size] = counter[size] + 1;
    }
    return counter;
}
