//
//  main.cpp
//  xiaomi
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



vector<string> VS;


int getS(string s) {
    return 0;
}





struct Node {
    int data;
    Node *lchild;
    Node *rchild;
};

void High(Node *T, int &h)
{
    if (T == NULL)
        h = 0;
    else {
        int left_h;
        High(T->lchild, left_h);
        int right_h;
        High(T->rchild, right_h);
        
        h = 1 + max(left_h, right_h);
    }
}

Node *CreateBiTree(Node *&T) {  // 算法6.4
    char ch;
    cin >> ch;
    if (ch == '#')
        T = NULL;
    else {
        if (!(T = (Node *)malloc(sizeof(Node))))
            return 0;
        T->data = ch;              // 生成根结点
        CreateBiTree(T->lchild);   // 构造左子树
        CreateBiTree(T->rchild);   // 构造右子树
    }
    return T;
} // CreateBiTree

void Free(Node *&T)
{
    if (T == NULL)
        return;
    
    Free(T->lchild);
    //	T->lchild = NULL;
    Free(T->rchild);
    //	T->rchild = NULL;
    free(T);
    T = NULL;
}

int main(int argc, char **argv)
{
    freopen("cin.txt", "r", stdin);
    
    Node *T = NULL;
    CreateBiTree(T);
    
    int height;
    High(T, height);
    cout << height << endl;
    
    Free(T);
    
    return 0;
}

/* cin.txt:
 A
 B
 C
 #
 #
 D
 E
 #
 G
 #
 #
 F
 #
 #
 #
 */

/*
int main(int argc, const char * argv[]) {
    int T;
    string s;
    cin >> T;
    //"FIVE", "SIX", "SEVEN", "EIGHT", "NINE"），"（"ZERO", "ONE", "TWO", "THREE", "FOUR",
    VS.push_back("EIGHT");
    VS.push_back("NINE");
    VS.push_back("ZERO");
    VS.push_back("ONE");
    VS.push_back("TWO");
    VS.push_back("THREE");
    VS.push_back("FOUR");
    VS.push_back("FIVE");
    VS.push_back("SIX");
    VS.push_back("SEVEN");
    
    for (int i = 0; i < T; ++ i) {
        cin >> s; cout << getS(s) << "\n";
    }
    
    
    
    
    
    return 0;
}
*/