//
//  main.cpp
//  461. Hamming Distance
//
//  Created by Kieran Will on 10/11/17.
//  Copyright © 2017 liuw53. All rights reserved.
//

#include <iostream>
using namespace std;

class Solution {
public:
    int hammingDistance(int x, int y) {
        int res = x ^ y;
        int count = 0;
        for (int i = 0; i < 32; i++) {
            if ((res & 1) != 0)
                count++;
            res >>= 1;
        }
        return count;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
