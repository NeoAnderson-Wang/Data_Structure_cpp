#include <iostream>
#include "dLinkList.cpp"
using namespace std;

int main()
{
    dLinkList<double> a, b, c;
    int i;
    cin >> a;
    cout << a;
    cout << a.length() << endl;

    cin >> b;
    cout << b;
    cout << b.length() << endl;

    c = a + b;
    cout << c;
    cout << c.length() << endl;

    system("pause");
    return 0;
}