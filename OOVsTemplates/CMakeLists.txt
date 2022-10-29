cmake_minimum_required(VERSION 3.21)
project(OOVsTemplates)

set(CMAKE_CXX_STANDARD 14)

add_executable(OOVsTemplates main.cpp IComparable.cpp IComparable.h OOInt.cpp OOInt.h OOStr.cpp OOStr.h genericWrapper.h mergeSort.h)
