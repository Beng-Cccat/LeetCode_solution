/*
 * @lc app=leetcode.cn id=395 lang=cpp
 *
 * [395] 至少有 K 个重复字符的最长子串
 */

// @lc code=start
class Solution
{
public:
    int longestSubstring(string s, int k)
    {
        /*
        找到出现次数小于k的字符，如果某个字符串内出现了该字符，则肯定是不符合要求的
        所以可以在每一段字符内都找到这些不符合要求的字符，然后分割
        不断分割直至字符串内所有字符都符合要求
        */
        if (s.size() == 0)
            return 0;
        return cutstr(s, 0, s.size() - 1, k);
    }
    int cutstr(string s, int start, int end, int k)
    {
        // 停止条件:字符串长度小于k
        if (end - start + 1 < k)
            return 0;

        // 统计每个字符出现的次数
        unordered_map<char, int> cnt;
        for (int i = start; i <= end; i++)
        {
            cnt[s[i]]++;
        }

        // 找到出现次数小于k的字符,split记录分割点
        vector<int> split;
        for (int i = start; i <= end; i++)
        {
            if (cnt[s[i]] < k)
            {
                split.push_back(i);
            }
        }

        // 如果没有出现次数小于k的字符，则返回字符串长度
        if (split.size() == 0)
            return end - start + 1;

        // 分割字符串
        // res记录最大值, last记录上一个分割点
        int res = 0;
        int last = start;
        for (int i = 0; i < split.size(); i++)
        {
            res = max(res, cutstr(s, last, split[i] - 1, k));
            last = split[i] + 1;
        }

        // 最后一个分割点到end
        res = max(res, cutstr(s, last, end, k));
        return res;
    }
};
// @lc code=end
