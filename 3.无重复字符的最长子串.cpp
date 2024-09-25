/*
 * @lc app=leetcode.cn id=3 lang=cpp
 *
 * [3] 无重复字符的最长子串
 */

// @lc code=start
class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        int left = 0, right = 0;
        int start = 0, end = 0;

        unordered_map<char, int> cnt;
        for (; right < s.size(); right++)
        {
            // 找到了重复的字符
            if (cnt.find(s[right]) != cnt.end())
            {

                // 更新start和end
                if (end - start < right - left)
                {
                    start = left;
                    end = right;
                }
                // 更新左边界
                // 首先删除需要删除的字符
                for (int i = left; i < cnt[s[right]]; i++)
                {
                    cnt.erase(s[i]);
                }
                // 再更新左边界
                left = cnt[s[right]] + 1;
                // 更新重复字符的位置
                cnt[s[right]] = right;
            }
            // 没有找到重复字符
            else
            {
                cnt[s[right]] = right;
            }
        }
        // 注意这里需要和right-left比较，因为最后一个字符有可能不是重复字符，就无法更新
        // 也可以直接使用maxlength，但是这种做法可以找到最长子字符串的首尾下标而已
        return max(right - left, end - start);
    }
};
// @lc code=end
