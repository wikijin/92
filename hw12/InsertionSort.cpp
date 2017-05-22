//
// Created by TwoDog on 2017/4/25.
//

#include "InsertionSort.h"

/**
 * Constructor.
 * @param name the name of the algorithm.
 */
InsertionSort::InsertionSort(string name) : VectorSorter(name) {}

/**
 * Destructor.
 */
InsertionSort::~InsertionSort() {}

/**
 * Run the insertion sort algorithm.
 * @throws an exception if an error occurred.
 */
void InsertionSort::run_sort_algorithm() throw (string)
{
    /***** Complete this member function. *****/
    for (int i = 1; i < size; ++i) {
        long val = data[i].get_value();
        int j = i - 1;
        for (; j >= 0; --j) {
            compare_count++;
            if (val >= data[j].get_value())
                break;
        }
        Element temp = data[i];
        for (int k = i - 1; k > j; --k) {
            data[k + 1] = data[k];
            move_count++;
        }
        data[j + 1] = temp;
    }
}

