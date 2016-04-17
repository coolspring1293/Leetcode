//
//  main.cpp
//  326. Power of Three
//
//  Created by Kieran Will on 4/17/16.
//  Copyright © 2016 liuw53. All rights reserved.
//

#include <iostream>
#include <cmath>
/*
 Given an integer, write a function to determine if it is a power of three.
 
 Follow up:
 Could you do it without using any loop / recursion?
 

 */

class Solution {
public:
    bool isPowerOfThree(int n) {
        double a = log10(n) / log10(3);
        return (a - int(a) == 0) ? true : false;
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    std::cout << s.isPowerOfThree(27) << "\n";
    std::cout << "Hello, World!\n";
    return 0;
}
