#include <iostream>
using namespace std;

int main()
{
    int i, n;
    long long int result = 0, p = 1;
    cin >> n;

    if (n < 1)
        cout << "INPUT ERROR!" << endl;
    else
    {
        for (i = 1; i <= n; ++i)
        {
            p *= i;
            result += p;
        }

        cout << result << endl;
    }

    system("pause");
    return 0;
}