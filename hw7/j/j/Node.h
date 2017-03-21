#ifndef NODE_H_
#define NODE_H_

#include "City.h"
#include "Coordinate.h"

/**
 * A linked list node.
 */
class Node
{
public:

    /***** Complete this file. *****/
    Node(City& city);
    Node(Coordinate& coordinate);
    // Public pointer to the next node in the list.
    Node *next;

    // Overloaded > operator.
    bool operator >(const Node& other);

    // Overloaded stream output insertion operator.
    friend ostream& operator <<(ostream& outs, const Node& node);

    int get_row() const { return row; }
    int get_col() const { return col; }

private:
    string name;   // city name,  or the empty string for a border location
    string state;  // city state, or the empty string for a border location
    int row;       // print row
    int col;       // print column

    void convert_coordinate(const Coordinate& coordinate);
};

#endif /* NODE_H_ */
