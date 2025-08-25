/*
 * @lc app=leetcode id=918 lang=cpp
 *
 * [918] Maximum Sum Circular Subarray
 */

// @lc code=start
class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int len=nums.size();
        vector<int> min_dp=nums;
        vector<int> max_dp=nums;
        int total=nums[0];

        for(int i=1;i<len;i++){
            min_dp[i]=min(min_dp[i-1]+nums[i],nums[i]);
            max_dp[i]=max(max_dp[i-1]+nums[i],nums[i]);
            total+=nums[i];
        }

        int min_sub=*min_element(min_dp.begin(),min_dp.end());
        int max_sub=*max_element(max_dp.begin(),max_dp.end());

        if(total==min_sub){
            //说明全是负数
            return max_sub;
        }
        return max(total-min_sub,max_sub);
    }
};
// @lc code=end

