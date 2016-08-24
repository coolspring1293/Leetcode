//
//  main.cpp
//  258. Add Digits
//
//  Created by Kieran Will on 8/24/16.
//  Copyright © 2016 liuw53. All rights reserved.
//
/*
 Given a non-negative integer num, repeatedly add all its digits until the result has only one digit.
 
 For example:
 
 Given num = 38, the process is like: 3 + 8 = 11, 1 + 1 = 2. Since 2 has only one digit, return it.
 
 Follow up:
 Could you do it without any loop/recursion in O(1) runtime?
 
*/
 
 

#include <iostream>

class Solution {
public:
    int addDigits(int num) {
        return 1 + (num - 1) % 9;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
