/*
 * @lc app=leetcode.cn id=15 lang=cpp
 *
 * [15] 三数之和
 */

// @lc code=start
class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        /*
        朴素思路：
        先排序，过程中可以进行剪枝
        第一个数用来遍历，第二个数和第三个数使用双指针来遍历，找到所有的可能
        */

        // 特殊情况
        if (nums.size() < 3)
        {
            return {};
        }

        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        for (int i = 0; i < nums.size(); i++)
        {
            // 第一个数相同的话，后面会重复，所以直接下一个
            if (i > 0 && nums[i] == nums[i - 1])
            {
                continue;
            }
            // 这个数太大了，后面肯定没有符合条件的了
            if (i + 1 < nums.size() && i + 2 < nums.size() && nums[i] + nums[i + 1] + nums[i + 2] > 0)
            {
                break;
            }
            // 这个数太小了，下一个
            if (nums[i] + nums[nums.size() - 2] + nums[nums.size() - 1] < 0)
            {
                continue;
            }
            // 开始双指针
            int left = i + 1;
            int right = nums.size() - 1;
            while (left < right)
            {
                int sum = nums[i] + nums[left] + nums[right];
                if (sum < 0)
                    left++;
                else if (sum > 0)
                    right--;
                else if (sum == 0)
                {
                    res.push_back({nums[i], nums[left], nums[right]});
                    // 去重
                    while (left < right && nums[left] == nums[left + 1])
                    {
                        left++;
                    }
                    while (left < right && nums[right] == nums[right - 1])
                    {
                        right--;
                    }
                    left++;
                    right--;
                }
            }
        }
        return res;
    }
};
// @lc code=end
