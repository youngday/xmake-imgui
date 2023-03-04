
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

 int items[] = { 1, 2, 3, 4, 5 };
  

        for (int i = 0; i != 100; ++i) {
            std::this_thread::sleep_for(std::chrono::milliseconds(i % 10));
              q.enqueue_bulk(items, 5);
        } });
    std::thread consumer([&]()
                         {
        int items[] = { 1, 2, 3, 4, 5 };

        for (int i = 0; i != 100; ++i) {
            int results[5]; // Could also be any iterator
    size_t count = q.try_dequeue_bulk(results, 5);
    for (size_t i = 0; i != count; ++i)
    {
        assert(results[i] == items[i]);
    }
            
           
        } });
    producer.join();
    consumer.join();

 
    cout << "end" << endl;
    return 0;
}
