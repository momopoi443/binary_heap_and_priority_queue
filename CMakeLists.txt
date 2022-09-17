cmake_minimum_required(VERSION 3.21)
project(2_3_0)

set(CMAKE_CXX_STANDARD 20)

add_executable(2_3_0 main.cpp
        Heap/Heap.cpp Heap/Heap.h
        Data/Data.cpp Data/Data.h
        PriorityQueue/PriorityQueue.cpp PriorityQueue/PriorityQueue.h)
