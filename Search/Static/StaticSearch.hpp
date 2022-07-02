#ifndef _StaticSearch_hpp
#define _StaticSearch_hpp
// .hpp 详百度
#include <iostream>
using namespace std;

//集合元素
template <class KEY, class OTHER>
struct SET
{
    KEY key;     //键值
    OTHER other; //其他信息
};

//无序表的顺序查找
template <class KEY, class OTHER>
int seqSearch(SET<KEY, OTHER> data[], int size, const KEY &x)
{
    data[0].key = x;
    int i;
    for (i = size; x != data[i].key; --i)
        ;
    return i; // i==0 不存在
}

//默认有序表递增
//有序表的顺序查找
template <class KEY, class OTHER>
int seqSearchOrder(SET<KEY, OTHER> data[], int size, const KEY &x)
{
    data[0].key = x;
    int i;
    for (i = 0; x < data[i].key; --i)
        ;
    if (x == data[i].key && i != 0)
        return i;
    else
        return 0;
}

//有序表的二分查找（非递归）
template <class KEY, class OTHER>
int binarySearch(SET<KEY, OTHER> data[], int size, const KEY &x)
{
    int low = 1, high = size, mid;
    while (low <= high)
    {
        mid = (low + high) / 2;
        if (x == data[mid].key)
            return mid;
        if (x < data[mid].key)
            high = mid - 1;
        else
            low = mid + 1;
    }
    return 0;
}

//书P246 T1
//有序表的二分查找（递归）
template <class KEY, class OTHER>
int BiSearch(SET<KEY, OTHER> data[], int low, int high, const KEY &x) //可做右值
{
    int mid = (low + high) / 2;
    if (low > high)
        return 0;
    if (x == data[mid].key)
        return mid;
    if (x < data[mid].key)
        return BiSearch(data, low, mid - 1, x);
    else
        return BiSearch(data, mid + 1, high, x);
}

template <class KEY, class OTHER>
int binarySearchRec(SET<KEY, OTHER> data[], int size, const KEY &x)
{
    return BiSearch(data, 1, size, x); //传入时，data 后无需加 []  ;  传入时，无需写参数类型，返回值类型
}

#endif