#include <iostream>
#include "BinarySearchTree.cpp"
using namespace std;

int main()
{
    SET<int, char const *> a[] = {{10, "aaa"}, {8, "bbb"}, {21, "ccc"}, {87, "ddd"}, {56, "eee"}, {4, "fff"}, {11, "ggg"}, {3, "hhh"}, {22, "iiiii"}, {7, "jjj"}};
    BinarySearchTree<int, char const *> tree; // char* ：可修改值，char const* ：不可修改；字符串为常量，要加const
    SET<int, char const *> x;
    SET<int, char const *> *p; // SET的指针

    for (int i = 0; i < 10; ++i)
        tree.insert(a[i]);

    cout << tree.isOrdered() << endl;
    p = tree.Max();
    cout << p->key << " " << p->other << endl;
    p = tree.Min();
    cout << p->key << " " << p->other << endl;

    for (int i = 0; i < 10; ++i)
    {
        p = tree.iMin(i + 1); //要求 i>0， i==0时返回的是root
        cout << p->key << " " << p->other << "  ";
    }
    cout << endl;
    for (int i = 0; i < 10; ++i)
    {
        p = tree.iMax(i + 1);
        cout << p->key << " " << p->other << "  ";
    }
    cout << endl;

    p = tree.find(56);
    if (p)
        cout << "find 56 is " << p->key << " " << p->other << endl;
    else
        cout << "not found" << endl;

    tree.remove(56);
    p = tree.find(56);
    if (p)
        cout << "find 56 is " << p->key << " " << p->other << endl;
    else
        cout << "not found" << endl;

    p = tree.find(21);
    if (p)
        cout << "find 21 is " << p->key << " " << p->other << endl;
    else
        cout << "not found" << endl;

    tree.remove(21);
    p = tree.find(21);
    if (p)
        cout << "find 21 is " << p->key << " " << p->other << endl;
    else
        cout << "not found" << endl;

    x.key = 30;
    x.other = "xyz";
    tree.insert(x);
    p = tree.find(30);
    if (p)
        cout << "find 30 is " << p->key << " " << p->other << endl;
    else
        cout << "not found" << endl;

    system("pause");
    return 0;
}