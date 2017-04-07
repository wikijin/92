cmake_minimum_required(VERSION 3.7)
project(Cpp)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
        Node.cpp
        Node.h
        SortedList.cpp
        SortedList.h
        SortedVector.cpp
        SortedVector.h
        STLVectorList.cpp
        TestSuite.cpp)

add_executable(Cpp ${SOURCE_FILES})