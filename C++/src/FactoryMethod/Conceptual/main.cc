#include <iostream>
#include <string>

/**
 * Factory Method Design Pattern
 *
 * Intent: Provides an interface for creating objects in a superclass, but
 * allows subclasses to alter the type of objects that will be created.
 */

/**
 * The Product interface declares the operations that all concrete products must
 * implement.
 note by that the definition of an interface is a class that in which the behaviour
 or rather the function of a class is defined but rather the implementation of 
the class is now implemeted in the subclasses of this interface class 
so inorder to create an interface class  its paramount to create an abstract class
so the definition of an abstract class is a class with which the all the functions 
found within the class are not implemented but rather the implementation is provided
within the subclasses that come from the base class 

such functions in c++ are called pure virtual functions and the definition of 
virtual functions is as below.
a pure virtual function or abstract in c++ is a function for which we may have an 
implementation but we must ovverride that function in the derived class . the
derived class will also become an abstract class. in c++ this is declared by 
having a 0 in the function declaration in the base class.
 */

class Product 
{
  /*
  note by that the product declares an interface that is common to all the 
  objects that can be produced by the creator and its subclasses */
 public:
 // declaration of a virtual destructor 
 /*
 recall : deleting a derived clas object using a pointer of a base class type 
 that has a non virtual destructor results in undefined behaviour . to correct this 
 situation the base class should be defined with a virtual destructor
 */
  virtual ~Product() {}
  /*
  call to a viirtual destructor as described . this ensures that the call for the 
  destructor happens as expected 
  */

  // the above is a virtual operation class that has been defined with constant 0
  // implementation will occur in the derived classes for the above virtual method
  virtual std::string Operation() const = 0;
};

/**
 * Concrete Products provide various implementations of the Product interface.
 */
class ConcreteProduct1 : public Product 
{
  /*
  so note that the concreteProduct1 provides various implementations of the 
  product classs.the product class in this case is an interface(abstract class)
  basically provides an interface/blueprint by which the derived class shall have 
  to implement differently */
 public:
  std::string Operation() const override 
  {
    return "{Result of the ConcreteProduct1}";
  }
};
class ConcreteProduct2 : public Product 
{
 public:
  std::string Operation() const override 
  {
    return "{Result of the ConcreteProduct2}";
  }
};

/**
 * The Creator class declares the factory method that is supposed to return an
 * object of a Product class. The Creator's subclasses usually provide the
 * implementation of this method.
 */

class Creator 
{
  /**
   * Note that the Creator may also provide some default implementation of the
   * factory method.
   */
 public:
  virtual ~Creator(){};
  // this is a virtual function that returns a pointer of type product
  virtual Product* FactoryMethod() const = 0;
  /**
   * Also note that, despite its name, the Creator's primary responsibility is
   * not creating products. Usually, it contains some core business logic that
   * relies on Product objects, returned by the factory method. Subclasses can
   * indirectly change that business logic by overriding the factory method and
   * returning a different type of product from it.
   */

  std::string SomeOperation() const {
    // Call the factory method to create a Product object.
    Product* product = this->FactoryMethod();
    // Now, use the product.
    std::string result = "Creator: The same creator's code has just worked with " + product->Operation();
    delete product;
    return result;
  }
};

/**
 * Concrete Creators override the factory method in order to change the
 * resulting product's type.
 */
class ConcreteCreator1 : public Creator {
  /**
   * Note that the signature of the method still uses the abstract product type,
   * even though the concrete product is actually returned from the method. This
   * way the Creator can stay independent of concrete product classes.
   */
 public:
  Product* FactoryMethod() const override {
    return new ConcreteProduct1();
  }
};

class ConcreteCreator2 : public Creator {
 public:
  Product* FactoryMethod() const override {
    return new ConcreteProduct2();
  }
};

/**
 * The client code works with an instance of a concrete creator, albeit through
 * its base interface. As long as the client keeps working with the creator via
 * the base interface, you can pass it any creator's subclass.
 */
void ClientCode(const Creator& creator) 
/*
so note by what happens in the clientCode void function , we can see that in this case 
we are having a pointer of type creator being passed onto this void function 

in this case you can pass either a creator of concreteCreator1 or a creator of ConcreteCreator2
in both cases what happens is that each of thsi concreteCreator implements the factoryMethod differently 
so what happens lets say when you pass lets say the concreteCreator1 object to this void function ,
in the constructor for object of concreteCreator1 what occurs is the following 

an object of type concreteCreator1 is created in which we have no defined default constructor 
so then the clientCode void functon in retrospect calls a someOperation() method 
this is a const method that means that it does not in this case alter the object type that has been passed 

within the someOperation method we are creating a product pointer and in this case the result is from 
the call of the factory method which is a virtual function implemented differently in both of this classes that are 
subclasses of the main base creator class.

now the concrete creator1 implements the factoryMethod by returning a product of concreteProduct1
so in this case the concreteProduct1 object is returned 

*/
{
  // ...
  std::cout << "Client: I'm not aware of the creator's class, but it still works.\n"
            << creator.SomeOperation() << std::endl;
  // ...
}

/**
 * The Application picks a creator's type depending on the configuration or
 * environment.
 */

int main() {
  std::cout << "App: Launched with the ConcreteCreator1.\n";
  Creator* creator = new ConcreteCreator1();
  ClientCode(*creator);
  std::cout << std::endl;
  std::cout << "App: Launched with the ConcreteCreator2.\n";
  Creator* creator2 = new ConcreteCreator2();
  ClientCode(*creator2);

  delete creator;
  delete creator2;
  return 0;
}

/*
the factory methodd is a recreation design pattern that provides an interface 
for creating objects of a subclass, but allows subclasses to alter the type of
object that is being  created
*/ 