#include <iostream>
#include "seqFHQueue.h"
using namespace std;

template <class elemType>
seqFHQueue<elemType>::seqFHQueue(int size)
{
    elem = new elemType[size];
    maxsize = size; //这两个也要初始化
    rear = -1;      //不能设为0！
}

template <class elemType>
seqFHQueue<elemType>::~seqFHQueue()
{
    delete[] elem;
}

template <class elemType>
bool seqFHQueue<elemType>::isEmpty() const
{
    return rear == -1;
}

template <class elemType>
void seqFHQueue<elemType>::enQueue(const elemType &x)
{
    if (rear + 1 == maxsize)
        doubleSpace();
    elem[++rear] = x;
}

template <class elemType>
elemType seqFHQueue<elemType>::deQueue()
{
    elemType tmp = elem[0];
    if (rear == 0)
        rear = -1;
    else
    {
        for (int i = 0; i < rear; ++i)
            elem[i] = elem[i + 1];
        rear--;
    }
    return tmp;
}

template <class elemType>
elemType seqFHQueue<elemType>::getHead() const
{
    return elem[0]; //要求队列不能为空
}

template <class elemType>
elemType seqFHQueue<elemType>::getTail() const
{
    return elem[rear]; //要求队列不能为空
}

template <class elemType>
int seqFHQueue<elemType>::capacity() const
{
    return maxsize;
}

template <class elemType>
void seqFHQueue<elemType>::doubleSpace()
{
    elemType *tmp = elem;
    elem = new elemType[2 * maxsize];
    for (int i = 0; i < maxsize; ++i)
        elem[i] = tmp[i];
    maxsize *= 2;
    delete tmp;
}
