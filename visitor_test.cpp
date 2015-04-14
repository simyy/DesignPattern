#include "visitor.h"

int main(int argc, char** argv)
{
    Employee* eA = new ConcreteEmployee("A");
    Employee* eB = new ConcreteEmployee("B");

    ObjectStructure* os = new ObjectStructure();
    os->attach(eA);
    os->attach(eB);

    Visitor* vA = new ConcreteVistorA();
    Visitor* vB = new ConcreteVistorB();

    os->accept(vA);
    os->accept(vB);

    delete vA;
    delete vB;

    delete eA;
    delete eB;

    return 0;
}
