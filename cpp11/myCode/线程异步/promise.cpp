#include <future>
#include <iostream>
#include <thread>

using namespace std;

int main()
{
    promise<int> pr;
    thread t1(
        [](promise<int> &p) {
            p.set_value_at_thread_exit(100);
            this_thread::sleep_for(chrono::seconds(3));
            cout << "睡醒了...." << endl;
        },
        ref(pr));

    future<int> f = pr.get_future();
    int value = f.get();
    cout << "value: " << value << endl;

    t1.join();
    return 0;
}
