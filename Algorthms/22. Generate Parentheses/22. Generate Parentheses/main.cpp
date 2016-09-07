//
//  main.cpp
//  22. Generate Parentheses
//
//  Created by Kieran Will on 9/7/16.
//  Copyright © 2016 liuw53. All rights reserved.
//

#include <iostream>
#include <set>
#include <vector>

using namespace std;




class Solution {
public:
    vector<string> generateParenthesis(int n) {
        if (n < 1) {
            vector<string> res_vec;
            return res_vec;
        }
        else if (n == 1) {
            vector<string> res_vec;
            res_vec.push_back("()");
            return res_vec;
        }else{
            vector<string> pre_vec = generateParenthesis(n - 1);
            set<string> filter_set;
            vector<string> res_vec;
            for(int i = 0;i < pre_vec.size();i ++) {
                string pre_str = pre_vec[i];
                int pre_str_len = (int)pre_str.length();
                for(int j = 0;j <= pre_str_len;j ++) {
                    string now_str = pre_str.substr(0, j) + "()" + pre_str.substr(j, pre_str_len - j);
                    if(filter_set.find(now_str) == filter_set.end()) {
                        filter_set.insert(now_str);
                        res_vec.push_back(now_str);
                    }
                }
                string now_str = pre_str+"()";
                if(filter_set.find(now_str)==filter_set.end()){
                    filter_set.insert(now_str);
                    res_vec.push_back(now_str);
                }
            }
            return res_vec;
        }
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    
    for (int i = 0; i < 10; ++ i) {
        vector<string> v = s.generateParenthesis(i);
        for (int k = 0; k < v.size(); ++ k) {
            cout << v[k] << "\n";
        }
        cout << "============\n\n";
    }
    return 0;
}
