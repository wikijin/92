//
// Created by TwoDog on 2017/4/30.
//

#ifndef HW13_BINARYNODE_H
#define HW13_BINARYNODE_H

class BinaryNode
{
public:
    BinaryNode(const int data);
    BinaryNode(const int data, BinaryNode *left, BinaryNode *right);
    virtual ~BinaryNode();

    int data;
    int height;  // node height

    BinaryNode *left;
    BinaryNode *right;
};


#endif //HW13_BINARYNODE_H
