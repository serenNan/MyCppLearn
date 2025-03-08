#include <iostream>
using namespace std;

class Apple
{
  public:
    void A()
    {
        _static = 1;
        non_static = 1;
        B();
        cout << "A" << endl;
    }
    
    static void B()
    {
        _static = 1;
        non_static = 1; // error
        A(); // error
        cout << "B" << endl;
    }

  private:
    int non_static;
    static int _static;
};

// main function
int main()
{
    Apple a;
    a.A();
    
    Apple :: B();
}
