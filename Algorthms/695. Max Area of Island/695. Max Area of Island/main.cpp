//
//  main.cpp
//  695. Max Area of Island
//
//  Created by Kieran Will on 10/11/17.
//  Copyright © 2017 liuw53. All rights reserved.
//

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int res = 0;
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid.size(); j++){
                if(grid[i][j] == 1) res = max(res, curser(grid, i, j));
            }
        }
        return res;
    }
    
private:
    int curser(vector<vector<int>>& grid, int r, int c){
        if(r < 0 || r >= grid.size() || c < 0 || c >= grid[0].size()) return 0;
        int res = 0;
        if(grid[r][c] == 1){
            //去除已经扫描过的1
            grid[r][c] = 0;
            res = 1 + curser(grid, r-1, c)
                + curser(grid, r+1, c)
                + curser(grid, r, c-1)
                + curser(grid, r, c+1);
        }
        return res;
    }
};




int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
