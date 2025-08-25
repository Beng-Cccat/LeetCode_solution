/*
 * @lc app=leetcode id=740 lang=cpp
 *
 * [740] Delete and Earn
 */

// @lc code=start
class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        int maxNum=*max_element(nums.begin(),nums.end());
        vector<int> sum(maxNum+1,0);

        for(auto num:nums)
            sum[num]+=num;

        vector<int> dp(maxNum+1,0);
        int pre=0,cur=0;
        for(int i=0;i<=maxNum;i++){
            int temp=max(cur,pre+sum[i]);
            pre=cur;
            cur=temp;
        }
        return cur;
    }
};
// @lc code=end

