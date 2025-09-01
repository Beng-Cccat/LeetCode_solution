/*
 * @lc app=leetcode id=673 lang=cpp
 *
 * [673] Number of Longest Increasing Subsequence
 */

// @lc code=start
class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int len=nums.size();
        vector<int> dp(len,1);//最长递增子序列的长度
        vector<int> count(len,1);//最长递增子序列的个数

        for(int i=0;i<len;i++)
            for(int j=0;j<i;j++){
                if(nums[j]>=nums[i])
                    continue;
                if(dp[j]+1==dp[i]){
                    //长度不需要被更新
                    dp[i]=dp[j]+1;
                    count[i]+=count[j];
                }
                else if(dp[j]+1>dp[i]){
                    //长度需要被更新
                    dp[i]=dp[j]+1;
                    count[i]=count[j];
                }
            }
            int res=0;
            int maxLen=*max_element(dp.begin(),dp.end());
            for(int i=0;i<len;i++)
                if(dp[i]==maxLen)
                    res+=count[i];
            return res;

    }
};
// @lc code=end

