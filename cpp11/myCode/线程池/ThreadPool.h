#pragma once
#include <atomic>
#include <condition_variable>
#include <functional>
#include <future>
#include <map>
#include <mutex>
#include <queue>
#include <thread>
#include <vector>
using namespace std;

/**
 * @brief 线程池类，用于管理一组工作线程并执行异步任务
 *
 * 该类实现了线程池模式，可以动态调整线程数量，在最小和最大线程数之间变化
 * 通过任务队列管理待执行任务，工作线程从队列中获取任务执行
 */

class ThreadPool
{
  public:
    /**
     * @brief 构造函数
     * @param min 线程池最小线程数，默认为4
     * @param max 线程池最大线程数，默认为硬件支持的并发线程数
     */
    ThreadPool(int min = 4, int max = thread::hardware_concurrency());

    /**
     * @brief 析构函数，停止所有线程并清理资源
     */
    ~ThreadPool();

    /**
     * @brief 添加任务到线程池
     * @param f 要执行的任务函数，类型为function<void()>
     */
    void addTask(function<void()> f);

  private:
    /**
     * @brief 管理线程函数，负责动态调整线程数量
     *
     * 定期检查任务队列和工作线程状态，根据需要创建或销毁线程
     */
    void manager();

    /**
     * @brief 工作线程函数，负责从任务队列获取并执行任务
     */
    void worker();

  private:
    thread *m_manager;                 ///< 管理线程指针
    map<thread::id, thread> m_workers; ///< 工作线程map，key为线程ID，value为线程对象
    vector<thread::id> m_ids;          ///< 工作线程ID列表
    int m_minThreads;                  ///< 线程池最小线程数
    int m_maxThreads;                  ///< 线程池最大线程数
    atomic<bool> m_stop;               ///< 线程池停止标志
    atomic<int> m_curThreads;          ///< 当前线程数量
    atomic<int> m_idleThreads;         ///< 空闲线程数量
    atomic<int> m_exitNumber;          ///< 需要退出的线程数量
    queue<function<void()>> m_tasks;   ///< 任务队列
    mutex m_idsMutex;                  ///< 保护线程ID列表的互斥量
    mutex m_queueMutex;                ///< 保护任务队列的互斥量
    condition_variable m_condition;    ///< 条件变量，用于线程间同步
};
