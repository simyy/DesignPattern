/*************************************************************************
	> File Name: observer_test.cpp
	> Author: 
	> Mail: 
	> Created Time: Sat 28 Mar 2015 09:30:02 PM PDT
 ************************************************************************/

#include "observer.h"

#include <iostream>
#include <string>
using namespace std;

class news : public Subject 
{
public:
    news(string type):m_type(type) {}
    ~news() {}
    void setStatus(string content)
    {
        m_status = m_type+"\tnews:"+content;
    }
private:
    string m_type; 
};

class media : public Observer
{
public:
    media(string name, Subject* subject):m_name(name),m_subject(subject) {}
    ~media() {}
    void update()
    {
        string status = m_subject->getStatus();
        cout<<"media "+m_name+":\t"<<status<<endl;
    }
private:
    string m_name;
    Subject *m_subject;
};

int main(int argc, char** argv)
{

    Subject* m_news = new news("sport");
    Observer* A = new media("media A", m_news);
    Observer* B = new media("media B", m_news);
    Observer* C = new media("media C", m_news);

    m_news->attach(A);
    m_news->attach(B);
    m_news->attach(C);

    m_news->setStatus("This is a sport news!");
    m_news->notify();

    delete m_news;
    delete A;
    delete B;
    delete C;

    return 0;
}
