/*
 * @lc app=leetcode id=329 lang=cpp
 *
 * [329] Longest Increasing Path in a Matrix
 */

// @lc code=start
class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int row=matrix.size(),col=matrix[0].size();
        vector<vector<int>>dp(row,vector<int>(col,-1));


        function<int(int,int,int)> findways=[&](int x,int y,int val){
            if(x>=row||x<0||y>=col||y<0)
                return 0;
            
            if(matrix[x][y]<=val)
                return 0;

            if(dp[x][y]!=-1)
                return dp[x][y];

            dp[x][y]=max({  1+findways(x+1,y,matrix[x][y]),
                            1+findways(x-1,y,matrix[x][y]),
                            1+findways(x,y+1,matrix[x][y]),
                            1+findways(x,y-1,matrix[x][y]),
                            1});
            return dp[x][y];
        };

        int ans=0;
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                ans=max(ans,findways(i,j,INT_MIN));
            }
        }

        return ans;
    }
};
// @lc code=end

