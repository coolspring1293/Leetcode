//
//  main.cpp
//  shen
//
//  Created by Kieran Will on 9/20/16.
//  Copyright © 2016 liuw53. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <string>
#include <set>
using namespace std;

int N;

class B {
public:
    vector<bool> v;
    int value;
    B(int x) {
        while (x) {
            v.push_back(x % 2);
            x /= 2;
        }
        value = x;
    }
    
    B(vector<bool> b) {
        v = b;
    }
    void show() {
        for (int i = 0 ; i < v.size(); ++ i) {
            cout << (v[i] == true?'1':'0') << "\t";
        }
        cout << "\n";
    }
    
    int getC() {
        int x = 0;
        for (int i = 0; i < v.size(); ++ i) {
            if (v[i]) {
                ++ x;
            }
        }
        return x;
    }
    
    B getN2() {
        int x = toValue() + 1;
        B newb = B(x);
        //cout << "getC = " <<this->getC()  << "  " << newb.getC() << "\n";
        while (this->getC() != newb.getC()) {
            x ++;
            //cout << "x=" <<  x << "\n";
            newb = B(x);
        }
        return newb;
    }
    
    B getN() {
        int x = toValue();
        B newb = B(x);
        vector<bool> tt;
        int pos = -1;
        for (int i = 0; i < v.size(); ++ i) {
            if (v[i] == false) {
                pos = i; break;
            }
        }
        
        if (pos < 0) {
            tt.push_back(false);
            for (int i = 0; i <v.size(); ++ i) {
                tt.push_back(v[i]);
            }
            
        } else if (pos == 0) {
            tt.push_back(false);
            for (int i = 1; i < v.size(); ++ i) {
                if (v[i] == 0) pos = i;
                tt.push_back(v[i]);
            }
            if (pos == 0) {
                tt[v.size()-1] = false;
                tt.push_back(true);
            } else {
                tt[pos] = true;
                tt[pos+1] = false;
            }
        }
        else {
            for (int i = 0; i < v.size(); ++ i) {
                if (i == pos - 1) {
                    tt.push_back(false);
                } else if (i == pos) {
                    tt.push_back(true);
                } else {
                    tt.push_back(v[i]);
                }
                
            }
        }
        return B(tt);
    }
    
    int toValue() {
        
        int base = 1, value = 0;
        for (int i = 0; i < v.size(); ++ i) {
            value += (v[i] == true? base : 0);
            base *= 2;
        }
        return value;
    }
};

int getV(int x) {
    B b = B(x);
    //b.show();
    B c = b.getN();
    //c.show();
    return c.toValue();
    
}

int getV2(int x) {
    B b = B(x);
    //b.show();
    B c = b.getN2();
    //c.show();
    return c.toValue();
    
}

bool isS(string s) {
    if (s.size() % 2 == 1) return false;
    string s1, s2;
    for (int i = 0; i < s.size() / 2; ++ i) {
        s1 += s[i];
    }
    for (int i = s.size()/2; i < s.size(); ++ i) {
        s2 += s[i];
    }
    
    return (s1 == s2);
}

int getStrSqr(string s) {
    int count = 0;
    set<string> ss;
    for (int i = 0; i < s.size(); ++ i) {
        for (int j = i+1; j < s.size(); ++ j) {
            string tmp = "";
            for (int p = i; p <= j; ++ p) {
                tmp += s[p];
            }
            if (isS(tmp) ) { count ++;
                ss.insert(tmp);
            }
        }
    }
    return ss.size();
}

int main() {
    
    
    
    string ss;
    while (cin >> ss) {
        cout << getStrSqr(ss) << "\n";
    }
    
    
    return 0;
}

