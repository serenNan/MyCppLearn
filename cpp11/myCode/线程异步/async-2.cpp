#include <chrono>
#include <future>
#include <iostream>
#include <thread>

using namespace std;

int main()
{
    cout << "主线程ID: " << this_thread::get_id() << endl;
    future<int> f = async(
        launch::async,
        [](int x) {
            cout << "子线程ID: " << this_thread::get_id() << endl;
            return x += 100;
        },
        100);

    this_thread::sleep_for(chrono::seconds(5));
    cout << f.get();

    return 0;
}