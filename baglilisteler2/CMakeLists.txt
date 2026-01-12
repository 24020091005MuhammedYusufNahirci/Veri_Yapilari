cmake_minimum_required(VERSION 4.0)
project(baglilisteler2)

set(CMAKE_CXX_STANDARD 20)

add_executable(baglilisteler2 main.cpp
        LinkedList.h
        DoublyLinkedList.cpp)
