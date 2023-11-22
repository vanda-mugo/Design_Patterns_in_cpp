/*
Copy Constructor:

A copy constructor is a special constructor that is used to create a new object as a copy of an 
existing object of the same type. It is invoked when a new object is being created as a copy of an existing object, 
either explicitly or implicitly. The general syntax for a copy constructor looks like this:
*/
#include <iostream>
#include <cstring>

/*
class MyClass 
{
public:
    // Copy constructor
    MyClass(const MyClass& other) 
    {
        // Copy the members from 'other' to 'this'
    }
};

*/


// another class with a copy constructor 

class MyClass 
{
public:
    int data;

    // Copy constructor
    MyClass()
    {
        // this is for provision of the default constructor 
        /*
        When you declare a class with a copy constructor 
        (or any constructor other than the default constructor), 
        and you do not explicitly provide a default constructor,
         the C++ compiler won't generate a default constructor for you. 
         This can lead to errors in certain situations, as some operations
         or scenarios may implicitly require a default constructor to be available.
        */
    }

    MyClass(const MyClass& other) 
    : data(other.data) 
    {
        std::cout << "Copy constructor called" << std::endl;
    }
};


/*
Deep copy becomes necessary in a copy constructor when a class contains dynamically allocated 
resources (such as a raw pointer pointing to memory created with new). 
In such cases, a shallow copy (copying the pointer value only) would result in multiple objects 
pointing to the same memory location. If one object modifies or frees that memory, 
it affects all the other objects sharing that memory, leading to undefined behavior and potential crashes.
*/

class StringWrapper 
{
public:
    // Constructor
    StringWrapper(const char* str) 
    {
        // Dynamically allocate memory for the string
        data = new char[strlen(str) + 1]; // creating an array of characters
        strcpy(data, str);
    }

    // Copy constructor (without deep copy)
    StringWrapper(const StringWrapper& other) 
    : data(other.data) 
    {}

    // Display the string
    void display() const 
    {
        std::cout << "String: " << *data << std::endl;
        std::cout << "adress of data for this is " << &(*data) << std::endl;
    }

    // Destructor to free the dynamically allocated memory
    ~StringWrapper() 
    {
        delete[] data;
    }

private:
    char* data;// raw pointer variable of class StringWrapper
};

/*
In this example, the StringWrapper class has a dynamically allocated char* member (data) to store a string. 
The copy constructor, however, performs a shallow copy by copying the pointer value only. As a result, 
both the original object and the shallow copy end up pointing to the same memory location.

When the original object is modified and its destructor is called, it frees the memory. Subsequently, 
if you try to access the data through the shallow copy, it results in undefined behavior because the memory it points to has been freed.

To address this issue, a deep copy should be performed in the copy constructor. Here's an updated example with a deep copy:
*/

class StringWrapperDeepCopy 
{
public:
    // Constructor
    StringWrapperDeepCopy(const char* str) 
    {
        // Dynamically allocate memory for the string
        data = new char[strlen(str) + 1]; // creating an array of characters
        strcpy(data, str);
    }

    // Copy constructor (without deep copy)
    // Copy constructor (with deep copy)
StringWrapperDeepCopy(const StringWrapperDeepCopy& other) 
: data(new char[strlen(other.data) + 1]) 
{
    strcpy(data, other.data);
}
//Now, each object has its own copy of the dynamically allocated memory, preventing interference between objects.

    // Display the string
    void display() const 
    {
        std::cout << "String: " << *data << std::endl;
        std::cout << "adress of data for this is " << &(*data) << std::endl;
    }

    // Destructor to free the dynamically allocated memory
    ~StringWrapperDeepCopy() 
    {
        delete[] data;
    }

private:
    char* data;// raw pointer variable of class StringWrapper
};

/*
copy constructor with a deep copy when a class has dynamically allocated resources*/

class DynamicArray 

{
public:
    // Constructor
    DynamicArray(const char* str) 
    {
        data = new char[strlen(str) + 1];
        strcpy(data, str);
    }

    // Copy constructor (with deep copy)
    DynamicArray(const DynamicArray& other) : data(new char[strlen(other.data) + 1]) 
    {
        strcpy(data, other.data);
    }

    // Display the string
    void display() const 
    {
        std::cout << "String: " << data << std::endl;
    }

    // Destructor to free the dynamically allocated memory
    ~DynamicArray() 
    {
        delete[] data;
    }

private:
    char* data;
};


class Person 
{
public:
    // Constructor
    Person(const char* name, int age) 
    : age(age) 
    {
        // Deep copy for the name
        this->name = new char[strlen(name) + 1];
        strcpy(this->name, name);
    }

    // Copy constructor (with deep copy)
    Person(const Person& other) 
    : age(other.age) 
    {
        // Deep copy for the name
        this->name = new char[strlen(other.name) + 1];
        strcpy(this->name, other.name);
    }

    // Display person information
    void display() const 
    {
        std::cout << "Name: " << name << ", Age: " << age << std::endl;
    }

    // Destructor to free the dynamically allocated memory
    ~Person() 
    {
        delete[] name;
    }

private:
    char* name;
    int age;
};


int main() 
{

    // content of class MyClass 
    MyClass obj1;
    obj1.data = 42;

    MyClass obj2 = obj1;  // Copy constructor is called here

    std::cout << obj2.data << std::endl;

    // content of class StringWrapper
    std::cout << " original " << std::endl;
    StringWrapper original("Hello, World!");
    original.display();

    std::cout << " shallow copy " << std::endl;
    StringWrapper shallowCopy(original);  // Shallow copy, both objects point to the same memory for the value of the dynamically allocated memory


    // Modify the original string
    shallowCopy.display();  // Both display the same modified string due to shallow copy

    DynamicArray original2("Hello, World!");

    DynamicArray deepCopy(original2);  // Copy constructor with deep copy

    original2.display();
    deepCopy.display();

    Person original3("John Doe", 30);

    Person deepCopy(original3);  // Copy constructor with deep copy

    original.display();
    deepCopy.display();

    return 0;
}

/*
    In C++, the strcpy function works similarly to its counterpart in C, 
    but it's used with char arrays or pointers, and it's part of the <cstring> or <string.h> header. The function signature is the same:

    syntax
    char* strcpy(char* dest, const char* src);
    Copying Characters:
    strcpy copies characters from the source string (src) to the destination string (dest) one by one until it encounters the null character 
    '\0' in the source string. The null character is also copied to the destination, marking the end of the string.
    note by that in the strlen(str) + 1 we are actually adding 1 for the null terminating strings

    Termination:
    The copying stops when the null character is encountered in the source string, and the null character is then appended to the destination string.

    Return Value:
    The function returns a pointer to the destination string, which is also the initial value of dest. This allows for easy chaining of string operations.

    it's important to ensure that the destination array has enough space to accommodate the source string, including the null terminator, 
    to avoid buffer overflow issues. C++ also provides safer alternatives, such as std::string and std::strcpy (from <cstring>),
    which are part of the C++ Standard Library and offer better memory safety.
    */