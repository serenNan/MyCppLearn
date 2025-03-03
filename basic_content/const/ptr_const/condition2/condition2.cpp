#include <iostream>
using namespace std;
int main()
{
    int num = 0;
    int *const ptr = &num; // error! const int* -> int*
    cout << *ptr << endl;
}
