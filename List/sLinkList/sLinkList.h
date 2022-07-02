#ifndef _sLinkList_h
#define _sLinkList_h
#include <iostream>
#include "D:\VsCode_Cpp\Data_Structure\list\list.h"
using namespace std;

// template <class elemType>
// class sLinkList;

// template <class elemType>
// int SearchSameSuffix(const sLinkList<elemType> &str1, const sLinkList<elemType> &str2);

template <class elemType>
class sLinkList : public list<elemType>
{
    template <class T>
    friend int SearchSameSuffix(const sLinkList<T> &str1, const sLinkList<T> &str2); //书P67 T10 查找相同后缀
    template <class T>
    friend ostream &operator<<(ostream &os, const sLinkList<T> &obj);
    template <class T>
    friend istream &operator>>(istream &is, sLinkList<T> &obj);

private:
    struct node //整个结构体定义在类内， 此时暂未定义类的数据成员
    {
        elemType data;
        node *next;

        node(const elemType &x, node *n = NULL)
        {
            data = x;
            next = n;
        }
        node() : next(NULL) {}
        ~node() {} //后面有用到吗？ 防止内存泄露
    };

    node *head;
    int currentLength;

    node *move(int i) const;

public:
    sLinkList();
    ~sLinkList()
    {
        clear();
        delete head;
    }

    void clear();
    int length() const { return currentLength; } //内联
    void insert(int i, const elemType &x);       //认为链表第一个元素 下标 为 1
    void remove(int i);
    int search(const elemType &x) const;
    elemType visit(int i) const;
    void traverse() const;
    void erase(int i);
    void erase(elemType x, elemType y); //书P66 T1 删除值在[x,y]间的结点
    void reverse() const;               //书P66 T6 逆置单链表
    void reverse1() const;              //陈弈天的reverse
    int movebackward(int k) const;      //书P67 T9 仅给出头指针，查找倒数第k个位置上的结点
};

#endif