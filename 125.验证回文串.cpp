/*
 * @lc app=leetcode.cn id=125 lang=cpp
 *
 * [125] 验证回文串
 */

// @lc code=start
class Solution
{
public:
    bool isPalindrome(string s)
    {
        // 处理字符串
        for (int i = 0; i < s.size(); i++)
        {
            // 两个函数：
            // isalnum()判断是否是字母或数字
            // tolower()转换为小写字母
            if (!isalnum(s[i]))
            {
                // 字符串的移除操作
                s.erase(i, 1);
                i--;
                continue;
            }
            s[i] = tolower(s[i]);
        }
        // 判断回文
        for (int i = 0; i < s.size() / 2; i++)
        {
            if (s[i] != s[s.size() - 1 - i])
                return false;
        }
        return true;
    }
};
// @lc code=end
