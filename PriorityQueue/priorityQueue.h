#ifndef _priorityQueue_h
#define _priorityQueue_h
#include <iostream>
#include "D:\VsCode_Cpp\Data_Structure\Queue\queue.h"
using namespace std;

//最小化堆
template <class Type>
class priorityQueue : public queue<Type>
{
private:
    int currentSize;
    Type *array;
    int maxsize;

    void doubleSpace();
    void buildHeap();
    void percolateDown(int hole);

public:
    priorityQueue(int capacity = 100);
    priorityQueue(const Type data[], int size);
    ~priorityQueue();
    bool isEmpty() const;
    void enQueue(const Type &x);
    Type deQueue();
    Type getHead() const;
    //
    void printPQ() const;
    //家庭作业
    int findMin(Type x) const;           //书P234 T7（1） 找到优先级大于等于x的最小元素，返回其下标    //jyq：可用栈实现
    void decreaseKey(int i, Type value); //书P234 T7（2） 将第i个结点的优先级值减少value
};

#endif