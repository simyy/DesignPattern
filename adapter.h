#include <iostream>

using namespace std;

#ifndef _ADAPTER_H
#define _ADAPTER_H

class Target
{
public:
    virtual void Request() = 0;
};

class Adaptee
{
public:
    void request()
    {
        cout<<"this is Adaptee::request"<<endl;
    }
};

class ClassAdapter : public Target, Adaptee
{
public:
    void Request()
    {
        Adaptee::request();
    }
};

class ObjAdapter : public Target
{
public:
    ObjAdapter(Adaptee* a):adpt(a) {}
    void Request()
    {
        adpt->request();
    }
private:
    Adaptee* adpt;
};


#endif
