#pragma once

#include <functional>
#include <vector>
#include <thread>


class ThreadPool 
{
public:
    using Task = std::function<void()>;

    // If count equal to zero, ThreadPool automatically
    // determines count of hardware threads
    ThreadPool(size_t count=0);

    void Submit(Task task);

    void Wait();
    void WaitAndStop();
    void Stop();

private:
    std::vector<std::thread> m_workers;
};
