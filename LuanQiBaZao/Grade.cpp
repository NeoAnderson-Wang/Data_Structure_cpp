#include <iostream>

using namespace std;
int i=0;

struct student
{
    long long int id;
    char name[50];
    int class1;
    int class2;
    int class3;
};

/*struct link
{
    student a;
    link *next;
};
*/
void fun1(student *a) //addstudent
{
    int j,k;
    long long int idnow;
    bool flag=false;
    char namenow[50]= {'\0'};
    int class1now,class2now,class3now;
    cin >> idnow >> class1now >> class2now >> class3now ;
    cin.get();
    cin.getline(namenow,50);

    for(j=0; j<i; ++j)
    {
        if(idnow==a[j].id)
        {
            flag=true;
            a[j].class1=class1now;
            a[j].class2=class2now;
            a[j].class3=class3now;
            for(k=0; k<50/*&&a[j].name[k]!='\0'*/; ++k)
            {
                a[j].name[k]='\0';
                a[j].name[k]=namenow[k];
            }
        }
    }

    if(flag==false)
    {
        a[i].id=idnow;
        a[i].class1=class1now;
        a[i].class2=class2now;
        a[i].class3=class3now;
        for(k=0; k<50&&namenow[k]!='\0'; ++k)
            a[i].name[k]=namenow[k];

        i++;
    }
}

void fun2(student *a) //change
{
    int j,k;
    long long int idnow;
    char namenow[50]= {'\0'};
    int class1now,class2now,class3now;
    cin >> idnow >> class1now >> class2now >> class3now ;
    cin.get();
    cin.getline(namenow,50);

    for(j=0; j<i; ++j)
    {
        if(idnow==a[j].id)
        {
            a[j].class1=class1now;
            a[j].class2=class2now;
            a[j].class3=class3now;
            for(k=0; k<50/*&&a[j].name[k]!='\0'*/; ++k)
            {
                a[j].name[k]='\0';
                a[j].name[k]=namenow[k];
            }
        }
    }
}

void fun3(student *a) //delete
{
    long long int delid;
    int j,k;
    cin >> delid;
    for(j=0; j<i; ++j)
    {
        if(a[j].id==delid)
        {
            a[j].id=0;
            a[j].class1=0;
            a[j].class2=0;
            a[j].class3=0;
            for(k=1; k+j<i; ++j)
            {
                //a[j].name[k]='\0';  //内存泄露？
                a[j+k-1]=a[j+k];
            }
            a[i-1].id=0;
            a[i-1].class1=0;
            a[i-1].class2=0;
            a[i-1].class3=0;
            for(k=0;k<50;++k)
                a[i-1].name[k]='\0';
            --i;
        }
        //break;
    }
}

void fun4(student *a) //inquire
{
    long long int inqid;
    int j;
    cin >> inqid;

    for(j=0; j<i; ++j)
    {
        if(a[j].id==inqid)
        {
            cout << a[j].id << " " << a[j].name << " " << a[j].class1 << " " << a[j].class2 << " " << a[j].class3 << " " << endl;
        }
    }
}

void fun5(student *a)
{
    char namenow[50];
    bool flag=false;
    int count=0;
    cin.get();
    cin.getline(namenow,50);

    int l,r,j,k;
    student tmp;
    for(l=0; l<i; ++l)
    {
        r=l;
        for(j=l; j<i; ++j)
            if(a[j].id<a[r].id) r=j;
        tmp =a[l];
        a[l]=a[r];
        a[r]=tmp;
    }
    for(j=0; j<i; ++j)
    {
        for(k=0; k<50&&namenow[k]!='\0'; ++k)
        {
            if(a[j].name[k]==namenow[k])
                ++count;
            //else break;
        }
        if(count==k)
        {
            cout << a[j].id << " " << a[j].name << " " << a[j].class1 << " " << a[j].class2 << " " << a[j].class3 << " " << endl;
        }
        count=0;
    }

}

void fun6(student *a)
{
    int l,r,j;
    student tmp;
    for(l=0; l<i; ++l)
    {
        r=l;
        for(j=l; j<i; ++j)
            if(a[j].id<a[r].id) r=j;
        tmp =a[l];
        a[l]=a[r];
        a[r]=tmp;
    }
    for(j=0; j<i; ++j)
    {
        cout << a[j].id << " " << a[j].name << " " << a[j].class1 << " " << a[j].class2 << " " << a[j].class3 << " " << endl;
    }
}

void fun7(student *a)
{
    int sum[1000]= {0},j,l,r,tmpi=0;
    student tmp;

    for(j=0; j<i; ++j)
        sum[j]=a[j].class1+a[j].class2+a[j].class3;

    for(l=0; l<i; ++l)
    {
        r=l;
        for(j=l; j<i; ++j)
            if(sum[j]>sum[r]) r=j;
            else if(sum[j]==sum[r])
            {
                if(a[j].id<a[r].id) r=j;
            }
        tmp =a[l];
        a[l]=a[r];
        a[r]=tmp;

        tmpi=sum[l];
        sum[l]=sum[r];
        sum[r]=tmpi;
    }
    for(j=0; j<i; ++j)
    {
        cout << a[j].id << " " << a[j].name << " " << a[j].class1 << " " << a[j].class2 << " " << a[j].class3 << " " << endl;
    }
}

int main()
{
    int n;
    student a[1000]={0};
    while(1)
    {
        cin >> n;
        switch (n)
        {
        case 1 :
            fun1(a);
            break;
        case 2 :
            fun2(a);
            break;
        case 3 :
            fun3(a);
            break;
        case 4 :
            fun4(a);
            break;
        case 5 :
            fun5(a);
            break;
        case 6 :
            fun6(a);
            break;
        case 7 :
            fun7(a);
            break;
        case 0:
            break;
        }
        if(n==0) break;
    }



    return 0;
}

