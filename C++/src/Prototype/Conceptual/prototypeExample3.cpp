/*
in this example I shall illustrate prototype in classes that have raw pointers as data memebers and 
with this have dynamically allocated memory for the raw pointers 
*/

#include <iostream>
#include <string>
#include <cstring>

// prototype interface class

class ConceptDesign
{

public:
    virtual void displaySeatConcept() = 0;
    virtual ConceptDesign* clone() const = 0;
    virtual ~ConceptDesign() = default;
};

// concrete prototype
class Wooden : public ConceptDesign
{

public:
// we will need a default constructor since we shall define a copy constructor 
Wooden()
{
    std::cout << " default constructor called " << std::endl;
}

// define the overloaded constructor 
// to use initialisation lists 
Wooden(std::string stringVal , const char* cString , int val)
:intVal(val), strVal(new std::string(stringVal)), charData(new char[strlen(cString) + 1]) // for null terminated cstring 
{
    // to now assign the value for the cString 
    strcpy(this->charData , cString);
}

// now to define the copy constructor

Wooden(const Wooden& source )
:intVal(source.intVal), strVal(new std::string(*source.strVal))// in this case source will be the object with which the copy constructor is called 
{
    // to assign the values for the pointer member variable
    this->charData = new char[strlen(source.charData) + 1];
    strcpy(this->charData, source.charData);

}

void displaySeatConcept() override
{
    std::cout << " the string value is " << *strVal << std::endl;
    std::cout << " the address for string variable is " << strVal << std::endl;
    std::cout << " the char data is as follows " << charData << std::endl ;
    
}

Wooden* clone() const override
{
    return new Wooden(*this);
}

~Wooden() override
{
    // to delete the data pointers 
    delete [] charData;
    delete strVal;
}

private:
    int intVal ;
    std::string* strVal ;// pointer to a value of type std::string
    char* charData ;


};


int main()
{
    // client code 
    Wooden obj1("geek", "cool", 34);
    obj1.displaySeatConcept();
    // cloned object definition 
    std::cout << " cloned concept " << std::endl;
    Wooden obj2 = obj1;
    obj2.displaySeatConcept();


    return 0;
}
/*
 if you provide any other constructor for your class (a non-default constructor), and you still need default construction,
you may need to explicitly define the default constructor. If no constructor is provided, the compiler generates a default 
constructor automatically, but if you provide one with arguments, the compiler doesn't generate the default constructor.
 */

// so its noted that the order of initialisation in the copy constructor or any other constrctor should be in the order with which the variables have been initialised 