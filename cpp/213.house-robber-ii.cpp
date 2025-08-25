/*
 * @lc app=leetcode id=213 lang=cpp
 *
 * [213] House Robber II
 */

// @lc code=start
class Solution {
public:
    int rob(vector<int>& nums) {
        //分成两个情况：不偷第一个房子+不偷最后一个房子
        int len=nums.size();
        if(len==1)return nums[0];
        if(len==2)return max(nums[0],nums[1]);

        function<int(int,int)> dp=[&](int start,int end){
            int pre=0,cur=0;
            for(int i=start;i<=end;i++){
                int temp=max(cur,pre+nums[i]);
                pre=cur;
                cur=temp;
            }
            return cur;
        };

        int noFirst=dp(1,len-1);
        int noLast=dp(0,len-2);
        return max(noFirst,noLast);
    }
};
// @lc code=end

