#include "SortedLinkedList.h"

    /***** Complete this file. *****/
    
/**
 * Insert a new node into the sorted linked list.
 * Uses the overloaded Node::operator > to compare nodes.
 * @param node points to the node to insert.
 */
SortedLinkedList::~SortedLinkedList()
{
    Node *prev = NULL;
    Node *current = head;
    while (current)
    {
        prev = current;
        current = current->next;
        delete prev;
    }
}

void SortedLinkedList::insert(Node *node)
{
    /***** Complete this function. *****/
    if (!head)
    {
        head = node;
        return ;
    }
    Node *prev = NULL;
    Node *current = head;
    while (current && *node > *current)
    {
        prev = current;
        current = current->next;
    }

    node->next = current;
    if (prev)
        prev->next = node;
    else
        head = node;

}

ostream& operator <<(ostream& outs, const SortedLinkedList& list)
{
    Node *current = list.head;

    while (current)
    {
        //outs << current->get_row() << "," << current->get_col() << endl;
        outs << *current;
        current = current->next;
    }
    return outs;
}
