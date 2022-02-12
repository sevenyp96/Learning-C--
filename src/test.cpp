#include<iostream>
#include<string>

using namespace std;
/*******函数模板**************/
template<class _Type>
_Type Max(_Type a,_Type b)
{
    return a>b?a:b;
}
//模板传变量
//调用的时候必须显示调用，且只能传入常量
template<class _Type,int Size>
_Type* newMemeory()
{
    return new _Type[Size];
}
void testConstSize()
{
    int* p =  newMemeory<int,4>();
    for(int i=0;i<4;i++)
    {
        p[i]=i;
        cout<<p[i]<<"\t";
    }
}
template<class _Type1,class _Type2=string>
void printData(_Type1 one, _Type2 two)
{
    cout<<one<<endl;
    cout<<two<<endl;
}
void func()
{
    printData<int>(1,"yipeng");//如果只传入一个参数另一个参数则为默认值string
    printData<int,int>(1,2);
}

class MM
{
public:
    //类中的函数模板
    template<class _Type>
    void print(_Type data)
    {
        cout<<data<<endl;
    }
protected:
};

//当调用函数时，若模板函数和普通函数均能匹配，则优先调用普通函数
template<class _Type1,class _Type2,class _Type3>
void printSum(_Type1 one,_Type2 two,_Type3 three)
{
    cout<<"普通函数……"<<endl;
    cout<<one<<endl;
    cout<<two<<endl;
    cout<<three<<endl;
}
void PrintSum(int one,int two,int three)
{
    cout<<"普通函数"<<endl;
    cout<<one<<endl;
    cout<<two<<endl;
    cout<<three<<endl;
}
void testCallFunc()
{
    printSum(1,2,3);
    printSum<int,int,int>(1,2,3);
}


int main()
{
    cout<<"hello world"<<endl;
    cout<<Max(1,5)<<endl;              //隐式调用
    cout<<Max<double>(1.2,1.3)<<endl;  //显示调用
    testConstSize();
    func();

    MM mm;
    mm.print(1.1);

    testCallFunc();
    return 0;
}

