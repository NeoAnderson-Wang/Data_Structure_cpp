#include <iostream>
#include "priorityQueue.cpp"
using namespace std;

int main()
{
    int a[] = {3, 6, 7, 12, 8, 21, 14, 15, 37, 18, 24, 23, 33, 18, 17, 26};
    priorityQueue<int> p(a, 16);
    // p.enQueue(0);
    p.printPQ();

    cout << p.findMin(9) << endl;

    // while (!p.isEmpty())
    //     cout << p.deQueue() << " ";

    p.decreaseKey(4, 7);
    p.printPQ();
    while (!p.isEmpty())
        cout << p.deQueue() << " ";

    system("pause");
    return 0;
}