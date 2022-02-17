//fstream：可读可写————一般编程都用它
//ifstream:读 in:往程序内存走
//ofstrean:写 out：打印到文件中

#include<fstream>
#include<iostream>
#include<string>
using namespace std;

void saveFile()
{
    fstream fp("write.txt",ios::in | ios::out);
    //判断文件是否打开成功
    if(!fp||!fp.is_open())
    {
        cout<<"打开文件失败"<<endl;
    }

    //<<、>>流操作
    fp<<1<<" "<<"name";
    fp.close();
}

void readFile()
{
    fstream fp("write.txt",ios::in | ios::out);
    //判断文件是否打开成功
    if(!fp||!fp.is_open())
    {
        cout<<"打开文件失败"<<endl;
    }

    int num;
    string str;
    //流的方式可以忽略空格和换行
    fp>>num>>str;
    cout<<"文件内容:"<<endl<<num<<"\t"<<str<<endl;
    fp.close();
}

int main()
{

    saveFile();
    readFile();
    return 0;
}