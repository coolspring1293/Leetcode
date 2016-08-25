//
//  main.cpp
//  268. Missing Number
//
//  Created by Kieran Will on 8/25/16.
//  Copyright © 2016 liuw53. All rights reserved.
//
/*
 Missing Number
 
 Given an array containing n distinct numbers taken from 0, 1, 2, ..., n, find the one that is missing from the array.
 
 For example,
 Given nums = [0, 1, 3] return 2.
 
 Note:
 Your algorithm should run in linear runtime complexity. Could you implement it using only constant extra space complexity?
 
 Credits:
 Special thanks to @jianchao.li.fighter for adding this problem and creating all test cases.*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        size_t n = nums.size();
        size_t expect = (n+1) * n / 2;
        for(size_t i = 0; i < n; i ++)
            expect -= nums[i];
        return expect;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
