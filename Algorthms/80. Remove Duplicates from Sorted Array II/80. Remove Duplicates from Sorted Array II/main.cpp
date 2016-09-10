//
//  main.cpp
//  80. Remove Duplicates from Sorted Array II
//
//  Created by Kieran Will on 9/11/16.
//  Copyright © 2016 liuw53. All rights reserved.
//

#include <iostream>
#include <vector>
#define  INF 0x3f3f3f3f

using namespace std;


// 黑夜给了我黑色的眼睛，我却用它来写代码
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int cur_count = 0;
        
        vector<int> new_nums;
        if (!nums.empty()) {
            new_nums.push_back(nums[0]);
        } else {
            return 0;
        }
        int tmp = nums[0];
        for (int i = 1; i < nums.size(); ++ i) {
            cout << "LOOP:" << i << "\tNUM = " << nums[i] << "\tTMP = " << tmp << "\tCUR_COUNT = " << cur_count << "\n";
            if(tmp == nums[i]) {
                cur_count ++;
            } else {
                cur_count = 0;
            }
            tmp = nums[i];
            if (cur_count < 2) {
                new_nums.push_back(nums[i]);
            }
            
        }
        nums = new_nums;
        return static_cast<int>(new_nums.size());
    }
};


int main(int argc, const char * argv[]) {
    //vector<int> v {1, 1, 1, 1, 1, 2, 2, 2, 2, 3, 3, 3, 3, 3 };
    vector<int> v {1, 1, 2, 3, 4 };
    Solution s;
    cout << s.removeDuplicates(v) << ": ";
    for (int i = 0; i < v.size(); ++ i) {
        cout << v[i] << "\t";
    }
    cout << "\n";
    return 0;
}
