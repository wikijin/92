cmake_minimum_required(VERSION 3.7)
project(hw13)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp AvlTree.cpp AvlTree.h BinaryNode.cpp BinaryNode.h BinarySearchTree.cpp BinarySearchTree.h BinaryTreeChecker.cpp BinaryTreeChecker.h BinaryTreePrinter.cpp BinaryTreePrinter.h)
add_executable(hw13 ${SOURCE_FILES} AvlTree.cpp AvlTree.h BinaryNode.cpp BinaryNode.h BinarySearchTree.cpp BinarySearchTree.h BinaryTreeChecker.cpp BinaryTreeChecker.h BinaryTreePrinter.cpp BinaryTreePrinter.h)