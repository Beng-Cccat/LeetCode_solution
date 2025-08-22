/*
 * @lc app=leetcode id=33 lang=cpp
 *
 * [33] Search in Rotated Sorted Array
 */

// @lc code=start
class Solution {
public:
    int search(vector<int>& nums, int target) {
        //标准查找，但不是o(logn)
        /*
        for(int i=0;i<nums.size();i++){
            if(nums[i]==target)
                return i;
        }
        return -1;
        */

        //二分查找
        int left=0;
        int right=nums.size()-1;

        while(left<=right){
            int mid=left+(right-left)/2;
            if(nums[mid]==target)
                return mid;
            //中间的不是
            //左边是否有序
            if(nums[left]<=nums[mid]){
                //左边有序
                if(target>=nums[left]&&target<nums[mid]){
                    right=mid-1;
                }
                else
                    left=mid+1;
            }
            //右边有序
            else{
                if(target<=nums[right]&&target>nums[mid])
                    left=mid+1;
                else
                    right=mid-1;
            }
        }
        return -1;
    }
};
// @lc code=end

