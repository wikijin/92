//
// Created by TwoDog on 2017/4/25.
//

#include "Node.h"
#include "Element.h"

/***** Complete this class. *****/

using namespace std;

Node::Node() : element(0), next(NULL){}
Node::Node(Element val) : element(val), next(NULL) {}
Node::~Node()
{
    /***** Complete this class. *****/
}

/**
 * Getter.
 * @return the value.
 */

