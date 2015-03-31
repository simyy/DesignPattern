#include <iostream>

using namespace std;


#ifndef _FACTORY_H
#define _FACTORY_H

class Product
{
public:
    virtual void print() = 0;
};

class ConcreteProductA : public Product
{
public:
    virtual void print()
    {
        cout<<"Product A"<<endl;
    }
};

class ConcreteProductB : public Product
{
public:
    void print()
    {
        cout<<"Product B"<<endl;
    }
};

class Creator
{
public:
    virtual Product* createProduct() = 0; 
};

class ConcreteCreatorA : public Creator
{
public:
   Product* createProduct()
    {
        return new ConcreteProductA;
    }
};

class ConcreteCreatorB : public Creator
{
public:
   Product* createProduct()
    {
        return new ConcreteProductB;
    }
};

#endif
