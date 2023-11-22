/*
Document cloning : -

consider a scenario where you have a document with various sections. you can use prototype pattern to clone the sections of the document 

*/

#include <iostream>
#include <string>

// Prototype Interface
class Section 
{
public:
    virtual Section* clone() const = 0;
    virtual void print() const = 0;
};

// Concrete Prototypes
class Introduction : public Section 
{
public:
    Section* clone() const override 
    {
        return new Introduction(*this);
    }

    void print() const override 
    {
        std::cout << "Introduction section" << std::endl;
    }
};

class Conclusion : public Section 
{
public:
    Section* clone() const override 
    {
        return new Conclusion(*this);
    }

    void print() const override 
    {
        std::cout << "Conclusion section" << std::endl;
    }
};

// Client
int main() 
{
    Section* intro = new Introduction();
    Section* conclusion = new Conclusion();

    Section* introCopy = intro->clone();
    Section* conclusionCopy = conclusion->clone();

    introCopy->print();
    conclusionCopy->print();

    delete intro;
    delete conclusion;
    delete introCopy;
    delete conclusionCopy;

    return 0;
}
