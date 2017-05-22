cmake_minimum_required(VERSION 3.7)
project(Node_signed)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
        Node.cpp
        Node.h
        SortedList.cpp
        SortedList.h
        SortedVector.cpp
        SortedVector.h
        TestSuite.cpp)

add_executable(Node_signed ${SOURCE_FILES})