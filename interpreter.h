#include <iostream>
#include <string.h>
#include <stack>
#include <vector>
using namespace std;

#ifndef _INTERPERTER_H
#define _INTERPERTER_H

class Context
{
public:
    Context(char* s){
        int len = sizeof(s);
        for (int i = 0; i <= len; i++)
            v.push_back(*(s+i));
    }
    char get(int i) 
    {
        if (i >= v.size()) 
            return 'z';
        else
            return v[i];
    }
    int get_len() { return v.size(); }
private:
    vector<char> v;
};

class AbstractExpression
{
public:
    virtual int Interpret(Context* c) = 0;
};

class TerminalExpression : public AbstractExpression
{
public:
    TerminalExpression(int i) { this->i = i; }
    int Interpret(Context* c)
    {
        char p = c->get(i);
        if ('a' == p)
            return 1; 
        else if ('b' == p)
            return 2;
        else
            return 0;
    }
private:
    int i;
};

class NotTerminalExpression : public AbstractExpression
{
public:
    NotTerminalExpression(int i, AbstractExpression* left, AbstractExpression* right) 
    {
        this->i = i;
        this->left = left;
        this->right = right;
    }

    int Interpret(Context* c)
    {
        char p = c->get(i);
        if ('+' == p) 
            return left->Interpret(c) + right->Interpret(c); 
        else if ('-' == p)
            return left->Interpret(c) - right->Interpret(c); 
        else if ('*' == p)
            return left->Interpret(c) * right->Interpret(c); 
        else if ('/' == p)
            return left->Interpret(c) / right->Interpret(c); 
    }
private:
    AbstractExpression* left;
    AbstractExpression* right;
    int i;
};

#endif
