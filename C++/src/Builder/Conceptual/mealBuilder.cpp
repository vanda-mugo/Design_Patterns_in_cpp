#include <iostream>
#include <string>

// Product class
class Meal 
{
public:
    void setMainCourse(const std::string& mainCourse) 
    {
        mainCourse_ = mainCourse;
    }

    void setSideDish(const std::string& sideDish) 
    {
        sideDish_ = sideDish;
    }

    void setDrink(const std::string& drink) 
    {
        drink_ = drink;
    }

    void displayMeal() const 
    {
        std::cout << "Meal: " << mainCourse_ << ", " << sideDish_ << ", " << drink_ << std::endl;
    }

private:
    std::string mainCourse_;
    std::string sideDish_;
    std::string drink_;
};

// Abstract Builder class
class MealBuilder 
{
public:
    virtual void buildMainCourse() = 0;
    virtual void buildSideDish() = 0;
    virtual void buildDrink() = 0;
    virtual Meal getResult() = 0;
};

// Concrete Builder class
class HealthyMealBuilder : public MealBuilder 
{
public:
    void buildMainCourse() override 
    {
        meal_.setMainCourse("Grilled chicken salad");
    }

    void buildSideDish() override 
    {
        meal_.setSideDish("Quinoa");
    }

    void buildDrink() override 
    {
        meal_.setDrink("Green tea");
    }

    Meal getResult() override 
    {
        return meal_;
    }

private:
    Meal meal_;
};

// Director class
class MealDirector 
{
public:
    Meal constructMeal(MealBuilder& builder) 
    {
        builder.buildMainCourse();
        builder.buildSideDish();
        builder.buildDrink();
        return builder.getResult();
    }
};

int main() 
{
    HealthyMealBuilder healthyBuilder;
    MealDirector director;
    Meal healthyMeal = director.constructMeal(healthyBuilder);

    healthyMeal.displayMeal();

    return 0;
}
