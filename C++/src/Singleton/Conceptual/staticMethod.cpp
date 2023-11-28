/*
In C++, a static method is a member function of a class that is associated with the class rather than an instance 
of the class. It can be called on the class itself, rather than on an object of that class.
Here are some key points about static methods in C++:

    Belongs to the Class, Not to an Instance:
        A static method is associated with the class, not with instances of the class. 
        It can be called using the class name rather than an object of the class.

    No Access to Instance-Specific Data:
        Static methods cannot access non-static (instance) members or data of the class directly. 
        They operate on the class level and don't have access to this pointer.

    No this Pointer:
        Since static methods are not associated with a specific instance, they don't have a this pointer. 
        This means they can't access instance-specific data or call non-static methods directly.

    Common Use Cases:
        Static methods are often used for utility functions that don't depend on an instance's state, 
        such as mathematical calculations, factory methods, or helper functions.

    Declared with the static Keyword:
        To declare a method as static, the static keyword is used in the method declaration.
*/

#include <iostream>

class MathOperations 
{
public:
    // Static method to add two numbers
    static int add(int a, int b) 
    {
        return a + b;
    }

    // Non-static method (instance method)
    void displayMessage() 
    {
        std::cout << "This is an instance method." << std::endl;
    }
};

int main() 
{
    // Calling the static method without creating an instance
    int result = MathOperations::add(5, 3);
    std::cout << "Result of addition: " << result << std::endl;

    // Creating an instance to call a non-static method
    MathOperations obj;
    obj.displayMessage();

    return 0;
}

/*

The add method is declared as a static method using the static keyword. 
It can be called using the class name MathOperations::add.

The displayMessage method is a non-static (instance) method and requires an instance of the class to be called.
*/
