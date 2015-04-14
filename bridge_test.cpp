#include "bridge.h"

int main(int argc, char** argv)
{
    Implementor* imA = new ConcreteImplementorA();
    Implementor* imB = new ConcreteImplementorB();
    
    Abstractor* a = new ConcreteAbstractor(imA);
    a->operation();

    Abstractor* b = new ConcreteAbstractor(imB);
    b->operation();

    delete b;
    delete a;
    delete imB;
    delete imA;

    return 0;
}
