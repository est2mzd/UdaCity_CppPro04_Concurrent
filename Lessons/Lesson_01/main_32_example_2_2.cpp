#include <iostream>
#include <thread>
#include <chrono>
#include <random>
#include <vector>

int main()
{
    // create threads
    std::vector<std::thread> threads;

    for (size_t i=0; i < 10; i++)
    {
        //
        auto f = [i](){
                // wati for certain amount of time
                std::this_thread::sleep_for(std::chrono::milliseconds(10*(i+1)));

                // perform work
                std::cout << "Hello from Worker thread #" << i << std::endl;
        };

        // create new thread from a Lambda
        threads.emplace_back(f);
    }

    // do something in main()
    std::cout << "Hellow from Main thread" << std::endl;

    // call join on all thread objects using a range-based loop
    for (auto &t: threads){t.join();}

    return 0;
}