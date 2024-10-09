/*
 * @lc app=leetcode.cn id=53 lang=cpp
 *
 * [53] 最大子数组和
 */

// @lc code=start
class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        int n = nums.size();
        if (n == 0)
            return 0;

        int curNum = nums[0];
        int maxNum = nums[0];

        for (int i = 1; i < n; i++)
        {
            // 连续子数组的和，如果当前数比之前的和还大，那么就从当前数开始重新计算
            // 反之则继续加
            curNum = max(nums[i], curNum + nums[i]);
            // maxNum表示连续的过程中记录过的最大值
            maxNum = max(maxNum, curNum);
        }

        return maxNum;
    }
};
// @lc code=end
