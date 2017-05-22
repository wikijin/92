//
// Created by TwoDog on 2017/4/25.
//

#ifndef HW12_LISTSORTER_H
#define HW12_LISTSORTER_H

//#ifndef LISTSORTER_H_
//#define LISTSORTER_H_

#include <string>
#include "Sorter.h"
#include "LinkedList.h"

/**
 * Abstract base class of the singly linked list sorting algorithms.
 */
class ListSorter: public Sorter
{
public:
    ListSorter(string name);
    virtual ~ListSorter();

    virtual void generate_data(DataGenerator *generator, int size);
    void print_data() const;
    void clear_data();

protected:
    LinkedList data;  // the data to sort

    bool is_data_sorted() const;
};

//#endif /* LISTSORTER_H_ */

#endif //HW12_LISTSORTER_H