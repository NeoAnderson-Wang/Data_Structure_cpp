#include <iostream>
#include "BinarySearchTree.h"
#include "D:\VsCode_Cpp\Data_Structure\Stack\linkStack\linkStack.cpp"
using namespace std;

template <class KEY, class OTHER>
SET<KEY, OTHER> *BinarySearchTree<KEY, OTHER>::find(const KEY &x) const
{
    return find(x, root);
}

template <class KEY, class OTHER>
SET<KEY, OTHER> *BinarySearchTree<KEY, OTHER>::find(const KEY &x, BinaryNode *t) const
{
    if (t == NULL || t->data.key == x)
        return (SET<KEY, OTHER> *)t; //将 BinaruNode* 类型的 指针 强制转换 为 SET* 类型的
    if (x < t->data.key)
        return find(x, t->left);
    else
        return find(x, t->right);
}

template <class KEY, class OTHER>
void BinarySearchTree<KEY, OTHER>::insert(const SET<KEY, OTHER> &x)
{
    insert(x, root);
}

template <class KEY, class OTHER>
void BinarySearchTree<KEY, OTHER>::insert(const SET<KEY, OTHER> &x, BinaryNode *&t) //涉及修改指针地址的，要用指针的引用
{
    if (t == NULL)
        t = new BinaryNode(x, NULL, NULL);
    else if (x.key < t->data.key)
        insert(x, t->left);
    else
        insert(x, t->right);
}

template <class KEY, class OTHER>
void BinarySearchTree<KEY, OTHER>::remove(const KEY &x)
{
    remove(x, root);
}

template <class KEY, class OTHER>
void BinarySearchTree<KEY, OTHER>::remove(const KEY &x, BinaryNode *&t)
{
    if (t == NULL)
        return; //没找到
    if (x < t->data.key)
        remove(x, t->left);
    else if (x > t->data.key)
        remove(x, t->right);

    // t即为要找的   此处不同于insert,find，从中间移除会对整棵树有影响
    else if (t->left != NULL && t->right != NULL) //有俩儿子
    {
        BinaryNode *tmp = t->right;
        while (tmp->left != NULL)
            tmp = tmp->left; //找到比t的key大的最小元素
        t->data = tmp->data;
        remove(t->data.key, t->right);
    }
    else //只有一个儿子
    {
        BinaryNode *old = t;
        t = (t->left != NULL) ? t->left : t->right;
        delete old;
    }
}

template <class KEY, class OTHER>
BinarySearchTree<KEY, OTHER>::BinarySearchTree()
{
    root = NULL;
}

template <class KEY, class OTHER>
void BinarySearchTree<KEY, OTHER>::makeEmpty(BinaryNode *t)
{
    if (t == NULL)
        return;
    makeEmpty(t->left);
    makeEmpty(t->right);
    delete t; //自己也要删掉(清空内部数据)
}

template <class KEY, class OTHER>
BinarySearchTree<KEY, OTHER>::~BinarySearchTree()
{
    makeEmpty(root);
}

//家庭作业
// P322 T1 查找是否每个结点都满足有序性
template <class KEY, class OTHER>
bool BinarySearchTree<KEY, OTHER>::isOrdered() const
{
    return isOrdered(root);
}

template <class KEY, class OTHER>
bool BinarySearchTree<KEY, OTHER>::isOrdered(const BinaryNode *t) const
{
    if (t == NULL)
        return true;
    if (isOrdered(t->left) && isOrdered(t->right))
    {
        if (!(t->left && t->right)) //左右儿子都不存在
            return true;
        if (t->left && !t->right)
            if (t->data.key > t->left->data.key) // data(SET )未重载预算符，不可直接比较
                return true;
        if (!t->left && t->right)
            if (t->data.key < t->right->data.key)
                return true;
        if (t->left && t->right)
            if (t->data.key > t->left->data.key && t->data.key < t->right->data.key)
                return true;
    }
    return false;
}

// P322 T6 查找最大值，最小值
template <class KEY, class OTHER>
SET<KEY, OTHER> *BinarySearchTree<KEY, OTHER>::Max() const
{
    BinaryNode *t = root;

    while (t->right != NULL)
        t = t->right;
    return (SET<KEY, OTHER> *)t;
}

template <class KEY, class OTHER>
SET<KEY, OTHER> *BinarySearchTree<KEY, OTHER>::Min() const
{
    BinaryNode *t = root;

    while (t->left != NULL)
        t = t->left;
    return (SET<KEY, OTHER> *)t;
}

// P322 T7，8  查找第i大，小
template <class KEY, class OTHER>
SET<KEY, OTHER> *BinarySearchTree<KEY, OTHER>::iMax(int i) const
{
    linkStack<MidOrder> s;
    int cnt = 0;
    MidOrder current(root);
    s.push(current);

    while (!s.isEmpty() && cnt != i)
    {
        current = s.pop();
        if (++current.times == 2)
        {
            cnt++;
            if (current.node->left != NULL)
                s.push(current.node->left);
        }
        else
        {
            s.push(current);
            if (current.node->right != NULL)
                s.push(current.node->right);
        }
    }
    return (SET<KEY, OTHER> *)current.node;
}

template <class KEY, class OTHER>
SET<KEY, OTHER> *BinarySearchTree<KEY, OTHER>::iMin(int i) const
{
    linkStack<MidOrder> s;
    int cnt = 0;
    MidOrder current(root);
    s.push(current);

    while (!s.isEmpty() && cnt != i)
    {
        current = s.pop();
        if (++current.times == 2)
        {
            cnt++;
            if (current.node->right != NULL)
                s.push(current.node->right);
        }
        else
        {
            s.push(current);
            if (current.node->left != NULL)
                s.push(current.node->left);
        }
    }
    return (SET<KEY, OTHER> *)current.node;
}