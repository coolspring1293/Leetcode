//
//  main.cpp
//  BinaryTree
//
//  Created by Kieran Will on 10/9/16.
//  Copyright © 2016 liuw53. All rights reserved.
//
//  二叉树的遍历与还原


#include <iostream>
#include <string>
#include <vector>

using namespace std;

class BT {
public:
    char _node;
    BT *_left, *_right;
    
};


BT bt;

const string mid_s = "DBGEHJACIF";
const string lst_s = "DGJHEBIFCA";





vector<char> mid;
vector<char> lst;

vector<char> pre;
void printV(const vector<char> v) {
    for (int i = 0; i < v.size(); ++ i) {
        //cout << v[i] << "\t";
    }
    //cout << "\n";
}


void init() {
    for (int i = 0; i < mid_s.size(); ++ i) {
        mid.push_back(mid_s[i]);
        lst.push_back(lst_s[i]);
    }
}


int level = 0;


bool NodeIn(char root, vector<char> v) {
    for (int  i = 0; i < v.size(); ++ i) {
        if (root == v[i]) return true;
    }
    return false;
}

vector<char> getSame(const vector<char> mid, const vector<char> sub) {
    vector<char> v;
    for (int i = 0; i < mid.size(); ++ i) {
        if (NodeIn(mid[i], sub)) v.push_back(mid[i]);
    }
    return v;
}

void rev(vector<char> lst, vector<char> mid, vector<char>& m_l, vector<char>& m_r, char& root) {
    // 后续遍历最后一个节点就是跟节点
    if(lst.size() == 0) {
        // 子节点是空的
        // cout << "LEAF NODE is NULL.\n";
        return;
    }
    root = lst[lst.size()-1];
    if(lst.size() == 1) {
        // 已经是叶子节点
        pre.push_back(root);
        // cout << "LEAF NODE: " << root << "\n";
        return;
    }
    bool flg = false;
    for (int i = 0; i < mid.size(); ++ i) {
        if (mid[i] == root)  { flg = true; continue; }
        if (flg) {
            m_r.push_back(mid[i]);
        } else {
            m_l.push_back(mid[i]);
        }
    }
    
    // cout << "LEVEL: " << level++ << "\t";
    // cout << "ROOT: " << root << "\n";
    pre.push_back(root);
    
    printV(m_l);
    
    
    vector<char> l_l = getSame(lst, m_l);
    vector<char> l_r = getSame(lst, m_r);
    
    printV(l_l);
    // cout << "-----------\n";
    printV(m_r);
    printV(l_r);
    
    vector<char> l1, l2;
    vector<char> r1, r2;
    char _root;
    
    rev(l_l, m_l, l1, r1, _root);
    rev(l_r, m_r, l1, r1, _root);
    
    
}


void test() {
    vector<char> l;
    vector<char> r;
    char _root;
    
    rev(lst, mid, l, r, _root);
    
    
}




int main(int argc, const char * argv[]) {
    init();
    
    test();
    // 输出前序
    for (int i = 0; i < pre.size(); ++ i) {
        cout << pre[i] << "\t";
    }
    cout << "\n";
    
    return 0;
}
