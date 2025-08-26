/*
 * @lc app=leetcode id=174 lang=cpp
 *
 * [174] Dungeon Game
 */

// @lc code=start
class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int row=dungeon.size(),col=dungeon[0].size();
        vector<vector<int>>dp(row+1,vector<int>(col+1,INT_MAX));

        //逆向dp
        
        //初始化
        dp[row-1][col]=dp[row][col-1]=1;
        //填充
        for(int i=row-1;i>=0;i--){
            for(int j=col-1;j>=0;j--){
                int need=min(dp[i][j+1],dp[i+1][j])-dungeon[i][j];
                dp[i][j]=max(1,need);
            }
        }
        return dp[0][0];
    }
};
// @lc code=end

