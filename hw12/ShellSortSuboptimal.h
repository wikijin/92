//
// Created by TwoDog on 2017/4/25.
//

#ifndef HW12_SHELLSORTSUBOPTIMAL_H
#define HW12_SHELLSORTSUBOPTIMAL_H


//#ifndef SHELLSORTSUBOPTIMAL_H_
//#define SHELLSORTSUBOPTIMAL_H_

#include "VectorSorter.h"

/**
 * The class that implements the suboptimal Shellsort algorithm
 * for a vector of data, where the diminishing increment is halved
 * for each pass.
 */
class ShellSortSuboptimal: public VectorSorter
{
public:
    ShellSortSuboptimal(string name);
    virtual ~ShellSortSuboptimal();

    virtual void run_sort_algorithm() throw (string);
};

//#endif /* SHELLSORTSUBOPTIMAL_H_ */


#endif //HW12_SHELLSORTSUBOPTIMAL_H
