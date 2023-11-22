/*
GRAPHIC OBJECTS :-

Imagine you have a graphic editor, and you want to create copies of complex objects.
the prototype pattern can be applied here.

*/

#include <iostream>
#include <vector>

// Prototype Interface
class GraphicObject 
{
public:
    virtual GraphicObject* clone() const = 0;
    virtual void draw() const = 0;
};

// Concrete Prototypes
class Circle : public GraphicObject 
{
public:
    GraphicObject* clone() const override 
    {
        return new Circle(*this);
    }

    void draw() const override 
    {
        std::cout << "Drawing a circle." << std::endl;
    }
};

class Square : public GraphicObject 
{
public:
    GraphicObject* clone() const override 
    {
        return new Square(*this);
    }

    void draw() const override 
    {
        std::cout << "Drawing a square." << std::endl;
    }
};

// Client
int main() 
{
    std::vector<GraphicObject*> objects;
    objects.push_back(new Circle());
    objects.push_back(new Square());

    for (const auto& obj : objects) 
    {
        GraphicObject* copy = obj->clone();
        // within this for loop we are making a copy of each of the objects using the clone method in the function 
        
        copy->draw();
        delete copy;
    }

    // Cleanup
    for (auto obj : objects) 
    {
        delete obj;
    }

    return 0;
}
