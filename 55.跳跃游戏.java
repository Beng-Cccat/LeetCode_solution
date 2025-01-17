/*
 * @lc app=leetcode.cn id=55 lang=java
 *
 * [55] 跳跃游戏
 */

// @lc code=start
class Solution {
    public boolean canJump(int[] nums) {
        int maxindex=0;
        for(int i=0;i<nums.length-1;i++){
            if(nums[i]==0&&maxindex==i)
                break;
            maxindex=Math.max(maxindex, i+nums[i]);
        }
        return maxindex>=nums.length-1;
    }
}
// @lc code=end

