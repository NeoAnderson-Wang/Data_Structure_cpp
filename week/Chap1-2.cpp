#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;

    if (n <= 0)
        cout << "INPUT ERROR!" << endl;
    else
    {
        if (n % 2 == 0)
            cout << -n / 2 << endl;
        else
            cout << (n + 1) / 2 << endl;
    }

    system("pause");
    return 0;
}