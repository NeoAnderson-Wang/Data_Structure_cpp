#include <iostream>
using namespace std;

int main()
{
    int i, a[10], b[10], c[10];
    a[0] = 1;
    a[1] = 1;

    for (i = 2; i < 10; ++i)
        a[i] = a[i - 1] + a[i - 2];

    b[0] = 1;
    b[1] = 2;
    for (i = 2; i < 10; ++i)
        b[i] = b[i - 1] + a[i];

    for (i = 0; i < 10; ++i)
        c[i] = (i + 1) * b[i];

    for (i = 0; i < 10; ++i)
        cout << c[i] << " ";
    cout << endl;

    system("pause");
    return 0;
}
