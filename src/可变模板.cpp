#include<iostream>
#include<stdio.h>

using namespace std;


template<class _Ty>
void printDAta(_Ty data)
{
    cout<<data<<" ";
}

//知道折叠参数的类型：...  Args
// 类型为：...Args
//参数包（变量名）：Args... args

//知道折叠参数的展开方式
template<class ... Args>
void print(Args... args)    
{
    int num=sizeof...(args);//检查参数表中有几个参数
    int array[]={(printDAta(args),0)...};
    //若args：{1，"string","name"}
    //printDAta("string");  args：{"string","name"} array[0]=0
    //printDAta("name");  args：{} array[0]=0
    cout<<endl;
}



int main()
{
    print(1);
    print(2.2,3);
    print(1,"string","name",1);
}