#include <iostream>
using namespace std;

#ifndef _TEMPALATE_H
#define _TEMPALATE_H

class Abstract 
{
public:
    void run()
    {
        first();
        sencond();
    }
    virtual void first() = 0;
    virtual void sencond() = 0;
};

class ConcreteA : public Abstract
{
public:
    void first() {
        cout<<"A first"<<endl;
    }

    void sencond() {
        cout<<"A sencond"<<endl;
    }

};

class ConcreteB : public Abstract
{
public:
    void first() {
        cout<<"B first"<<endl;
    }

    void sencond() {
        cout<<"B sencond"<<endl;
    }

};

#endif
