#include <iostream>
using namespace std;

#ifndef _DECORATOR_H
#define _DECORATOR_H

class Component
{
public:
    virtual void show() = 0;
};

class ConcreteComponent : public Component
{
public:
    void show() { cout<<"place"<<endl; }
};

class Decorator : public Component
{
public:
    Decorator(Component* c): component(c) {}
    void show() 
    {
        if (component != NULL)
            component->show();
    }
private:
    Component* component;
};

class DecoratorA : public Decorator 
{
public:
    DecoratorA(Component* c):Decorator(c) {}
    void show() 
    {
        doSomething();
        Decorator::show();        
    }
    void doSomething() {cout<<"A ";}
};

class DecoratorB : public Decorator 
{
public:
    DecoratorB(Component* c):Decorator(c) {}
    void show() 
    {
        doSomething();
        Decorator::show();        
    }
    void doSomething() {cout<<"B ";}
};

#endif
