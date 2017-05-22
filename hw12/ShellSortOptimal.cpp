//
// Created by TwoDog on 2017/4/25.
//

#include "ShellSortOptimal.h"

/**
 * Constructor.
 * @param name the name of this algorithm.
 */
ShellSortOptimal::ShellSortOptimal(string name) :VectorSorter(name) {}

/**
 * Destructor.
 */
ShellSortOptimal::~ShellSortOptimal() {}

/**
 * Run the optimal shellsort algorithm.
 * According to Don Knuth:
 * h = 3*i + 1 for i = 0, 1, 2, ... used in reverse.
 * @throws an exception if an error occurred.
 */
void ShellSortOptimal::run_sort_algorithm() throw (string)
{
    /***** Complete this member function. *****/
    int gap = size / 2;
    while (gap >= 1) {
        for (int i = 0; i < gap; ++i) {
            for (int j = gap + i; j < size; j = j + gap) {
                int k = j - gap;
                for (; k >= 0; k = k - gap) {
                    compare_count++;
                    if (data[k].get_value() <= data[j].get_value())
                        break;
                }
                Element temp = data[j];
                for(int l = j - gap; l >= k; l = l - gap) {
                    data[l + gap] = data[l];
                    if (l != k)
                        move_count++;
                }
                data[k + gap] = temp;
            }
        }
        gap = gap / 2;
    }
}

