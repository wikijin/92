//
// Created by TwoDog on 2017/4/25.
//

#ifndef HW12_QUICKSORTSUBOPTIMAL_H
#define HW12_QUICKSORTSUBOPTIMAL_H

//#ifndef QUICKSORTSUBOPTIMAL_H_
//#define QUICKSORTSUBOPTIMAL_H_

#include "QuickSorter.h"

/**
 * The class that implements the suboptimal quicksort algorithm
 * for a vector of data by using a bad pivot strategy.
 */
class QuickSortSuboptimal: public QuickSorter
{
public:
    QuickSortSuboptimal(string name);
    virtual ~QuickSortSuboptimal();

private:
    virtual Element& choose_pivot_strategy(const int left, const int right);
};

//#endif /* QUICKSORTSUBOPTIMAL_H_ */

#endif //HW12_QUICKSORTSUBOPTIMAL_H
