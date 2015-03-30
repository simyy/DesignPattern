/*************************************************************************
	> File Name: sington.h
	> Author: 
	> Mail: 
	> Created Time: Sat 28 Mar 2015 10:40:50 PM PDT
 ************************************************************************/

#include <iostream>
#include <memory>
using namespace std;

#ifndef _SINGTON_H
#define _SINGTON_H

class Singleton
{
public:
    ~Singleton() {cout<<"delete singleton"<<endl;}

    static Singleton* Instance()
    {
        if (!m_instance.get())
            m_instance = auto_ptr<Singleton>(new Singleton);
        return m_instance.get();
    }

protected:

private:
    Singleton() {cout<<"create singleton"<<endl;}
    Singleton(const Singleton &other);
    Singleton &operator=(const Singleton &other);
    static auto_ptr<Singleton> m_instance;
};

auto_ptr<Singleton> Singleton::m_instance;

#endif
