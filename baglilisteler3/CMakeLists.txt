cmake_minimum_required(VERSION 4.0)
project(baglilisteler3)

set(CMAKE_CXX_STANDARD 20)

add_executable(baglilisteler3 main.cpp
        LinkedList.h
        CircularLinkedList.cpp)
