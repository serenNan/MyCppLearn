#include <iostream>
using namespace std;

void change(int *dst, const int *src)
{
    *dst = 2;
    // *src = 2; // error
}

int main()
{
    int a = 1;
    int b = 1;
    int *ptr1 = &a;
    int *ptr2 = &b;
    change(ptr1, ptr2);
    cout << "ptr1 -> " << *ptr1 << endl;
    cout << "ptr2 -> " << *ptr2 << endl;
}