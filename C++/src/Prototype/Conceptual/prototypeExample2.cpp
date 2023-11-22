/*
*The Prototype Design Pattern is a creational design pattern that 
is used to create objects by copying an existing object, 
known as the prototype. 
Instead of creating a new object from scratch, 
the pattern involves cloning an existing object and then customizing 
it as needed. 
This approach can be particularly useful when the cost of creating an 
object is more expensive or complex than copying an existing one.

*/

/*

// it involves the following 
i. prototype interface : this is an interface or abstract class that declares 
the method for cloning itself . this interface may involve a method like 
 clone()
 
 ii. concrete prototype which implements the prototype interface. these 
 classes override the clone() method to provide a concrete implementation 
 of the cloning process 
 
 iii. client which is responsible for creating new objects by requesting the
 cloning of an existing prototype
 
 an example follows ahead
 */

#include <iostream>
#include <string>

// prototype interface
class Animal
{
public:
    virtual Animal* clone() const = 0;
    virtual void makeSound() const = 0;
    virtual ~Animal()
    {}

};

// to make classes that implement this interface 
class Dog : public Animal
{
public:
    Animal* clone() const override
    {
        return new Dog(*this);
    }
    
    void makeSound() const override
    {
        std::cout << "Woof ! woof !" << std::endl;
    }

};

class Cat : public Animal
{
    Animal* clone() const override
    {
        return new Cat(*this);
    }
    // so note that we are passing the *this which in this case is a dereferenced pointer 
    /*
    the purpose of clone method is to produce a copy of the existing object, and creating a new instance is a fundamental part of the process
    
    so lets take a close look at the 'clone' method 

    Animal* clone() const override 
    {
        return new Cat(*this);
    }

    In C++, the this pointer represents a pointer to the object for which a member function is called. In the context of a copy constructor,
    the this pointer refers to the object being copied. The copy constructor is a special member function used to create a new object as a copy 
    of an existing object. When the copy constructor is invoked, the this pointer points to the object being copied.

    here the new Cat(*this) is calling the copy constructor of the Cat class to create a new instance of the Cat. the *this part is a reference 
    to the current instance of Cat object with which the method has been called and its used to initialise based on the current state of the 
    existing object.

    1. Initialization: When you create a new object, its initial state needs to be set. The copy constructor is responsible for initializing 
    the new object's state based on the existing object's state. This ensures that the cloned object is an independent copy of the original.

    2. Polymorphism: The clone method is declared in the base class (Animal), and it returns a pointer to the base class (Animal). However,
    the actual type of the object being cloned is a derived class (Dog). By calling the copy constructor of the derived class (Dog),
    you ensure that the correct type of object is created and that polymorphism is preserved.

    3. Deep Copy: Depending on the complexity of the object and its components, a deep copy may be required to ensure that all the 
    internal state of the object is duplicated. The copy constructor is responsible for performing a deep copy if needed.


    */

    void makeSound() const override
    {
        std::cout << "meow ! meow !" << std::endl;
    };
};

// step three client 
int main()
{
    Animal * originalDog = new Dog();
    Animal * clonedDog = originalDog->clone();

    Animal* originalCat = new Cat();
    Animal* clonedCat = originalCat->clone();
    // in the case here this will refer to the originalCat object that is being created

    originalDog->makeSound();
    clonedDog->makeSound();

    originalCat->makeSound();
    clonedCat->makeSound();

    delete originalDog;
    delete clonedDog;
    delete originalCat;
    delete clonedCat;

    return 0;
}

/*
In this example, Animal is the prototype interface,
 and Dog and Cat are concrete prototypes. 
 The client (main function) creates and clones instances of 
 Dog and Cat objects, demonstrating the use of the 
 Prototype Design Pattern.

Remember to handle memory management appropriately,
 such as deleting the cloned objects when they are no longer needed.

This pattern is particularly useful in scenarios where the cost 
of creating a new object is more expensive than copying an existing one,
 and it helps in keeping the system independent of the classes of
  the objects it needs to instantiate.
*/