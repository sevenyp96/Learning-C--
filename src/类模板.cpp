/*********类模板***********/
//多文件中，类模板不能把声明和实现分开
//类模板在调用的时候必须显示调用，不能隐式调用
//类模板不是完整的类，故用到类名的地方必须用类名<类型的方式调用>
 #include<iostream>
 #include<string>
 #include<array>

 using namespace  std;

template<class _Ty1,class _Ty2>
class MM
{
public:
    MM() {}
    MM(_Ty1 one, _Ty2 two) :one(one),two(two){}
    void print();
protected:
    _Ty1 one;
    _Ty2 two;
};

//用到类型的地方必须要用类名<类型>的方式使用
template<class _Ty1,class _Ty2>
void MM<_Ty1,_Ty2>::print()
{
    cout<<one<<endl;
    cout<<two<<endl;
}

void testMM()
{
    MM<string,string> mm("abc","abcd");
    MM<int,string>* p=new MM<int ,string>(1,"zhangshan");
    p->print();
    mm.print();
}



template<class _Ty1,class _Ty2>
class Girl :public MM<_Ty1,_Ty2>
{
public:
    Girl(){}
protected:

};

template<class _Ty, int size>
class MyAarry
{
public:
    MyAarry()
    {
       memory = new _Ty[size];
    } 
protected:
    _Ty* memory;
};

void testMyArray()
{
    MyAarry<int, 3> arr; 
    array<int ,3> arr1D;//等效于一维数组int arr1D[3]
    for(int i=0;i<arr1D.size();i++)
    {
        arr1D[i]=i;
        cout<<arr1D[i]<<"\t";
    }
}

array<MM<int,string>,3> mmData;
/*下面两句与上面一句是等价的
using DataType =MM<int,string>; //起别名
array<DataType,3> mmData;
*/


//模板类的特化
template<class _Ty1,class _Ty2,class _Ty3>
class Data
{
public:
    Data(_Ty1 one,_Ty2 two,_Ty3 three) :one(one),two(two),three(three)
    {
        cout<<"原生模板"<<endl;
    }
protected:
    _Ty1 one;
    _Ty2 two;
    _Ty3 three;
};

//局部特化
template<class _Ty1>
class Data<_Ty1,_Ty1,_Ty1>
{
public:
    Data(_Ty1 one,_Ty1 two,_Ty1 three) :one(one),two(two),three(three)
    {
        cout<<"局部特化"<<endl;
    }
protected:
    _Ty1 one;
    _Ty1 two;
    _Ty1 three;
};
//完全特化--->针对特定数据做特定处理
template<>
class Data<int,string,string>
{
public:
    Data(int one,string two,string three) :one(one),two(two),three(three)
    {
        cout<<"完全特化"<<endl;
    }
protected:
    int one;
    string two;
    string three;
};

void testCallClass()
{
    Data<int,string,string> data1(1,"zhangshan","lisi");   //调用完全特化模板
    Data<string,string,string> data2("wangwu","qqq","sdasd"); //调用局部特化模板
    Data<string,int,string> data3("wangwu",111,"sdasd"); //调用原生模板
}
 int main()
 {


    testMM();

    testMyArray();
    testCallClass();

     return 0;
 }