/*
 * @lc app=leetcode id=34 lang=cpp
 *
 * [34] Find First and Last Position of Element in Sorted Array
 */

// @lc code=start
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> res;

        int left=0,right=nums.size()-1;
        int minN=nums.size(),maxN=-1;

        while(left<=right){
            int mid=left+(right-left)/2;
            if(nums[mid]==target){
                minN=mid;
                maxN=mid;
                int maxtemp=mid,mintemp=mid;
                while(maxtemp<nums.size()&&nums[maxtemp]==target){
                    maxN=maxtemp;
                    maxtemp++;
                }
                while(mintemp>=0&&nums[mintemp]==target){
                    minN=mintemp;
                    mintemp--;
                }
                break;
            }
            else if(nums[mid]<target){
                left=mid+1;
            }
            else if(nums[mid]>target)
                right=mid-1;
        }
        res.push_back(minN==nums.size()?-1:minN);
        res.push_back(maxN);

        return res;
    }
};
// @lc code=end

