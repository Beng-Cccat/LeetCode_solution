/*
 * @lc app=leetcode.cn id=239 lang=cpp
 *
 * [239] 滑动窗口最大值
 */

// @lc code=start
class Solution
{
public:
    vector<int> maxSlidingWindow(vector<int> &nums, int k)
    {
        /*
        分组：每k个元素为一组
        用两个数组分别存储左边界和右边界到自己的最大值
        每次push的值为左右边界的最大值
        */
        vector<int> res;
        vector<int> left(nums.size());
        vector<int> right(nums.size());

        // 左边界到自己的最大值
        for (int i = 0; i < nums.size(); i++)
        {
            if (i % k == 0)
            {
                left[i] = nums[i];
            }
            else
            {
                left[i] = max(left[i - 1], nums[i]);
            }
        }

        // 右边界到自己的最大值
        for (int i = nums.size() - 1; i >= 0; i--)
        {
            if (i == nums.size() - 1 || (i + 1) % k == 0)
            {
                right[i] = nums[i];
            }
            else
            {
                right[i] = max(right[i + 1], nums[i]);
            }
        }

        // 每k个元素为一组，push左右边界的最大值
        for (int i = 0; i < nums.size() - k + 1; i++)
        {
            res.push_back(max(right[i], left[i + k - 1]));
        }

        return res;
    }
};
// @lc code=end
