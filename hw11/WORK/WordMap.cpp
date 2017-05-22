#include <iostream>
#include <map>
#include <string>
#include "WordMap.h"

using namespace std;
using namespace std::chrono;

WordMap::WordMap()
{
}

WordMap::~WordMap()
{
}

map<string, Word>& WordMap::get_data() { return data; }

int WordMap::get_count(const string text) const
{
    /***** Complete this member function. *****/
    map<string, Word>::const_iterator it = data.find(text);
    if (it == data.end())
        return 0;
    return it->second.get_count();
}

void WordMap::insert(const string text)
{
    /***** Complete this member function. *****/
    chrono::time_point<chrono::high_resolution_clock> begint = chrono::high_resolution_clock::now();
    if (data.find(text) == data.end())
        data[text] = Word(text);
    else
        data[text].increment_count();
    chrono::time_point<chrono::high_resolution_clock> endt = chrono::high_resolution_clock::now();
    unsigned long ts = chrono::duration_cast<chrono::microseconds>(endt - begint).count();
    increment_elapsed_time(ts);
}

map<string, Word>::iterator WordMap::search(const string text)
{
    /***** Complete this member function. *****/
    chrono::time_point<chrono::high_resolution_clock> begint = chrono::high_resolution_clock::now();
    map<string, Word>::iterator it = data.find(text);
    chrono::time_point<chrono::high_resolution_clock> endt = chrono::high_resolution_clock::now();
    unsigned long ts = chrono::duration_cast<chrono::microseconds>(endt - begint).count();
    increment_elapsed_time(ts);
    return it;
}
