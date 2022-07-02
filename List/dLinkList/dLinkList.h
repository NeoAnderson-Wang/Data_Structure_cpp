#ifndef _dLinkList_h
#define _dLinkList_h
#include <iostream>
#include "D:\VsCode_Cpp\Data_Structure\list\list.h"
using namespace std;

template <class elemType>
class dLinkList : public list<elemType>
{
    template <class T>
    friend dLinkList<T> operator+(const dLinkList<T> &a, const dLinkList<T> &b);
    template <class T>
    friend ostream &operator<<(ostream &os, const dLinkList<T> &obj);
    template <class T>
    friend istream &operator>>(istream &is, dLinkList<T> &obj);

private:
    struct node
    {
        elemType data;
        node *prev, *next;

        node(const elemType &x, node *p = NULL, node *n = NULL)
        {
            data = x;
            prev = p;
            next = n;
        }
        node() : next(NULL), prev(NULL) {} // next,prev顺序没关系吧   参数的括号记得写！！！
        ~node() {}
    };

    node *head, *tail;
    int currentLength;

    node *move(int i) const;

public:
    dLinkList();
    // dLinkList(const dLinkList<elemType> &a);
    ~dLinkList()
    {
        clear();
        delete head;
        delete tail;
    }

    void clear();
    int length() const { return currentLength; }
    void insert(int i, const elemType &x);
    void remove(int i);
    int search(const elemType &x) const;
    elemType visit(int i) const;
    void traverse() const;
    dLinkList<elemType> &operator = (const dLinkList<elemType> &right);
};

#endif