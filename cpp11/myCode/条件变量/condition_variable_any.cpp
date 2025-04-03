#include <condition_variable>
#include <iostream>
#include <mutex>
#include <queue>
#include <thread>

using namespace std;

class TaskQueue
{
  public:
    // 添加数据
    void put(int task)
    {
        while (taskQueue.size() == maxSize)
        {
            full.wait(myMutex);
        }
        taskQueue.push(task);
        cout << "添加任务：" << task << "，线程ID：" << this_thread::get_id() << endl;
        // 唤醒生产者
        full.notify_one();
    }

    // 取数据
    void take()
    {
        myMutex.lock();
        empty.wait(myMutex, [=]() { return !taskQueue.empty(); });

        int node = taskQueue.front();
        taskQueue.pop();
        cout << "删除任务：" << node << "，线程ID：" << this_thread::get_id() << endl;
        myMutex.unlock();
        // 唤醒消费者
        empty.notify_one();
    }

    // 任务队列是否满
    bool isFull()
    {
        lock_guard<mutex> locker(myMutex);
        if (maxSize == taskQueue.size())
        {
            return true;
        }
        return false;
    }

    // 任务队列是否空
    bool isEmpty()
    {
        lock_guard<mutex> locker(myMutex);
        if (taskQueue.empty())
        {
            return true;
        }
        return false;
    }

    int taskSize()
    {
        lock_guard<mutex> locker(myMutex);
        return taskQueue.size();
    }

  private:
    int maxSize = 100;
    queue<int> taskQueue;
    mutex myMutex;
    condition_variable_any full;  // 管理生产者
    condition_variable_any empty; // 管理消费者
};

int main()
{
    thread t1[5];
    thread t2[5];
    TaskQueue taskQ;
    for (int i = 0; i < 5; i++)
    {
        t1[i] = thread(&TaskQueue::put, &taskQ, 100 + i);
        t2[i] = thread(&TaskQueue::take, &taskQ);
    }
    for (int i = 0; i < 5; i++)
    {
        t1[i].join();
        t2[i].join();
    }
    return 0;
}