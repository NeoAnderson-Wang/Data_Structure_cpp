#ifndef _bTree_h
#define _bTtree_h

template <class T>
class bTree
{
public:
    virtual void clear() = 0;
    virtual bool isEmpty() const = 0;
    virtual T Root(T flag) const = 0;
    virtual T parent(T x, T flag) const = 0;
    virtual T lchild(T x, T flag) const = 0; //找x的左儿子
    virtual T rchild(T x, T flag) const = 0; //找x的右儿子
    virtual void delLeft(T x) = 0;           //删除左子树
    virtual void delRight(T x) = 0;          //删除右子树
    virtual void preOrder() const = 0;
    virtual void midOrder() const = 0;
    virtual void postOrder() const = 0;
    virtual void levelOrder() const = 0;
};

#endif