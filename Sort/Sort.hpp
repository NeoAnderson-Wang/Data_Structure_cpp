#ifndef _Sort_h
#define _Sort_h
#include <iostream>
using namespace std;

//按递增排序

//集合元素
template <class KEY, class OTHER>
struct SET
{
    KEY key;     //键值
    OTHER other; //其他信息
};

// 插入排序
//直接插入排序
template <class KEY, class OTHER>
void simpleInsertSort(SET<KEY, OTHER> a[], int size)
{
    int k;
    SET<KEY, OTHER> tmp;

    for (int j = 1; j < size; ++j)
    {
        tmp = a[j];
        for (k = j - 1; k >= 0 && a[k].key > tmp.key; --k)
            a[k + 1] = a[k];
        a[k + 1] = tmp; //此时a[k].key<=tmp
    }
}

//二分插入排序（自己写的）
template <class KEY, class OTHER>
void binaryInsertSort(SET<KEY, OTHER> a[], int size)
{
    int low, high, mid;
    int i, j, pos;
    SET<KEY, OTHER> tmp;

    for (i = 1; i < size; ++i)
    {
        if (a[i].key < a[i - 1].key) //如果a[i]已经是最大的，就没必要在找；  如果硬找会造成特例！！！
        {
            low = 0;
            high = i - 1;
            tmp = a[i];
            while (low <= high)
            {
                mid = (low + high) / 2;
                if (a[mid].key == tmp.key)
                    break;
                if (a[mid].key > tmp.key)
                    high = mid - 1;
                else
                    low = mid + 1;
            }
            pos = mid - 1; // pos为比tmp小的第一个元素的位置
            for (j = i - 1; j > pos; --j)
                a[j + 1] = a[j];
            a[j + 1] = tmp; //是j+1,a[j]和a[i]之间所有都往后挪了
        }
    }
}

//希尔排序
template <class KEY, class OTHER>
void shellSort(SET<KEY, OTHER> a[], int size)
{
    int step, i, j;
    SET<KEY, OTHER> tmp;

    for (step = size / 2; step > 0; step /= 2) //增量序列从N/2平分到1
    {
        for (i = step; i < size; ++i)
        {
            tmp = a[i];
            for (j = i - step; j >= 0 && a[j].key > tmp.key; j -= step)
                a[j + step] = a[j];
            a[j + step] = tmp;
        }
    }
}

// 选择排序
//直接选择排序
template <class KEY, class OTHER>
void simpleSelectSort(SET<KEY, OTHER> a[], int size)
{
    int i, j, min; // min为目前最小值的坐标
    SET<KEY, OTHER> tmp;

    for (i = 0; i < size; ++i)
    {
        min = i;
        for (j = i + 1; j < size; ++j)
            if (a[j].key < a[min].key)
                min = j;
        tmp = a[i];
        a[i] = a[min];
        a[min] = tmp;
    }
}

//堆排序
template <class KEY, class OTHER>
void heapSort(SET<KEY, OTHER> a[], int size)
{
    int i;
    SET<KEY, OTHER> tmp;

    for (i = size / 2 - 1; i >= 0; --i) //创建二叉堆(size=最大下标+1)
        percolateDown(a, i, size);      //在原数列的基础上，对每个父结点向下过滤

    for (i = size - 1; i > 0; --i)
    {
        tmp = a[0];
        a[0] = a[i];
        a[i] = tmp; //相当于deQueue()
        percolateDown(a, 0, i);
    }
}

template <class KEY, class OTHER>
void percolateDown(SET<KEY, OTHER> a[], int hole, int size)
{
    int child;
    SET<KEY, OTHER> tmp = a[hole];

    for (; hole * 2 + 1 < size; hole = child) //有儿子
    {
        child = hole * 2 + 1;
        if (child != size - 1 && a[child + 1].key > a[child].key) //要求右儿子存在
            child++;
        if (a[child].key > tmp.key)
            a[hole] = a[child];
        else
            break;
    }
    a[hole] = tmp;
}

//建最小化堆的percolateDown()
template <class KEY, class OTHER>
void percolateDownMin(SET<KEY, OTHER> a[], int hole, int size)
{
    int child;
    SET<KEY, OTHER> tmp = a[hole];

    for (; hole * 2 + 1 < size; hole = child) //有儿子
    {
        child = hole * 2 + 1;
        if (child != size - 1 && a[child + 1].key < a[child].key) //要求右儿子存在
            child++;
        if (a[child].key < tmp.key)
            a[hole] = a[child];
        else
            break;
    }
    a[hole] = tmp;
}

//交换排序
//冒泡排序
template <class KEY, class OTHER>
void bubbleSort(SET<KEY, OTHER> a[], int size)
{
    int i, j;
    SET<KEY, OTHER> tmp;
    bool flag = true; //记录是否起泡

    for (i = 1; i < size && flag; ++i) //上一轮起泡过;  i代表第几次，即尾部有i个有序
    {
        flag = false; //标定，初始化，现在暂未起泡
        for (j = 0; j < size - i; ++j)
        {
            if (a[j + 1].key < a[j].key) // 1别写成i ！！！
            {
                tmp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = tmp;
                flag = true;
            }
        }
    }
}

//快速排序
template <class KEY, class OTHER>
void quickSort(SET<KEY, OTHER> a[], int size)
{
    quickSort(a, 0, size - 1);
}

template <class KEY, class OTHER>
void quickSort(SET<KEY, OTHER> a[], int low, int high)
{
    int mid;
    if (low >= high)
        return;
    mid = divide(a, low, high); // mid位置已定
    quickSort(a, low, mid - 1);
    quickSort(a, mid + 1, high);
}

template <class KEY, class OTHER>
int divide(SET<KEY, OTHER> a[], int low, int high)
{
    SET<KEY, OTHER> k = a[low];

    do
    {
        while (low < high && a[high].key >= k.key)
            --high;
        if (low < high)
        {
            a[low] = a[high];
            ++low;
        }
        while (low < high && a[low].key <= k.key)
            ++low;
        if (low < high)
        {
            a[high] = a[low];
            --high;
        }
    } while (low != high);

    a[low] = k;
    return low;
}

//归并排序
template <class KEY, class OTHER>
void mergeSort(SET<KEY, OTHER> a[], int size)
{
    mergeSort(a, 0, size - 1);
}

template <class KEY, class OTHER>
void mergeSort(SET<KEY, OTHER> a[], int left, int right)
{
    int mid = (left + right) / 2;

    if (left == right)
        return;
    mergeSort(a, left, mid);
    mergeSort(a, mid + 1, right);
    merge(a, left, mid + 1, right);
}

template <class KEY, class OTHER>
void merge(SET<KEY, OTHER> a[], int left, int mid, int right)
{
    SET<KEY, OTHER> *tmp = new SET<KEY, OTHER>[right - left + 1];

    int i = left, j = mid, k = 0; //前半部分：left~mid-1; 后半部分：mid~right

    while (i < mid && j <= right)
        if (a[i].key < a[j].key)
            tmp[k++] = a[i++];
        else
            tmp[k++] = a[j++];

    while (i < mid)
        tmp[k++] = a[i++];
    while (j <= right)
        tmp[k++] = a[j++];

    for (i = 0, k = left; k <= right;)
        a[k++] = tmp[i++];
    delete[] tmp;
}

//基数排序
//仅针对int的key，数据结构为链表
template <class OTHER>
struct bucketNode
{
    SET<int, OTHER> data;
    bucketNode *next;

    bucketNode() { next = NULL; }
    bucketNode(SET<int, OTHER> d) : data(d) { next = NULL; }
};

template <class OTHER>
void bucketSort(bucketNode<OTHER> *&p)
{
    bucketNode<OTHER> *bucket[10], *last[10], *tail; // bucket,last：口袋的头尾; tail整个的尾巴
    int i, j, k, base = 1, max = 0, len = 0;

    for (tail = p; tail != NULL; tail = tail->next)
        if (tail->data.key > max)
            max = tail->data.key;

    if (max == 0)
        len = 0; //省的算
    else
        while (max > 0)
        {
            ++len;
            max /= 10;
        }

    for (i = 1; i <= len; ++i)
    {
        for (j = 0; j <= 9; ++j)
            bucket[j] = last[j] = NULL; //清空口袋
        while (p != NULL)
        {
            k = p->data.key / base % 10;
            if (bucket[k] == NULL)
                bucket[k] = last[k] = p;
            else
                last[k] = last[k]->next = p;
            p = p->next;
        }

        p = NULL; //重组
        for (j = 0; j < 10; ++j)
        {
            if (bucket[j] == NULL)
                continue;
            if (p == NULL)
                p = bucket[j];
            else
                tail->next = bucket[j];
            tail = last[j];
        }

        tail->next = NULL; //表尾置空
        base *= 10;
    }
}

//  家 庭 作 业
// P349 T4 将负整数放在正整数前面
template <class KEY, class OTHER>
void NegBeforePos(SET<KEY, OTHER> a[], int size)
{
    int neg = 0, i; // neg存储下一个将放负数的位置（此位置现在放的未必是负数）
    SET<KEY, OTHER> tmp;

    for (i = 0; i < size; ++i)
    {
        if (a[i].key < 0)
        {
            tmp = a[neg];
            a[neg] = a[i];
            a[i] = tmp;
            neg++;
        }
    }
}

// P349 T7 规模为N的无序数组中找第k大的元素
//时间复杂度 O(N+klogN)
template <class KEY, class OTHER>
SET<KEY, OTHER> findKMax(SET<KEY, OTHER> a[], int size, int k)
{
    int i;
    SET<KEY, OTHER> tmp;

    for (i = size / 2 - 1; i >= 0; --i)
        percolateDown(a, i, size);

    for (i = size - 1; i > size - k; --i)
    {
        tmp = a[0];
        a[0] = a[i];
        a[i] = tmp;
        percolateDown(a, 0, i);
    }
    return a[0];
}

//时间复杂度 O(Nlogk)   //找最大时会退化为 O(N)
template <class KEY, class OTHER>
SET<KEY, OTHER> FindKMax(SET<KEY, OTHER> a[], int size, int k)
{
    int i;
    SET<KEY, OTHER> tmp;

    for (i = k / 2 - 1; i >= 0; --i) //对前k个建 ！！最小化堆！！
        percolateDownMin(a, i, k);

    for (i = k + 1; i < size; ++i)
    {
        if (a[i].key > a[0].key)
        {
            tmp = a[0];
            a[0] = a[i];
            a[i] = tmp;
            percolateDownMin(a, 0, k); //两处percolateDown()第3个参数都为 k , 只需对前 k 个向下过滤
        }
    }
    return a[0];
}

// P349 T10 a[n]中 n个不同元素，关键字值位于0~n-1，且互不相同
//递增排序，时间复杂度O(N)，空间复杂度O(1)
//这题想干嘛？？？
template <class OTHER>
void Nsort(SET<int, OTHER> a[], int n)
{
    int i,temp;
    SET<int, OTHER> tmp;

    for (i = 0; i < n; ++i)
    {
        while (a[i].key != i + 1)
        {
            tmp = a[i];
            temp=a[i].key-1;  //需要存下a[i].key，不然换的时候会变
            a[i] = a[temp];
            a[temp] = tmp;
        }
    }
}

// P349 T12
// O(N^2)
template <class OTHER>
void isPair(SET<int, OTHER> a[], int size, int k)
{
    int i, j;
    bool flag = false;

    for (i = 0; i < size; ++i)
        for (j = i + 1; j < size; ++j)
            if (a[i].key + a[j].key == k)
            {
                cout << "(" << a[i].key << " " << a[i].other << "," << a[j].key << " " << a[j].other << ")";
                flag = true;
            }

    if (flag == false)
        cout << "NOT FOUND!";
    cout << endl;
}

// O(NlogN)
template <class OTHER>
void isPAIR(SET<int, OTHER> a[], int size, int k)
{
    quickSort(a, size);

    int i = 0, j = size - 1;
    while (i < j)
    {
        if (a[i].key + a[j].key > k)
            j--;
        else if (a[i].key + a[j].key == k)
            cout << "(" << a[i].key << " " << a[i++].other << "," << a[j].key << " " << a[j--].other << ")"; //同时变 i,j
        else
            i++;
    }
}

#endif