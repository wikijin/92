#include <iostream>
#include <iterator>
#include "SortedVector.h"

using namespace std;

/**
 * Defaut constructor.
 * Reset the global Node counters.
 */
SortedVector::SortedVector()
{
    Node::reset();
}

/**
 * Destructor.
 * Reset the global Node counters.
 */
SortedVector::~SortedVector()
{
    Node::reset();
}

/**
 * @return the size of the data vector.
 */
int SortedVector::size() const { return data.size(); }

/**
 * Check that the data is sorted.
 * @return true if sorted, false if not.
 */
bool SortedVector::check() const
{
    if (data.size() == 0) return true;

    vector<Node>::const_iterator it = data.begin();
    vector<Node>::const_iterator prev = it;

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
 * Insert a new node at the beginning of the data vector.
 * @param value the new node's value.
 */
void SortedVector::prepend(const long value)
{
    /***** Complete this function. *****/
    Node node(value);
    data.insert(data.begin(), node);
}

/**
 * Append a new node at the end of the data vector.
 * @param value the new node's value.
 */
void SortedVector::append(const long value)
{
    /***** Complete this function. *****/
    Node node(value);
    data.push_back(node);
}

/**
 * Remove a node.
 * @param index the index of the node to remove.
 */
void SortedVector::remove(const int index)
{
    /***** Complete this function. *****/
    int i = 0;
    vector<Node>::iterator it = data.begin();
    while (i != index && it != data.end())
    {
        ++i;
        ++it;
    }
    if (it != data.end())
        data.erase(it);
}

/**
 * Insert a new node into the data vector at the
 * appropriate position to keep the vector sorted.
 */
void SortedVector::insert(const long value)
{
    /***** Complete this function. *****/
    Node node(value);
    vector<Node>::iterator it = data.begin();
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
Node SortedVector::at(const int index) const
{
    /***** Complete this function. *****/
    return data.at(index);
}
