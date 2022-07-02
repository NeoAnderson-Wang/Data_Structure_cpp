#ifndef _linkStack_h
#define _linkStack_h
#include <iostream>
#include "D:\VsCode_Cpp\Data_Structure\stack\stack.h"
using namespace std;

template <class elemType>
class linkStack : public stack<elemType>
{
private:
    struct node
    {
        elemType data;
        node *next;
        node(const elemType &x, node *n = NULL)
        {
            data = x;
            next = n;
        }
        node() : next(NULL) {}
        ~node() {}
    };

    node *top_p;

public:
    linkStack();
    ~linkStack();
    bool isEmpty() const;
    void push(const elemType &x);
    elemType pop();
    elemType top() const;
};

#endif