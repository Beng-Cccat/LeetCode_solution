/*
 * @lc app=leetcode id=136 lang=cpp
 *
 * [136] Single Number
 */

// @lc code=start
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int,int> hmap;
        for(int i=0;i<nums.size();i++){
            if(hmap.find(nums[i])!=hmap.end())
                hmap[nums[i]]++;
            else
                hmap.insert({nums[i],1});
        }
        int res=0;
        for(auto it=hmap.begin();it!=hmap.end();it++){
            if(it->second%2)
                res=it->first;
        }
        return res;
    }
};
// @lc code=end

