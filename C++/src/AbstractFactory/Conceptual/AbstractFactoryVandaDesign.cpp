/*
lets say you wanted to buy a set of vehicles involving a bus a truck a van and a saloon ,
within this differet categories we have different variants of the categories eg for the bus we have 
VW buses , Honda buses and volvo buses as the rest of the categories above

Implement abstract factory such that it implements this with client code */

#include <iostream>
#include <string>

class Bus
{
public:
    virtual ~Bus(){};
    virtual std::string printBusType() = 0;

};

class Truck
{
public:
    virtual ~Truck(){};
    virtual std::string printTruckType() = 0;
};

class Van
{
public:
    virtual ~Van(){};
    virtual std::string printVanType() = 0;
};

class Saloon
{
public:
    virtual ~Saloon(){};
    virtual std::string printSaloonType() = 0;
};

// now that we have the interfaces for the different product families we make the variants implement this interface
class VWbus : public Bus
{
public:
    std::string printBusType()
    {
        //std::cout << "VW bus produces " << std::endl;
        return "VW bus produces ";
    }

    ~VWbus()
    {
        std::cout << "VW Bus destroyed" << std::endl;
    }
};

class VWtruck : public Truck
{
public:
    std::string printTruckType()
    {
        //std::cout << "VW Truck produces " << std::endl;
        return "VW Truck produces ";
    }
    ~VWtruck()
    {
        std::cout << "VW Truck destroyed" << std::endl;
    }
};

class VWvan : public Van
{
public:
    std::string printVanType()
    {
        //std::cout << "VW van produces " << std::endl;
        return "VW Van produces ";
    }
    ~VWvan()
    {
        std::cout << "VW van destroyed" << std::endl;
    }
};

class VWsaloon : public Saloon
{
public:
    std::string printSaloonType()
    {
        // std::cout << "VW Saloon produces " << std::endl;
        return "VW Saloon produces ";
    }
    ~VWsaloon()
    {
        std::cout << "VW Saloon destroyed" << std::endl;
    }
};

// implement variants for honda 
class Hondabus : public Bus
{
public:
    std::string printBusType()
    {
        //std::cout << "Honda bus produces " << std::endl;
        return "Honda bus produces ";
    }
    ~Hondabus()
    {
        std::cout << "Honda Bus destroyed" << std::endl;
    }
};

class Hondatruck : public Truck
{
public:
    std::string printTruckType()
    {
        //std::cout << "Honda Truck produces " << std::endl;
        return "Honda Truck produces ";
    }
    ~Hondatruck()
    {
        std::cout << "Honda Truck destroyed" << std::endl;
    }
};

class Hondavan : public Van
{
public:
    std::string printVanType()
    {
        //std::cout << "Honda Van produces " << std::endl;
        return "Honda Van produces ";
    }
    ~Hondavan()
    {
        std::cout << "Honda Van destroyed" << std::endl;
    }
};

class Hondasaloon : public Saloon
{
public:
    std::string printSaloonType()
    {
        //std::cout << "Honda Saloon produces " << std::endl;
        return "Honda Saloon produces ";
    }
    ~Hondasaloon()
    {
        std::cout << "Honda Saloon destroyed" << std::endl;
    }
};

// implement volvo variants 
class Volvobus : public Bus
{
public:
    std::string printBusType()
    {
        //std::cout << "Volvo bus produces " << std::endl;
        return "Volvo bus produces ";
    }
    ~Volvobus()
    {
        std::cout << "Volvo Bus destroyed" << std::endl;
    }
};

class Volvotruck : public Truck
{
public:
    std::string printTruckType()
    {
        //td::cout << "Volvo Truck produces " << std::endl;
        return "Volvo Truck produces ";
    }
    ~Volvotruck()
    {
        std::cout << "Volvo Truck destroyed" << std::endl;
    }
};

class Volvovan : public Van
{
public:
    std::string printVanType()
    {
        //std::cout << "Volvo Van produces " << std::endl;
        return "Volvo Van produces ";
    }
    ~Volvovan()
    {
        std::cout << "Volvo Van destroyed" << std::endl;
    }
};

class Volvosaloon : public Saloon
{
public:
    std::string printSaloonType()
    {
        // std::cout << "Volvo Saloon produces " << std::endl;
        return "Volvo Saloon produces ";
    }
    ~Volvosaloon()
    {
        std::cout << "Volvo Saloon destroyed" << std::endl;
    }
};

// now to define the abstract factory 
class AbstractFactory
{
public:
    virtual Bus* createBus() = 0;
    virtual Truck* createTruck() = 0;
    virtual Van* createVan() = 0;
    virtual Saloon* createSaloon() = 0;
    virtual ~AbstractFactory()
    {
        std::cout << "Abstract factory destructor called " << std::endl;
    };
};

//now to have the concreteFactory that will implement the abstract Factory
class VWconcreteFactory : public AbstractFactory
{
public:
    Bus* createBus()
    {
        return new VWbus;
    } 
    Truck* createTruck() 
    {
        return new VWtruck;
    }
    Van* createVan() 
    {
        return new VWvan;
    }
    Saloon* createSaloon() 
    {
        return new VWsaloon;
    }
    virtual ~VWconcreteFactory()
    {
        std::cout << "VWconcreteFactory factory destructor called " << std::endl;
    };
};

// for Honda 
class HondaconcreteFactory : public AbstractFactory
{
public:
    Bus* createBus()
    {
        return new Hondabus;
    } 
    Truck* createTruck() 
    {
        return new Hondatruck;
    }
    Van* createVan() 
    {
        return new Hondavan;
    }
    Saloon* createSaloon() 
    {
        return new Hondasaloon;
    }
    virtual ~HondaconcreteFactory()
    {
        std::cout << "HondaconcreteFactory factory destructor called " << std::endl;
    };
};

// for volvo
class VolvoconcreteFactory : public AbstractFactory
{
public:
    Bus* createBus()
    {
        return new Volvobus;
    } 
    Truck* createTruck() 
    {
        return new Volvotruck;
    }
    Van* createVan() 
    {
        return new Volvovan;
    }
    Saloon* createSaloon() 
    {
        return new Volvosaloon;
    }
    virtual ~VolvoconcreteFactory()
    {
        std::cout << "VolvoconcreteFactory factory destructor called " << std::endl;
    };
};

// now to script client code 
void clientCode(AbstractFactory & contributor)
{
    Bus* bus = contributor.createBus();
    Saloon* saloon = contributor.createSaloon();
    Truck* truck = contributor.createTruck();
    Van* van = contributor.createVan();

    std::cout << bus->printBusType() << std::endl;
    std::cout << saloon->printSaloonType() << std::endl;
    std::cout << truck->printTruckType() << std::endl;
    std::cout << van->printVanType() << std::endl;
}

int main()
{
    AbstractFactory* volvoCatalogue = new VolvoconcreteFactory;
    clientCode(*volvoCatalogue);

    AbstractFactory* HondaCatalogue = new HondaconcreteFactory;
    clientCode(*HondaCatalogue);

    AbstractFactory* VWcatalogue = new VWconcreteFactory;
    clientCode(*VWcatalogue);
    delete volvoCatalogue;
    delete VWcatalogue;
    delete HondaCatalogue;
    return 0;
}