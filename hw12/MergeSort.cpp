//
// Created by TwoDog on 2017/4/25.
//

#include <string>
#include "MergeSort.h"

/**
 * Constructor.
 * @param name the name of the algorithm.
 */
MergeSort::MergeSort(string name) : ListSorter(name) {}

/**
 * Destructor.
 */
MergeSort::~MergeSort() {}

/**
 * Run the mergesort algorithm.
 * @throws an exception if an error occurred.
 */
void MergeSort::run_sort_algorithm()
throw (string)
{
    // Defensive programming: Make sure we end up
    // with the same size list after sorting.
    int size_before = data.get_size();

    mergesort(data);
    // Check sizes.
    int size_after = data.get_size();
    if (size_before != size_after)
    {
        string message = "***** Size mismatch: before " +
                         to_string(size_before) + ", size after " +
                         to_string(size_after);
        throw message;
    }
}

/**
 * The mergesort algorithm recursively splits and merges data lists.
 * @param list the list of data to sort.
 */
void MergeSort::mergesort(LinkedList& list)
{
    /***** Complete this member function. *****/
    if (list.get_size() <= 1)
        return;
    LinkedList sublist1;
    LinkedList sublist2;
    list.split(sublist1, sublist2);
    mergesort(sublist1);
    mergesort(sublist2);
    merge(list,sublist1,sublist2);
}

/**
 * Merge two sublists back into a single list.
 * @param list the merged list.
 * @param sublist1 the first sublist.
 * @param sublist2 the second sublist.
 */
void MergeSort::merge(LinkedList& list,
                      LinkedList& sublist1, LinkedList& sublist2)
{
    /***** Complete this member function. *****/
    LinkedList temp = LinkedList();
//    cout << "debug!" << endl;
//    cout << "sublist1 size" << sublist1.get_size() << endl;
//    sublist1.print();
//    cout << "sublist2 size" << sublist2.get_size() << endl;
//    sublist2.print();
    while (sublist1.get_size()!= 0 && sublist2.get_size()!=0)
    {
        Node * head1 = sublist1.get_head();
        Node * head2 = sublist2.get_head();
        compare_count++;
        move_count++;
        if (head1->element.get_value() >= head2->element.get_value())
            temp.add(sublist2.remove_head());
        else
            temp.add(sublist1.remove_head());
    }
    //cout << "temp result!" << endl;
    //temp.print();
    if (sublist1.get_size() != 0) {
        move_count+=sublist1.get_size();
        temp.concatenate(sublist1);
    }
    else if (sublist2.get_size() != 0) {
        move_count+=sublist2.get_size();
        temp.concatenate(sublist2);
    }
//    cout << "final result!" << endl;
//    temp.print();
    list = LinkedList(temp.get_head(), temp.get_tail(), temp.get_size());
}

/**
 * Clear the data.
 */
void MergeSort::clear() { data.clear(); }

