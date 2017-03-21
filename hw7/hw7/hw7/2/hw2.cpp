#include "list.h"

/*
	This function removes every even element from the given linked
	list. For example, if a list contains 16 26 25 12 11 (and then NULL),
	it is modified to contain 25 11 (and then NULL).
*/
void remove_every_even(NodePtr& head)
{
	NodePtr prev = NULL;
    NodePtr next = NULL;
    NodePtr current = head;
    while (current)
    {
        if (current->data % 2)
        {
            prev = current;
            current = current->link;
            continue;
        }
        next = current->link;
        if (!prev)
        {
            head = next;
        }
        else
        {
            prev->link = next;
        }
        delete current;
        current = next;
    }
}
