/*
 * @lc app=leetcode.cn id=42 lang=cpp
 *
 * [42] 接雨水
 */

// @lc code=start
class Solution
{
public:
    int trap(vector<int> &height)
    {
        /*
        思路：
        重点：每一个柱子上的积水
        1.暴力解法：对于每一个柱子，遍历找到其左边和右边的最高柱子，取两者的较小值减去当前柱子的高度，即为当前柱子上的雨水量
        如果当前柱子的高度大于等于左边和右边的最高柱子的高度，则当前柱子上的雨水量为0
        时间复杂度：O(n^2)
        空间复杂度：O(1)
        2. 动态规划：对于每一个柱子，分别计算其左边和右边的最高柱子，分别存储在两个数组left_max和right_max中
        left_max[i]=max(left_max[i-1],height[i-1])
        时间复杂度：O(n)
        空间复杂度：O(n)
        3. 双指针：使用两个指针left和right分别指向数组的两端，使用两个变量left_max和right_max分别记录左边和右边的最高柱子
        如果left_max < right_max，则移动left指针，否则移动right指针
        left_max = max(left_max, height[left])
        right_max = max(right_max, height[right])
        时间复杂度：O(n)
        空间复杂度：O(1)
        4. 使用栈：使用栈来存储柱子的下标
        遍历数组，如果栈为空或者当前柱子的高度小于等于栈顶柱子的高度
        则将当前柱子的下标入栈
        否则，将栈顶柱子的下标出栈，计算当前柱子和栈顶柱子之间的雨水量
        雨水量 = (min(当前柱子高度，栈顶柱子高度) - 栈顶柱子高度) * (当前柱子下标 - 栈顶柱子下标 - 1)
        直到栈为空或者当前柱子的高度小于等于栈顶柱子的高度
        时间复杂度：O(n)
        空间复杂度：O(n)
        */

        // 特殊情况
        if (height.size() <= 2)
        {
            return 0;
        }

        int n = height.size();
        int res = 0;
        vector<int> left_max(n), right_max(n);
        for (int i = 1; i < n; i++)
        {
            left_max[i] = max(left_max[i - 1], height[i - 1]);
        }
        for (int i = n - 2; i >= 0; i--)
        {
            right_max[i] = max(right_max[i + 1], height[i + 1]);
        }
        for (int i = 1; i < n; i++)
        {
            if (height[i] < min(left_max[i], right_max[i]))
            {
                res += min(left_max[i], right_max[i]) - height[i];
            }
        }
        return res;
    }
};
// @lc code=end
