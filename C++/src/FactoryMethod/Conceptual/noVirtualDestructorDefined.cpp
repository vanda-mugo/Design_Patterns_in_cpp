// CPP program without virtual destructor 
// causing undefined behavior

/*
Deleting a derived class object using a pointer of base class type that has a non-virtual destructor results in undefined behavior. To correct this situation, the base class should be defined with a virtual destructor. 
For example, the following program results in undefined behavior. 
*/


#include <iostream>

using namespace std;

class Base 
{
public:
	Base()	 
	{ cout << "Constructing base\n"; }
	~Base()
	{ cout<< "Destructing base\n"; }	 
};

class Derived: public Base
{
public:
	Derived()	 
	{ cout << "Constructing derived\n"; }
	~Derived()
	{ cout << "Destructing derived\n"; }
};

int main()
{
Derived * d = new Derived(); 
// a pointer to an object of type derived in this case which is 
// being dynamically allocated in the heap memory using the new dynamic 
// memory allocation in c++
//delete d;
Base *b = d;
/*
in this we are creating an object of type base and this will be a pointer
to this type . we are assigning this pointer to be equal to the already
created d which is a pointer . in this case both the base object and the
derived object will be pointing the same memory location 
*/
delete b;
//getchar();
return 1;

}




/*
output
Constructing base
Constructing derived
Destructing base
*/

// the above behaviour is undefined since we have an object of type derived that is not being deleted as expected 
// in this case what would happen if we had some attributes of the derived class that were only initialised within the derived class 
// or a pointer attribute ,would this in any case lead to a memory leak in the system 



/*
some notes to take note of
when creating an object of a derived class the order by which the constructors is
called first begins with the invocation of the base class constructor then the 
derived class contructor comes to play. so in this case what happens is that 
the base class constructor is called before the derived class constructor is called 

to understand this we neeed to first understand inheritance and what happens during
inheritance .
so when a class inherits from another one what happens is that the data members of 
the base class comes automatically in the derived class based on the access specifier
access specifier refers to aspects such as the public, private and protected

recall that the definitions of this members exists in the base class therefore 
whenever we create an object of this class, the members of the derived class must be
initialised by the base class only .therefore the constructor of the base class
has to be called first inorder to initialise members whose definition may as well only be 
in the base class ( to initialize all the inherited members )

the call/invocation of the destrcutor is done in the reverse order of the constructor
*/


// usinhg virtual destrutor 
// A program with virtual destructor

#include <iostream>

using namespace std;

class base {
public:
	base()	 
	{ cout << "Constructing base\n"; }
	virtual ~base()
	{ cout << "Destructing base\n"; }	 
};

class derived : public base {
public:
	derived()	 
	{ cout << "Constructing derived\n"; }
	~derived()
	{ cout << "Destructing derived\n"; }
};

int main()
{
derived *d = new derived(); 
base *b = d;
delete d;
getchar();
return 1;
}


/*
output
Constructing base
Constructing derived
Destructing derived
Destructing base
*/


// this basically occurs when we have a situation in which a Base class object is referenced as a derived class object 
// that is because of polymorphism 


/*
the above illustrates what happens with the above 
*/

class Base
{
public:
	Base()
	{
		std::cout<< "base Constructor" << std::endl;
	}
	virtual ~Base()
	{
		std::cout << " Base destructor " << std::endl;
	}
};

class Derived : public Base
{
	public:
	Derived()
	{
		std::cout << " derived constructor " << std::endl;
	}
	~Derived()
	{
		std::cout << "Derived destructor" << std::endl;
	}

};

// note that in c++ if you dont define the access specifier of a member they default to private access 
//

int main()
{
	// the first case we shall create a base class object and delete it expecting base constructor and destructors to be called 
	Base * base = new Base(); // dynamic memory allocation on the heap using new 
	delete base;

	Derived * derived{nullptr};
	derived = new Derived();
	delete derived;

	// now with the third scenario we shall have some form of polymorphic activity where a pointer of base references an object of the subclass
	Base * baseDerived = new Derived();
	delete baseDerived;
	return 0;

}



/*
output is as follows 

base constructor
base destructor

base constructor 
derived constructor 
derived destructor 
base destructor 

base constructor 
derived constructor
base destructor 
*/

/* 
when you create the Base object as a pointer to the derived object then this is the polymorhic 
so when you call delete on this object of the class Base that however points to the derived object 
so the Base destructor doesnt know that there may be an override somewhere or there might be other 
implementations of the base destructor
this occurs when you dont include the virtual keyword 


output if virtual is included in the base class destructor 
base Constructor
 Base destructor

base Constructor
 derived constructor
Derived destructor
 Base destructor
 
base Constructor
 derived constructor
Derived destructor
 Base destructor

 */