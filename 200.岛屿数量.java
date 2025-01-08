/*
 * @lc app=leetcode.cn id=200 lang=java
 *
 * [200] 岛屿数量
 */

// @lc code=start
class Solution {
    public int numIslands(char[][] grid) {
        /*
         * DFS：深度优先遍历，通常在图或树结构上
         * 重要元素：
         * 1. 访问相邻节点
         * 2. 判断base case
         * 而对于网格问题来说：
         * 1. 访问相邻节点->上下左右四个节点
         * 2. 判断base case->是否超出网格面积
         * 3. 状态变化：
         *  a. 0表示海洋
         *  b. 1表示陆地（未遍历过）
         *  c. 2表示陆地（遍历过）->或者变成0，即“陆地沉没”
         */
        int count=0;
        for(int i=0;i<grid.length;i++){
            for(int j=0;j<grid[0].length;j++){
                if(grid[i][j]=='1'){
                    dfs(grid,i,j);
                    count++;
                }
            }
        }
        return count;
    }

    public void dfs(char[][] grid,int r,int c){
        //root->判断是否在网格内
        if(!inArea(grid,r,c)){
            return;
        }

        if(grid[r][c]!='1')
            return;

        grid[r][c]='2';

        dfs(grid,r,c-1);
        dfs(grid,r,c+1);
        dfs(grid,r+1,c);
        dfs(grid,r-1,c);
    }
    boolean inArea(char[][] grid,int r,int c){
        if(r<0||r>=grid.length||c<0||c>=grid[0].length)
            return false;
        return true;
    } 
}
// @lc code=end

