#ifndef _tree_h
#define _tree_h

template <class T>
class tree
{
public:
    virtual void clear() = 0;
    virtual bool isEmpty() const = 0;
    virtual T root(T flag) const = 0;             //找根结点
    virtual T parent(T x, T flag) const = 0;      //找x的父亲
    virtual T child(T x, int i T flag) const = 0; //找x的第i个儿子
    virtual void remove(t x, int i) = 0;          //剪枝，删除x的第i棵子树
    virtual void traverse() const = 0;
};

#endif