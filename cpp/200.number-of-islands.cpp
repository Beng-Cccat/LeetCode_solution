/*
 * @lc app=leetcode id=200 lang=cpp
 *
 * [200] Number of Islands
 */

// @lc code=start
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {

        auto inArea=[&](int row,int col){
            return row>=0&&row<grid.size()&&col>=0&&col<grid[0].size();
        };

        function<void(int,int)> dfs=[&](int row,int col){
            if(!inArea(row,col))
                return;
            
            if(grid[row][col]!='1')
                return;

            grid[row][col]=2;

            dfs(row+1,col);
            dfs(row-1,col);
            dfs(row,col+1);
            dfs(row,col-1);
        };

        int res=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]=='1'){
                    dfs(i,j);
                    res++;
                }
            }
        }
        return res;
    }
};
// @lc code=end

