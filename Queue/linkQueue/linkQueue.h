#ifndef _linkQueue_h
#define _linkQueue_h
#include <iostream>
#include "D:\VsCode_Cpp\Data_Structure\Queue\queue.h"

template <class elemType>
class linkQueue : public queue<elemType>
{
private:
    struct node
    {
        elemType data;
        node *next;
        node(const elemType &x, node *N = NULL)
        {
            data = x;
            next = N;
        }
        node() : next(NULL) {}
        ~node() {}
    };

    node *front, *rear;

public:
    linkQueue();
    ~linkQueue();
    bool isEmpty()const;
    void enQueue(const elemType &x);
    elemType deQueue();
    elemType getHead() const;
};

#endif