/*
 * @lc app=leetcode id=454 lang=cpp
 *
 * [454] 4Sum II
 */

// @lc code=start
class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        int n=nums1.size();

        unordered_map<int,int> hmap;
        for(auto num1:nums1)
            for(auto num2:nums2)
                hmap[num2+num1]++;

        int res=0;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                int sum=nums3[i]+nums4[j];
                if(hmap.find(-sum)!=hmap.end()){
                    res+=hmap[-sum];
                }
            }
        }
        return res;
    }
};
// @lc code=end

