/*
 * @lc app=leetcode id=292 lang=cpp
 *
 * [292] Nim Game
 */

// @lc code=start
class Solution {
public:
    bool canWinNim(int n) {
        if(n%4<=3&&n%4>=1)
            return true;
        return false;
    }
};
// @lc code=end

