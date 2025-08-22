/*
 * @lc app=leetcode id=342 lang=cpp
 *
 * [342] Power of Four
 */

// @lc code=start
class Solution {
public:
    bool isPowerOfFour(int n) {
        //位运算+模运算
        return n>0&&((n&(n-1))==0)&&(n%3==1);
    }
};
// @lc code=end

