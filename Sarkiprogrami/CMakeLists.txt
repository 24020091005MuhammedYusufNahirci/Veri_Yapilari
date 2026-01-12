cmake_minimum_required(VERSION 4.0)
project(Sarkiprogrami)

set(CMAKE_CXX_STANDARD 20)

add_executable(Sarkiprogrami main.cpp
        Node.h
        Playlist.h
        Song.h
        Playlist.cpp)
