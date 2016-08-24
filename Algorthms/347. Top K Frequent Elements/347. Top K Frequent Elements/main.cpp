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

//class Solution {
//public:
//    vector<int> topKFrequent(vector<int>& nums, int k) {
//        unordered_map<int, int> hash;
//        priority_queue<pair<int,int>> heap;
//        vector<int> ret;
//        
//        for(int num:nums)
//            hash[num]++;
//        
//        for(auto it:hash)
//            heap.push(make_pair(it.second, it.first));
//        
//        for(int i=0; i<k; ++i) {
//            ret.push_back(heap.top().second);
//            heap.pop();
//        }
//        
//        return ret;
//    }
//};

// 此函数主要实现，将次数放在第一的位置，主要用于按照次数进行排序
class MAP1
{
public:
    int time;
    int elem;
    MAP1(int _time, int _elem)
    {
        time = _time;
        elem = _elem;
    }
    bool operator < (const MAP1& obj)const
    {
        return time > obj.time;
    }
};
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k)
    {
        int n = nums.size();
        map<int, int> mp;
        map<int, int>::iterator it;
        // 统计nums中每个元素出现的次数
        for (int i = 0; i < n; i++)
        {
            if (mp.find(nums[i]) == mp.end())
                mp[nums[i]] = 1;
            else
                mp[nums[i]] += 1;
        }
        // 将mp中元素存放在Node数组中
        vector<MAP1> p;
        for (it = mp.begin(); it != mp.end(); it++)
            p.push_back(MAP1(it->second, it->first));
        // 对Node中的数组进行排序，即按照出现的次数进行排序
        sort(p.begin(), p.end());
        // 返回最终出现多于k次的元素
        vector<int> result;
        for (int i = 0; i < k; i++)
            result.push_back(p[i].elem);
        return result;
    }
};


int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
