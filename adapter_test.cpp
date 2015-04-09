#include "adapter.h"

int main(int argc, char** argv)
{
    Target* t = new ClassAdapter();
    
    t->Request();
    delete t;

    Adaptee* a = new Adaptee();
    Target* tt = new ObjAdapter(a);
    
    tt->Request();
    delete a;
    delete tt;

    return 0;
}
