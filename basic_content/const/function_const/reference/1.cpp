#include <iostream>
using namespace std;

void func(int *var) // 指针本身不可变
{
    *var = 2;
}
int main()
{
    int a = 1;
    cout << a;
    func(&a);
    cout << a;
}