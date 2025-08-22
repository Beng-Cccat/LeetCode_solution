/*
 * @lc app=leetcode id=300 lang=cpp
 *
 * [300] Longest Increasing Subsequence
 */

// @lc code=start
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> dp(nums.size(),1);

        int maxLen=1;

        for(int i=1;i<nums.size();i++){
            for(int j=1;i-j>=0;j++){
                if(nums[i]>nums[i-j]){
                    dp[i]=max(dp[i-j]+1,dp[i]);
                }
            }
            maxLen=max(maxLen,dp[i]);
        }

        return maxLen;
    }
};
// @lc code=end

