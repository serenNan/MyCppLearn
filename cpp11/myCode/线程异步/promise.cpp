#include <future>
#include <iostream>
#include <thread>
using namespace std;

void func(promise<string> &p)
{
    this_thread::sleep_for(chrono::seconds(3));
    p.set_value("子线程的字符串");
    this_thread::sleep_for(chrono::seconds(1));
}

int main()
{
    promise<string> pro;
    //thread t1(func, ref(pro));
    thread t2([](promise<string> &p) {
        this_thread::sleep_for(chrono::seconds(3));
        p.set_value("子线程的字符串");
        this_thread::sleep_for(chrono::seconds(1));
    },ref(pro));
    future<string> f = pro.get_future();
    string str = f.get();
    cout << "子线程返回的数据:" << str << endl;
    t2.join();
    return 0;
}