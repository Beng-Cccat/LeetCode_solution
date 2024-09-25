/*
 * @lc app=leetcode.cn id=128 lang=cpp
 *
 * [128] 最长连续序列
 */

// @lc code=start
class Solution
{
public:
    int longestConsecutive(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        int res = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            int cnt = 1;
            while (i + 1 < nums.size())
            {
                if (nums[i + 1] == nums[i] + 1)
                {
                    cnt++;
                    i++;
                }
                else if (nums[i + 1] == nums[i])
                {
                    i++;
                }
                else
                {
                    break;
                }
            }
            res = max(res, cnt);
        }
        return res;
    }
};
// @lc code=end
