/*
 * @lc app=leetcode.cn id=283 lang=cpp
 *
 * [283] 移动零
 */

// @lc code=start
class Solution
{
public:
    void moveZeroes(vector<int> &nums)
    {
        /*
        思路：
        用左右两个指针，左指针指向零元素，右指针指向非零元素，每次交换两指针指向元素的值，直到右指针到达数组末尾
        */
        // 特殊情况
        if (nums.size() <= 1)
            return;
        int left = 0;
        int right = 0;
        while (right != nums.size())
        {
            // 找到左指针的位置
            while (left < nums.size() && nums[left] != 0)
            {
                left++;
            }
            // 找到右指针的位置
            right = left;
            while (right < nums.size() && nums[right] == 0)
            {
                // 如果最后一个数是0，那么再++会越界，所以直接跳过
                if (right == nums.size() - 1)
                    return;
                right++;
            }
            // 如果两指针指向元素不相等，交换
            if (left != right)
                swap(nums[left], nums[right]);
        }
    }
};
// @lc code=end
