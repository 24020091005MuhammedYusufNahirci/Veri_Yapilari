cmake_minimum_required(VERSION 4.0)
project(binarytree)

set(CMAKE_CXX_STANDARD 20)

add_executable(binarytree main.cpp
        Node.h
        BinaryTree.h
        BinaryTree.cpp
        Node.cpp)
