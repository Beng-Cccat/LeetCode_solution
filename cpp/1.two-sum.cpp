/*
 * @lc app=leetcode id=1 lang=cpp
 *
 * [1] Two Sum
 */

// @lc code=start
class Solution {
public:
    vector<int> twoSum_1(vector<int>& nums, int target) {
        for(int i=0;i<nums.size();i++){
            for(int j=i+1;j<nums.size();j++){
                if(nums[i]+nums[j]==target){
                    return {i,j};
                }        
            }
        }
        return {};
    }

    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> hmap;
        int ptr=0;
        for(auto num:nums)
            hmap[num]=ptr++;
        for(int i=0;i<nums.size();i++){
            //查找并避免用同一个元素
            if(hmap.find(target-nums[i])!=hmap.end()&& hmap[target - nums[i]] != i){
                //有
                return {hmap[target-nums[i]],i};
            
            }
            //或者可以在这里面再进行建哈希表
        }
        return {};
    }
};
// @lc code=end

