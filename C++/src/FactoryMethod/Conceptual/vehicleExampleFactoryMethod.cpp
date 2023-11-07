// C++ program to demonstrate factory method design pattern
#include <iostream>

using namespace std;

enum VehicleType 
{
	VT_TwoWheeler,
	VT_ThreeWheeler,
	VT_FourWheeler
};

// Library classes
class Vehicle 
{

public:

	virtual void printVehicleInfo() = 0;
    // virtual method, abstract method , the class vehicle also has a virtual destructor henceforth the behaviour when deleting an object of derived class is defined 
	virtual ~Vehicle() {}
};

class TwoWheeler : public Vehicle 
// different implementation of the class that is TwoWheeler
{
public:
	void printVehicleInfo()
	{
		cout << "I am two wheeler" << endl;
	}
};

class ThreeWheeler : public Vehicle {
public:
	void printVehicleInfo()
	{
		cout << "I am three wheeler" << endl;
	}
};

class FourWheeler : public Vehicle {
public:
	void printVehicleInfo()
	{
		cout << "I am four wheeler" << endl;
	}
};

// Class Vehicle Factory with a single responsibility to
// construct Vehicles according to the clients requests. PS:
// This class can be extended to TwoWheelerFactory,
// ThreeWheelerFactory and so on.
class VehicleFactory 
{
public:
// in this case the class Vehicle factory has a method called build
// this method basically returns a pointer of type Vehicle, recall that the Vehicle class has been implemented in different ways 
// in this case the different implmentations of this class will come to play . so it can return a pointer to any of the official 
// child or derived classes of the Vehicle class

// the input argument in this case is the VehicleType which is a type to be defined below
	Vehicle* build(VehicleType vehicleType)
	{
        // so note the return from this function which happens to be any of the types from the vehicle derived classses 

		if (vehicleType == VT_TwoWheeler)
			return new TwoWheeler();
		else if (vehicleType == VT_ThreeWheeler)
			return new ThreeWheeler();
		else if (vehicleType == VT_FourWheeler)
			return new FourWheeler();
		else
			return nullptr;
	}
};

// Client class. The client object will ask the factory to
// build vehicles.
class Client 
{
public:
// client class default constructor , in this case the default constructor assigns the value for the class attribute that happens to be pVehicle
// pVehicle happens to be a private member of the class that is client 
// initialises the pVehicle pointer which happens to be a pointer of type Vehicle to be equal to nullptr
	Client() :pVehicle{nullptr} 
    {}

	void BuildVehicle(VehicleType vehicleType)
	{
		VehicleFactory* vf = new VehicleFactory();
		pVehicle = vf->build(vehicleType);

		delete vf;
	}

	~Client()
	{
		if (pVehicle) 
        {
            // in this case we are deleting the pointer to avoid having a memory leak 
            // if the pointer has a value then the if will be true
			delete pVehicle;
			pVehicle = NULL;
		}
	}

	Vehicle* getVehicle() { return pVehicle; }

private:
	Vehicle* pVehicle;
};

// Driver program
int main()
{
    // creating a pointer to the class client dynamically in the heap storage
	Client* pClient = new Client();

    // The BuildVehicle method assigns pVehicle which is a private pointer of type Vehicle the value which in this case will be from the fractory method that returns Vehicle
    // the buld method returns a pointer of type vehicle which means that the pVehicle will be a pointer to the type Vehicle 
    // the getVehicle returns a pointer as well and in this case since its a pointer of type vehicle it access the Vehicle printVehicleInfo method 
	pClient->BuildVehicle(VT_TwoWheeler);
	pClient->getVehicle()->printVehicleInfo();

	pClient->BuildVehicle(VT_ThreeWheeler);
	pClient->getVehicle()->printVehicleInfo();

	pClient->BuildVehicle(VT_FourWheeler);
	pClient->getVehicle()->printVehicleInfo();

	delete pClient;
	return 0;
}
