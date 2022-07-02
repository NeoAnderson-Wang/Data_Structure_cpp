#include <iostream>
#include "binaryTree.h"
#include "D:\VsCode_Cpp\Data_Structure\Queue\linkQueue\linkQueue.cpp" //include .cpp 否则 undefined reference to
using namespace std;

template <class T>
bool binaryTree<T>::isEmpty() const
{
    return root == NULL;
}

template <class T>
T binaryTree<T>::Root(T flag) const
{
    if (root == NULL)
        return flag;
    else
        return root->data;
}

template <class T>
void binaryTree<T>::clear(binaryTree<T>::node *&t)
{
    if (t == NULL)
        return;
    clear(t->left);
    clear(t->right);
    delete t;
    t = NULL;
}

template <class T>
void binaryTree<T>::clear()
{
    clear(root);
}

template <class T>
binaryTree<T>::~binaryTree()
{
    clear(root);
}

template <class T>
void binaryTree<T>::preOrder(binaryTree<T>::node *t) const
{
    if (t == NULL)
        return;
    cout << t->data << " ";
    preOrder(t->left);
    preOrder(t->right);
}

template <class T>
void binaryTree<T>::preOrder() const
{
    cout << "\nPreorder Traversal: ";
    preOrder(root);
}

template <class T>
void binaryTree<T>::midOrder(binaryTree<T>::node *t) const
{
    if (t == NULL)
        return;
    midOrder(t->left);
    cout << t->data << " ";
    midOrder(t->right);
}

template <class T>
void binaryTree<T>::midOrder() const
{
    cout << "\nMidorder Traversal: ";
    midOrder(root);
}

template <class T>
void binaryTree<T>::postOrder(binaryTree<T>::node *t) const
{
    if (t == NULL)
        return;
    postOrder(t->left);
    postOrder(t->right);
    cout << t->data << " ";
}

template <class T>
void binaryTree<T>::postOrder() const
{
    cout << "\nPostorder Traversal: ";
    postOrder(root);
}

template <class T>
void binaryTree<T>::levelOrder() const
{
    linkQueue<node *> que;
    node *tmp;

    cout << "\nLeveLOrder Traversal: ";

    if (root == NULL) //数为空
        return;

    que.enQueue(root);

    while (!que.isEmpty())
    {
        tmp = que.deQueue();
        cout << tmp->data << " ";
        if (tmp->left)
            que.enQueue(tmp->left);
        if (tmp->right)
            que.enQueue(tmp->right);
    }
}

template <class T>
typename binaryTree<T>::node *binaryTree<T>::find(T x, binaryTree<T>::node *t) const
{
    node *tmp;
    if (t == NULL)
        return NULL;
    if (t->data == x)
        return t;
    if (tmp = find(x, t->left))
        return tmp; //直接赋值
    else
        return find(x, t->right);
}

template <class T>
void binaryTree<T>::delLeft(T x)
{
    node *tmp = find(x, root);
    if (tmp == NULL)
        return;
    clear(tmp->left);
}

template <class T>
void binaryTree<T>::delRight(T x)
{
    node *tmp = find(x, root);
    if (tmp == NULL)
        return;
    clear(tmp->right);
}

template <class T>
T binaryTree<T>::lchild(T x, T flag) const
{
    node *tmp = find(x, root);
    if (tmp == NULL || tmp->left == NULL)
        return flag;

    return tmp->left->data;
}

template <class T>
T binaryTree<T>::rchild(T x, T flag) const
{
    node *tmp = find(x, root);
    if (tmp == NULL || tmp->right == NULL)
        return flag;

    return tmp->right->data;
}

template <class T>
void binaryTree<T>::createTree(T flag)
{
    linkQueue<node *> que;
    node *tmp;
    T x, ldata, rdata;

    cout << "Please Input Root: ";
    cin >> x;
    //书上未考虑输入为空
    if (x == flag)
    {
        root = NULL;
        return;
    }

    root = new node(x);
    que.enQueue(root);

    while (!que.isEmpty())
    {
        tmp = que.deQueue();
        cout << "Please input the two sons of  " << tmp->data << "  ( " << flag << " stands for NULL) : ";
        cin >> ldata >> rdata;
        if (ldata != flag)
            que.enQueue(tmp->left = new node(ldata));
        if (rdata != flag)
            que.enQueue(tmp->right = new node(rdata));
    }

    cout << "Create Completed!" << endl;
}

template <class T>
void printTree(const binaryTree<T> &t, T flag)
{
    linkQueue<T> que;
    que.enQueue(t.root->data);
    cout << endl;

    while (!que.isEmpty())
    {
        T p, l, r;
        p = que.deQueue();
        l = t.lchild(p, flag); // l是p的左儿子
        r = t.rchild(p, flag);
        cout << p << " " << l << " " << r << endl;
        if (l != flag)
            que.enQueue(l);
        if (r != flag)
            que.enQueue(r);
    }
}

//书P178 例6.1

template <class T>
int binaryTree<T>::size(binaryTree<T>::node *t) const
{
    if (t == NULL)
        return 0;
    return 1 + size(t->left) + size(t->right);
}

template <class T>
int binaryTree<T>::size() const
{
    return size(root);
}

template <class T>
int binaryTree<T>::height(binaryTree<T>::node *t) const
{
    if (t == NULL)
        return 0;
    else
        return 1 + (height(t->left) > height(t->right) ? height(t->left) : height(t->right));
}

template <class T>
int binaryTree<T>::height() const
{
    return height(root);
}

//家庭作业

//书P209 T1 交换所有结点的左右子树，实现函数
template <class T>
void binaryTree<T>::ExchangeSons(binaryTree<T>::node *t)
{
    node *tmp;
    if (t == NULL || (t->left == NULL && t->right == NULL)) // t 有可能直接为空
        return;
    ExchangeSons(t->left);
    ExchangeSons(t->right);

    tmp = t->left;
    t->left = t->right;
    t->right = tmp;
}

//书P209 T1   交换所有结点的左右子树，包裹函数
template <class T>
void binaryTree<T>::ExchangeSons()
{
    ExchangeSons(root);
}

//书P209 T2 统计度数为2的结点个数，实现函数
template <class T>
int binaryTree<T>::DegreeofTwo(binaryTree<T>::node *t) const
{
    if (t == NULL)
        return 0; //不能写成-1，不然加的时候会有问题
    if (t->left != NULL && t->right != NULL)
        return DegreeofTwo(t->left) + DegreeofTwo(t->right) + 1;
    else
        return DegreeofTwo(t->left) + DegreeofTwo(t->right);
}

//书P209 T2 统计度数为2的结点个数，包裹函数
template <class T>
int binaryTree<T>::DegreeofTwo() const
{
    return DegreeofTwo(root);
}

//书P209 T3   判断是否为满二叉树，实现函数
template <class T>
bool binaryTree<T>::isFull(binaryTree<T>::node *t) const
{
    if (root == NULL)
    {
        cout << "INPUT ERROR! It's Empty!" << endl;
        return false;
    }

    if (t->left == NULL && t->right == NULL)
        return true;
    if (t->left != NULL && t->right != NULL)
        return (isFull(t->left) && isFull(t->right));
    else
        return false;
}

//书P209 T3   判断是否为满二叉树，包裹函数
template <class T>
bool binaryTree<T>::isFull() const
{
    return isFull(root);
}

//书P209 T3   判断是否为完全二叉树，实现函数
template <class T>
bool binaryTree<T>::isComplete(binaryTree<T>::node *t) const
{
    if (root == NULL)
    {
        cout << "INPUT ERROR! It's Empty!" << endl;
        return false;
    }

    linkQueue<node *> que;
    node *tmp;
    bool isRightFull = false;
    bool ans = true;

    que.enQueue(root);
    while (!que.isEmpty())
    {
        tmp = que.deQueue();
        if (tmp->left == NULL && tmp->right != NULL)
            return ans = false;

        if (isRightFull == true)
            if (!(tmp->left == NULL && tmp->right == NULL))
                return ans = false;

        if (isRightFull == false)
        {
            if (tmp->left != NULL && tmp->right == NULL)
                isRightFull = true;
        }

        if (tmp->left)
            que.enQueue(tmp->left);
        if (tmp->right)
            que.enQueue(tmp->right);
    }

    return ans;
}

//书P209 T3   判断是否为完全二叉树，包裹函数
template <class T>
bool binaryTree<T>::isComplete() const
{
    return isComplete(root);
}

// 书P209 T5 重载== （形状及对应结点值相同）
template <class T>
bool operator==(const binaryTree<T> &p, const binaryTree<T> &q)
{
    linkQueue<typename binaryTree<T>::node *> lp, lq; // typename binaryTree<T>::  要写上
    typename binaryTree<T>::node *ptmp, *qtmp;        // typename binaryTree<T>::  要写上
    if ((p.root == NULL && q.root != NULL) || (p.root != NULL && q.root == NULL))
        return false;
    if (p.root == NULL && q.root == NULL)
        return true;

    lp.enQueue(p.root);
    lq.enQueue(q.root);

    while (!lp.isEmpty())
    {
        if (lq.isEmpty())
            return false;

        ptmp = lp.deQueue();
        qtmp = lq.deQueue();
        if (ptmp->data != qtmp->data)
            return false;

        if ((ptmp->left == NULL && qtmp->left != NULL) || (ptmp->left != NULL && qtmp->left == NULL) || (ptmp->right == NULL && qtmp->right != NULL) || (ptmp->right != NULL && qtmp->right == NULL))
            return false;

        if (ptmp->left && qtmp->left)
        {
            lp.enQueue(ptmp->left);
            lq.enQueue(qtmp->left);
        }
        if (ptmp->right && qtmp->right)
        {
            lp.enQueue(ptmp->right);
            lq.enQueue(qtmp->right);
        }
    }
    if (!lq.isEmpty())
        return false;
    else
        return true;
}

//重载赋值
template <class T>
binaryTree<T> &binaryTree<T>::operator=(const binaryTree<T> &right)
{
    this->root = copy(right.root);
    return *this;

    //下面这一坨直接对树进行操作
    // linkQueue<node *> qthis, qright;
    // node *tpthis, *tpright;

    // if (this == &right)
    //     return *this;

    // clear();                                 //复制构造时，*this 内所有东西是随机的，clear() 中会出现 t 内啥数据没有

    // if (right.root == NULL)
    //     return *this;

    // this->root = new node(right.root->data); // clear()后整个this为NULL，需要开辟空间
    // qthis.enQueue(this->root);
    // qright.enQueue(right.root);

    // while (!qright.isEmpty())
    // {
    //     tpthis = qthis.deQueue();
    //     tpright = qright.deQueue();

    //     if (tpright->left)
    //     {
    //         qthis.enQueue(tpthis->left = new node(tpright->left->data));
    //         qright.enQueue(tpright->left);
    //     }
    //     if (tpright->right)
    //     {
    //         qthis.enQueue(tpthis->right = new node(tpright->right->data));
    //         qright.enQueue(tpright->right);
    //     }
    // }

    // return *this;
}

template <class T>
typename binaryTree<T>::node *binaryTree<T>::copy(const node *t)
{
    if (t == NULL)
        return NULL;
    node *tmp = new node(t->data);
    tmp->left = copy(t->left);
    tmp->right = copy(t->right);
    return tmp;
}

//赋值构造函数
template <class T>
binaryTree<T>::binaryTree(const binaryTree<T> &x)
{
    this->root = copy(x.root);
}

//书P209 T6   判断两棵树是否对称
template <class T>
bool isMirror(const binaryTree<T> &p, binaryTree<T> &q) //前面无需加friend！！！
{
    q.ExchangeSons();
    binaryTree<T> tmp = q; //要先写复制构造函数！！！
    // tmp = q;           //要先重载 = ！！！
    q.ExchangeSons();

    return p == tmp;
}

//保证两个输入都是const的isMirror (类似重载 == )
template <class T>
bool isMirrorConst(const binaryTree<T> &p, binaryTree<T> &q)
{
    linkQueue<typename binaryTree<T>::node *> lp, lq;
    typename binaryTree<T>::node *ptmp, *qtmp;
    if ((p.root == NULL && q.root != NULL) || (p.root != NULL && q.root == NULL))
        return false;
    if (p.root == NULL && q.root == NULL)
        return true;

    lp.enQueue(p.root);
    lq.enQueue(q.root);

    while (!lp.isEmpty())
    {
        if (lq.isEmpty())
            return false;

        ptmp = lp.deQueue();
        qtmp = lq.deQueue();
        if (ptmp->data != qtmp->data)
            return false;

        if ((ptmp->left == NULL && qtmp->right != NULL) || (ptmp->left != NULL && qtmp->right == NULL) || (ptmp->right == NULL && qtmp->left != NULL) || (ptmp->right != NULL && qtmp->left == NULL))
            return false;

        if (ptmp->left && qtmp->right)
        {
            lp.enQueue(ptmp->left);
            lq.enQueue(qtmp->right);
        }
        if (ptmp->right && qtmp->left)
        {
            lp.enQueue(ptmp->right);
            lq.enQueue(qtmp->left);
        }
    }
    if (!lq.isEmpty())
        return false;
    else
        return true;
}