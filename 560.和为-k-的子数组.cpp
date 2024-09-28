/*
 * @lc app=leetcode.cn id=560 lang=cpp
 *
 * [560] 和为 K 的子数组
 */

// @lc code=start
class Solution
{
public:
    int subarraySum_0(vector<int> &nums, int k)
    {
        /*暴力枚举*/
        int res = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            int sum = 0;
            for (int j = i; j < nums.size(); j++)
            {
                sum += nums[j];
                if (sum == k)
                {
                    res++;
                }
            }
        }
        return res;
    }

    int subarraySum(vector<int> &nums, int k)
    {
        /*前缀+哈希*/
        unordered_map<int, int> mp;
        vector<int> num(nums);
        for (int i = 1; i < nums.size(); i++)
        {
            num[i] += num[i - 1];
            mp[nums[i]]++;
        }

        int res = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == k)
            {
                res++;
            }
            if (mp.find(nums[i] - k) != mp.end())
            {
                res += mp[nums[i] - k];
            }
        }
        return res;
    }
};
// @lc code=end
