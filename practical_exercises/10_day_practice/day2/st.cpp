/* 结构体.cpp */
#include <iostream>
using namespace std;
struct student
{
    int num;
    char name[20];
    char gender;
};

int main(int argc, char const *argv[])
{
    student s = {10, "asd", 'M'};
    cout << s.num << endl;
    cout << sizeof(s.num) << endl;
    cout << sizeof(s.name) << endl;
    cout << sizeof(s.gender) << endl;
    cout << sizeof(s) << endl;
    // C++中，当定义一个结构体（struct）时，编译器会按照成员变量的顺序在内存中排列这些变量。为了提高访问效率，编译器会在必要时在成员变量之间插入“填充字节”（也称为空位或对齐字节），以确保每个成员变量都从它们的对齐边界开始。这种机制称为“内存对齐”或“数据对齐”
    return 0;
}
