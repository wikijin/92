//
// Created by TwoDog on 2017/4/25.
//

#include <iostream>
#include "QuickSorter.h"
using namespace std;

/**
 * Constructor.
 * @param name the name of this algorithm.
 */
QuickSorter::QuickSorter(string name):VectorSorter(name) {}

/**
 * Destructor.
 */
QuickSorter::~QuickSorter() {}

/**
 * Run the quicksort algorithm.
 * @throws an exception if an error occurred.
 */
void QuickSorter::run_sort_algorithm() throw (string)
{
    quicksort(0, size-1);
}

/**
 * The quicksort algorithm recursively sorts data subranges.
 * @param left the left index of the subrange to sort.
 * @param right the right index of the subrange to sort.
 */
void QuickSorter::quicksort(const int left, const int right)
{
    /***** Complete this member function. *****/
    if (left >= right)
        return;
    else if (left == right - 1){
        compare_count++;
        if (data[left].get_value() > data[right].get_value())
            swap(left, right);
    } else {
        Element element = choose_pivot(left, right);
        int position = partition(left, right, element);
        Element temp = data[position];
        data[position] = element;
        data[left] = temp;
        quicksort(left, position - 1);
        quicksort(position + 1, right);
    }

}

/**
 * Choose the pivot according to a pivot strategy.
 * The chosen pivot will be moved temporarily to the right end.
 * @param left the left index of the partition to sort.
 * @param right the right index of the partition to sort.
 * @return the pivot value.
 */
Element& QuickSorter::choose_pivot(const int left, const int right)
{
    return choose_pivot_strategy(left, right);
}

/**
 * Partition the subrange by moving data elements < pivot to the left
 * and data elements > pivot to the right.
 * @param left the left index of the partition to sort.
 * @param right the right index of the partition to sort.
 * @param pivot the pivot value.
 */
int QuickSorter::partition(const int left, const int right, const Element& pivot)
{
    /***** Complete this member function. *****/
    int small = left + 1;
    int big = right;
    while (true) {
        while (small < big && data[small].get_value() < pivot.get_value()) {
            compare_count += 1;
            ++small;
        }
        compare_count++;
        if (small == big)
            break;
        while (small < big && data[big].get_value() >= pivot.get_value()) {
            compare_count += 1;
            --big;
        }
        compare_count++;
        if (small == big)
            break;
        swap(small, big);
    }
    compare_count++;
    if (data[small].get_value() >= pivot.get_value())
        --small;
    return small;
}
