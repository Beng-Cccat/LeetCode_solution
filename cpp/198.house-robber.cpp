/*
 * @lc app=leetcode id=198 lang=cpp
 *
 * [198] House Robber
 */

// @lc code=start
class Solution {
public:
    int rob(vector<int>& nums) {
        int maxSum=nums[0];
         vector<int> dp(nums.size(),0);

         //初始化
         for(int i=0;i<nums.size();i++)
            dp[i]=nums[i];

        //开始填充
        for(int i=0;i<nums.size();i++){
            for(int j=2;i-j>=0;j++){
                dp[i]=max(dp[i],dp[i-j]+nums[i]);
            }

            maxSum=max(maxSum,dp[i]);
        }

        return maxSum;
    }
};
// @lc code=end

