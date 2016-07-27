//
//  main.cpp
//  292. Nim Game
//
//  Created by Kieran Will on 4/17/16.
//  Copyright © 2016 liuw53. All rights reserved.
//

/*
 292. Nim Game   My Submissions QuestionEditorial Solution
 Total Accepted: 63550 Total Submissions: 120679 Difficulty: Easy
 You are playing the following Nim Game with your friend: There is a heap of stones on the table, each time one of you take turns to remove 1 to 3 stones. The one who removes the last stone will be the winner. You will take the first turn to remove the stones.
 
 Both of you are very clever and have optimal strategies for the game. Write a function to determine whether you can win the game given the number of stones in the heap.
 
 For example, if there are 4 stones in the heap, then you will never win the game: no matter 1, 2, or 3 stones you remove, the last stone will always be removed by your friend.
 */

#include <iostream>

class Solution {
public:
    bool canWinNim(int n) {
        return n % 4 != 0;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
