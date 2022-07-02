#include <iostream>
#include "seqList.h"
#include "seqList.cpp"
using namespace std;

int main()
{
    seqList<int> a,b,c;
    cin >> a;
    cin >> b;
    cout << a.length() << " " << a.capacity() << endl;
    cout << b.length() << " " << b.capacity() << endl;

    c=a+b;
    cout << c;
    cout << c.length() << " " << c.capacity() << endl;

    system("pause");
    return 0;
}

// .exe  does not exit
// :注意终端输出，看看是否有东西没定义完整
// 似乎 include .cpp 暂时没啥问题
// 可能太智能了？