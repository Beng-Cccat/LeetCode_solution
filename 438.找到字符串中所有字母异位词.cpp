/*
 * @lc app=leetcode.cn id=438 lang=cpp
 *
 * [438] 找到字符串中所有字母异位词
 */

// @lc code=start
class Solution
{
public:
    vector<int> findAnagrams_0(string s, string p)
    {
        /*
        思路：滑动窗口+哈希表
        1. 统计字符串p中每个字符的个数，存储在哈希表中
        2. 使用滑动窗口，遍历字符串s，每次移动右指针，将右指针指向的字符加入到窗口中
        3. 如果遍历到的字符在哈希表中，则加入到另一个哈希表中
        4. 如果不在，则右移左指针并清空另一个哈希表
        5. 如果另一个哈希表和哈希表相等，则将左指针加入到结果中
        */
        // 特殊情况
        if (s.size() < p.size())
            return {};

        vector<int> res;
        unordered_map<char, int> need, window;
        for (char c : p)
        {
            need[c]++;
        }
        int left = 0;
        int right = 0;
        while (1)
        {
            // 往后找p.size()个字符
            while (right - left < p.size())
            {
                if (need.find(s[right]) != need.end())
                {
                    window[s[right]]++;
                    right++;
                }
                else
                {
                    // 不满足条件，左指针右移
                    if (right + 1 <= s.size() - p.size())
                    {
                        left = right + 1;
                        right = left;
                        window.clear();
                        continue;
                    }
                    else
                    {
                        break;
                    }
                }
            }
            if (window == need)
            {
                res.push_back(left);
            }
            left++;
            right = left;
            window.clear();

            if (left > s.size() - p.size())
                break;
        }
        return res;
    }

    vector<int> findAnagrams(string s, string p)
    {
        /*
        进阶思路：
        不完全清空window，用左右指针收缩和扩张窗口，用valid表示窗口中满足need条件的字符个数
        */

        int left = 0, right = 0, valid = 0;
        vector<int> res;
        unordered_map<char, int> need, window;

        for (char c : p)
        {
            need[c]++;
        }

        while (right < s.size())
        {
            // 遇见了不需要的字符
            {
                if (need.find(s[right]) == need.end())
                {
                    // 重置窗口
                    window.clear();
                    left = right + 1;
                    right = left;
                    valid = 0;
                    continue;
                }
            }
            {
                // 扩大窗口
                window[s[right]]++;
                if (window[s[right]] == need[s[right]])
                {
                    valid++;
                }
                right++;
            }
            // 判断是否满足题意
            if (valid == need.size())
            {
                res.push_back(left);
            }

            // 缩小窗口
            if (right - left == p.size())
            {
                if (window[s[left]] == need[s[left]])
                {
                    valid--;
                }
                window[s[left]]--;
                left++;
            }
        }
        return res;
    }
};
// @lc code=end
