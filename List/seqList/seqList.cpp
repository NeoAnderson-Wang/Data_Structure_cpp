#include <iostream>
#include "seqList.h"
using namespace std;

template <class elemType>
void seqList<elemType>::doubleSpace()
{
    elemType *tmp = data;

    maxsize *= 2;
    data = new elemType[maxsize];
    for (int i = 0; i < currentLength; ++i)
        data[i] = tmp[i];
    delete[] tmp;
}

template <class elemType>
seqList<elemType>::seqList(int initSize) //设定默认长度为10,默认值写在声明处！！！光写在定义的时候无意义！！！   这个不要typename??
{
    data = new elemType[initSize];
    maxsize = initSize;
    currentLength = 0;
}

template <class elemType>
seqList<elemType>::~seqList()
{
    delete[] data;
}

template <class elemType>
void seqList<elemType>::clear()
{
    currentLength = 0;
}

template <class elemType>
int seqList<elemType>::length() const
{
    return currentLength;
}

template <class elemType>
int seqList<elemType>::capacity() const
{
    return maxsize;
}

template <class elemType>
void seqList<elemType>::insert(int i, const elemType &x)
{
    if (currentLength == maxsize)
        doubleSpace();
    for (int j = currentLength; j > i; --j) // currentLength = 最后一个元素下标+1
    {
        data[j] = data[j - 1];
    }
    data[i] = x;
    ++currentLength;
}

template <class elemType>
void seqList<elemType>::remove(int i)
{
    if (i < 0 || i >= currentLength - 1)
    {
        cout << "INPUT ERROR!" << endl;
        return;
    }

    for (int j = i; j < currentLength; j++)
    {
        data[j] = data[j + 1];
    }
    --currentLength;
}

template <class elemType>
int seqList<elemType>::search(const elemType &x) const
{
    int i;
    for (i = 0; i < currentLength && data[i] != x; ++i)
        ;
    if (i == currentLength)
        return -1;
    else
        return i;
}

template <class elemType>
elemType seqList<elemType>::visit(int i) const
{
    return data[i];
}

template <class elemType>
void seqList<elemType>::traverse() const
{
    // cout << endl;
    for (int i = 0; i < currentLength; ++i)
        cout << data[i] << " ";
    cout << endl;
}

template <class elemType>
seqList<elemType> operator+(const seqList<elemType> &a, const seqList<elemType> &b)
{
    seqList<elemType> c;
    delete[] c.data;

    c.data = new elemType[a.currentLength + b.currentLength];
    c.maxsize = a.maxsize + b.maxsize;
    c.currentLength = a.currentLength + b.currentLength;

    int i;
    for (i = 0; i < a.currentLength; ++i)
        c.data[i] = a.data[i];
    for (i = a.currentLength; i < c.currentLength; ++i)
        c.data[i] = b.data[i - a.currentLength];

    return c;
}

template <class elemType>
seqList<elemType>::seqList(const seqList<elemType> &other)
{
    currentLength = other.currentLength;
    maxsize = other.maxsize;
    data = new elemType[maxsize];
    for (int i = 0; i < currentLength; ++i)
        data[i] = other.data[i];
}

template <class elemType>
seqList<elemType> &seqList<elemType>::operator=(const seqList<elemType> &right)
{
    if (this == &right)
        return *this;

    delete[] data;
    currentLength = right.currentLength;
    maxsize = right.maxsize;
    data = new elemType[maxsize];

    for (int i = 0; i < currentLength; ++i)
        data[i] = right.data[i];
    return *this;
}

template <class elemType>
ostream &operator<<(ostream &os, const seqList<elemType> &obj)
{
    for (int i = 0; i < obj.currentLength; ++i)
        os << obj.data[i] << " ";
    os << endl;
    return os;
}

template <class elemType>
istream &operator>>(istream &in, seqList<elemType> &obj)
{
    int num, i;

    cout << "Please type in the number of the elements : ";
    in >> num;
    while (num + obj.currentLength > obj.maxsize)
        obj.doubleSpace();

    for (i = 0; i < num; ++i)
        in >> obj.data[obj.currentLength + i];
    obj.currentLength += num;

    return in;
}