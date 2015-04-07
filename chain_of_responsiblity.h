#include <iostream>
#include <string.h>
using namespace std;

#ifndef _CHAIN_OF_RESPONSIBLITY_H
#define _CHAIN_OF_RESPONSIBLITY_H

class Handler
{
public:
    virtual void handler(char, string) = 0;
    void setSuccessor(Handler *successor) { this->successor = successor; }
protected:
    Handler* successor;
};

class HandlerA : public Handler
{
public:
    void handler(char i, string str) 
    { 
        if ( i == 'A')
            cout<<"A:\t"<<str<<endl; 
        else {
            cout<<"A:\t"<<"can't handle ... next"<<endl; 
            successor->handler(i, str);
        }
    }
};

class HandlerB : public Handler
{
public:
    void handler(char i, string str) 
    { 
        if ( i == 'B')
            cout<<"B:\t"<<str<<endl; 
        else {
            cout<<"B:\t"<<"can't handle ... next"<<endl; 
            successor->handler(i, str);
        }
    }
};
 
class HandlerALL : public Handler
{
public:
    void handler(char i, string str) 
    { 
        cout<<"B:\t"<<str<<endl; 
    }
};

#endif
