/*
 * @lc app=leetcode id=474 lang=cpp
 *
 * [474] Ones and Zeroes
 */

// @lc code=start
class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        int len=strs.size();
        vector<vector<int>> dp(m+1,vector<int>(n+1,0));

        //相当于是三层循环，第一层遍历物品维度，后面两层遍历重量维度
        for(auto str:strs){
            int zero=0;
            int one=0;
            for(auto ch:str){
                if(ch=='0')zero++;
                else if(ch=='1')one++;
            }

            for(int i=m;i>=zero;i--){
                for(int j=n;j>=one;j--){
                    dp[i][j]=max(dp[i][j],dp[i-zero][j-one]+1);
                }
            }
        }

        return dp[m][n];
        
    }
};
// @lc code=end

