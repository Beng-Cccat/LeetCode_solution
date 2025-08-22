/*
 * @lc app=leetcode id=63 lang=cpp
 *
 * [63] Unique Paths II
 */

// @lc code=start
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int row=obstacleGrid.size();
        int col=obstacleGrid[0].size();

        vector<vector<int>> dp(row,vector<int>(col,0));

        //初始化
        for(int i=0;i<row;i++){
            if(obstacleGrid[i][0])
                break;
            dp[i][0]=1;
        }
        for(int i=0;i<col;i++){
            if(obstacleGrid[0][i])
                break;
            dp[0][i]=1;
        }

        //开始填充
        for(int i=1;i<row;i++){
            for(int j=1;j<col;j++){
                //没有障碍物再开始判断
                if(!obstacleGrid[i][j]){
                    if(!obstacleGrid[i-1][j])
                        dp[i][j]+=dp[i-1][j];
                    if(!obstacleGrid[i][j-1])
                        dp[i][j]+=dp[i][j-1];

                }
            }
        }
        return dp[row-1][col-1];
    }
};
// @lc code=end

