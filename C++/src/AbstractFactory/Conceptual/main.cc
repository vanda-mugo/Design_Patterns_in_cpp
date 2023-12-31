#include <iostream>
#include <string>

/**
 * Abstract Factory Design Pattern
 *
 * Intent: Lets you produce families of related objects without specifying their
 * concrete classes.
 */

/**
 * Each distinct product of a product family should have a base interface. All
 * variants of the product must implement this interface.
 */

/*
the above is a product family abstract interface
this is the abstract interface for productA  
*/

class AbstractProductA 
{
 public:
  virtual ~AbstractProductA(){}; // virtual destructor
  virtual std::string UsefulFunctionA() const = 0;// UsefulFunction which is a virtual method that returns the string
  // this method will be implemented in the variant product type that will implement this interface 
};

/**
 * Concrete Products are created by corresponding Concrete Factories.
 */

// the above is a class that implements AbstractProductA interface and returns string related to the product A1, ConcreteProductA1 returns
// the productA1 is the product created by the concreteProductA1
class ConcreteProductA1 : public AbstractProductA 
{
 public:
  std::string UsefulFunctionA() const override {
    return "The result of the product A1.";
  }
};


// another implementation of the AbstractProductA which creates the product that is A2
class ConcreteProductA2 : public AbstractProductA 
{
  std::string UsefulFunctionA() const override {
    return "The result of the product A2.";
  }
};

/**
 * Here's the the base interface of another product. All products can interact
 * with each other, but proper interaction is possible only between products of
 * the same concrete variant.
 */
class AbstractProductB 
{
  /**
   * Product B is able to do its own thing...
   */
 public:
  virtual ~AbstractProductB(){};//this is the virtual destructor .a virtual destructor for the abstract class that is AbstractProductB
  // this makes a defined way of where if the subclass object is deleted it will follow the defined reverse order
  // reverse order of constructor call that is where in constructor the base class is called first before the subclass is called and in this
  // what happens is that in the defined virtual destructor the subclass is called first before the base class is called 

  virtual std::string UsefulFunctionB() const = 0;
  /**
   * ...but it also can collaborate with the ProductA.
   *
   * The Abstract Factory makes sure that all products it creates are of the
   * same variant and thus, compatible.
   */
  virtual std::string AnotherUsefulFunctionB(const AbstractProductA &collaborator) const = 0;
  // const means that it doesnot alter the input parameter that is the const reference to AbstractProductA

};

/**
 * Concrete Products are created by corresponding Concrete Factories.
 */
class ConcreteProductB1 : public AbstractProductB {
 public:
  std::string UsefulFunctionB() const override 
  {
    return "The result of the product B1.";
  }
  /**
   * The variant, Product B1, is only able to work correctly with the variant,
   * Product A1. Nevertheless, it accepts any instance of AbstractProductA as an
   * argument.
   */
  std::string AnotherUsefulFunctionB(const AbstractProductA &collaborator) const override 
  {
    const std::string result = collaborator.UsefulFunctionA();
    return "The result of the B1 collaborating with ( " + result + " )";
  }
};

class ConcreteProductB2 : public AbstractProductB {
 public:
  std::string UsefulFunctionB() const override {
    return "The result of the product B2.";
  }
  /**
   * The variant, Product B2, is only able to work correctly with the variant,
   * Product A2. Nevertheless, it accepts any instance of AbstractProductA as an
   * argument.
   */
  std::string AnotherUsefulFunctionB(const AbstractProductA &collaborator) const override {
    const std::string result = collaborator.UsefulFunctionA();
    return "The result of the B2 collaborating with ( " + result + " )";
  }
};

/**
 * The Abstract Factory interface declares a set of methods that return
 * different abstract products. These products are called a family and are
 * related by a high-level theme or concept. Products of one family are usually
 * able to collaborate among themselves. A family of products may have several
 * variants, but the products of one variant are incompatible with products of
 * another.
 */
class AbstractFactory 
{
 public:
  virtual AbstractProductA *CreateProductA() const = 0;
  virtual AbstractProductB *CreateProductB() const = 0;
};

/**
 * Concrete Factories produce a family of products that belong to a single
 * variant. The factory guarantees that resulting products are compatible. Note
 * that signatures of the Concrete Factory's methods return an abstract product,
 * while inside the method a concrete product is instantiated.
 */
class ConcreteFactory1 : public AbstractFactory 
{
 public:
  AbstractProductA *CreateProductA() const override 
  {
    return new ConcreteProductA1();
  }
  AbstractProductB *CreateProductB() const override 
  {
    return new ConcreteProductB1();
  }
};

/**
 * Each Concrete Factory has a corresponding product variant.
 */
class ConcreteFactory2 : public AbstractFactory 
{
 public:
  AbstractProductA *CreateProductA() const override 
  {
    return new ConcreteProductA2();
  }
  AbstractProductB *CreateProductB() const override 
  {
    return new ConcreteProductB2();
  }
};

/**
 * The client code works with factories and products only through abstract
 * types: AbstractFactory and AbstractProduct. This lets you pass any factory or
 * product subclass to the client code without breaking it.
 */

void ClientCode(const AbstractFactory &factory) 
{
  const AbstractProductA *product_a = factory.CreateProductA();
  const AbstractProductB *product_b = factory.CreateProductB();
  std::cout << product_b->UsefulFunctionB() << "\n";
  std::cout << product_b->AnotherUsefulFunctionB(*product_a) << "\n";
  delete product_a;
  delete product_b;
}

int main() {
  std::cout << "Client: Testing client code with the first factory type:\n";
  ConcreteFactory1 *f1 = new ConcreteFactory1();
  ClientCode(*f1);
  delete f1;
  std::cout << std::endl;
  std::cout << "Client: Testing the same client code with the second factory type:\n";
  ConcreteFactory2 *f2 = new ConcreteFactory2();
  ClientCode(*f2);
  delete f2;
  return 0;
}


/*
this comes to play when you have or want to create a family of products that is lets say a family of variants
lets say you want a whole set of furniture that is of victorian style, so the factory should produce you a whole 
set of different variants of the victorian style as defined in the product family 
*/

// TO INCLUDE THE NECESSARY DELETERS