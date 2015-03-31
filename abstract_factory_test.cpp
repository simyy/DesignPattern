#include "abstract_factory.h"

int main(int argc, char** argv)
{
    Creator* A = new ConcreteCreatorA();
    Creator* B = new ConcreteCreatorB();

    A->createProduct1()->print();
    A->createProduct2()->print();
    B->createProduct1()->print();
    B->createProduct2()->print();

    return 0;
}
