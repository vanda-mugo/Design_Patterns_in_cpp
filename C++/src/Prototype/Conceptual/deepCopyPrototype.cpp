
/*
In scenarios where the instance of a class being copied contains a raw pointer to dynamically allocated memory,
a deep copy is essential to ensure that the copied object has its own distinct copy of the dynamically allocated 
memory rather than just copying the pointer. The Prototype Design Pattern is well-suited for such situations. Here's an example:
*/

#include <iostream>
#include <string>

// Prototype Interface
class Animal 
{
public:
    virtual Animal* clone() const = 0;
    virtual void makeSound() const = 0;
    virtual ~Animal() = default;
};

// Concrete Prototype
class Dog : public Animal 
{
private:
    std::string* sound;

public:
    Dog(const std::string& s) 
    : sound(new std::string(s)) 
    {}

    // Deep copy constructor
    Dog(const Dog& other) 
    : sound(new std::string(*(other.sound))) 
    {}

    Animal* clone() const override 
    {
        return new Dog(*this);
    }

    void makeSound() const override 
    {
        std::cout << "Dog says: " << *sound << std::endl;
        std::cout << " adress of member that is sound " << sound << std::endl;
    }

    ~Dog() {
        delete sound;
    }
};

// Client
int main() {
    Dog originalDog("Woof! Woof!");
    originalDog.makeSound();

    Dog* clonedDog = dynamic_cast<Dog*>(originalDog.clone());
    clonedDog->makeSound();

    delete clonedDog;

    return 0;
}
