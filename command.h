#include <iostream>
#include <vector>

using namespace std;

#ifndef _COMMAND_H
#define _COMMAND_H

class Receiver;

class Command
{
public:
    Command(Receiver* recv) { this->recv = recv; }
    virtual void Execute() = 0;
protected:
    Receiver* recv;
};

class Receiver
{
public:
    void cmdA() { cout<<"cmd A"<<endl; }
    void cmdB() { cout<<"cmd B"<<endl; }
};

class CommandA : public Command
{
public:
    CommandA(Receiver* recv):Command(recv) {}
    void Execute() {recv->cmdA();}
};

class CommandB : public Command
{
public:
    CommandB(Receiver* recv):Command(recv) {}
    void Execute() {recv->cmdB();}
};

class Invoker
{
public:
    void addCommand(Command* cmd) { cmd_list.push_back(cmd); }
    void notify()
    {
        vector<Command*>::iterator iter;
        for (iter = cmd_list.begin(); iter != cmd_list.end(); ++iter) {
            (*iter)->Execute();
        }
    }
private:
    vector<Command*> cmd_list;
};

#endif
