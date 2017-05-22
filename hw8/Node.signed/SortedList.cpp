#include <iostream>
#include <iterator>
#include "SortedList.h"

using namespace std;

/**
 * Defaut constructor.
 * Reset the global Node counters.
 */
SortedList::SortedList()
{
    Node::reset();
}

/**
 * Destructor.
 * Reset the global Node counters.
 */
SortedList::~SortedList()
{
    Node::reset();
}

/**
 * @return the size of the data list.
 */
int SortedList::size() const { return data.size(); }

/**
 * Check that the data is sorted.
 * @return true if sorted, false if not.
 */
bool SortedList::check()
{
    if (data.size() == 0) return true;

    list<Node>::iterator it = data.begin();
    list<Node>::iterator prev = it;

    it++;

    // Ensure that each node is greater than the previous node.
    while ((it != data.end()) && (*it > *prev))
    {
        prev = it;
        it++;
    }

    return it == data.end();  // Good if reached the end.
}

/**
 * Insert a new node at the beginning of the data list.
 * @param value the new node's value.
 */
void SortedList::prepend(const long value)
{
    /***** Complete this function. *****/
    Node node(value);
    data.push_front(node);
}

/**
 * Append a new node at the end of the data list.
 * @param value the new node's value.
 */
void SortedList::append(const long value)
{
    /***** Complete this function. *****/
    Node node(value);
    data.push_back(node);
}

/**
 * Remove a node.
 * @param index the index of the node to remove.
 */
void SortedList::remove(const int index)
{
    /***** Complete this function. *****/
    int i = 0;
    list<Node>::iterator it = data.begin();
    while (i != index && it != data.end())
    {
        ++i;
        ++it;
    }
    if (it != data.end())
        data.erase(it);
}

/**
 * Insert a new node into the data list at the
 * appropriate position to keep the list sorted.
 */
void SortedList::insert(const long value)
{
    /***** Complete this function. *****/
    Node node(value);
    list<Node>::iterator it = data.begin();
    for (;it != data.end(); ++it)
    {
        if (it->get_value() >= value)
        {
            data.insert(it, node);
            return ;
        }
    }
    data.insert(it, node);
}

/**
 * Return the data node at the indexed position.
 * @param the index of the node.
 * @return a copy of the data node.
 */
Node SortedList::at(const int index)
{
    /***** Complete this function. *****/
    int i = 0;
    list<Node>::iterator it = data.begin();
    while (i != index && it != data.end())
    {
        ++i;
        ++it;
    }
    return *it;
}
