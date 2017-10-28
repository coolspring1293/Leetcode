//
//  main.cpp
//  Google 2016 面试题5 : 岛屿计数2
//
//  Created by Kieran Will on 10/28/17.
//  Copyright © 2017 liuw53. All rights reserved.
//
/***
 给出两个节点，判断它们是否连通，如果连通，不需要给出具体的路径
 给出两个节点，判断它们是否连通，如果连通，需要给出具体的路径
 
 就上面两种问题而言，虽然只有是否能够给出具体路径的区别，但是这个区别导致了选择算法的不同，本文主要介绍的是第一种情况，即不需要给出具体路径的Union-Find算法，而第二种情况可以使用基于DFS的算法。
 
 */

#include <iostream>
#include <list>
#include <vector>

using namespace std;

const int POS_MAX = 2; // 坐标
const int DIC_MAX = 4;

class  Solution{
private:
    
    int dirct[DIC_MAX][2] = {
        {1, 0},
        {-1, 0},
        {0, 1},
        {0, -1},
    };
    
    int _m, _n;
    
public:
    
    
    vector<int> getIslandCount(int m, int n, int pos[][POS_MAX], int size) {
        this->_m = m; this->_n = n;
        vector<int> res;
        int island = 0;
        bool ** visit = new bool *[m];//分配一个指针数组
        for (int i = 0; i < m; ++ i) {
            visit[i] = new bool[n];//为指针数组的每个元素分配一个数组
        }
        int *fa = new int[m*n];
        for (int i = 0; i < m * n; ++ i) {
            fa[i] = i; // 每个岛有它自己的特征值，fa[i]
        }
        
        for (int i = 0; i < size; ++ i) {
            island++;
            visit[pos[i][0]][pos[i][1]] = true;
            int hash = pos[i][0] * n + pos[i][1];
            for (int j = 0; j < DIC_MAX; ++ j) {
                int x = pos[i][0] + dirct[j][0];
                int y = pos[i][1] + dirct[j][1];
                int curHash = x * n + y;
                if (inMap(x, y) and visit[x][y] and hash != getHash(curHash, fa)) {
                    fa[curHash] = hash;
                    island --;
                }
            }
            res.push_back(island);
        }
        return res;
    }
    
    
private:
    
    
    
    bool inMap(int x, int y) {
        return (x >= 0) and (y >= 0) and (x < _m) and (y < _n);
    }
    
    // 并查集 O(k log mn)
    int getHash(int index, int fa[]) {
        if (fa[index] == index) {
            return index;
        }
        
        fa[index] = getHash(fa[index], fa); // 注意，这里之前写错了
    
        return fa[index];
    }
    
    
    
};


int main(int argc, const char * argv[]) {
    Solution s = * new Solution();
    int size = 5;
    int pos[5][2] = {{0, 0}, {0, 1}, {1, 2}, {2, 1}, {1, 1}};
    
    vector<int> res = s.getIslandCount(3, 3, pos, size);
    
    for (int i = 0; i < res.size(); ++ i) {
        cout << res[i] << "\t";
    }
    
    return 0;
}
