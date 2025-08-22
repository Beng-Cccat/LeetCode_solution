/*
 * @lc app=leetcode id=16 lang=cpp
 *
 * [16] 3Sum Closest
 */

// @lc code=start
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int result=nums[0]+nums[1]+nums[nums.size()-1];
        int dis=abs(result-target);

        int curadd=0,curdis=0;
        for(int i=0;i<nums.size()-2;i++){
            for(int left=i+1,right=nums.size()-1;left<right;){
                curadd=nums[i]+nums[left]+nums[right];
                curdis=abs(curadd-target);
                if(curdis<dis){
                    dis=curdis;
                    result=curadd;
                }
                if(curadd>target){
                    right--;
                }
                else if(curadd<target){
                    left++;
                }
                else if(result==target){
                    return result;
                }
            }
        }
        return result;
    }
};
// @lc code=end

