#ifndef _TreeBinary_h
#define _TreeBinary_h
#include <iostream>
#include "D:\VsCode_Cpp\Data_Structure\Tree\bTree.h"
using namespace std;

template <class T>
class binaryTree : public bTree<T>
{
    template <class elemT>
    friend void printTree(const binaryTree<elemT> &t, elemT flag);
    //书P209 T5   重载== （形状及对应结点值相同）
    template <class elemT>
    friend bool operator==(const binaryTree<elemT> &p, const binaryTree<elemT> &q);
    //书P209 T6   判断两棵树是否对称
    template <class elemT>
    friend bool isMirror(const binaryTree<elemT> &p, binaryTree<elemT> &q);
    template<class elemT>
    friend bool isMirrorConst(const binaryTree<elemT> &p, binaryTree<elemT> &q); //保证两个输入都是const

private:
    struct node
    {
        node *left, *right;
        T data;

        node() : left(NULL), right(NULL) {}
        node(T item, node *L = NULL, node *R = NULL) : data(item), left(L), right(R) {}
        ~node() {}
    };

    node *root;

    node *find(T x, node *t) const;
    void clear(node *&t);
    void preOrder(node *t) const;
    void midOrder(node *t) const;
    void postOrder(node *t) const;
    //书P178 例6.1
    int size(node *t) const;
    int height(node *t) const;
    //书后习题
    void ExchangeSons(node *t);     //书P209 T1   交换所有结点的左右子树，实现函数
    int DegreeofTwo(node *t) const; //书P209 T2   统计度数为2的结点个数，实现函数
    bool isFull(node *t) const;     //书P209 T3   判断是否为满二叉树，实现函数
    bool isComplete(node *t) const; //书P209 T4   判断是否为完全二叉树，实现函数

public:
    binaryTree() : root(NULL) {}
    binaryTree(T x) { root = new node(x); }
    binaryTree(const binaryTree<T> &x);
    ~binaryTree();
    void clear();
    bool isEmpty() const;
    T Root(T flag) const; //写成root（小写）会跟定义的 node *root 冲突！
    T lchild(T x, T flag) const;
    T rchild(T x, T flag) const;
    void delLeft(T x);
    void delRight(T x);
    void preOrder() const;
    void midOrder() const;
    void postOrder() const;
    void levelOrder() const;
    void createTree(T flag);
    T parent(T x, T flag) const { return flag; } //实际上找不到爸爸
    //书P178 例6.1
    int size() const;
    int height() const;
    //书后习题
    void ExchangeSons();     //书P209 T1   交换所有结点的左右子树，包裹函数
    int DegreeofTwo() const; //书P209 T2   统计度数为2的结点个数，包裹函数
    bool isFull() const;     //书P209 T3   判断是否为满二叉树，包裹函数
    bool isComplete() const; //书P209 T4   判断是否为完全二叉树，包裹函数
    //重载赋值
    binaryTree<T> &operator=(const binaryTree<T> &right); //赋值结果是对左边对象的引用
    binaryTree<T>::node *copy(const node *t);                   //返回引用，可直接当做右值
};

#endif