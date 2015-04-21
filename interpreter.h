#include <iostream>
#include <string.h>
#include <vector>
using namespace std;

#ifndef _INTERPERTER_H
#define _INTERPERTER_H

class Context
{
public:
    Context(char* s){
        for (char* p = s; p != '\0'; ++p)
            v.push_back(*p);
    }
    void add(char* s) { v.push_back(s); }
    char* get(int i) 
    {
        if (i >= v.size()) 
            return NULL;
        else
            return v[i];
    }
    void set(int i, int value) { v[i] = value; }
    int get_len() { return v.size(); }
private:
    vector<char*> v;
};

class AbstractExpression
{
public:
    virtual void Interpret(Context* c) = 0;
protected:
    int i;
};

class TerminalExpression : public AbstractExpression
{
public:
    TerminalExpression(int i):AbstractExpression(i) {}
    void Interpret(Context* c)
    {
        char* p = c->get(i);
        if ('a' == *p)
            ct.set(i, 1);
        else if ('b' == *p)
            ct.set(i, 2);
        else
            ct.set(i, 0);
    }

};

class NotTerminalExpression : public AbstractExpression
{
public:
    NotTerminalExpression(int i):AbstractExpression(i) {}
    void Interpret(Context* c)
    {
        char* p = c->get(i);
        if ('+' == *p) 
            return (*(c->get(i-1))) + (*(c->get(i+1)))
        else if ('-' == *p)
            return (*(c->get(i-1))) - (*(c->get(i+1)))
        else if ('*' == *p)
            return (*(c->get(i-1))) * (*(c->get(i+1)))
        else if ('/' == *p)
            return (*(c->get(i-1))) / (*(c->get(i+1)))
    }
};

#endif
