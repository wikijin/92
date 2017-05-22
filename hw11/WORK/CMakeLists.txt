cmake_minimum_required(VERSION 3.7)
project(WORK)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
        Constitution.cpp
        TimedContainer.cpp
        TimedContainer.h
        USConstitution.txt
        Word.cpp
        Word.h
        WordMap.cpp
        WordMap.h
        WordVector.cpp
        WordVector.h)

add_executable(WORK ${SOURCE_FILES})