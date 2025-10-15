/*
 * @lc app=leetcode id=139 lang=cpp
 *
 * [139] Word Break
 */

// @lc code=start
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> exists(wordDict.begin(),wordDict.end());

        //用dp数组时，常常用的是[前多少个字符]来定义的
        vector<bool> dp(s.size()+1,false);

        dp[0]=true;

        for(int end=1;end<=s.size();end++){
            for(int i=0;i<end;i++){
                if(dp[i]&&exists.count(s.substr(i,end-i))){
                    dp[end]=true;
                    break;
                }
            }
        }
        return dp[s.size()];
    }
};
// @lc code=end

