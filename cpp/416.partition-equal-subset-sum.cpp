/*
 * @lc app=leetcode id=416 lang=cpp
 *
 * [416] Partition Equal Subset Sum
 */

// @lc code=start
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int len=nums.size();
        int sum=accumulate(nums.begin(),nums.end(),0);
        if(sum%2)return false;
        int target=sum/2;

        vector<vector<bool>> dp(len+1,vector<bool>(target+1,false));

        //初始化
        for(int i=0;i<=len;i++)
            dp[i][0]=true;

        for(int i=1;i<=len;i++){
            for(int j=1;j<=target;j++){
                if(j<nums[i-1])
                    dp[i][j]=dp[i-1][j];
                else
                //dp[i][j]对应的数其实是nums的第i-1个数
                    dp[i][j]=dp[i-1][j]||dp[i-1][j-nums[i-1]];
            }
        }
        return dp[len][target];
    }
};
// @lc code=end

