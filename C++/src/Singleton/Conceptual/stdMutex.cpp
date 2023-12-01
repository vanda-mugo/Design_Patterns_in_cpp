/*
std::mutex is a C++ Standard Library class that provides a synchronization primitive for 
managing access to shared resources in a multithreaded environment. The term "mutex" stands for 
"mutual exclusion," and the primary purpose of a mutex is to protect shared data from being simultaneously 
accessed or modified by multiple threads. Using a mutex helps avoid race conditions and ensures thread safety.
*/

// header file for the std::mutex class 
#include <mutex>
#include <iostream>
#include <thread>
// creation of the Mutex object
// lets implement a singleton using the same

class Singleton
{
// private variables 
private:
    static Singleton* m_Instance ;
    std::string m_string;
    static std::mutex m_Mutex; // to use a mutex, you create an instance of 'std::mutex'. this instance will be used to lock
    // and unlock the access to shared resources 

    // private constructor and destructor 
    Singleton(std::string stringVal) :m_string(stringVal)
    {
        std::cout << " just to show the constructor is accessed only once per " << std::endl;
    } 
    ~Singleton() {
        std::cout << " destructor called " << std::endl;
    }

    // private copy constructor and operator overloading 
    Singleton(const Singleton & source) = delete;
    void operator=(const Singleton & source) = delete;

public:

    //static get instance method
    static Singleton* getInstance(std::string stringVal)
    {
        std::unique_lock<std::mutex> lock(m_Mutex);
        if(!m_Instance)
        {
            m_Instance = new Singleton(stringVal);
        }
        return m_Instance;
    }

    void value()
    {
        std::cout << " the string is " << m_string << std::endl;
    }


};
/*
intializing static member variables such as Singleton Singleton::m_Instance and std::mutex Singleton::m_Mutex
is necessary to ensure that they have well defined initial values when program starts executing .

Static members are typically initialized outside the class definition to avoid potential issues related to 
order of initialization in the presence of multiple translation units (source files).
The initialization order of static variables across translation units is not guaranteed, 
and using the static members inside their own class for initialization may lead to undefined behavior.

Initializing the static members outside the class definition ensures that they are initialized before 
any code is executed, providing a reliable and consistent starting state for the program.
*/

Singleton* Singleton::m_Instance{nullptr};
std::mutex Singleton::m_Mutex;

void ThreadFoo()
{
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    // remember you can call a static method using the class name 
    Singleton * instanceFoo = Singleton::getInstance("FOO");
    instanceFoo->value();

}

void ThreadBar()
{
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    Singleton * instanceBar = Singleton::getInstance("Bar");
    instanceBar->value();
}


int main()
{
    std::thread t1(ThreadFoo);
    std::thread t2(ThreadBar);

    t1.join();
    t2.join();
    return 0;

}

/*
just to show the constructor is accessed only once per 
 the string is Bar
 the string is Bar
*/