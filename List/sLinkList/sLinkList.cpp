#include <iostream>
#include "sLinkList.h"
using namespace std;

template <class elemType>
typename sLinkList<elemType>::node *sLinkList<elemType>::move(int i) const // sLinkList 前须加上 typename
{
    node *p = head;
    while (i-- > 0)  //如果 i<0, return head
        p = p->next; // i--,--i区别？
    return p;
}

template <class elemType>
sLinkList<elemType>::sLinkList()
{
    head = new node;
    currentLength = 0;
}

template <class elemType>
void sLinkList<elemType>::clear()
{
    node *p = head->next, *q;

    if (currentLength == 0)
        return; //处理特殊情况，防止空链表

    head->next = NULL;      //变成空链表，head还存在
    while (p->next != NULL) //����Ǹ���������ֻ��head��p��֪��ָ����ȥ�ˣ�while��������   ��(����ѭ����)   segmentation fault
    {
        q = p->next;
        delete p;
        p = q;
    }
    currentLength = 0; //这个不要忘！
}

template <class elemType>
void sLinkList<elemType>::insert(int i, const elemType &x)
{
    node *pos;
    pos = move(i - 1); //动到前一个
    pos->next = new node(x, pos->next);
    ++currentLength;
}

template <class elemType>
void sLinkList<elemType>::remove(int i)
{
    node *pos, *delp; //删除的时候会有delp
    pos = move(i - 1);
    delp = pos->next;
    pos->next = delp->next;
    delete delp;
    --currentLength;
}

template <class elemType>
int sLinkList<elemType>::search(const elemType &x) const
{
    node *p = head->next;
    int i = 1; //认为head是第0个

    while (p != NULL && p->data != x)
    {
        p = p->next;
        ++i;
    }
    if (p == NULL)
        return -1;
    else
        return i;
}

template <class elemType>
elemType sLinkList<elemType>::visit(int i) const
{
    return move(i)->data;
}

template <class elemType>
void sLinkList<elemType>::traverse() const
{
    node *p = head->next;

    if (currentLength == 0)
    {
        cout << "It's empty" << endl;
        return;
    }

    // cout << endl;
    while (p != NULL)
    {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}

template <class elemType>
void sLinkList<elemType>::erase(int i)
{
    node *pre = move(i - 1), *delp = pre->next;
    elemType tmp = delp->data; //存储要删的数据
    int cnt = 1;

    pre->next = delp->next;
    delete delp;

    for (pre = head; pre->next != NULL;)
    {
        if (pre->next->data == tmp)
        {
            delp = pre->next;
            pre->next = delp->next;
            delete delp;
            ++cnt;
        }
        else
            pre = pre->next;
    }
    currentLength -= cnt;
}

//书P66 T1 删除值在[x,y]间的结点
template <class elemType>
void sLinkList<elemType>::erase(elemType x, elemType y)
{
    node *p, *delp;
    int cnt = 0;

    if (x > y)
    {
        cout << "INPUT ERROR" << endl;
        return;
    }

    for (p = head; p->next != NULL;)
    {
        if (p->next->data >= x && p->next->data <= y)
        {
            delp = p->next;
            p->next = delp->next;
            delete delp;
            ++cnt;
        }
        else
            p = p->next;
    }
    currentLength -= cnt;
}

//书P66 T6 逆置单链表
template <class elemType>
void sLinkList<elemType>::reverse() const
{
    node *tmp, *pleft, *pright;

    if (head->next == NULL)
        return;

    pleft = head->next;
    if (pleft->next == NULL)
    {
        head->next = pleft;
        return;
    }

    tmp = pleft->next;
    pleft->next = NULL;

    while (tmp->next != NULL)
    {
        pright = tmp->next;
        tmp->next = pleft;

        pleft = tmp;
        tmp = pright;
    }
    tmp->next = pleft;
    head->next = tmp;
}

//陈弈天的reverse
template<class elemType>
void sLinkList<elemType>::reverse1() const
{
    node *p=head->next,*q;      //p用来遍历，q是转置后head的下一个
    head->next=NULL;
    while(p)                    //p!=NULL
    {
        q=p;
        p=p->next;
        q->next=head->next;
        head->next=q;
    }
}

//书P67 T9 仅给出头指针，查找倒数第k个位置上的结点
template <class elemType>
int sLinkList<elemType>::movebackward(int k) const //要求 k > = 0 !!!
{
    int cnt = 0, length;
    node *p = head;

    while (p->next != NULL)
    {
        cnt++;
        p = p->next;
    }
    length = cnt;

    if (k > length || k <= 0)
        return 0; //超出范围

    cnt = length - k + 1;
    p = head;
    while (cnt-- > 0)
        p = p->next;
    cout << p->data << endl;
    return 1;
}

template <class elemType>
int SearchSameSuffix(const sLinkList<elemType> &str1, const sLinkList<elemType> &str2)
{
    typename sLinkList<elemType>::node *p, *q, *point1 = NULL, *point2 = NULL; //需指定作用域
    p = str1.head->next;
    q = str2.head->next;

    if (str1.currentLength == 0 || str2.currentLength == 0)
        return -1; //无法比较

    if (str1.currentLength > str2.currentLength)
        p = str1.move(str1.currentLength - str2.currentLength + 1);
    else if (str2.currentLength > str1.currentLength)
        q = str2.move(str2.currentLength - str1.currentLength + 1);

    int cnt = 0;
    bool isNull = true;
    while (p != NULL)
    {
        if (p->data == q->data)
        {
            if (isNull == true)
            {
                point1 = p;
                point2 = q;
                isNull = false;
            }
            cnt++;
        }
        else
        {
            cnt = 0;
            point1 = point2 = NULL;
            isNull = true;
        }
        p = p->next;
        q = q->next;
    }

    if (isNull == true)
        return -1; //未找到
    else
        return cnt; //返回相同的长度 （即从倒数第k个开始）
}

template <class elemType>
ostream &operator<<(ostream &os, const sLinkList<elemType> &obj)
{
    typename sLinkList<elemType>::node *p = obj.head->next;
    for (; p != NULL; p = p->next)
    {
        os << p->data << " ";
    }
    os << endl;
    return os;
}

template <class elemType>
istream &operator>>(istream &is, sLinkList<elemType> &obj)
{
    typename sLinkList<elemType>::node *tmp, *p = obj.move(obj.currentLength);
    int num, i = 1;
    elemType n;
    cout << "Please type in the number of the elements : ";
    is >> num;
    while (i <= num)
    {
        is >> n;
        tmp = new typename sLinkList<elemType>::node(n); // typename sLinkList<elemType> 格式要加上
        p = p->next = tmp;
        ++obj.currentLength;
        ++i;
    }

    return is;
}