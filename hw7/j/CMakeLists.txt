cmake_minimum_required(VERSION 3.6)
project(j)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
        j/City.cpp
        j/City.h
        j/Coordinate.cpp
        j/Coordinate.h
        j/MapMaker.cpp
        j/Node.cpp
        j/Node.h
        j/SortedLinkedList.cpp
        j/SortedLinkedList.h)

add_executable(j ${SOURCE_FILES})