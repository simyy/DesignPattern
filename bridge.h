#include <iostream>
using namespace std;

#ifndef _H_BRIDGE
#define _H_BRIDGE

class Implementor
{
public:
    virtual void operation() = 0;
};

class ConcreteImplementorA : public Implementor
{
public:
    void operation() { cout<<"Implementor A"<<endl; }
};

class ConcreteImplementorB : public Implementor
{
public:
    void operation() { cout<<"Implementor B"<<endl;}
};

class Abstractor
{
public:
    Abstractor(Implementor* im):im(im) {}
    virtual void operation() = 0;
protected:
    Implementor* im;
};

class ConcreteAbstractor : public Abstractor
{
public:
    ConcreteAbstractor(Implementor* im):Abstractor(im) {}
    void operation() { im->operation(); }
};

#endif
