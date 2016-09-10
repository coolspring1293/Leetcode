//
//  main.cpp
//  Alibaba-2016
//
//  Created by Kieran Will on 9/9/16.
//  Copyright © 2016 liuw53. All rights reserved.
//

#include <iostream>

using namespace std;
/*
class A
{
public:
    A ():m_iVal(0){test();cout << "A constructor" << "\n";}
    virtual void func() { std::cout<<m_iVal<<' ';}
    void test(){func(); cout << "A test" << "\n";}
public:
    int m_iVal;
};
class B : public A
{
public:
    B(){test(); cout << "B constructor" << "\n"; }
    virtual void func()
    {
        ++m_iVal;
        std::cout<<m_iVal<<' ';
    }
};
int main(int argc ,char* argv[])
{
    A*p = new B;
    p->test();
    return 0;
}*/

void func(const int& v1, const int& v2)
{
    std::cout << v1 << ' ';
    std::cout << v2 << ' ';
}

class A
{
public:
    virtual void func(int val = 1)
    { std::cout<<"A->"<<val <<std::endl;}
    virtual void test()
    { func();}
};
class B : public A
{
public:
    void func(int val=0)
    {std::cout<<"B->"<<val <<std::endl;}
};
int main_t(int argc ,char* argv[])
{
    B*p = new B;
    p->test();
    return 0;
}


int main (int argc, char* argv[])
{
    int i=0;
    func(++i,i++);
    return 0;
}
