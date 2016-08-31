//
//  main.cpp
//  299. Bulls and Cows
//
//  Created by Kieran Will on 31/08/2016.
//  Copyright © 2016 liuw53. All rights reserved.
//
/*
 You are playing the following Bulls and Cows game with your friend: You write down a number and ask your friend to guess what the number is. Each time your friend makes a guess, you provide a hint that indicates how many digits in said guess match your secret number exactly in both digit and position (called "bulls") and how many digits match the secret number but locate in the wrong position (called "cows"). Your friend will use successive guesses and hints to eventually derive the secret number.
 
 For example:
 
 Secret number:  "1807"
 Friend's guess: "7810"
 Hint: 1 bull and 3 cows. (The bull is 8, the cows are 0, 1 and 7.)
 Write a function to return a hint according to the secret number and friend's guess, use A to indicate the bulls and B to indicate the cows. In the above example, your function should return "1A3B".
 
 Please note that both secret number and friend's guess may contain duplicate digits, for example:
 
 Secret number:  "1123"
 Friend's guess: "0111"
 In this case, the 1st 1 in friend's guess is a bull, the 2nd or 3rd 1 is a cow, and your function should return "1A1B".
 You may assume that the secret number and your friend's guess only contain digits, and their lengths are always equal.
 
 solution:
 
 Hashmap to record character occurance number, iterate string, if equals hit++, else if not equal && map[i] >0 miss++
 */
#include <iostream>
#include <string>
#include <vector>
using namespace std;


class Solution {
public:
    string getHint(string secret, string guess) {
        vector<int> sec(10);
        vector<int> gue(10);
        int tmp = 0;      // bull
        for (int i = 0; i < secret.length(); ++i) {
            sec[secret[i] - '0']++;
            gue[guess[i] - '0']++;
            if (guess[i] == secret[i]) {
                ++ tmp;
            }
        }
        int summation = 0;
        for (int i = 0; i < 10; ++i) {
            summation += min(sec[i], gue[i]);
        }
        return to_string(tmp) + "A" + to_string(summation - tmp) + "B";
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
