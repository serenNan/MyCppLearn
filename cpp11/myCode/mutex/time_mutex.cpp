#include <chrono>
#include <iostream>
#include <mutex>
#include <thread>
using namespace std;

timed_mutex g_mutex;
void work(const string &thread_name)
{
    chrono::seconds timeout(1);

    if (g_mutex.try_lock_for(timeout))
    {
        cout << "线程 [" << thread_name << "] 获得互斥锁！ID：" << this_thread::get_id() << endl;
        // 模拟工作：占用 1秒
        this_thread::sleep_for(chrono::seconds(1));
    }
    else
    {
        cout << "线程 [" << thread_name << "] 未获得锁，重试..." << endl;
        this_thread::sleep_for(chrono::milliseconds(50));
    }
}

int main()
{
    thread t1(work, "Thread1");
    thread t2(work, "Thread2");
    t1.join();
    t2.join();
    return 0;
}