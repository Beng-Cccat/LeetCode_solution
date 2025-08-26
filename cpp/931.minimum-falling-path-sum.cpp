/*
 * @lc app=leetcode id=931 lang=cpp
 *
 * [931] Minimum Falling Path Sum
 */

// @lc code=start
class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int row=matrix.size();
        int col=matrix[0].size();
        vector<vector<int>>dp(row,vector<int>(col,0));
        int res=0;

        //只有一列
        if(col==1){
            for(int i=0;i<row;i++)
                res+=matrix[i][0];
            return res;
        }

        for(int i=0;i<col;i++)
            dp[0][i]=matrix[0][i];

        for(int i=1;i<row;i++){
            for(int j=0;j<col;j++){
                if(j==0)
                    dp[i][j]=min(dp[i-1][j],dp[i-1][j+1]);
                else if(j==col-1)
                    dp[i][j]=min(dp[i-1][j],dp[i-1][j-1]);
                else{
                    dp[i][j]=min(dp[i-1][j],dp[i-1][j-1]);
                    dp[i][j]=min(dp[i][j],dp[i-1][j+1]);
                }
                dp[i][j]+=matrix[i][j];
            }
        }

        res=*min_element(dp[row-1].begin(),dp[row-1].end());
        return res;
    }
};
// @lc code=end

