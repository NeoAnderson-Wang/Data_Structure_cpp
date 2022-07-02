#ifndef _DynamicSearch_h
#define _DynamicSearch_h
#include <iostream>
using namespace std;

//集合元素
template <class KEY, class OTHER>
struct SET
{
    KEY key;     //键值
    OTHER other; //其他信息
};

template <class KEY, class OTHER>
class DynamicSearchTable
{
public:
    virtual SET<KEY, OTHER> *find(const KEY &x) const = 0;
    virtual void insert(const SET<KEY, OTHER> &x) = 0;
    virtual void remove(const KEY &x) = 0;
    virtual ~DynamicSearchTable(){};
};

#endif