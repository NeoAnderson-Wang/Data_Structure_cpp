#include <iostream>
#include "linkQueue.h"
using namespace std;

template <class elemType>
linkQueue<elemType>::linkQueue()
{
    front = rear = NULL;
}

template <class elemType>
linkQueue<elemType>::~linkQueue()
{
    node *tmp;
    while (front != NULL)
    {
        tmp = front;
        front = front->next; //从前往后删
        delete tmp;
    }
}

template <class elemType>
bool linkQueue<elemType>::isEmpty() const
{
    return front == NULL;
}

template <class elemType>
void linkQueue<elemType>::enQueue(const elemType &x)
{
    if (rear == NULL)
        front = rear = new node(x);
    else
        rear = rear->next = new node(x);
}

template <class elemType>
elemType linkQueue<elemType>::deQueue()
{
    node *tmp = front;
    elemType value = front->data;
    front = front->next;
    if (front == NULL) //别写成赋值了！
        rear = NULL;   //出队后为空
    delete tmp;
    return value;
}

template <class elemType>
elemType linkQueue<elemType>::getHead() const
{
    return front->data;
}