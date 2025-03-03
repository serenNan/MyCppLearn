#include <iostream>

using namespace std;

const int func1()
{
    const int i = 1;
    return i;
}

int main()
{
    const int a = 1;
    int b = a;
    a = b; 
}