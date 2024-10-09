/*
 * @lc app=leetcode.cn id=41 lang=cpp
 *
 * [41] 缺失的第一个正数
 */

// @lc code=start
class Solution
{
public:
    int firstMissingPositive(vector<int> &nums)
    {
        /*
        先要将其按照大小排序，方便后续查找
        sort(nums.begin(), nums.end());
        但是由于map本身会根据键的大小进行排序，所以这里可以省略排序的步骤
        */
        map<int, int> hs;
        for (int i = 0; i < nums.size(); i++)
        {
            hs[nums[i]] = nums[i];
        }

        int i = 1;
        while (true)
        {
            if (hs.find(i) != hs.end())
            {
                i++;
                continue;
            }
            return i;
        }
    }
};
// @lc code=end
