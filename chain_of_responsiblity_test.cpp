#include "chain_of_responsiblity.h"

int main(int argc, char** argv)
{
    Handler* hA = new HandlerA();
    Handler* hB = new HandlerB();
    Handler* hAll = new HandlerALL();

    hA->setSuccessor(hB);
    hB->setSuccessor(hAll);

    hA->handler('A', "hello");
    cout<<endl;
    hA->handler('B', "hello");
    cout<<endl;
    hA->handler('C', "hello");

    delete hAll;
    delete hB;
    delete hA;

    return 0;
}
