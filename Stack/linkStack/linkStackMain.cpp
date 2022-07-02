#include <iostream>
#include <cstring>
#include "linkStack.cpp"
using namespace std;

bool isReverse(char *s);

int main()
{
    //基本功能尝试
    linkStack<double> a;
    cout << a.isEmpty() << endl;
    for (int i = 0; i < 10; ++i)
        a.push(i);
    cout << a.isEmpty() << endl;

    cout << a.top() << endl;

    for (int i = 0; i < 10; ++i)
        cout << a.pop() << " ";
    cout << endl;

    //书P74 判断回文
    char b[80];
    cin.getline(b, 80);

    cout << isReverse(b) << endl;

    system("pause");
    return 0;
}

bool isReverse(char *s)
{
    int i, len = strlen(s);
    linkStack<char> st;

    for (i = 0; i < len; ++i)
        st.push(s[i]);

    for (i = 0; !st.isEmpty(); ++i)
        if (s[i] != st.pop())
            return false;
    return true;
}