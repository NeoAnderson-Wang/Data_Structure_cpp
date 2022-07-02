#include <iostream>
#include <cmath>
#include "D:\VsCode_Cpp\Data_Structure\Stack\linkStack\linkStack.cpp"
using namespace std;

void DecimalConvertToBinary(double num); //书P103 T2 将非负十进制数转换为二进制输出
int calcRPN(char *s);                    //书P103 T5 计算后缀表达式
int ARec(int m, int n);                  //书P103 T9 Ackerman函数 recursion 递归
int ANORec(int m, int n);                //书P103 T9 Ackerman函数 非递归

int main()
{
    //书P103 T2 将非负十进制数转换为二进制输出
    double a;
    cin >> a;
    DecimalConvertToBinary(a); // e.g. 173.8125 -> 10101101.1101

    //书P103 T5 计算后缀表达式
    char s[80];
    cin.get();
    cin.getline(s, 80);           //整形会导致除法不准确
    cout << calcRPN(s) << endl;

    //书P103 T9 Ackerman函数
    int m, n;
    cin >> m >> n;
    cout << ARec(m, n) << endl;   //递归
    cout << ANORec(m, n) << endl; //非递归   //(3,6)开始有明显停顿

    system("pause");
    return 0;
}

void DecimalConvertToBinary(double num)
{
    if (num < 0)
    {
        cout << "INPUT ERROR!" << endl;
        return;
    }
    if (num == 0)
    {
        cout << 0 << endl;
        return;
    }

    int inte = num;
    double deci = num - inte;
    // cout << inte << " " << deci << endl;

    linkStack<char> Bnum;

    //整数部分：除2取余，逆序排列
    while (inte != 0)
    {
        Bnum.push(inte % 2 + '0'); //别忘了 +'0'!!!!!!!!!!
        inte /= 2;
    }
    while (!Bnum.isEmpty())
        cout << Bnum.pop();

    cout << '.';

    //小数部分：乘2取整，顺序排列
    while (deci != 0)
    {
        deci *= 2;
        cout << static_cast<int>(deci); //静态转换 格式写对！
        deci -= static_cast<int>(deci);
    }
    cout << endl;
}

//书P103 T5 计算后缀表达式
//认为各运算数为只有个位的整数
int calcRPN(char *s)
{
    // enum token{OPAREN,ADD,SUB,MULTI,DIV,EXP,CPAREN,VALUE,EOL};  //parentheses 括号，
    linkStack<int> taken;
    int rightnum, leftnum, result;

    while (*s)
    {
        //跳过空格
        if (*s == ' ') // s++ 不要写在判断里
        {
            s++;
            continue;
        }
        //接受数字
        if ('0' <= *s && *s <= '9')
        {
            taken.push(*s++ - '0');
            continue;
        }
        //接受符号
        if (taken.isEmpty())
        {
            cout << "RIGHT OPERANG LOST!" << endl;
            return -1;
        }
        else
            rightnum = taken.pop();

        if (taken.isEmpty())
        {
            cout << "LEFT OPERANG LOST!" << endl;
            return -1;
        }
        else
            leftnum = taken.pop();

        char now = *s;
        *s++;
        switch (now)
        {
        case '+':
            taken.push((leftnum + rightnum));
            break;
        case '-':
            taken.push((leftnum - rightnum));
            break;
        case '*':
            taken.push((leftnum * rightnum));
            break;
        case '/':
            taken.push((leftnum / rightnum));
            break;
        case '^':
            taken.push(pow(leftnum, rightnum));
            break;
        default:
            cout << "OPRATOR INPUT ERROR!" << endl;
            return -1;
        }
    }

    if (taken.isEmpty())
    {
        cout << "NO RESULT!" << endl;
        return -1;
    }
    result = taken.pop();
    if (!taken.isEmpty())
    {
        cout << "OPERATOR LOST!" << endl;
        return -1;
    }

    return result;
}

int ARec(int m, int n)
{
    if (m < 0 || n < 0)
    {
        cout << "INPUT ERROR!" << endl;
        return -1;
    }

    if (m == 0)
        return n + 1;
    if (m != 0 && n == 0)
        return ARec(m - 1, 1);
    if (m != 0 && n != 0)
        return ARec(m - 1, ARec(m, n - 1));
    cout << "INPUT ERROR!" << endl;
    return -1;
}

int ANORec(int m, int n)
{
    struct pos
    {
        int m, n;
    };
    linkStack<pos> A;
    pos tmp, tmp2;
    int result;

    if (m < 0 || n < 0)
    {
        cout << "INPUT ERROR!" << endl;
        return -1;
    }
    if (m == 0)
        return n + 1;

    tmp.m = m;
    tmp.n = n;
    A.push(tmp);

    while (!A.isEmpty())
    {
        if (A.top().m == 0)
        {
            result = A.top().n + 1;
            while (!A.isEmpty() && A.top().n != -1)  //没用到递归的，函数值均为n+1（即result)
                A.pop();

            if (A.isEmpty())
                return result;
            else // A.top().n = result 不对？
            {
                tmp.m = A.top().m;
                tmp.n = result;
                A.pop();
                A.push(tmp);  //当前top是递归，出栈后用tmp代替
            }
        }

        else if (A.top().m != 0 && A.top().n == 0)
        {
            tmp.m = A.top().m - 1;
            tmp.n = 1;
            A.push(tmp);
        }

        else if (A.top().m != 0 && A.top().n != 0)
        {
            tmp.m = A.top().m - 1;
            tmp.n = -1; //-1表示此处n是个递归，后面先算这个n
                        //也可将m,n先后入栈，m,n 均不为0时，将 m-1,m,n-1 依次入栈
            tmp2.m = A.top().m;
            tmp2.n = A.top().n - 1;

            A.push(tmp);
            A.push(tmp2);
        }
    }

    return result;
}