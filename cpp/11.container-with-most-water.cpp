/*
 * @lc app=leetcode id=11 lang=cpp
 *
 * [11] Container With Most Water
 */

// @lc code=start

//思路：双指针
class Solution {
public:
    int maxArea(vector<int>& height) {
        int left=0,right=height.size()-1;
        int result=(right-left)*min(height[right],height[left]);
        while(left!=right){
            if(height[left]<=height[right]){
                left++;
            }
            else
                right--;
            int temp=(right-left)*min(height[right],height[left]);
                result=max(result,temp);
        }
        return result;
    }
};
// @lc code=end

