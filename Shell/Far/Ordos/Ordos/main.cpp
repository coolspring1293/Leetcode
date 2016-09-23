//
//  main.cpp
//  Ordos
//
//  Created by Kieran Will on 9/18/16.
//  Copyright © 2016 liuw53. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>
using namespace std;


class Person {
public:
    string _name;
    double _amt;
    
    Person(string name) {
        this->_name = name;
        this->_amt  = 0.0;
    }
    
    void print() const {
        cout << _name << " should get " << _amt << " ￥ in total." << "\n";
    }
    
    
};

enum ItemType { fee, diet, euth };

class Item {
public:
    string _name;
    ItemType _type;
    Person _chendan;
    vector<Person> _xiaofei;
    
    
    
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
