//
// Created by TwoDog on 2017/4/30.
//

#ifndef HW13_BINARYSEARCHTREE_H
#define HW13_BINARYSEARCHTREE_H

#include <string>
#include "BinaryNode.h"

using namespace std;

class BinarySearchTree
{
public:
    BinarySearchTree();
    BinarySearchTree(const BinarySearchTree& rhs);
    virtual ~BinarySearchTree();
    long count_of_probes = 0;
    long count_of_comparison = 0;

    BinaryNode *getRoot() const;
    int height() const;
    int findMin() const throw(string);
    int findMax() const throw(string);

    void clear();
    bool isEmpty() const;
    bool contains(const int data) const;
    void insert(const int data);
    void remove(const int data);

protected:
    virtual int height(const BinaryNode *ptr) const;
    virtual void insert(const int data, BinaryNode* &ptr);
    virtual void remove(const int data, BinaryNode* &ptr);

private:
    BinaryNode *root;

    BinaryNode *findMin(BinaryNode *ptr) const;
    BinaryNode *findMax(BinaryNode *ptr) const;
    void clear(BinaryNode* &ptr);
    bool contains(const int data, BinaryNode *ptr) const;
};


#endif //HW13_BINARYSEARCHTREE_H
