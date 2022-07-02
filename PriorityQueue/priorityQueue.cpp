#include <iostream>
#include "priorityQueue.h"
using namespace std;

template <class Type>
priorityQueue<Type>::priorityQueue(int capacity) // 无需写默认值
{
    array = new Type[capacity];
    maxsize = capacity;
    currentSize = 0;
}

template <class Type>
priorityQueue<Type>::~priorityQueue()
{
    delete[] array;
}

template <class Type>
bool priorityQueue<Type>::isEmpty() const
{
    return currentSize == 0;
}

template <class Type>
Type priorityQueue<Type>::getHead() const
{
    return array[1];
}

template <class Type>
void priorityQueue<Type>::enQueue(const Type &x)
{
    if (currentSize == maxsize - 1)
        doubleSpace();

    //向上过滤
    int hole = ++currentSize;
    for (; hole > 1 && x < array[hole / 2]; hole /= 2) //循环中，hole去上次循环结束的结果
        array[hole] = array[hole / 2];
    array[hole] = x;
}

template <class Type>
Type priorityQueue<Type>::deQueue()
{
    Type minItem;
    minItem = array[1];
    array[1] = array[currentSize--];
    percolateDown(1);
    return minItem;
}

template <class Type>
void priorityQueue<Type>::percolateDown(int hole)
{
    int child;
    Type tmp = array[hole];

    for (; hole * 2 <= currentSize; hole = child) // child 未初始化？？
    {
        child = hole * 2;
        if (child != currentSize && array[child + 1] < array[child])
            child++;
        if (array[child] < tmp)
            array[hole] = array[child];
        else
            break;
    }
    array[hole] = tmp;
}

template <class Type>
void priorityQueue<Type>::buildHeap()
{
    for (int i = currentSize / 2; i > 0; i--) //叶结点无需
        percolateDown(i);
}

template <class Type>
priorityQueue<Type>::priorityQueue(const Type *items, int size) : maxsize(size + 10), currentSize(size)
{
    array = new Type[maxsize];
    for (int i = 0; i < size; i++)
        array[i + 1] = items[i];
    buildHeap();
}

template <class Type>
void priorityQueue<Type>::doubleSpace()
{
    Type *tmp = array;
    maxsize *= 2;
    array = new Type[maxsize];
    for (int i = 0; i <= currentSize; ++i)
        array[i] = tmp[i];
    delete[] tmp;
}

//家庭作业
//书P234 T7（1） 找到优先级大于等于x的最小元素，返回其下标
template <class Type>
int priorityQueue<Type>::findMin(Type x) const
{
    int i, ans;
    Type tmp;
    bool flag = false;
    for (i = 1; i <= currentSize; ++i)
    {
        if (array[i] >= x)
        {
            if (flag == false)
            {
                flag = true;
                ans = i;
                tmp = array[i];
            }
            else if (array[i] < tmp)
            {
                ans = i;
                tmp = array[i];
            }
        }
    }
    return ans;
}

//书P234 T7（2） 将第i个结点的优先级值减少value
template <class Type>
void priorityQueue<Type>::decreaseKey(int i, Type value)
{
    array[i] -= value;
    for (int j = i / 2; j > 0; j /= 2)
        percolateDown(j);
}

template <class Type>
void priorityQueue<Type>::printPQ() const
{
    for (int i = 1; i <= currentSize && 2 * i <= currentSize; ++i)
    {
        cout << array[i] << " " << array[2 * i] << " ";
        if (2 * i + 1 <= currentSize)
            cout << array[2 * i + 1];
        cout << endl;
    }
    cout << "Print Completed!" << endl;
}