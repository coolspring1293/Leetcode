//
//  main.cpp
//  Google 2016 面试题 : 数组补丁
//
//  Created by Kieran Will on 10/21/17.
//  Copyright © 2017 liuw53. All rights reserved.
//


#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;



class Solution {
    
public:
    int minPatches(std::vector<int> num, int n) {
        sort(num.begin(), num.end());
        int miss = 0;
        int index = 0;
        int upper = 1;
        
        while (upper <= n) {
            if (index < num.size() and num[index] <= upper) {
                upper += num[index];
                index ++;
            } else {
//               cout << upper <<"\t";
                miss ++;
                upper *= 2;
            }
        }
        return miss;
    }
};

int main(int argc, const char * argv[]) {

    Solution s = * new Solution();
    
    vector<int> x;
    
    x.push_back(1);
    x.push_back(9);
    x.push_back(4);
    int n = 7;
    std::cout << "\n" << s.minPatches(x, n) << "\n";
    
    
    
    
    return 0;
}
