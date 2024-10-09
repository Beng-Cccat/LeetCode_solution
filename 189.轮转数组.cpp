/*
 * @lc app=leetcode.cn id=189 lang=cpp
 *
 * [189] 轮转数组
 */

// @lc code=start
class Solution
{
public:
    void rotate(vector<int> &nums, int k)
    {
        /*
        三次反转，首先后面k%n个元素肯定会在前面，其他元素在后面
        先反转，使后面元素在前面，前面元素在后面
        再使用两次反转将这些元素放置在对应的位置上
        */
        int n = nums.size();
        k %= n;
        reverse(nums.begin(), nums.end());
        reverse(nums.begin(), nums.begin() + k);
        reverse(nums.begin() + k, nums.end());
    }

    void rotate_0(vector<int> &nums, int k)
    {
        /*
        非原地算法，使用额外的数组
        */
        int n = nums.size();
        k %= n;
        vector<int> res(n);
        for (int i = n - k; i < n; i++)
        {
            res[i - n + k] = nums[i];
        }
        for (int i = 0; i < n - k; i++)
        {
            res[i + k] = nums[i];
        }
        nums = res;
    }

    void rotate_1(vector<int> &nums, int k)
    {
        /*
        循环替换，每次将当前元素放到正确的位置上，但是会超时
        */
        int n = nums.size();
        k %= n;
        for (int i = 0; i < k; i++)
        {
            nums.insert(nums.begin(), nums.back());
            nums.pop_back();
        }
    }
};
// @lc code=end
