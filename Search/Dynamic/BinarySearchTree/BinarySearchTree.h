#ifndef _BinarySearchTree_h
#define _BinarySearchTree_h
#include <iostream>
#include "D:\VsCode_Cpp\Data_Structure\Search\Dynamic\DynamicSearch.h"
using namespace std;

template <class KEY, class OTHER>
class BinarySearchTree : public DynamicSearchTable<KEY, OTHER>
{
private:
    struct BinaryNode
    {
        SET<KEY, OTHER> data;
        BinaryNode *left;
        BinaryNode *right;

        BinaryNode(const SET<KEY, OTHER> &d, BinaryNode *l = NULL, BinaryNode *r = NULL) : data(d), left(l), right(r) {}
    };
    BinaryNode *root;

    //中序遍历的结构体
    struct MidOrder
    {
        BinaryNode *node;
        int times;

        MidOrder(BinaryNode *n = NULL) : node(n), times(0) {}
    };

public:
    BinarySearchTree();
    ~BinarySearchTree();
    SET<KEY, OTHER> *find(const KEY &x) const;
    void insert(const SET<KEY, OTHER> &x);
    void remove(const KEY &x);
    //家庭作业
    bool isOrdered() const;             // P322 T1 查找是否每个结点都满足有序性
    SET<KEY, OTHER> *Max() const;       // P322 T6 查找最大值
    SET<KEY, OTHER> *Min() const;       // P322 T6 查找最小值    非递归没必要写包裹函数
    SET<KEY, OTHER> *iMax(int i) const; // P322 T7 查找第i大
    SET<KEY, OTHER> *iMin(int i) const; // P322 T8 查找第i小     要求 i>0， i==0时返回的是root

private:
    void insert(const SET<KEY, OTHER> &x, BinaryNode *&t);
    void remove(const KEY &x, BinaryNode *&t);
    SET<KEY, OTHER> *find(const KEY &x, BinaryNode *t) const;
    void makeEmpty(BinaryNode *t);
    //家庭作业
    bool isOrdered(const BinaryNode *t) const; // P322 T1 实现函数
};

#endif