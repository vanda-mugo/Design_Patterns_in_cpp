
#include <iostream>
#include <cstring>
#include <string>

class Vehicles
{
public:
    virtual Vehicles* clone() const = 0;
    virtual ~Vehicles() = default;
    virtual void printMemberInfor() const = 0;
};

class Saloon : public Vehicles
{
public:
    Saloon( int value = 4, const char* value2 = "cool", const char* value3 = "geek", const std::string value4 = "Jazz")
    : size(value), charData1(new char[strlen(value2) + 1]), charData2(new char[strlen(value3) + 1]), stringData(new std::string(value4))
    {
        strcpy(this->charData1, value2);
        strcpy(this->charData2, value3);
        std::cout << " Saloon default constructor " << std::endl; 
    } 
    Saloon* clone() const override
    {
        std::cout << " clone saloon " << std::endl;
        return new Saloon(*this);
    }

    void printMemberInfor() const override
    {
        std::cout << " char data 1 " << charData1 << std::endl;
        std::cout << " char data 2 " << charData2 << std::endl;
    }
    
    Saloon( const Saloon& source)
    :size(source.size), charData1(new char[strlen(source.charData1) + 1]), charData2(new char[strlen(source.charData2) + 1]), stringData(source.stringData)
    {
        strcpy(this->charData1, source.charData1);
        strcpy(this->charData2, source.charData2);
        std::cout << " copy constructor called " << std::endl;
    }

    ~Saloon()
    {
        //std::cout << " destrcutor called for " << this->charData1 << " char data 2 " << this->charData2 << std::endl;
        delete [] charData1;
        delete [] charData2;
        delete stringData;
         
    }

private:
    int size;
    char * charData1;
    char * charData2;
    std::string * stringData;

};

class Bus : public Vehicles
{
public:

    Bus(const std::string value1 = " cool ",const char* value2 = " geek ")
    : strVal(new std::string(value1)), charData(new char[strlen(value2) + 1])
    {
        strcpy(this->charData, value2);
        std::cout << " default constructor " << std::endl;
    }
    // want to perform a shallow copy of copy constructor 
    Bus(const Bus& source)
    : strVal(source.strVal), charData(source.charData)
    {
        // 
        std::cout << " shallow copy constructor " << std::endl;
    }
    Bus* clone() const override
    {
        std::cout << " bus clone " << std::endl;
        return new Bus(*this);
    }

    void printMemberInfor() const override
    {
        std::cout << " char data  " << charData << std::endl;
        std::cout << " string strVal " << strVal << std::endl;
        std::cout << " string strVal " << *strVal << std::endl;
    }

    ~Bus() override
    {
        //std::cout << " destrcutor called for " << this->charData << " char data 2 " << this->strVal << " whose value is " << *this->strVal << std::endl;
        delete strVal;
        delete [] charData;
        
    }



private:
    std::string* strVal;
    char * charData;

};

int main()
{

    std::cout << " obj 1 saloon object " << std::endl;
    Saloon obj1(4, " kenya " , " Migrate " , " Australia ");
    obj1.printMemberInfor();

    std::cout << " obj 2 cloned from obj1 " << std::endl;
    Saloon* obj2 = obj1.clone();
    obj2->printMemberInfor();

    std::cout << " obj 3 cloned from obj 2 " << std::endl;
    Saloon obj3 = *obj2;
    obj3.printMemberInfor();

    std::cout << " obj 4 bus object " << std::endl;
    Bus obj4( " BUS ", " DTA");
    obj4.printMemberInfor();

    std::cout << " obj 5 copy of Bus object with shallow copy " << std::endl;
    Bus obj5 = obj4;
    obj5.printMemberInfor();
    return 0;
}