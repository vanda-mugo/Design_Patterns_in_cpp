#include <iostream>
#include <string>

// Product class which represents the complex object being created 
class Computer 
{
public:
    void setCPU(const std::string& cpu) 
    {
        cpu_ = cpu;
    }

    void setRAM(const std::string& ram) 
    {
        ram_ = ram;
    }

    void setStorage(const std::string& storage) 
    {
        storage_ = storage;
    }

    void displaySpecs() const 
    {
        std::cout << "Computer Specs: CPU - " << cpu_ << ", RAM - " << ram_ << ", Storage - " << storage_ << std::endl;
    }

private:
    std::string cpu_;
    std::string ram_;
    std::string storage_;
};

// Abstract Builder class which is an interface that represents the steps to building the product 
class ComputerBuilder 
{
public:
    virtual void buildCPU() = 0;
    virtual void buildRAM() = 0;
    virtual void buildStorage() = 0;
    virtual Computer getResult() = 0;
};

// Concrete Builder class that implements the builder class 
class GamingComputerBuilder : public ComputerBuilder 
{
public:
    void buildCPU() override 
    {
        computer_.setCPU("High-end gaming CPU");
    }

    void buildRAM() override 
    {
        computer_.setRAM("32GB DDR4 RAM");
    }

    void buildStorage() override 
    {
        computer_.setStorage("1TB SSD");
    }

    Computer getResult() override 
    {
        return computer_;
    }

private:
    Computer computer_;
};

// Director class
class ComputerDirector 
{
public:
    Computer constructComputer(ComputerBuilder& builder) 
    {
        builder.buildCPU();
        builder.buildRAM();
        builder.buildStorage();
        return builder.getResult();
    }
};

int main() 
{
    GamingComputerBuilder gamingBuilder;
    ComputerDirector director;
    Computer gamingComputer = director.constructComputer(gamingBuilder);

    gamingComputer.displaySpecs();

    return 0;
}
