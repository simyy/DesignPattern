#include "flyweight.h"

int main(int argc, char** argv)
{
    string ext = "this is a ext";

    FlyweightFactory* factory = new FlyweightFactory();
    Flyweight* A = new ConcreteFlyweight("FlyweightA");
    Flyweight* B = new ConcreteFlyweight("FlyweightB");
    factory->addFlyweight(A);
    factory->addFlyweight(B);
    
    Flyweight* r = factory->getFlyweight("FlyweightA");
    r = factory->getFlyweight("FlyweightC");
    r->operation("ext C");
    r = factory->getFlyweight("FlyweightB");
    r->operation("ext B");

    return 0;
}
