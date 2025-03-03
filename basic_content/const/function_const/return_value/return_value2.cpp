#include <iostream>
using namespace std;

int a = 10;
const int b = 20;
int *c = &a;
const int *func2()
{
    return &b;
} // 返回指向常数的指针

int main()
{
    int *p = func2(); // p是指向常数的指针
    *p = 30;                // 错误，不能修改p指向的值
    p = &a;                 // 正确，p现在指向a
    return 0;
}