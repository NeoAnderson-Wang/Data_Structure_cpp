#include <iostream>
using namespace std;

int main()
{
    int i, n;
    bool flag = true;

    cin >> n;

    if (n <= 1)
    {
        cout << "INPUT ERROR!" << endl;
        flag = false;
    }
    else if (n > 2 && n % 2 == 0)
    {
        flag = false;
        cout << "It is NOT a prime number" << endl;
    }
    else
    {
        for (i = 3; i <= n / 2; i += 2)
        {
            if (n % i == 0)
            {
                flag = false;
                cout << "It is NOT a prime number" << endl;
                break;
            }
        }
    }

    if (flag == true)
        cout << "It is a prime number" << endl;

    system("pause");
    return 0;
}