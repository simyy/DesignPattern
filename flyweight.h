#include <map>
#include <iostream>
#include <string>
using namespace std;

#ifndef _FLYWEIGHT_H
#define _FLYWEIGHT_H

class Flyweight
{
public:
    Flyweight(string str):str(str) {}
    virtual void operation(const string ext) = 0;
    string getIntrinsicState()
    {
        return str;
    }
protected:
    string str;
};

class ConcreteFlyweight : public Flyweight 
{
public:
    ConcreteFlyweight(string str):Flyweight(str) {}
    void operation(const string ext)
    {
        cout<<Flyweight::getIntrinsicState()<<"\t"<<ext<<endl;
    }
};

class UnsharedConcreteFlyweight : public Flyweight
{
public:
    UnsharedConcreteFlyweight(string str):Flyweight(str) {}
    void operation(const string ext)
    {
        cout<<Flyweight::getIntrinsicState()<<"\t"<<ext<<endl;
    }
};

class FlyweightFactory
{
public:
    void addFlyweight(Flyweight* f)
    {
        this->mmap.insert(pair<string, Flyweight*>(f->getIntrinsicState(), f));
    }
    Flyweight* getFlyweight(const string str)
    {
        if (mmap.find(str) != mmap.end()) {
            cout<<"Find Flyweight "<<str<<endl;
            return mmap[str];
        }
        cout<<"new Flyweight "<<str<<endl;
        Flyweight* fly = new UnsharedConcreteFlyweight(str);
        this->mmap.insert(pair<string, Flyweight*>(str, fly));
        return mmap[str];
    }
    ~FlyweightFactory()
    {
        map<string, Flyweight*>::iterator iter = mmap.begin();
        for (;iter != mmap.end(); ++iter) {
            delete iter->second;
        }
    }
private:
   map<string, Flyweight*> mmap;  
};

#endif
