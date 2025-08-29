/*
 * @lc app=leetcode id=494 lang=cpp
 *
 * [494] Target Sum
 */

// @lc code=start
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int len=nums.size();
        int sum=0;
        for(auto i:nums)
            sum+=i;
        int add=(sum+target);
        if(add%2|| abs(target) > sum)
            return 0;
        else
            add/=2;

        vector<vector<int>> dp(len+1,vector<int>(add+1,0));

        dp[0][0]=1;

        for(int i=1;i<=len;i++){
            for(int j=0;j<=add;j++){
                dp[i][j] = dp[i-1][j]; // 不选
                if(j >= nums[i-1])
                    dp[i][j] += dp[i-1][j-nums[i-1]]; // 选
            }
        }
        return dp[len][add];
    }
};
// @lc code=end

