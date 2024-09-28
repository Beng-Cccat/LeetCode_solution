/*
 * @lc app=leetcode.cn id=11 lang=cpp
 *
 * [11] 盛最多水的容器
 */

// @lc code=start
class Solution
{
public:
    int maxArea(vector<int> &height)
    {
        /*
        朴素思路：
        由于容器的容量取决于两个因素：底边的长度和两边较短的高度，所以我们可以用两个指针遍历数组
        然后计算容器的容量，用一个双层循环遍历所有的可能，找到最大的容量

        进阶思路：
        使用两个指针初始化为数组的头和尾，移动较短的那一边，直到两个指针相遇，找到最大的容量
        */

        // 特殊情况
        if (height.size() < 2)
        {
            return 0;
        }

        int left = 0;
        int right = height.size() - 1;
        int max_area = 0;
        int area = 0;
        while (left != right)
        {
            area = min(height[left], height[right]) * (right - left);
            max_area = max(max_area, area);
            if (height[left] < height[right])
            {
                left++;
            }
            else
            {
                right--;
            }
        }
        return max_area;
    }
};
// @lc code=end
