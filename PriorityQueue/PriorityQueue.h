
#ifndef INC_2_3_0_PRIORITYQUEUE_H
#define INC_2_3_0_PRIORITYQUEUE_H

#include "../Heap/Heap.h"

struct PriorityQueue {
    Heap maxHeap;

    void push(const Data& obj);

    Data top();

    void pop();

    size_t size() const;

    bool empty() const;
};

#endif