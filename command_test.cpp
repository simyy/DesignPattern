#include "command.h"

int main(int argc, char** argv)
{
    Receiver* recv = new Receiver();
    Invoker* invk = new Invoker();
    Command* cmdA = new CommandA(recv);
    Command* cmdB = new CommandB(recv);

    invk->addCommand(cmdA);
    invk->addCommand(cmdB);
    invk->notify();

    return 0;
}
