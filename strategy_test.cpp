#include "strategy.h"

int main(int argc, char** argv)
{
    string str = "hello!";
    
    Context* ct = new Context;

    auto_ptr<Strategy> stA(new ConcreteStrategyA());
    auto_ptr<Strategy> stB(new ConcreteStrategyB());

    ct->setStrategy(stA);
    cout<<ct->algorithm(str)<<endl;

    ct->setStrategy(stB);
    cout<<ct->algorithm(str)<<endl;

    delete ct;

    return 0;
}
