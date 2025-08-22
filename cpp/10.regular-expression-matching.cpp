/*
 * @lc app=leetcode id=10 lang=cpp
 *
 * [10] Regular Expression Matching
 */

// @lc code=start
class Solution {
public:
    bool isMatch(string s, string p) {
        int m=s.size(),n=p.size();
        vector<vector<bool>> dp(m+1,vector<bool>(n+1,false));

        //初始化，s和p均为空
        dp[0][0]=true;

        //初始化，s为空但p不为空
        for(int i=2;i<=n;i++){
            if(p[i-1]=='*')
                dp[0][i]=dp[0][i-2];
        }

        //填充开始
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                if(s[i-1]==p[j-1]||p[j-1]=='.')
                    dp[i][j]=dp[i-1][j-1];
                else if(p[j-1]=='*'){
                    if(s[i-1]==p[j-2]||p[j-2]=='.')
                        dp[i][j]=dp[i-1][j-2]||dp[i-1][j]||dp[i][j-2];
                    else
                        dp[i][j]=dp[i][j-2];
                }
            }
        }
        return dp[m][n];

    }

};
// @lc code=end

