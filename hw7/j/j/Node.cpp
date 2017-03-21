#include <math.h>
#include "Node.h"

    /***** Complete this file. *****/

Node::Node(City& city): next(NULL)
{
    name = city.get_name();
    state = city.get_state();
    convert_coordinate(city.get_coordinate());
}

Node::Node(Coordinate& coordinate): next(NULL)
{
    name = "";
    state = "";
    convert_coordinate(coordinate);
}
/**
 * Convert a coordinate's latitude and longitude
 * into a row and column, respectively, for printing.
 */
void Node::convert_coordinate(const Coordinate& coordinate)
{
    row = round(2*(Coordinate::MAX_LATITUDE - coordinate.get_latitude()));
    col = round(2*(coordinate.get_longitude() - Coordinate::MIN_LONGITUDE));
}

/**
 * Overloaded > operator used to determine
 * where to insert a node into the linked list.
 * The list is sorted first by row and then by column.
 */
bool Node::operator >(const Node &other)
{
    /***** Complete this function. *****/
    if (row > other.row)
        return true;
    if (row < other.row)
        return false;
    if (col > other.col)
        return true;
    return false;
}

ostream& operator <<(ostream& outs, const Node& node)
{
    if (node.name != "")
    {
        outs << "*" << node.name << " " << node.state;
    }
    else
    {
        outs << "#";
    }
    return outs;
}
