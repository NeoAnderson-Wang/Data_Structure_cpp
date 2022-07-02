#include <iostream>
// #include <stack>
// #include <list>
#include "seqFHQueue.cpp"
#include "D:\VsCode_Cpp\Data_Structure\List\seqList\seqList.cpp"
using namespace std;

int main()
{
    seqFHQueue<int> a(2);
    int i;
    cout << a.isEmpty() << endl;
    cout << a.capacity() << endl;

    for (i = 0; i < 10; ++i)
        a.enQueue(i);
    cout << a.isEmpty() << endl;
    cout << a.capacity() << endl;
    cout << a.getHead() << endl;
    cout << a.getTail() << endl;

    for (i = 0; i < 10; ++i)
        cout << a.deQueue() << " ";
    cout << endl;
    // stack<int, list<int>> a;
    system("pause");
    return 0;
}