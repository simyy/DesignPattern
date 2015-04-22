#include "proxy.h"

int main(int argc, char** argv)
{
    Subject* s = new RealSubject();
    Proxy* p = new Proxy(s);
    p->request();

    delete p;
    delete s;
    return 0;
}
