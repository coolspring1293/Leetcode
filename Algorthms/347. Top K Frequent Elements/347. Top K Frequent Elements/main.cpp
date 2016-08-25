//
//  main.cpp
//  347. Top K Frequent Elements
//
//  Created by Kieran Will on 8/24/16.
//  Copyright © 2016 liuw53. All rights reserved.
//

#include <iostream>
#include <vector>
#include <map>
using namespace std;

//347. Top K Frequent Elements  QuestionEditorial Solution  My Submissions
//Total Accepted: 26905
//Total Submissions: 61341
//Difficulty: Medium
//Given a non-empty array of integers, return the k most frequent elements.
//
//For example,
//Given [1,1,1,2,2,3] and k = 2, return [1,2].
//
//Note:
//You may assume k is always valid, 1 ≤ k ≤ number of unique elements.
//Your algorithm's time complexity must be better than O(n log n), where n is the array's size.
//Subscribe to see which companies asked this question
//
//Hide Tags Hash Table Heap
//Hide Similar Problems (M) Word Frequency (M) Kth Largest Element in an Array


// 此函数主要实现，将次数放在第一的位置，主要用于按照次数进行排序
class MAP1 {
public:
    int time;
    int elem;
    MAP1(int _time, int _elem) {
        time = _time;
        elem = _elem;
    }
    bool operator < (const MAP1& obj)const {
        return time > obj.time;
    }
};
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        size_t n = nums.size();
        map<int, int> mp;
        map<int, int>::iterator it;
        // 统计nums中每个元素出现的次数
        for (int i = 0; i < n; i ++) {
            if (mp.find(nums[i]) == mp.end())
                mp[nums[i]] = 1;
            else
                mp[nums[i]] += 1;
        }
        // 将mp中元素存放在Node数组中
        vector<MAP1> p;
        for (it = mp.begin(); it != mp.end(); it ++) {
            p.push_back(MAP1(it->second, it->first));}
        
        // 对Node中的数组进行排序，即按照出现的次数进行排序
        sort(p.begin(), p.end());
        // 返回最终出现多于k次的元素
        vector<int> result;
        for (int i = 0; i < k; i ++) {
            result.push_back(p[i].elem);
        }
        return result;
    }
};


int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
