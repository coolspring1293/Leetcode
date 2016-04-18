//
//  main.cpp
//  326. Power of Three
//
//  Created by Kieran Will on 4/17/16.
//  Copyright © 2016 liuw53. All rights reserved.
//

#include <iostream>
#include <cmath>
#include <cfloat>
#include <stdio.h>
#include <string>
/*
 Given an integer, write a function to determine if it is a power of three.
 
 Follow up:
 Could you do it without using any loop / recursion?
 

 */
const double EPSINON = 1E-14;
char buf[100]={'\0'};
class Solution {
public:
    bool isPowerOfThree(int n) {
        double a = log(n) / log(3);
        
        sprintf(buf,"%.100lf",a);
        std::cout << buf << "\n";
        std::cout << "org:   "<< a<< "_________\n";
        std::cout << "int:   "<< int(a)<< "_________\n";
        std::cout << "floor: "<< floor(a)<< "_________\n";
        std::cout << "ceil:  "<< ceil(a)<< "_________\n";
        std::cout << "round:  "<< round(a)<< "_________\n";
        return (std::abs(a - round(a)) < EPSINON);
    }
    
    bool isPowerOfThree2(int n) {
        double a = log10(n) / log10(3);
        sprintf(buf,"%.100lf",a);
        std::cout << buf << "\n";
        std::cout << "org:   "<< a<< "_________\n";
        std::cout << "int:   "<< int(a)<< "_________\n";
        std::cout << "floor: "<< floor(a)<< "_________\n";
        std::cout << "ceil:  "<< ceil(a)<< "_________\n";
        std::cout << "round:  "<< round(a)<< "_________\n";
        return (a - int(a) == 0) ;
    }
};

int main(int argc, const char * argv[]) {
    double x = log(3), y = log10(3);
    
    sprintf(buf,"%.100lf",x);
    std::cout << "x = "<< buf << "\n";
    sprintf(buf,"%.100lf",y);
    std::cout<< "y = "<< buf << "\n";

    
    Solution s;
    std::cout << s.isPowerOfThree2(14348908) << "\n";
    std::cout << s.isPowerOfThree(14348908) << "\n";
    std::cout << "Hello, World!\n";
    
    std::cout << DBL_MAX << "\t" << DBL_MIN;
    return 0;
}
