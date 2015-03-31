#include "Iterator.h"

int main(int argc, char** argv)
{
    Aggregate<int> *aggr = new ConcreteAggregate<int>();

    Iterator<int>* it = aggr->createIterator();

    for (it->first(); !it->isDone(); it->next()) {
        cout<<*(it->currentItem())<<endl;
    }

    delete it;
    delete aggr;

    return 0;
}
