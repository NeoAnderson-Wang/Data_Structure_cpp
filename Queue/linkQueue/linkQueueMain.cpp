#include <iostream>
#include "linkQueue.cpp"
using namespace std;

int main()
{
    linkQueue<int> a;
    int i;
    cout << a.isEmpty() << endl;
    for (i = 0; i < 10; ++i)
        a.enQueue(i);
    cout << a.isEmpty() << endl;
    cout << a.getHead() << endl;

    for (i = 0; i < 10; ++i)
        cout << a.deQueue() << " ";
    cout << endl;

    system("pause");
    return 0;
}