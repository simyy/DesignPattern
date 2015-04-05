#include <iostream>
#include <string.h>
#include <vector>

using namespace std;

#ifndef _MEDIATOR_H
#define _MEDIATOR_H

class Mediator;

class Colleage
{
public:
    Colleage(Mediator* m):mediator(m) {}
    virtual void sendMsg(string str) = 0;
    virtual void recvMsg(string str) = 0; 
protected:
    Mediator* mediator;
};

class Mediator
{
public:
    Mediator() {}
    void addColleage(Colleage* coll) { colls.push_back(coll); }
    virtual void notify(string, Colleage*) = 0;
protected:
    vector<Colleage*> colls;
};

class ConcreteMediator : public Mediator
{
public:
    void notify(string msg, Colleage* sender)
    {
        vector<Colleage*>::iterator iter;
        for (iter = colls.begin(); iter != colls.end(); ++iter) {
            if (*iter != sender)
                (*iter)->recvMsg(msg);
        }
    }
};

class ConcreteColleageA : public Colleage
{
public:
    ConcreteColleageA(Mediator* m):Colleage(m) {}
    void sendMsg(string msg) { mediator->notify(msg, this); }
    void recvMsg(string msg) { cout<<"A recv:\t"<<msg<<endl; }
};

class ConcreteColleageB : public Colleage
{
public:
    ConcreteColleageB(Mediator* m):Colleage(m) {}
    void sendMsg(string msg) { mediator->notify(msg, this); }
    void recvMsg(string msg) { cout<<"B recv:\t"<<msg<<endl; }
};

#endif
