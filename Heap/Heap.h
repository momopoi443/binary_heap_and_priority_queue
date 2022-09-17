
#ifndef INC_2_3_0_HEAP_H
#define INC_2_3_0_HEAP_H

#include "../Data/Data.h"
#include <vector>

struct Heap{
    std::vector<Data> arr;

    static size_t getParent(size_t index);

    static size_t getLeftChild(size_t index);

    static size_t getRightChild(size_t index);


    Heap() = default;

    void siftUp(size_t index);

    void siftDown(size_t index);
};

#endif
