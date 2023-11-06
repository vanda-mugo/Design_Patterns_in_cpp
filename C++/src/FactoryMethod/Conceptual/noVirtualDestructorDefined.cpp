// CPP program without virtual destructor 
// causing undefined behavior

/*
Deleting a derived class object using a pointer of base class type that has a non-virtual destructor results in undefined behavior. To correct this situation, the base class should be defined with a virtual destructor. 
For example, the following program results in undefined behavior. 
*/
#include <iostream>

using namespace std;

class base {
public:
	base()	 
	{ cout << "Constructing base\n"; }
	~base()
	{ cout<< "Destructing base\n"; }	 
};

class derived: public base {
public:
	derived()	 
	{ cout << "Constructing derived\n"; }
	~derived()
	{ cout << "Destructing derived\n"; }
};

int main()
derived *d = new derived(); 
// a pointer to an object of type derived in this case which is 
// being dynamically allocated in the heap memory using the new dynamic 
// memory allocation in c++

base *b = d;
/*
in this we are creating an object of type base and this will be a pointer
to this type . we are assigning this pointer to be equal to the already
created d which is a pointer . in this case both the base object and the
derived object will be pointing the same memory location 
*/
delete b;
getchar();
return 0;
}


/*
output
Constructing base
Constructing derived
Destructing base
*/



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
delete b;
getchar();
return 0;
}

/*
output
Constructing base
Constructing derived
Destructing derived
Destructing base
*/