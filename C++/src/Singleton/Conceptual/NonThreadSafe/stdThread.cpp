/*
std::thread is a class in the C++ Standard Library that represents a thread of execution. 
It provides a way to create and manage concurrent threads in a C++ program. 
The <thread> header file is needed to use this class.

Here's a basic overview of std::thread:*/

// you can create a thread by passing a function (or a callable object) to the 'std::thread' constructor
// the function will executed in a separate thread .the thread starts running immediately after its created

#include <iostream>
#include <thread>

void myFunction() 
{
    std::cout << "Hello from thread!" << std::endl;
}

int main() 
{
    std::thread myThread(myFunction);

    // Do other work in the main thread

    myThread.join();  // Wait for the thread to finish

    return 0;
}

/*

A thread is the smallest unit of execution in a concurrent programming environment. It represents an independent flow of control within a program. 
Threads share the same process resources, including memory space and file descriptors, but each thread has its own program counter, register set, 
and stack.

Here are key characteristics and concepts associated with threads:

    Concurrency:
        Threads enable concurrent execution, allowing multiple tasks to run simultaneously within a single program.

    Lightweight:
        Threads are often considered lightweight compared to processes because they share resources, making their creation and context switching faster.

    Independence:
        Each thread has its own program counter, which means it can execute different parts of the program independently of other threads.

    Parallelism:
        Threads can run in parallel on multiprocessor systems, potentially improving overall program performance.

    Shared Resources:
        Threads within the same process share the same memory space, allowing them to communicate and share data more easily than separate processes.

    Creation:
        Threads can be created within a process using thread creation mechanisms provided by the operating system or programming language.

    Scheduling:
        Thread scheduling is handled by the operating system or a threading library. The scheduler determines which thread to execute at a given time.

    Communication:
        Threads within the same process can communicate through shared memory or other inter-thread communication mechanisms. However,
         care must be taken to synchronize access to shared data to avoid race conditions.

    Lifetime:
        Threads have a lifecycle that includes creation, execution, and termination. 
        The termination of the main thread often leads to the termination of the entire process.

    Concurrency Issues:
        Concurrency introduces challenges such as race conditions, deadlocks, and synchronization issues. 
        Proper synchronization mechanisms, like mutexes and semaphores, are used to manage access to shared resources.

    Thread Safety:
        Thread safety is a concept ensuring that a program behaves correctly when multiple threads are executing concurrently. 
        Proper design and synchronization are essential for achieving thread safety.

Threads are a fundamental concept in concurrent programming and are widely used to implement parallelism, responsiveness, 
and efficient resource utilization in modern software systems. They are crucial for tasks such as handling user interfaces, 
network communication, and parallel processing.
*/
