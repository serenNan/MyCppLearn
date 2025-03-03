#include <iostream>
using namespace std;

class Apple
{
  private:
    int num;

  public:
    Apple(int i);
    static const int apple_number = 10;
    static int app;
    int add(int num);
    int take() const;
};

int Apple :: app = 1;

int Apple::add(int num)
{
    add(num);
    return 0;
}
int Apple::take() const
{
    return this->num;
}

