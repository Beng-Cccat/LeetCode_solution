/*
 * @lc app=leetcode id=3 lang=cpp
 *
 * [3] Longest Substring Without Repeating Characters
 */

// @lc code=start
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        //滑动窗口
        int start=0,maxLen=0;
        unordered_map<char,int> hp;//字符及其最后出现的位置

        for(int i=0;i<s.size();i++){
            if(hp.find(s[i])!=hp.end()&&hp[s[i]]>=start)//有重复的并且在窗口范围内重复
                start=hp[s[i]]+1;
            maxLen=max(maxLen,i-start+1);
            hp[s[i]]=i;
        }

        return maxLen;
    }
};
// @lc code=end

