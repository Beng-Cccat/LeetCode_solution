/*
 * @lc app=leetcode.cn id=56 lang=cpp
 *
 * [56] 合并区间
 */

// @lc code=start
class Solution
{
public:
    vector<vector<int>> merge(vector<vector<int>> &intervals)
    {
        // 先按照区间起始位置排序
        /*
        sort给二维数组排序，默认先按照第一个元素排序，如果第一个元素相等，则按照第二个元素排序
        */
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> res;

        for (int i = 0; i < intervals.size(); i++)
        {
            // 完整地放进去
            if (res.empty() || res.back()[1] < intervals[i][0])
            {
                res.push_back(intervals[i]);
            }
            else
            {
                res.back()[1] = max(res.back()[1], intervals[i][1]);
            }
        }
        return res;
    }
};
// @lc code=end
