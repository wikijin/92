#include <map>
#include <set>

using namespace std;

/**
	Invert the given map: Given an int->int map, return a map
	from int->set<int> whose keys are the values of the original
	map, and whose values are the keys from the original map mapping
	to the given values. For example, the inverse of the map

	1 -> 2, 2 -> 2, 3 -> 3

	is the map

	2 -> { 1, 2 }
	3 -> { 3 }
*/

map<int, set<int>> invert(const map<int, int>& m)
{
	...
}
