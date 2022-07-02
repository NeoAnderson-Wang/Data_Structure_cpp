#ifndef _seqList_h
#define _seqList_h
#include <iostream>
#include "D:\VsCode_Cpp\Data_Structure\list\list.h"
using namespace std;

template <class elemType>
class seqList : public list<elemType>
{
    template <class T>                                                     //为啥要加？？？？？
    friend seqList<T> operator+(const seqList<T> &a, const seqList<T> &b); //书P66 T7
    template <class T>
    friend ostream &operator<<(ostream &os, const seqList<T> &obj);
    template <class T>
    friend istream &operator>>(istream &in, seqList<T> &obj);

private:
    elemType *data;    //数组的指针    //首个元素为第 0 个
    int currentLength; //已经存入长度
    int maxsize;       //空间总长
    void doubleSpace();

public:
    seqList(int initSize = 10);
    seqList(const seqList &other); //复制构造函数
    ~seqList();
    void clear();
    int length() const;
    int capacity() const; //返回最大长度
    void insert(int i, const elemType &x);
    void remove(int i);
    int search(const elemType &x) const;
    elemType visit(int i) const;
    void traverse() const;
    seqList<elemType> &operator=(const seqList<elemType> &right); //书P66 T7 C=A+B
};

#endif