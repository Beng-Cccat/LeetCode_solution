/*
 * @lc app=leetcode id=695 lang=cpp
 *
 * [695] Max Area of Island
 */

// @lc code=start
class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        auto inArea=[&](int row,int col){
            return row>=0&&row<grid.size()&&col>=0&&col<grid[0].size();
        };

        function<int(int,int)> dfs=[&](int row,int col){
            if(!inArea(row,col))
                return 0;
            
            if(grid[row][col]!=1)
                return 0;

            grid[row][col]=2;
            return 1+dfs(row+1,col)
                    +dfs(row-1,col)
                    +dfs(row,col+1)
                    +dfs(row,col-1);
        };


        int res=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                int area=dfs(i,j);
                res=max(area,res);
            }
        }
        return res;
    }
};
// @lc code=end

