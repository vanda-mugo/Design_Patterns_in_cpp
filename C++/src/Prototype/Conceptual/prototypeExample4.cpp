#include <iostream>
#include <string>
#include <cstring>

class AbstractDesign
{
public:
virtual AbstractDesign* clone() const = 0;
virtual ~AbstractDesign() = default;
virtual void printAbstractInfo() const = 0;

};

class AbstractConcrete : public AbstractDesign
{

public:
    //default constructor 
    AbstractConcrete(int value = 4, double doubleVal = 3.4, const char* string = "cool", std::string strvalue = " test string ")
    :value(value), amount(doubleVal), charData(new char[strlen(string) + 1]), strVal(new std::String(strvalue))
    {
        strcpy(this->charData, string);
    }
    // copy constuctor 
    AbstractConcrete( const AbstractConcrete& source) 
    :value(source.value), amount(source.amount), charData(new char[strlen(source.charData) + 1]), strVal(new std::string(*source.strVal))
    {
        strcpy(this->charData, source.charData);
    }

    AbstractConcrete* clone() const override
    {
        return new AbstractConcrete(*this);
    }

    void printAbstractInfo()
    {
        std::cout << " val of the string is " << *this->strVal << std::endl;
        std::cout << " address of the string is " << this->strVal << std::endl;
        std::cout << " value of the char Data is " << this->charData << std::endl;
    }
    ~AbstractConcrete()
    {
        delete [] charData;
        delete strVal;
    }



private:
    int value;
    double amount;
    char * charData;
    std::string* strVal;
};

int main()
{
    std::cout << " obj 1" << std::endl;
    AbstractConcrete obj1;
    obj1.printAbstractInfo();
    std::cout << " obj 2 " << std::endl;
    AbstractConcrete obj2(20, 39.4, "guess", " this ");
    obj2.printAbstractInfo();
    std::cout << " obj 3 " << std::endl;
    AbstractConcrete obj3 = obj2;
    obj3.printAbstractInfo();
    std::cout << " obj 4 " << std::endl;
    AbstractConcrete obj4 = obj1;
    obj4.printAbstractInfo();
    return 0;

}