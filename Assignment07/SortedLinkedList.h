#ifndef SORTEDLINKEDLIST_H_
#define SORTEDLINKEDLIST_H_

#include "Node.h"

/**
 * A singly-linked list of Node objects that is sorted
 * by the nodes' rows and columns.
 */
class SortedLinkedList
{
public:
    // Constructor and destructor.
    SortedLinkedList();
    virtual ~SortedLinkedList();

    // Getter.
    Node *get_head() const { return head; }

    void insert(Node *node);

    // Overloaded stream output insertion operator.
    friend ostream& operator <<(ostream& outs, const SortedLinkedList& list);

private:
    Node *head;  // pointer to the head of the linked list
};

#endif /* SORTEDLINKEDLIST_H_ */
