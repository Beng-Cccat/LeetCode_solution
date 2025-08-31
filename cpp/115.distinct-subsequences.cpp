/*
 * @lc app=leetcode id=115 lang=cpp
 *
 * [115] Distinct Subsequences
 */

// @lc code=start
class Solution {
public:
    int numDistinct(string s, string t) {
        //大致思路：回溯->会指数爆炸
        int lens=s.size(),lent=t.size();
        //这里用ull不会溢出，用ll都会溢出
        vector<vector<unsigned long long>> dp(lens+1,vector<unsigned long long>(lent+1,0));

        for(int i=0;i<=lens;i++)dp[i][0]=1;
        for(int i=1;i<=lens;i++)
            for(int j=1;j<=lent;j++){
                if(s[i-1]==t[j-1])
                //相等的时候，可以考虑要用这个进行匹配吗（s[i-2]==t[j-2]，也就是说这个是匹配字符的最后一个
                //那么前面就需要匹配 s[0..i-2] 和 t[0..j-2]，即 dp[i-1][j-1]
                //同时还有另一种情况，也就是他虽然是匹配的，但是不用这个进行匹配，也就是s[i-2]==t[j-1]
                //那么 t[0..j-1] 依然要从 s[0..i-2] 中匹配，即 dp[i-1][j]
                    dp[i][j]=dp[i-1][j]+dp[i-1][j-1];
                else
                    dp[i][j]=dp[i-1][j];
            }

        return (int)dp[lens][lent];
    }
};
// @lc code=end

