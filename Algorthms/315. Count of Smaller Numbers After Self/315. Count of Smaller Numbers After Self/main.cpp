//
//  main.cpp
//  315. Count of Smaller Numbers After Self
//
//  Created by Kieran Will on 8/9/16.
//  Copyright © 2016 liuw53. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    // Time Limit Exceeded
    vector<int> countSmaller_2(vector<int>& nums) {
        vector<int> res;
        for (int i = 0; i < nums.size(); ++ i) {
            int tmp = 0;
            for (int j = i + 1; j < nums.size(); ++ j) {
                if (nums[i] > nums[j]) tmp ++;
             }
            res.push_back(tmp);
        }
        return res;
        
    }
    
    class BT {
    public:
        int _val, _count;
        BT *_l, *_r;
        BT (int v, int c = 0, BT *l = NULL, BT *r = NULL) :
            _val(v), _count(c), _l(l), _r(r) {}
    };
    
    void insert(BT* &root, int num, int &ret) {
        if (root == NULL) {
            root = new BT(num); return;
        }
        if (num > root->_val) {
            ret += (root->_count + 1);
            insert(root->_r, num, ret);
        } else {
            root->_count ++;
            insert(root->_l, num, ret);
        }
        
    }
    
    
    vector<int> countSmaller(vector<int>& nums) {
        vector<int> res;
        if (nums.empty()) return res;
        res.resize(nums.size(), 0);
        BT *root = new BT(nums[nums.size()-1]);
        for (int i = nums.size() - 2; i >= 0; -- i) {
            insert(root, nums[i], res[i]);
        }
        return res;
        
    }
};


int main(int argc, const char * argv[]) {
    Solution s = *new Solution();
    vector<int> v;
    v.push_back(5);
    v.push_back(2);
    v.push_back(6);
    v.push_back(1);

    vector<int> t = s.countSmaller(v);
    
    for (int i = 0; i < t.size(); ++ i) {
        cout << t[i] << "\t";
    }
    
    return 0;
}
