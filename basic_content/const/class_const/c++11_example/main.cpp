//#include "apple.h"
#include <iostream>
using namespace std;

class Apple
{
  public:
    Apple(int i);
    // 使用c++11标准编译
    static const int apple_number = 10;
    // const int apple_number=10;
    void take(int num) const;
    int add(int num);
    int add(int num) const;
    int getCount() const;
};

int main()
{
    Apple a(2);
    cout << a.getCount() << endl;
    a.add(10);
    const Apple b(3);
    b.add(100);
    return 0;
}
