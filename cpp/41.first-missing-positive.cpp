/*
 * @lc app=leetcode id=41 lang=cpp
 *
 * [41] First Missing Positive
 */

// @lc code=start
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int cur=1,pre=0;
        int result=1;
        sort(nums.begin(),nums.end());
        //找到第一个非负整数
        while(nums[pre]<0&&pre<nums.size()-1){
            pre++;
            cur++;
        }
   
        if(nums[pre]>1||(pre==nums.size()&&nums[pre]<1))
            return result;
        while(cur!=nums.size()){
            if(nums[cur]<1){
                cur++;
                pre++;
                continue;
            }
            if(nums[cur]!=nums[pre]+1&&nums[cur]!=nums[pre]){
                result=nums[pre]+1;
                return result;
            }
            cur++;
            pre++;
        }
        result=nums[pre]+1<1?1:nums[pre]+1;
        return result;
    }
};
// @lc code=end

