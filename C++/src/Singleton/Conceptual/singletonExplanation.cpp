/*

the singleton design pattern is a creational design pattern that ensures a class has only one instance and provides
a global  point of access to that instance, in other words, it restricts the instantiation of a class to a single 
instance and provides a way to access that instance from any point in the application

this is useful in scenarios where only one object is needed to coordinate action across the system, such as 
configuration manager, a logging service or a connection pool */

// implementation of singleton 
#include <iostream>

class Singleton
{
private:
    static Singleton* instance; // private static member variable 'instance' that holds a reference to the single 
    // instance instance of the class
    Singleton() {} // private constructor to prevent direct instantiation from outside the class 
    Singleton(const Singleton& ) = delete; // its good practice to declare the copy constructor as private or by
    /*
    deleting it which prevents unintentional creation of additional instances through copy constructor 
    by doing so you ensure that the singleton remains a single instance throughout the lifetime of the program
    */
   ~Singleton(){}

public:

static Singleton* getInstance() // note by that static functions operate on a class level and dont have access to 'this' pointer 
{
    if(!instance)
    {
        instance = new Singleton();
    }
    return instance;
}
/* the get instance method is a public method that ensures only one instance is created and returns this instance 
This example demonstrates that singletonInstance1 and singletonInstance2 are indeed the same instance, as expected 
from a Singleton.
*/

void showMessage()
{
    std::cout << " hello I am singleton " << std::endl;
}

};
// initialise the static instance pointer to nullptr
Singleton* Singleton::instance = nullptr;

int main()
{
    Singleton* singletonInstance1 = Singleton::getInstance(); // note that the getInstance is a static method 
    Singleton* singletonInstance2 = Singleton::getInstance();

    // note that in this case both of this are pointers to the same instance object created and returned with the 
    // get instance method 

    std::cout << " singletonInstance1 " << singletonInstance1 << " singletonInstance2 " << singletonInstance2 << std::endl;
    singletonInstance1->showMessage();
    return 0;
}

// output 
// This example demonstrates that singletonInstance1 and singletonInstance2 are indeed the same instance, as expected from a Singleton.
// singletonInstance1 0x2ada37c17f0 singletonInstance2 0x2ada37c17f0


