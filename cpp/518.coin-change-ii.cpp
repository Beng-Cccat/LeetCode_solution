/*
 * @lc app=leetcode id=518 lang=cpp
 *
 * [518] Coin Change II
 */

// @lc code=start
class Solution {
public:
    int change(int amount, vector<int>& coins) {
        const int MOD = 1e9 + 7;
        vector<long long> dp(amount+1,0);

        dp[0]=1;

        for(auto coin:coins){
            for(int i=coin;i<=amount;i++){
                if((dp[i] + dp[i - coin]) / MOD){
                    dp[i] = (dp[i] + dp[i - coin]) % MOD;
                    dp[i]+=MOD;
                }
                else dp[i] = (dp[i] + dp[i - coin]);
            }
        }
        return dp[amount];
    }
};
// @lc code=end

