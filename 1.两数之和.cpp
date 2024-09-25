/*
 * @lc app=leetcode.cn id=1 lang=cpp
 *
 * [1] 两数之和
 */

// @lc code=start
class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        /*
        for (int i = 0; i < nums.size(); i++)
        {
            for (int j = i + 1; j < nums.size(); j++)
            {
                if (nums[i] + nums[j] == target)
                {
                    return {i, j};
                }
            }
        }
        //这里记得有个默认的返回
        return {};
        */

        // 进阶
        unordered_map<int, int> hash;
        for (int i = 0; i < nums.size(); i++)
        {
            int temp = target - nums[i];
            if (hash.find(temp) != hash.end())
            {
                return {hash[temp], i};
            }
            // 如果没找到的话把当前的值当作键存起来，方便后续查找
            hash[nums[i]] = i;
        }
        return {};
    }
};
// @lc code=end
