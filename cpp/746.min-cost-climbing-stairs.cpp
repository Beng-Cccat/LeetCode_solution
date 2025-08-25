/*
 * @lc app=leetcode id=746 lang=cpp
 *
 * [746] Min Cost Climbing Stairs
 */

// @lc code=start
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int len=cost.size();

        //状态数组
        vector<int> dp(len,0);
        //初始化
        dp[0]=cost[0];
        dp[1]=cost[1];

        int res;

        //动态规划
        for(int i=2;i<len;i++){
            dp[i]=min(dp[i-1],dp[i-2])+cost[i];
        }

        res=min(dp[len-1],dp[len-2]);
        return res;
    }
};
// @lc code=end

