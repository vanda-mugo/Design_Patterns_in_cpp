#include <iostream>
#include <string>
#include <thread>

/**
 * Singleton Design Pattern
 *
 * Intent: Lets you ensure that a class has only one instance, while providing a
 * global access point to this instance.
 */
/**
 * The Singleton class defines the `GetInstance` method that serves as an
 * alternative to constructor and lets clients access the same instance of this
 * class over and over.
 */
class Singleton
{

    /**
     * The Singleton's constructor should always be private to prevent direct
     * construction calls with the `new` operator.
     */

protected:
    Singleton(const std::string value): value_(value)
    {
        // overloaded constructor that is protected 
    }

    static Singleton* singleton_;

    std::string value_;

public:

    /**
     * Singletons should not be cloneable.
     */
    Singleton(Singleton &other) = delete;
    /**
     * Singletons should not be assignable.
     */
    void operator=(const Singleton &) = delete; // keeps the singleton from being assignable 
    /**
     * This is the static method that controls the access to the singleton
     * instance. On the first run, it creates a singleton object and places it
     * into the static field. On subsequent runs, it returns the client existing
     * object stored in the static field.
     */

    static Singleton *GetInstance(const std::string& value);
    /**
     * Finally, any singleton should define some business logic, which can be
     * executed on its instance.
     */
    void SomeBusinessLogic()
    {
        // ...
    }

    std::string value() const
    {
        return value_;
    } 
};

Singleton* Singleton::singleton_= nullptr;;

/**
 * Static methods should be defined outside the class.
 */
Singleton * Singleton::GetInstance(const std::string& value)
{
    /**
     * This is a safer way to create an instance. instance = new Singleton is
     * dangeruous in case two instance threads wants to access at the same time
     */
    if(singleton_==nullptr){
        singleton_ = new Singleton(value);
    }
    return singleton_;
}

void ThreadFoo()
{
    // Following code emulates slow initialization.
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));// pauses for 1 sec 
    Singleton* singleton = Singleton::GetInstance("FOO");
    std::cout << singleton->value() << "\n";
}

void ThreadBar()
{
    // Following code emulates slow initialization.
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    Singleton* singleton = Singleton::GetInstance("BAR");
    std::cout << singleton->value() << "\n";
}


int main()
{
    std::cout <<"If you see the same value, then singleton was reused (yay!\n" <<
                "If you see different values, then 2 singletons were created (booo!!)\n\n" <<
                "RESULT:\n";   
    std::thread t1(ThreadFoo); // in this case you are creating a thread and calling this function ThreadFoo within this said thread 
    std::thread t2(ThreadBar);
    t1.join();// want the main thread to wait for the completion of the thread 
    t2.join();

    return 0;
}


/*
non thread safe the implementation does not take into account the possibility of multiple threads trying to create an instance of the class 
simultaneously, as a result of this two or more threads attempt to create an istance at the same time which could lead to creation of 
multiple instances violating the singleton design pattern
*/

/*
std::this_thread::sleep_for()
this basically blocks the execution of the current thread for at least the specified sleep duration .
basically it pauses the execution of the current thread in c++ for a specified duration of time 

std::this_thread::sleep_for : this is a function in the c++ standard library. 
std::this_thread provides facilities to work with threads, the sleep_for function is used for introducing 
a delay in the execution of the current thread 

std::chrono::milliseconds(1000) is involved creating a duration object representing a time interval 
of 1000 milliseconds . the std::chrono provides utilities for time related operations 
*/

/*
std::thread is a class in the C++ Standard Library that represents a thread of execution. 
It provides a way to create and manage concurrent threads in a C++ program. 
The <thread> header file is needed to use this class.


Here's a basic overview of std::thread:*/


/*
If you see the same value, then singleton was reused (yay!
If you see different values, then 2 singletons were created (booo!!)

RESULT:
FOO
BAR

which clearly shows that there are two different instances cause of the non thread safe approach */