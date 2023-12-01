/*
ADAPTER
Adapter : A structural design pattern that allows objects with incompatible interfaces to collaborate

Structure

Object adapter 

This implementation uses the object composition principle : the  adapter implements the interface of one object 
wraps the other one .

there are two types of adapters that is the class adapter and object adapter


*/

#include <iostream>

// Adaptee (the existing class with a different interface)
class Adaptee 
{
public:
    void specificRequest() 
    {
        std::cout << "Adaptee's specificRequest called." << std::endl;
    }
};

// Target (the desired interface)
class Target 
{
public:
    virtual void request() = 0;
};

// Adapter (class adapter)
//  so note that typically what this class does is that it inherits from the existing class Adaptee and implements
// the target interface 
class Adapter : public Adaptee, public Target 
{
public:
    void request() override 
    {
        specificRequest();
    }
};

int main() {
    // Client code using the Target interface
    Target* target = new Adapter();
    target->request();

    delete target;

    return 0;
}


// class adaptee pattern 
/*
Class Adapter Pattern 
the adapter class inheirts from the existing class (Adaptee) and implements the target interface

multiple inheritance 
multiple inheritance where a class directly inherits from two or more classes , however this is not the 
primary mechanism used in the class adapter pattern 

*/