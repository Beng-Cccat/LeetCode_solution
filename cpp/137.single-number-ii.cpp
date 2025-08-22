/*
 * @lc app=leetcode id=137 lang=cpp
 *
 * [137] Single Number II
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
            if(it->second==1)
                res=it->first;
        }
        return res;
    }
};
// @lc code=end

