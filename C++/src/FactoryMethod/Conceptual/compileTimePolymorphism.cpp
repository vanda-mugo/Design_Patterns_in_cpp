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

//output 
/*
Sum of 2 and 3: 5
Sum of 2, 3, and 4: 9
Sum of 2.5 and 3.7: 6.2


In this example:

    The MathOperations class has three overloaded add functions.
    The first add function takes two integers, the second takes three integers, and the third takes two double numbers.
    In the main function, we create an object of the MathOperations class and call the overloaded add functions with different sets of parameters.

Function overloading allows multiple functions with the same name but 
different parameter lists to coexist in the same scope. The compiler 
determines which function to call based on the number and types of 
arguments provided during the function call. This decision is made at 
compile time, hence the term "compile-time polymorphism" or "static 
polymorphism."
*/
