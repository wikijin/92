//
// Created by TwoDog on 2017/4/25.
//
#include "ShellSortSuboptimal.h"

/**
 * Constructor.
 * @param name the name of this algorithm.
 */
ShellSortSuboptimal::ShellSortSuboptimal(string name):VectorSorter(name) {}

/**
 * Destructor.
 */
ShellSortSuboptimal::~ShellSortSuboptimal() {}

/**
 * Run the suboptimal shellsort algorithm.
 * @throws an exception if an error occurred.
 */
void ShellSortSuboptimal::run_sort_algorithm() throw (string)
{
    /***** Complete this member function. *****/
    vector<int> step;
    int gap = 1;
    while (gap <= size / 2) {
        step.push_back(gap);
        gap = 3 * gap + 1;
    }
    int position = step.size() - 1;
    while (position >= 0) {
        gap = step[position];
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
        --position;
    }
}


