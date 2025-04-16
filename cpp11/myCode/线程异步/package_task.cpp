#include <functional>
#include <future>
#include <iostream>
#include <thread>

using namespace std;

void func(promise<string> &p)
{
    this_thread::sleep_for(chrono::seconds(3));
    p.set_value("我是路飞，要成为海贼王。。。");
    this_thread::sleep_for(chrono::seconds(1));
}

string myFunc()
{
    this_thread::sleep_for(chrono::seconds(3));
    return "我是路飞，要成为海贼王。。。";
}

using funcPtr = string (*)(string, int);
class Base
{
  public:
    string operator()(string msg)
    {
        string str = "operator() function msg: " + msg;
        return str;
    }

    operator funcPtr()
    {
        return showMsg;
    }

    int getNumber(int num)
    {
        int number = num + 100;
        return number;
    }

    static string showMsg(string msg, int num)
    {
        string str = "showMsg() function msg: " + msg + ", " + to_string(num);
        return str;
    }
};

int main()
{
    // 普通函数
    packaged_task<string(void)> task1(myFunc);
    // 匿名函数
    packaged_task<int(int)> task2([](int arg) { return arg; });
    // 仿函数
    Base ba;
    packaged_task<string(string)> task3(ba);

    // 将类对象进行转换得到的函数指针
    Base bb;
    packaged_task<string(string, int)> task4(bb);
    // 静态函数
    packaged_task<string(string, int)> task5(&Base::showMsg);
    // 非静态函数
    Base bc;
    auto obj = bind(&Base::getNumber, &bc, placeholders::_1);
    packaged_task<int(int)> task6(obj);

    thread t1(ref(task2), 200);
    future<int> f = task2.get_future();
    int num = f.get();
    cout << "子线程返回值: " << num << endl;
    t1.join();
}
