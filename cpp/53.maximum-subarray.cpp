/*
 * @lc app=leetcode id=53 lang=cpp
 *
 * [53] Maximum Subarray
 */

// @lc code=start
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        vector<int> dp(nums.size());
        int maxSum=nums[0];

        //初始化
        for(int i=0;i<nums.size();i++)
            dp[i]=nums[i];

        for(int i=1;i<nums.size();i++){
            dp[i]=max(dp[i],dp[i-1]+nums[i]);
            maxSum=max(dp[i],maxSum);
        }
        return maxSum;
    }
};
// @lc code=end

