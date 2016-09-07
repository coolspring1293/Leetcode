#include <iostream>
#include <string>
#include <vector>
using namespace std;

int T;
long long x;

vector<long long> v;

string getLN(long long x) {
    if (x == 1) return "4";
    if (x == 2) return "7";
    int loc = 0;
    
    int c = 0;
    for (int i = 0; i < v.size(); ++ i) {
        if (v[i] > x) {
            c = i; break;
        }
    }
    loc = c-1;
    long long tmp = x - v[loc] - 1;
    
    string s = "";
    while(tmp) {
        int xx = tmp % 2;
        if (xx == 0) {
            
            s = '4' + s;
        } else {
            s = '7' + s;
        }
        tmp /= 2;

    }
    for (int i = s.size()-1; i <= loc; ++ i) {
        s = '4' + s;
    }
    return s;
}





int main () {
    
    v.push_back(2);
    long long last = 2;
    for (long long i = 4; i <= 1000000000000; i = i * 2) {
        long long tmp = i + last;
        v.push_back(tmp);
        last = tmp;
    }
    
    cin >> T;
    for (int i = 0; i < T; ++ i) {
        cin >> x;
        cout << getLN(x) << "\n";
    }
    
}
