/*
 * @lc app=leetcode.cn id=49 lang=cpp
 *
 * [49] 字母异位词分组
 */

// @lc code=start
class Solution
{
public:
    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {
        /*思路：将每一个字符串中的字符从小到大排序，然后用哈希存储，每次都寻找一下*/

        // 特殊情况
        if (strs.size() == 0)
            return {};

        unordered_map<string, vector<string>> mp;
        // 学会使用auto
        for (auto str : strs)
        {
            string key = str;
            sort(key.begin(), key.end());
            mp[key].push_back(str);
        }

        vector<vector<string>> res;

        for (auto pairs : mp)
        {
            res.push_back(pairs.second);
        }
        return res;
    }
};
// @lc code=end
