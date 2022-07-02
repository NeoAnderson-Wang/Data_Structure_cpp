#include <iostream>
#include "Sort.hpp"
using namespace std;

int main()
{
    int i;

    // 家 庭 作 业
    // P349 T4 将负整数放在正整数前面
    SET<int, char const *> a0[11] = {{10, "aaa"}, {8, "bbb"}, {21, "ccc"}, {-10, "aaa"}, {87, "ddd"}, {56, "eee"}, {-4, "fff"}, {11, "ggg"}, {-3, "hhh"}, {-22, "iiiii"}, {-7, "jjj"}};
    NegBeforePos(a0, 11);
    for (i = 0; i < 11; ++i)
        cout << a0[i].key << " " << a0[i].other << "  ";
    cout << endl;

    // P349 T7 规模为N的无序数组中找第k大的元素
    //时间复杂度 O(N+klogN)
    SET<int, char const *> a1[11] = {{10, "aaa"}, {8, "bbb"}, {21, "ccc"}, {-10, "aaa"}, {87, "ddd"}, {56, "eee"}, {-4, "fff"}, {11, "ggg"}, {-3, "hhh"}, {-22, "iiiii"}, {-7, "jjj"}};
    cout << findKMax(a1, 11, 3).key << " " << findKMax(a1, 11, 3).other << endl;

    //时间复杂度 O(Nlogk)
    SET<int, char const *> a2[11] = {{10, "aaa"}, {8, "bbb"}, {21, "ccc"}, {-10, "aaa"}, {87, "ddd"}, {56, "eee"}, {-4, "fff"}, {11, "ggg"}, {-3, "hhh"}, {-22, "iiiii"}, {-7, "jjj"}};
    cout << FindKMax(a2, 11, 3).key << " " << FindKMax(a2, 11, 3).other << endl;

    // P349 T10
    SET<int, char const *> an[5] = { {4, "aaa"}, {5, "bbb"}, {2, "ccc"}, {1, "eee"}, {3, "ddd"}};
    Nsort(an, 5);
    for (i = 0; i < 5; ++i)
        cout << an[i].key << " " << an[i].other << "  ";
    cout << endl;

    // P349 T12
    // O(N^2)
    SET<int, char const *> a3[11] = {{10, "aaa"}, {8, "bbb"}, {21, "ccc"}, {-10, "aaa"}, {87, "ddd"}, {56, "eee"}, {-4, "fff"}, {11, "ggg"}, {-3, "hhh"}, {-22, "iiiii"}, {-7, "jjj"}};
    isPair(a3, 11, 18);

    // O(NlogN)
    SET<int, char const *> a4[11] = {{10, "aaa"}, {8, "bbb"}, {21, "ccc"}, {-10, "aaa"}, {87, "ddd"}, {56, "eee"}, {-4, "fff"}, {11, "ggg"}, {-3, "hhh"}, {-22, "iiiii"}, {-7, "jjj"}};
    isPair(a4, 11, 1000000);

    //
    //
    // 课 本 验 证
    //直接插入排序
    SET<int, char const *> a[11] = {{10, "aaa"}, {8, "bbb"}, {21, "ccc"}, {10, "aaa"}, {87, "ddd"}, {56, "eee"}, {4, "fff"}, {11, "ggg"}, {3, "hhh"}, {22, "iiiii"}, {7, "jjj"}};
    simpleInsertSort(a, 11);
    for (i = 0; i < 11; ++i)
        cout << a[i].key << " " << a[i].other << "  ";
    cout << endl;

    //二分插入排序
    SET<int, char const *> b[11] = {{10, "aaa"}, {8, "bbb"}, {21, "ccc"}, {10, "aaa"}, {87, "ddd"}, {56, "eee"}, {4, "fff"}, {11, "ggg"}, {3, "hhh"}, {22, "iiiii"}, {7, "jjj"}};
    binaryInsertSort(b, 11);
    for (i = 0; i < 11; ++i)
        cout << b[i].key << " " << b[i].other << "  ";
    cout << endl;

    //希尔排序
    SET<int, char const *> c[11] = {{10, "aaa"}, {8, "bbb"}, {21, "ccc"}, {10, "aaa"}, {87, "ddd"}, {56, "eee"}, {4, "fff"}, {11, "ggg"}, {3, "hhh"}, {22, "iiiii"}, {7, "jjj"}};
    shellSort(c, 11);
    for (i = 0; i < 11; ++i)
        cout << c[i].key << " " << c[i].other << "  ";
    cout << endl;

    //直接选择排序
    SET<int, char const *> d[11] = {{10, "aaa"}, {8, "bbb"}, {21, "ccc"}, {10, "aaa"}, {87, "ddd"}, {56, "eee"}, {4, "fff"}, {11, "ggg"}, {3, "hhh"}, {22, "iiiii"}, {7, "jjj"}};
    simpleSelectSort(d, 11);
    for (i = 0; i < 11; ++i)
        cout << d[i].key << " " << d[i].other << "  ";
    cout << endl;

    //堆排序
    SET<int, char const *> E[11] = {{10, "aaa"}, {8, "bbb"}, {21, "ccc"}, {10, "aaa"}, {87, "ddd"}, {56, "eee"}, {4, "fff"}, {11, "ggg"}, {3, "hhh"}, {22, "iiiii"}, {7, "jjj"}};
    heapSort(E, 11);
    for (i = 0; i < 11; ++i)
        cout << E[i].key << " " << E[i].other << "  ";
    cout << endl;

    //冒泡排序
    SET<int, char const *> F[11] = {{10, "aaa"}, {8, "bbb"}, {21, "ccc"}, {10, "aaa"}, {87, "ddd"}, {56, "eee"}, {4, "fff"}, {11, "ggg"}, {3, "hhh"}, {22, "iiiii"}, {7, "jjj"}};
    bubbleSort(F, 11);
    for (i = 0; i < 11; ++i)
        cout << F[i].key << " " << F[i].other << "  ";
    cout << endl;

    //快速排序
    SET<int, char const *> G[11] = {{10, "aaa"}, {8, "bbb"}, {21, "ccc"}, {10, "aaa"}, {87, "ddd"}, {56, "eee"}, {4, "fff"}, {11, "ggg"}, {3, "hhh"}, {22, "iiiii"}, {7, "jjj"}};
    quickSort(G, 11);
    for (i = 0; i < 11; ++i)
        cout << G[i].key << " " << G[i].other << "  ";
    cout << endl;

    //归并排序
    SET<int, char const *> H[11] = {{10, "aaa"}, {8, "bbb"}, {21, "ccc"}, {10, "aaa"}, {87, "ddd"}, {56, "eee"}, {4, "fff"}, {11, "ggg"}, {3, "hhh"}, {22, "iiiii"}, {7, "jjj"}};
    mergeSort(H, 11);
    for (i = 0; i < 11; ++i)
        cout << H[i].key << " " << H[i].other << "  ";
    cout << endl;

    //
    //
    //
    //基数排序
    SET<int, char const *> w[11] = {{10, "aaa"}, {8, "bbb"}, {21, "ccc"}, {10, "aaa"}, {87, "ddd"}, {56, "eee"}, {4, "fff"}, {11, "ggg"}, {3, "hhh"}, {22, "iiiii"}, {7, "jjj"}};
    bucketNode<char const *> *head, *pos; //同单链表，head 头指针 保存整个链表，pos为当前位置，便于插入
    pos = head = new bucketNode<char const *>(w[0]);
    for (i = 1; i < 11; ++i)
    {
        pos = pos->next = new bucketNode<char const *>(w[i]);
    }

    bucketSort(head);
    pos = head;
    for (i = 0; i < 11; ++i, pos = pos->next)
        cout << pos->data.key << " " << pos->data.other << "  ";
    cout << endl;

    system("pause");
    return 0;
}