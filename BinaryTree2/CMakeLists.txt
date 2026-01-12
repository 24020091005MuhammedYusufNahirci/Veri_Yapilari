cmake_minimum_required(VERSION 4.0)
project(BinaryTree2)

set(CMAKE_CXX_STANDARD 20)

add_executable(BinaryTree2 main.cpp
        Node.h
        Node.cpp
        BinaryTree.h
        BinaryTree.cpp)
