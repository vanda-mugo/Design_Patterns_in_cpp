/*
Let’s look at some animal examples. Most Animals can make
sounds. We can anticipate that all subclasses will need to override
the base makeSound method so each subclass can emit
the correct sound; therefore we can declare it abstract right
away. This lets us omit any default implementation of the
method in the superclass, but force all subclasses to come up
with their own.
*/

/*
this enables us to create different objects without knowing the concrete
type of the object inside the a variable, because of polymorphism the 
program can trace down the subclass of the object whose method is being 
executed and run the appropriate behaviour as per the concrete class of 
the said object */


/*

bag = [new Cat(), new Dog()];

 foreach (Animal a : bag)
 a.makeSound()

 // Meow!
 // Woof!

we can say polymorphism is the ability of a program to detect the real class
of an objecvt and call its implementation even when the real type of the 
object is unknown in the current context

You can also think of polymorphism as the ability of an object
to “pretend” to be something else, usually a class it extends or
an interface it implements. In our example, the dogs and cats
in the bag were pretending to be generic animals.
 */

//note by that the Polymorphism is a pillar of OOP which are 4 
/*
polymorphism 
abstraction 
inheritance 
encapsulation 
*/


/*
basically polymorphism in OOP refers to ability by which different classes 
can be treated as objects of the same common base class . there are two types
of polymorphism in c++ which are 

compile time or static polymorphism 
run time or dynamic polymorphism */

// example of run time polymorphism usingh virtual functions 

#include <iostream>

// Base class
class Shape 
{
public:
    // Virtual function for calculating area
    // this is a const method therefore doesnt affect the this parameter 
    virtual float calculateArea() const 
    {
        return 0.0;
    }
    virtual ~Shape(){
        std::cout << " destructor for the base class has been called "<< std::endl;
    }
};

// Derived class 1: Circle
// public specifier inheritance from the Shape class 
class Circle : public Shape 
{
private:
    float radius;

public:
//public overloaded contructor that takes an arg or type float to be used with the calculateArea method that is an override of base Shape 
    Circle(float r) : radius(r)
    {}

    // Override the virtual function to calculate the area of a circle
    float calculateArea() const override 
    {
        return 3.14 * radius * radius;
    }

    ~Circle()
    {
        std::cout << "destructor for the Cicle class has been called " << std::endl;
    }
};

// Derived class 2: Rectangle
class Rectangle : public Shape {
private:

    float length;
    float width;

public:
    Rectangle(float l, float w) : length(l), width(w) 
    {}

    // Override the virtual function to calculate the area of a rectangle
    float calculateArea() const override 
    {
        return length * width;
    }

    ~Rectangle()
    {
        std::cout << "destructor for the Rectangle class has been called " << std::endl;
    }
};

int main() {
    // Create objects of different classes
    Circle circle(5.0);
    Rectangle rectangle(4.0, 6.0);

    // Create an array of Shape pointers
    // note that teh 
    Shape* shapes[] = { &circle, &rectangle };

    // Calculate and display the area of each shape using polymorphism
    for (const auto shape : shapes)
    {
        std::cout << "Area: " << shape->calculateArea() << std::endl;
    }

    // for(auto shape: shapes)
    // {
    //     delete shape;
    // }

    return 0;
}


//output 
/*
Area: 78.5
Area: 24

We have a base class Shape with a virtual function calculateArea().
There are two derived classes, Circle and Rectangle, each overriding the calculateArea() function.

    In the main() function, we create objects of the derived classes and store them in an array of pointers to the base class (Shape*).
    Through polymorphism, we can use a loop to iterate over the array of Shape pointers and call the calculateArea() function for each shape, which dynamically resolves to the appropriate derived class's implementation based on the actual object type.

This is an example of runtime polymorphism because the decision about which function to call is made at runtime based on the actual type of the object being pointed to.

*/