#include "decorator.h"

int main(int argc, char** argv)
{
    Component* c = new ConcreteComponent();
    c->show();
    Decorator* A = new DecoratorA(c);
    A->show();
    Decorator* B = new DecoratorB(A);
    B->show();

    delete B;
    delete A;
    delete c;

    return 0;
}
