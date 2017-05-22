//
// Created by TwoDog on 2017/4/25.
//

#ifndef HW12_NODE_H
#define HW12_NODE_H

//#ifndef NODE_H_
//#define NODE_H_

#include "Element.h"

/**
 * A node of the linked list for mergesort.
 */
class Node
{
public:
    /***** Complete this class. *****/
    Node();
    Node(Element val);
    virtual ~Node();

    Element element;
    Node * next;

};



//#endif /* NODE_H_ */


#endif //HW12_NODE_H
