/*
 * @lc app=leetcode id=322 lang=cpp
 *
 * [322] Coin Change
 */

// @lc code=start
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1,INT_MAX);

        //初始化
        dp[0]=0;
        /*
        for(int i=0;i<coins.size()&&i<amount;i++)
            dp[coins[i]]=1;
        for(int i=0;i<coins[0];i++)
            dp[i]=-1;
        */
        
        for(int i=1;i<=amount;i++){
            for(int coin:coins){
                if(i-coin>=0&&dp[i-coin]!=INT_MAX)
                    dp[i]=min(dp[i],dp[i-coin]+1);
            }
        }

        return dp[amount]==INT_MAX?-1:dp[amount];
    }
};
// @lc code=end

