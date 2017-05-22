//**
//**
//* Test the binary search tree and AVL tree implementations.
//* The AVL tree is derived from the binary search tree.
//*
//* Create a tree of height 5 and then repeatedly
//* delete the root. The AVL tree should remain balanced
//* after each node insertion and deletion.
//*/

#include <iostream>
#include <vector>
#include <time.h>

#include "BinarySearchTree.h"
#include "AvlTree.h"
#include "BinaryTreeChecker.h"
#include "BinaryTreePrinter.h"

using namespace std;

const bool DUMP = false;

void testBST();
void testAVL();

void buildTree(BinarySearchTree& tree,
               BinaryTreeChecker& checker,
               BinaryTreePrinter& printer,
               string kind,
               int quantity);

void dismantleTree(BinarySearchTree& tree,
                   BinaryTreeChecker& checker,
                   BinaryTreePrinter& printer);

/**
 * Main.
 */
int main( )
{
    testBST();
    //testAVL();
}

double diffclock(clock_t clock1,clock_t clock2)
{
    double diffticks=clock1-clock2;
    double diffms=(diffticks)/(CLOCKS_PER_SEC/1000);
    return diffms;
}

/**
 * Run the test with a binary search tree.
 */
void testBST()
{
    cout << endl;
    cout << "**********************" << endl;
    cout << "* BINARY SEARCH TREE *" << endl;
    cout << "**********************" << endl;

    BinarySearchTree  tree;
    BinaryTreeChecker checker(tree);
    BinaryTreePrinter printer(tree);

    for (int n = 10000; n <= 100000; n += 10000) {
        clock_t start = clock();
        buildTree(tree, checker, printer, "BST", n);
        dismantleTree(tree, checker, printer);
        clock_t end = clock();
        cout << "Count of Milliseconds" << endl;
        cout << diffclock(end, start)<< endl;
        cout << "Count of Probes" << endl;
        cout << tree.count_of_probes << endl;
        cout << "Count of Comparison" << endl;
        cout << tree.count_of_comparison << endl;
    }
}

/**
 * Run the test with an AVL tree.
 */
void testAVL()
{
    cout << endl;
    cout << "************" << endl;
    cout << "* AVL TREE *" << endl;
    cout << "************" << endl;

    AvlTree tree;
    BinaryTreeChecker checker(tree);
    BinaryTreePrinter printer(tree);
    for (int n = 10000; n <= 100000; n += 10000) {
        clock_t start = clock();
        buildTree(tree, checker, printer, "AVL", n);
        dismantleTree(tree, checker, printer);
        clock_t end = clock();
        cout << "Count of Milliseconds" << endl;
        cout << diffclock(end, start)<< endl;
        cout << "Count of Probes" << endl;
        cout << tree.count_of_probes << endl;
        cout << "Count of Comparison" << endl;
        cout << tree.count_of_comparison << endl;
    }
}

//static const int VALUES[] = {
//        62,71,29,88,11,41,21,66,57,27,39,40,77,20,51,49,82,37,
//        94,63,76,91,70,64,60,90,12,80,23,10,52,35,96,75,28
//};

/**
 * Build a binary search tree containing unique random integer data items.
 * @param tree the tree to make.
 * @param maxNodes the maximum number of nodes to generate.
 * @param checker the binary tree checker to use.
 * @param printer the binary tree printer to use.
 * @param insertPrint true iff print a message after each node insertion
 */
void buildTree(BinarySearchTree& tree,
               BinaryTreeChecker& checker,
               BinaryTreePrinter& printer,
               string kind,
               int quantity)
{


    for (int n = 0; n < quantity; ++n)
    {
        int x = rand() % 100000;
        //cout << endl << "Inserted node " << n << ":" << endl;

        tree.insert(x);  // insert into tree
        checker.add(x);  // store with the tree checker

        //cout << endl;
        //printer.print();
    }

    cout << endl;
    cout << "*****" << endl;
    cout << "***** COMPLETED " << kind << " TREE:" << endl;
    cout << "*****" << endl << endl;
    //printer.print();
}

/**
 * Dismantle a binary tree.
 * @param tree the tree to test.
 * @param checker the binary tree checker to use.
 * @param printer the binary tree printer to use.
 */
void dismantleTree(BinarySearchTree& tree,
                   BinaryTreeChecker& checker,
                   BinaryTreePrinter& printer)
{
    int status = BinaryTreeChecker::NO_ERROR;

    // Delete the root node each time through the loop.
    // Print the tree after each deletion.
    while (!tree.isEmpty())
    {
        BinaryNode *root = tree.getRoot();
        int data = root->data;
        //cout << endl << "Deleted root node " << data << ":" << endl;

        tree.remove(data);
        checker.remove(data);

        //cout << endl;
        //printer.print();

        status = checker.check(DUMP);
        if (status != BinaryTreeChecker::NO_ERROR) break;
    }

    // What was the status?
    string msg;
    switch (status)
    {
        case BinaryTreeChecker::NO_ERROR:
        {
            msg = ">>>>> The tree is now empty.";
            break;
        }
        case BinaryTreeChecker::DATA_MISMATCH:
        {
            msg =  ">>>>> Data mismatch.";
            break;
        }
        case BinaryTreeChecker::INSUFFICIENT_DATA:
        {
            msg =  ">>>>> Data missing from tree.";
            break;
        }
        case BinaryTreeChecker::REMAINING_DATA:
        {
            msg =  ">>>>> Data remaining in tree.";
            break;
        }
    }
    cout << msg << endl;
}