#include <iostream>
#include "dLinkList.h"
using namespace std;

template <class elemType>
typename dLinkList<elemType>::node *dLinkList<elemType>::move(int i) const
{
    node *p = head;
    while (i-- > 0) //书上是 >= ， 书上定义应该 链表 第一个元素 下标 为 0
        p = p->next;
    return p;
}

template <class elemType>
dLinkList<elemType>::dLinkList() //函数名是dLinkList,不需要加<elemType>
{
    head = new node;
    head->next = tail = new node;
    tail->prev = head;
    currentLength = 0;
}

template <class elemType>
void dLinkList<elemType>::clear()
{
    node *p = head->next, *q;

    if (currentLength == 0)
        return; //空链表算是特殊情况

    head->next = tail;
    tail->prev = head; //清为刚构造出来的样子
    while (p != tail)  //双链表无需p->next
    {
        q = p->next;
        delete p; //如果只有head，tail，p即为tail，此时已经删了tail！（按书上的代码来的话）
        p = q;
    }
    currentLength = 0;
}

template <class elemType>
void dLinkList<elemType>::insert(int i, const elemType &x) //在第i个 前面 插入，成为第i个
{
    node *pos, *tmp;
    pos = move(i); //需要断2个链，连4个链
    tmp = new node(x, pos->prev, pos);
    pos->prev->next = tmp;
    pos->prev = tmp;
    ++currentLength;
}

template <class elemType>
void dLinkList<elemType>::remove(int i)
{
    node *pos;
    pos = move(i);
    pos->prev->next = pos->next;
    pos->next->prev = pos->prev;
    delete pos;
    --currentLength; //别忘了！！！！！！
}

template <class elemType>
int dLinkList<elemType>::search(const elemType &x) const //如果有多个相同元素，只会输出第一个的位置
{
    node *p = head->next;
    int i;

    for (i = 1; p != tail && p->data != x; ++i) //书上起始为 i=0
        p = p->next;
    if (p == tail)
        return -1;
    else
        return i;
}

template <class elemType>
elemType dLinkList<elemType>::visit(int i) const
{
    return move(i)->data;
}

template <class elemType>
void dLinkList<elemType>::traverse() const
{
    node *p = head->next;
    // cout << endl;     //y1s1, 这行没太大必要
    while (p != tail)
    {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}

template <class elemType>
dLinkList<elemType> operator+(const dLinkList<elemType> &a, const dLinkList<elemType> &b)
{
    dLinkList<elemType> tmp;
    typename dLinkList<elemType>::node *q; //需要加typename

    for (q = b.tail->prev; q != b.head; q = q->prev)
        tmp.insert(1, q->data);
    for (q = a.tail->prev; q != a.head; q = q->prev)
        tmp.insert(1, q->data);

    return tmp;
}

template <class elemType>
dLinkList<elemType> &dLinkList<elemType>::operator=(const dLinkList<elemType> &right)
{
    if (this == &right)
        return *this;

    clear();
    for (node *p = right.tail->prev; p != right.head; p = p->prev)
        insert(1, p->data);

    return *this;
}

template <class elemType>
ostream &operator<<(ostream &os, const dLinkList<elemType> &obj)
{
    typename dLinkList<elemType>::node *p = obj.head->next;
    for (; p != obj.tail; p = p->next)
        os << p->data << " ";
    os << endl;
    return os;
}

template <class elemType>
istream &operator>>(istream &is, dLinkList<elemType> &obj)
{
    typename dLinkList<elemType>::node *p = obj.move(obj.currentLength), *tmp;
    int num, i = 1;
    elemType n;
    cout << "Please type in the number of the elements : ";
    is >> num;

    while (i <= num)
    {
        is >> n;
        tmp = new typename dLinkList<elemType>::node(n, p, obj.tail);
        obj.tail->prev = tmp;  //这一行要有！！ 不能断链了
        p = p->next = tmp;
        ++obj.currentLength;
        ++i;
    }

    return is;
}