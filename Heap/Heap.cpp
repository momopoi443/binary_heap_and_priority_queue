
#include "Heap.h"

size_t Heap::getParent(size_t index) {
    return (index - 1) / 2;
}

size_t Heap::getLeftChild(size_t index) {
    return 2 * index + 1;
}

size_t Heap::getRightChild(size_t index) {
    return 2 * index + 2;
}


void Heap::siftUp(size_t index) {
    size_t parent = getParent(index);

    while(index != 0) {
        if (arr[index] < arr[parent]) break;

        std::swap(arr[index], arr[parent]);

        index = parent;
        parent = getParent(index);
    }
}

void Heap::siftDown(size_t index) {
    size_t left = getLeftChild(index);

    while (left < arr.size()) {
        size_t largest = left;
        if (left + 1 < arr.size())
            largest += arr[left] < arr[left + 1] ? 1: 0;
        if (arr[largest] < arr[index]) break;

        std::swap(arr[index], arr[largest]);

        index = largest;
        left = getLeftChild(index);
    }
}