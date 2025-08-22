/*
 * @lc app=leetcode id=827 lang=cpp
 *
 * [827] Making A Large Island
 */

// @lc code=start
class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) {
        int idx=2;
        int res=0;

        auto inArea=[&](int row,int col){
            return row>=0&&row<grid.size()&&col>=0&&col<grid[0].size();
        };

        function<int(int,int)> dfs=[&](int row,int col){
            if(!inArea(row,col))
                return 0;
            
            if(grid[row][col]!=1)
                return 0;

            grid[row][col]=idx;

            return 1+dfs(row+1,col)
                    +dfs(row-1,col)
                    +dfs(row,col+1)
                    +dfs(row,col-1);
        };

        unordered_map<int,int> area;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                int a=dfs(i,j);
                if(a>0){
                    area[idx]=a;
                    idx++;
                    res=max(res,a);
                }
            }
        }

        //如何进行上下左右遍历
        vector<pair<int,int>> dirs={{1,0},{-1,0},{0,1},{0,-1}};
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==0){
                    unordered_set<int> seen;
                    int newArea=1;
                    for(auto& d:dirs){
                        int r=i+d.first,c=j+d.second;
                        if(inArea(r,c)&&grid[r][c]>1){
                            int id=grid[r][c];
                            if(!seen.count(id)){
                                newArea+=area[id];
                                seen.insert(id);
                            }
                        }
                    }
                    res=max(res,newArea);
                }
            }
        }
        return res;
    }
};
// @lc code=end

