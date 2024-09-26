/*
 * @lc app=leetcode.cn id=32 lang=cpp
 *
 * [32] 最长有效括号
 */

// @lc code=start
class Solution
{
public:
    int longestValidParentheses(string s)
    {
        /*
        利用状态转移方程：
        s[i]表示第i个字符，dp[i]表示以第i个字符结尾的最长有效括号的长度
        if s[i] == '(' :
            dp[i] = 0
        if s[i] == ')' :
            if s[i - 1] == '(' and i - 2 >= 0 :
                dp[i] = dp[i - 2] + 2

            if s[i - 1] == ')' and i - dp[i - 1] - 2 >= 0 and s[i - dp[i - 1] - 1] == '(' :
                dp[i] = dp[i - 1] + dp[i - dp[i - 1] - 2] + 2
        */
        // 特殊情况
        if (s.size() == 0)
            return 0;

        vector<int> dp(s.size(), 0);
        for (int i = 0; i < s.size(); i++)
        {
            // 最后一个字符是左括号，无效
            if (s[i] == '(')
            {
                dp[i] = 0;
            }
            // 最后一个字符是右括号
            else
            {
                // 当右括号前面字符即可匹配，即为"()"，则dp[i] = dp[i-2] + 2
                if (i - 1 >= 0 && s[i - 1] == '(')
                    if (i - 2 >= 0)
                        dp[i] = dp[i - 2] + 2;
                    else
                        dp[i] = 2;
                // 当右括号前面字符仍然不能匹配，继续往前面找是否匹配
                else if (i - 1 >= 0 && s[i - 1] == ')' && i - dp[i - 1] - 1 >= 0 && s[i - dp[i - 1] - 1] == '(')
                    // 已经是一个完整的匹配了，但是还需要看前面是否还有匹配，所以再加上前面的匹配长度
                    if (i - dp[i - 1] - 2 >= 0)
                        dp[i] = dp[i - 1] + dp[i - dp[i - 1] - 2] + 2;
                    else
                        dp[i] = dp[i - 1] + 2;
            }
        }
        // 找到dp中的最大值
        return *max_element(dp.begin(), dp.end());
    }
};
// @lc code=end
