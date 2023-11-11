/*
compile time polymorphism in c++ is achieved through function overloading
and operator overloading . the example above is through function overloading */

#include <iostream>

class MathOperations 
{
public:
    // Function to add two integers
    int add(int a, int b) 
    {
        return a + b;
    }

    // Function to add three integers
    int add(int a, int b, int c) 
    {
        return a + b + c;
    }

    // Function to add two double numbers
    double add(double a, double b) 
    {
        return a + b;
    }
};

int main() {
    MathOperations math;

    // Call the overloaded functions
    std::cout << "Sum of 2 and 3: " << math.add(2, 3) << std::endl;
    std::cout << "Sum of 2, 3, and 4: " << math.add(2, 3, 4) << std::endl;
    std::cout << "Sum of 2.5 and 3.7: " << math.add(2.5, 3.7) << std::endl;

    return 0;
}
