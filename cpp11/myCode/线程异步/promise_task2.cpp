#include <future>
#include <iostream>
#include <string>
#include <thread>

using namespace std;

int main()
{
    // packaged_task<返回值类型(参数类型)>
    packaged_task<int(string)> task([](string x) -> int {
        // lambda参数类型必须匹配packaged_task的参数类型(string)
        // lambda返回值类型必须匹配packaged_task的返回值类型(int)
        return stoi(x); // 将string转换为int返回
    });

    // thread构造函数的参数:
    // 第一个参数是可调用对象(这里是包装后的task)
    // 第二个参数必须能转换为task的参数类型(string)
    thread t1(ref(task), "10"); 

    // future类型必须匹配packaged_task的返回值类型(int)
    future<int> f = task.get_future();

    // value类型必须匹配future的模板参数(int)
    int value = f.get();
    cout << "value: " << value << endl;

    t1.join();
    return 0;
}
