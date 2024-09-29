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

    int subarraySum_1(vector<int> &nums, int k)
    {
        /*一点点改进：前缀*/
        vector<int> num(nums);
        for (int i = 1; i < nums.size(); i++)
        {
            num[i] += num[i - 1];
        }

        int res = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (num[i] == k)
            {
                res++;
            }
            for (int j = 0; j < i; j++)
            {
                if (num[i] - num[j] == k)
                {
                    res++;
                }
            }
        }
        return res;
    }

    int subarraySum(vector<int> &nums, int k)
    {
        /*
        前缀+哈希：
        统计以 i 结尾的和为 k 的连续子数组个数时
        只要统计有多少个前缀和为 pre[i]−k 的 pre[j] 即可

        在数组中向前移动时，逐步增加 pre（当前的累积和）。
        对于每个新的 pre 值，检查 pre - k 是否在 Map 中：
        pre - k ：
        如果 pre - k 存在于 Map 中，说明之前在某个点的累积和是 pre - k。
        由于当前的累积和是 pre，这意味着从那个点到当前点的子数组之和恰好是 k（因为 pre - (pre - k) = k）。
        */
        unordered_map<int, int> mp;
        mp[0] = 1;
        int res = 0, pre = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            pre += nums[i];
            if (mp.find(pre - k) != mp.end())
            {
                res += mp[pre - k];
            }
            mp[pre]++;
        }
        return res;
    }
};
// @lc code=end
