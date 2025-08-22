/*
 * @lc app=leetcode id=64 lang=cpp
 *
 * [64] Minimum Path Sum
 */

// @lc code=start
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int row=grid.size();
        int col=grid[0].size();
        vector<vector<int>> dp(grid);

        for(int j=1;j<col;j++)
            dp[0][j]+=dp[0][j-1];
        
        for(int i=1;i<row;i++)
            dp[i][0]+=dp[i-1][0];

        for(int i=1;i<row;i++){
            for(int j=1;j<col;j++){
                dp[i][j]=min(dp[i-1][j],dp[i][j-1])+dp[i][j];
            }
        }

        return dp[row-1][col-1];
    }
};
// @lc code=end

