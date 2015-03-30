/*************************************************************************
	> File Name: observer.h
	> Author: 
	> Mail: 
	> Created Time: Sat 28 Mar 2015 09:21:41 PM PDT
 ************************************************************************/

#include <string>
#include <list>

using namespace std;

#ifndef _OBSERVER_H
#define _OBSERVER_H

class Observer {
public:
    Observer() {}
    virtual ~Observer() {}
    virtual void update() {}
};

class Subject {
public:
    Subject() {}
    virtual ~Subject() {}
    void attach(Observer *observer) {m_observers.push_back(observer);}
    void remove(Observer *observer) {m_observers.remove(observer);}
    void notify() 
    {
        list<Observer*>::iterator iter = m_observers.begin();
        for(; iter != m_observers.end(); iter++) {
            (*iter)->update();
        }
    }
    virtual void setStatus(string str) {m_status = str;}
    virtual string getStatus() {return m_status;}
private:
    list<Observer*> m_observers;
protected:
    string m_status;
};

#endif
