/*************************************************************************
	> File Name: singleton_test.cpp
	> Author: 
	> Mail: 
	> Created Time: Sat 28 Mar 2015 11:16:20 PM PDT
 ************************************************************************/

#include "singleton.h"

#include<iostream>
using namespace std;


int main(int argc, char** argv)
{
    Singleton *singleton = Singleton::Instance(); 

    return 0;
}
