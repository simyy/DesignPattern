#include <iostream>
#include <memory>
#include <string>

using namespace std;


#ifndef _STRATEGY_H
#define _STRATEGY_H

class Strategy
{
public:
    virtual string AlgorithmInterface(string str) = 0;
    virtual ~Strategy() {}
};

class ConcreteStrategyA : public Strategy
{
public:
    string AlgorithmInterface(string str)
    {
        return "A\t" + str;
    }
};

class ConcreteStrategyB : public Strategy
{
public:
    string AlgorithmInterface(string str)
    {
        return "B\t" + str;
    }
};

class Context
{
public:
    void setStrategy(auto_ptr<Strategy> strategy)
    {
        m_strategy = strategy;
    }
    string algorithm(string str)
    {
        return m_strategy->AlgorithmInterface(str);
    }
private:
    auto_ptr<Strategy> m_strategy;
};

#endif
