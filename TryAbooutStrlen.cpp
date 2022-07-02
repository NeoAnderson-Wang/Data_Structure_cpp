#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    char a1[] = "abcdef";
    char a2[] = "abc";
    char a3[] = "a\0bc";

    cout << strlen(a1) << endl;
    cout << strlen(a2) << endl;
    cout << strlen(a3) << endl;

    if (strlen(a1) - strlen(a2) > 0)
        cout << strlen(a1) << endl;
    else
        cout << strlen(a2);

    if (strlen(a1) > strlen(a2))
        cout << strlen(a1) << endl;
    else
        cout << strlen(a2);

    system("pause");
    return 0;
}