/*
 * @lc app=leetcode.cn id=238 lang=cpp
 *
 * [238] 除自身以外数组的乘积
 */

// @lc code=start
class Solution
{
public:
    vector<int> productExceptSelf(vector<int> &nums)
    {
        /*
        使用前缀数组和后缀数组分别表示前面的和后面的元素的乘积
        */
        int n = nums.size();
        vector<int> suffix(n);
        vector<int> prefix(n);

        prefix[0] = 1;
        suffix[n - 1] = 1;
        for (int i = 1; i < n; i++)
        {
            prefix[i] = prefix[i - 1] * nums[i - 1];
        }
        for (int i = n - 2; i >= 0; i--)
        {
            suffix[i] = suffix[i + 1] * nums[i + 1];
        }

        vector<int> res(n);
        for (int i = 0; i < n; i++)
        {
            res[i] = (suffix[i] * prefix[i]);
        }
        return res;
    }
};
// @lc code=end
