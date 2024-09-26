/*
 * @lc app=leetcode.cn id=5 lang=cpp
 *
 * [5] 最长回文子串
 */

// @lc code=start
class Solution
{
public:
    string longestPalindrome(string s)
    {
        /*中心扩散：从最中间的值开始，向两边扩散*/
        int n = s.size();

        // 特殊情况
        if (n == 0 || n < 2)
            return s;

        int maxLen = 1;
        int maxStart = 0;
        int left = 0, right = 0;
        int curLen = 1;

        // 从第一个元素开始判断
        for (int i = 0; i < n; i++)
        {
            /*
            总共有三种情况：
            1. aba型（两边相同，和中间不同）
            2. abba型（即他和左边或者右边的值相同但是和另一边的值不同）
            3. a型（即左中右均不同）
            第一种为奇数型，第二种为偶数型，第三种为不符合条件型
            */

            // 奇数情况
            left = i;
            right = i;
            curLen = 1;
            while (left - 1 >= 0 && right + 1 < n && s[left - 1] == s[right + 1])
            {
                left--;
                right++;
                curLen += 2;
            }
            // 更新最大值
            if (curLen > maxLen)
            {
                maxLen = curLen;
                maxStart = left;
            }

            // 偶数情况
            left = i;
            right = i + 1;
            curLen = 0;
            while (left >= 0 && right < n && s[left] == s[right])
            {
                left--;
                right++;
                curLen += 2;
            }
            // 更新最大值
            if (curLen > maxLen)
            {
                maxLen = curLen;
                // 注意这里，由于在最后判断失败后left--，所以这里的起始位置需要+1
                maxStart = left + 1;
            }
        }
        return s.substr(maxStart, maxLen);

        /*
        改进：动态规划——空间换时间
        使用数组dp[i][j]表示s[i]到s[j]是否为回文串
        于是有状态转移方程：
        dp[i][j] = (s[i] == s[j]) && dp[i+1][j-1]
        边界条件：
        1. dp[i][i] = true
        2. dp[i][i+1] = (s[i] == s[i+1])
        即双层循环，分别遍历left和right，判断是否为回文串
        */
    }
};
// @lc code=end
