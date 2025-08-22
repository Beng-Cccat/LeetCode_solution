/*
 * @lc app=leetcode id=15 lang=cpp
 *
 * [15] 3Sum
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++){
            for(int left=i+1,right=nums.size()-1;left<right;){
                if(nums[left]+nums[right]+nums[i]==0){
                    result.push_back({nums[i],nums[left],nums[right]});
                    left++;
                }
                else if(nums[left]+nums[right]+nums[i]<0)
                    left++;
                else if(nums[left]+nums[right]+nums[i]>0)
                    right--;
            }
        }

        //去重
        set<vector<int>> s(result.begin(),result.end());
        result.assign(s.begin(),s.end());

        //另一种形式：直接跳过所有重复的
        return result;
    }
};
// @lc code=end

