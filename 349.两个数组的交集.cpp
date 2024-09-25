/*
 * @lc app=leetcode.cn id=349 lang=cpp
 *
 * [349] 两个数组的交集
 */

// @lc code=start
class Solution
{
public:
    vector<int> intersection(vector<int> &nums1, vector<int> &nums2)
    {
        // 如何用set去重：
        set<int> s1(nums1.begin(), nums1.end());
        set<int> s2(nums2.begin(), nums2.end());

        // 使用交集并集函数
        // 首先得排序
        /* 但是set本身有序，所以不需要再次排序
        std::sort(s1.begin(), s1.end());
        std::sort(s2.begin(), s2.end());
        */

        vector<int> s;
        std::set_intersection(s1.begin(), s1.end(), s2.begin(), s2.end(), std::inserter(s, s.begin()));
        return s;
    }
};
// @lc code=end
