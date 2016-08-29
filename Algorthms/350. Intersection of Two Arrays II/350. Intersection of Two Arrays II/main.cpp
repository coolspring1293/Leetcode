//
//  main.cpp
//  350. Intersection of Two Arrays II
//
//  Created by Kieran Will on 29/08/2016.
//  Copyright © 2016 liuw53. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> v;
        size_t len2 = nums2.size();
        for(size_t i = 0; i < len2; i ++) {
            for(int j = 0; j < nums1.size(); j ++) {
                if(nums2[i] == nums1[j]) {
                    v.push_back(nums2[i]);
                    nums1.erase(nums1.begin()+j);
                    break;
                }
            }
        }
        return v;
    }
};
int main(int argc, const char * argv[]) {
    vector<int> v1, v2, v3;
    v1.push_back(1);
    v1.push_back(2);
    v1.push_back(2);
    v1.push_back(1);
    v2.push_back(2);
    v2.push_back(2);

    Solution s;
    v3 = s.intersect(v1, v2);
    
    for (int i = 0; i < v3.size(); ++ i) {
        cout << v3[i] << "\t";
    }
    
    
    
    
    return 0;
}
