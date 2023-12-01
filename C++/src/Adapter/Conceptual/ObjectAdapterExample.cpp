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

// Adapter (object adapter)
class Adapter : public Target 
{
private:
    Adaptee* adaptee{nullptr};

public:
// overloaded constructor 
// in this case I believe the pointer to the adaptee is initialised in the constructor
    Adapter(Adaptee* adaptee) : adaptee(adaptee) 
    {}

    void request() override 
    {
        if(adaptee)
        {
            adaptee->specificRequest();
        }
        else
        {
            std::cout << " Initialise the Adapter object this* with an Adaptee object in initialisation " << std::cout;
        }
    }
};

int main() 
{
    // Client code using the Target interface
    Adaptee* adaptee = new Adaptee();
    Target* target = new Adapter(adaptee);
    target->request();

    delete target;
    delete adaptee;

    return 0;
}
