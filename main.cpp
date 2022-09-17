#include <iostream>
#include <vector>
#include <random>
#include <chrono>
#include <queue>
#include <cstdlib>
#include <ctime>
#include "Heap/Heap.h"
#include "Data/Data.h"
#include "PriorityQueue/PriorityQueue.h"

using namespace std::literals;

using namespace std;


template <typename T>
float testPriorityQueueSpeed(T&& priorityQueue)
{
    const int iters = 100000;
    clock_t timeStart = clock();
    for (int i = 0; i < iters; i++)
    {
        int insertDataAmount = rand() % 6 + 5;
        for (int j = 0; j < insertDataAmount; j++)
        {
            priorityQueue.push(Data());
        }
        priorityQueue.top();
        priorityQueue.pop();
    }
    clock_t timeEnd = clock();
    float time = (float(timeEnd - timeStart)) / CLOCKS_PER_SEC;
    return time;
}

bool testPriorityQueue()
{
    srand(time(NULL));
    const int iters = 20'000'000;
    PriorityQueue myPriorQueue;

    priority_queue<Data> stlPriorQueue;
    bool isDataEqual = true;
    for (int i = 0; i < iters; i++)
    {
        int insertDataAmount = rand() % 6 + 5;
        for (int j = 0; j < insertDataAmount; j++)
        {
            Data randData = Data();
            myPriorQueue.push(randData);
            stlPriorQueue.push(randData);
        }
        if (!(myPriorQueue.top() == stlPriorQueue.top()))
        {
            isDataEqual = false;
            cerr << "Comparing failed on iteration " << i << endl << endl;
            break;
        }
        int removeDataAmount = rand() % insertDataAmount;
        for (int j = 0; j < removeDataAmount; j++)
        {
            myPriorQueue.pop();
            stlPriorQueue.pop();
        }
    }

    int myQueueSize = myPriorQueue.size();
    int stlQueueSize = stlPriorQueue.size();
    float stlTime =
            testPriorityQueueSpeed<priority_queue<Data>>(priority_queue<Data>());
    float myTime = testPriorityQueueSpeed<PriorityQueue>(PriorityQueue());
    cout << "My PriorityQueue:" << endl;
    cout << "Time: " << myTime << ", size: " << myQueueSize << endl;
    cout << "STL priority_queue:" << endl;
    cout << "Time: " << stlTime << ", size: " << stlQueueSize << endl << endl;
    if (isDataEqual && myQueueSize == stlQueueSize)
    {
        cout << "The lab is completed" << endl << endl;
        return true;
    }
    cerr << ":(" << endl << endl;
    return false;
}

void heapify(std::vector<long>& arr, size_t size, size_t index) {
    size_t left = Heap::getLeftChild(index);

    while (left < size) {
        size_t largest = left;
        if (left + 1 < size)
            largest += arr[left] < arr[left + 1] ? 1: 0;
        if (arr[largest] < arr[index]) break;

        std::swap(arr[index], arr[largest]);

        index = largest;
        left = Heap::getLeftChild(index);
    }
}

void heapSort(std::vector<long>& vec) {
    for (size_t i = vec.size() / 2 - 1; i != ULONG_LONG_MAX; --i) {
        heapify(vec, vec.size(), i);
    }
    for (size_t i = vec.size() - 1; i != ULONG_LONG_MAX; --i) {
        std::swap(vec[0], vec[i]);
        heapify(vec, i, 0);
    }
}

void compare() {
    size_t size = 2'000'000;

    random_device rd;
    mt19937 mt(rd());
    uniform_int_distribution<long> dist(-10'000'000, 10'000'000);

    std::vector<long> vecRand(size), vecSame(size), vecSorted(size), vecSortedPartly(size);
    std::generate(vecRand.begin(), vecRand.end(), [&] () {return dist(mt);});
    std::generate(vecSame.begin(), vecSame.end(), [&] () {return 5;});
    std::generate(vecSorted.begin(), vecSorted.end(), [&] () {return dist(mt);});
    std::generate(vecSortedPartly.begin(), vecSortedPartly.end(), [&] () {return dist(mt);});
    std::sort(vecSorted.begin(), vecSorted.end());
    std::sort(vecSortedPartly.begin(), vecSortedPartly.end() - size / 3);

    auto buff = vecRand;
    auto start = std::chrono::steady_clock::now();
    heapSort(buff);
    auto end = std::chrono::steady_clock::now();
    auto start1 = std::chrono::steady_clock::now();
    std::sort(vecRand.begin(), vecRand.end());
    auto end1 = std::chrono::steady_clock::now();
    std::cout << "Full rand values" << std::endl;
    std::cout
        << "Heap sort: " << (end - start) / 1ms << "ms" << std::endl
        << "Std sort: " << (end1 - start1) / 1ms << "ms" << std::endl;

    buff = vecSame;
    start = std::chrono::steady_clock::now();
    heapSort(buff);
    end = std::chrono::steady_clock::now();
    start1 = std::chrono::steady_clock::now();
    std::sort(vecSame.begin(), vecSame.end());
    end1 = std::chrono::steady_clock::now();
    std::cout << "Full same values" << std::endl;
    std::cout
        << "Heap sort: " << (end - start) / 1ms << "ms" << std::endl
        << "Std sort: " << (end1 - start1) / 1ms << "ms" << std::endl;

    buff = vecSorted;
    start = std::chrono::steady_clock::now();
    heapSort(buff);
    end = std::chrono::steady_clock::now();
    start1 = std::chrono::steady_clock::now();
    std::sort(vecSorted.begin(), vecSorted.end());
    end1 = std::chrono::steady_clock::now();
    std::cout << "Full sorted values" << std::endl;
    std::cout
        << "Heap sort: " << (end - start) / 1ms << "ms" << std::endl
        << "Std sort: " << (end1 - start1) / 1ms << "ms" << std::endl;

    buff = vecSortedPartly;
    start = std::chrono::steady_clock::now();
    heapSort(buff);
    end = std::chrono::steady_clock::now();
    start1 = std::chrono::steady_clock::now();
    std::sort(vecSortedPartly.begin(), vecSortedPartly.end());
    end1 = std::chrono::steady_clock::now();
    std::cout << "Partly sorted values" << std::endl;
    std::cout
        << "Heap sort: " << (end - start) / 1ms << "ms" << std::endl
        << "Std sort: " << (end1 - start1) / 1ms << "ms" << std::endl;
}

int main() {
    compare();
    //testPriorityQueue();
    return 0;
}
