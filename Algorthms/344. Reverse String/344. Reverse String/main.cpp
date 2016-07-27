//
//  main.cpp
//  344. Reverse String
//
//  Created by Kieran Will on 7/27/16.
//  Copyright © 2016 liuw53. All rights reserved.
//

#include <iostream>
#include <stack>
using namespace std;


stack<char> h;
class Solution {
public:
    string reverseString(string s) {
        string f = "";
        for (int i = 0; i < s.length(); ++ i) {
            h.push(s[i]);
        }
        
        while(!h.empty()){
            f = f + h.top();
            h.pop();
        }
        return f;
    }
    // another method
    string reverseString2(string s) {
        string ret;
        if(s.empty()) return ret;
        string::const_iterator tail = s.cend();
        do
        {
            tail --;
            ret.push_back(*tail);
        }while (tail != s.cbegin());
        return ret;
    }
};



int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
