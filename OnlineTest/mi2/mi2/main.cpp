//
//  main.cpp
//  mi2
//
//  Created by Kieran Will on 9/23/16.
//  Copyright © 2016 liuw53. All rights reserved.
//

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <stack>
#include <vector>
#include <string>
using namespace std;

class B {
public:
    int _n, _h;
    B(int n, int h) {
        _n = n;
        _h = h;
    }
    
};

vector<B> vb;


int getX() {
    int s = 0;
    for (int i = 0; i < vb.size(); ++ i) {
        if (vb[i]._h > s) {
            s = vb[i]._h;
        }
    }
    return s;
}

int main(int argc, const char * argv[]) {
    int T;
    cin >> T;
    int a,b;
    vb.push_back(B(0, 1));
    while(cin >> a >> b) {
        if (a == 0 and b == 0) break;
        for (int i = 0; i < vb.size(); ++i) {
            if (vb[i]._n == a) {
                vb.push_back(B(b, vb[i]._h+1));
                break;
            }
        }
    }
    
    cout << getX() << "\n";
    
    return 0;
}
