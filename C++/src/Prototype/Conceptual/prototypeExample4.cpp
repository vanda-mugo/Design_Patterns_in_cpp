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
    // note that in the above constructor the initilisation of the  char variable as const char* strVal1 
    // this is because strcpy requires c style string ( a pointer to char)

    AbstractConcrete(int value = 4, double doubleVal = 3.4, const char* strval1 = "cool", std::string strvalue = " test string ")
    :value(value), amount(doubleVal), charData(new char[strlen(strval1) + 1]), strVal(new std::string(strvalue))
    {
        strcpy(this->charData, strval1);
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

    void printAbstractInfo() const override
    {
        std::cout << " val of the string is " << *this->strVal << std::endl;
        std::cout << " address of the string is " << this->strVal << std::endl;
        std::cout << " value of the char Data is " << this->charData << std::endl;
    }
    ~AbstractConcrete() override
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
    std::cout << " \nobj 2 " << std::endl;
    AbstractConcrete obj2(20, 39.4, "guess", " this ");
    obj2.printAbstractInfo();
    std::cout << "\n obj 3 " << std::endl;
    AbstractConcrete obj3 = obj2;
    obj3.printAbstractInfo();
    std::cout << "\n obj 4 " << std::endl;
    AbstractConcrete obj4 = obj1;
    obj4.printAbstractInfo();
    return 0;

}