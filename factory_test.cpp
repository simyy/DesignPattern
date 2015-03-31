#include "factory.h"

int main(int argc, char** argv)
{
    Creator* A = new ConcreteCreatorA();
    Creator* B = new ConcreteCreatorB();

    A->createProduct()->print();
    B->createProduct()->print();

    return 0;
}
