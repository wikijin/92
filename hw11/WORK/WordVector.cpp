#include <iostream>
#include <vector>
#include <string>
#include "WordVector.h"

using namespace std;
using namespace std::chrono;

WordVector::WordVector()
{
}

WordVector::~WordVector()
{
}

vector<Word>& WordVector::get_data() { return data; }

int WordVector::get_count(const string text) const
{
    /***** Complete this member function. *****/
    int pos = find(text, 0, data.size());
    if (pos == -1)
        return 0;
    else
        return data[pos].get_count();
}

void WordVector::insert(const string text)
{
    /***** Complete this member function. *****/
    chrono::time_point<chrono::high_resolution_clock> begint = chrono::high_resolution_clock::now();
    if (data.size() == 0)
    {
        Word word(text);
        data.push_back(word);
    }
    else
    {
        int pos = find(text, 0, data.size());
        if (pos == -1)
        {
            bool sett = false;
            Word word(text);
            for (vector<Word>::iterator it = data.begin();
                it != data.end(); ++it)
            {
                if (it->get_text().compare(text) < 0)
                    continue;
                data.insert(it, word);
                sett = true;
                break;
            }
            if (!sett)
                data.push_back(word);
        }
        else
        {
            data[pos].increment_count();
        }
    }
    chrono::time_point<chrono::high_resolution_clock> endt = chrono::high_resolution_clock::now();
    unsigned long ts = chrono::duration_cast<chrono::microseconds>(endt - begint).count();
    increment_elapsed_time(ts);
}

vector<Word>::iterator WordVector::search(const string text)
{
    /***** Complete this member function. *****/
    chrono::time_point<chrono::high_resolution_clock> begint = chrono::high_resolution_clock::now();
    vector<Word>::iterator it = data.end();
    int pos = find(text, 0, data.size());
    if (pos != -1)
        it = data.begin() + pos;
    chrono::time_point<chrono::high_resolution_clock> endt = chrono::high_resolution_clock::now();
    unsigned long ts = chrono::duration_cast<chrono::microseconds>(endt - begint).count();
    increment_elapsed_time(ts);
    return it;
}

int WordVector::find(const string text, int low, int high) const
{
    /***** Complete this member function. *****/
    chrono::time_point<chrono::high_resolution_clock> begint = chrono::high_resolution_clock::now();
    int head = low;
    int rear = high;
    while (head < rear)
    {
        int mid = (head + rear) / 2;
        if (data[mid].get_text() == text)
        {
            return mid;
        }
        if (data[mid].get_text().compare(text) > 0)//myword > word
        {
            rear = mid;
        }
        else//myword < word
        {
            head = mid + 1;
        }
    }
    return -1;
}
