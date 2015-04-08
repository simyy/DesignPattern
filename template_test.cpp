#include "template.h"

int main(int argc, char** argv)
{
    ConcreteA* a = new ConcreteA();
    ConcreteB* b = new ConcreteB();

    a->run();
    b->run();

    delete a;
    delete b;

    return 0;
}
