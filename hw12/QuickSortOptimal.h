//
// Created by TwoDog on 2017/4/25.
//

#ifndef HW12_QUICKSORTOPTIMAL_H
#define HW12_QUICKSORTOPTIMAL_H

//#ifndef QUICKSORTOPTIMAL_H_
//#define QUICKSORTOPTIMAL_H_

#include "QuickSorter.h"

/**
 * The class that implements the optimal quicksort algorithm
 * for a vector of data by using a good pivot strategy.
 */
class QuickSortOptimal: public QuickSorter
{
public:
    QuickSortOptimal(string name);
    virtual ~QuickSortOptimal();

private:
    virtual Element& choose_pivot_strategy(const int left, const int right);
};

//#endif /* QUICKSORTOPTIMAL_H_ */

#endif //HW12_QUICKSORTOPTIMAL_H
