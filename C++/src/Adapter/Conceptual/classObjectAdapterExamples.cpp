/*
in this example we shall be using both the class and the object adapter approach to 
implement the adapter where we have the class and the adapter approach 
*/

// two legacy classes 
#include <iostream>
#include <string>
#include <algorithm>

// The two legacy classes are the classes with which are old and not compatible with the 
// client code. LegacyOne shall use class Adapter while legacytwo will be object adapter 
class LegacyOne
{
public:
    // a method that should be specific to the legacy code 
    std::string specificLegacyOne()
    {
        return strVal;
    }
    LegacyOne()
    {
        std::cout << " constructor called " << std::endl;
    }
    void setString( std::string & strValOne)
    {
        strVal = strValOne;
    }
private:
    std::string strVal;
};

class LegacyTwo
{
public:
    std::string request()
    {
        std::string strVal{"desu edoc owt ycageL."};
        return strVal;
    }
};

class Target 
{
public:
    virtual void targetRequest() = 0;
    virtual ~Target() = 0;
};

//implementation of the virtual Target destructor is necessary

Target::~Target()
{
    std::cout << " Pure virtual destructor definition for the Target interface " << std::endl;
}


// class adapter that inherits LegacyTwo and implements Target
class Adapter : public LegacyTwo , public Target
{
public:
    Adapter(LegacyOne *legacyOneObj) : objLegOne(legacyOneObj)
    {
        std::cout << " Adapter overloaded constructor called " << std::endl;
    }
    void targetRequest() override
    {
        std::cout << " Legacy one class used " << std::endl;
        std::string strVal1 = objLegOne->specificLegacyOne();
        
        // the adapter has used the legacyOne and LegacyTwo class
        std::cout << " Legacy two used " << strVal1 << std::endl;
        std::string strVal2 = request();
        std::reverse(strVal2.begin(), strVal2.end());
        std::cout << " legacy two output " << strVal2 << std::endl;


    }
    ~Adapter() override
    {
        std::cout << " Adapter destructor called " << std::endl;
    }

    
private:

    LegacyOne* objLegOne;

};

int main()
{

    std::cout << " to use the lagacy class one " << std::endl;
    LegacyOne* obj1 = new LegacyOne;
    std::string objstr{"object one legacy object"};
    obj1->setString(objstr);
    Adapter adapterObj(obj1);
    adapterObj.targetRequest();
    
    delete obj1;
    return 0;

}



