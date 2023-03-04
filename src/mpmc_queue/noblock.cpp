
#include <thread>
#include <chrono>
#include <iostream>
#include "concurrentqueue/blockingconcurrentqueue.h"
using namespace std;

int main()
{
    moodycamel::ConcurrentQueue<int> q;

    std::thread producer([&]()
                         {
        for (int i = 0; i != 100; ++i) {
            std::this_thread::sleep_for(std::chrono::milliseconds(i % 10));
            q.enqueue(i);
        } });
    producer.join();
    std::thread consumer([&]()
                         {
        for (int i = 0; i != 100; ++i) {
            int item;
            q.try_dequeue(item);
            assert(item == i);
            
          
        } });

    consumer.join();

    assert(q.size_approx() == 0);
    cout << "end" << endl;
    return 0;
}
