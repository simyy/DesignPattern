#include <iostream>
using namespace std;

#ifndef _PROXY_H
#define _PROXY_H

class Subject
{
public:
    virtual void request() = 0;
};

class RealSubject : public Subject
{
public:
    void request() { cout<<"RealSubject request"<<endl; }
};

class Proxy : public Subject
{
public:
    Proxy(Subject* s):s(s) {}
    void request() 
    { 
        cout<<"Proxy request"<<endl; 
        s->request();
    }
private:
    Subject* s;
};

#endif
