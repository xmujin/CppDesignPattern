/**
 * @file Decorator.cpp
 * @brief Brief description of the file
 *
 * Detailed description of the file
 *
 * @version 1.0
 * @date 2025-07-17 09:46:34
 * @author xiangxun
 */
#include <iostream>
using namespace std;

class Component
{
public:
    virtual ~Component() {}
    virtual std::string Operation() const = 0;
};

class ConcreteComponent : public Component
{
public:
    std::string Operation() const override
    {
        return "ConcreteComponent";
    }
};

class Decorator : public Component
{
  
protected:
    Component *component_;

public:
    Decorator(Component *component) : component_(component)
    {
    }
    std::string Operation() const override
    {
        return this->component_->Operation();
    }
};

class ConcreteDecoratorA : public Decorator
{
public:
    ConcreteDecoratorA(Component *component) : Decorator(component)
    {
    }
    std::string Operation() const override
    {
        return "ConcreteDecoratorA(" + Decorator::Operation() + ")";
    }
};

class ConcreteDecoratorB : public Decorator
{
public:
    ConcreteDecoratorB(Component *component) : Decorator(component)
    {
    }

    std::string Operation() const override
    {
        return "ConcreteDecoratorB(" + Decorator::Operation() + ")";
    }
};

void ClientCode(Component *component)
{
    // ...
    std::cout << "RESULT: " << component->Operation();
    // ...
}

int main()
{
    /**
     * This way the client code can support both simple components...
     */
    Component *simple = new ConcreteComponent;
    std::cout << "Client: I've got a simple component:\n";
    ClientCode(simple);
    std::cout << "\n\n";
  
    Component *decorator1 = new ConcreteDecoratorA(simple);
    Component *decorator2 = new ConcreteDecoratorB(decorator1);
    std::cout << "Client: Now I've got a decorated component:\n";
    ClientCode(decorator2);
    std::cout << "\n";

    delete simple;
    delete decorator1;
    delete decorator2;

    return 0;
}