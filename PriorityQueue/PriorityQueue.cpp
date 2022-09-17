
#include <iostream>
#include "PriorityQueue.h"

void PriorityQueue::push(const Data& obj) {
    maxHeap.arr.push_back(obj);
    maxHeap.siftUp(maxHeap.arr.size() - 1);
}

Data PriorityQueue::top() {
    try {
        return maxHeap.arr.at(0);
    } catch (std::exception& e) {
        std::cerr << "Exception caught : " << e.what() << std::endl;
    }
    return {};
}

void PriorityQueue::pop() {
    try {
        std::swap(maxHeap.arr[0], maxHeap.arr[maxHeap.arr.size() - 1]);
        maxHeap.arr.pop_back();
        maxHeap.siftDown(0);
    } catch (std::exception& e) {
        std::cerr << "Exception caught : " << e.what() << std::endl;
    }
}

size_t PriorityQueue::size() const {return maxHeap.arr.size();}

bool PriorityQueue::empty() const {return maxHeap.arr.empty();}

