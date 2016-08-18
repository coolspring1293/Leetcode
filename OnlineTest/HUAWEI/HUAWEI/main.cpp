//
//  main.cpp
//  HUAWEI
//
//  Created by Kieran Will on 8/10/16.
//  Copyright © 2016 liuw53. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;

bool isL(char c) {
    return ('A' <= c and c <= 'Z') or ('a' <= c and c <= 'z');
}

string getRes(string s) {
    for (int i = 0; i < s.size() - 1; i ++) {
        for (int j = 0; j < s.size() - i - 1; j ++) {
            if (isL(s[j])) {
                int cur = j + 1;
                while (!isL(s[cur]) and cur < s.size() - i - 1) {
                    ++ cur;
                }
                if (isL(s[cur])) {
                    if (s[j] > s[cur]) {
                        char tmp = s[j];
                        s[j] = s[cur];
                        s[cur] = tmp;
                    }
                }
            }
        }
    }
    return s;
}


int main(int argc, const char * argv[]) {
    string s;
    while (cin >> s)  cout << getRes(s) << endl;
    return 0;
}
