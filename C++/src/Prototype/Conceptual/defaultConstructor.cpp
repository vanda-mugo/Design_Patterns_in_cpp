/*
When a class has attributes but only a default constructor, and you haven't explicitly provided any 
initialization for the member attributes in the default constructor's initializer list or body,
the member attributes will be left uninitialized if they are of primitive types (like int, double, etc.)
or they will be default-initialized if they are of class types.

Here's an example to illustrate this:
*/

#include <iostream>

class MyClass 
{
public:
    // Default constructor
    MyClass() 
    {
        // No explicit initialization for member attributes
    }

    // Member function to display attribute values
    void displayAttributes() const 
    {
        std::cout << "Attribute1: " << attribute1 << ", Attribute2: " << attribute2 << std::endl;
    }

private:
    int attribute1;
    double attribute2;
};
/*
In this example, the MyClass has a default constructor but doesn't provide any explicit initialization for attribute1 
(of type int) and attribute2 (of type double). When you create an object of MyClass using the default constructor,
the values of these attributes will be unpredictable or have indeterminate values.

If the member attributes were of a class type with its own default constructor, 
that default constructor would be implicitly called for each member attribute, 
and they would be default-initialized according to their own default constructors.

To ensure predictable initial values for member attributes, you should either provide explicit 
initializations in the default constructor's initializer list or set default values directly in 
the class definition (since C++11), as shown in the following example:
*/

class MyClassTwo 
{
public:
    // Default constructor with member attributes initialized
    MyClassTwo() : attribute1(0), attribute2(0.0) 
    {
        // Other initialization if needed
    }

    // Member function to display attribute values
    void displayAttributes() const 
    {
        std::cout << "Attribute1: " << attribute1 << ", Attribute2: " << attribute2 << std::endl;
    }

private:
    int attribute1;
    double attribute2;
};


class MyClassThree 
{
public:
    // Default constructor with member attributes initialized
    MyClassThree()
    {
        // Other initialization if needed
    }

    // Member function to display attribute values
    void displayAttributes() const 
    {
        std::cout << "Attribute1: " << attribute1 << ", Attribute2: " << attribute2 << std::endl;
    }

private:
    int attribute1 = 30;
    double attribute2 = 20.0;
};


int main() 
{
    MyClass obj;
    obj.displayAttributes(); // Outputs unpredictable values for attribute1 and attribute2

    MyClassTwo obj2{};
    obj2.displayAttributes();

    MyClassThree obj3{};
    obj3.displayAttributes();

    return 0;
}

