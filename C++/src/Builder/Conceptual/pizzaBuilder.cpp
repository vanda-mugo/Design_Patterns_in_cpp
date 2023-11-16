#include <iostream>
#include <string>

// product class 

/*
in this example the Pizza class is the product class that represents the complex object to be created 
Pizza Builder is the abstract interface that declares the steps necessary to build the product 
the margheritaPizzaBuilder and the  TikkaPizzaBuilder are the concrete classes that implement the pizzaBuilder interface specifying the construction process steps 
for each one of them separately 
Pizza direactor is responsible for constructing different types of pizzas by creating new builder classes without modifying the client code 

This pattern allows flexibility in constructing different types of pizzas by creating new builder classes without modifying the client code.\
*/
class Pizza 
{
public:
    void setDough(const std::string & dough)
    {
        m_dough = dough;
    }
    void setSauce(const std::string & sauce)
    {
        m_sause = sauce;
    }
    void setTopping(const std::string & topping)
    {
        m_topping = topping;
    }
    std::string displayPizza() 
    {
        std::string pizza{" Pizza with " + m_dough + " dough " + m_sause + " sauce " + m_topping + " topping " };
        return pizza;
    }
private:
    std::string m_dough;
    std::string m_sause;
    std::string m_topping;

};

//Abstract Builder class 
class PizzaBuilder
{
public:
    virtual void buildDough() = 0;
    virtual void buildSauce() = 0;
    virtual void buildTopping() = 0;
    virtual Pizza getResult() = 0; // this is a getResult method that returns Pizza object 

};

// Abstract classes that implements the Abstract PizzaBuilder interface 
class MargheritaPizzaBuilder : public PizzaBuilder
{
public:
    void buildDough() override
    {
        m_pizza.setDough(" thin crust ");
    }

    void buildSauce() override
    {
        m_pizza.setSauce(" tomato sauce ");
    }
    void buildTopping() override
    {
        m_pizza.setTopping(" mozzarella cheese ");
    }
    Pizza getResult() override
    {
        return m_pizza;
    }
private:
    Pizza m_pizza;
};

class TikkaPizzaBuilder : public PizzaBuilder
{
public:
    void buildDough() override
    {
        m_pizza.setDough(" Tikka Dough ");
    }
    void buildSauce() override
    {
        m_pizza.setSauce(" Chicken Sauce ");
    }
    void buildTopping() override
    {
        m_pizza.setTopping(" Max cheese with Mozzarrella ");
    }
    Pizza getResult() override
    {
        return m_pizza;
    }
private:
    Pizza m_pizza;
};

// director class
class PizzaDirector 
{
public:
    Pizza constructPizza( PizzaBuilder & builder)
    {
        builder.buildDough();
        builder.buildSauce();
        builder.buildTopping();

        return builder.getResult();
    }
};


int main()
{
    TikkaPizzaBuilder tikkaBuilder;
    PizzaDirector director;
    Pizza tikka = director.constructPizza(tikkaBuilder);
    std::cout << tikka.displayPizza() << std::endl;

    MargheritaPizzaBuilder margheritaPizza;
    PizzaDirector margheritaDirector;
    Pizza margherita = margheritaDirector.constructPizza(margheritaPizza);
    std::cout << margherita.displayPizza() << std::endl;
}

/*
Example: Builder Design Pattern in C++
1. Object-Oriented Principles:

    Encapsulation: The Pizza class encapsulates the details of its internal representation, such as dough, sauce, and toppings.

    Abstraction: The PizzaBuilder class provides an abstraction for building pizzas, defining the steps without specifying how they are implemented in concrete builders.

    Inheritance: The MargheritaPizzaBuilder inherits from the abstract PizzaBuilder class, ensuring that it implements the required building steps.

    Polymorphism: The PizzaDirector class can work with any class derived from PizzaBuilder, demonstrating polymorphic behavior.
*/