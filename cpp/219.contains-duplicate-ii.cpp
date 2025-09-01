/*
 * @lc app=leetcode id=219 lang=cpp
 *
 * [219] Contains Duplicate II
 */

// @lc code=start
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int,int> hmap;

        for(int i=0;i<nums.size();i++){
            int ptr=nums[i];
            if(hmap.find(ptr)!=hmap.end()){
                //找到了
                int dis=i-hmap[ptr];
                if(dis<=k){
                    return true;
                }
            }
            hmap[nums[i]]=i;
        }
        return false;
    }
};
// @lc code=end

