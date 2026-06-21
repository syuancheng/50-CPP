#include <cassert>
#include <condition_variable>
#include <mutex>
#include <queue>
#include <thread>

class WorkQueue {
public:
    void push(int value) {
        {
            std::lock_guard<std::mutex> lock(mutex_);
            values_.push(value);
        }
        ready_.notify_one();
    }

    int wait_and_pop() {
        std::unique_lock<std::mutex> lock(mutex_);
        ready_.wait(lock, [this] { return !values_.empty(); });
        const int value = values_.front();
        values_.pop();
        return value;
    }

private:
    std::mutex mutex_;
    std::condition_variable ready_;
    std::queue<int> values_;
};

int main() {
    WorkQueue queue;
    int result = 0;

    std::thread consumer([&] { result = queue.wait_and_pop(); });
    queue.push(42);
    consumer.join();

    assert(result == 42);
}
