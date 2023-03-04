
#include <thread>
#include<chrono>
#include<iostream>
#include "concurrentqueue/blockingconcurrentqueue.h"
using namespace std;


int main()
{
    moodycamel::BlockingConcurrentQueue<int> q;

    std::thread producer([&]()
                         {
        for (int i = 0; i != 100; ++i) {
            std::this_thread::sleep_for(std::chrono::milliseconds(i % 10));
            q.enqueue(i);
        } });
    std::thread consumer([&]()
                         {
        for (int i = 0; i != 100; ++i) {
            int item;
             q.wait_dequeue(item);//one for wait without timeout
             assert(item == i);
            
            if (q.wait_dequeue_timed(item, std::chrono::milliseconds(5))) {//other for wait with timeout
                ++i;
                assert(item == i);
            }
        } });
    producer.join();
    consumer.join();

    assert(q.size_approx() == 0);
    cout<<"end"<<endl;
    return 0;
}
