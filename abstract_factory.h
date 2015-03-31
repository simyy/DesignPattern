#include <iostream>

using namespace std;


#ifndef _FACTORY_H
#define _FACTORY_H

class Product1
{
public:
    virtual void print() = 0;
};

class Product2
{
public:
    virtual void print() = 0;
};

class ConcreteProductA1 : public Product1
{
public:
    virtual void print()
    {
        cout<<"A Product1"<<endl;
    }
};

class ConcreteProductA2 : public Product2
{
public:
    void print()
    {
        cout<<"A Product2"<<endl;
    }
};

class ConcreteProductB1 : public Product1
{
public:
    void print()
    {
        cout<<"B Product1"<<endl;
    }
};

class ConcreteProductB2 : public Product2
{
public:
    void print()
    {
        cout<<"B Product2"<<endl;
    }
};

class Creator
{
public:
    virtual Product1* createProduct1() = 0; 
    virtual Product2* createProduct2() = 0; 
};

class ConcreteCreatorA : public Creator
{
public:
    Product1* createProduct1()
    {
        return new ConcreteProductA1;
    }
    Product2* createProduct2()
    {
        return new ConcreteProductA2;
    }
};

class ConcreteCreatorB : public Creator
{
public:
    Product1* createProduct1()
    {
        return new ConcreteProductB1;
    }
    Product2* createProduct2()
    {
        return new ConcreteProductB2;
    }
};

#endif
