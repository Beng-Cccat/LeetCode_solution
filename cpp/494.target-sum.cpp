/*
 * @lc app=leetcode id=494 lang=cpp
 *
 * [494] Target Sum
 */

// @lc code=start
class Solution {
public:
//再想想
    int findTargetSumWays(vector<int>& nums, int target) {
        int len=nums.size();
        vector<vector<int>> dp(len+1,vector<int>(target+1,0));

        for(int i=0;i<=target;i++)
            dp[0][i]=0;

        for(int i=1;i<=len;i++){
            for(int j=1;j<=target;j++){
                dp[i][j]+=(dp[i-1][j-nums[i-1]]+dp[i-1][j+nums[i-1]]);
            }
        }
        return dp[len][target];
    }
};
// @lc code=end

