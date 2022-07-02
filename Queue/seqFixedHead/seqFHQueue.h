#ifndef _seqFHQueue_h
#define _seqFHQueue_h
#include <iostream>
#include "D:\VsCode_Cpp\Data_Structure\Queue\queue.h"

template <class elemType>
class seqFHQueue : public queue<elemType> // FH: fixed head
{
private:
    elemType *elem;
    int maxsize;
    int rear; // front==0
    void doubleSpace();

public:
    seqFHQueue(int size = 10);
    ~seqFHQueue();
    bool isEmpty() const;
    void enQueue(const elemType &x);
    elemType deQueue();
    elemType getHead() const;
    elemType getTail() const;
    int capacity() const;
};

#endif