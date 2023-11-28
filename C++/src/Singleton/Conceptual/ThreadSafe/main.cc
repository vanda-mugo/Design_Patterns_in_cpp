/**
 * Have in mind it is an ilustrative trivial example, in real world
 *     you may have in mind some more possible issues.
 */

#include <iostream>
#include <mutex>
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
     * The Singleton's constructor/destructor should always be private to
     * prevent direct construction/desctruction calls with the `new`/`delete`
     * operator.
     */
private:
    static Singleton * pinstance_;
    static std::mutex mutex_; // an instance of std::mutex it is this instance that will be used to lock and unlock access to shared resources 

protected:
    Singleton(const std::string value): value_(value)
    {
    }
    ~Singleton() {} // protected or private destructors 
    std::string value_;

public:
    /**
     * Singletons should not be cloneable.
     */
    Singleton(Singleton &other) = delete;
    /**
     * Singletons should not be assignable.
     */
    void operator=(const Singleton &) = delete;
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
    
    std::string value() const{
        return value_;
    } 
};

/**
 * Static methods should be defined outside the class.
 */

Singleton* Singleton::pinstance_{nullptr};
std::mutex Singleton::mutex_;

/**
 * The first time we call GetInstance we will lock the storage location
 *      and then we make sure again that the variable is null and then we
 *      set the value. RU:
 */

/*
RAII (Resource Acquisition Is Initialization):

    Using std::lock_guard or std::unique_lock with a mutex follows 
    the RAII principle, ensuring that the lock is released automatically when the lock guard or unique lock goes out of scope.
*/
Singleton *Singleton::GetInstance(const std::string& value)
{
    std::lock_guard<std::mutex> lock(mutex_);
    if (pinstance_ == nullptr)
    {
        pinstance_ = new Singleton(value);
    }
    return pinstance_;
}

void ThreadFoo(){
    // Following code emulates slow initialization.
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    Singleton* singleton = Singleton::GetInstance("FOO");
    std::cout << singleton->value() << "\n";
}

void ThreadBar(){
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
    std::thread t1(ThreadFoo);
    std::thread t2(ThreadBar);
    t1.join();
    t2.join();
    
    return 0;
}

/*
in thread safe singleton, mechanisms are put in place to ensure that only one instance is created even in the presence of multiple 
threads. this typically involves using syncronization techniques to controll access to the critical section of the code where the 
instace is created 
*/

/*
std::mutex is a C++ Standard Library class that provides a mechanism for mutual exclusion, enabling safe concurrent access 
to shared resources in a multithreaded environment. The term "mutex" stands for "mutual exclusion," which is the key concept behind its usage.
basic characteristics and usage of the 'std::mutex'

1. Header File:

    The std::mutex class is defined in the <mutex> header.

    #include <mutex>

2. creation 
    to use a mutex, you create an instance of 'std::mutex' this instance will be used to lock and unlock access to shared resources

    std::mutex myMutex;

3. locking
    you use the 'lock' member function of the 'std::mutex' to acquire a lock on the mutex. if the mutex is not available teh calling thread will
    be blocked until it can obtain the lock 

    myMutex.lock();
    // Critical section (shared resource access)
    myMutex.unlock();

    alternatively you can use the 'std::unique_lock' to automatically manage the locking and unlocking of a mutex

    std::unique_lock<std::mutex> lock(myMutex);
    //critical section < shared resource >

4: unlocking 
    the unlock member function is used to remove the lock from the mutex

5. scoping 
     the mutex is used to protect a critical section of code where shared resources are accessed . the scope of the mutex should be 
     limited to the critical section 

     std::unique_lock<std::mutex> lock(myMutex);
     myCondition.wait(lock)// wait for the condition to be satisfied 

*/


/*
Multithreading is a programming concept that involves the simultaneous execution of multiple threads (smaller units of a process or program) 
within the same program or process. Each thread runs independently, and they share the same resources, such as memory space and file handles, 
within the process. Multithreading is commonly used to improve the overall performance and responsiveness of applications by parallelizing tasks.

std::mutex and associated classes in the <mutex> header are essential tools for managing concurrent access to shared resources and ensuring thread safety. 
They play a crucial role in preventing race conditions and ensuring that multiple threads can safely access and modify shared data.
*/


/*
If you see the same value, then singleton was reused (yay!
If you see different values, then 2 singletons were created (booo!!)

RESULT:
FOO
BAR*/

/*

Explanation:

    Static Members:
        pinstance_: A static pointer to the Singleton instance. It is initially set to nullptr.
        mutex_: A static mutex used for thread safety.

    Private Constructor and Destructor:
        The constructor is private to prevent external instantiation.
        The destructor is private to prevent external deletion.

    Private Copy Constructor and Assignment Operator:
        The copy constructor and assignment operator are private to prevent the creation of additional instances through copying.

    Private Member:
        value_: A private member to store the value associated with the Singleton.

    GetInstance Method:
        Singleton* GetInstance(const std::string& value): A public static method that implements the Singleton pattern.
        It uses a std::lock_guard to ensure thread safety by locking the mutex during the creation of the Singleton instance.
        If pinstance_ is nullptr, it creates a new instance of Singleton with the provided value.
        It returns the Singleton instance.

    Usage:
        Clients can get the Singleton instance and access its value using the GetInstance method and other public methods.


        
*/