/*
 * @lc app=leetcode.cn id=18 lang=cpp
 *
 * [18] 四数之和
 */

// @lc code=start
class Solution
{
public:
    vector<vector<int>> fourSum(vector<int> &nums, int target)
    {
        /*
        定两个数，后面两个数用双指针进行求解
        过程中为了优化需要进行一系列剪枝
        */

        // 首先进行排序
        std::sort(nums.begin(), nums.end());
        int n = nums.size();

        // 存储答案
        vector<vector<int>> res;

        // 处理特殊情况
        if (n < 4)
            return res; // 如果数组长度小于4，直接返回空

        // 开始枚举
        // 第一个数
        for (int i = 0; i < n - 3; i++)
        {
            // 与上一个第一个数一样，那么这里也可以剪掉
            // 虽然四个数分别可以不一样，但是作为第一个数来说，第一个数是一样的，那么后面满足条件的组合就是固定的
            // 种类不去重是因为可能第二个数可以和第一个数一样，但是第一个数如果还和刚刚遍历到的第一个数一样就没有意义了
            // 用于避免诸如[-2,-1,-1,1,1,2,2]\n0的问题
            if (i > 0 && nums[i] == nums[i - 1])
                continue;
            // 此时选中的第一个数太小了，直接跳过
            if ((long long)nums[i] + nums[n - 1] + nums[n - 2] + nums[n - 3] < target)
                continue;
            // 此时选中的第一个数太大了，那么后面的数作为第一个数就都不可能了
            if ((long long)nums[i] + nums[i + 1] + nums[i + 2] + nums[i + 3] > target)
                break;

            // 第二个数
            for (int j = i + 1; j < n - 2; j++)
            {
                if (j > i + 1 && nums[j] == nums[j - 1])
                    continue;
                // 此时选中的第二个数太小了，直接跳过
                if ((long long)nums[i] + nums[j] + nums[n - 1] + nums[n - 2] < target)
                    continue;
                // 此时选中的第二个数太大了，直接跳过
                if ((long long)nums[i] + nums[j] + nums[j + 1] + nums[j + 2] > target)
                    break;

                // 双指针
                int left = j + 1;
                int right = n - 1;
                while (left < right)
                {
                    // 这里后面如果不加long long，会导致运算是按照int进行的，最后转成long long也会导致溢出
                    // 所以在等号后面就要进行类型转换
                    long long sum = (long long)nums[i] + nums[j] + nums[left] + nums[right];
                    if (sum == target)
                    {
                        res.push_back({nums[i], nums[j], nums[left], nums[right]});
                        left++;
                        right--;
                        while (left < right && nums[left] == nums[left - 1])
                            left++;
                        while (left < right && nums[right] == nums[right + 1])
                            right--;
                    }
                    else if (sum < target)
                    {
                        left++;
                    }
                    else
                    {
                        right--;
                    }
                }
            }
        }
        // 对结果去重，但前面已经去重过了
        // set<vector<int>> s1(res.begin(), res.end());
        // vector<vector<int>> result(s1.begin(), s1.end());
        // return result;
        return res;
    }
};
// @lc code=end
