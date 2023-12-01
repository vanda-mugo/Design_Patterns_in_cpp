/*
this is just another example to test the understanding of the singleton Thread safe approach 
*/

#include <thread>
#include <mutex>
#include <iostream>

class Singleton
{
private:
    static Singleton* m_instance;
    static std::mutex m_mutex;
    std::string m_string;

    // private constructors 
    Singleton(const std::string stringVal): m_string(stringVal)
    {
        std::cout << "Overloaded constructor called " << std::endl;
    }
    ~Singleton(){}
public:
    // negate the copy and operator equal constructor and funtion 
    Singleton(const Singleton&) = delete;
    void operator=(const Singleton&) = delete;

    // get instance method 
    static Singleton* getInstance(std::string strVal)
    {
        std::lock_guard<std::mutex> lock(m_mutex);
        // you can also use 
        /*
        std::lock_guard<std::mutex> name(initialisation)
        */
        if(m_instance == nullptr)
        {
            m_instance = new Singleton(strVal);
        }

        return m_instance;
    }
    void value() const 
    {
        std::cout << "string value " << m_string << std::endl;
    }
};

// to initialise the static class variables 
Singleton* Singleton::m_instance{nullptr};
std::mutex Singleton::m_mutex;

// definition of the function that introduce different threads 
void threadFoo()
{
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    Singleton* singletonObject = Singleton::getInstance("Foo");
    singletonObject->value();
}

void threadBar()
{
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    Singleton* singletonObject =  Singleton::getInstance("Bar");
    singletonObject->value();
}

int main()
{
    // to create two threads
    std::thread t1(threadFoo);
    std::thread t2(threadBar);
    t1.join();
    t2.join();
    return 0;
}
