#include "mediator.h"

int main(int argc, char** argv)
{
    Mediator* mediator = new ConcreteMediator();

    Colleage* A = new ConcreteColleageA(mediator);
    Colleage* B = new ConcreteColleageB(mediator);

    mediator->addColleage(A);
    mediator->addColleage(B);

    A->sendMsg("hello B");
    B->sendMsg("hello A");

    return 0;
}
