#include <iostream>
#include <vector>

using namespace std;

#ifndef _ITERATOR_H
#define _ITERATOR_H

template<class Item>
class Iterator 
{
public:
    virtual void first() = 0;
    virtual void next() = 0;
    virtual Item* currentItem() = 0;
    virtual bool isDone() = 0;
    virtual ~Iterator() {}
};

template<class Item>
class Aggregate
{
public:
    virtual Iterator<Item>* createIterator() = 0;
    virtual ~Aggregate() {}
};

template<class Item>
class ConcreteIterator;

template<class Item>
class ConcreteAggregate : public Aggregate <Item>
{
public:
    ConcreteAggregate()
    {
        data.push_back(1);
        data.push_back(2);
        data.push_back(3);
    }
    ~ConcreteAggregate()
    {
        data.clear();
    }
    virtual Iterator<Item>* createIterator()
    {
        return  new ConcreteIterator<Item>(this);
    }
    int length()
    {
        return data.size();
    }
    Item& operator[](int i)
    {
        return data[i];
    }
private:
    vector<Item> data;
};


template<class Item>
class ConcreteIterator : public Iterator <Item>
{
public:
    ConcreteIterator(ConcreteAggregate<Item>* a):ca(a),cur(0){}
    virtual void first()
    {
        cur=0;
    }
    virtual void next()
    {
        if (cur < ca->length())
            cur++;
    }
    virtual Item* currentItem()
    {
        if(cur < ca->length())
            return &(*ca)[cur];
        else
            return NULL;
    }
    virtual bool isDone()
    {
        return (cur >= ca->length());
    }
private:
    ConcreteAggregate<Item>* ca;
    int cur;
};

#endif
