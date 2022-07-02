#ifndef _seqStack_h
#define _seqStack_h
#include <iostream>
#include "D:\VsCode_Cpp\Data_Structure\stack\stack.h"
using namespace std;

template <class elemType>
class seqStack : public stack<elemType>
{
private:
    elemType *elem;
    int top_p;
    int maxSize;
    void doubleSpace();

public:
    seqStack(int initSize = 10);
    ~seqStack();
    bool isEmpty() const;
    void push(const elemType &x);
    elemType pop();
    elemType top() const;
};

#endif