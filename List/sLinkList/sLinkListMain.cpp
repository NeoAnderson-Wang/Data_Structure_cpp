#include <iostream>
// #include "sLinkList.h"
#include "sLinkList.cpp"
using namespace std;

int main()
{
    sLinkList<int> a, b;
    int i;
    cin >> a;
    cout << a;
    cout << a.length() << endl;

    a.erase(2,5);
    cout << a;
    a.erase(2,1);

    a.reverse();
    cout << a;

    cout << a.movebackward(2) << endl;
    cout << a.movebackward(-100) << endl;

    cin >> b;
    cout << b;
    cout << b.length() << endl;

    cout << SearchSameSuffix(a,b) << endl;
    // for (int i = 1; i < 10; ++i)
    //     a.insert(i, i);
    // cout << a;
    // a.reverse();
    // cout << a;
    // a.reverse1();
    // cout << a;

    system("pause");
    return 0;
}