#include "list.h"

/*
	This function removes every second element from the given linked
	list. For example, if a list contains 12 15 26 25 11 (and then NULL),
	it is modified to contain 12 26 11 (and then NULL).
*/
void remove_every_second(NodePtr head)
{
    NodePtr current = head;
    NodePtr next;
    NodePtr next2;
    while (current)
    {
        next = current->link;
        if (next)
        {
            current->link = next->link;
            delete next;
        }
        current = current->link;
    }
}
