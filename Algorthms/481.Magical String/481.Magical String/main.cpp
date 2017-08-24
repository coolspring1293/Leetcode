//
//  main.cpp
//  481.Magical String
//
//  Created by Kieran Will on 8/24/17.
//  Copyright © 2017 liuw53. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int magicalString(int n) {
        if (!n) return 0;
        vector<int> str{1};
        int con = 0, occur = 0;
        vector<int> store;
        store.push_back(0);
        store.push_back(0);
        store.push_back(0);
        while (con < n) {
            if (str[occur] == 1) {
                str.push_back(str[con] == 1? 2: 1);
                ++con;
                ++occur;
                store[0] = 0; store[1] = 0; store[2] = 0;
            } else {
                int cur = str[con];
              //  cout << " |" << cur << "| ";
                if (store[cur] < 1) {
                    ++store[cur];
                    str.push_back(cur);
                    ++con;
                } else {
                    store[cur] = 0;
                    str.push_back(cur == 1? 2: 1);
                    ++con;
                    ++occur;
                }
            }
           string s = "";
            for (int i = 0; i < str.size(); ++ i) {
                s += (str[i] + '0');
            }
           // cout << s << "\t";
            
        }

        // cout << "\n\n";
        return count_if(str.begin(), str.begin() + n, [](int& element){return element == 1;});
        
    }
};


int main(int argc, const char * argv[]) {
    Solution s = * new Solution();
    
    cout << s.magicalString(99999) << "\n";
    cout << s.magicalString(10) << "\n";
    
    return 0;
}
