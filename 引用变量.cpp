//引用多用在结构体和类当中，主要是为了节约资源，提高效率

#include<iostream>

using namespace std;

int main()
{
    int a=1;

    //b是a的引用变量，它们指向相同的地址,声明引用时必须进行初始化
    int & b = a;       
    int* c=&a;

    cout<<&a<<endl<<&b<<endl<<c;

    return 0;
}