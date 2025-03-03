#include <iostream>
using namespace std;


class Apple
{
private:
    int num;
public:
    Apple(int i); 
    const int apple_number;
    int add(int num);
    int take() const;
};

Apple::Apple(int i) : apple_number(i) {}

int Apple::add(int num)
{
    add(num);
    return 0;
}
int Apple::take() const
{
    add(1); // error
    return this->num;
}

int main()
{
    Apple a(2);
    a.add(10);
    a.take();
    cout << a.take() << endl;
    const Apple b(3);
    b.add(100); // error
    b.take();
    return 0;
}